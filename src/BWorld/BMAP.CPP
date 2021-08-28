#include <BWorld/BMap.h>

#include <raster_device.h>
#include <AnalyticGeometry/Polygon.h>
#include "bld_misc_funcs.h"


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x0042E011
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_SectorLights@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_SectorLights &lights)
{
    file >> lights.ambient >> lights.flat;
    return file;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x0042E06B
* VC++ mangling:          ??0B_Sector@@QAE@XZ
*/
#ifdef BLD_NATIVE
B_Sector::B_Sector()
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x0042E464
* VC++ mangling:          ?CalculateBoundingBox@B_Sector@@QAEXXZ
*/
#ifdef BLD_NATIVE
void B_Sector::CalculateBoundingBox()
{
}
#endif



/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x0042FFDC
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Sector@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_Sector &sector)
{
    unsigned int numSurfaces;
    B_Name atmosphereName;

    file >> atmosphereName;
    sector.atmosphere = B_3D_raster_device->GetAtmosphere(atmosphereName);
    file >> sector.lights;
    file >> numSurfaces;
    for (unsigned int i = 0; i < numSurfaces; i++)
    {
        B_Surface *surface = ReadSurface(file);
        if (surface->GetPolygon()->numVertices < 3)
        {
            delete surface;
        }
        else
        {
            sector.Append(surface);
        }
    }
    sector.CalculateBoundingBox();
    return file;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x00432379
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Map@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_Map &map)
{
    return (file >> static_cast<B_PtrArray<B_Sector> &>(map));
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
