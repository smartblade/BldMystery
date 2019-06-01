//---------------------------------------------------------------------------

#include <float.h>
#include "bld_ext_funcs.h"

//---------------------------------------------------------------------------


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
        HMODULE shw32;

        blade = LoadLibrary("Blade.dll");

        if (!blade)
                return 1;

        shw32 = LoadLibrary("Shw32.dll");

        _cdecl_read_points = (void *)((char *)blade + 0x000088F4);
        _cdecl_read_point = (void *)((char *)blade + 0x0000ACDD);
        _thiscall_0040AD82 = (void *)((char *)blade + 0x0000AD82);
        _thiscall_0040ADA8 = (void *)((char *)blade + 0x0000ADA8);
        _thiscall_application_init2 = (void *)((char *)blade + 0x0000F040);
        _thiscall_application_set_mode = (void *)((char *)blade + 0x00011EB9);
        _thiscall_application_process_event = (void *)((char *)blade + 0x000121CE);
        _thiscall_application_prepare_level = (void *)((char *)blade + 0x00014F7F);
        _cdecl_read_sectors = (void *)((char *)blade + 0x00032379);
        _thiscall_00439F5D = (void *)((char *)blade + 0x00039F5D);
        _cdecl_read_light = (void *)((char *)blade + 0x0004AD38);
        _thiscall_00451A21 = (void *)((char *)blade + 0x00051A21);
        _thiscall_camera_init = (void *)((char *)blade + 0x000EAD20);
        _thiscall_camera_004EB1AA = (void *)((char *)blade + 0x000EB1AA);
        _cdecl_Set007EA988To01 = (void *)((char *)blade + 0x001AC791);
        _cdecl_OnEvent = (void *)((char *)blade + 0x001AF2CE);
        _cdecl_reset_client_map_name = (void *)((char *)blade + 0x001B1431);
        _cdecl_get_map_for_net_game = (void *)((char *)blade + 0x001B143D);
        _cdecl_LoadNetModule = (void *)((char *)blade + 0x001B65D2);
        BldStartup = (void *)((char *)blade + 0x001BC34A);
        _stdcall_BladeWinMain = (void *)((char *)blade + 0x00010CC2);

        application_methods_ptr = (void *)((char *)blade + 0x001C0848);
        init_start = (void *)((char *)blade + 0x001C8000);
        init_end = (void *)((char *)blade + 0x001C8240);
        world_points_ptr = (void *)((char *)blade + 0x001DF898);
        game_state_ptr = (void *)((char *)blade + 0x001E0B88);
        anims_ptr = (void *)((char *)blade + 0x003072A8);
        sound_device_ptr = (void *)((char *)blade + 0x003C8ED0);
        client_map_name = (void *)((char *)blade + 0x003EE018);
        net_game_name = (void *)((char *)blade + 0x003EE0B8);
        net_max_players_ptr = (void *)((char *)blade + 0x003EE138);
        net_data_ptr = (void *)((char *)blade + 0x003EE2C4);
        application_ptr = (void *)((char *)blade + 0x003EFC94);
        __onexitbegin_ptr = (void *)((char *)blade + 0x003F00EC);

        bld_new = (void *)GetProcAddress(shw32, "shi_new");

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

