#ifndef RASTER_DEVICE_H

#define RASTER_DEVICE_H

#include <bld_system.h>
#include <export.h>

class B_BitMap24;
class B_Name;
class B_Color;
class B_Font;

class B_3DRasterDevice {
public:
    virtual ~B_3DRasterDevice()
    {
    }

    virtual void swap_buffers() = 0;
    virtual void unknown008(void *) = 0;
    virtual void set_gamma_correction(float gamma) = 0;
    virtual float get_gamma_correction() = 0;
    virtual void set_contrast(float contrast) = 0;
    virtual float get_contrast() = 0;
    virtual void set_brightness(float brightness) = 0;
    virtual float get_brightness() = 0;

    virtual void SetVideoSettings(
        float gamma, float contrast, float brightness)
    {
    }

    virtual void set_flags(long flags) = 0;

    virtual long GetFlags()
    {
        return flags;
    }

    virtual void unknown030() = 0;
    virtual void unknown034() = 0;
    virtual void unknown038() = 0;
    virtual void add_atmosphere(const B_Name &name, const B_Color &color, float intensity) = 0;
    virtual long bmp_handle(const char *bmp_name) = 0;
    virtual int GetAtmosphere(const B_Name &name) = 0;
    virtual const char *bmp_name(long handle) = 0;
    virtual void unknown04C() = 0;
    virtual void update_dome() = 0;
    virtual int get_texture_info(
        int index, int &w, int &h, int &depth
    ) = 0;
    virtual void unknown058() = 0;
    virtual void unknown05C() = 0;
    virtual void unknown060() = 0;
    virtual int n_textures() = 0;
    virtual void unknown068() = 0;
    virtual void unknown06C() = 0;
    virtual void unknown070() = 0;

    virtual void IncModeReflection()
    {
    }

    virtual void DecModeReflection()
    {
    }

    virtual void unknown07C() = 0;
    virtual void unknown080() = 0;
    virtual void unknown084() = 0;
    virtual void unknown088() = 0;
    virtual void unknown08C() = 0;
    virtual void unknown090() = 0;
    virtual void StartScene(void *) = 0;
    virtual void EndScene() = 0;
    virtual void cls(boolean unknown1, boolean unknown2, boolean unknown3) = 0;
    virtual void Cls(B_Color color) = 0;

    virtual void SetDomeColor(byte r, byte g, byte b)
    {
    }

    virtual void GetDomeColor(byte &r, byte &g, byte &b)
    {
    }

    virtual void unknown0AC() = 0;
    virtual void unknown0B0() = 0;
    virtual void unknown0B4() = 0;
    virtual void unknown0B8() = 0;
    virtual void unknown0BC() = 0;
    virtual void unknown0C0() = 0;
    virtual void unknown0C4() = 0;
    virtual void unknown0C8() = 0;
    virtual void unknown0CC() = 0;
    virtual void unknown0D0() = 0;
    virtual void unknown0D4() = 0;
    virtual void unknown0D8() = 0;
    virtual void unknown0DC() = 0;
    virtual void unknown0E0() = 0;
    virtual void unknown0E4() = 0;
    virtual void unknown0E8() = 0;
    virtual void unknown0EC() = 0;
    virtual void unknown0F0() = 0;
    virtual void unknown0F4() = 0;
    virtual void unknown0F8() = 0;
    virtual void unknown0FC() = 0;
    virtual void unknown100() = 0;
    virtual void unknown104() = 0;
    virtual void unknown108() = 0;

    virtual void SysWrite(
        int x, int y, const char *text, byte r, byte g, byte b)
    {
    }

    virtual void unknown110() = 0;
    virtual void SetMode(int mode) = 0;
    virtual void unknown118() = 0;
    virtual void unknown11C() = 0;
    virtual void unknown120() = 0;
    virtual void unknown124() = 0;
    virtual B_BitMap24 *GetBitMap24() = 0;

    virtual void UnifyRenderBuffers()
    {
    }

    virtual void set_clip_window(int x, int y, int w, int h) = 0;

    virtual void GetClipWindow(int &x, int &y, int &w, int &h)
    {
        x = this->clipX;
        y = this->clipY;
        w = this->clipWidth;
        h = this->clipHeight;
    }

    virtual void set_clip_active(int clip_active) = 0;

    virtual int GetClipActive()
    {
        return clipActive;
    }

    virtual void SetTransformation()
    {
    }

    virtual void ResetTransformation()
    {
    }

    virtual void Line(int x1, int y1, int x2, int y2) = 0;

    virtual void LineTo(int x, int y)
    {
        Line(this->posX, this->posY, x, y);
        SetPosition(x, y);
    }

    virtual void Rectangle(int x1, int y1, int x2, int y2)
    {
        float origX, origY;
        GetPosition(origX, origY);
        SetPosition(x1, y1);
        LineTo(x2, y1);
        LineTo(x2, y2);
        LineTo(x1, y2);
        LineTo(x1, y1);
        SetPosition(origX, origY);
    }

    virtual void solid_rectangle(int x1, int y1, int x2, int y2) = 0;
    virtual void unknown158() = 0;

    virtual void SetPosition(float x, float y)
    {
        this->posX = x;
        this->posY = y;
    }

    virtual void set_pen_color(byte r, byte g, byte b) = 0;
    virtual void unknown164() = 0;
    virtual void set_fill_color(byte r, byte g, byte b) = 0;
    virtual void unknown16C() = 0;
    virtual void set_alpha(float alpha) = 0;

    virtual void GetPosition(float &x, float &y)
    {
        x = this->posX;
        y = this->posY;
    }

    virtual void unknown178() = 0;
    virtual void unknown17C() = 0;
    virtual float get_alpha() = 0;

    virtual void SetFont(B_Font *font)
    {
        this->currentFont = font;
    }

    virtual B_Font *GetFont()
    {
        return currentFont;
    }

    virtual void SetTextMode(int textMode)
    {
        this->textMode = textMode;
    }

    virtual int GetTextMode()
    {
        return textMode;
    }

    virtual void SetTextDirection(int textDirection)
    {
        this->textDirection = textDirection;
    }

    virtual int GetTextDirection()
    {
        return textDirection;
    }

    virtual void SetTextShadow(int textShadowX, int textShadowY)
    {
        this->textShadowX = textShadowX;
        this->textShadowY = textShadowY;
    }

    virtual void GetTextShadow(int &textShadowX, int &textShadowY)
    {
        textShadowX = this->textShadowX;
        textShadowY = this->textShadowY;
    }

    virtual void SetTextScale(float scaleX, float scaleY)
    {
        this->textScaleX = scaleX;
        this->textScaleY = scaleY;
    }

    virtual void GetTextScale(float &scaleX, float &scaleY)
    {
        scaleX = this->textScaleX;
        scaleY = this->textScaleY;
    }

    virtual void SetTextBlur(
        int blurLeft, int blurTop, int blurRight, int blurBottom)
    {
        this->blurLeft = blurLeft;
        this->blurTop = blurTop;
        this->blurRight = blurRight;
        this->blurBottom = blurBottom;
    }

    virtual void GetTextBlur(
        int &blurLeft, int &blurTop, int &blurRight, int &blurBottom)
    {
        blurLeft = this->blurLeft;
        blurTop = this->blurTop;
        blurRight = this->blurRight;
        blurBottom = this->blurBottom;
    }

    virtual void set_text_color(byte r, byte g, byte b) = 0;
    virtual void unknown1B8() = 0;
    virtual void set_text_alpha(float alpha) = 0;
    virtual void set_text_blur_color(byte r, byte g, byte b) = 0;
    virtual void unknown1C4() = 0;
    virtual void set_text_blur_alpha(float alpha) = 0;
    virtual void unknown1CC() = 0;
    virtual float get_text_alpha() = 0;
    virtual void unknown1D4() = 0;
    virtual float get_text_blur_alpha() = 0;
    virtual void unknown1DC() = 0;
    virtual int write_text(const char *text) = 0;
    virtual void draw_bitmap(long handle, int w, int h) = 0;
    virtual void draw_image(
        int w, int h, const char *color_style, const char *is_normal,
        const void *image_data
    ) = 0;
    virtual int get_image(
        int x, int y, int w, int h, const char *color_style,
        const char *stretch_or_centered, int image_size, long image_data
    ) = 0;
    virtual void set_background_image(
        int w, int h, const char *is_rgb, const char *is_normal,
        const char *stretch_or_centered, long image_data
    ) = 0;
    virtual void remove_background_image() = 0;

    virtual int SetRasterParameter(
        const char *parameter, const char *value)
    {
        return 0;
    }

    virtual const char *GetRasterParameter(const char *parameter)
    {
        return NULL;
    }

    virtual void GetSize(int &w, int &h)
    {
        if (FullScreen())
        {
            int dummy1, dummy2, dummy3;
            GetCurrentMode(dummy1, w, h, dummy2, dummy3);
        }
        else
        {
            GetWindowSize(w, h);
        }
    }

    virtual void unknown204(int) = 0;
    virtual int set_window_size(int w, int h) = 0;
    virtual int GetWindowSize(int &w, int &h) = 0;
    virtual int n_video_modes() = 0;
    virtual int get_video_mode_dscr(
        int mode_index, int &depth, int &w, int &h, int &unknown,
        int &frequency
    ) = 0;
    virtual void unknown218() = 0;
    virtual int set_video_mode(int mode_index) = 0;
    virtual int GetCurrentMode(
        int &unknown1, int &w, int &h, int &unknown4,
        int &unknown5
    ) = 0;
    virtual int FullScreen() = 0;
    virtual void unknown228() = 0;
    virtual int unknown22C() = 0;
    virtual const char *class_id_name() = 0;

protected:
    long flags;
    float posX;
    float posY;
    B_Font *currentFont;
    int textMode;
    int textDirection;
    int textShadowX;
    int textShadowY;
    float textScaleX;
    float textScaleY;
    int mode;
    int blurLeft;
    int blurTop;
    int blurRight;
    int blurBottom;
    int clipX;
    int clipY;
    int clipWidth;
    int clipHeight;
    int clipActive;
};

LIB_EXP B_3DRasterDevice *B_3D_raster_device;

#endif /* RASTER_DEVICE_H */
