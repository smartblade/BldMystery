
#include <bld_system.h>
#include <console.h>
#include <raster_device.h>
#include "BladeApp.h"
#include "bld_misc_funcs.h"


/*
* Module:                 Blade.exe
* Entry point:            0x0040F040
* VC++ mangling:          ??0B_WinApp@@QAE@PAXHPAD0@Z
*/

#ifdef BLD_NATIVE_CONSTRUCTOR

B_WinApp::B_WinApp(void *module, int nCmdShow, char *cmdLine, void *unknown)
{
}

#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0040F1B4
* VC++ mangling:          ??1B_WinApp@@UAE@XZ
*/

B_WinApp::~B_WinApp()
{
    if (destroyRasterCB != NULL)
    {
        destroyRasterCB(B_3D_raster_device);
        B_3D_raster_device = NULL;
        FreeLibrary(rasterLibrary);
        this->rasterLibrary = NULL;
    }
    if (showConsole)
    {
        DestroyConsole(console);
    }
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040F256
* VC++ mangling:          ?InitWindow@B_WinApp@@UAE_NXZ
*/
#ifdef BLD_NATIVE
bool B_WinApp::InitWindow()
{
    return false;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0040F388
* VC++ mangling:          ?ProcessMessage@B_WinApp@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_WinApp::ProcessMessage()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0040F3BB
* VC++ mangling:          ?unknown_method070@B_WinApp@@UAEPAXXZ
*/
#ifdef BLD_NATIVE
void *B_WinApp::unknown_method070()
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0040F403
* VC++ mangling:          ?NewWindow@B_WinApp@@UAEPAXXZ
*/
#ifdef BLD_NATIVE
void *B_WinApp::NewWindow()
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0040F4A4
* VC++ mangling:          ?Start@B_WinApp@@UAE_NXZ
*/
#ifdef BLD_NATIVE
bool B_WinApp::Start()
{
    return false;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0041009D
* VC++ mangling:          ?LoadLevel@B_WinApp@@UAEXPBD@Z
*/

void B_WinApp::LoadLevel(const char *map)
{
        char buffer[260];
        double timeBefore, timeAfter;
        static int loadLevelCounter = 0;

        timeBefore = timeGetTime();

        this->mapName = get_map_for_net_game(map);
        map = this->mapName;

        GetCurrentDirectory(sizeof(buffer), buffer);
        mout << buffer;
        mout << "\n";

        if (loadLevelCounter) {
                SetCurrentDirectory(vararg("..\\%s", map));
        } else {
                SetCurrentDirectory(vararg("..\\Maps\\%s", map));
        }

        GetCurrentDirectory(sizeof(buffer), buffer);
        mout << buffer;
        mout << "\n";

        if (gbl_sound_device) {
                gbl_sound_device->unknown08 = 1;
                gbl_sound_device->unknown0C = 1;
        }

        if (gbl_net->is_net_game()) {
                if (gbl_net->is_server()) {
                        B_App::LoadLevel("Server.py");
                        Set007EA988To01();
                } else {
                        B_App::LoadLevel("Client.py");
                }
        } else {
                loadLevelCounter++;

                B_App::LoadLevel("Cfg.py");
        }

        timeAfter = timeGetTime();
        mout << vararg("Load Time = %f\n", (timeAfter - timeBefore)/1000.0);

        if (gbl_sound_device) {
                gbl_sound_device->unknown08 = 0;
                gbl_sound_device->unknown0C = 0;
        }
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410305
* VC++ mangling:          ?ProcessEvents@B_WinApp@@UAEXXZ
*/

void B_WinApp::ProcessEvents() {
        static int counter = 0;

        if (!this->no_sleep)
                Sleep(50);

        if (counter == 60) {
                SetWindowText(
                        (HWND)this->window,
                        vararg("%s %.1f", "Blade", this->fUnknown5C0)
                );
                counter = 0;
        }

        counter++;
        B_App::ProcessEvents();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410384
* VC++ mangling:          ?End@B_WinApp@@UAEXXZ
*/
#ifdef BLD_NATIVE
void B_WinApp::End()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004103A1
* VC++ mangling:          ?Quit@B_WinApp@@UAEHXZ
*/
#ifdef BLD_NATIVE
int B_WinApp::Quit()
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004103D7
* VC++ mangling:          ?ReadArguments@B_WinApp@@UAEXPBD@Z
*/
#ifdef BLD_NATIVE
void B_WinApp::ReadArguments(const char *arguments)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00410640
* VC++ mangling:          ?unknown_method010@B_WinApp@@UAEPAXPAX@Z
*/
#ifdef BLD_NATIVE
void *B_WinApp::unknown_method010(void *)
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004106F2
* VC++ mangling:          ?ReadLevel@B_WinApp@@UAEXPBD@Z
*/
#ifdef BLD_NATIVE
void B_WinApp::ReadLevel(const char *file_name)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0041073A
* VC++ mangling:          ?WindowProcedure@B_WinApp@@UAEJPAUHWND__@@IIJ@Z
*/
#ifdef BLD_NATIVE
LRESULT B_WinApp::WindowProcedure(
    HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00410AF5
* VC++ mangling:          ?Mouse@B_WinApp@@UAEX_N@Z
*/
#ifdef BLD_NATIVE
void B_WinApp::Mouse(bool acquireFlag)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00410B53
* VC++ mangling:          ?ExitWithError@B_WinApp@@UAEXPAD0@Z
*/
#ifdef BLD_NATIVE
void B_WinApp::ExitWithError(char *title, char* message)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00410BBE
* VC++ mangling:          ?PrintWarning@B_WinApp@@UAEXPBD0@Z
*/
#ifdef BLD_NATIVE
void B_WinApp::PrintWarning(const char *, const char *)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00410C3D
* VC++ mangling:          ?Input@B_WinApp@@UAEPBDPBD@Z
*/
#ifdef BLD_NATIVE
const char *B_WinApp::Input(const char *text)
{
    return NULL;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00410CC2
* VC++ mangling:          _WinMain@16
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
        B_App *App;
        char *cmd;
        MSG msg;

        cmd = lpCmdLine;

        LoadNetModule("NetBlade\\Netblade.dll");
        App = create_application(hInstance, nCmdShow, cmd);

        assert(App);

        if (!App->Start())
                return 0;

        Set007EA988To01();
        for(;;) {
                if (PeekMessage(&msg, NULL, WM_NULL, WM_NULL, PM_REMOVE)) {

                        if (msg.message == WM_QUIT) {
                                App->End();
                                delete App;
                                return msg.wParam;
                        } else {
                                TranslateMessage(&msg);
                                DispatchMessage(&msg);
                        }
                } else {
                        App->ProcessEvents();

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
* Entry point:            0x00410F6F
* VC++ mangling:          ?SetCurrentMap@B_WinApp@@UAEHPBD@Z
*/
#ifdef BLD_NATIVE
int B_WinApp::SetCurrentMap(const char *map)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00411034
* VC++ mangling:          ?GetInputMode@B_WinApp@@UAEPBDPBD@Z
*/
#ifdef BLD_NATIVE
const char *B_WinApp::GetInputMode(const char *device)
{
    return NULL;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00411043
* VC++ mangling:          ?SetInputMode@B_WinApp@@UAEHPBD0@Z
*/
#ifdef BLD_NATIVE
int B_WinApp::SetInputMode(const char *device, const char *mode)
{
    return 0;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00411170
* VC++ mangling:          ?GetWindow@B_WinApp@@UAEHXZ
*/
#ifdef BLD_NATIVE
int B_WinApp::GetWindow()
{
    return 0;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00411190
* VC++ mangling:          ?GetModule@B_WinApp@@UAEHXZ
*/
#ifdef BLD_NATIVE
int B_WinApp::GetModule()
{
    return 0;
}
#endif
