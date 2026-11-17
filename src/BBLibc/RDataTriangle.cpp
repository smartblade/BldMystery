#include "RDataTriangle.h"
#include "IDataFile.h"
#include "Name.h"
#include "ODataFile.h"
#include <Raster/RasterDevice.h>


#ifndef BLD_NATIVE

#ifdef __cplusplus
extern "C" {
#endif

    int gbl_loading_packed;

#ifdef __cplusplus
}
#endif

#endif


/*
* Module:                 BBLibc.dll
* Data address:           0x1004BF70
*/
static char gbl_empty_bmp_name[4];


/*
* Module:                 BBLibc.dll
* Entry point:            0x10007F40
* VC++ mangling:          ??4B_RDataTriangle@@QAEAAV0@ABV0@@Z
*/
#ifndef BLD_NATIVE
B_RDataTriangle &B_RDataTriangle::operator=(const B_RDataTriangle &other)
{
    return *this;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10040D58
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_ModelTriangleData@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_ModelTriangleData &data)
{
    B_Name bmpName;
    file >> bmpName;
    if (B_3D_raster_device != nullptr)
    {
        data.bmpHandle = B_3D_raster_device->BmpHandle(bmpName);
    }
    else
    {
        data.bmpHandle = -1;
    }
    file
        >> data.u[0]
        >> data.u[1]
        >> data.u[2]
        >> data.v[0]
        >> data.v[1]
        >> data.v[2];
    if (gbl_loading_packed == 0)
    {
        data.v[0] *= -1.0;
        data.v[1] *= -1.0;
        data.v[2] *= -1.0;
    }
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10040E61
* VC++ mangling:          ??6@YAAAVB_ODataFile@@AAV0@ABVB_ModelTriangleData@@@Z
*/

B_ODataFile &operator <<(B_ODataFile &file, const B_ModelTriangleData &data)
{
    const char *bmpName = B_3D_raster_device->BmpName(data.bmpHandle);
    if (bmpName != nullptr)
    {
        file << B_Name(bmpName);
    }
    else
    {
        file << B_Name(gbl_empty_bmp_name);
    }
    file
        << data.u[0]
        << data.u[1]
        << data.u[2]
        << data.v[0]
        << data.v[1]
        << data.v[2];
    return file;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10040F51
* VC++ mangling:          ??0B_RDataTriangle@@QAE@XZ
*/
#ifndef BLD_NATIVE
B_RDataTriangle::B_RDataTriangle()
{

}
#endif
