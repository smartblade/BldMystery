//---------------------------------------------------------------------------

#include <float.h>
#include <bld_system.h>

//---------------------------------------------------------------------------

HMODULE blade = NULL;
static void (**init_start)(void) = NULL;
static void (**init_end)(void) = NULL;
static void **__onexitbegin_ptr = NULL;
static int (__stdcall *_stdcall_BladeWinMain)(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow) = NULL;



void DoInitializers(void)
{
        void (**init_fn)(void);

        for(init_fn = init_start; init_fn <= init_end; init_fn++)
        {
                if (*init_fn)
                        (*init_fn)();
        }
}


WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
        blade = LoadLibrary("Blade.dll");

        if (!blade)
                return 1;

       _stdcall_BladeWinMain = (void *)((char *)blade + 0x00010CC2);

        init_start = (void *)((char *)blade + 0x001C8000);
        init_end = (void *)((char *)blade + 0x001C8240);
        __onexitbegin_ptr = (void *)((char *)blade + 0x003F00EC);

        /*
         * Disable floating point exceptions to avoid throwing division
         * by zero exception when using OpenGL raster
         */
        _control87(MCW_EM,MCW_EM);

        /* __onexitbegin should be -1 on EXE module */
        *__onexitbegin_ptr = (void *)-1;

        DoInitializers();

        /*
         * Pass blade dll module pointer to blade main function instead of exe process
         * handler to avoid following error from DialogBoxParam function when game
         * launcher starting:
         *   error 1813: ”казанный тип ресурса в файле образа отсутствует
        */
        _stdcall_BladeWinMain(blade, hPrevInstance, lpCmdLine, nCmdShow);

        return 0;
}
//---------------------------------------------------------------------------

