
#ifndef BLADE_EXT_H

#define BLADE_EXT_H

#include <bld_server_info.h>
#include <export.h>

#ifdef GetCommandLine
/* Undefine WINAPI macro GetCommandLine to avoid collision with
 * Blade.GetCommandLine
 */
#undef GetCommandLine

#endif

#ifdef GetObject
/* Undefine WinGDI macro GetObject to avoid collision with
 * Blade.GetObject
 */
#undef GetObject

#endif

#ifdef __cplusplus

class entity_t;
class material_t;

#else

typedef struct _entity_t entity_t;
typedef struct _material_t material_t;

#endif

typedef struct {
        const char *name;
        int executed;
} combo_t;

typedef struct {
        double x;
        double y;
} point_2d_t;

typedef struct {
        double x;
        double y;
        double z;
} point_3d_t;


#define CHR_FLT_TURN_SPEED                0
#define CHR_FLT_DIE_FALL                  1
#define CHR_FLT_J_DIST                    2
#define CHR_FLT_J_DIST_2                  3
#define CHR_FLT_J_COST                    4
#define CHR_FLT_MAX_FALL                  5
#define CHR_FLT_MAX_STAIR                 6
#define CHR_FLT_FOV                       7
#define CHR_FLT_MAX_GRAB                 10
#define CHR_FLT_MED_GRAB                 11
#define CHR_FLT_MIN_TAKE                 13
#define CHR_FLT_MAX_TAKE_1               14
#define CHR_FLT_MAX_TAKE_2               15
#define CHR_FLT_MAX_TAKE_3               16
#define CHR_FLT_MAX_TAKE_4               17
#define CHR_FLT_MAX_TAKE_5               18
#define CHR_FLT_REACH                    19
#define CHR_FLT_MIN_2_GRAB               20
#define CHR_FLT_HEAR_MIN_VOLUME          21
#define CHR_FLT_MOV_FRWD_SPEED_IN_STRAFE 22
#define CHR_FLT_MOV_BKWD_SPEED_IN_STRAFE 23
#define CHR_FLT_MAX_COMBAT_DIST          24
#define CHR_FLT_DIST_STOP                25
#define CHR_FLT_DIST_STOP_2              26
#define CHR_FLT_MAX_SEE_DIST             27
#define CHR_FLT_DIST_STOP_MAX_FACT       28

#define CHR_STR_INT_NAME                  0
#define CHR_STR_ADD_ROUTE_ANIM            1
#define CHR_STR_BIPED                     2
#define CHR_STR_NO_ARMOUR                 3
#define CHR_STR_LOW_ARMOUR                4
#define CHR_STR_MED_ARMOUR                5
#define CHR_STR_HIGH_ARMOUR               6

#define CHR_INT_NATURAL_WEAPONS           0
#define CHR_INT_HEAD_CONTROLLED           1

#define CHR_FNC_ON_FIRST                  0


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


#define INV_INT_N_OBJECTS                 0
#define INV_INT_N_WEAPONS                 1
#define INV_INT_N_SHIELDS                 2
#define INV_INT_HAS_BOW                   3
#define INV_INT_N_KIND_OBJECTS            4
#define INV_INT_N_QUIVERS                 5
#define INV_INT_MAX_OBJECTS               6
#define INV_INT_MAX_WEAPONS               7
#define INV_INT_MAX_SHIELDS               8
#define INV_INT_MAX_QUIVERS               9
#define INV_INT_N_KEYS                   10
#define INV_INT_N_SPECIAL_KEYS           11
#define INV_INT_N_TABLETS                12
#define INV_INT_HOLDING_BOW              13
#define INV_INT_HAS_BOW_ON_BACK          15
#define INV_INT_HOLDING_SHIELD           16
#define INV_INT_HAS_SHIELD_ON_BACK       17

#define INV_STR_NAME                      0
#define INV_STR_OWNER                     1


#define INV_OBJ_TYPE_MAGIC_SHIELD        -5
#define INV_OBJ_TYPE_BOW                 -4
#define INV_OBJ_TYPE_OBJECT               0
#define INV_OBJ_TYPE_SHIELD               1
#define INV_OBJ_TYPE_WEAPON               2
#define INV_OBJ_TYPE_QUIVER               3
#define INV_OBJ_TYPE_KEY                  4
#define INV_OBJ_TYPE_SPECIAL_KEY          5
#define INV_OBJ_TYPE_TABLET               6


#define MAT_FLT_WEIGHT                    0

#define MAT_STR_NAME                      0

#define MAT_SND_FRICTION_SOUND            0
#define MAT_SND_HIT_SOUND                 1
#define MAT_SND_BREAK_SOUND               2


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


#define SND_INT_SEND_NOTIFY               0

#define SND_FLT_MIN_DISTANCE              0
#define SND_FLT_MAX_DISTANCE              1
#define SND_FLT_VOLUME                    2
#define SND_FLT_BASE_VOLUME               3
#define SND_FLT_SCALE                     4
#define SND_FLT_PITCH                     5

#define SND_STR_NAME                      0


#define TRL_FLT_TIME_2_LIVE               0
#define TRL_FLT_TRANSPARENCY              1
#define TRL_FLT_SHRINK_FACTOR             2

#define TRL_VEC_COLOR                     0


#ifdef __cplusplus
extern "C" {
#endif

LIB_EXP int WorldToMBW(const char *world);
LIB_EXP int SoundSystemActive(void);
LIB_EXP int SetSSFrecuency(int frequency);
LIB_EXP int SetSS2dChannels(int num_ch);
LIB_EXP int SetSS3dChannels(int num_ch);
LIB_EXP int SetSSFilter(int filter_output);
LIB_EXP int KillMusic(void);
LIB_EXP int ShutDownSoundChannels(void);
LIB_EXP int PauseSoundSystem(void);
LIB_EXP int PauseSoundSystemButMusic(void);
LIB_EXP int ResumeSoundSystem(void);
LIB_EXP int SetMusicVolume(float volume);
LIB_EXP double GetMusicVolume(void);
LIB_EXP int SetSoundVolume(double volume);
LIB_EXP double GetSoundVolume(void);
LIB_EXP int GetSSSpeakerConfig(void);
LIB_EXP int SetEAXOverride(int EAXOverride);
LIB_EXP int GetEAXOverride(void);
LIB_EXP int SaveSSConfig(void);
LIB_EXP int SetSSSpeakerConfig(int config);
LIB_EXP int GetSSQuality(void);
LIB_EXP int SetSSQuality(int SSQuality);
LIB_EXP int SetAutoGenTexture(const char *textureName, int textureEffect);
LIB_EXP int SetBloodLevel(int blood_level);
LIB_EXP int GetBloodLevel(void);
LIB_EXP int SetMutilationLevel(int mutilation_level);
LIB_EXP int GetMutilationLevel(void);
LIB_EXP const char *GetWorldFileName(void);
LIB_EXP int AddTranTime(
        const char *biped_name, const char *next_anm , const char *prev_anm,
        double time, int unknown
);
LIB_EXP int CheckAnims(void);
LIB_EXP int GiveAnims(const char *race_name);
LIB_EXP int GetAnimationDuration(const char *animation_name, double *duration);
LIB_EXP int SetAnimationFactor(const char *mov, double new_speed_factor);
LIB_EXP void SetTurnSpeed(const char *race_name, double new_speed);
LIB_EXP entity_t *GetEntity(const char *name);
LIB_EXP entity_t *GetEntityI(int index);
LIB_EXP entity_t *CreateEntity(
        const char *name, const char *kind, double x, double y, double z,
        const char *parent_class, const char *unknown
);
LIB_EXP entity_t *CreateEntityDecal(
        const char *name, double x, double y, double z, int i_unknown,
        double d_unknown1, double d_unknown2
);
LIB_EXP entity_t *CreateSpark(
        const char *name, point_3d_t *spark_point, point_3d_t *spark_dir,
        double d_unknown1, double d_unknown2, double d_unknown3,
        double d_unknown4, double d_unknown5, int i_unknown6, int i_unknown7,
        int i_unknown8, int i_unknown9, int i_unknown10, int i_unknown11,
        float d_unknown12, float d_unknown13, float d_unknown14, int i_unknown15
);
LIB_EXP const char *GetEntityName(entity_t *entity);
LIB_EXP int DeleteEntity(const char *name);
LIB_EXP int GetEntityStringProperty(
        const char *entity_name, int property_kind, int index,
        const char **value
);
LIB_EXP int SetEntityStringProperty(
        const char *entity_name, int property_kind, int index,
        const char *value
);
LIB_EXP int GetEntityFloatProperty(
        const char *entity_name, int property_kind, int index, double *value
);
LIB_EXP int SetEntityFloatProperty(
        const char *entity_name, int property_kind, int index, double value
);
LIB_EXP int GetEntityIntProperty(
        const char *entity_name, int property_kind, int index, int *value
);
LIB_EXP int SetEntityIntProperty(
        const char *entity_name, int property_kind, int index, int value
);
LIB_EXP int GetEntityVectorProperty(
        const char *entity_name, int property_kind, int index,
        double *x, double *y, double *z
);
LIB_EXP int SetEntityVectorProperty(
        const char *entity_name, int property_kind, int index,
        double x, double y, double z
);
LIB_EXP int GetEntityFuncProperty(
        const char *entity_name, int property_kind, int index, PyObject **func
);
LIB_EXP int SetEntityFuncProperty(
        const char *entity_name, int property_kind, int index, PyObject *func
);
LIB_EXP int GetEntityQuatProperty(
        const char *entity_name, int property_kind, int index, double *quat1,
        double *quat2, double *quat3, double *quat4
);
LIB_EXP int SetEntityQuatProperty(
        const char *entity_name, int property_kind, int index, double quat1,
        double quat2, double quat3, double quat4
);
LIB_EXP entity_t *SeverLimb(const char *entity_name, int limb);
LIB_EXP int ResetWounds(const char *entity_name);
LIB_EXP int ImpulseC(
        const char *entity_name, double x, double y, double z, double x_vec,
        double y_vec, double z_vec
);
LIB_EXP int AddCameraEvent(const char *entity_name, int frame, PyObject *func);
LIB_EXP int DeleteCameraEvent(const char *entity_name, int frame);
LIB_EXP int SubscribeEntityToList(
        const char *entity_name, const char *timer_name
);
LIB_EXP int MessageEvent(
        const char *entity_name, int message_type, int unknown1, int unknown2
);
LIB_EXP int Rel2AbsPoint(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
);
LIB_EXP int Rel2AbsPointN(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
);
LIB_EXP int Rel2AbsVector(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
);
LIB_EXP int Rel2AbsVectorN(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
);
LIB_EXP int Abs2RelPoint(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
);
LIB_EXP int Abs2RelPointN(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
);
LIB_EXP int Abs2RelVector(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
);
LIB_EXP int Abs2RelVectorN(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
);
LIB_EXP int GetDummyAxis(
        const char *entity_name, const char *anchor_name, double x_dir,
        double y_dir, double z_dir, double *x_dummy_axis, double *y_dummy_axis,
        double *z_dummy_axis, int unknown
);
LIB_EXP double SQDistance2(const char *entity_name1, const char *entity_name2);
LIB_EXP int RemoveEntityFromList(
        const char *entity_name, const char *timer_name
);
LIB_EXP int RemoveFromInvent(const char *entity_name, const char *obj_name);
LIB_EXP int RemoveFromInventRight(const char *entity_name);
LIB_EXP int RemoveFromInventLeft(const char *entity_name);
LIB_EXP int RemoveFromInventLeft2(const char *entity_name);
LIB_EXP int LaunchAnimation2(
        const char *entity_name, const char *anm_name1, const char *anm_name2
);
LIB_EXP int SetTmpAnmFlags(
        const char *entity_name, int wuea, int mod_y, int solf, int copy_rot,
        int bng_mov, int headf, int unknown
);
LIB_EXP int SetAnmFlags(
        const char *entity_name, const char *anm_name, int wuea, int mod_y,
        int solf, int copy_rot, int bng_mov, int headf
);
LIB_EXP int SetActiveEnemy(
        const char *entity_name, const char *active_enemy_name, int *unknown
);
LIB_EXP int CanISee(
        const char *entity_name, const char *seen_entity_name, int *canISee
);
LIB_EXP int CanISeeFrom(
        const char *entity_name, const char *seen_entity_name,
        double x, double y, double z, int *canISee
);
LIB_EXP int ExcludeHitFor(
        const char *entity_name, const char *exclude_hit_for_name,
        void *unknown
);
LIB_EXP int ExcludeHitInAnimationFor(
        const char *entity_name, const char *exclude_hit_for_name, void *unknown
);
LIB_EXP int UnlinkChild(
        const char *entity_name, const char *child_entity_name, void *unknown
);
LIB_EXP int Link(
        const char *entity_name, const char *child_entity_name, void *unknown
);
LIB_EXP int LinkAnchors(
        const char *entity_name, const char *entity_anchor_name,
        const char *child_name, const char *child_anchor_name, void *unknown
);
LIB_EXP int LinkToNode(
        const char *entity_name, const char *child_name, int node_index,
        void *unknown
);
LIB_EXP int GetNodeIndex(
        const char *entity_name, const char *node_name, int *index
);
LIB_EXP int GetNChildren(const char *entity_name);
LIB_EXP const char *GetChild(const char *entity_name, int index);
LIB_EXP int InsideActionArea(
        const char *entity_name, int action_area, int *is_inside
);
LIB_EXP int CheckAnimCol(
        const char *entity_name, const char *anm_name, const char *obj_name,
        int unknown, int *res
);
LIB_EXP int TestPos(
        const char *entity_name, double x, double y, double z, double max_fall,
        int action_area, int *isCorrect
);
LIB_EXP int TestPosInOwnBox(
        const char *entity_name, double x, double y, double z, double box_size,
        int *isCorrect
);
LIB_EXP int UnlinkChilds(const char *entity_name);
LIB_EXP int SetNextAttack(
        const char *entity_name, const char *attack, int *res
);
LIB_EXP int SetEnemy(const char *entity_name, const char *enemy_name);
LIB_EXP const char *GetEnemy(const char *entity_name);
LIB_EXP int Chase(
        const char *entity_name, const char *enemy_name, int action_area
);
LIB_EXP int ResetChase(const char *entity_name);
LIB_EXP int GoTo(const char *entity_name, int x, int y, int z);
LIB_EXP int CanGoTo(const char *entity_name, int x, int y, int z);
LIB_EXP int LookAtEntity(
        const char *entity_name, const char *look_at_entity_name
);
LIB_EXP int QuickFace(const char *entity_name, double angle);
LIB_EXP int Face(const char *entity_name, double angle);
LIB_EXP int StartLooking(const char *entity_name, int x, int y, int z);
LIB_EXP int StopLooking(const char *entity_name);
LIB_EXP int AddEntWatchAnim(const char *entity_name, const char *anm_name);
LIB_EXP int GraspPos(
        const char *entity_name, const char *grasp, double *x, double *y,
        double *z
);
LIB_EXP int Freeze(const char *entity_name);
LIB_EXP int UnFreeze(const char *entity_name);
LIB_EXP int SwitchTo1H(const char *entity_name);
LIB_EXP int SwitchToBow(const char *entity_name);
LIB_EXP int LaunchBayRoute(const char *entity_name);
LIB_EXP int LaunchWatch(const char *entity_name);
LIB_EXP int GetActionMode(const char *entity_name, int *action_mode);
LIB_EXP int StartGrabbing(const char *entity_name);
LIB_EXP int StopGrabbing(const char *entity_name);
LIB_EXP int AddSoundAnim(
        const char *entity_name, const char *anm_event, double time, int soundID
);
LIB_EXP int EntityAddAnmEventFunc(
        const char *entity_name, const char *anm_event, PyObject *func
);
LIB_EXP int EntityDelAnmEventFunc(
        const char *entity_name, const char *anm_event
);
LIB_EXP int EntityClearAnmEventFuncs(const char *entity_name);
LIB_EXP int AddSoundEvent(
        const char *entity_name, const char *event, int soundID
);
LIB_EXP int ClearActorPath(const char *entity_name);
LIB_EXP int CameraClearPath(const char *entity_name, int node);
LIB_EXP int CameraStartPath(const char *entity_name, int node);
LIB_EXP int AddActorPathnode(
        const char *entity_name, double time, double x, double y, double z
);
LIB_EXP int StartActorPath(const char *entity_name);
LIB_EXP int GoToActorPath(
        const char *entity_name, int i_unknown, double d_unknown
);
LIB_EXP int TurnOnActor(const char *entity_name);
LIB_EXP int TurnOffActor(const char *entity_name);
LIB_EXP int SetActorNodeStartTangent(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
);
LIB_EXP int SetActorNodeEndTangent(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
);
LIB_EXP int CameraAddTargetNode(
        const char *entity_name, float time, double x, double y, double z
);
LIB_EXP int CameraAddSourceNode(
        const char *entity_name, float time, double x, double y, double z
);
LIB_EXP int CameraSetStartTangentTargetNode(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
);
LIB_EXP int CameraSetStartTangentSourceNode(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
);
LIB_EXP int CameraSetEndTangentTargetNode(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
);
LIB_EXP int CameraSetEndTangentSourceNode(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
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
        const char *entity_name, int unknown1, int unknown2
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
LIB_EXP PyObject *GetGroupMembers(const char *entity_name);
LIB_EXP PyObject *GetCombatants(const char *entity_name);
LIB_EXP int EntityPutToWorld(const char *entity_name);
LIB_EXP void EntityRemoveFromWorld(const char *entity_name);
LIB_EXP void EntityRemoveFromWorldWithChilds(const char *entity_name);
LIB_EXP int UseEntity(const char *entity_name);
LIB_EXP int SetSound(const char *entity_name, const char *sound);
LIB_EXP int SetObjectSound(const char *entity_name, const char *sound);
LIB_EXP int PlayEntitySound(const char *entity_name, int i_unknown);
LIB_EXP int Stop(const char *entity_name);
LIB_EXP int StopAt(const char *entity_name, double x, double y, double z);
LIB_EXP int EntityCatchOnFire(
        const char *entity_name, double x, double y, double z
);
LIB_EXP const char *GetParticleEntity(const char *entity_name);
LIB_EXP int DoAction(const char *entity_name, const char *action_name);
LIB_EXP int DoActionWI(
        const char *entity_name, const char *action_name,
        int interpolation_type, double time, double unknown1
);
LIB_EXP int SetOnFloor(const char *entity_name);
LIB_EXP int RaiseEvent(const char *entity_name, const char *event_name);
LIB_EXP int InterruptCombat(const char *entity_name);
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
LIB_EXP int IsValidEntity(const char *entity_name);
LIB_EXP PyObject *GetEntityData(const char *entity_name);
LIB_EXP PyObject *GetAttackList(const char *entity_name);
LIB_EXP int ChangeEntityStatic(const char *entity_name, int is_static);
LIB_EXP int ChangeEntityActor(const char *entity_name, int is_actor);
LIB_EXP int ChangeEntityPerson(const char *entity_name, int is_person);
LIB_EXP int ChangeEntityWeapon(const char *entity_name, int is_weapon);
LIB_EXP int ChangeEntityArrow(const char *entity_name, int is_arrow);
LIB_EXP int SetEntityData(const char *entity_name, PyObject *data);
LIB_EXP int SetAttackList(const char *entity_name, PyObject *attack_list);
LIB_EXP int SetEntityInternalState(
        const char *entity_name, PyObject *internal_state
);
LIB_EXP int GetEntityInternalState(
        const char *entity_name, PyObject **internal_state
);
LIB_EXP int CarringObject(const char *inv_name, const char *obj_name);
LIB_EXP const char *GetRightBack(const char *inv_name);
LIB_EXP const char *GetLeftBack(const char *inv_name);
LIB_EXP int LinkRightHand(const char *inv_name, const char *obj_name);
LIB_EXP int LinkLeftHand(const char *inv_name, const char *obj_name);
LIB_EXP int LinkLeftHand2(const char *inv_name, const char *obj_name);
LIB_EXP int LinkRightBack(const char *inv_name, const char *obj_name);
LIB_EXP int LinkLeftBack(const char *inv_name, const char *obj_name);
LIB_EXP int LinkBack(const char *inv_name, const char *obj_name);
LIB_EXP int SetCurrentQuiver(const char *inv_name, const char *quiver_name);
LIB_EXP int AddObject(
        const char *inv_name, int obj_type, int unknown, const char *obj_name
);
LIB_EXP int RemoveObject(
        const char *inv_name, int obj_type, const char *obj_name
);
LIB_EXP const char *GetObject(const char *inv_name, int obj_type, int index);
LIB_EXP const char *GetObjectByName(
        const char *inv_name, int obj_type, const char *obj_name
);
LIB_EXP const char *GetSelectedObject(const char *inv_name, int obj_type);
LIB_EXP void Cycle(const char *inv_name, int obj_type);
LIB_EXP int IsSelected(const char *inv_name, int obj_type, int obj_index);
LIB_EXP int GetNumberObjectsAt(const char *inv_name, int obj_type, int index);
LIB_EXP int GetMaxNumberObjectsAt(
        const char *inv_name, int obj_type, int index
);
LIB_EXP const char *GetActiveShield(const char *inv_name);
LIB_EXP const char *GetActiveWeapon(const char *inv_name);
LIB_EXP const char *GetActiveQuiver(const char *inv_name);
LIB_EXP int AddWeapon(const char *inv_name, int flag, const char *weapon_name);
LIB_EXP int GetInventoryStringProperty(
	const char *name, int property_kind, const char **value
);
LIB_EXP int GetInventoryIntProperty(
        const char *name, int property_kind, int *value
);
LIB_EXP int SetInventoryIntProperty(
        const char *name, int property_kind, int value
);
LIB_EXP int SetListenerMode(int mode, double x, double y, double z);
LIB_EXP int GetListenerMode();
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
LIB_EXP int GetCharByName(const char *name, const char *short_name);
LIB_EXP int LoadAllAnimations(int charID);
LIB_EXP int ChangeAnimation(
        int charID, const char *old_anm_name, const char *new_anm_name
);
LIB_EXP int SetAnmDefaultPrefix(int charID, const char *prefix);
LIB_EXP int AddAttack(int charID, const char *attack_name, const char *anm_name);
LIB_EXP int AttackWindow(
        int charID, const char *anm_name, float window1, float window2,
        const char *window_name
);
LIB_EXP int AttackLevels(
        int charID, const char *anm_name, float level1, float level2
);
LIB_EXP int AttackEnergyLevel(
        int charID, const char *anm_name, float  level
);
LIB_EXP int AttackTypeFlag(int charID, const char *attack_name, int flag);
LIB_EXP int AllowAttack(
        int charID, const char *attack_name, const char *keys,
        const char *previous, const char *previous_negative,
        const char *window_name, const char *weapon_kind
);
LIB_EXP int MetaAttack(
        int charID, const char *meta_attack_name, const char *attack_name
);
LIB_EXP int AssignTrail(
        int charID, const char *attack_name, const char *unknown,
        const char *trail_name
);
LIB_EXP int SetNCDSpheres(int charID, int NCDSpheres);
LIB_EXP int SetCDSphere(int charID, int index, double h, double r);
LIB_EXP int GetCharIntProperty(int charID, int property_kind, int index, int *value);
LIB_EXP int SetCharIntProperty(int charID, int property_kind, int index, int value);
LIB_EXP int GetCharFloatProperty(int charID, int property_kind, int index, double *value);
LIB_EXP int SetCharFloatProperty(int charID, int property_kind, int index, double value);
LIB_EXP int GetCharStringProperty(int charID, int property_kind, int index, const char **value);
LIB_EXP int SetCharStringProperty(int charID, int property_kind, int index, const char *value);
LIB_EXP int SetCharFuncProperty(int charID, int property_kind, int index, PyObject *func);
LIB_EXP int GetTrailByName(const char *name);
LIB_EXP int GetTrailFloatProperty(
        int trailID, int property_kind, int index, double *value
);
LIB_EXP int SetTrailFloatProperty(
        int trailID, int property_kind, int index, double value
);
LIB_EXP int GetTrailVectorProperty(
        int trailID, int property_kind, int index,
        double *x, double *y, double *z
);
LIB_EXP int SetTrailVectorProperty(
        int trailID, int property_kind, int index, double x, double y, double z
);
LIB_EXP int CreateSound(const char *file_name, const char *sound_name);
LIB_EXP int CreateSoundS(int soundID);
LIB_EXP void DestroySound(int soundID);
LIB_EXP int GetSoundDevInstace(void);
LIB_EXP int GetGhostSectorSound(const char *gs_name);
LIB_EXP char *GetSoundStringProperty(int property_kind, int soundID);
LIB_EXP double GetSoundFloatProperty(int property_kind, int soundID);
LIB_EXP void SetSoundFloatProperty(int property_kind, int soundID, double value);
LIB_EXP void SetSoundIntProperty(int property_kind, int soundID, int value);
LIB_EXP int PlaySoundM(int soundID, double x, double y, double z, int i_unknown);
LIB_EXP int PlaySoundStereo(int soundID, int i_unknown);
LIB_EXP void SetSoundPitchVar(
        int soundID, int i_unknown, float f_unknown1, float f_unknown2,
        float f_unknown3, float f_unknown4
);
LIB_EXP int addSoundVar(int soundID, const char *alt_sound);
LIB_EXP int StopSound(int soundID);
LIB_EXP int CreateTimer(const char *timer_name, double period);
LIB_EXP int GetnTimers(void);
LIB_EXP int GetTimerInfo(
        int timer_index, const char **timer_name, double *period
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
LIB_EXP int nEntities(void);
LIB_EXP int nSectors(void);
LIB_EXP double GetTime(void);
LIB_EXP int SetTime(double time);
LIB_EXP int GoToTime(double time);
LIB_EXP void StopTime(void);
LIB_EXP void RestartTime(void);
LIB_EXP double GetTimeSpeed(void);
LIB_EXP void SetTimeSpeed(double speed);
LIB_EXP int GetNewExclusionGroupId(void);
LIB_EXP int AssocKey(
        const char *action, const char *input_device, const char *key,
        int press
);
LIB_EXP double GetTimeActionHeld(const char *Action);
LIB_EXP int AddInputAction(const char *action_name, int npi);
LIB_EXP int RemoveInputAction(const char *action_name);
LIB_EXP int Bind(const char *key, PyObject *proc);
LIB_EXP int BindPred(const char *action_name, const char *predproc);
LIB_EXP int Bind2(
        const char *act, const char *subact1,
        const char *subact2, int unknown
);
LIB_EXP int UnBind(const char *key, PyObject *proc);
LIB_EXP int UnBindPred(const char *action_name, const char *predproc);
LIB_EXP void UnBindAll(void);
LIB_EXP const char *Input(const char *text);
LIB_EXP void MarkLevelToLoad(const char *dir_name);
LIB_EXP void ReadLevel(const char *file_name);
LIB_EXP void CloseLevel(const char *statement1, const char *statement2);
LIB_EXP int OutSound(int soundId, double x, double y, double z, int unknown);
LIB_EXP int SetShowSounds(int showSounds);
LIB_EXP int nSounds(void);
LIB_EXP const char *GetSoundName(int soundId);
LIB_EXP const char *GetSoundFileName(int soundId);
LIB_EXP void ReadBitMap(const char *file_name, const char *internal_name);
LIB_EXP void ReadAlphaBitMap(const char *file_name, const char *internal_name);
LIB_EXP void SetSun(int exists, double x, double y, double z);
LIB_EXP int InsideAA(int AA, double x, double y, double z);
LIB_EXP void AnmAddEvent(const char *anm_name, const char *event_name, double event_frame);
LIB_EXP void AddAnmEvent(const char *anm_name, const char *event_name, double event_frame);
LIB_EXP void AnmDelEvent(const char *anm_name, const char *event_name);
LIB_EXP void AnmClearEvents(const char *anm_name);
LIB_EXP double AnmGetEventFrame(const char *anm_name, const char *event_name);
LIB_EXP int AddParticleGType(
        const char *new_type, const char *parent_type, int operation_type,
        int duration
);
LIB_EXP int SetParticleGVal(
        const char *type, int i, int r, int g, int b, int alpha, double size
);
LIB_EXP int GetnParticleGType(void);
LIB_EXP int GetParticleGType(
        int index, const char **type, const char **parent_type,
        int *operation_type, int *duration
);
LIB_EXP int GetParticleGVal(
        const char *type, int index, int *r, int *g, int *b, int *alpha,
        double *size
);
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
LIB_EXP int GetCombos(const char *person_name, combo_t **combos);
LIB_EXP int SetCombos(
        const char *person_name, int num_combos, char **combos_names,
        int *combos_executed
);
LIB_EXP int GetWeaponCombos(
        const char *person_name, const char *weapon_kind, combo_t **combos
);
LIB_EXP const char *GetLastPlayerCType(void);
LIB_EXP int GetEnemiesVisibleFrom(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***enemy_names
);
LIB_EXP int PlayCDTrack(int ntrack);
LIB_EXP int nCDTracks(void);
LIB_EXP int CDLenght(void);
LIB_EXP int CDTrackLenght(int ntrack);
LIB_EXP int CDPresent(void);
LIB_EXP int CDStop(void);
LIB_EXP int CDPause(void);
LIB_EXP int CDSetCallBack(PyObject *func);
LIB_EXP int SetDefaultMass(const char *entity_kind, double mass);
LIB_EXP int SetDefaultMaterial(const char *entity_kind, const char *material);
LIB_EXP material_t *GetMaterial(const char *name);
LIB_EXP material_t *GetMaterialI(int index);
LIB_EXP material_t *CreateMaterial(const char *name);
LIB_EXP int AddHitSoundComb(
        material_t *material1, material_t *material2, int soundID
);
LIB_EXP int GetMaterialFloatProperty(
        material_t *material, int property_kind, int index, double *value
);
LIB_EXP int SetMaterialFloatProperty(
        material_t *material, int property_kind, int index, double value
);
LIB_EXP int GetMaterialStringProperty(
        material_t *material, int property_kind, int index, const char **value
);
LIB_EXP int GetMaterialSoundProperty(
        material_t *material, int property_kind, int index, int *soundID
);
LIB_EXP int SetMaterialSoundProperty(
        material_t *material, int property_kind, int index, int soundID
);
LIB_EXP int nMaterials(void);
LIB_EXP int CreateGhostSector(
	const char *ghost_sector_name, const char *group_name,
	double floor_height, double roof_height, int num_points,
	point_2d_t *points
);
LIB_EXP int CreateTriggerSector(
	const char *trigger_sector_name, const char *group_name,
	double floor_height, double roof_height, int num_points,
	point_2d_t *points
);
LIB_EXP int SetTriggerSectorFunc(
        const char *trigger_sector_name, const char *func_type, PyObject *func
);
LIB_EXP PyObject *GetTriggerSectorFunc(
        const char *trigger_sector_name, const char *func_type
);
LIB_EXP int SetTriggerSectorData(
        const char *trigger_sector_name, PyObject *data
);
LIB_EXP PyObject *GetTriggerSectorData(const char *trigger_sector_name);
LIB_EXP int GetTriggerSectorFloorHeight(const char *trigger_sector_name);
LIB_EXP int GetTriggerSectorRoofHeight(const char *trigger_sector_name);
LIB_EXP const char *GetTriggerSectorGroup(const char *trigger_sector_name);
LIB_EXP double *GetTriggerSectorPoints(const char *trigger_sector_name);
LIB_EXP int nTriggerSectors(void);
LIB_EXP const char *GetTriggerSectorName(int index);
LIB_EXP const char *GenerateEntityName(void);
LIB_EXP int AddWatchAnim(const char *anim);
LIB_EXP int AddAnimFlags(
        const char *anim, int wuea, int mdf_y, int solf, int copy_rot,
        int bng_mov, int head_f
);
LIB_EXP int SetEAX(int eax_flag);
LIB_EXP int SetActionCameraMovement(
        const char *action_name, double angle, double start_pos, double end_pos
);
LIB_EXP int DeactivateInput(void);
LIB_EXP int ActivateInput(void);
LIB_EXP int SetGhostSectorSound(
        const char *aghost_name, const char *file_name, double volume,
        double base_volume, double min_dist, double max_dist, double v_max_dist,
        double scale
);
LIB_EXP int GetSound(const char *sound_name);
LIB_EXP int SetGhostSectorGroupSound(
        const char *group_name, const char *file_name, double volume,
        double base_volume, double min_dist, double max_dist, double unknown,
        double scale
);
LIB_EXP int SetRootWidget(long int widget);
LIB_EXP long int GetRootWidget(void);
LIB_EXP int AddCombustionDataFor(
        const char *object_kind, const char *fire_kind, double upper_treshol,
        double lower_treshold, double flame_height, double flame_size,
        double speed, double livetime
);
LIB_EXP int SetAfterFrameFunc(const char *name, PyObject *function);
LIB_EXP PyObject *GetAfterFrameFunc(const char *name);
LIB_EXP int GetnAfterFrameFuncs(void);
LIB_EXP const char *GetAfterFrameFuncName(int index);
LIB_EXP int RemoveAfterFrameFunc(const char *name);
LIB_EXP int SetMenuTgapFunc(PyObject *func);
LIB_EXP PyObject *GetMenuTgapFunc(void);
LIB_EXP int SetCallCheck(int check);
LIB_EXP int DrawBOD(
        const char *BODName, int x, int y, int w, int h, double scale,
        int i_unknown
);
LIB_EXP int SetShowAreas(int action_areas_bit_mask);
LIB_EXP int WriteText(double x, double y, const char *text);
LIB_EXP void GetTextWH(const char *text, double *w, double *h);
LIB_EXP void GetScreenRect(
        double *x_min, double *y_min, double *x_max, double *y_max
);
LIB_EXP void GetScreenXY(
        double map_x, double map_y, double map_z, double *screen_x,
        double *screen_y
);
LIB_EXP int CloseDebugChannel(const char *channel_name);
LIB_EXP int OpenDebugChannel(const char *channel_name);
LIB_EXP int SetAppMode(const char *mode);
LIB_EXP const char *GetAppMode(void);
LIB_EXP const char *GetCommandLine(void);
LIB_EXP int Quit(void);
LIB_EXP int LoadSampledAnimation(
        const char *file, const char *internal_name, int type,
        const char *s_unknown, int i_unknown
);
LIB_EXP int CreateFCAnimation(
        const char *file, const char *internal_name, int n_armonics
);
LIB_EXP int CreateDFCAnimation(
        const char *file1, const char *file2, const char *internal_name,
        int n_armonics
);
LIB_EXP int CreateBipedData(const char *biped_name, const char *kind);
LIB_EXP int AddBipedAction(
        const char *char_name, const char *action_name,
        const char *animation_name, double d_unknown1, double d_unknown2,
        int i_unknown
);
LIB_EXP int AddBipedActionC(
        const char *char_name, const char *action_name,
        const char *animation_name, const char *s_unknown, double d_unknown1,
        double d_unknown2, int i_unknown
);
LIB_EXP int RemoveBipedAction(const char *s_unknown1, const char *s_unknown2);
LIB_EXP int AddRStepEvent(const char *animation_name, double d_unknown);
LIB_EXP int RStepEvents(const char *s_unknown1, const char *s_unknown2);
LIB_EXP int LStepEvents(const char *s_unknown1, const char *s_unknown2);
LIB_EXP int SetActionEventTable(
        const char *race_name, const char *action_name, const char *table_name
);
LIB_EXP int SetEventTableFuncC(
        const char *s_unknown1, const char *s_unknown2, const char *s_unknown3
);
LIB_EXP int SetEventTableFunc(
        const char *event_table_name, const char *event_type, PyObject *func
);
LIB_EXP int AddLStepEvent(const char *animation_name, double d_unknown);
LIB_EXP int AddRReleaseEvent(const char *animation_name, double d_unknown);
LIB_EXP int AddLReleaseEvent(const char *animation_name, double d_unknown);
LIB_EXP void AddStopTests(const char *animation_name);
LIB_EXP void AddFloorCTolerance(const char *animation_name, double tolerance);
LIB_EXP int SetSolidMask(const char *kind, int mask);
LIB_EXP int SetDrawObjectShadows(int draw);
LIB_EXP int GetAutoEngageCombat(void);
LIB_EXP int SetAutoEngageCombat(int auto_engage_combat);
LIB_EXP double GetAecGap(void);
LIB_EXP int SetAecGap(double aec_gap);
LIB_EXP int GetDrawObjectShadows(void);
LIB_EXP int GetModelPos(const char *person, double *x, double *y, double *z);
LIB_EXP const char *GetCurrentMap(void);
LIB_EXP int SetCurrentMap(const char *map);
LIB_EXP int LoadWorld(const char *file_name);
LIB_EXP void DoneLoadGame(void);
LIB_EXP void BeginLoadGame(void);
LIB_EXP int GetWindowId(void);
LIB_EXP int GetProgramId(void);
LIB_EXP int AddStepSound(const char *name, int soundID);
LIB_EXP int AddMaterialStepSound(
        const char *table, const char *material, const char *step_sound
);
LIB_EXP int AddActionStepSound(
        const char *table, const char *action, const char *step_sound_table
);
LIB_EXP int AddTextureMaterial(const char *texture, const char *material);
LIB_EXP int GetMusicEventPriority(int unknown);
LIB_EXP int getMusicEvent(const char *event_name);
LIB_EXP int exeMusicEvent(int unknown1, int unknown2);
LIB_EXP int addMusicEventCD(
        const char *lpszEventName, int iTrack, double dFIn, double dFOut,
        float fVolume, float fPriority, int bBackGround, int iNext
);
LIB_EXP int addMusicEventMP3(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int unknown
);
LIB_EXP int addMusicEventWAV(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int opened
);
LIB_EXP int addMusicEventADPCM(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int unknown
);
LIB_EXP int dropDebugInfo(void);
LIB_EXP int loadSoundDataBase(const char *file_name);
LIB_EXP int saveSoundDataBase(const char *file_name);
LIB_EXP int loadMusicState(const char *file_name);
LIB_EXP int saveMusicState(const char *file_name);
LIB_EXP void TakeSnapShot(void);
LIB_EXP void saveSoundStats(const char *file_name);
LIB_EXP void GetMouseState(int *invert, double *xsens, double *ysens);
LIB_EXP void SetMouseState(int invert, double xsens, double ysens);
LIB_EXP double GetPSeconds(void);
LIB_EXP int GetnRaces(void);
LIB_EXP const char *GetRaceName(int index);
LIB_EXP void BodInspector(void);
LIB_EXP void SetRunString(const char *variable);
LIB_EXP int SetStringValue(const char *variable, const char *value);
LIB_EXP const char *GetStringValue(const char *variable);
LIB_EXP int DeleteStringValue(const char *variable);
LIB_EXP int SaveEntitiesData(const char *filename);
LIB_EXP int LoadEntitiesData(const char *filename);
LIB_EXP int SaveParticleSystemsData(const char *filename);
LIB_EXP int LoadParticleSystemsData(const char *filename);
LIB_EXP int SaveCombustionData(const char *file_name);
LIB_EXP int LoadCombustionData(const char *file_name);
LIB_EXP int ReassignCombustionData(void);
LIB_EXP int SaveAnmRaceData(const char *file_name, const char *race);
LIB_EXP int LoadAnmRaceData(const char *file_name);
LIB_EXP int SaveAnmSoundData(const char *file_name, const char *race);
LIB_EXP int LoadAnmSoundData(const char *file_name);
LIB_EXP PyObject *GetSaveInfo(void);
LIB_EXP int SetSaveInfo(PyObject *info);
LIB_EXP int OpenProfileSection(int section, const char *comment);
LIB_EXP int CloseProfileSection(int section);
LIB_EXP int StartProfile(void);
LIB_EXP int EnableProfiler(void);
LIB_EXP int DisableProfiler(void);
LIB_EXP int SaveProfileData(const char *file_name);
LIB_EXP int SetInputMode(const char *device, const char *mode);
LIB_EXP const char *GetInputMode(const char *device);
LIB_EXP void SaveScreeShoot(const char *filename, int width, int height);
LIB_EXP void CleanArea(double x, double y, double z, float distance);
LIB_EXP void NetServerChangeLevel(const char *level_name);
LIB_EXP void SetLocalOptions(
        const char *name, const char *kind, const char *weapon,
        const char *shield, const char *map
);
LIB_EXP void RestartNet(void);
LIB_EXP boolean JoinSession(int index, const char *player_name);
LIB_EXP boolean GetBrowseResult(int index, bld_server_info *info);
LIB_EXP boolean BrowseSessions(const char *ip_address);
LIB_EXP boolean StartServer(
        const char *game_name, const char *player_name, int max_players,
        boolean TCP
);
LIB_EXP const char *ServerInfoBlock(void);
LIB_EXP void CallNetEventSound(const char *entity_name, byte id);
LIB_EXP void ClientSetPyClientSoundFunc(PyObject *func);
LIB_EXP void ClientSetPyClientMutilaFunc(PyObject *func);
LIB_EXP void ClientSetPyClientDamageFunc(PyObject *func);
LIB_EXP void NetAddSoundToClient(
        const char *entity_name, const char *animation_name,
        PyObject *sound_object
);
LIB_EXP void ClearPools(void);
LIB_EXP const char *NetGetClientId(void);
LIB_EXP boolean NetSetObjectState(const char *entity_name, boolean state);
LIB_EXP void NetAddEventUserFunc(
        const char *action, PyObject *func, int ignore_host
);
LIB_EXP void NetAddPosition(double x, double y, double z);
LIB_EXP void NetSetPersonView(const char *entity_name);
LIB_EXP void GetLocalOptionsNet(
        const char **name, const char **kind, const char **weapon,
        const char **shield
);
LIB_EXP void GetNextPosition(double *x, double *y, double *z);
LIB_EXP void SendNetUserString(
        short kind, const char *str, int guaranteed, const char *str_unknown
);
LIB_EXP void ServerSetPyGetUserString(PyObject *func);
LIB_EXP void ServerSetPyByePlayerFunc(PyObject *func);
LIB_EXP void GetLifeAndLevel(const char *entity_name, int *energy, int *life);
LIB_EXP int GetNetState(void);
LIB_EXP void ServerSetPyCreatePlayerFunc(PyObject *func);
LIB_EXP boolean ClientStartMainChar(void);
LIB_EXP int ServerSetSendDataState(int state);
LIB_EXP float NetGetTime(void);
LIB_EXP int NetSetPPS(int PPS);
LIB_EXP int IsValidProtocol(int protocol);
LIB_EXP int GetDedicatedServerState(void);
LIB_EXP void SetDedicatedServerState(int dedicated);
LIB_EXP void PersonChangeAnmSoundIndex(const char *person_name, int index);
LIB_EXP void StartGSQR(void);
LIB_EXP int GetSplinePos(void *spline, float time, void *pos);
LIB_EXP int AddNodeSpline(
        void *spline, int num_node, double time, double pos_x, double pos_y,
        double pos_z, double tang_i_x, double tang_i_y, double tang_i_z,
        double tang_j_x, double tang_j_y, double tang_j_z
);
LIB_EXP int CloseSpline(void *spline);
LIB_EXP int ClearSpline(void *spline);

#ifdef __cplusplus
}
#endif


#endif /* BLADE_EXT_H */
