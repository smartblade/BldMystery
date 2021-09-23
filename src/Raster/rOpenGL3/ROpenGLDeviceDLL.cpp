#include "ROpenGLDeviceDLL.h"

#include <math.h>


/*
* Module:                 rOpenGL.dll
* Entry point:            0x1001E100
* VC++ mangling:          ??0B_OpenGLRasterDevice@@QAE@PAUHWND__@@PAUHINSTANCE__@@@Z
*/
#ifndef BLD_NATIVE
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
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 rOpenGL.dll
* Entry point:            0x10024D13
* VC++ mangling:          ?add_atmosphere@B_OpenGLRasterDevice@@UAEXABVB_Name@@ABVB_Color@@M@Z
*/
#ifndef BLD_NATIVE
void B_OpenGLRasterDevice::add_atmosphere(const B_Name &name, const B_Color &color, float intensity)
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
* Entry point:            0x10024ECB
* VC++ mangling:          ?GetAtmosphere@B_OpenGLRasterDevice@@UAEHABVB_Name@@@Z
*/
#ifndef BLD_NATIVE
int B_OpenGLRasterDevice::GetAtmosphere(const B_Name &name)
{
    return 0;
}
#endif

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
* Entry point:            0x1002B590
* VC++ mangling:          ?GetFlags@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
long B_3DRasterDevice::GetFlags()
{
}
#endif

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
* Entry point:            0x1002B5F0
* VC++ mangling:          ?UnifyRenderBuffers@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
void B_3DRasterDevice::UnifyRenderBuffers()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B600
* VC++ mangling:          ?GetClipWindow@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
void B_3DRasterDevice::GetClipWindow(int &x, int &y, int &w, int &h)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B650
* VC++ mangling:          ?GetClipActive@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
int B_3DRasterDevice::GetClipActive()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B670
* VC++ mangling:          ?LineTo@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
void B_3DRasterDevice::LineTo(int x, int y)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B6E0
* VC++ mangling:          ?SetFont@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
void B_3DRasterDevice::SetFont(B_Font *font)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B700
* VC++ mangling:          ?GetFont@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
B_Font *B_3DRasterDevice::GetFont()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B720
* VC++ mangling:          ?SetTextMode@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
void B_3DRasterDevice::SetTextMode(int textMode)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B740
* VC++ mangling:          ?GetTextMode@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
int B_3DRasterDevice::GetTextMode()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B760
* VC++ mangling:          ?SetTextDirection@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
void B_3DRasterDevice::SetTextDirection(int textDirection)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B780
* VC++ mangling:          ?GetTextDirection@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
int B_3DRasterDevice::GetTextDirection()
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B7A0
* VC++ mangling:          ?SetTextShadow@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
void B_3DRasterDevice::SetTextShadow(int textShadowX, int textShadowY)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B7D0
* VC++ mangling:          ?GetTextShadow@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
void B_3DRasterDevice::GetTextShadow(int &textShadowX, int &textShadowY)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B800
* VC++ mangling:          ?SetTextScale@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
void B_3DRasterDevice::SetTextScale(float scaleX, float scaleY)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B830
* VC++ mangling:          ?GetTextScale@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
void B_3DRasterDevice::GetTextScale(float &scaleX, float &scaleY)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B860
* VC++ mangling:          ?SetTextBlur@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
void B_3DRasterDevice::SetTextBlur(
    int blurLeft, int blurTop, int blurRight, int blurBottom)
{
}
#endif

/*
* Module:                 rOpenGL.dll
* Entry point:            0x1002B8A0
* VC++ mangling:          ?GetTextBlur@B_3DRasterDevice@@UAEXXZ
*/
#ifdef BLD_NATIVE_HEADER
void B_3DRasterDevice::GetTextBlur(
    int &blurLeft, int &blurTop, int &blurRight, int &blurBottom)
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
