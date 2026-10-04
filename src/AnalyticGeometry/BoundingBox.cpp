#include <AnalyticGeometry/BoundingBox.h>

#include <bld_system.h>
#include <AnalyticGeometry/Vector.h>


/*
* Module:                 Blade.exe
* Entry point:            0x00401000
* VC++ mangling:          ??0B_Sphere@@QAE@XZ
*/

B_Sphere::B_Sphere()
{
    this->center.x = 0.0;
    this->center.y = 0.0;
    this->center.z = 0.0;
    this->radius = 0.0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00401548
* VC++ mangling:          ??0B_BoundingBox@@QAE@XZ
*/

#ifndef BLD_NATIVE
B_BoundingBox::B_BoundingBox()
{

}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004015C5
* VC++ mangling:          ??0B_BoundingBox@@QAE@ABVB_Vector@@0@Z
*/

B_BoundingBox::B_BoundingBox(const B_Vector& minCoords, const B_Vector& maxCoords)
{
    this->minCoords = minCoords;
    this->maxCoords = maxCoords;
}

/*
* Module:                 Blade.exe
* Entry point:            0x0044F052
* VC++ mangling:          ?Intersects@B_BoundingBox@@QBE_NPBVB_Sector@@@Z
*/

#ifndef BLD_NATIVE
bool B_BoundingBox::Intersects(const B_Sector* sector) const
{
    return false;
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004501C1
* VC++ mangling:          ?CollectIntersectingSectors@B_BoundingBox@@QAEXABV?$B_PtrArray@VB_Sector@@@@AAV2@@Z
*/

void B_BoundingBox::CollectIntersectingSectors(const B_PtrArray<B_Sector>& sectors, B_PtrArray<B_Sector>& outBuffer)
{
    for (unsigned int i = 0; i < sectors.size; ++i)
    {
        B_Sector* sector = sectors.elements[i];

        if (this->Intersects(sector))
        {
            outBuffer.Append(sector);
        }
    }

}


