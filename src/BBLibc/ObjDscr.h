
#ifndef B_OBJ_DSCR_H

#define B_OBJ_DSCR_H

#include "array.h"
#include "Resource.h"
#include <Raster/RasterDevice.h>
#include <bld_system.h>

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

class LIB_EXP B_ObjDscr : public B_Resource
{
public:
    unsigned char EdgeFaceGrp(unsigned int);
    int GetVtxNode(unsigned int);
    void SetUpNormals(void);
    void SetUpEdges(void);
    void SetUpBSP(void);
    void SetUpInertialT(void);
    void Draw(
        B_3DRasterDevice* raster, float x1, float y1, float x2, float y2,
        float scale, int i_unknown);
};


#endif /* B_OBJ_DSCR_H */