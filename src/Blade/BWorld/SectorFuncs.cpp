
#include <bld_system.h>
#define BUILD_LIB
#include <BWorld/SectorFuncs.h>


/*
* Module:                 Blade.exe
* Entry point:            0x0045C040
*/
#ifdef BLD_NATIVE
int GetSectorByPosition(double x, double y, double z)
{
    int (*bld_proc)(double x, double y, double z) = NULL;
    return bld_proc(x, y, z);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045C080
*/
#ifdef BLD_NATIVE
int GetSectorByIndex(int index)
{
    int (*bld_proc)(int index) = NULL;
    return bld_proc(index);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045C0A3
*/
#ifdef BLD_NATIVE
// TODO fix prototype
void GetNumberOfSectors()
{
        assert("GetNumberOfSectors" == NULL);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045C0AD
*/
#ifdef BLD_NATIVE
int InitBreakSector(
        int sectorID, double x_vec1, double y_vec1, double z_vec1,
        double x_vec2, double y_vec2, double z_vec2, double x_vec3,
        double y_vec3, double z_vec3, const char *s_unknown, double d_unknown,
        int i_unknown
)
{
    int (*bld_proc)(
        int sectorID, double x_vec1, double y_vec1, double z_vec1,
        double x_vec2, double y_vec2, double z_vec2, double x_vec3,
        double y_vec3, double z_vec3, const char *s_unknown, double d_unknown,
        int i_unknown
) = NULL;
    return bld_proc(sectorID, x_vec1, y_vec1, z_vec1, x_vec2, y_vec2, z_vec2, x_vec3, y_vec3, z_vec3, s_unknown, d_unknown, i_unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045C159
*/
#ifdef BLD_NATIVE
int DoBreakSector(
        int sectorID, double x_impulse, double y_impulse, double z_impulse,
        double x, double y, double z, double x_unknown, double y_unknown,
        double z_unknown
)
{
    int (*bld_proc)(
        int sectorID, double x_impulse, double y_impulse, double z_impulse,
        double x, double y, double z, double x_unknown, double y_unknown,
        double z_unknown
) = NULL;
    return bld_proc(sectorID, x_impulse, y_impulse, z_impulse, x, y, z, x_unknown, y_unknown, z_unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045C1F5
*/
#ifdef BLD_NATIVE
int GetSectorIntProperty(
        int sectorID, int property_kind, int index, int *value
)
{
    int (*bld_proc)(
        int sectorID, int property_kind, int index, int *value
) = NULL;
    return bld_proc(sectorID, property_kind, index, value);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045C34D
*/
#ifdef BLD_NATIVE
int SetSectorIntProperty(
        int sectorID, int property_kind, int index, int value
)
{
    int (*bld_proc)(
        int sectorID, int property_kind, int index, int value
) = NULL;
    return bld_proc(sectorID, property_kind, index, value);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045C415
*/
#ifdef BLD_NATIVE
int GetSectorFloatProperty(
        int sectorID, int property_kind, int index, double *value
)
{
    int (*bld_proc)(
        int sectorID, int property_kind, int index, double *value
) = NULL;
    return bld_proc(sectorID, property_kind, index, value);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045C5A6
*/
#ifdef BLD_NATIVE
int SetSectorFloatProperty(
        int sectorID, int property_kind, int index, double value
)
{
    int (*bld_proc)(
        int sectorID, int property_kind, int index, double value
) = NULL;
    return bld_proc(sectorID, property_kind, index, value);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045C735
*/
#ifdef BLD_NATIVE
int GetSectorStringProperty(
        int sectorID, int property_kind, int index, const char **value
)
{
    int (*bld_proc)(
        int sectorID, int property_kind, int index, const char **value
) = NULL;
    return bld_proc(sectorID, property_kind, index, value);
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045C8B0
*/
#ifdef BLD_NATIVE
int SetSectorStringProperty(
        int sectorID, int property_kind, int index, const char *value
)
{
    int (*bld_proc)(
        int sectorID, int property_kind, int index, const char *value
) = NULL;
    return bld_proc(sectorID, property_kind, index, value);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045C9A0
*/
#ifdef BLD_NATIVE
int SetSectorVectorProperty(
        int sectorID, int property_kind, int index, double x,
        double y, double z
)
{
    int (*bld_proc)(
        int sectorID, int property_kind, int index, double x,
        double y, double z
) = NULL;
    return bld_proc(sectorID, property_kind, index, x, y, z);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045CA86
*/
#ifdef BLD_NATIVE
int GetSectorVectorProperty(
        int sectorID, int property_kind, int index,
        double *x, double *y, double *z
)
{
    int (*bld_proc)(
        int sectorID, int property_kind, int index,
        double *x, double *y, double *z
) = NULL;
    return bld_proc(sectorID, property_kind, index, x, y, z);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045CB7C
*/
#ifdef BLD_NATIVE
int SetSectorFuncProperty(
        int sectorID, int property_kind, int index, PyObject *value
)
{
    int (*bld_proc)(
        int sectorID, int property_kind, int index, PyObject *value
) = NULL;
    return bld_proc(sectorID, property_kind, index, value);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0045CCD8
*/
#ifdef BLD_NATIVE
int GetSectorFuncProperty(
        int sectorID, int property_kind, int index, PyObject **value
)
{
    int (*bld_proc)(
        int sectorID, int property_kind, int index, PyObject **value
) = NULL;
    return bld_proc(sectorID, property_kind, index, value);
}
#endif
