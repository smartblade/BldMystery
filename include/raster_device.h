#ifndef RASTER_DEVICE_H

#define RASTER_DEVICE_H

#include <bld_system.h>
#include <export.h>

class B_3DRasterDevice {
public:
        virtual void unknown000() = 0;
        virtual void swap_buffers() = 0;
        virtual void unknown008() = 0;
        virtual void set_gamma_correction(float gamma) = 0;
        virtual float get_gamma_correction() = 0;
        virtual void set_contrast(float contrast) = 0;
        virtual float get_contrast() = 0;
        virtual void set_brightness(float brightness) = 0;
        virtual float get_brightness() = 0;
        virtual void set_video_settings(
                float gamma, float contrast, float brightness
        ) = 0;
        virtual void set_flags(long flags) = 0;
        virtual void unknown02C() = 0;
        virtual void unknown030() = 0;
        virtual void unknown034() = 0;
        virtual void unknown038() = 0;
        virtual void unknown03C() = 0;
        virtual long bmp_handle(const char *bmp_name) = 0;
        virtual void unknown044() = 0;
        virtual const char *bmp_name(long handle) = 0;
        virtual void unknown04C() = 0;
        virtual void unknown050() = 0;
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
        virtual void unknown074() = 0;
        virtual void unknown078() = 0;
        virtual void unknown07C() = 0;
        virtual void unknown080() = 0;
        virtual void unknown084() = 0;
        virtual void unknown088() = 0;
        virtual void unknown08C() = 0;
        virtual void unknown090() = 0;
        virtual void unknown094() = 0;
        virtual void unknown098() = 0;
        virtual void cls(boolean unknown1, boolean unknown2, boolean unknown3) = 0;
        virtual void unknown0A0() = 0;
        virtual void set_dome_color(byte r, byte g, byte b) = 0;
        virtual void get_dome_color(byte &r, byte &g, byte &b) = 0;
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
        virtual void sys_write(
                int x, int y, const char *text, byte r, byte g, byte b
        ) = 0;
        virtual void unknown110() = 0;
        virtual void unknown114() = 0;
        virtual void unknown118() = 0;
        virtual void unknown11C() = 0;
        virtual void unknown120() = 0;
        virtual void unknown124() = 0;
        virtual void unknown128() = 0;
        virtual void unify_render_buffers() = 0;
        virtual void set_clip_window(int x, int y, int w, int h) = 0;
        virtual void get_clip_window(int &x, int &y, int &w, int &h) = 0;
        virtual void set_clip_active(int clip_active) = 0;
        virtual int get_clip_active() = 0;
        virtual void unknown140() = 0;
        virtual void unknown144() = 0;
        virtual void line(int x1, int y1, int x2, int y2) = 0;
        virtual void line_to(int x, int y) = 0;
        virtual void rectangle(int x1, int y1, int x2, int y2) = 0;
        virtual void solid_rectangle(int x1, int y1, int x2, int y2) = 0;
        virtual void unknown158() = 0;
        virtual void set_position(float x, float y) = 0;
        virtual void set_pen_color(byte r, byte g, byte b) = 0;
        virtual void unknown164() = 0;
        virtual void set_fill_color(byte r, byte g, byte b) = 0;
        virtual void unknown16C() = 0;
        virtual void set_alpha(float alpha) = 0;
        virtual void get_position(float &x, float &y) = 0;
        virtual void unknown178() = 0;
        virtual void unknown17C() = 0;
        virtual float get_alpha() = 0;
        virtual void set_font(long font_pointer) = 0;
        virtual void unknown188() = 0;
        virtual void set_text_mode(int text_mode) = 0;
        virtual int get_text_mode() = 0;
        virtual void unknown194() = 0;
        virtual void unknown198() = 0;
        virtual void set_text_shadow(int x_shadow, int y_shadow) = 0;
        virtual void get_text_shadow(int &x_shadow, int &y_shadow) = 0;
        virtual void set_text_scale(float scale_x, float scale_y)  = 0;
        virtual void get_text_scale(float &scale_x, float &scale_y) = 0;
        virtual void set_text_blur(
                int unknown1, int unknown2, int unknown3, int unknown4
        ) = 0;
        virtual void get_text_blur(
                int &unknown1, int &unknown2, int &unknown3, int &unknown4
        ) = 0;
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
                long image_data
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
        virtual int set_raster_parameter(
                const char *parameter, const char *value
        ) = 0;
        virtual const char *get_raster_parameter(const char *parameter) = 0;
        virtual void get_size(int &w, int &h) = 0;
        virtual void unknown204() = 0;
        virtual int set_window_size(int w, int h) = 0;
        virtual int get_window_size(int &w, int &h) = 0;
        virtual int n_video_modes() = 0;
        virtual int get_video_mode_dscr(
                int mode_index, int &depth, int &w, int &h, int &unknown,
                int &frequency
        ) = 0;
        virtual void unknown218() = 0;
        virtual int set_video_mode(int mode_index) = 0;
        virtual int get_current_mode(
                int &unknown1, int &unknown2, int &unknown3, int &unknown4,
                int &unknown5
        ) = 0;
        virtual int full_screen() = 0;
        virtual void unknown228() = 0;
        virtual void unknown22C() = 0;
        virtual const char *class_id_name() = 0;
};

LIB_EXP B_3DRasterDevice *B_3D_raster_device;

#endif /* RASTER_DEVICE_H */
