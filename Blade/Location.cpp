#include <bld_system.h>
#include "Location.h"
#include "bld_misc_funcs.h"

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0040AD77
* VC++ mangling:          ??1location_t@@QAE@XZ
*/

location_t::~location_t()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040AD82
* VC++ mangling:          ?setPosition@location_t@@QAEXABVB_Vector@@@Z
*/

#ifdef BLD_NATIVE

void location_t::setPosition(const B_Vector &pos)
{
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x0040ADA8
* VC++ mangling:          ?setOrientation@location_t@@QAEXABVB_Vector@@@Z
*/

#ifdef BLD_NATIVE

void location_t::setOrientation(const B_Vector &orientation)
{
}

#endif