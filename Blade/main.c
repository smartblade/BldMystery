//---------------------------------------------------------------------------

#include <float.h>
#include <bld_system.h>
#include <bld_python.h>
#define BUILD_LIB
#include <blade_ext.h>
#include "application.h"
#include "BBLibc.h"
#include "net_data.h"
#include "bld_ext_funcs.h"
#pragma hdrstop

//---------------------------------------------------------------------------


static application_methods_t application_methods = {
        NULL, NULL, NULL, NULL, NULL, NULL, NULL,
        _thiscall_application_wait_for_event,
        NULL, NULL, NULL, NULL,
        _thiscall_application_mark_level_to_load,
         NULL,
        _thiscall_application_load_level,
#ifdef _MSC_VER
        _thiscall_application_read_level,
#endif
};


/*
* Module:                 Blade.exe
* Entry point:            0x0041009D
*/

void _impl_application_load_level(application_t *self, char *map)
{
        char buffer[260];
        double timeBefore, timeAfter;
        B_Name mapName;
        static loadLevelCounter = 0;

        timeBefore = timeGetTime();

        BBlibc_name_set(&mapName, get_map_for_net_game(map));
        BBlibc_name_copy(&self->mapName, &mapName);
        BBlibc_name_clear(&mapName);

        map = self->mapName.string;

        GetCurrentDirectory(sizeof(buffer), buffer);
        message_manager_print(message_manager, buffer);
        message_manager_print(message_manager, "\n");

        if (loadLevelCounter) {
                SetCurrentDirectory(BBlibc_format_string("..\\%s", map));
        } else {
                SetCurrentDirectory(BBlibc_format_string("..\\Maps\\%s", map));
        }

        GetCurrentDirectory(sizeof(buffer), buffer);
        message_manager_print(message_manager, buffer);
        message_manager_print(message_manager, "\n");

        if (gbl_sound_device) {
                gbl_sound_device[2] = 1;
                gbl_sound_device[3] = 1;
        }

        if (net_data_is_net_game(gbl_net_data)) {
                if (net_data_is_server(gbl_net_data)) {
                        application_load_level_script(self, "Server.py");
                        Set007EA988To01();
                } else {
                        application_load_level_script(self, "Client.py");
                }
        } else {
                loadLevelCounter++;

                application_load_level_script(self, "Cfg.py");
        }

        timeAfter = timeGetTime();
        message_manager_print(
                message_manager,
                BBlibc_format_string(
                        "Load Time = %f\n", (timeAfter - timeBefore)/1000.0
                )
        );

        if (gbl_sound_device) {
                gbl_sound_device[2] = 0;
                gbl_sound_device[3] = 0;
        }
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410305
*/

void _impl_application_wait_for_event(application_t *self) {
        static int counter = 0;

        if (!self->no_sleep)
                Sleep(50);

        if (counter == 60) {
                SetWindowText(
                        self->window,
                        BBlibc_format_string(
                                "%s %.1f", "Blade", self->fUnknown5C0
                        )
                );
                counter = 0;
        }

        counter++;
        application_process_event(self);
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00410CC2
*/

int BladeWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
        application_t *App;
        char *cmd;
        MSG msg;
        int code;

        cmd = lpCmdLine;

        LoadNetModule("NetBlade\\Netblade.dll");
        App = create_application(hInstance, nCmdShow, cmd);

        assert(App);

        if (application_start(App) == 0)
                return 0;

        Set007EA988To01();
        for(;;) {
                if (PeekMessage(&msg, NULL, WM_NULL, WM_NULL, PM_REMOVE)) {

                        if (msg.message == WM_QUIT) {
                                application_end(App);

                                if (App) {
                                        code = application_destroy(App, 1);
                                } else {
                                        code = 0;
                                }

                                return msg.wParam;
                        } else {
                                TranslateMessage(&msg);
                                DispatchMessage(&msg);
                        }
                } else {
                        /* wait for event */

                        application_wait_for_event(App);

                        OnEvent(0, 0xbff00000);
                }
        }
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x005B9B60
*/

application_t* create_application(void *module, int nCmdShow, char *cmdLine)
{
        application_t *new_application;

        NEW_APPLICATION(new_application, module, nCmdShow, cmdLine)

        gbl_application = new_application;

        return gbl_application;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x005B9BB7
*/

application_t* get_application()
{
        return gbl_application;
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B9BC1
*/

application_t* application_init(
        application_t *self, void *module, int nCmdShow, char *cmdLine
) {
        application_init2(self, module, nCmdShow, cmdLine, NULL);
        self->methods = &application_methods;
        return self;
}


void LoadMsvcrtFunctions(void)
{
        HMODULE msvcrt = NULL;
        msvcrt = LoadLibrary("bicrt.dll");

        msvcrt_fopen = (void *)GetProcAddress(msvcrt, "fopen");
        msvcrt_fclose = (void *)GetProcAddress(msvcrt, "fclose");
}


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
        HMODULE BBLibc, shw32;

        LoadMsvcrtFunctions();

        blade = LoadLibrary("Blade.dll");

        if (!blade)
                return 1;

        BBLibc = LoadLibrary("BBLibc.dll");
        shw32 = LoadLibrary("Shw32.dll");

        _cdecl_read_points = (void *)((char *)blade + 0x000088F4);
        _cdecl_read_point = (void *)((char *)blade + 0x0000ACDD);
        _thiscall_0040AD82 = (void *)((char *)blade + 0x0000AD82);
        _thiscall_0040ADA8 = (void *)((char *)blade + 0x0000ADA8);
        _thiscall_application_init2 = (void *)((char *)blade + 0x0000F040);
        _thiscall_application_set_mode = (void *)((char *)blade + 0x00011EB9);
        _thiscall_application_process_event = (void *)((char *)blade + 0x000121CE);
        _thiscall_application_prepare_level = (void *)((char *)blade + 0x00014F7F);
        _thiscall_application_load_world = (void *)((char *)blade + 0x00016C6F);
        _cdecl_read_sectors = (void *)((char *)blade + 0x00032379);
        _thiscall_00439F5D = (void *)((char *)blade + 0x00039F5D);
        _cdecl_read_light = (void *)((char *)blade + 0x0004AD38);
        _thiscall_00451A21 = (void *)((char *)blade + 0x00051A21);
        _thiscall_camera_init = (void *)((char *)blade + 0x000EAD20);
        _thiscall_camera_004EB1AA = (void *)((char *)blade + 0x000EB1AA);
        Set007EA988To01 = (void *)((char *)blade + 0x001AC791);
        OnEvent = (void *)((char *)blade + 0x001AF2CE);
        reset_client_map_name = (void *)((char *)blade + 0x001B1431);
        get_map_for_net_game = (void *)((char *)blade + 0x001B143D);
        LoadNetModule = (void *)((char *)blade + 0x001B65D2);
        BldStartup = (void *)((char *)blade + 0x001BC34A);

        application_methods_ptr = (void *)((char *)blade + 0x001C0848);
        init_start = (void *)((char *)blade + 0x001C8000);
        init_end = (void *)((char *)blade + 0x001C8240);
        world_points_ptr = (void *)((char *)blade + 0x001DF898);
        game_state_ptr = (void *)((char *)blade + 0x001E0B88);
        var005E24DC = (void *)((char *)blade + 0x001E24DC);
        var005E24F4 = (void *)((char *)blade + 0x001E24F4);
        anims_ptr = (void *)((char *)blade + 0x003072A8);
        sound_device_ptr = (void *)((char *)blade + 0x003C8ED0);
        client_map_name = (void *)((char *)blade + 0x003EE018);
        net_game_name = (void *)((char *)blade + 0x003EE0B8);
        net_max_players_ptr = (void *)((char *)blade + 0x003EE138);
        net_data_ptr = (void *)((char *)blade + 0x003EE2C4);
        application_ptr = (void *)((char *)blade + 0x003EFC94);
        __onexitbegin_ptr = (void *)((char *)blade + 0x003F00EC);

        _thiscall_BBlibc_name_set = (void *)GetProcAddress(BBLibc, "??0B_Name@@QAE@PBD@Z");
        _thiscall_BBlibc_name_clear = (void *)GetProcAddress(BBLibc, "??1B_Name@@QAE@XZ");
        _thiscall_BBlibc_name_copy = (void *)GetProcAddress(BBLibc, "??4B_Name@@QAEAAV0@ABV0@@Z");
        _thiscall_BBlibc_name_string = (void *)GetProcAddress(BBLibc, "?String@B_Name@@QBEQADXZ");
        _thiscall_BBlibc_name_is_equal_string = (void *)GetProcAddress(BBLibc, "??8B_Name@@QBEIPBD@Z");
        _thiscall_BBLibc_named_object_id = (void *)GetProcAddress(BBLibc, "?Id@B_NamedObj@@QBEABVB_Name@@XZ");
        BBlibc_format_string = (void *)GetProcAddress(BBLibc, "?vararg@@YAPBDPBDZZ");
        message_manager_print = (void *)GetProcAddress(BBLibc, "??6@YAAAVB_MessageManager@@AAV0@PBD@Z");
        msg_manager_ptr = (void *)GetProcAddress(BBLibc, "?mout@@3VB_MessageManager@@A");

        bld_new = (void *)GetProcAddress(shw32, "shi_new");

#ifdef __BORLANDC__

        create_bcb_wrappers();

        /*
         * Disable floating point exceptions to avoid throwing division
         * by zero exception when using OpenGL raster
         */
        _control87(MCW_EM,MCW_EM);

#endif

        /* __onexitbegin should be -1 on EXE module */
        *__onexitbegin_ptr = (void *)-1;

        DoInitializers();

        /*
         * Pass blade dll module pointer to blade main function instead of exe process
         * handler to avoid following error from DialogBoxParam function when game
         * launcher starting:
         *   error 1813: ”казанный тип ресурса в файле образа отсутствует
        */

        BladeWinMain(blade, hPrevInstance, lpCmdLine, nCmdShow);

        return 0;
}
//---------------------------------------------------------------------------

