
#include <bld_system.h>
#include <bld_python.h>
#define BUILD_LIB
#include <blade_ext.h>

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00491B70
*/
#ifndef BLD_NATIVE
int AddStepSound(const char *name, B_Sound *sound)
{
    int (*bld_proc)(const char *name, B_Sound *sound) = NULL;
    return bld_proc(name, sound);
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
* Entry point:            0x00491E7C
*/
#ifndef BLD_NATIVE
int AddMaterialStepSound(
        const char *table, const char *material, const char *step_sound
)
{
    int (*bld_proc)(
        const char *table, const char *material, const char *step_sound
) = NULL;
    return bld_proc(table, material, step_sound);
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
* Entry point:            0x0049259A
*/
#ifndef BLD_NATIVE
int AddTextureMaterial(const char *texture, const char *material)
{
    int (*bld_proc)(const char *texture, const char *material) = NULL;
    return bld_proc(texture, material);
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
* Entry point:            0x004929C4
*/
#ifndef BLD_NATIVE
int AddActionStepSound(
        const char *table, const char *action, const char *step_sound_table
)
{
    int (*bld_proc)(
        const char *table, const char *action, const char *step_sound_table
) = NULL;
    return bld_proc(table, action, step_sound_table);
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
* Entry point:            0x005856A0
*/
#ifndef BLD_NATIVE
int GetCharByName(const char *name, const char *short_name)
{
    int (*bld_proc)(const char *name, const char *short_name) = NULL;
    return bld_proc(name, short_name);
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
* Entry point:            0x00585715
*/
#ifndef BLD_NATIVE
int LoadAllAnimations(int charID)
{
    int (*bld_proc)(int charID) = NULL;
    return bld_proc(charID);
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
* Entry point:            0x00585758
*/
#ifndef BLD_NATIVE
int ChangeAnimation(
        int charID, const char *old_anm_name, const char *new_anm_name
)
{
    int (*bld_proc)(
        int charID, const char *old_anm_name, const char *new_anm_name
) = NULL;
    return bld_proc(charID, old_anm_name, new_anm_name);
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
* Entry point:            0x00585789
*/
#ifndef BLD_NATIVE
int SetAnmDefaultPrefix(int charID, const char *prefix)
{
    int (*bld_proc)(int charID, const char *prefix) = NULL;
    return bld_proc(charID, prefix);
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
* Entry point:            0x005857C3
*/
#ifndef BLD_NATIVE
int AddAttack(int charID, const char *attack_name, const char *anm_name)
{
    int (*bld_proc)(int charID, const char *attack_name, const char *anm_name) = NULL;
    return bld_proc(charID, attack_name, anm_name);
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
* Entry point:            0x00585807
*/
#ifndef BLD_NATIVE
int AttackWindow(
        int charID, const char *anm_name, float window1, float window2,
        const char *window_name
)
{
    int (*bld_proc)(
        int charID, const char *anm_name, float window1, float window2,
        const char *window_name
) = NULL;
    return bld_proc(charID, anm_name, window1, window2, window_name);
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
* Entry point:            0x00585853
*/
#ifndef BLD_NATIVE
int AttackLevels(
        int charID, const char *anm_name, float level1, float level2
)
{
    int (*bld_proc)(
        int charID, const char *anm_name, float level1, float level2
) = NULL;
    return bld_proc(charID, anm_name, level1, level2);
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
* Entry point:            0x0058589B
*/
#ifndef BLD_NATIVE
int AttackEnergyLevel(
        int charID, const char *anm_name, float  level
)
{
    int (*bld_proc)(
        int charID, const char *anm_name, float  level
) = NULL;
    return bld_proc(charID, anm_name, level);
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
* Entry point:            0x005858DF
*/
#ifndef BLD_NATIVE
// TODO fix prototype
void ForwardsOffset()
{
        assert("ForwardsOffset" == NULL);
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
* Entry point:            0x00585923
*/
#ifndef BLD_NATIVE
int AttackTypeFlag(int charID, const char *attack_name, int flag)
{
    int (*bld_proc)(int charID, const char *attack_name, int flag) = NULL;
    return bld_proc(charID, attack_name, flag);
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
* Entry point:            0x00585967
*/
#ifndef BLD_NATIVE
int AllowAttack(
        int charID, const char *attack_name, const char *keys,
        const char *previous, const char *previous_negative,
        const char *window_name, const char *weapon_kind
)
{
    int (*bld_proc)(
        int charID, const char *attack_name, const char *keys,
        const char *previous, const char *previous_negative,
        const char *window_name, const char *weapon_kind
) = NULL;
    return bld_proc(charID, attack_name, keys, previous, previous_negative, window_name, weapon_kind);
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
* Entry point:            0x005859BB
*/
#ifndef BLD_NATIVE
int MetaAttack(
        int charID, const char *meta_attack_name, const char *attack_name
)
{
    int (*bld_proc)(
        int charID, const char *meta_attack_name, const char *attack_name
) = NULL;
    return bld_proc(charID, meta_attack_name, attack_name);
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
* Entry point:            0x005859FF
*/
#ifndef BLD_NATIVE
int AssignTrail(
        int charID, const char *attack_name, const char *unknown,
        const char *trail_name
)
{
    int (*bld_proc)(
        int charID, const char *attack_name, const char *unknown,
        const char *trail_name
) = NULL;
    return bld_proc(charID, attack_name, unknown, trail_name);
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
* Entry point:            0x00585A47
*/
#ifndef BLD_NATIVE
int SetNCDSpheres(int charID, int NCDSpheres)
{
    int (*bld_proc)(int charID, int NCDSpheres) = NULL;
    return bld_proc(charID, NCDSpheres);
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
* Entry point:            0x00585C53
*/
#ifndef BLD_NATIVE
int SetCDSphere(int charID, int index, double h, double r)
{
    int (*bld_proc)(int charID, int index, double h, double r) = NULL;
    return bld_proc(charID, index, h, r);
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
* Entry point:            0x00585CE3
*/
#ifndef BLD_NATIVE
int GetCharIntProperty(int charID, int property_kind, int index, int *value)
{
    int (*bld_proc)(int charID, int property_kind, int index, int *value) = NULL;
    return bld_proc(charID, property_kind, index, value);
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
* Entry point:            0x00585D4E
*/
#ifndef BLD_NATIVE
int SetCharIntProperty(int charID, int property_kind, int index, int value)
{
    int (*bld_proc)(int charID, int property_kind, int index, int value) = NULL;
    return bld_proc(charID, property_kind, index, value);
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
* Entry point:            0x00585DB4
*/
#ifndef BLD_NATIVE
int GetCharFloatProperty(int charID, int property_kind, int index, double *value)
{
    int (*bld_proc)(int charID, int property_kind, int index, double *value) = NULL;
    return bld_proc(charID, property_kind, index, value);
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
* Entry point:            0x0058616F
*/
#ifndef BLD_NATIVE
int SetCharFloatProperty(int charID, int property_kind, int index, double value)
{
    int (*bld_proc)(int charID, int property_kind, int index, double value) = NULL;
    return bld_proc(charID, property_kind, index, value);
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
* Entry point:            0x00586518
*/
#ifndef BLD_NATIVE
int GetCharStringProperty(int charID, int property_kind, int index, const char **value)
{
    int (*bld_proc)(int charID, int property_kind, int index, const char **value) = NULL;
    return bld_proc(charID, property_kind, index, value);
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
* Entry point:            0x00586614
*/
#ifndef BLD_NATIVE
int SetCharStringProperty(int charID, int property_kind, int index, const char *value)
{
    int (*bld_proc)(int charID, int property_kind, int index, const char *value) = NULL;
    return bld_proc(charID, property_kind, index, value);
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
* Entry point:            0x005867AB
*/
#ifndef BLD_NATIVE
int SetCharFuncProperty(int charID, int property_kind, int index, PyObject *func)
{
    int (*bld_proc)(int charID, int property_kind, int index, PyObject *func) = NULL;
    return bld_proc(charID, property_kind, index, func);
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
* Entry point:            0x00596E90
*/
#ifndef BLD_NATIVE
int GetTrailByName(const char *name)
{
    int (*bld_proc)(const char *name) = NULL;
    return bld_proc(name);
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
* Entry point:            0x00596EFE
*/
#ifndef BLD_NATIVE
// TODO fix prototype
void GetTrailIntProperty()
{
        assert("GetTrailIntProperty" == NULL);
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
* Entry point:            0x00596F08
*/
#ifndef BLD_NATIVE
// TODO fix prototype
void SetTrailIntProperty()
{
        assert("SetTrailIntProperty" == NULL);
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
* Entry point:            0x00596F12
*/
#ifndef BLD_NATIVE
int GetTrailFloatProperty(
        int trailID, int property_kind, int index, double *value
)
{
    int (*bld_proc)(
        int trailID, int property_kind, int index, double *value
) = NULL;
    return bld_proc(trailID, property_kind, index, value);
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
* Entry point:            0x00596F82
*/
#ifndef BLD_NATIVE
int SetTrailFloatProperty(
        int trailID, int property_kind, int index, double value
)
{
    int (*bld_proc)(
        int trailID, int property_kind, int index, double value
) = NULL;
    return bld_proc(trailID, property_kind, index, value);
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
* Entry point:            0x00596FFE
*/
#ifndef BLD_NATIVE
// TODO fix prototype
void GetTrailStringProperty()
{
        assert("GetTrailStringProperty" == NULL);
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
* Entry point:            0x00597024
*/
#ifndef BLD_NATIVE
int GetTrailVectorProperty(
        int trailID, int property_kind, int index,
        double *x, double *y, double *z
)
{
    int (*bld_proc)(
        int trailID, int property_kind, int index,
        double *x, double *y, double *z
) = NULL;
    return bld_proc(trailID, property_kind, index, x, y, z);
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
* Entry point:            0x005970DE
*/
#ifndef BLD_NATIVE
// TODO fix prototype
void SetTrailFuncProperty()
{
        assert("SetTrailFuncProperty" == NULL);
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
* Entry point:            0x005970FC
*/
#ifndef BLD_NATIVE
int SetTrailVectorProperty(
        int trailID, int property_kind, int index, double x, double y, double z
)
{
    int (*bld_proc)(
        int trailID, int property_kind, int index, double x, double y, double z
) = NULL;
    return bld_proc(trailID, property_kind, index, x, y, z);
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
* Entry point:            0x0059D660
*/
#ifndef BLD_NATIVE
// TODO fix prototype
void GetInventory()
{
        assert("GetInventory" == NULL);
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
* Entry point:            0x0059D8A0
*/
#ifndef BLD_NATIVE
// TODO fix prototype
void GetInventoryFloatProperty()
{
        assert("GetInventoryFloatProperty" == NULL);
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
* Entry point:            0x0059D8A8
*/
#ifndef BLD_NATIVE
// TODO fix prototype
void SetInventoryFloatProperty()
{
        assert("SetInventoryFloatProperty" == NULL);
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
* Entry point:            0x0059D8B0
*/
#ifndef BLD_NATIVE
int GetInventoryStringProperty(
    const char *name, int property_kind, const char **value
)
{
    int (*bld_proc)(
    const char *name, int property_kind, const char **value
) = NULL;
    return bld_proc(name, property_kind, value);
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
* Entry point:            0x0059D937
*/
#ifndef BLD_NATIVE
// TODO fix prototype
void SetInventoryStringProperty()
{
        assert("SetInventoryStringProperty" == NULL);
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
* Entry point:            0x0059D93F
*/
#ifndef BLD_NATIVE
int GetInventoryIntProperty(
        const char *name, int property_kind, int *value
)
{
    int (*bld_proc)(
        const char *name, int property_kind, int *value
) = NULL;
    return bld_proc(name, property_kind, value);
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
* Entry point:            0x0059DCFF
*/
#ifndef BLD_NATIVE
int SetInventoryIntProperty(
        const char *name, int property_kind, int value
)
{
    int (*bld_proc)(
        const char *name, int property_kind, int value
) = NULL;
    return bld_proc(name, property_kind, value);
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
* Entry point:            0x0059DDE6
*/
#ifndef BLD_NATIVE
int LinkRightHand(const char *inv_name, const char *obj_name)
{
    int (*bld_proc)(const char *inv_name, const char *obj_name) = NULL;
    return bld_proc(inv_name, obj_name);
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
* Entry point:            0x0059E03F
*/
#ifndef BLD_NATIVE
int LinkLeftHand(const char *inv_name, const char *obj_name)
{
    int (*bld_proc)(const char *inv_name, const char *obj_name) = NULL;
    return bld_proc(inv_name, obj_name);
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
* Entry point:            0x0059E298
*/
#ifndef BLD_NATIVE
int LinkLeftHand2(const char *inv_name, const char *obj_name)
{
    int (*bld_proc)(const char *inv_name, const char *obj_name) = NULL;
    return bld_proc(inv_name, obj_name);
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
* Entry point:            0x0059E4F1
*/
#ifndef BLD_NATIVE
int LinkRightBack(const char *inv_name, const char *obj_name)
{
    int (*bld_proc)(const char *inv_name, const char *obj_name) = NULL;
    return bld_proc(inv_name, obj_name);
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
* Entry point:            0x0059E74A
*/
#ifndef BLD_NATIVE
int LinkLeftBack(const char *inv_name, const char *obj_name)
{
    int (*bld_proc)(const char *inv_name, const char *obj_name) = NULL;
    return bld_proc(inv_name, obj_name);
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
* Entry point:            0x0059E9A3
*/
#ifndef BLD_NATIVE
int LinkBack(const char *inv_name, const char *obj_name)
{
    int (*bld_proc)(const char *inv_name, const char *obj_name) = NULL;
    return bld_proc(inv_name, obj_name);
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
* Entry point:            0x0059EBFC
*/
#ifndef BLD_NATIVE
int SetCurrentQuiver(const char *inv_name, const char *quiver_name)
{
    int (*bld_proc)(const char *inv_name, const char *quiver_name) = NULL;
    return bld_proc(inv_name, quiver_name);
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
* Entry point:            0x0059EE55
*/
#ifndef BLD_NATIVE
int AddWeapon(const char *inv_name, int flag, const char *weapon_name)
{
    int (*bld_proc)(const char *inv_name, int flag, const char *weapon_name) = NULL;
    return bld_proc(inv_name, flag, weapon_name);
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
* Entry point:            0x0059F08C
*/
#ifndef BLD_NATIVE
int AddObject(
        const char *inv_name, int obj_type, int unknown, const char *obj_name
)
{
    int (*bld_proc)(
        const char *inv_name, int obj_type, int unknown, const char *obj_name
) = NULL;
    return bld_proc(inv_name, obj_type, unknown, obj_name);
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
* Entry point:            0x0059F2C7
*/
#ifndef BLD_NATIVE
int RemoveObject(
        const char *inv_name, int obj_type, const char *obj_name
)
{
    int (*bld_proc)(
        const char *inv_name, int obj_type, const char *obj_name
) = NULL;
    return bld_proc(inv_name, obj_type, obj_name);
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
* Entry point:            0x0059F316
*/
#ifndef BLD_NATIVE
const char *GetObject(const char *inv_name, int obj_type, int index)
{
    const char *(*bld_proc)(const char *inv_name, int obj_type, int index) = NULL;
    return bld_proc(inv_name, obj_type, index);
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
* Entry point:            0x0059F362
*/
#ifndef BLD_NATIVE
const char *GetObjectByName(
        const char *inv_name, int obj_type, const char *obj_name
)
{
    const char *(*bld_proc)(
        const char *inv_name, int obj_type, const char *obj_name
) = NULL;
    return bld_proc(inv_name, obj_type, obj_name);
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
* Entry point:            0x0059F3C4
*/
#ifndef BLD_NATIVE
const char *GetRightBack(const char *inv_name)
{
    const char *(*bld_proc)(const char *inv_name) = NULL;
    return bld_proc(inv_name);
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
* Entry point:            0x0059F406
*/
#ifndef BLD_NATIVE
const char *GetLeftBack(const char *inv_name)
{
    const char *(*bld_proc)(const char *inv_name) = NULL;
    return bld_proc(inv_name);
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
* Entry point:            0x0059F448
*/
#ifndef BLD_NATIVE
const char *GetSelectedObject(const char *inv_name, int obj_type)
{
    const char *(*bld_proc)(const char *inv_name, int obj_type) = NULL;
    return bld_proc(inv_name, obj_type);
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
* Entry point:            0x0059F490
*/
#ifndef BLD_NATIVE
const char *GetActiveShield(const char *inv_name)
{
    const char *(*bld_proc)(const char *inv_name) = NULL;
    return bld_proc(inv_name);
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
* Entry point:            0x0059F4D4
*/
#ifndef BLD_NATIVE
const char *GetActiveWeapon(const char *inv_name)
{
    const char *(*bld_proc)(const char *inv_name) = NULL;
    return bld_proc(inv_name);
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
* Entry point:            0x0059F518
*/
#ifndef BLD_NATIVE
// TODO fix prototype
void ActiveWeaponActive()
{
        assert("ActiveWeaponActive" == NULL);
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
* Entry point:            0x0059F541
*/
#ifndef BLD_NATIVE
const char *GetActiveQuiver(const char *inv_name)
{
    const char *(*bld_proc)(const char *inv_name) = NULL;
    return bld_proc(inv_name);
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
* Entry point:            0x0059F585
*/
#ifndef BLD_NATIVE
void Cycle(const char *inv_name, int obj_type)
{
    void (*bld_proc)(const char *inv_name, int obj_type) = NULL;
    bld_proc(inv_name, obj_type);
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
* Entry point:            0x0059F5B0
*/
#ifndef BLD_NATIVE
int GetNumberObjectsAt(const char *inv_name, int obj_type, int index)
{
    int (*bld_proc)(const char *inv_name, int obj_type, int index) = NULL;
    return bld_proc(inv_name, obj_type, index);
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
* Entry point:            0x0059F5E1
*/
#ifndef BLD_NATIVE
int GetMaxNumberObjectsAt(
        const char *inv_name, int obj_type, int index
)
{
    int (*bld_proc)(
        const char *inv_name, int obj_type, int index
) = NULL;
    return bld_proc(inv_name, obj_type, index);
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
* Entry point:            0x0059F612
*/
#ifndef BLD_NATIVE
int IsSelected(const char *inv_name, int obj_type, int obj_index)
{
    int (*bld_proc)(const char *inv_name, int obj_type, int obj_index) = NULL;
    return bld_proc(inv_name, obj_type, obj_index);
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
* Entry point:            0x0059F643
*/
#ifndef BLD_NATIVE
int CarringObject(const char *inv_name, const char *obj_name)
{
    int (*bld_proc)(const char *inv_name, const char *obj_name) = NULL;
    return bld_proc(inv_name, obj_name);
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


