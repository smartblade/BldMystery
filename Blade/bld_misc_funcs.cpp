
#include <bld_system.h>
#include "App.h"
#ifdef BLD_NATIVE
    #define BLD_EXT_FUNCS
    #include "bld_ext_funcs.h"
#endif
#include "bld_misc_funcs.h"

__declspec(naked) void _thiscall_application_load_level(char *map)
{
    _asm { jmp B_WinApp::load_level}
}

__declspec(naked) void _thiscall_application_wait_for_event(void)
{
    _asm { jmp B_WinApp::process_events}
}

__declspec(naked) void _thiscall_application_mark_level_to_load(char *map)
{
    _asm { jmp B_App::mark_level_to_load}
}

__declspec(naked) void _thiscall_application_read_level(char *file_name)
{
    _asm { jmp B_App::read_level}
}

/*
* Module:                 Blade.exe
* Entry point:            0x004088F4
*/

#ifdef BLD_NATIVE

__declspec(naked) B_IDataFile * read_points(B_IDataFile *file, array_t *points)
{
    _asm { jmp _cdecl_read_points }
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x0040ACDD
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAUpoint_t@@@Z
*/

#ifdef BLD_NATIVE

__declspec(naked) B_IDataFile& operator >>(B_IDataFile& file, point_t &point)
{
    _asm { jmp _cdecl_read_point }
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00432379
*/

#ifdef BLD_NATIVE

__declspec(naked) B_IDataFile * read_sectors(B_IDataFile *file, array_t *sectors)
{
    _asm { jmp _cdecl_read_sectors }
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x0044AD38
*/

#ifdef BLD_NATIVE

__declspec(naked) light_t * read_light(B_IDataFile *file)
{
    _asm { jmp _cdecl_read_light }
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00451A21
* VC++ mangling:          ?unknown_00451A21@unknown_18F8_class@@QAEXPAXHH@Z
*/

#ifdef BLD_NATIVE

__declspec(naked) void unknown_18F8_class::unknown_00451A21(void *, int, int)
{
    _asm { jmp _thiscall_00451A21 }
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004EAD20
* VC++ mangling:          ??0camera_t@@QAE@HABVB_Name@@@Z
*/

#ifdef BLD_NATIVE

__declspec(naked) camera_t *camera_t::init(int unknown, const B_Name &name)
{
    _asm { jmp _thiscall_camera_init}
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x004EB1AA
* VC++ mangling:          ?unknown_004EB1AA@camera_t@@QAEXPAX@Z
*/

#ifdef BLD_NATIVE

__declspec(naked) void camera_t::unknown_004EB1AA(void *)
{
    _asm { jmp _thiscall_camera_004EB1AA }
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005AC791
*/

#ifdef BLD_NATIVE

__declspec(naked) void Set007EA988To01()
{
    _asm { jmp _cdecl_Set007EA988To01 }
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005AF2CE
*/

#ifdef BLD_NATIVE

__declspec(naked) void OnEvent(int a, int b)
{
    _asm { jmp _cdecl_OnEvent }
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B1431
*/

#ifdef BLD_NATIVE

__declspec(naked) void reset_client_map_name()
{
    _asm { jmp _cdecl_reset_client_map_name }
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B143D
*/

#ifdef BLD_NATIVE

__declspec(naked) char *get_map_for_net_game(const char *map)
{
    _asm { jmp _cdecl_get_map_for_net_game }
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B65D2
*/

#ifdef BLD_NATIVE

__declspec(naked) void LoadNetModule(char *fileName)
{
    _asm { jmp _cdecl_LoadNetModule }
}

#endif
