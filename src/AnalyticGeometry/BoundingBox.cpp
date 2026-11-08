#include <AnalyticGeometry/BoundingBox.h>

#include <bld_system.h>
#include <AnalyticGeometry/Vector.h>


/*
* Module:                 Blade.exe
* Entry point:            0x00401000
* VC++ mangling:          ??0B_Sphere@@QAE@XZ
*/

B_Sphere::B_Sphere()
:
    radius(0.0)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x00401548
* VC++ mangling:          ??0B_BoundingBox@@QAE@XZ
*/

B_BoundingBox::B_BoundingBox()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004015C5
* VC++ mangling:          ??0B_BoundingBox@@QAE@ABVB_Vector@@0@Z
*/

B_BoundingBox::B_BoundingBox(const B_Vector &minCoords, const B_Vector &maxCoords)
:
    minCoords(minCoords),
    maxCoords(maxCoords)
{
}
