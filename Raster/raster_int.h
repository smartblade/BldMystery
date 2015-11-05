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
extern void set_alpha(float alpha);
extern void set_background_image(
        int w, int h, const char *is_rgb, const char *is_normal,
        const char *stretch_or_centered, long image_data
);
extern void get_size(int &w, int &h);
extern const char *class_id_name(void);


#endif /* RASTER_INT_H */
