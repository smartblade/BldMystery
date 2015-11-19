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
extern int n_textures(void);
extern void set_text_mode(int text_mode);
extern int get_text_mode(void);
extern void rectangle(int x1, int y1, int x2, int y2);
extern void solid_rectangle(int x1, int y1, int x2, int y2);
extern void set_position(float x, float y);
extern void get_position(float &x, float &y);
extern void set_pen_color(byte r, byte g, byte b);
extern void set_fill_color(byte r, byte g, byte b);
extern void set_alpha(float alpha);
extern float get_alpha(void);
extern void set_text_color(byte r, byte g, byte b);
extern void set_text_alpha(float alpha);
extern int write_text(const char *text);
extern void sys_write(int x, int y, const char *text, byte r, byte g, byte b);
extern float get_text_alpha(void);
extern void draw_image(
        int w, int h, const char *color_style, const char *stretch_or_centered,
        long image_data
);
extern void set_background_image(
        int w, int h, const char *is_rgb, const char *is_normal,
        const char *stretch_or_centered, long image_data
);
extern void remove_background_image(void);
extern void draw_bitmap(long bmp_handle, int w, int h);
extern int set_raster_parameter(const char *scene, const char *parameter);
extern void get_size(int &w, int &h);
extern const char *class_id_name(void);
extern void set_font(long font_pointer);
extern void set_dome_color(byte r, byte g, byte b);


#endif /* RASTER_INT_H */
