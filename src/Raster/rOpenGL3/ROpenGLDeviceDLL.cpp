#include "ROpenGLDeviceDLL.h"

#include "ConfigSections.h"
#include "GlExtensions.h"
#include <AnalyticGeometry/ViewPose.h>
#include <View/CameraView.h>
#include <math.h>
#include <stdio.h>


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001E100
* VC++ mangling:          ??0B_OpenGLRasterDevice@@QAE@PAUHWND__@@PAUHINSTANCE__@@@Z
*/

B_OpenGLRasterDevice::B_OpenGLRasterDevice(HWND window, HMODULE rasterModule)
    : unknown0847B4(0), domeColor(255, 255, 255), fullScreenMode(NULL)
{
    mout << "Initializing OpenGL device.\n";
    this->isFog = false;
    this->fogEnabled = false;
    this->window = window;
    this->rasterModule = rasterModule;
    DEVMODE devMode;
    memset(&devMode, 0, sizeof(devMode));
    devMode.dmSize = sizeof(devMode);
    this->currentDisplayHeight = -1;
    this->currentDisplayWidth = -1;
    if (EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode))
    {
        this->currentDisplayWidth = devMode.dmPelsWidth;
        this->currentDisplayHeight = devMode.dmPelsHeight;
        this->currentDisplayDepth = devMode.dmBitsPerPel;
        this->currentDisplayFrequency = devMode.dmDisplayFrequency;
    }
    this->isGammaRampSet = false;
    this->useTextureFont = true;
    this->tFontScale = 0.5;
    this->tFontOpaque = false;
    this->backgroundRegion = -1;
    this->useCreditsHack = true;
    this->backgroundImageHeight = 0;
    this->backgroundImageWidth = 0;
    this->showStats = false;
    this->useMipmaps = false;
    this->unknown0847F0 = 0;
    this->unknown0847F4 = 0;
    this->hasTextureEnvCombine = false;
    this->hasTextureFilterAnisotropic = false;
    this->hasTextureLodBias = false;
    this->hasFogCoord = false;
    this->hasARBTextureCompression = false;
    this->hasNVRegisterCombiners = false;
    this->hasSGISMipmapping = false;
    this->textureLODBias = 0.0;
    this->useCompressedTextures = false;
    this->invertOGLLight = false;
    this->useOGLLight = false;
    this->useOGLFog = true;
    this->notUsePalettes = false;
    this->textureMagnificationFunc = GL_LINEAR;
    this->textureMinifyingFunc = GL_LINEAR;
    this->GetVideoModes();
    char cfgFile[256];
    strcpy(cfgFile, GetConfigDirectory());
    strcat(cfgFile, "/rOpenGL.ini");
    B_VideoModeSection videoModeSection(cfgFile);
    if (!videoModeSection.isWindow)
    {
        this->SetVideoModeParameters(
            videoModeSection.bpp,
            videoModeSection.width,
            videoModeSection.height,
            videoModeSection.frequency);
    }
    this->fogColor[2] = 0.7f;
    this->fogColor[1] = 0.7f;
    this->fogColor[0] = 0.7f;
    this->fogColor[3] = 0.0f;
    this->fogDensity = 1e-05f;
    this->fogFactor = 0.02f;
    this->flags = RASTER_FLAGS_TEXTURE | RASTER_FLAGS_0002 | RASTER_FLAGS_0010;
    this->cacheStretchImage = false;
    this->unknown084870 = 0;
    this->unknown084874 = -1;
    this->CreateContext();
    mout << "OpenGL Info:\n";
    mout << vararg("  Vendor: %s.\n", glGetString(GL_VENDOR));
    mout << vararg("  Renderer: %s.\n", glGetString(GL_RENDERER));
    mout << vararg("  Version: %s.\n", glGetString(GL_VERSION));
    GLint maxTextureSize;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxTextureSize);
    mout << vararg("  MaxTextureSize: %d.\n", maxTextureSize);
    GLint stencilBits;
    glGetIntegerv(GL_STENCIL_BITS, &stencilBits);
    mout << vararg("  StencilBits: %d.\n", stencilBits);
    GLint redBits, greenBits, blueBits;
    glGetIntegerv(GL_RED_BITS, &redBits);
    glGetIntegerv(GL_GREEN_BITS, &greenBits);
    glGetIntegerv(GL_BLUE_BITS, &blueBits);
    mout << vararg("  ColorBits: %d %d %d.\n", redBits, greenBits, blueBits);
    GLint depthBits;
    glGetIntegerv(GL_DEPTH_BITS, &depthBits);
    mout << vararg("  DepthBits: %d.\n", depthBits);
    this->LoadExtensions();
    mout << vararg("  Available video modes: %d.\n", this->videoModes.size);
    this->ClsRGB(0, 0, 0);
    glEnable(GL_SCISSOR_TEST);
    this->clipActive = false;
    this->clipX = 0;
    this->clipY = 0;
    this->clipWidth = this->width;
    this->clipHeight = this->height;
    this->depthMode = 0;
    this->textureMode = false;
    this->blendMode = 0;
    GLfloat pixels[] =
    {
        0.2f, 0.2f, 0.2f,
        0.2f, 0.2f, 0.2f,
        0.2f, 0.2f, 0.2f,
        0.2f, 0.2f, 0.2f,
        0.2f, 0.2f, 0.2f,
        0.2f, 0.2f, 0.2f,
        0.5f, 0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
    };
    glBindTexture(GL_TEXTURE_1D, 2001);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage1D(
        GL_TEXTURE_1D, 0, GL_RGB, sizeof(pixels) / (sizeof(pixels[0]) * 3),
        0, GL_RGB, GL_FLOAT, &pixels);
    this->LoadBitmapWinResource(105, 2002);
    this->LoadBitmapWinResource(108, 2003);
    this->LoadBitmapWinResource(103, 2004);
    this->LoadBitmapWinResource(107, 2005);
    this->LoadBitmapWinResource(120, 2006);
    this->projectionZ = -1.0;
    this->projectionHeight = -1;
    this->projectionWidth = -1;
    glNewList(GL_LIST_START_2D, GL_COMPILE);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glScalef(2.0 / this->width, 2.0 / this->height, 1.0);
    glTranslatef(-(this->width / 2.0), -(this->height / 2.0), 0.0);
    glViewport(0, 0, this->width, this->height);
    glEndList();
    glNewList(GL_LIST_END_2D, GL_COMPILE);
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glEndList();
    this->UpdateColorAdjustment();
    this->BWRender = 0;
    mout << "OpenGL initialized.\n\n";
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001F599
* VC++ mangling:          ??1B_OpenGLRasterDevice@@UAE@XZ
*/
#ifndef BLD_NATIVE
B_OpenGLRasterDevice::~B_OpenGLRasterDevice()
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
* Entry point:            0x1001FA3E
* VC++ mangling:          ?CreateContext@B_OpenGLRasterDevice@@QAEHXZ
*/
#ifndef BLD_NATIVE
int B_OpenGLRasterDevice::CreateContext()
{
    return 0;
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
* Entry point:            0x1001FDF8
* VC++ mangling:          ?SwapBuffers@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::SwapBuffers()
{
    if (!::SwapBuffers(this->deviceContext))
    {
        OutputWin32Error("Error in SwapBuffers().");
        mout << "B_OpenGLRasterDevice::SwapBuffers() -> Fallo en SwapBuffers().\n";
    }
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001FE3A
* VC++ mangling:          ?SetFlags@B_OpenGLRasterDevice@@UAEXJ@Z
*/

void B_OpenGLRasterDevice::SetFlags(long flags)
{
    this->flags = flags;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001FE50
* VC++ mangling:          ?SetProjection@B_OpenGLRasterDevice@@UAEXABVB_CameraView@@@Z
*/

void B_OpenGLRasterDevice::SetProjection(const B_CameraView &cameraView)
{
    RECT clientRectangle;
    if (this->FullScreen() && this->fullScreenMode != NULL)
    {
        this->width = this->fullScreenMode->width;
        this->height = this->fullScreenMode->height;
    }
    else if (GetClientRect(this->window, &clientRectangle))
    {
        this->width = abs(clientRectangle.left - clientRectangle.right);
        this->height = abs(clientRectangle.bottom - clientRectangle.top);
    }
    else
    {
        this->width = 640;
        this->height = 480;
    }
    if (
        (this->width != this->projectionWidth) ||
        (this->height != this->projectionHeight) ||
        (this->projectionZ != cameraView.z))
    {
        this->xCentre = this->width / 2;
        this->yCentre = this->height / 2;
        B_TrisDevice::SetProjection(cameraView);
        glViewport(0, 0, this->width, this->height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        double left = -100.0f * cameraView.width / (2.0f * cameraView.z);
        double right = -left;
        /* FIXME incorrect work for other aspect ratios */
        double displayRatio = 0.75;
        double bottom = left * displayRatio;
        double top = right * displayRatio;
        glFrustum(left, right, bottom, top, 100.0, 1000000.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glScaled(1.0, -1.0, -1.0);
        glScissor(1, 1, this->width - 2, this->height - 2);
        glGetDoublev(GL_PROJECTION_MATRIX, this->projectionMatrix);
        glGetDoublev(GL_MODELVIEW_MATRIX, this->modelviewMatrix);
        glGetIntegerv(GL_VIEWPORT, this->viewport);
        this->projectionZ = cameraView.z;
        this->projectionWidth = this->width;
        this->projectionHeight = this->height;
        glNewList(GL_LIST_START_2D, GL_COMPILE);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        glOrtho(0.0, this->width, 0.0, this->height, -499950.0, 499950.0);
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glViewport(0, 0, this->width, this->height);
        glEndList();
        glNewList(GL_LIST_END_2D, GL_COMPILE);
        glMatrixMode(GL_MODELVIEW);
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glEndList();
        glNewList(510, GL_COMPILE);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();
        glOrtho(0.0, this->width, 0.0, this->height, 100.0, -1000000.0);
        glEndList();
        glNewList(511, GL_COMPILE);
        glMatrixMode(GL_MODELVIEW);
        glPopMatrix();
        glMatrixMode(GL_PROJECTION);
        glPopMatrix();
        glEndList();
    }
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002022E
* VC++ mangling:          ?Cls@B_OpenGLRasterDevice@@UAEXVB_Color@@@Z
*/

void B_OpenGLRasterDevice::Cls(B_Color color)
{
    if (this->backgroundRegion != -1)
    {
        glDrawBufferRegion(
            this->backgroundRegion, 0, 0, this->width, this->height, 0, 0);
    }
    else
    {
        glClearColor(color.r / 255.0, color.g / 255.0, color.b / 255.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100202D7
* VC++ mangling:          ?ClsRGB@B_OpenGLRasterDevice@@UAEXEEE@Z
*/

void B_OpenGLRasterDevice::ClsRGB(byte r, byte g, byte b)
{
    if (this->backgroundRegion != -1)
    {
        glDrawBufferRegion(
            this->backgroundRegion, 0, 0, this->width, this->height, 0, 0);
    }
    else
    {
        glClearColor(r / 255.0, g / 255.0, b / 255.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10020380
* VC++ mangling:          ?unknown0EC@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown0EC()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002045B
* VC++ mangling:          ?StartScene@B_OpenGLRasterDevice@@UAEXPAVB_ViewPose@@@Z
*/

void B_OpenGLRasterDevice::StartScene(B_ViewPose *cameraPose)
{
    B_TrisDevice::StartScene(cameraPose);
    if (cameraPose)
    {
        this->fromWorld = cameraPose->fromWorld;
        this->toWorld = cameraPose->toWorld;
    }
    if (this->invertOGLLight)
    {
        this->useOGLLight = !this->useOGLLight;
        if (this->useOGLLight)
        {
            glEnable(GL_NORMALIZE);
        }
        else
        {
            glDisable(GL_NORMALIZE);
        }
        this->invertOGLLight = false;
    }
    this->numTrisMaps = 0;
    this->numTrisObjs = 0;
    this->numParticles = 0;
    this->numTextureSwaps = 0;
    if (this->flags & RASTER_FLAGS_CLS)
    {
        this->Cls(B_Color(0, 0, 0));
    }
    this->fogEnabled = false;
    glDisable(GL_FOG);
    this->SetMode(RASTER_MODE_NONE);
    this->activeTextureHandle = -1;
    this->drawSunFlare = false;
    if (this->useCreditsHack)
    {
        if (
            this->backgroundImageWidth != 800 &&
            this->backgroundImageHeight != 600)
        {
            this->RemoveBackgroundImage();
        }
    }
    else
    {
        this->RemoveBackgroundImage();
    }
    if (this->useOGLLight)
    {
        glEnable(GL_LIGHTING);
        glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 0);
        float specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
        float unknown05Ch[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        float unknown024h[] = { 0.8f, 0.8f, 0.2f, 1.0f };
        float unknown014h[] = { 0.1f, 0.5f, 0.8f, 1.0f };
        float white[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        float unknown004h = 0.0f;
        float shininess = 5.0f;
        float unknown038 = 100.0f;
        float emission[] = { 0.01f, 0.01f, 0.01f, 0.0f };
        glMaterialfv(GL_FRONT, GL_AMBIENT, white);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, white);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
        glMaterialfv(GL_FRONT, GL_SHININESS, &shininess);
        glMaterialfv(GL_FRONT, GL_EMISSION, emission);
    }
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10020755
* VC++ mangling:          ?EndScene@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::EndScene()
{
    if (this->showStats)
    {
        char buffer[256];
        sprintf(buffer, "Tris mapa: %d.", this->numTrisMaps);
        glColor3d(1.0, 1.0, 1.0);
        this->DisplayText(10, 112, buffer, 0x00AAFF00);
        sprintf(buffer, "Tris Objs: %d.", this->numTrisObjs);
        this->DisplayText(10, 128, buffer, 0x00AAFF00);
        sprintf(buffer, "Particles: %d.", this->numParticles);
        this->DisplayText(10, 144, buffer, 0x00AAFF00);
        sprintf(buffer, "Texture Swaps: %d.", this->numTextureSwaps);
        this->DisplayText(10, 160, buffer, 0x00AAFF00);
    }
    if (!::SwapBuffers(this->deviceContext))
    {
        OutputWin32Error("Error in SwapBuffers().");
        mout << "B_OpenGLRasterDevice::EndScene -> Fallo en SwapBuffers().\n";
    }
    B_TrisDevice::EndScene();
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100208FB
* VC++ mangling:          ?ClearMap@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::ClearMap()
{
    this->UnLoadBitmaps();
    this->atmospheres.Clear(true);
    this->domeColor.b = 255;
    this->domeColor.g = 255;
    this->domeColor.r = 255;
    this->projectionZ = -1.0F;
    this->projectionHeight = -1;
    this->projectionWidth = -1;
    this->fogEnabled = false;
    glDisable(GL_FOG);
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10020B5D
* VC++ mangling:          ?HasWglExtension@B_OpenGLRasterDevice@@QAEHPBD@Z
*/
#ifndef BLD_NATIVE
int B_OpenGLRasterDevice::HasWglExtension(const char *extension)
{
    return false;
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10020B94
* VC++ mangling:          ?HasExtension@B_OpenGLRasterDevice@@QAEHPBD@Z
*/
#ifndef BLD_NATIVE
int B_OpenGLRasterDevice::HasExtension(const char *extension)
{
    return false;
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
* Entry point:            0x10021571
* VC++ mangling:          ?LoadExtensions@B_OpenGLRasterDevice@@QAEHXZ
*/

int B_OpenGLRasterDevice::LoadExtensions()
{
    mout << "\n";
    if (this->HasExtension("GL_EXT_paletted_texture"))
    {
        glColorTableEXT = (PFNGLCOLORTABLEEXTPROC)
            wglGetProcAddress("glColorTableEXT");
        glColorSubTableEXT = (PFNGLCOLORSUBTABLEEXTPROC)
            wglGetProcAddress("glColorSubTableEXT");
        glGetColorTableEXT = (PFNGLGETCOLORTABLEEXTPROC)
            wglGetProcAddress("glGetColorTableEXT");
        glGetColorTableParameteriv = (PFNGLGETCOLORTABLEPARAMETERIVPROC)
            wglGetProcAddress("glGetColorTableParameteriv");
        glGetColorTableParameterfv = (PFNGLGETCOLORTABLEPARAMETERFVPROC)
            wglGetProcAddress("glGetColorTableParameterfv");
        mout << "  Found GL_EXT_paletted_texture.\n";
    }
    if (this->HasExtension("GL_ARB_multitexture"))
    {
        glActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC)
            wglGetProcAddress("glActiveTextureARB");
        glMultiTexCoord1fARB = (PFNGLMULTITEXCOORD1FARBPROC)
            wglGetProcAddress("glMultiTexCoord1fARB");
        glMultiTexCoord2fARB = (PFNGLMULTITEXCOORD2FARBPROC)
            wglGetProcAddress("glMultiTexCoord2fARB");
        glMultiTexCoord2fvARB = (PFNGLMULTITEXCOORD2FVARBPROC)
            wglGetProcAddress("glMultiTexCoord2fvARB");
        mout << "  Found GL_ARB_multitexture.\n";
    }
    if (this->HasExtension("GL_EXT_texture_env_combine"))
    {
        mout << "  Found GL_EXT_texture_env_combine.\n";
        this->hasTextureEnvCombine = true;
    }
    if (this->HasExtension("GL_EXT_texture_filter_anisotropic"))
    {
        mout << "  Found GL_EXT_texture_filter_anisotropic.\n";
        this->hasTextureFilterAnisotropic = true;
    }
    if (this->HasExtension("GL_EXT_texture_lod_bias"))
    {
        mout << "  Found GL_EXT_texture_lod_bias.\n";
        this->hasTextureLodBias = true;
    }
    if (this->HasExtension("GL_EXT_fog_coord"))
    {
        glFogCoordfEXT = (PFNGLFOGCOORDFEXTPROC)
            wglGetProcAddress("glFogCoordfEXT");
        glFogCoordfvEXT = (PFNGLFOGCOORDFVEXTPROC)
            wglGetProcAddress("glFogCoordfvEXT");
        glGetColorTableEXT2 = (PFNGLGETCOLORTABLEEXTPROC)
            wglGetProcAddress("glGetColorTableEXT");
        glFogCoorddvEXT = (PFNGLFOGCOORDDVEXTPROC)
            wglGetProcAddress("glFogCoorddvEXT");
        this->hasFogCoord = true;
        this->useOGLFog = false;
        mout << "  Found GL_EXT_fog_coord.\n";
    }
    if (this->HasExtension("GL_KTX_buffer_region"))
    {
        glNewBufferRegion = (PFNGLNEWBUFFERREGIONPROC)
            wglGetProcAddress("glNewBufferRegion");
        glDeleteBufferRegion = (PFNGLDELETEBUFFERREGIONPROC)
            wglGetProcAddress("glDeleteBufferRegion");
        glReadBufferRegion = (PFNGLREADBUFFERREGIONPROC)
            wglGetProcAddress("glReadBufferRegion");
        glDrawBufferRegion = (PFNGLDRAWBUFFERREGIONPROC)
            wglGetProcAddress("glDrawBufferRegion");
        glBufferRegionEnabled = (PFNGLBUFFERREGIONENABLEDPROC)
            wglGetProcAddress("glBufferRegionEnabled");
        mout << "  Found GL_KTX_buffer_region.\n";
        if (glBufferRegionEnabled())
        {
            mout << "  Driver supports GL_KTX_buffer_region in an efficient manner.\n";
        }
    }
    if (this->HasExtension("GL_ARB_texture_compression"))
    {
        glCompressedTexImage3DARB = (PFNGLCOMPRESSEDTEXIMAGE3DARBPROC)
            wglGetProcAddress("glCompressedTexImage3DARB");
        glCompressedTexImage2DARB = (PFNGLCOMPRESSEDTEXIMAGE2DARBPROC)
            wglGetProcAddress("glCompressedTexImage2DARB");
        glCompressedTexImage1DARB = (PFNGLCOMPRESSEDTEXIMAGE1DARBPROC)
            wglGetProcAddress("glCompressedTexImage1DARB");
        glCompressedTexSubImage3DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE3DARBPROC)
            wglGetProcAddress("glCompressedTexSubImage3DARB");
        glCompressedTexSubImage2DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE2DARBPROC)
            wglGetProcAddress("glCompressedTexSubImage2DARB");
        glCompressedTexSubImage1DARB = (PFNGLCOMPRESSEDTEXSUBIMAGE1DARBPROC)
            wglGetProcAddress("glCompressedTexSubImage1DARB");
        glGetCompressedTexImageARB = (PFNGLGETCOMPRESSEDTEXIMAGEARBPROC)
            wglGetProcAddress("glGetCompressedTexImageARB");
        this->hasARBTextureCompression = true;
        mout << "  Found GL_ARB_texture_compression.\n";
    }
    if (this->HasExtension("GL_NV_register_combiners"))
    {
        glCombinerParameterfvNV = (PFNGLCOMBINERPARAMETERFVNVPROC)
            wglGetProcAddress("glCombinerParameterfvNV");
        glCombinerParameterivNV = (PFNGLCOMBINERPARAMETERIVNVPROC)
            wglGetProcAddress("glCombinerParameterivNV");
        glCombinerParameterfNV = (PFNGLCOMBINERPARAMETERFNVPROC)
            wglGetProcAddress("glCombinerParameterfNV");
        glCombinerParameteriNV = (PFNGLCOMBINERPARAMETERINVPROC)
            wglGetProcAddress("glCombinerParameteriNV");
        glCombinerInputNV = (PFNGLCOMBINERINPUTNVPROC)
            wglGetProcAddress("glCombinerInputNV");
        glCombinerOutputNV = (PFNGLCOMBINEROUTPUTNVPROC)
            wglGetProcAddress("glCombinerOutputNV");
        glFinalCombinerInputNV = (PFNGLFINALCOMBINERINPUTNVPROC)
            wglGetProcAddress("glFinalCombinerInputNV");
        glGetCombinerInputParameterfvNV = (PFNGLGETCOMBINERINPUTPARAMETERFVNVPROC)
            wglGetProcAddress("glGetCombinerInputParameterfvNV");
        glGetCombinerInputParameterivNV = (PFNGLGETCOMBINERINPUTPARAMETERIVNVPROC)
            wglGetProcAddress("glGetCombinerInputParameterivNV");
        glGetCombinerOutputParameterfvNV = (PFNGLGETCOMBINEROUTPUTPARAMETERFVNVPROC)
            wglGetProcAddress("glGetCombinerOutputParameterfvNV");
        glGetCombinerOutputParameterivNV = (PFNGLGETCOMBINEROUTPUTPARAMETERIVNVPROC)
            wglGetProcAddress("glGetCombinerOutputParameterivNV");
        /* FIXME Incorrect name. Should be GetFinalCombinerInputParameterfvNV*/
        glGetFinalCombinerInputfvNV = (PFNGLGETFINALCOMBINERINPUTPARAMETERFVNVPROC)
            wglGetProcAddress("glGetFinalCombinerInputfvNV");
         /* FIXME Incorrect name. Should be GetFinalCombinerInputParameterivNV*/
        glGetFinalCombinerInputivNV = (PFNGLGETFINALCOMBINERINPUTPARAMETERIVNVPROC)
            wglGetProcAddress("glGetFinalCombinerInputivNV");
        this->hasNVRegisterCombiners = true;
        mout << "  Found GL_NV_register_combiners\n";
    }
    if (this->HasExtension("GL_SGIS_generate_mipmap"))
    {
        this->hasSGISMipmapping = true;
        mout << "  Found SGIS_generate_mipmap.\n";
    }
    if (this->HasWglExtension("WGL_EXT_swap_control"))
    {
        wglSwapIntervalEXT = (PFNWGLSWAPINTERVALEXTPROC)
            wglGetProcAddress("wglSwapIntervalEXT");
        wglGetSwapIntervalEXT = (PFNWGLGETSWAPINTERVALEXTPROC)
            wglGetProcAddress("wglGetSwapIntervalEXT");
        mout << "  Found WGL_EXT_swap_control.\n";
    }
    mout << "\n";
    return true;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10021A5B
* VC++ mangling:          ?SetMode@B_OpenGLRasterDevice@@UAEXH@Z
*/

void B_OpenGLRasterDevice::SetMode(int mode)
{
    if (this->mode == mode)
        return;
    this->mode = mode;
    if ((mode & RASTER_MODE_DEPTH_MASK) != this->depthMode)
    {
        if (mode & RASTER_MODE_DEPTH_TEST)
        {
            glEnable(GL_DEPTH_TEST);
            glDepthMask(GL_TRUE);
            if (this->unknown07A210)
            {
                glDepthFunc(GL_GREATER);
            }
            else
            {
                glDepthFunc(GL_LEQUAL);
            }
        }
        else if (mode & RASTER_MODE_DEPTH_OVERWRITE)
        {
            glEnable(GL_DEPTH_TEST);
            glDepthMask(GL_TRUE);
            glDepthFunc(GL_ALWAYS);
        }
        else if (mode & RASTER_MODE_DEPTH_READ_ONLY)
        {
            glEnable(GL_DEPTH_TEST);
            glDepthMask(GL_FALSE);
            if (this->unknown07A210)
            {
                glDepthFunc(GL_GREATER);
            }
            else
            {
                glDepthFunc(GL_LEQUAL);
            }
        }
        else
        {
            glDisable(GL_DEPTH_TEST);
            glDepthMask(GL_FALSE);
            glDepthFunc(GL_ALWAYS);
        }
        this->depthMode = mode & RASTER_MODE_DEPTH_MASK;
    }
    if (
        ((mode & RASTER_MODE_TEXTURE) || (mode & RASTER_MODE_TEXT)) &&
        (this->flags & RASTER_FLAGS_TEXTURE))
    {
        if (!this->textureMode)
        {
            glEnable(GL_TEXTURE_2D);
            this->textureMode = true;
        }
    }
    else
    {
        if (this->textureMode)
        {
            glDisable(GL_TEXTURE_2D);
            this->textureMode = false;
        }
    }
    if ((mode & RASTER_MODE_BLEND_MASK) != this->blendMode)
    {
        if (mode & RASTER_MODE_BLEND)
        {
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        }
        else if (mode & RASTER_MODE_ADD_SCR_RGBA)
        {
            glBlendFunc(GL_SRC_ALPHA, GL_ONE);
            glEnable(GL_BLEND);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        }
        else if (mode & RASTER_MODE_GTYPE_ADD)
        {
            glBlendFunc(GL_SRC_ALPHA, GL_ONE);
            glEnable(GL_BLEND);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        }
        else if (mode & RASTER_MODE_ADD_SCR_RGB)
        {
            glBlendFunc(GL_ONE, GL_ONE);
            glEnable(GL_BLEND);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        }
        else if (mode & RASTER_MODE_TEXT)
        {
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        }
        else if (mode & RASTER_MODE_GTYPE_BLEND)
        {
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glEnable(GL_BLEND);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        }
        else if (mode & RASTER_MODE_GTYPE_MUL)
        {
            glBlendFunc(GL_SRC_ALPHA, GL_SRC_COLOR);
            glEnable(GL_BLEND);
            glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        }
        else
        {
            glDisable(GL_BLEND);
        }
        this->blendMode = mode & RASTER_MODE_BLEND_MASK;
    }
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10021DD4
* VC++ mangling:          ?unknown0D4@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown0D4()
{
}
#endif


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10021EB5
* VC++ mangling:          ?unknown240@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown240()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002206C
* VC++ mangling:          ?unknown124@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown124()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x100221EA
* VC++ mangling:          ?RasterParticles@B_OpenGLRasterDevice@@UAEXPAUB_Particle@@IPAVB_ParticleGType@@@Z
*/

void B_OpenGLRasterDevice::RasterParticles(
    B_Particle *particles, unsigned int numParticles,
    B_ParticleGType *particleType)
{
    int multiply = false;
    switch (particleType->operation_type)
    {
    case B_PARTICLE_GTYPE_BLEND:
        this->SetMode(
            RASTER_MODE_GTYPE_BLEND |
            RASTER_MODE_TEXTURE |
            RASTER_MODE_DEPTH_READ_ONLY
        );
        break;
    case B_PARTICLE_GTYPE_ADD:
        this->SetMode(
            RASTER_MODE_GTYPE_ADD |
            RASTER_MODE_TEXTURE |
            RASTER_MODE_DEPTH_READ_ONLY
        );
        break;
    case B_PARTICLE_GTYPE_MUL:
        this->SetMode(
            RASTER_MODE_GTYPE_MUL |
            RASTER_MODE_TEXTURE |
            RASTER_MODE_DEPTH_READ_ONLY
        );
        multiply = true;
        break;
    default:
        this->SetMode(RASTER_MODE_TEXTURE | RASTER_MODE_DEPTH_READ_ONLY);
        break;
    }
    if (multiply && this->BWRender != 0)
    {
        glDisable(GL_REGISTER_COMBINERS_NV);
    }
    this->numParticles += numParticles;
    if (this->isFog)
    {
        this->DisableFog();
    }
    B_Particle *particle = particles;
    B_ParticleElement *element = NULL;
    this->SetActiveTexture(particleType->bmpHandle);
    glBegin(GL_QUADS);
    for (unsigned int i = 0; i < numParticles; i++)
    {
        if (particle->z > 0.5)
        {
            element = &particleType->a00C[particle->time];
            float x = particle->x;
            float y = particle->y;
            float size = element->size;
            if (size < 1.0f)
            {
                size = 1.0f;
            }
            glColor4ubv(&element->r);
            glTexCoord2f(0.0, 0.0);
            float z = particle->z;
            glVertex3f(x - size, y - size, z);
            glTexCoord2f(0.0, 1.0);
            glVertex3f(x - size, y + size, z);
            glTexCoord2f(1.0, 1.0);
            glVertex3f(x + size, y + size, z);
            glTexCoord2f(1.0, 0.0);
            glVertex3f(x + size, y - size, z);
        }
        particle++;
    }
    glEnd();
    if (this->isFog)
    {
        this->EnableFog();
    }
    if (multiply && this->BWRender != 0)
    {
        glEnable(GL_REGISTER_COMBINERS_NV);
    }
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002249D
* VC++ mangling:          ?unknown0FC@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown0FC()
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
* Entry point:            0x100239E7
* VC++ mangling:          ?unknown100@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown100()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10023A08
* VC++ mangling:          ?unknown244@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown244()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10023F15
* VC++ mangling:          ?unknown0D0@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown0D0()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x100241EF
* VC++ mangling:          ?unknown234@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown234()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10024730
* VC++ mangling:          ?unknown23C@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown23C()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10024A68
* VC++ mangling:          ?unknown238@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown238()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10024D13
* VC++ mangling:          ?AddAtmosphere@B_OpenGLRasterDevice@@UAEHABVB_Name@@ABVB_Color@@M@Z
*/

int B_OpenGLRasterDevice::AddAtmosphere(
    const B_Name &name, const B_Color &color, float intensity)
{
    B_Atmosphere *newAtm = new B_Atmosphere(color, intensity, name);
    return this->atmospheres.Append(newAtm);
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10024ECB
* VC++ mangling:          ?GetAtmosphere@B_OpenGLRasterDevice@@UAEHABVB_Name@@@Z
*/

int B_OpenGLRasterDevice::GetAtmosphere(const B_Name &name)
{
    return this->atmospheres.FindItemIndex(name);
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10024F36
* VC++ mangling:          ?GetAtmosphereName@B_OpenGLRasterDevice@@UAE?AVB_Name@@H@Z
*/

B_Name B_OpenGLRasterDevice::GetAtmosphereName(int atmosphereHandle)
{
    if (
        (unsigned int)atmosphereHandle < this->atmospheres.size &&
        atmosphereHandle >= 0
    )
        return this->atmospheres[atmosphereHandle]->Id();
    mout << "B_OpenGLRasterDevice::AtmName() -> Handle no v\xE1lido.\n";
    return "";
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10024FA8
* VC++ mangling:          ?unknown0B0@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown0B0()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10025229
* VC++ mangling:          ?GetAtmosphereColor@B_OpenGLRasterDevice@@UAEXHNAAMAAVB_Color@@@Z
*/

void B_OpenGLRasterDevice::GetAtmosphereColor(
    int atmosphereHandle, double intensityFactor, float &alpha,
    B_Color &color)
{
    if (atmosphereHandle == -1)
        return;
    B_Atmosphere *atm = this->atmospheres[atmosphereHandle];
    alpha = 1.0 - exp(-intensityFactor * atm->intensity * this->fogFactor);
    color = atm->color;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100252A6
* VC++ mangling:          ?unknown108@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown108()
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
* Entry point:            0x1002562B
* VC++ mangling:          ?unknown0F8@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown0F8()
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
* Entry point:            0x10025AAF
* VC++ mangling:          ?unknown118@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown118()
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
* Entry point:            0x10025C79
* VC++ mangling:          ?unknown120@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown120()
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
* Entry point:            0x10025E28
* VC++ mangling:          ?unknown07C@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown07C()
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
* Entry point:            0x10025F18
* VC++ mangling:          ?SetClipActive@B_OpenGLRasterDevice@@UAEXH@Z
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::SetClipActive(int clip_active)
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
* Entry point:            0x10025F82
* VC++ mangling:          ?SetClipWindow@B_OpenGLRasterDevice@@UAEXHHHH@Z
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::SetClipWindow(int x, int y, int w, int h)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10025FEA
* VC++ mangling:          ?SetTransformation@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::SetTransformation()
{
    this->transformations++;
    DisableFog();
    if (this->transformations != 1)
        return;
    glCallList(GL_LIST_START_2D);
    if (this->BWRender != 0 && !this->ModeReflection)
    {
        glDisable(GL_REGISTER_COMBINERS_NV);
    }
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10026067
* VC++ mangling:          ?ResetTransformation@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::ResetTransformation()
{
    this->transformations--;
    if (this->transformations != 0)
        return;
    glCallList(GL_LIST_END_2D);
    if (this->BWRender != 0 && !this->ModeReflection)
    {
        glEnable(GL_REGISTER_COMBINERS_NV);
    }
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100260C0
* VC++ mangling:          ?IncModeReflection@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::IncModeReflection()
{
    this->ModeReflection++;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x100260DA
* VC++ mangling:          ?DecModeReflection@B_OpenGLRasterDevice@@UAEXXZ
*/

void B_OpenGLRasterDevice::DecModeReflection()
{
    this->ModeReflection--;
    assert(ModeReflection >= 0);
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10026115
* VC++ mangling:          ?SetRasterParameter@B_OpenGLRasterDevice@@UAEHPBD0@Z
*/
#ifndef BLD_NATIVE
int B_OpenGLRasterDevice::SetRasterParameter(
    const char *parameter, const char *value)
{
    return 0;
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
* Entry point:            0x10027929
* VC++ mangling:          ?GetRasterParameter@B_OpenGLRasterDevice@@UAEPBDPBD@Z
*/
#ifndef BLD_NATIVE
const char *B_OpenGLRasterDevice::GetRasterParameter(const char *parameter)
{
    return NULL;
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x100286FC
* VC++ mangling:          ?SetDomeColor@B_OpenGLRasterDevice@@UAEXEEE@Z
*/

void B_OpenGLRasterDevice::SetDomeColor(byte r, byte g, byte b)
{
    this->domeColor.r = r;
    this->domeColor.g = g;
    this->domeColor.b = b;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002872D
* VC++ mangling:          ?GetDomeColor@B_OpenGLRasterDevice@@UAEXAAE00@Z
*/

void B_OpenGLRasterDevice::GetDomeColor(byte &r, byte &g, byte &b)
{
    r = this->domeColor.r;
    g = this->domeColor.g;
    b = this->domeColor.b;
}


/*
* Module:                 rOpenGL.dll
* Entry point:            0x10028764
* VC++ mangling:          ?unknown204@B_OpenGLRasterDevice@@UAEXH@Z
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown204(int)
{
}
#endif

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
