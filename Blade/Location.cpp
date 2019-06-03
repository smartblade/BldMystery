#include <bld_system.h>
#include "Location.h"
#include "bld_misc_funcs.h"

/*
* Module:                 Blade.exe
* Entry point:            0x0040AD82
* VC++ mangling:          ?setPosition@location_t@@QAEXABVB_Vector@@@Z
*/

void location_t::setPosition(const B_Vector &pos)
{
    this->position = pos;
    updateMatrix();
}


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


/*
* Module:                 Blade.exe
* Entry point:            0x0040AE60
* VC++ mangling:          ?updateMatrix@location_t@@QAEXXZ
*/

#ifdef BLD_NATIVE

void location_t::updateMatrix()
{
}

#endif