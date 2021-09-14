#include <BWorld/MapTexture.h>

#include <Raster/RasterDevice.h>
#include <BBLibc.h>


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0044D702
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_Texture@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_Texture &texture)
{
    B_Name textureName;
    file >> textureName;
    texture.handle = B_3D_raster_device->BmpHandle(textureName);
    file
        >> texture.xTransform
        >> texture.yTransform
        >> texture.xOffset
        >> texture.yOffset;
    if (B_3D_raster_device->ClassId() == 4)
    {
        texture.xTransform *= (1.0 / 256.0);
        texture.yTransform *= (1.0 / 256.0);
        texture.xOffset *= (1.0 / 256.0);
        texture.yOffset *= (1.0 / 256.0);
    }
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
* Entry point:            0x0044D88C
* VC++ mangling:          ??5@YAAAVB_IDataFile@@AAV0@AAVB_MapTexture@@@Z
*/

B_IDataFile &operator >>(B_IDataFile &file, B_MapTexture &mapTexture)
{
    file
        >> mapTexture.unknown000
        >> mapTexture.fUnknown004
        >> mapTexture.texture
        >> mapTexture.fUnknown048
        >> mapTexture.fUnknown04C;
    return file;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
