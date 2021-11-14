#include <AnalyticGeometry/ViewPose.h>

#include <bld_system.h>


/*
* Module:                 Blade.exe
* Entry point:            0x00040AD10
* VC++ mangling:          ??0B_ViewPose@@QAE@ABVB_Vector@@NNN@Z
*/
#ifndef BLD_NATIVE
B_ViewPose::B_ViewPose(
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
* VC++ mangling:          ??1B_ViewPose@@QAE@XZ
*/

B_ViewPose::~B_ViewPose()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x0040AD82
* VC++ mangling:          ?setPosition@B_ViewPose@@QAEXABVB_Vector@@@Z
*/

#ifndef BLD_NATIVE

void B_ViewPose::setPosition(const B_Vector &pos)
{
}

#endif


/*
* Module:                 Blade.exe
* Entry point:            0x0040ADA8
* VC++ mangling:          ?setOrientation@B_ViewPose@@QAEXABVB_Vector@@@Z
*/

#ifndef BLD_NATIVE

void B_ViewPose::setOrientation(const B_Vector &orientation)
{
}

#endif