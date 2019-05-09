
#include <bld_system.h>
#include "application.h"
#include "bld_ext_funcs.h"


/*
* Module:                 Blade.exe
* Entry point:            0x0041009D
*/

void _impl_application_load_level(application_t *self, const char *map)
{
        char buffer[260];
        double timeBefore, timeAfter;
        static int loadLevelCounter = 0;

        timeBefore = timeGetTime();

        self->mapName = get_map_for_net_game(map);
        map = self->mapName;

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

        if (gbl_net_data->is_net_game()) {
                if (gbl_net_data->is_server()) {
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
        mout << vararg("Load Time = %f\n", (timeAfter - timeBefore)/1000.0);

        if (gbl_sound_device) {
                gbl_sound_device->unknown08 = 0;
                gbl_sound_device->unknown0C = 0;
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
                        (HWND)self->window,
                        vararg("%s %.1f", "Blade", self->fUnknown5C0)
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