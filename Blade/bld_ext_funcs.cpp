
#include <bld_system.h>
#include "application.h"
#include "bld_ext_funcs.h"

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
    _asm { jmp application_t::mark_level_to_load}
}

__declspec(naked) void _thiscall_application_read_level(char *file_name)
{
    _asm { jmp application_t::read_level}
}

/*
* Module:                 Blade.exe
* Entry point:            0x004EAD20
*/

#ifdef BLD_NATIVE

__declspec(naked) camera_t *camera_t::init(int unknown, const B_Name &name)
{
    _asm { jmp _thiscall_camera_init}
}

#endif
