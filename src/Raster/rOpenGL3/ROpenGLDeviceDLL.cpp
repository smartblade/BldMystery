#include "ROpenGLDeviceDLL.h"

#include "ConfigSections.h"
#include <math.h>


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
    this->unknown084864 = 0;
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
    this->flags = RASTER_FLAGS_0001 | RASTER_FLAGS_0002 | RASTER_FLAGS_0010;
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
    this->unknown084878 = 0;
    this->unknown084880 = 0;
    this->unknown08487C = 0;
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
    this->unknown0847E0 = -1.0;
    this->unknown0847CC = -1;
    this->unknown0847C8 = -1;
    glNewList(500, GL_COMPILE);
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
    glNewList(501, GL_COMPILE);
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
* VC++ mangling:          ?unknown008@B_OpenGLRasterDevice@@UAEXPAX@Z
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown008(void *)
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
* Entry point:            0x1002022E
* VC++ mangling:          ?Cls@B_OpenGLRasterDevice@@UAEXVB_Color@@@Z
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::Cls(B_Color color)
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
* Entry point:            0x100202D7
* VC++ mangling:          ?ClsRGB@B_OpenGLRasterDevice@@UAEXEEE@Z
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::ClsRGB(byte r, byte g, byte b)
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
* Entry point:            0x10020380
* VC++ mangling:          ?unknown0EC@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown0EC()
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
* Entry point:            0x1002045B
* VC++ mangling:          ?StartScene@B_OpenGLRasterDevice@@UAEXPAX@Z
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::StartScene(void *)
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
* Entry point:            0x10020755
* VC++ mangling:          ?EndScene@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::EndScene()
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
* Entry point:            0x100208FB
* VC++ mangling:          ?unknown080@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown080()
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
* Entry point:            0x10021571
* VC++ mangling:          ?LoadExtensions@B_OpenGLRasterDevice@@QAEHXZ
*/
#ifndef BLD_NATIVE
int B_OpenGLRasterDevice::LoadExtensions()
{
    return true;
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10021A5B
* VC++ mangling:          ?SetMode@B_OpenGLRasterDevice@@UAEXH@Z
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::SetMode(int mode)
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
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 rOpenGL.dll
* Entry point:            0x100221EA
* VC++ mangling:          ?unknown104@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown104()
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
* VC++ mangling:          ?set_clip_active@B_OpenGLRasterDevice@@UAEXH@Z
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::set_clip_active(int clip_active)
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
* VC++ mangling:          ?set_clip_window@B_OpenGLRasterDevice@@UAEXHHHH@Z
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::set_clip_window(int x, int y, int w, int h)
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
* Entry point:            0x10025FEA
* VC++ mangling:          ?SetTransformation@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::SetTransformation()
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
* Entry point:            0x10026067
* VC++ mangling:          ?ResetTransformation@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::ResetTransformation()
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
* Entry point:            0x100260C0
* VC++ mangling:          ?IncModeReflection@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::IncModeReflection()
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
* Entry point:            0x100260DA
* VC++ mangling:          ?DecModeReflection@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::DecModeReflection()
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


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B5B0
* VC++ mangling:          ?unknown068@B_3DRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_3DRasterDevice::unknown068()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B5C0
* VC++ mangling:          ?unknown06C@B_3DRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_3DRasterDevice::unknown06C()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B5D0
* VC++ mangling:          ?unknown070@B_3DRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_3DRasterDevice::unknown070()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B5E0
* VC++ mangling:          ?unknown11C@B_3DRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_3DRasterDevice::unknown11C()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B8F0
* VC++ mangling:          ?WriteText@B_3DRasterDevice@@UAEHPBD@Z
*/
#ifndef BLD_NATIVE
int B_3DRasterDevice::WriteText(const char *text)
{
    return 0;
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002BCD0
* VC++ mangling:          ?unknown228@B_3DRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_3DRasterDevice::unknown228()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002BCF0
* VC++ mangling:          ?unknown084@B_OpenGLRasterDevice@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::unknown084()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002BD00
* VC++ mangling:          ?SetPosition@B_OpenGLRasterDevice@@UAEXMM@Z
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::SetPosition(float x, float y)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002BD30
* VC++ mangling:          ?GetPosition@B_OpenGLRasterDevice@@UAEXAAM0@Z
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::GetPosition(float &x, float &y)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002BD70
* VC++ mangling:          ?GetSize@B_OpenGLRasterDevice@@UAEXAAH0@Z
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::GetSize(int &w, int &h)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002BDB0
* VC++ mangling:          ?nVideoModes@B_OpenGLRasterDevice@@UAEHXZ
*/
#ifndef BLD_NATIVE
int B_OpenGLRasterDevice::nVideoModes()
{
    return 0;
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002BDD0
* VC++ mangling:          ?ClassId@B_OpenGLRasterDevice@@UAEHXZ
*/
#ifndef BLD_NATIVE
int B_OpenGLRasterDevice::ClassId()
{
    return 0;
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002BDF0
* VC++ mangling:          ?ClassIdName@B_OpenGLRasterDevice@@UAEPBDXZ
*/
#ifndef BLD_NATIVE
const char *B_OpenGLRasterDevice::ClassIdName()
{
    return NULL;
}
#endif
