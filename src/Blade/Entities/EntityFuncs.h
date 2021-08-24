
#ifndef ENTITY_FUNCS_H

#define ENTITY_FUNCS_H

#include <bld_python.h>
#include <AnalyticGeometry/Vector.h>
#include <export.h>

class B_Entity;
class B_Sound;
class B_Spline;

typedef struct {
    const char *name;
    int executed;
} combo_t;


#define ENT_INT_STATIC                    0
#define ENT_INT_N_LIGHTS                  1
#define ENT_INT_N_FIRES                   2
#define ENT_INT_PERSON                    4
#define ENT_INT_SEND_SECTOR_MSGS          5
#define ENT_INT_VISIBLE                   6
#define ENT_INT_FLICK                     7
#define ENT_INT_ACTION_AREA               8
#define ENT_INT_R_ATTACK                  9
#define ENT_INT_WEAPON                   10
#define ENT_INT_ACTOR                    11
#define ENT_INT_ARROW                    12
#define ENT_INT_PHYSIC                   13
#define ENT_INT_GLOW                     14
#define ENT_INT_CAN_USE                  16
#define ENT_INT_INVENTORY_VISIBLE        17
#define ENT_INT_ACTIVE                   18
#define ENT_INT_DAMAGE                   20
#define ENT_INT_SEND_NOTIFY              21
#define ENT_INT_SOLID                    22
#define ENT_INT_GOF                      23
#define ENT_INT_GOB                      24
#define ENT_INT_TR                       25
#define ENT_INT_TL                       26
#define ENT_INT_RUN                      27
#define ENT_INT_LEVEL                    28
#define ENT_INT_CURRENT_AREAS            29
#define ENT_INT_BLIND                    30
#define ENT_INT_TEXTURE                  30
#define ENT_INT_DEAF                     31
#define ENT_INT_WOUNDED_ZONES            32
#define ENT_INT_TEST_HIT                 33
#define ENT_INT_IN_COMBAT                34
#define ENT_INT_FIXED_TARGET             35
#define ENT_INT_EXCLUSION_GROUP          36
#define ENT_INT_SIMPLE_SECTIONS          37
#define ENT_INT_SNEAK                    38
#define ENT_INT_CAST_SHADOWS             39
#define ENT_INT_ATTACK                   40
#define ENT_INT_BLOCK                    41
#define ENT_INT_COMBAT_DIST_FLAG         42
#define ENT_INT_T_TYPE                   43
#define ENT_INT_S_TYPE                   44
#define ENT_INT_EARTH_QUAKE              45
#define ENT_INT_ON_FLOOR                 46
#define ENT_INT_LAST_BAY_NUM_ANIMS       47
#define ENT_INT_HEARD                    48
#define ENT_INT_SEEN                     49
#define ENT_INT_SEND_TRIGGER_SECTOR_MSGS 50
#define ENT_INT_PARTIAL_LEVEL            51
#define ENT_INT_IN_DESTRUCTOR_ATTACK     52
#define ENT_INT_GLOW_TEST_Z              53
#define ENT_INT_GLOW_SIZE_DIST           53
#define ENT_INT_OBJ_C_TEST               54
#define ENT_INT_RETURNS                  55
#define ENT_INT_MUTILATIONS_MASK         56
#define ENT_INT_GO_TO_JOGGING            57
#define ENT_INT_EXCLUSION_MASK           58
#define ENT_INT_P_VIEW_TYPE              59
#define ENT_INT_CONTINUOUS_BLOCK         60
#define ENT_INT_DEFENCE_NEEDED           61
#define ENT_INT_AIM                      62
#define ENT_INT_WILL_CRASH_IN_FLOOR      64
#define ENT_INT_INVERTED_ROUTE           65
#define ENT_INT_GO_TO_SNEAKING           66
#define ENT_INT_CONTINUOUS_DAMAGE        67
#define ENT_INT_WILL1AA_TO2AA            68
#define ENT_INT_N_SUBSCRIBED_LISTS       69
#define ENT_INT_IN_WORLD                 71
#define ENT_INT_IN_ATTACK                72
#define ENT_INT_RANGE_ACTIVE             73
#define ENT_INT_MELEE_ACTIVE             74
#define ENT_INT_TRAIL_MODE               75
#define ENT_INT_WEAPON_MODE              76
#define ENT_INT_STATIC_WEAPON_MODE       77
#define ENT_INT_IS_STOPPED               78
#define ENT_INT_PLAYING                  79
#define ENT_INT_REFLECTS                 80
#define ENT_INT_FROZEN                   81
#define ENT_INT_OBJECT                   82
#define ENT_INT_RANGE_DEFENCE_CAPABLE    83

#define ENT_FLT_SCALE                     0
#define ENT_FLT_FIRES_INTENSITY           1
#define ENT_FLT_LIGHTS_INTENSITY          2
#define ENT_FLT_LIGHTS_PRECISION          3
#define ENT_FLT_INTENSITY                 5
#define ENT_FLT_PRECISSION                6
#define ENT_FLT_INTENSITY2                7
#define ENT_FLT_FLICK_PERIOD              8
#define ENT_FLT_ANGLE                     9
#define ENT_FLT_LIFE                     10
#define ENT_FLT_ENERGY                   11
#define ENT_FLT_DAMAGE_RADIUS            12
#define ENT_FLT_T2_FALL                  13
#define ENT_FLT_LOOK_AT_TIME             16
#define ENT_FLT_MASS                     17
#define ENT_FLT_PITCH                    20
#define ENT_FLT_ANM_POS                  21
#define ENT_FLT_DISPLACEMENT             22
#define ENT_FLT_REFLECTION               24
#define ENT_FLT_TRANSPARENCY             25
#define ENT_FLT_F_P_S                    26
#define ENT_FLT_TRAIL_LIFE_TIME          27
#define ENT_FLT_MIN_DISTANCE             28
#define ENT_FLT_MAX_DISTANCE             29
#define ENT_FLT_VOLUME                   30
#define ENT_FLT_BASE_VOLUME              31
#define ENT_FLT_SOUND_SCALE              32
#define ENT_FLT_MIN_SECTOR_LENGTH        33
#define ENT_FLT_MAX_AMPLITUDE            34
#define ENT_FLT_WUEA                     35
#define ENT_FLT_ROUTE_TYPE               36
#define ENT_FLT_ANG_VEL                  37
#define ENT_FLT_SIZE_FACTOR              38
#define ENT_FLT_BAY_ROUTE                39
#define ENT_FLT_ASTAR_STATE              40
#define ENT_FLT_DIST2_FLOOR              41
#define ENT_FLT_Y_GRAVITY                42
#define ENT_FLT_FRICTION                 43
#define ENT_FLT_FRICTION2                44
#define ENT_FLT_P_P_S                    45
#define ENT_FLT_DEATH_TIME               46
#define ENT_FLT_RANDOM_VELOCITY          47
#define ENT_FLT_RANDOM_VELOCITY_V        48
#define ENT_FLT_TIME2_LIVE               49
#define ENT_FLT_TIME2_LIVE_V             50
#define ENT_FLT_DIST                     51
#define ENT_FLT_EARTH_QUAKE_FACTOR       52
#define ENT_FLT_BLOCKING_PROPENSITY      53
#define ENT_FLT_RADIUS                   54
#define ENT_FLT_HEIGHT                   55
#define ENT_FLT_CONE                     56
#define ENT_FLT_ALPHA                    57
#define ENT_FLT_LAST_BAY_ANG_ANIMS       58
#define ENT_FLT_LAST_TIME_SEEN           59
#define ENT_FLT_ZOOM_S                   60
#define ENT_FLT_ZOOM_T                   61
#define ENT_FLT_ORIGIN_S                 62
#define ENT_FLT_ORIGIN_T                 63
#define ENT_FLT_ANGLE_2                  67
#define ENT_FLT_FRAME                    68
#define ENT_FLT_ZOOM                     69
#define ENT_FLT_NORMAL_VELOCITY          70
#define ENT_FLT_FOLLOW_FACTOR            71
#define ENT_FLT_SELF_ILUM                72
#define ENT_FLT_ACCURACY                 73
#define ENT_FLT_AIM_OFF_TARGET           74
#define ENT_FLT_LAST_ATTACK_TIME         75
#define ENT_FLT_DISPLACEMENT_LIMIT       76
#define ENT_FLT_V_D                      77
#define ENT_FLT_A_D                      78
#define ENT_FLT_SELF_LIGHT               79

#define ENT_STR_NAME                      0
#define ENT_STR_KIND                      1
#define ENT_STR_PREV_ANIM_NAME            2
#define ENT_STR_LOOK_AT                   3
#define ENT_STR_LOOK_AT_PERSON            4
#define ENT_STR_MATERIAL                  5
#define ENT_STR_ANIMATION                 6
#define ENT_STR_ANIM_FULL_NAME            9
#define ENT_STR_ANIM_NAME                10
#define ENT_STR_INVENTORY_SELECTION      11
#define ENT_STR_CHAR_TYPE                12
#define ENT_STR_CHAR_TYPE_EXT            13
#define ENT_STR_PARENT                   14
#define ENT_STR_INV_RIGHT                15
#define ENT_STR_INV_LEFT                 16
#define ENT_STR_GLOW_TEXTURE             17
#define ENT_STR_OBJECT_NAME              18
#define ENT_STR_PERSON_NAME              19
#define ENT_STR_PERSON_NODE_NAME         20
#define ENT_STR_MESH                     21
#define ENT_STR_INV_RIGHT_BACK           22
#define ENT_STR_INV_LEFT_BACK            23
#define ENT_STR_ACTIVE_ENEMY             24
#define ENT_STR_E_TARGET                 25
#define ENT_STR_E_SOURCE                 26
#define ENT_STR_COMBAT_GROUP             27
#define ENT_STR_BLEND_MODE               28
#define ENT_STR_INV_LEFT2                29
#define ENT_STR_RASTER_MODE              31
#define ENT_STR_TEXTURE_NAME             32
#define ENT_STR_RASTER_MODE_Z            33
#define ENT_STR_RASTER_MODE_ALPHA        34
#define ENT_STR_LAST_SOUND               35
#define ENT_STR_FIRE_PARTICLE_TYPE       36
#define ENT_STR_PARTICLE_TYPE            37
#define ENT_STR_SUBSCRIBED_LIST          38
#define ENT_STR_MESH_NAME                39
#define ENT_STR_GOT_ANM_TYPE             40

#define ENT_VEC_POSITION                  0
#define ENT_VEC_LIGHTS_COLOUR             2
#define ENT_VEC_IMPULSE                   3
#define ENT_VEC_COLOR                     4
#define ENT_VEC_VELOCITY                  5
#define ENT_VEC_GRAVITY                   6
#define ENT_VEC_ANGULAR_VELOCITY          7
#define ENT_VEC_LOOK_AT_COORD             8
#define ENT_VEC_SLIDING_SURFACE           9
#define ENT_VEC_SLIDE_TO                 10
#define ENT_VEC_TRAIL_COLOR              11
#define ENT_VEC_ADD_BAY_POINT            12
#define ENT_VEC_TARGET                   13
#define ENT_VEC_OUTER_GLOW_COLOR         14
#define ENT_VEC_INNER_GLOW_COLOR         15
#define ENT_VEC_CORE_GLOW_COLOR          16
#define ENT_VEC_INIT_POS                 17
#define ENT_VEC_ENEMY_LAST_SEEN          18
#define ENT_VEC_FLY_VELOCITY             19
#define ENT_VEC_D1                       20
#define ENT_VEC_D2                       21
#define ENT_VEC_D                        22
#define ENT_VEC_T_ANG                    24
#define ENT_VEC_T_POS                    25
#define ENT_VEC_DEEP_COLOR               26
#define ENT_VEC_LAST_SOUND_POSITION      27
#define ENT_VEC_AIM_VECTOR               28

#define ENT_FNC_FRAME                     0
#define ENT_FNC_HIT_FUNC                  1
#define ENT_FNC_TIMER_FUNC                2
#define ENT_FNC_HEAR_FUNC                 3
#define ENT_FNC_ON_STOP                   4
#define ENT_FNC_ON_ANIMATION_END_FUNC     5
#define ENT_FNC_TOUCH_FLUID               6
#define ENT_FNC_ON_PATH_NODE              7
#define ENT_FNC_USE_FUNC                  8
#define ENT_FNC_SEE_FUNC                  9
#define ENT_FNC_ENTER_CLOSE              10
#define ENT_FNC_ENTER_LARGE              11
#define ENT_FNC_ANM_ENDED                12
#define ENT_FNC_DELAY_NO_SEEN_FUNC       13
#define ENT_FNC_ROUTE_ENDED              14
#define ENT_FNC_IM_DEAD_FUNC             15
#define ENT_FNC_IM_HURT_FUNC             16
#define ENT_FNC_ENEMY_DEAD_FUNC          17
#define ENT_FNC_NO_ALLOWED_AREA_FUNC     18
#define ENT_FNC_ENEMY_NO_ALLOWED_AREA    19
#define ENT_FNC_ON_HIT                   20
#define ENT_FNC_CHAR_SEEING_ENEMY        21
#define ENT_FNC_ANM_TRAN                 22
#define ENT_FNC_TAKE_FUNC                23
#define ENT_FNC_THROW_FUNC               24
#define ENT_FNC_NEW_COMBO_FUNC           25
#define ENT_FNC_TOGGLE_COMBAT            26
#define ENT_FNC_STICK_FUNC               27
#define ENT_FNC_MUTILATE_FUNC            29
#define ENT_FNC_DAMAGE_FUNC              30
#define ENT_FNC_CHANGE_NODE              31
#define ENT_FNC_HIT_SHIELD_FUNC          32
#define ENT_FNC_INFLICT_HIT              33
#define ENT_FNC_ENTER_PRIMARY_AA         34
#define ENT_FNC_ENTER_SECONDARY_AA       35
#define ENT_FNC_ON_STEP                  36
#define ENT_FNC_ATTACK_FUNC              37
#define ENT_FNC_BIG_FALL_FUNC            38

#define ENT_QUAT_ORIENTATION              1

#ifdef __cplusplus
extern "C" {
#endif

LIB_EXP int GetSplinePos(B_Spline *spline, float time, B_Vector *position);
LIB_EXP void AddNodeSpline(
    B_Spline *spline, int nodeIndex, double time, B_Vector position,
    B_Vector startTangent, B_Vector endTangent);
LIB_EXP int CloseSpline(B_Spline *spline);
LIB_EXP int ClearSpline(B_Spline *spline);
LIB_EXP B_Entity *CreateSpark(
    const char *name, const B_Vector &spark_point, const B_Vector &spark_dir,
    double d_unknown1, double d_unknown2, double d_unknown3,
    double d_unknown4, double d_unknown5, int i_unknown6, int i_unknown7,
    int i_unknown8, int i_unknown9, int i_unknown10, int i_unknown11,
    float d_unknown12, float d_unknown13, float d_unknown14, int i_unknown15
);
LIB_EXP B_Entity *CreateEntity(
    const char *name, const char *kind, double x, double y, double z,
    const char *parent_class, const char *unknown
);
LIB_EXP int DeleteEntity(const char *name);
LIB_EXP B_Entity *CreateEntityDecal(
    const char *name, double x, double y, double z, int i_unknown,
    double d_unknown1, double d_unknown2
);
LIB_EXP B_Entity *GetEntity(const char *name);
LIB_EXP B_Entity *GetEntityI(int index);
LIB_EXP const char *GetEntityName(B_Entity *entity);
LIB_EXP int GetEntitiesAt(
    double x, double y, double z, double radius, char ***entity_names
);
LIB_EXP int GetEntitiesVisibleFrom(
    double xc, double yc, double zc, double radius, double xdir,
    double ydir, double zdir, double angle, char ***entity_names
);
LIB_EXP int GetObjectEntitiesVisibleFrom(
    double xc, double yc, double zc, double radius, double xdir,
    double ydir, double zdir, double angle, char ***entity_names
);
LIB_EXP int GetEnemiesVisibleFrom(
    double xc, double yc, double zc, double radius, double xdir,
    double ydir, double zdir, double angle, char ***enemy_names
);
LIB_EXP int SetCombos(
    const char *person_name, int num_combos, char **combos_names,
    int *combos_executed
);
LIB_EXP int GetCombos(const char *person_name, combo_t **combos);
LIB_EXP int GetWeaponCombos(
    const char *person_name, const char *weapon_kind, combo_t **combos
);
LIB_EXP int nEntities(void);
LIB_EXP int GetNewExclusionGroupId(void);
LIB_EXP int AddCameraEvent(const char *entity_name, int frame, PyObject *func);
LIB_EXP int DeleteCameraEvent(const char *entity_name, int frame);
LIB_EXP int CameraAddSourceNode(
    const char *entity_name, float time, B_Vector position
);
LIB_EXP int CameraAddTargetNode(
    const char *entity_name, float time, B_Vector position
);
LIB_EXP int CameraSetStartTangentSourceNode(
    const char *entity_name, int nodeIndex, B_Vector startTangent
);
LIB_EXP int CameraSetEndTangentSourceNode(
    const char *entity_name, int nodeIndex, B_Vector endTangent
);
LIB_EXP int CameraSetStartTangentTargetNode(
    const char *entity_name, int nodeIndex, B_Vector startTangent
);
LIB_EXP int CameraSetEndTangentTargetNode(
    const char *entity_name, int nodeIndex, B_Vector endTangent
);
LIB_EXP int CameraSetPersonView(
    const char *entity_name, const char *person_name
);
LIB_EXP int CameraSetMaxCamera(
    const char *entity_name, const char *cam_file_name, int i_unknown,
    int num_frames
);
LIB_EXP int CameraCut(const char *entity_name);
LIB_EXP int CameraSetTravelingView(
    const char *entity_name, int s_type, int t_type
);
LIB_EXP int CameraClearPath(const char *entity_name, int node);
LIB_EXP int CameraStartPath(const char *entity_name, int node);
LIB_EXP int UseEntity(const char *entity_name);
LIB_EXP int ChangeEntityStatic(const char *entity_name, int is_static);
LIB_EXP int ChangeEntityActor(const char *entity_name, int is_actor);
LIB_EXP int ChangeEntityPerson(const char *entity_name, int is_person);
LIB_EXP int ChangeEntityWeapon(const char *entity_name, int is_weapon);
LIB_EXP int ChangeEntityArrow(const char *entity_name, int is_arrow);
LIB_EXP int SetNextAttack(
    const char *entity_name, const char *attack, int *res
);
LIB_EXP B_Entity *SeverLimb(const char *entity_name, int limb);
LIB_EXP int SubscribeEntityToList(
    const char *entity_name, const char *timer_name
);
LIB_EXP int MessageEvent(
    const char *entity_name, int message_type, int unknown1, int unknown2
);
LIB_EXP int InterruptCombat(const char *entity_name);
LIB_EXP const char *GetParticleEntity(const char *entity_name);
LIB_EXP int Rel2AbsVector(
    const char *entity_name, double x_rel, double y_rel, double z_rel,
    double *x_abs, double *y_abs, double *z_abs
);
LIB_EXP int Rel2AbsPoint(
    const char *entity_name, double x_rel, double y_rel, double z_rel,
    double *x_abs, double *y_abs, double *z_abs
);
LIB_EXP int Rel2AbsVectorN(
    const char *entity_name, double x_rel, double y_rel, double z_rel,
    const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
);
LIB_EXP int Rel2AbsPointN(
    const char *entity_name, double x_rel, double y_rel, double z_rel,
    const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
);
LIB_EXP int Abs2RelVector(
    const char *entity_name, double x_abs, double y_abs, double z_abs,
    double *x_rel, double *y_rel, double *z_rel
);
LIB_EXP int Abs2RelPoint(
    const char *entity_name, double x_abs, double y_abs, double z_abs,
    double *x_rel, double *y_rel, double *z_rel
);
LIB_EXP int Abs2RelVectorN(
    const char *entity_name, double x_abs, double y_abs, double z_abs,
    const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
);
LIB_EXP int Abs2RelPointN(
    const char *entity_name, double x_abs, double y_abs, double z_abs,
    const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
);
LIB_EXP double SQDistance2(const char *entity_name1, const char *entity_name2);
LIB_EXP int RemoveEntityFromList(
    const char *entity_name, const char *timer_name
);
LIB_EXP int CreateTimer(const char *timer_name, double period);
LIB_EXP int GetnTimers(void);
LIB_EXP int GetTimerInfo(
    int timer_index, const char **timer_name, double *period
);
LIB_EXP int GetEntityIntProperty(
    const char *entity_name, int property_kind, int index, int *value
);
LIB_EXP int GetEntityFloatProperty(
    const char *entity_name, int property_kind, int index, double *value
);
LIB_EXP int GetEntityStringProperty(
    const char *entity_name, int property_kind, int index,
    const char **value
);
LIB_EXP int GetEntityVectorProperty(
    const char *entity_name, int property_kind, int index,
    double *x, double *y, double *z
);
LIB_EXP int GetEntityQuatProperty(
    const char *entity_name, int property_kind, int index, double *quat1,
    double *quat2, double *quat3, double *quat4
);
LIB_EXP int GetEntityFuncProperty(
    const char *entity_name, int property_kind, int index, PyObject **func
);
LIB_EXP int SetEntityIntProperty(
    const char *entity_name, int property_kind, int index, int value
);
LIB_EXP int SetEntityFloatProperty(
    const char *entity_name, int property_kind, int index, double value
);
LIB_EXP int SetEntityStringProperty(
    const char *entity_name, int property_kind, int index,
    const char *value
);
LIB_EXP int SetEntityVectorProperty(
    const char *entity_name, int property_kind, int index,
    double x, double y, double z
);
LIB_EXP int SetEntityQuatProperty(
    const char *entity_name, int property_kind, int index, double quat1,
    double quat2, double quat3, double quat4
);
LIB_EXP int SetEntityData(const char *entity_name, PyObject *data);
LIB_EXP PyObject *GetEntityData(const char *entity_name);
LIB_EXP int SetEntityFuncProperty(
    const char *entity_name, int property_kind, int index, PyObject *func
);
LIB_EXP int SetEntityInternalState(
    const char *entity_name, PyObject *internal_state
);
LIB_EXP int GetEntityInternalState(
    const char *entity_name, PyObject **internal_state
);
LIB_EXP int AddSoundAnim(
    const char *entity_name, const char *anm_event, double time, B_Sound *sound
);
LIB_EXP int AddSoundEvent(
    const char *entity_name, const char *event, B_Sound *sound
);
LIB_EXP int AddScheduledFunc(
    double time, PyObject *func, PyObject *args, const char *name
);
LIB_EXP int RemoveScheduledFunc(const char *name);
LIB_EXP int GetnScheduledFuncs(void);
LIB_EXP int GetScheduledFunc(
    int index, PyObject **func, PyObject **args, const char **name,
    double *time
);
LIB_EXP int EntityRotate(
    const char *entity_name, double x_dir, double y_dir, double z_dir,
    double velocity, int unknown
);
LIB_EXP int EntityRotateAbs(
    const char *entity_name, double x, double y, double z, double x_dir,
    double y_dir, double z_dir, double angle, int i_unknown
);
LIB_EXP int EntityRotateRel(
    const char *entity_name, double x, double y, double z, double x_dir,
    double y_dir, double z_dir, double angle, int i_unknown
);
LIB_EXP int EntityMove(
    const char *entity_name, double x, double y, double z, int unknown
);
LIB_EXP int EntitySetPosition(
    const char *entity_name, double x, double y, double z, int unknown
);
LIB_EXP int EntitySetOrientation(
    const char *entity_name, double quat1, double quat2, double quat3,
    double quat4, int unknown
);
LIB_EXP int EntityPutToWorld(const char *entity_name);
LIB_EXP int EntityAddAnmEventFunc(
    const char *entity_name, const char *anm_event, PyObject *func
);
LIB_EXP int EntityDelAnmEventFunc(
    const char *entity_name, const char *anm_event
);
LIB_EXP int EntityClearAnmEventFuncs(const char *entity_name);
LIB_EXP int ClearActorPath(const char *entity_name);
LIB_EXP int AddActorPathnode(
    const char *entity_name, double time, double x, double y, double z
);
LIB_EXP int StartActorPath(const char *entity_name);
LIB_EXP int GoToActorPath(
    const char *entity_name, int i_unknown, double d_unknown
);
LIB_EXP int TestPos(
    const char *entity_name, double x, double y, double z, double max_fall,
    int action_area, int *isCorrect
);
LIB_EXP int TestPosInOwnBox(
    const char *entity_name, double x, double y, double z, double box_size,
    int *isCorrect
);
LIB_EXP int TurnOnActor(const char *entity_name);
LIB_EXP int TurnOffActor(const char *entity_name);
LIB_EXP int SetAttackList(const char *entity_name, PyObject *attack_list);
LIB_EXP PyObject *GetAttackList(const char *entity_name);
LIB_EXP PyObject *GetGroupMembers(const char *entity_name);
LIB_EXP PyObject *GetCombatants(const char *entity_name);
LIB_EXP int SetActorNodeStartTangent(
    const char *entity_name, int unknown1, double unknown2, double unknown3,
    double unknown4
);
LIB_EXP int SetActorNodeEndTangent(
    const char *entity_name, int unknown1, double unknown2, double unknown3,
    double unknown4
);
LIB_EXP int SetSound(const char *entity_name, const char *sound);
LIB_EXP int SetObjectSound(const char *entity_name, const char *sound);
LIB_EXP int PlayEntitySound(const char *entity_name, int i_unknown);
LIB_EXP int Stop(const char *entity_name);
LIB_EXP int StopAt(const char *entity_name, double x, double y, double z);
LIB_EXP int CheckAnimCol(
    const char *entity_name, const char *anm_name, const char *obj_name,
    int unknown, int *res
);
LIB_EXP int RemoveFromInvent(const char *entity_name, const char *obj_name);
LIB_EXP int ResetWounds(const char *entity_name);
LIB_EXP int RemoveFromInventRight(const char *entity_name);
LIB_EXP int RemoveFromInventLeft(const char *entity_name);
LIB_EXP int RemoveFromInventLeft2(const char *entity_name);
LIB_EXP int CanISee(
    const char *entity_name, const char *seen_entity_name, int *canISee
);
LIB_EXP int CanISeeFrom(
    const char *entity_name, const char *seen_entity_name,
    double x, double y, double z, int *canISee
);
LIB_EXP int SetActiveEnemy(
    const char *entity_name, const char *active_enemy_name, int *unknown
);
LIB_EXP int ExcludeHitFor(
    const char *entity_name, const char *exclude_hit_for_name,
    void *unknown
);
LIB_EXP int ExcludeHitInAnimationFor(
    const char *entity_name, const char *exclude_hit_for_name, void *unknown
);
LIB_EXP int Link(
    const char *entity_name, const char *child_entity_name, void *unknown
);
LIB_EXP int LinkToNode(
    const char *entity_name, const char *child_name, int node_index,
    void *unknown
);
LIB_EXP int LinkAnchors(
    const char *entity_name, const char *entity_anchor_name,
    const char *child_name, const char *child_anchor_name, void *unknown
);
LIB_EXP int UnlinkChilds(const char *entity_name);
LIB_EXP int GetNodeIndex(
    const char *entity_name, const char *node_name, int *index
);
LIB_EXP int UnlinkChild(
    const char *entity_name, const char *child_entity_name, void *unknown
);
LIB_EXP int InsideActionArea(
    const char *entity_name, int action_area, int *is_inside
);
LIB_EXP int SetTmpAnmFlags(
    const char *entity_name, int wuea, int mod_y, int solf, int copy_rot,
    int bng_mov, int headf, int unknown
);
LIB_EXP int SetAnmFlags(
    const char *entity_name, const char *anm_name, int wuea, int mod_y,
    int solf, int copy_rot, int bng_mov, int headf
);
LIB_EXP int LaunchAnimation2(
    const char *entity_name, const char *anm_name1, const char *anm_name2
);
LIB_EXP int SetEnemy(const char *entity_name, const char *enemy_name);
LIB_EXP const char *GetEnemy(const char *entity_name);
LIB_EXP int Chase(
    const char *entity_name, const char *enemy_name, int action_area
);
LIB_EXP int ResetChase(const char *entity_name);
LIB_EXP int GoTo(const char *entity_name, int x, int y, int z);
LIB_EXP int CanGoTo(const char *entity_name, int x, int y, int z);
LIB_EXP int QuickFace(const char *entity_name, double angle);
LIB_EXP int Face(const char *entity_name, double angle);
LIB_EXP int StartLooking(const char *entity_name, int x, int y, int z);
LIB_EXP int StopLooking(const char *entity_name);
LIB_EXP int LookAtEntity(
    const char *entity_name, const char *look_at_entity_name
);
LIB_EXP int LaunchWatch(const char *entity_name);
LIB_EXP int GetActionMode(const char *entity_name, int *action_mode);
LIB_EXP int StartGrabbing(const char *entity_name);
LIB_EXP int StopGrabbing(const char *entity_name);
LIB_EXP int AddEntWatchAnim(const char *entity_name, const char *anm_name);
LIB_EXP int Freeze(const char *entity_name);
LIB_EXP int UnFreeze(const char *entity_name);
LIB_EXP int SwitchTo1H(const char *entity_name);
LIB_EXP int GetDummyAxis(
    const char *entity_name, const char *anchor_name, double x_dir,
    double y_dir, double z_dir, double *x_dummy_axis, double *y_dummy_axis,
    double *z_dummy_axis, int unknown
);
LIB_EXP int GraspPos(
    const char *entity_name, const char *grasp, double *x, double *y,
    double *z
);
LIB_EXP int SwitchToBow(const char *entity_name);
LIB_EXP int LaunchBayRoute(const char *entity_name);
LIB_EXP int EntityCatchOnFire(
    const char *entity_name, double x, double y, double z
);
LIB_EXP int GetNChildren(const char *entity_name);
LIB_EXP const char *GetChild(const char *entity_name, int index);
LIB_EXP int CreateBipedData(const char *biped_name, const char *kind);
LIB_EXP int AddBipedAction(
    const char *char_name, const char *action_name,
    const char *animation_name, double d_unknown1, double d_unknown2,
    int i_unknown
);
LIB_EXP int RemoveBipedAction(const char *race_name, const char *action_name);
LIB_EXP int AddBipedActionC(
    const char *char_name, const char *action_name,
    const char *animation_name, const char *s_unknown, double d_unknown1,
    double d_unknown2, int i_unknown
);
LIB_EXP int SetActionEventTable(
    const char *race_name, const char *action_name, const char *table_name
);
LIB_EXP int SetEventTableFuncC(
    const char *event_table_name, const char *event_type, const char *func_name
);
LIB_EXP int SetEventTableFunc(
    const char *event_table_name, const char *event_type, PyObject *func
);
LIB_EXP int DoAction(const char *entity_name, const char *action_name);
LIB_EXP int DoActionWI(
    const char *entity_name, const char *action_name,
    int interpolation_type, double time, double unknown1
);
LIB_EXP int SetOnFloor(const char *entity_name);
LIB_EXP int RaiseEvent(const char *entity_name, const char *event_name);
LIB_EXP int SetSolidMask(const char *kind, int mask);
LIB_EXP int IsValidEntity(const char *entity_name);
LIB_EXP int EntityRemoveFromWorld(const char *entity_name);
LIB_EXP int EntityRemoveFromWorldWithChilds(const char *entity_name);
LIB_EXP int ImpulseC(
    const char *entity_name, double x, double y, double z, double x_vec,
    double y_vec, double z_vec
);
LIB_EXP int SetAuraActive(const char *entity_name, int is_active);
LIB_EXP int SetAuraParams(
    const char *entity_name, double size, double alpha,
    double colour_intensity, int hide_front_faces, int hide_back_faces,
    int alpha_mode
);
LIB_EXP int SetAuraGradient(
    const char *entity_name, int gap, double r1, double g1, double b1,
    double alpha1, double starting_point, double r2, double g2, double b2,
    double alpha2, double ending_point
);
LIB_EXP void GetMouseState(int *invert, double *xsens, double *ysens);
LIB_EXP void SetMouseState(int invert, double xsens, double ysens);
LIB_EXP double GetPSeconds(void);
LIB_EXP void BodInspector(void);
LIB_EXP void SaveScreeShoot(const char *filename, int width, int height);
LIB_EXP void CleanArea(double x, double y, double z, float distance);

#ifdef __cplusplus
}
#endif


#endif /* ENTITY_FUNCS_H */
