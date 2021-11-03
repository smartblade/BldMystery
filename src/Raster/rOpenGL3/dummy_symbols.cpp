#ifndef BLD_NATIVE

#include <bld_system.h>

class B_Matrix
{
public:
    B_Matrix();
};

B_Matrix::B_Matrix()
{
}

#ifdef __cplusplus
extern "C" {
#endif

void *ERM_GetResource;
void *ERM_FreeResource;
void *UpdateAGTexture;
void *glColorTableEXT;
void *glColorSubTableEXT;
void *glGetColorTableEXT;
void *glGetColorTableParameteriv;
void *glGetColorTableParameterfv;
void *glActiveTextureARB;
void *glMultiTexCoord1fARB;
void *glMultiTexCoord2fARB;
void *glMultiTexCoord2fvARB;
void *glFogCoordfEXT;
void *glFogCoordfvEXT;
void *glGetColorTableEXT2;
void *glFogCoorddvEXT;
void *glNewBufferRegion;
void *glDeleteBufferRegion;
void *glReadBufferRegion;
void *glDrawBufferRegion;
void *glBufferRegionEnabled;
void *wglGetExtensionsStringEXT;
void *wglSwapIntervalEXT;
void *wglGetSwapIntervalEXT;
void *glCompressedTexImage3DARB;
void *glCompressedTexImage2DARB;
void *glCompressedTexImage1DARB;
void *glCompressedTexSubImage3DARB;
void *glCompressedTexSubImage2DARB;
void *glCompressedTexSubImage1DARB;
void *glGetCompressedTexImageARB;
void *glCombinerParameterfvNV;
void *glCombinerParameterivNV;
void *glCombinerParameterfNV;
void *glCombinerParameteriNV;
void *glCombinerInputNV;
void *glCombinerOutputNV;
void *glFinalCombinerInputNV;
void *glGetCombinerInputParameterfvNV;
void *glGetCombinerInputParameterivNV;
void *glGetCombinerOutputParameterfvNV;
void *glGetCombinerOutputParameterivNV;
void *glGetFinalCombinerInputfvNV;
void *glGetFinalCombinerInputivNV;

#ifdef __cplusplus
}
#endif

#endif
