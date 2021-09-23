#pragma once

#include "GLVideoMode.h"
#include "RTrisDeviceDLL.h"
#include <AnalyticGeometry/Matrix.h>
#include <BBLibc.h>
#include <bld_system.h>
#include <GL/gl.h>
#define BUILD_LIB
#include <export.h>

class B_BitMap;
class B_Resource;


struct B_Atmosphere : public B_NamedObj
{
    B_Atmosphere(const B_Color &color, float intensity, const B_Name &name)
        : B_NamedObj(name)
    {
        this->color = color;
        this->intensity = intensity;
    }

    B_Color color;
    float intensity;
};


class B_OpenGLRasterDevice : public B_TrisDevice
{
public:
    B_OpenGLRasterDevice(HWND window, HMODULE rasterModule);
    virtual ~B_OpenGLRasterDevice();
    virtual void SwapBuffers();
    virtual void unknown008(void *);
    virtual void SetGammaCorrection(float gamma);
    virtual float GetGammaCorrection();
    virtual void SetContrast(float contrast);
    virtual float GetContrast();
    virtual void SetBrightness(float brightness);
    virtual float GetBrightness();
    virtual void SetVideoSettings(
        float gamma, float contrast, float brightness
    );
    virtual void SetFlags(long flags);
    virtual void unknown038();
    virtual int AddAtmosphere(
        const B_Name &name, const B_Color &color, float intensity
    );
    virtual long BmpHandle(const char *bmpName);
    virtual int GetAtmosphere(const B_Name &name);
    virtual const char *BmpName(long handle);
    virtual B_Name GetAtmosphereName(int atmosphereHandle);
    virtual void update_dome();
    virtual int GetTextureInfo(
        int index, int &w, int &h, int &depth
    );
    virtual void unknown058();
    virtual void unknown05C();
    virtual void unknown060();
    virtual int nTextures();
    virtual void IncModeReflection();
    virtual void DecModeReflection();
    virtual void unknown07C();
    virtual void unknown080();
    virtual void unknown084();
    virtual void unknown088();
    virtual void unknown08C();
    virtual void unknown090();
    virtual void StartScene(void *);
    virtual void EndScene();
    virtual void ClsRGB(byte r, byte g, byte b);
    virtual void Cls(B_Color color);
    virtual void SetDomeColor(byte r, byte g, byte b);
    virtual void GetDomeColor(byte &r, byte &g, byte &b);
    virtual void unknown0AC();
    virtual void unknown0B0();
    virtual void GetAtmosphereColor(
        int atmosphereHandle, double intensityFactor, float &alpha,
        B_Color &color);
    virtual void unknown0B8();
    virtual void unknown0C0();
    virtual void unknown0C8();
    virtual void unknown0CC();
    virtual void unknown0D0();
    virtual void unknown0D4();
    virtual void unknown0D8();
    virtual void unknown0DC();
    virtual void unknown0E0();
    virtual void unknown0EC();
    virtual void unknown0F8();
    virtual void unknown0FC();
    virtual void unknown100();
    virtual void unknown104();
    virtual void unknown108();
    virtual void SysWrite(
        int x, int y, const char *text, byte r, byte g, byte b
    );
    virtual void unknown110();
    virtual void SetMode(int mode);
    virtual void unknown118();
    virtual void unknown120();
    virtual void unknown124();
    virtual B_BitMap24 *GetBitMap24();
    virtual void set_clip_window(int x, int y, int w, int h);
    virtual void set_clip_active(int clip_active);
    virtual void SetTransformation();
    virtual void ResetTransformation();
    virtual void Line(int x1, int y1, int x2, int y2);
    virtual void Rectangle(int x1, int y1, int x2, int y2);
    virtual void solid_rectangle(int x1, int y1, int x2, int y2);
    virtual void unknown158();
    virtual void SetPosition(float x, float y);
    virtual void set_pen_color(byte r, byte g, byte b);
    virtual void unknown164() ;
    virtual void set_fill_color(byte r, byte g, byte b);
    virtual void unknown16C();
    virtual void set_alpha(float alpha);
    virtual void GetPosition(float &x, float &y);
    virtual void unknown178();
    virtual void unknown17C();
    virtual float get_alpha();
    virtual void set_text_color(byte r, byte g, byte b);
    virtual void unknown1B8();
    virtual void set_text_alpha(float alpha);
    virtual void set_text_blur_color(byte r, byte g, byte b);
    virtual void unknown1C4();
    virtual void set_text_blur_alpha(float alpha);
    virtual void unknown1CC();
    virtual float get_text_alpha();
    virtual void unknown1D4();
    virtual float get_text_blur_alpha();
    virtual void unknown1DC();
    virtual void draw_bitmap(long handle, int w, int h);
    virtual void draw_image(
        int w, int h, const char *color_style, const char *is_normal,
        const void *image_data
    );
    virtual int get_image(
        int x, int y, int w, int h, const char *color_style,
        const char *stretch_or_centered, int image_size, long image_data
    );
    virtual void set_background_image(
        int w, int h, const char *is_rgb, const char *is_normal,
        const char *stretch_or_centered, long image_data
    );
    virtual void remove_background_image();
    virtual int SetRasterParameter(
        const char *parameter, const char *value);
    virtual const char *GetRasterParameter(const char *parameter);
    virtual void GetSize(int &w, int &h);
    virtual void unknown204(int);
    virtual int SetWindowSize(int w, int h);
    virtual int GetWindowSize(int &w, int &h);
    virtual int nVideoModes();
    virtual int GetVideoModeDscr(
        int mode_index, int &depth, int &w, int &h, int &flags,
        int &frequency
    );
    virtual int SetVideoModeParameters(
        int depth, int width, int height, int frequency
    );
    virtual int SetVideoMode(int mode_index);
    virtual int GetCurrentMode(
        int &unknown1, int &w, int &h, int &unknown4,
        int &unknown5
    );
    virtual int FullScreen();
    virtual int ClassId();
    virtual const char *ClassIdName();
    virtual void unknown234();
    virtual void unknown238();
    virtual void unknown23C();
    virtual void unknown240();
    virtual void unknown244();

    void UpdateColorAdjustment();
    void LoadBitmapWinResource(
        int resourceId, GLint textureId);
    void GetVideoModes();
    int CreateContext();
    int LoadExtensions();

private:
    HWND window;
    HDC deviceContext;
    HGLRC glContext;
    int unknown0841A4;
    HMODULE rasterModule;
    WORD gammaRamp[256][3];
    int hasGammaRamp;
    int isGammaRampSet;
    int unknown0847B4;
    GLuint backgroundRegion;
    int useCreditsHack;
    int backgroundImageWidth;
    int backgroundImageHeight;
    int unknown0847C8;
    int unknown0847CC;
    int currentDisplayWidth;
    int currentDisplayHeight;
    int currentDisplayDepth;
    int currentDisplayFrequency;
    float unknown0847E0;
    B_Color domeColor;
    int useMipmaps;
    int unknown0847F0;
    int unknown0847F4;
    int toonRender;
    int toonColor;
    int toonTextures;
    int BWRender;
    float toonLineWidth;
    int showStats;
    int textureMinifyingFunc;
    int textureMagnificationFunc;
    float anisotropicLevel;
    float textureLODBias;
    int hasTextureEnvCombine;
    int hasTextureFilterAnisotropic;
    int hasTextureLodBias;
    int hasFogCoord;
    int hasARBTextureCompression;
    int hasNVRegisterCombiners;
    int hasSGISMipmapping;
    int useTextureFont;
    int tFontOpaque;
    int useCompressedTextures;
    float tFontScale;
    int unknown08484C[4];
    int useOGLLight;
    int notUsePalettes;
    int unknown084864;
    int useOGLFog;
    int cacheStretchImage;
    int unknown084870;
    int unknown084874;
    int unknown084878;
    int unknown08487C;
    int unknown084880;
    int unknown084884[1543];
    bool isFog;
    int unknown0860A4;
    int unknown0860A8;
    int unknown0860AC[3];
    float alpha;
    GLfloat fillColor[4];
    GLubyte textColor[4];
    GLfloat blurRGBA[4];
    B_Matrix pose;
    B_Matrix invPose;
    double modelviewMatrix[16];
    double projectionMatrix[16];
    int viewport[4];
    int unknown0862F0;
    int transformations;
    B_PtrArray<B_VideoMode> videoModes;
    B_VideoMode *fullScreenMode;
    int unknown086314[6];
    double gamma;
    double contrast;
    double brightness;
    byte colorTable[256];
    B_PtrArray<void> textures;
    int nextTextureId;
    B_PtrArray<B_Atmosphere> atmospheres;
    GLfloat fogColor[4];
    float fogDensity;
    float fogFactor;
    int fogEnabled;
    int numTrisMaps;
    int numTrisObjs;
    int numParticles;
    int numTextureSwaps;
    char unknownFields864A4[0x2C000];
};

typedef B_BitMap *(*RM_GetResourceFunc)(const char *name);
typedef void (*RM_FreeResourceFunc)(B_Resource *resource);
typedef void (*UpdateAGTextureFunc)(long bmpHandle);

#ifdef __cplusplus
extern "C" {
#endif

LIB_EXP B_3DRasterDevice *CreateRaster(
    HWND window, HMODULE mainModule, HMODULE rasterModule);
LIB_EXP int DestroyRaster(B_3DRasterDevice *raster);


/*
* Module:                 rOpenGL.dll
* Data address:           0x100517D4
*/
extern RM_GetResourceFunc ERM_GetResource;

/*
* Module:                 rOpenGL.dll
* Data address:           0x100517D8
*/
extern RM_FreeResourceFunc ERM_FreeResource;

/*
* Module:                 rOpenGL.dll
* Data address:           0x100517DC
*/
extern UpdateAGTextureFunc UpdateAGTexture;

#ifdef __cplusplus
}
#endif
