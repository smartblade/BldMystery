
#define BUILD_LIB
#include <raster_device.h>
#undef BUILD_LIB

#include "raster_int.h"


/*
* Module:                 Raster.dll
* Entry point:            0x10003550
*/

void cls(boolean unknown1, boolean unknown2, boolean unknown3) {
        return B_3D_raster_device->cls(unknown1, unknown2, unknown3);
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003574
*/

void swap_buffers() {
        return B_3D_raster_device->swap_buffers();
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003589
*/

long bmp_handle(const char *bmp_name) {
        return B_3D_raster_device->bmp_handle(bmp_name);
}


/*
* Module:                 Raster.dll
* Entry point:            0x100035A3
*/

const char *bmp_name(long handle) {
        return B_3D_raster_device->bmp_name(handle);
}


/*
* Module:                 Raster.dll
* Entry point:            0x100035BD
*/

int n_textures() {
        return B_3D_raster_device->n_textures();
}


/*
* Module:                 Raster.dll
* Entry point:            0x100035D2
*/

int get_texture_info(int index, int &w, int &h, int &depth) {

        return B_3D_raster_device->get_texture_info(
                index, w, h, depth
        );
}


/*
* Module:                 Raster.dll
* Entry point:            0x100035F8
*/

void set_flags(long flags) {
        B_3D_raster_device->set_flags(flags);
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003612
*/

void set_video_settings(float gamma, float contrast, float brightness) {
        B_3D_raster_device->set_video_settings(
                gamma, contrast, brightness
        );
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003633
*/

void set_gamma_correction(float gamma) {
        B_3D_raster_device->set_gamma_correction(gamma);
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000364D
*/

float get_gamma_correction() {
        return B_3D_raster_device->get_gamma_correction();
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003662
*/

void set_contrast(float contrast) {
        return B_3D_raster_device->set_contrast(contrast);
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000367C
*/

float get_contrast() {
        return B_3D_raster_device->get_contrast();
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003691
*/

void set_brightness(float brightness) {
        B_3D_raster_device->set_brightness(brightness);
}


/*
* Module:                 Raster.dll
* Entry point:            0x100036AB
*/

float get_brightness() {
        return B_3D_raster_device->get_brightness();
}


/*
* Module:                 Raster.dll
* Entry point:            0x100036C0
*/

void set_text_mode(int text_mode) {
        B_3D_raster_device->set_text_mode(text_mode);
}


/*
* Module:                 Raster.dll
* Entry point:            0x100036DD
*/

int get_text_mode() {
        return B_3D_raster_device->get_text_mode();
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Raster.dll
* Entry point:            0x10003781
*/

void rectangle(int x1, int y1, int x2, int y2) {
        B_3D_raster_device->rectangle(x1, y1, x2, y2);
}


/*
* Module:                 Raster.dll
* Entry point:            0x100037AA
*/

void solid_rectangle(int x1, int y1, int x2, int y2) {
        B_3D_raster_device->solid_rectangle(x1, y1, x2, y2);
}


/*
* Module:                 Raster.dll
* Entry point:            0x100037D3
*/

void set_position(float x, float y) {
        B_3D_raster_device->set_position(x, y);
}


/*
* Module:                 Raster.dll
* Entry point:            0x100037F4
*/

void get_position(float &x, float &y) {
        B_3D_raster_device->get_position(x, y);
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003815
*/

void set_pen_color(byte r, byte g, byte b) {
        B_3D_raster_device->set_pen_color(r, g, b);
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003839
*/

void set_fill_color(byte r, byte g, byte b) {
        B_3D_raster_device->set_fill_color(r, g, b);
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000385D
*/

void set_alpha(float alpha) {
        B_3D_raster_device->set_alpha(alpha);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Raster.dll
* Entry point:            0x1000389E
*/

void set_text_blur_alpha(float alpha) {
        B_3D_raster_device->set_text_blur_alpha(alpha);
}


/*
* Module:                 Raster.dll
* Entry point:            0x100038BB
*/

float get_text_blur_alpha() {
        return B_3D_raster_device->get_text_blur_alpha();
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Raster.dll
* Entry point:            0x10003967
*/

float get_alpha() {
        return B_3D_raster_device->get_alpha();
}


/*
* Module:                 Raster.dll
* Entry point:            0x1000397F
*/

void set_text_color(byte r, byte g, byte b) {
        B_3D_raster_device->set_text_color(r, g, b);
}


/*
* Module:                 Raster.dll
* Entry point:            0x100039A3
*/
 
void set_text_alpha(float alpha) {
        B_3D_raster_device->set_text_alpha(alpha);
}


/*
* Module:                 Raster.dll
* Entry point:            0x100039C0
*/

float get_text_alpha() {
        return B_3D_raster_device->get_text_alpha();
}


/*
* Module:                 Raster.dll
* Entry point:            0x100039D8
*/
 
int write_text(const char *text) {
        return B_3D_raster_device->write_text(text);
}


/*
* Module:                 Raster.dll
* Entry point:            0x100039F5
*/

void sys_write(int x, int y, const char *text, byte r, byte g, byte b) {
        B_3D_raster_device->sys_write(x, y, text, r, g, b);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Raster.dll
* Entry point:            0x10003A5E
*/

void draw_image(
        int w, int h, const char *color_style, const char *is_normal, long image_data
) {
        B_3D_raster_device->draw_image(w, h, color_style, is_normal, image_data);
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003A8B
*/

void set_background_image(
        int w, int h, const char *is_rgb, const char *is_normal,
        const char *stretch_or_centered, long image_data
) {
        B_3D_raster_device->set_background_image(
                w, h, is_rgb, is_normal, stretch_or_centered, image_data
        );
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003ABB
*/

void remove_background_image() {
        if (B_3D_raster_device != NULL)
                B_3D_raster_device->remove_background_image();
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003ADC
*/

void draw_bitmap(long handle, int w, int h) {
        B_3D_raster_device->draw_bitmap(handle, w, h);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Raster.dll
* Entry point:            0x10003B52
*/

int set_raster_parameter(const char *parameter, const char *value) {
        return B_3D_raster_device->set_raster_parameter(parameter, value);
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003B73
*/

const char *get_raster_parameter(const char *parameter) {
        return B_3D_raster_device->get_raster_parameter(parameter);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Raster.dll
* Entry point:            0x10003BC5
*/

void get_size(int &w, int &h) {
        B_3D_raster_device->get_size(w, h);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Raster.dll
* Entry point:            0x10003CFB
*/

const char *class_id_name() {
        return B_3D_raster_device->class_id_name();
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003D13
*/

void set_font(long font_pointer) {
        B_3D_raster_device->set_font(font_pointer);
}


/*
* Module:                 Raster.dll
* Entry point:            0x10003D30
*/

void set_dome_color(byte r, byte g, byte b) {
        B_3D_raster_device->set_dome_color(r, g, b);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
