#include <bld_system.h>
#include "Location.h"
#include "bld_ext_funcs.h"

/*
* Module:                 Blade.exe
* Entry point:            0x0040AD82
*/

#ifdef BLD_NATIVE

__declspec(naked) void location_t::setPosition(const point_t &pos)
{
    _asm { jmp _thiscall_0040AD82}
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x0040ADA8
*/

#ifdef BLD_NATIVE

__declspec(naked) void location_t::setOrientation(const point_t &orientation)
{
    _asm { jmp _thiscall_0040ADA8}
}

#endif