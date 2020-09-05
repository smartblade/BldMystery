
#include <bld_system.h>
#include "Events.h"
#include "CameraEntity.h"
#include "BipedEntity.h"
#include <Math/BSpline.h>
#include "bld_misc_funcs.h"
#define BUILD_LIB
#include <EntityFuncs.h>


/*
* Module:                 Blade.exe
* Entry point:            0x004FFEA0
*/

int GetSplinePos(B_Spline *spline, float time, B_Vector *position)
{
    return spline->GetPosition(time, position);
}


/*
* Module:                 Blade.exe
* Entry point:            0x004FFEBA
*/

void AddNodeSpline(
    B_Spline *spline, int nodeIndex, double time, B_Vector position,
    B_Vector startTangent, B_Vector endTangent)
{
    spline->AddNode(time, position);
    spline->SetStartTangent(nodeIndex, startTangent);
    spline->SetEndTangent(nodeIndex, endTangent);
}


/*
* Module:                 Blade.exe
* Entry point:            0x004FFEF3
*/

int CloseSpline(B_Spline *spline)
{
    return spline->Close();
}


/*
* Module:                 Blade.exe
* Entry point:            0x004FFF00
*/

int ClearSpline(B_Spline *spline)
{
    return spline->Clear();
}


/*
* Module:                 Blade.exe
* Entry point:            0x004FFF0D
*/
#ifdef BLD_NATIVE
B_Entity *CreateSpark(
        const char *name, point_3d_t *spark_point, point_3d_t *spark_dir,
        double d_unknown1, double d_unknown2, double d_unknown3,
        double d_unknown4, double d_unknown5, int i_unknown6, int i_unknown7,
        int i_unknown8, int i_unknown9, int i_unknown10, int i_unknown11,
        float d_unknown12, float d_unknown13, float d_unknown14, int i_unknown15
)
{
    B_Entity *(*bld_proc)(
        const char *name, point_3d_t *spark_point, point_3d_t *spark_dir,
        double d_unknown1, double d_unknown2, double d_unknown3,
        double d_unknown4, double d_unknown5, int i_unknown6, int i_unknown7,
        int i_unknown8, int i_unknown9, int i_unknown10, int i_unknown11,
        float d_unknown12, float d_unknown13, float d_unknown14, int i_unknown15
) = NULL;
    return bld_proc(name, spark_point, spark_dir, d_unknown1, d_unknown2, d_unknown3, d_unknown4, d_unknown5, i_unknown6, i_unknown7, i_unknown8, i_unknown9, i_unknown10, i_unknown11, d_unknown12, d_unknown13, d_unknown14, i_unknown15);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00500036
*/
#ifdef BLD_NATIVE
B_Entity *CreateEntity(
        const char *name, const char *kind, double x, double y, double z,
        const char *parent_class, const char *unknown
)
{
    B_Entity *(*bld_proc)(
        const char *name, const char *kind, double x, double y, double z,
        const char *parent_class, const char *unknown
) = NULL;
    return bld_proc(name, kind, x, y, z, parent_class, unknown);
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x00501FE9
*/
#ifdef BLD_NATIVE
int DeleteEntity(const char *name)
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
* Entry point:            0x00503351
*/
#ifdef BLD_NATIVE
B_Entity *CreateEntityDecal(
        const char *name, double x, double y, double z, int i_unknown,
        double d_unknown1, double d_unknown2
)
{
    B_Entity *(*bld_proc)(
        const char *name, double x, double y, double z, int i_unknown,
        double d_unknown1, double d_unknown2
) = NULL;
    return bld_proc(name, x, y, z, i_unknown, d_unknown1, d_unknown2);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0050340C
*/
#ifdef BLD_NATIVE
B_Entity *GetEntity(const char *name)
{
    B_Entity *(*bld_proc)(const char *name) = NULL;
    return bld_proc(name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0050360D
*/
#ifdef BLD_NATIVE
B_Entity *GetEntityI(int index)
{
    B_Entity *(*bld_proc)(int index) = NULL;
    return bld_proc(index);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005036B2
*/

const char *GetEntityName(B_Entity *entity)
{
    assert(entity);
    return entity->name.String();
}


/*
* Module:                 Blade.exe
* Entry point:            0x005036E1
*/
#ifdef BLD_NATIVE
int GetEntitiesAt(
        double x, double y, double z, double radius, char ***entity_names
)
{
    int (*bld_proc)(
        double x, double y, double z, double radius, char ***entity_names
) = NULL;
    return bld_proc(x, y, z, radius, entity_names);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005039F3
*/
#ifdef BLD_NATIVE
int GetEntitiesVisibleFrom(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***entity_names
)
{
    int (*bld_proc)(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***entity_names
) = NULL;
    return bld_proc(xc, yc, zc, radius, xdir, ydir, zdir, angle, entity_names);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00503D6F
*/
#ifdef BLD_NATIVE
int GetObjectEntitiesVisibleFrom(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***entity_names
)
{
    int (*bld_proc)(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***entity_names
) = NULL;
    return bld_proc(xc, yc, zc, radius, xdir, ydir, zdir, angle, entity_names);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005040EB
*/
#ifdef BLD_NATIVE
int GetEnemiesVisibleFrom(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***enemy_names
)
{
    int (*bld_proc)(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***enemy_names
) = NULL;
    return bld_proc(xc, yc, zc, radius, xdir, ydir, zdir, angle, enemy_names);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00504467
*/
#ifdef BLD_NATIVE
int SetCombos(
        const char *person_name, int num_combos, char **combos_names,
        int *combos_executed
)
{
    int (*bld_proc)(
        const char *person_name, int num_combos, char **combos_names,
        int *combos_executed
) = NULL;
    return bld_proc(person_name, num_combos, combos_names, combos_executed);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00504527
*/
#ifdef BLD_NATIVE
int GetCombos(const char *person_name, combo_t **combos)
{
    int (*bld_proc)(const char *person_name, combo_t **combos) = NULL;
    return bld_proc(person_name, combos);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005045A6
*/
#ifdef BLD_NATIVE
int GetWeaponCombos(
        const char *person_name, const char *weapon_kind, combo_t **combos
)
{
    int (*bld_proc)(
        const char *person_name, const char *weapon_kind, combo_t **combos
) = NULL;
    return bld_proc(person_name, weapon_kind, combos);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00504629
*/
#ifdef BLD_NATIVE
int nEntities()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0050463C
*/
#ifdef BLD_NATIVE
int GetNewExclusionGroupId()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00504646
*/

int AddCameraEvent(const char *entity_name, int frame, PyObject *func)
{
    B_Entity *entity = GetEntity(entity_name);
    if (entity->IsClassOf(B_ENTITY_CID_CAMERA))
    {
        B_CameraEntity *cameraEntity = static_cast<B_CameraEntity *>(entity);
        cameraEntity->cam.AddEvent(frame, func);
        return true;
    }
    return false;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504695
*/

int DeleteCameraEvent(const char *entity_name, int frame)
{
    B_Entity *entity = GetEntity(entity_name);
    if (entity->IsClassOf(B_ENTITY_CID_CAMERA))
    {
        B_CameraEntity *cameraEntity = static_cast<B_CameraEntity *>(entity);
        return cameraEntity->cam.DeleteEvent(frame);
    }
    return false;
}


/*
* Module:                 Blade.exe
* Entry point:            0x005046DB
*/

int CameraAddSourceNode(
    const char *entity_name, float time, B_Vector position
)
{
    B_Entity *entity = GetEntity(entity_name);
    if (entity->IsClassOf(B_ENTITY_CID_CAMERA))
    {
        B_CameraEntity *cameraEntity = static_cast<B_CameraEntity *>(entity);
        cameraEntity->cam.AddSourceNode(time, position);
        return true;
    }
    return false;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0050472F
*/

int CameraAddTargetNode(
    const char *entity_name, float time, B_Vector position
)
{
    B_Entity *entity = GetEntity(entity_name);
    if (entity->IsClassOf(B_ENTITY_CID_CAMERA))
    {
        B_CameraEntity *cameraEntity = static_cast<B_CameraEntity *>(entity);
        cameraEntity->cam.AddTargetNode(time, position);
        return true;
    }
    return false;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504783
*/

int CameraSetStartTangentSourceNode(
    const char *entity_name, int nodeIndex, B_Vector startTangent
)
{
    B_Entity *entity = GetEntity(entity_name);
    if (entity->IsClassOf(B_ENTITY_CID_CAMERA))
    {
        B_CameraEntity *cameraEntity = static_cast<B_CameraEntity *>(entity);
        cameraEntity->cam.SetStartTangentSourceNode(nodeIndex, startTangent);
        return true;
    }
    return false;
}


/*
* Module:                 Blade.exe
* Entry point:            0x005047D2
*/

int CameraSetEndTangentSourceNode(
    const char *entity_name, int nodeIndex, B_Vector endTangent
)
{
    B_Entity *entity = GetEntity(entity_name);
    if (entity->IsClassOf(B_ENTITY_CID_CAMERA))
    {
        B_CameraEntity *cameraEntity = static_cast<B_CameraEntity *>(entity);
        cameraEntity->cam.SetEndTangentSourceNode(nodeIndex, endTangent);
        return true;
    }
    return false;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00504821
*/
#ifdef BLD_NATIVE
int CameraSetStartTangentTargetNode(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
)
{
    int (*bld_proc)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
) = NULL;
    return bld_proc(entity_name, unknown1, unknown2, unknown3, unknown4);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00504870
*/
#ifdef BLD_NATIVE
int CameraSetEndTangentTargetNode(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
)
{
    int (*bld_proc)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
) = NULL;
    return bld_proc(entity_name, unknown1, unknown2, unknown3, unknown4);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005048BF
*/
#ifdef BLD_NATIVE
int CameraSetPersonView(
        const char *entity_name, const char *person_name
)
{
    int (*bld_proc)(
        const char *entity_name, const char *person_name
) = NULL;
    return bld_proc(entity_name, person_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00504905
*/
#ifdef BLD_NATIVE
int CameraSetMaxCamera(
        const char *entity_name, const char *cam_file_name, int i_unknown,
        int num_frames
)
{
    int (*bld_proc)(
        const char *entity_name, const char *cam_file_name, int i_unknown,
        int num_frames
) = NULL;
    return bld_proc(entity_name, cam_file_name, i_unknown, num_frames);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00504953
*/
#ifdef BLD_NATIVE
int CameraCut(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005049E2
*/
#ifdef BLD_NATIVE
int CameraSetTravelingView(
        const char *entity_name, int unknown1, int unknown2
)
{
    int (*bld_proc)(
        const char *entity_name, int unknown1, int unknown2
) = NULL;
    return bld_proc(entity_name, unknown1, unknown2);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00504A2C
*/
#ifdef BLD_NATIVE
int CameraClearPath(const char *entity_name, int node)
{
    int (*bld_proc)(const char *entity_name, int node) = NULL;
    return bld_proc(entity_name, node);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00504ABA
*/
#ifdef BLD_NATIVE
int CameraStartPath(const char *entity_name, int node)
{
    int (*bld_proc)(const char *entity_name, int node) = NULL;
    return bld_proc(entity_name, node);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00504B29
*/
#ifdef BLD_NATIVE
int UseEntity(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00504B5F
*/
#ifdef BLD_NATIVE
int ChangeEntityStatic(const char *entity_name, int is_static)
{
    int (*bld_proc)(const char *entity_name, int is_static) = NULL;
    return bld_proc(entity_name, is_static);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005050DD
*/
#ifdef BLD_NATIVE
int ChangeEntityActor(const char *entity_name, int is_actor)
{
    int (*bld_proc)(const char *entity_name, int is_actor) = NULL;
    return bld_proc(entity_name, is_actor);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00505F63
*/
#ifdef BLD_NATIVE
int ChangeEntityPerson(const char *entity_name, int is_person)
{
    int (*bld_proc)(const char *entity_name, int is_person) = NULL;
    return bld_proc(entity_name, is_person);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00506E31
*/
#ifdef BLD_NATIVE
int ChangeEntityWeapon(const char *entity_name, int is_weapon)
{
    int (*bld_proc)(const char *entity_name, int is_weapon) = NULL;
    return bld_proc(entity_name, is_weapon);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00507A06
*/
#ifdef BLD_NATIVE
int ChangeEntityArrow(const char *entity_name, int is_arrow)
{
    int (*bld_proc)(const char *entity_name, int is_arrow) = NULL;
    return bld_proc(entity_name, is_arrow);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0050888E
*/
#ifdef BLD_NATIVE
int SetNextAttack(
        const char *entity_name, const char *attack, int *res
)
{
    int (*bld_proc)(
        const char *entity_name, const char *attack, int *res
) = NULL;
    return bld_proc(entity_name, attack, res);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005088E8
*/
#ifdef BLD_NATIVE
B_Entity *SeverLimb(const char *entity_name, int limb)
{
    B_Entity *(*bld_proc)(const char *entity_name, int limb) = NULL;
    return bld_proc(entity_name, limb);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00508935
*/
#ifdef BLD_NATIVE
// TODO fix prototype
void SetCombatGroup()
{
        assert("SetCombatGroup" == NULL);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00508B11
*/
#ifdef BLD_NATIVE
int SubscribeEntityToList(
        const char *entity_name, const char *timer_name
)
{
    int (*bld_proc)(
        const char *entity_name, const char *timer_name
) = NULL;
    return bld_proc(entity_name, timer_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00508B80
*/
#ifdef BLD_NATIVE
int MessageEvent(
        const char *entity_name, int message_type, int unknown1, int unknown2
)
{
    int (*bld_proc)(
        const char *entity_name, int message_type, int unknown1, int unknown2
) = NULL;
    return bld_proc(entity_name, message_type, unknown1, unknown2);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00508BBB
*/
#ifdef BLD_NATIVE
int InterruptCombat(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00508CD9
*/
#ifdef BLD_NATIVE
const char *GetParticleEntity(const char *entity_name)
{
    const char *(*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00508D4D
*/
#ifdef BLD_NATIVE
int Rel2AbsVector(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
)
{
    int (*bld_proc)(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
) = NULL;
    return bld_proc(entity_name, x_rel, y_rel, z_rel, x_abs, y_abs, z_abs);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00508E06
*/
#ifdef BLD_NATIVE
int Rel2AbsPoint(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
)
{
    int (*bld_proc)(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
) = NULL;
    return bld_proc(entity_name, x_rel, y_rel, z_rel, x_abs, y_abs, z_abs);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00508EBF
*/
#ifdef BLD_NATIVE
int Rel2AbsVectorN(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
)
{
    int (*bld_proc)(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
) = NULL;
    return bld_proc(entity_name, x_rel, y_rel, z_rel, anchor_name, x_abs, y_abs, z_abs);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0050901D
*/
#ifdef BLD_NATIVE
int Rel2AbsPointN(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
)
{
    int (*bld_proc)(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
) = NULL;
    return bld_proc(entity_name, x_rel, y_rel, z_rel, anchor_name, x_abs, y_abs, z_abs);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0050917B
*/
#ifdef BLD_NATIVE
int Abs2RelVector(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
)
{
    int (*bld_proc)(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
) = NULL;
    return bld_proc(entity_name, x_abs, y_abs, z_abs, x_rel, y_rel, z_rel);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00509257
*/
#ifdef BLD_NATIVE
int Abs2RelPoint(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
)
{
    int (*bld_proc)(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
) = NULL;
    return bld_proc(entity_name, x_abs, y_abs, z_abs, x_rel, y_rel, z_rel);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00509333
*/
#ifdef BLD_NATIVE
int Abs2RelVectorN(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
)
{
    int (*bld_proc)(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
) = NULL;
    return bld_proc(entity_name, x_abs, y_abs, z_abs, anchor_name, x_rel, y_rel, z_rel);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005094D1
*/
#ifdef BLD_NATIVE
int Abs2RelPointN(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
)
{
    int (*bld_proc)(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
) = NULL;
    return bld_proc(entity_name, x_abs, y_abs, z_abs, anchor_name, x_rel, y_rel, z_rel);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0050966F
*/
#ifdef BLD_NATIVE
double SQDistance2(const char *entity_name1, const char *entity_name2)
{
    double (*bld_proc)(const char *entity_name1, const char *entity_name2) = NULL;
    return bld_proc(entity_name1, entity_name2);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0050973E
*/
#ifdef BLD_NATIVE
int RemoveEntityFromList(
        const char *entity_name, const char *timer_name
)
{
    int (*bld_proc)(
        const char *entity_name, const char *timer_name
) = NULL;
    return bld_proc(entity_name, timer_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005097AD
*/
#ifdef BLD_NATIVE
int CreateTimer(const char *timer_name, double period)
{
    int (*bld_proc)(const char *timer_name, double period) = NULL;
    return bld_proc(timer_name, period);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005097EB
*/
#ifdef BLD_NATIVE
int GetnTimers()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005097FA
*/
#ifdef BLD_NATIVE
int GetTimerInfo(
        int timer_index, const char **timer_name, double *period
)
{
    int (*bld_proc)(
        int timer_index, const char **timer_name, double *period
) = NULL;
    return bld_proc(timer_index, timer_name, period);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0050981F
*/
#ifdef BLD_NATIVE
int GetEntityIntProperty(
        const char *entity_name, int property_kind, int index, int *value
)
{
    int (*bld_proc)(
        const char *entity_name, int property_kind, int index, int *value
) = NULL;
    return bld_proc(entity_name, property_kind, index, value);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0050B513
*/
#ifdef BLD_NATIVE
int GetEntityFloatProperty(
        const char *entity_name, int property_kind, int index, double *value
)
{
    int (*bld_proc)(
        const char *entity_name, int property_kind, int index, double *value
) = NULL;
    return bld_proc(entity_name, property_kind, index, value);
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
* Entry point:            0x0050D31F
*/
#ifdef BLD_NATIVE
int GetEntityStringProperty(
        const char *entity_name, int property_kind, int index,
        const char **value
)
{
    int (*bld_proc)(
        const char *entity_name, int property_kind, int index,
        const char **value
) = NULL;
    return bld_proc(entity_name, property_kind, index, value);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0050E086
*/
#ifdef BLD_NATIVE
int GetEntityVectorProperty(
        const char *entity_name, int property_kind, int index,
        double *x, double *y, double *z
)
{
    int (*bld_proc)(
        const char *entity_name, int property_kind, int index,
        double *x, double *y, double *z
) = NULL;
    return bld_proc(entity_name, property_kind, index, x, y, z);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0050F6E7
*/
#ifdef BLD_NATIVE
int GetEntityQuatProperty(
        const char *entity_name, int property_kind, int index, double *quat1,
        double *quat2, double *quat3, double *quat4
)
{
    int (*bld_proc)(
        const char *entity_name, int property_kind, int index, double *quat1,
        double *quat2, double *quat3, double *quat4
) = NULL;
    return bld_proc(entity_name, property_kind, index, quat1, quat2, quat3, quat4);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0050F8B9
*/
#ifdef BLD_NATIVE
int GetEntityFuncProperty(
        const char *entity_name, int property_kind, int index, PyObject **func
)
{
    int (*bld_proc)(
        const char *entity_name, int property_kind, int index, PyObject **func
) = NULL;
    return bld_proc(entity_name, property_kind, index, func);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00510A2A
*/
#ifdef BLD_NATIVE
int SetEntityIntProperty(
        const char *entity_name, int property_kind, int index, int value
)
{
    int (*bld_proc)(
        const char *entity_name, int property_kind, int index, int value
) = NULL;
    return bld_proc(entity_name, property_kind, index, value);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00511DB7
*/
#ifdef BLD_NATIVE
int SetEntityFloatProperty(
        const char *entity_name, int property_kind, int index, double value
)
{
    int (*bld_proc)(
        const char *entity_name, int property_kind, int index, double value
) = NULL;
    return bld_proc(entity_name, property_kind, index, value);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00513675
*/
#ifdef BLD_NATIVE
int SetEntityStringProperty(
        const char *entity_name, int property_kind, int index,
        const char *value
)
{
    int (*bld_proc)(
        const char *entity_name, int property_kind, int index,
        const char *value
) = NULL;
    return bld_proc(entity_name, property_kind, index, value);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00514C9B
*/
#ifdef BLD_NATIVE
int SetEntityVectorProperty(
        const char *entity_name, int property_kind, int index,
        double x, double y, double z
)
{
    int (*bld_proc)(
        const char *entity_name, int property_kind, int index,
        double x, double y, double z
) = NULL;
    return bld_proc(entity_name, property_kind, index, x, y, z);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051603F
*/
#ifdef BLD_NATIVE
int SetEntityQuatProperty(
        const char *entity_name, int property_kind, int index, double quat1,
        double quat2, double quat3, double quat4
)
{
    int (*bld_proc)(
        const char *entity_name, int property_kind, int index, double quat1,
        double quat2, double quat3, double quat4
) = NULL;
    return bld_proc(entity_name, property_kind, index, quat1, quat2, quat3, quat4);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005163AA
*/
#ifdef BLD_NATIVE
int SetEntityData(const char *entity_name, PyObject *data)
{
    int (*bld_proc)(const char *entity_name, PyObject *data) = NULL;
    return bld_proc(entity_name, data);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051645D
*/
#ifdef BLD_NATIVE
PyObject *GetEntityData(const char *entity_name)
{
    PyObject *(*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005164FD
*/
#ifdef BLD_NATIVE
int SetEntityFuncProperty(
        const char *entity_name, int property_kind, int index, PyObject *func
)
{
    int (*bld_proc)(
        const char *entity_name, int property_kind, int index, PyObject *func
) = NULL;
    return bld_proc(entity_name, property_kind, index, func);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00517526
*/
#ifdef BLD_NATIVE
int SetEntityInternalState(
        const char *entity_name, PyObject *internal_state
)
{
    int (*bld_proc)(
        const char *entity_name, PyObject *internal_state
) = NULL;
    return bld_proc(entity_name, internal_state);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051758B
*/
#ifdef BLD_NATIVE
int GetEntityInternalState(
        const char *entity_name, PyObject **internal_state
)
{
    int (*bld_proc)(
        const char *entity_name, PyObject **internal_state
) = NULL;
    return bld_proc(entity_name, internal_state);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005175E8
*/
#ifdef BLD_NATIVE
int AddSoundAnim(
    const char *entity_name, const char *anm_event, double time, B_Sound *sound
)
{
    int (*bld_proc)(
        const char *entity_name, const char *anm_event, double time, B_Sound *sound
) = NULL;
    return bld_proc(entity_name, anm_event, time, sound);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00517688
*/
#ifdef BLD_NATIVE
int AddSoundEvent(
        const char *entity_name, const char *event, B_Sound *sound
)
{
    int (*bld_proc)(
        const char *entity_name, const char *event, B_Sound *sound
) = NULL;
    return bld_proc(entity_name, event, sound);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00517718
*/

int AddScheduledFunc(
    double time, PyObject *func, PyObject *args, const char *name
)
{
    B_world.AddScheduledFunc(time, func, args, name);
    return true;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00517740
*/
#ifdef BLD_NATIVE
int RemoveScheduledFunc(const char *name)
{
    int (*bld_proc)(const char *name) = NULL;
    return bld_proc(name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00517758
*/
#ifdef BLD_NATIVE
int GetnScheduledFuncs()
{
    int (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00517767
*/
#ifdef BLD_NATIVE
int GetScheduledFunc(
        int index, PyObject **func, PyObject **args, const char **name,
        double *time
)
{
    int (*bld_proc)(
        int index, PyObject **func, PyObject **args, const char **name,
        double *time
) = NULL;
    return bld_proc(index, func, args, name, time);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051778A
*/
#ifdef BLD_NATIVE
int EntityRotate(
        const char *entity_name, double x_dir, double y_dir, double z_dir,
        double velocity, int unknown
)
{
    int (*bld_proc)(
        const char *entity_name, double x_dir, double y_dir, double z_dir,
        double velocity, int unknown
) = NULL;
    return bld_proc(entity_name, x_dir, y_dir, z_dir, velocity, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00517867
*/
#ifdef BLD_NATIVE
int EntityRotateAbs(
        const char *entity_name, double x, double y, double z, double x_dir,
        double y_dir, double z_dir, double angle, int i_unknown
)
{
    int (*bld_proc)(
        const char *entity_name, double x, double y, double z, double x_dir,
        double y_dir, double z_dir, double angle, int i_unknown
) = NULL;
    return bld_proc(entity_name, x, y, z, x_dir, y_dir, z_dir, angle, i_unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005179E7
*/
#ifdef BLD_NATIVE
int EntityRotateRel(
        const char *entity_name, double x, double y, double z, double x_dir,
        double y_dir, double z_dir, double angle, int i_unknown
)
{
    int (*bld_proc)(
        const char *entity_name, double x, double y, double z, double x_dir,
        double y_dir, double z_dir, double angle, int i_unknown
) = NULL;
    return bld_proc(entity_name, x, y, z, x_dir, y_dir, z_dir, angle, i_unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00517B67
*/
#ifdef BLD_NATIVE
int EntityMove(
        const char *entity_name, double x, double y, double z, int unknown
)
{
    int (*bld_proc)(
        const char *entity_name, double x, double y, double z, int unknown
) = NULL;
    return bld_proc(entity_name, x, y, z, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00517C3C
*/
#ifdef BLD_NATIVE
int EntitySetPosition(
        const char *entity_name, double x, double y, double z, int unknown
)
{
    int (*bld_proc)(
        const char *entity_name, double x, double y, double z, int unknown
) = NULL;
    return bld_proc(entity_name, x, y, z, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00517D17
*/
#ifdef BLD_NATIVE
int EntitySetOrientation(
        const char *entity_name, double quat1, double quat2, double quat3,
        double quat4, int unknown
)
{
    int (*bld_proc)(
        const char *entity_name, double quat1, double quat2, double quat3,
        double quat4, int unknown
) = NULL;
    return bld_proc(entity_name, quat1, quat2, quat3, quat4, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00517E42
*/
#ifdef BLD_NATIVE
int EntityPutToWorld(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00517E97
*/
#ifdef BLD_NATIVE
int EntityAddAnmEventFunc(
        const char *entity_name, const char *anm_event, PyObject *func
)
{
    int (*bld_proc)(
        const char *entity_name, const char *anm_event, PyObject *func
) = NULL;
    return bld_proc(entity_name, anm_event, func);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00517F32
*/
#ifdef BLD_NATIVE
int EntityDelAnmEventFunc(
        const char *entity_name, const char *anm_event
)
{
    int (*bld_proc)(
        const char *entity_name, const char *anm_event
) = NULL;
    return bld_proc(entity_name, anm_event);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00517FB9
*/
#ifdef BLD_NATIVE
int EntityClearAnmEventFuncs(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
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
* Entry point:            0x00518030
*/
#ifdef BLD_NATIVE
int ClearActorPath(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005180A2
*/
#ifdef BLD_NATIVE
int AddActorPathnode(
        const char *entity_name, double time, double x, double y, double z
)
{
    int (*bld_proc)(
        const char *entity_name, double time, double x, double y, double z
) = NULL;
    return bld_proc(entity_name, time, x, y, z);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00518148
*/
#ifdef BLD_NATIVE
int StartActorPath(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005181BA
*/
#ifdef BLD_NATIVE
int GoToActorPath(
        const char *entity_name, int i_unknown, double d_unknown
)
{
    int (*bld_proc)(
        const char *entity_name, int i_unknown, double d_unknown
) = NULL;
    return bld_proc(entity_name, i_unknown, d_unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00518238
*/
#ifdef BLD_NATIVE
int TestPos(
        const char *entity_name, double x, double y, double z, double max_fall,
        int action_area, int *isCorrect
)
{
    int (*bld_proc)(
        const char *entity_name, double x, double y, double z, double max_fall,
        int action_area, int *isCorrect
) = NULL;
    return bld_proc(entity_name, x, y, z, max_fall, action_area, isCorrect);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051831A
*/
#ifdef BLD_NATIVE
int TestPosInOwnBox(
        const char *entity_name, double x, double y, double z, double box_size,
        int *isCorrect
)
{
    int (*bld_proc)(
        const char *entity_name, double x, double y, double z, double box_size,
        int *isCorrect
) = NULL;
    return bld_proc(entity_name, x, y, z, box_size, isCorrect);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005184E8
*/
#ifdef BLD_NATIVE
int TurnOnActor(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051855A
*/
#ifdef BLD_NATIVE
int TurnOffActor(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005185CC
*/
#ifdef BLD_NATIVE
int SetAttackList(const char *entity_name, PyObject *attack_list)
{
    int (*bld_proc)(const char *entity_name, PyObject *attack_list) = NULL;
    return bld_proc(entity_name, attack_list);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005186BA
*/
#ifdef BLD_NATIVE
PyObject *GetAttackList(const char *entity_name)
{
    PyObject *(*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051872A
*/
#ifdef BLD_NATIVE
PyObject *GetGroupMembers(const char *entity_name)
{
    PyObject *(*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00518910
*/
#ifdef BLD_NATIVE
PyObject *GetCombatants(const char *entity_name)
{
    PyObject *(*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051898B
*/
#ifdef BLD_NATIVE
int SetActorNodeStartTangent(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
)
{
    int (*bld_proc)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
) = NULL;
    return bld_proc(entity_name, unknown1, unknown2, unknown3, unknown4);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00518A2D
*/
#ifdef BLD_NATIVE
int SetActorNodeEndTangent(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
)
{
    int (*bld_proc)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
) = NULL;
    return bld_proc(entity_name, unknown1, unknown2, unknown3, unknown4);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00518ACF
*/
#ifdef BLD_NATIVE
int SetSound(const char *entity_name, const char *sound)
{
    int (*bld_proc)(const char *entity_name, const char *sound) = NULL;
    return bld_proc(entity_name, sound);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00518B45
*/
#ifdef BLD_NATIVE
int SetObjectSound(const char *entity_name, const char *sound)
{
    int (*bld_proc)(const char *entity_name, const char *sound) = NULL;
    return bld_proc(entity_name, sound);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00518BBB
*/
#ifdef BLD_NATIVE
int PlayEntitySound(const char *entity_name, int i_unknown)
{
    int (*bld_proc)(const char *entity_name, int i_unknown) = NULL;
    return bld_proc(entity_name, i_unknown);
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
* Entry point:            0x00518CA3
*/
#ifdef BLD_NATIVE
int Stop(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00518D90
*/
#ifdef BLD_NATIVE
int StopAt(const char *entity_name, double x, double y, double z)
{
    int (*bld_proc)(const char *entity_name, double x, double y, double z) = NULL;
    return bld_proc(entity_name, x, y, z);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00518E2E
*/
#ifdef BLD_NATIVE
int CheckAnimCol(
        const char *entity_name, const char *anm_name, const char *obj_name,
        int unknown, int *res
)
{
    int (*bld_proc)(
        const char *entity_name, const char *anm_name, const char *obj_name,
        int unknown, int *res
) = NULL;
    return bld_proc(entity_name, anm_name, obj_name, unknown, res);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00518F1A
*/
#ifdef BLD_NATIVE
int RemoveFromInvent(const char *entity_name, const char *obj_name)
{
    int (*bld_proc)(const char *entity_name, const char *obj_name) = NULL;
    return bld_proc(entity_name, obj_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051919B
*/
#ifdef BLD_NATIVE
int ResetWounds(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051920D
*/
#ifdef BLD_NATIVE
int RemoveFromInventRight(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00519285
*/
#ifdef BLD_NATIVE
int RemoveFromInventLeft(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005192FD
*/
#ifdef BLD_NATIVE
int RemoveFromInventLeft2(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00519375
*/
#ifdef BLD_NATIVE
int CanISee(
        const char *entity_name, const char *seen_entity_name, int *canISee
)
{
    int (*bld_proc)(
        const char *entity_name, const char *seen_entity_name, int *canISee
) = NULL;
    return bld_proc(entity_name, seen_entity_name, canISee);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051942F
*/
#ifdef BLD_NATIVE
int CanISeeFrom(
        const char *entity_name, const char *seen_entity_name,
        double x, double y, double z, int *canISee
)
{
    int (*bld_proc)(
        const char *entity_name, const char *seen_entity_name,
        double x, double y, double z, int *canISee
) = NULL;
    return bld_proc(entity_name, seen_entity_name, x, y, z, canISee);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005194EE
*/
#ifdef BLD_NATIVE
int SetActiveEnemy(
        const char *entity_name, const char *active_enemy_name, int *unknown
)
{
    int (*bld_proc)(
        const char *entity_name, const char *active_enemy_name, int *unknown
) = NULL;
    return bld_proc(entity_name, active_enemy_name, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005195C0
*/
#ifdef BLD_NATIVE
int ExcludeHitFor(
        const char *entity_name, const char *exclude_hit_for_name,
        void *unknown
)
{
    int (*bld_proc)(
        const char *entity_name, const char *exclude_hit_for_name,
        void *unknown
) = NULL;
    return bld_proc(entity_name, exclude_hit_for_name, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00519697
*/
#ifdef BLD_NATIVE
int ExcludeHitInAnimationFor(
        const char *entity_name, const char *exclude_hit_for_name, void *unknown
)
{
    int (*bld_proc)(
        const char *entity_name, const char *exclude_hit_for_name, void *unknown
) = NULL;
    return bld_proc(entity_name, exclude_hit_for_name, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00519792
*/
#ifdef BLD_NATIVE
int Link(
        const char *entity_name, const char *child_entity_name, void *unknown
)
{
    int (*bld_proc)(
        const char *entity_name, const char *child_entity_name, void *unknown
) = NULL;
    return bld_proc(entity_name, child_entity_name, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00519833
*/
#ifdef BLD_NATIVE
int LinkToNode(
        const char *entity_name, const char *child_name, int node_index,
        void *unknown
)
{
    int (*bld_proc)(
        const char *entity_name, const char *child_name, int node_index,
        void *unknown
) = NULL;
    return bld_proc(entity_name, child_name, node_index, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051996F
*/
#ifdef BLD_NATIVE
int LinkAnchors(
        const char *entity_name, const char *entity_anchor_name,
        const char *child_name, const char *child_anchor_name, void *unknown
)
{
    int (*bld_proc)(
        const char *entity_name, const char *entity_anchor_name,
        const char *child_name, const char *child_anchor_name, void *unknown
) = NULL;
    return bld_proc(entity_name, entity_anchor_name, child_name, child_anchor_name, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00519A7D
*/
#ifdef BLD_NATIVE
int UnlinkChilds(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00519ACF
*/
#ifdef BLD_NATIVE
int GetNodeIndex(
        const char *entity_name, const char *node_name, int *index
)
{
    int (*bld_proc)(
        const char *entity_name, const char *node_name, int *index
) = NULL;
    return bld_proc(entity_name, node_name, index);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00519B6F
*/
#ifdef BLD_NATIVE
int UnlinkChild(
        const char *entity_name, const char *child_entity_name, void *unknown
)
{
    int (*bld_proc)(
        const char *entity_name, const char *child_entity_name, void *unknown
) = NULL;
    return bld_proc(entity_name, child_entity_name, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00519C0D
*/
#ifdef BLD_NATIVE
int InsideActionArea(
        const char *entity_name, int action_area, int *is_inside
)
{
    int (*bld_proc)(
        const char *entity_name, int action_area, int *is_inside
) = NULL;
    return bld_proc(entity_name, action_area, is_inside);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00519CBF
*/
#ifdef BLD_NATIVE
int SetTmpAnmFlags(
        const char *entity_name, int wuea, int mod_y, int solf, int copy_rot,
        int bng_mov, int headf, int unknown
)
{
    int (*bld_proc)(
        const char *entity_name, int wuea, int mod_y, int solf, int copy_rot,
        int bng_mov, int headf, int unknown
) = NULL;
    return bld_proc(entity_name, wuea, mod_y, solf, copy_rot, bng_mov, headf, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00519D4F
*/
#ifdef BLD_NATIVE
int SetAnmFlags(
        const char *entity_name, const char *anm_name, int wuea, int mod_y,
        int solf, int copy_rot, int bng_mov, int headf
)
{
    int (*bld_proc)(
        const char *entity_name, const char *anm_name, int wuea, int mod_y,
        int solf, int copy_rot, int bng_mov, int headf
) = NULL;
    return bld_proc(entity_name, anm_name, wuea, mod_y, solf, copy_rot, bng_mov, headf);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00519DDF
*/
#ifdef BLD_NATIVE
int LaunchAnimation2(
        const char *entity_name, const char *anm_name1, const char *anm_name2
)
{
    int (*bld_proc)(
        const char *entity_name, const char *anm_name1, const char *anm_name2
) = NULL;
    return bld_proc(entity_name, anm_name1, anm_name2);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00519E5F
*/
#ifdef BLD_NATIVE
int SetEnemy(const char *entity_name, const char *enemy_name)
{
    int (*bld_proc)(const char *entity_name, const char *enemy_name) = NULL;
    return bld_proc(entity_name, enemy_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00519F38
*/
#ifdef BLD_NATIVE
const char *GetEnemy(const char *entity_name)
{
    const char *(*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00519FD6
*/
#ifdef BLD_NATIVE
int Chase(
        const char *entity_name, const char *enemy_name, int action_area
)
{
    int (*bld_proc)(
        const char *entity_name, const char *enemy_name, int action_area
) = NULL;
    return bld_proc(entity_name, enemy_name, action_area);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051A0A5
*/
#ifdef BLD_NATIVE
int ResetChase(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051A14B
*/
#ifdef BLD_NATIVE
int GoTo(const char *entity_name, int x, int y, int z)
{
    int (*bld_proc)(const char *entity_name, int x, int y, int z) = NULL;
    return bld_proc(entity_name, x, y, z);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051A1FC
*/
#ifdef BLD_NATIVE
int CanGoTo(const char *entity_name, int x, int y, int z)
{
    int (*bld_proc)(const char *entity_name, int x, int y, int z) = NULL;
    return bld_proc(entity_name, x, y, z);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051A2A8
*/
#ifdef BLD_NATIVE
int QuickFace(const char *entity_name, double angle)
{
    int (*bld_proc)(const char *entity_name, double angle) = NULL;
    return bld_proc(entity_name, angle);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051A32A
*/
#ifdef BLD_NATIVE
int Face(const char *entity_name, double angle)
{
    int (*bld_proc)(const char *entity_name, double angle) = NULL;
    return bld_proc(entity_name, angle);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051A3E3
*/
#ifdef BLD_NATIVE
int StartLooking(const char *entity_name, int x, int y, int z)
{
    int (*bld_proc)(const char *entity_name, int x, int y, int z) = NULL;
    return bld_proc(entity_name, x, y, z);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051A3ED
*/
#ifdef BLD_NATIVE
int StopLooking(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051A47A
*/
#ifdef BLD_NATIVE
int LookAtEntity(
        const char *entity_name, const char *look_at_entity_name
)
{
    int (*bld_proc)(
        const char *entity_name, const char *look_at_entity_name
) = NULL;
    return bld_proc(entity_name, look_at_entity_name);
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
* Entry point:            0x0051A5D6
*/
#ifdef BLD_NATIVE
int LaunchWatch(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051A68A
*/
#ifdef BLD_NATIVE
int GetActionMode(const char *entity_name, int *action_mode)
{
    int (*bld_proc)(const char *entity_name, int *action_mode) = NULL;
    return bld_proc(entity_name, action_mode);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051A74D
*/
#ifdef BLD_NATIVE
int StartGrabbing(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051A789
*/
#ifdef BLD_NATIVE
int StopGrabbing(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051A7C5
*/
#ifdef BLD_NATIVE
int AddEntWatchAnim(const char *entity_name, const char *anm_name)
{
    int (*bld_proc)(const char *entity_name, const char *anm_name) = NULL;
    return bld_proc(entity_name, anm_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051A841
*/
#ifdef BLD_NATIVE
int Freeze(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051A8D7
*/
#ifdef BLD_NATIVE
int UnFreeze(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051A96A
*/
#ifdef BLD_NATIVE
int SwitchTo1H(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051A9E2
*/
#ifdef BLD_NATIVE
int GetDummyAxis(
        const char *entity_name, const char *anchor_name, double x_dir,
        double y_dir, double z_dir, double *x_dummy_axis, double *y_dummy_axis,
        double *z_dummy_axis, int unknown
)
{
    int (*bld_proc)(
        const char *entity_name, const char *anchor_name, double x_dir,
        double y_dir, double z_dir, double *x_dummy_axis, double *y_dummy_axis,
        double *z_dummy_axis, int unknown
) = NULL;
    return bld_proc(entity_name, anchor_name, x_dir, y_dir, z_dir, x_dummy_axis, y_dummy_axis, z_dummy_axis, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051AD9B
*/
#ifdef BLD_NATIVE
int GraspPos(
        const char *entity_name, const char *grasp, double *x, double *y,
        double *z
)
{
    int (*bld_proc)(
        const char *entity_name, const char *grasp, double *x, double *y,
        double *z
) = NULL;
    return bld_proc(entity_name, grasp, x, y, z);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051AF97
*/
#ifdef BLD_NATIVE
int SwitchToBow(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051B00F
*/
#ifdef BLD_NATIVE
int LaunchBayRoute(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051B09A
*/
#ifdef BLD_NATIVE
int EntityCatchOnFire(
        const char *entity_name, double x, double y, double z
)
{
    int (*bld_proc)(
        const char *entity_name, double x, double y, double z
) = NULL;
    return bld_proc(entity_name, x, y, z);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051B18D
*/
#ifdef BLD_NATIVE
int GetNChildren(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051B1DB
*/
#ifdef BLD_NATIVE
const char *GetChild(const char *entity_name, int index)
{
    const char *(*bld_proc)(const char *entity_name, int index) = NULL;
    return bld_proc(entity_name, index);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051B225
*/
#ifdef BLD_NATIVE
int CreateBipedData(const char *biped_name, const char *kind)
{
    int (*bld_proc)(const char *biped_name, const char *kind) = NULL;
    return bld_proc(biped_name, kind);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051B4D3
*/
#ifdef BLD_NATIVE
int AddBipedAction(
        const char *char_name, const char *action_name,
        const char *animation_name, double d_unknown1, double d_unknown2,
        int i_unknown
)
{
    int (*bld_proc)(
        const char *char_name, const char *action_name,
        const char *animation_name, double d_unknown1, double d_unknown2,
        int i_unknown
) = NULL;
    return bld_proc(char_name, action_name, animation_name, d_unknown1, d_unknown2, i_unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051B971
*/
#ifdef BLD_NATIVE
int RemoveBipedAction(const char *s_unknown1, const char *s_unknown2)
{
    int (*bld_proc)(const char *s_unknown1, const char *s_unknown2) = NULL;
    return bld_proc(s_unknown1, s_unknown2);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051BC8F
*/
#ifdef BLD_NATIVE
int AddBipedActionC(
        const char *char_name, const char *action_name,
        const char *animation_name, const char *s_unknown, double d_unknown1,
        double d_unknown2, int i_unknown
)
{
    int (*bld_proc)(
        const char *char_name, const char *action_name,
        const char *animation_name, const char *s_unknown, double d_unknown1,
        double d_unknown2, int i_unknown
) = NULL;
    return bld_proc(char_name, action_name, animation_name, s_unknown, d_unknown1, d_unknown2, i_unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051BEF4
*/
#ifdef BLD_NATIVE
int SetActionEventTable(
        const char *race_name, const char *action_name, const char *table_name
)
{
    int (*bld_proc)(
        const char *race_name, const char *action_name, const char *table_name
) = NULL;
    return bld_proc(race_name, action_name, table_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051C4A4
*/
#ifdef BLD_NATIVE
int SetEventTableFuncC(
        const char *s_unknown1, const char *s_unknown2, const char *s_unknown3
)
{
    int (*bld_proc)(
        const char *s_unknown1, const char *s_unknown2, const char *s_unknown3
) = NULL;
    return bld_proc(s_unknown1, s_unknown2, s_unknown3);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051CA1C
*/
#ifdef BLD_NATIVE
int SetEventTableFunc(
        const char *event_table_name, const char *event_type, PyObject *func
)
{
    int (*bld_proc)(
        const char *event_table_name, const char *event_type, PyObject *func
) = NULL;
    return bld_proc(event_table_name, event_type, func);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051CE46
*/
#ifdef BLD_NATIVE
int DoAction(const char *entity_name, const char *action_name)
{
    int (*bld_proc)(const char *entity_name, const char *action_name) = NULL;
    return bld_proc(entity_name, action_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051CEBC
*/
#ifdef BLD_NATIVE
int DoActionWI(
        const char *entity_name, const char *action_name,
        int interpolation_type, double time, double unknown1
)
{
    int (*bld_proc)(
        const char *entity_name, const char *action_name,
        int interpolation_type, double time, double unknown1
) = NULL;
    return bld_proc(entity_name, action_name, interpolation_type, time, unknown1);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051CF72
*/
#ifdef BLD_NATIVE
int SetOnFloor(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051CFE4
*/

int RaiseEvent(const char *entity_name, const char *event_name)
{
    B_Entity *entity = GetEntity(entity_name);
    if (entity == NULL)
    {
        mout << vararg(
            "RaiseEvent() -> Error: Trying to access non-existent entity:%s.\n",
            entity_name);
        return -1;
    }
    if (entity->IsClassOf(B_ENTITY_CID_BIPED))
    {
        B_BipedEntity *bipedEntity = static_cast<B_BipedEntity *>(entity);
        bipedEntity->RaiseEvent(gbl_events.GetEventIndex(event_name));
        return 1;
    }
    return -2;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0051D065
*/
#ifdef BLD_NATIVE
int SetSolidMask(const char *kind, int mask)
{
    int (*bld_proc)(const char *kind, int mask) = NULL;
    return bld_proc(kind, mask);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051D25D
*/
#ifdef BLD_NATIVE
int IsValidEntity(const char *entity_name)
{
    int (*bld_proc)(const char *entity_name) = NULL;
    return bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051D283
*/
#ifdef BLD_NATIVE
void EntityRemoveFromWorld(const char *entity_name)
{
    void (*bld_proc)(const char *entity_name) = NULL;
    bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051D2D7
*/
#ifdef BLD_NATIVE
void EntityRemoveFromWorldWithChilds(const char *entity_name)
{
    void (*bld_proc)(const char *entity_name) = NULL;
    bld_proc(entity_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051D32B
*/
#ifdef BLD_NATIVE
int ImpulseC(
        const char *entity_name, double x, double y, double z, double x_vec,
        double y_vec, double z_vec
)
{
    int (*bld_proc)(
        const char *entity_name, double x, double y, double z, double x_vec,
        double y_vec, double z_vec
) = NULL;
    return bld_proc(entity_name, x, y, z, x_vec, y_vec, z_vec);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051D3FA
*/
#ifdef BLD_NATIVE
int SetAuraActive(const char *entity_name, int is_active)
{
    int (*bld_proc)(const char *entity_name, int is_active) = NULL;
    return bld_proc(entity_name, is_active);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051D47C
*/
#ifdef BLD_NATIVE
int SetAuraParams(
        const char *entity_name, double size, double alpha,
        double colour_intensity, int hide_front_faces, int hide_back_faces,
        int alpha_mode
)
{
    int (*bld_proc)(
        const char *entity_name, double size, double alpha,
        double colour_intensity, int hide_front_faces, int hide_back_faces,
        int alpha_mode
) = NULL;
    return bld_proc(entity_name, size, alpha, colour_intensity, hide_front_faces, hide_back_faces, alpha_mode);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051D554
*/
#ifdef BLD_NATIVE
int SetAuraGradient(
        const char *entity_name, int gap, double r1, double g1, double b1,
        double alpha1, double starting_point, double r2, double g2, double b2,
        double alpha2, double ending_point
)
{
    int (*bld_proc)(
        const char *entity_name, int gap, double r1, double g1, double b1,
        double alpha1, double starting_point, double r2, double g2, double b2,
        double alpha2, double ending_point
) = NULL;
    return bld_proc(entity_name, gap, r1, g1, b1, alpha1, starting_point, r2, g2, b2, alpha2, ending_point);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051D63D
*/
#ifdef BLD_NATIVE
void GetMouseState(int *invert, double *xsens, double *ysens)
{
    void (*bld_proc)(int *invert, double *xsens, double *ysens) = NULL;
    bld_proc(invert, xsens, ysens);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051D677
*/
#ifdef BLD_NATIVE
void SetMouseState(int invert, double xsens, double ysens)
{
    void (*bld_proc)(int invert, double xsens, double ysens) = NULL;
    bld_proc(invert, xsens, ysens);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051D6B1
*/
#ifdef BLD_NATIVE
double GetPSeconds()
{
    double (*bld_proc)() = NULL;
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051D6D4
*/
#ifdef BLD_NATIVE
void BodInspector()
{
    void (*bld_proc)() = NULL;
    bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051D6DE
*/
#ifdef BLD_NATIVE
void SaveScreeShoot(const char *filename, int width, int height)
{
    void (*bld_proc)(const char *filename, int width, int height) = NULL;
    bld_proc(filename, width, height);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0051D6FB
*/
#ifdef BLD_NATIVE
void CleanArea(double x, double y, double z, float distance)
{
    void (*bld_proc)(double x, double y, double z, float distance) = NULL;
    bld_proc(x, y, z, distance);
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
