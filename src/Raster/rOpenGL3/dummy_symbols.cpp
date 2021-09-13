#ifndef BLD_NATIVE

#include <bld_system.h>

class B_OpenGLRasterDevice
{
public:
    B_OpenGLRasterDevice(HWND window, HMODULE rasterModule);
};

B_OpenGLRasterDevice::B_OpenGLRasterDevice(HWND window, HMODULE rasterModule)
{
}

#ifdef __cplusplus
extern "C" {
#endif

void *ERM_GetResource;
void *ERM_FreeResource;
void *UpdateAGTexture;

#ifdef __cplusplus
}
#endif

#endif
