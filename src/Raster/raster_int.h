#ifndef RASTER_INT_H

#define RASTER_INT_H

#include <bld_system.h>
#include <bld_python.h>
#define BUILD_LIB
#include <export.h>


#ifdef __cplusplus
extern "C" {
#endif

LIB_EXP INIT_PY_MODULE_FUNC initRaster(void);

#ifdef __cplusplus
}
#endif


extern void cls(boolean unknown1, boolean unknown2, boolean unknown3);
extern void swap_buffers(void);
extern long bmp_handle(const char *bmp_name);
extern const char *bmp_name(long handle);
extern void set_flags(long flags);
extern int n_textures(void);
extern int get_texture_info(
        int index, int &w, int &h, int &depth
);
extern void SetVideoSettings(float gamma, float contrast, float brightness);
extern void set_gamma_correction(float gamma);
extern float get_gamma_correction(void);
extern void set_contrast(float contrast);
extern float get_contrast(void);
extern void set_brightness(float brightness);
extern float get_brightness(void);
extern void SetTextMode(int text_mode);
extern int GetTextMode(void);
extern void SetTextScale(float scale_x, float scale_y);
extern void GetTextScale(float &scale_x, float &scale_y);
extern void Line(int x1, int y1, int x2, int y2);
extern void LineTo(int x, int y);
extern void Rectangle(int x1, int y1, int x2, int y2);
extern void solid_rectangle(int x1, int y1, int x2, int y2);
extern void SetPosition(float x, float y);
extern void GetPosition(float &x, float &y);
extern void set_pen_color(byte r, byte g, byte b);
extern void set_fill_color(byte r, byte g, byte b);
extern void set_alpha(float alpha);
extern void set_text_blur_color(byte r, byte g, byte b);
extern void set_text_blur_alpha(float alpha);
extern void SetTextBlur(
        int blurLeft, int blurTop, int blurRight, int blurBottom
);
extern void GetTextBlur(
        int &blurLeft, int &blurTop, int &blurRight, int &blurBottom
);
extern float get_text_blur_alpha(void);
extern void SetTextShadow(int x_shadow, int y_shadow);
extern void GetTextShadow(int &x_shadow, int &y_shadow);
extern float get_alpha(void);
extern void set_text_color(byte r, byte g, byte b);
extern void set_text_alpha(float alpha);
extern int write_text(const char *text);
extern void SysWrite(int x, int y, const char *text, byte r, byte g, byte b);
extern float get_text_alpha(void);
extern int get_image(
        int x, int y, int w, int h, const char *color_style,
        const char *stretch_or_centered, int image_size, long image_data
);
extern void draw_image(
        int w, int h, const char *color_style, const char *stretch_or_centered,
        const void *image_data
);
extern void set_background_image(
        int w, int h, const char *is_rgb, const char *is_normal,
        const char *stretch_or_centered, long image_data
);
extern void remove_background_image(void);
extern void draw_bitmap(long bmp_handle, int w, int h);
extern void set_clip_window(int x, int y, int w, int h);
extern void GetClipWindow(int &x, int &y, int &w, int &h);
extern int SetRasterParameter(const char *parameter, const char *value);
extern const char *GetRasterParameter(const char * parameter);
extern void set_clip_active(int clip_active);
extern int GetClipActive(void);
extern void GetSize(int &w, int &h);
extern int set_window_size(int w, int h);
extern int GetWindowSize(int &w, int &h);
extern int FullScreen(void);
extern int n_video_modes(void);
extern int get_video_mode_dscr(
        int mode_index, int &depth, int &w, int &h, int &unknown, int &frequency
);
extern int set_video_mode(int mode_index);
extern int GetCurrentMode(
        int &unknown1, int &w, int &h, int &unknown4, int &unknown5
);
extern const char *class_id_name(void);
extern void SetFont(long font_pointer);
extern void GetDomeColor(byte &r, byte &g, byte &b);
extern void UnifyRenderBuffers(void);
extern void SetDomeColor(byte r, byte g, byte b);


#endif /* RASTER_INT_H */
