#include "ROpenGLDeviceDLL.h"


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001E100
* VC++ mangling:          ??0B_OpenGLRasterDevice@@QAE@PAUHWND__@@PAUHINSTANCE__@@@Z
*/
#ifdef BLD_NATIVE_CONSTRUCTOR
B_OpenGLRasterDevice::B_OpenGLRasterDevice(HWND window, HMODULE rasterModule)
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
* Module:                 rOpenGL.dll
* Entry point:            0x100289BA
*/

B_3DRasterDevice *CreateRaster(
    HWND window, HMODULE mainModule, HMODULE rasterModule)
{
    ERM_GetResource = (RM_GetResourceFunc)
        GetProcAddress(mainModule, "RM_GetResource");
    assert(ERM_GetResource);
    ERM_FreeResource = (RM_FreeResourceFunc)
        GetProcAddress(mainModule, "RM_FreeResource");
    assert(ERM_FreeResource);
    UpdateAGTexture = (UpdateAGTextureFunc)
        GetProcAddress(mainModule, "UpdateAGTexture");
    assert(UpdateAGTexture);
    return new B_OpenGLRasterDevice(window, rasterModule);
}

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10028A98
*/

int DestroyRaster(B_3DRasterDevice* raster)
{
    delete raster;
    return true;
}
