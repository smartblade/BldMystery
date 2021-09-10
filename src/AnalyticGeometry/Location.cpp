#include <AnalyticGeometry/Location.h>

#include <bld_system.h>
#include "bld_misc_funcs.h"


/*
* Module:                 Blade.exe
* Entry point:            0x00040AD10
* VC++ mangling:          ??0location_t@@QAE@ABVB_Vector@@NNN@Z
*/
#ifndef BLD_NATIVE
location_t::location_t(
    const B_Vector &position,
    double rotationX,
    double rotationY,
    double rotationZ)
{
}
#endif

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

#ifndef BLD_NATIVE

void location_t::setPosition(const B_Vector &pos)
{
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x0040ADA8
* VC++ mangling:          ?setOrientation@location_t@@QAEXABVB_Vector@@@Z
*/

#ifndef BLD_NATIVE

void location_t::setOrientation(const B_Vector &orientation)
{
}

#endif