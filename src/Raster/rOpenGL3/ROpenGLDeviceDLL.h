#pragma once

#include <Raster/RasterDevice.h>
#define BUILD_LIB
#include <export.h>

#ifdef __cplusplus
extern "C" {
#endif

LIB_EXP int DestroyRaster(B_3DRasterDevice* raster);

#ifdef __cplusplus
}
#endif
