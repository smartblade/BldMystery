#ifndef SECTOR_FUNCS_H

#define SECTOR_FUNCS_H

#include <bld_python.h>
#include <export.h>


#define SEC_INT_ACTIVE                    0
#define SEC_INT_N_SURFACES                1
#define SEC_INT_TOO_STEEP                 2
#define SEC_INT_NUM_PIECES                4
#define SEC_INT_ACTION_AREA               5

#define SEC_FLT_TEXTURE_X                 0
#define SEC_FLT_TEXTURE_Y                 1
#define SEC_FLT_TEXTURE_ZOOM_X            2
#define SEC_FLT_TEXTURE_ZOOM_Y            3
#define SEC_FLT_SPECULAR_LIGHT            4
#define SEC_FLT_SPECULAR_SHININESS        5
#define SEC_FLT_SELF_LIGHT                6
#define SEC_FLT_TOO_STEEP_ANGLE           7

#define SEC_STR_TEXTURE                   0
#define SEC_STR_PIECE_NAME                1

#define SEC_VEC_ACTIVE_SURFACE            0
#define SEC_VEC_PIECE                     1

#define SEC_FNC_ON_ENTER                  0
#define SEC_FNC_ON_LEAVE                  1
#define SEC_FNC_ON_HIT                    2
#define SEC_FNC_ON_WALK_ON                3
#define SEC_FNC_ON_WALK_OUT               4


#ifdef __cplusplus
extern "C" {
#endif

LIB_EXP int GetSectorByIndex(int index);
LIB_EXP int GetSectorByPosition(double x, double y, double z);
LIB_EXP int InitBreakSector(
        int sectorID, double x_vec1, double y_vec1, double z_vec1,
        double x_vec2, double y_vec2, double z_vec2, double x_vec3,
        double y_vec3, double z_vec3, const char *s_unknown, double d_unknown,
        int i_unknown
);
LIB_EXP int DoBreakSector(
        int sectorID, double x_impulse, double y_impulse, double z_impulse,
        double x, double y, double z, double x_unknown, double y_unknown,
        double z_unknown
);
LIB_EXP int GetSectorStringProperty(
        int sectorID, int property_kind, int index, const char **value
);
LIB_EXP int SetSectorStringProperty(
        int sectorID, int property_kind, int index, const char *value
);
LIB_EXP int GetSectorFloatProperty(
        int sectorID, int property_kind, int index, double *value
);
LIB_EXP int SetSectorFloatProperty(
        int sectorID, int property_kind, int index, double value
);
LIB_EXP int GetSectorIntProperty(
        int sectorID, int property_kind, int index, int *value
);
LIB_EXP int SetSectorIntProperty(
        int sectorID, int property_kind, int index, int value
);
LIB_EXP int GetSectorVectorProperty(
        int sectorID, int property_kind, int index,
        double *x, double *y, double *z
);
LIB_EXP int SetSectorVectorProperty(
        int sectorID, int property_kind, int index, double x,
        double y, double z
);
LIB_EXP int GetSectorFuncProperty(
        int sectorID, int property_kind, int index, PyObject **value
);
LIB_EXP int SetSectorFuncProperty(
        int sectorID, int property_kind, int index, PyObject *value
);

#ifdef __cplusplus
}
#endif

#endif /* SECTOR_FUNCS_H */