//---------------------------------------------------------------------------

#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include "application.h"
#include "BBLibc.h"
#include "net_data.h"
#include "bld_ext_funcs.h"
#pragma hdrstop

//---------------------------------------------------------------------------


static application_methods_t application_methods = {
        NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
        NULL, NULL,
        _thiscall_application_load_level
};


/*
* Module:                 Blade.exe
* Entry point:            0x0041000A
*/

void _impl_application_load_level(application_t *self, char *map)
{
        char buffer[260];
        double timeBefore, timeAfter;
        BBLibc_name_t mapName;
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

        if (*var007C59B8) {
                (*var007C59B8)[2] = 1;
                (*var007C59B8)[3] = 1;
        }

        if (net_data_is_net_game(net_data)) {
                if (net_data_is_server(net_data)) {
                        application_load_level_script(self, "Server.py");
                        Set007E7470To01();
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

        if (*var007C59B8) {
                (*var007C59B8)[2] = 0;
                (*var007C59B8)[3] = 0;
        }
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B8D91
*/

application_t* application_init(
        application_t *self, void *module, int nCmdShow, char *cmdLine
) {
        application_init2(self, module, nCmdShow, cmdLine, NULL);
        self->methods = &application_methods;
        return self;
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B8D30
*/


application_t* CreateApp(void *module, int nCmdShow, char *cmdLine)
{
        application_t *new_application;

        NEW_APPLICATION(new_application, module, nCmdShow, cmdLine)

        application = new_application;

        return application;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00410C02
*/

int BladeWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
        application_t *App;
        char *cmd;
        MSG msg;
        int code;

        cmd = lpCmdLine;

        LoadNetModule("NetBlade\\Netblade.dll");
        App = CreateApp(hInstance, nCmdShow, cmd);

        assert(App);

        if (application_start(App) == 0)
                return 0;

        Set007E7470To01();
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


void startup_cb(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
        if (!blade)
                return;

        /*
         * Pass blade dll module pointer to blade main function instead of exe process
         * handler to avoid following error from DialogBoxParam function when game
         * launcher starting:
         *   error 1813: ”казанный тип ресурса в файле образа отсутствует
        */

        BladeWinMain(blade, hPrevInstance, lpCmdLine, nCmdShow);
}


#pragma argsused
WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
        void (*BldStartup)(void *) = NULL;

        blade = LoadLibrary("Blade.exe");

        if (!blade)
                return 1;

        LoadNetModule = (void *)((char *)blade + 0x001B57C2);
        Set007E7470To01 = (void *)((char *)blade + 0x001ABD01);
        OnEvent = (void *)((char *)blade + 0x001AE837);
        get_map_for_net_game = (void *)((char *)blade + 0x001B09A6);
        _thiscall_BBlibc_name_set = (void *)((char *)blade + 0x001B9BA4);
        _thiscall_BBlibc_name_clear = (void *)((char *)blade + 0x001B9B98);
        _thiscall_BBlibc_name_copy = (void *)((char *)blade + 0x001B9B9E);
        BBlibc_format_string = (void *)((char *)blade + 0x001B9BF2);
        _thiscall_application_load_level_script = (void *)((char *)blade + 0x000131D2);
        _thiscall_application_init2 = (void *)((char *)blade + 0x0000EFB0);
        message_manager_print = (void *)((char *)blade + 0x001B9BDA);
        bld_new = (void *)((char *)blade + 0x001B96B4);

        var007C59B8 = (void *)((char *)blade + 0x003C59B8);
        msg_manager_ptr = (void *)((char *)blade + 0x001A67B4);
        net_data_ptr = (void *)((char *)blade + 0x003EAD20);
        application_ptr = (void *)((char *)blade + 0x003EC6F4);
        application_methods_ptr = (void *)((char *)blade + 0x001BE7D8);

        BldStartup = (void *)((char *)blade + 0x001BA062);

        BldStartup(startup_cb);

        return 0;
}
//---------------------------------------------------------------------------

