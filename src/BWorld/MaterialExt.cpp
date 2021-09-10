
#include <bld_system.h>
#define BUILD_LIB
#include <blade_ext.h>


/*
* Module:                 Blade.exe
* Entry point:            0x0044E9A0
*/
#ifndef BLD_NATIVE
int nMaterials()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0044E9AA
*/
#ifndef BLD_NATIVE
material_t *CreateMaterial(const char *name)
{
    material_t *(*bld_proc)(const char *name) = NULL;
    return bld_proc(name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0044EB5A
*/
#ifndef BLD_NATIVE
material_t *GetMaterial(const char *name)
{
    material_t *(*bld_proc)(const char *name) = NULL;
    return bld_proc(name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0044EBD3
*/
#ifndef BLD_NATIVE
material_t *GetMaterialI(int index)
{
    material_t *(*bld_proc)(int index) = NULL;
    return bld_proc(index);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0044EC02
*/
#ifndef BLD_NATIVE
int SetMaterialSoundProperty(
    material_t *material, int property_kind, int index, B_Sound *sound
)
{
    int (*bld_proc)(
        material_t *material, int property_kind, int index, B_Sound *sound
) = NULL;
    return bld_proc(material, property_kind, index, sound);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0044EC62
*/
#ifndef BLD_NATIVE
int GetMaterialSoundProperty(
        material_t *material, int property_kind, int index, B_Sound **sound
)
{
    int (*bld_proc)(
        material_t *material, int property_kind, int index, B_Sound **sound
) = NULL;
    return bld_proc(material, property_kind, index, sound);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0044ECC5
*/
#ifndef BLD_NATIVE
int GetMaterialStringProperty(
        material_t *material, int property_kind, int index, const char **value
)
{
    int (*bld_proc)(
        material_t *material, int property_kind, int index, const char **value
) = NULL;
    return bld_proc(material, property_kind, index, value);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0044ECF8
*/
#ifndef BLD_NATIVE
int SetMaterialFloatProperty(
        material_t *material, int property_kind, int index, double value
)
{
    int (*bld_proc)(
        material_t *material, int property_kind, int index, double value
) = NULL;
    return bld_proc(material, property_kind, index, value);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0044ED29
*/
#ifndef BLD_NATIVE
int GetMaterialFloatProperty(
        material_t *material, int property_kind, int index, double *value
)
{
    int (*bld_proc)(
        material_t *material, int property_kind, int index, double *value
) = NULL;
    return bld_proc(material, property_kind, index, value);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0044ED6A
*/
#ifndef BLD_NATIVE
int AddHitSoundComb(
    material_t *material1, material_t *material2, B_Sound *sound
)
{
    int (*bld_proc)(
        material_t *material1, material_t *material2, B_Sound *sound
) = NULL;
    return bld_proc(material1, material2, sound);
}

#endif
