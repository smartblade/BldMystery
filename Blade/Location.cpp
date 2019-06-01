#include <bld_system.h>
#include "Location.h"
#include "bld_misc_funcs.h"

/*
* Module:                 Blade.exe
* Entry point:            0x0040AD82
* VC++ mangling:          ?setPosition@location_t@@QAEXABUpoint_t@@@Z
*/

#ifdef BLD_NATIVE

void location_t::setPosition(const point_t &pos)
{
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x0040ADA8
* VC++ mangling:          ?setOrientation@location_t@@QAEXABUpoint_t@@@Z
*/

#ifdef BLD_NATIVE

void location_t::setOrientation(const point_t &orientation)
{
}

#endif