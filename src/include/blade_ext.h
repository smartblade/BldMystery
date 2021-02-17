
#ifndef BLADE_EXT_H

#define BLADE_EXT_H

#include <bld_python.h>
#include <Point2D.h>
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

class B_BitMap;
class material_t;
class B_Resource;
class B_Sound;
class B_Widget;


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


#define TRL_FLT_TIME_2_LIVE               0
#define TRL_FLT_TRANSPARENCY              1
#define TRL_FLT_SHRINK_FACTOR             2

#define TRL_VEC_COLOR                     0


#ifdef __cplusplus
extern "C" {
#endif

LIB_EXP int WorldToMBW(const char *world);
LIB_EXP int SetAutoGenTexture(const char *textureName, int textureEffect);
LIB_EXP int SetBloodLevel(int blood_level);
LIB_EXP int GetBloodLevel(void);
LIB_EXP int SetMutilationLevel(int mutilation_level);
LIB_EXP int GetMutilationLevel(void);
LIB_EXP const char *GetWorldFileName(void);
LIB_EXP int SetAnimationFactor(const char *mov, double new_speed_factor);
LIB_EXP int SetTurnSpeed(const char *race_name, double new_speed);
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
LIB_EXP int nSectors(void);
LIB_EXP double GetTime(void);
LIB_EXP int SetTime(double time);
LIB_EXP int GoToTime(double time);
LIB_EXP void StopTime(void);
LIB_EXP void RestartTime(void);
LIB_EXP double GetTimeSpeed(void);
LIB_EXP void SetTimeSpeed(double speed);
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
LIB_EXP int UnBindPred(const char *key, const char *pred);
LIB_EXP void UnBindAll(void);
LIB_EXP const char *Input(const char *text);
LIB_EXP int MarkLevelToLoad(const char *filename);
LIB_EXP int ReadLevel(const char *filename);
LIB_EXP void CloseLevel(const char *statement, const char *newMap);
LIB_EXP int StartRecordingDemo(void);
LIB_EXP int EndRecordingDemo(const char *name);
LIB_EXP int PlayDemo(const char *name);
LIB_EXP int OutSound(int soundId, double x, double y, double z, int unknown);
LIB_EXP unsigned int ReadBitMap(const char *filename, const char *internalname);
LIB_EXP unsigned int ReadAlphaBitMap(const char *filename, const char *internalname);
LIB_EXP void SetSun(int exists, double x, double y, double z);
LIB_EXP int InsideAA(int AA, double x, double y, double z);
LIB_EXP void AnmAddEvent(const char *anm_name, const char *event_name, double event_frame);
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
LIB_EXP const char *GetLastPlayerCType(void);
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
    material_t *material1, material_t *material2, B_Sound *sound
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
        material_t *material, int property_kind, int index, B_Sound **sound
);
LIB_EXP int SetMaterialSoundProperty(
    material_t *material, int property_kind, int index, B_Sound *sound
);
LIB_EXP int nMaterials(void);
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
LIB_EXP int SetActionCameraMovement(
        const char *action_name, double angle, double start_pos, double end_pos
);
LIB_EXP int DeactivateInput(void);
LIB_EXP int ActivateInput(void);
LIB_EXP int SetRootWidget(B_Widget *widget);
LIB_EXP B_Widget *GetRootWidget(void);
LIB_EXP int AddCombustionDataFor(
        const char *object_kind, const char *fire_kind, double upper_treshol,
        double lower_treshold, double flame_height, double flame_size,
        double speed, double livetime
);
LIB_EXP void RM_FreeResource(B_Resource *resource);
LIB_EXP B_BitMap *RM_GetResource(const char *name);
LIB_EXP void UpdateAGTexture(long bmp_handle);
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
LIB_EXP int GetTextWH(const char *text, double *w, double *h);
LIB_EXP int GetScreenRect(
        double *x_min, double *y_min, double *x_max, double *y_max
);
LIB_EXP int GetScreenXY(
        double map_x, double map_y, double map_z, double *screen_x,
        double *screen_y
);
LIB_EXP int CloseDebugChannel(const char *channel_name);
LIB_EXP int OpenDebugChannel(const char *channel_name);
LIB_EXP int SetAppMode(const char *mode);
LIB_EXP const char *GetAppMode(void);
LIB_EXP const char *GetCommandLine(void);
LIB_EXP int Quit(void);
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
LIB_EXP size_t GetWindowId(void);
LIB_EXP size_t GetProgramId(void);
LIB_EXP int AddStepSound(const char *name, B_Sound *sound);
LIB_EXP int AddMaterialStepSound(
        const char *table, const char *material, const char *step_sound
);
LIB_EXP int AddActionStepSound(
        const char *table, const char *action, const char *step_sound_table
);
LIB_EXP int AddTextureMaterial(const char *texture, const char *material);
LIB_EXP int TakeSnapShot(void);
LIB_EXP int GetnRaces(void);
LIB_EXP const char *GetRaceName(int index);
LIB_EXP void SetRunString(const char *str);
LIB_EXP int SetStringValue(const char *variable, const char *value);
LIB_EXP const char *GetStringValue(const char *variable);
LIB_EXP int DeleteStringValue(const char *variable);
LIB_EXP int SaveEntitiesData(const char *filename);
LIB_EXP int LoadEntitiesData(const char *filename);
LIB_EXP int SaveParticleSystemsData(const char *filename);
LIB_EXP int LoadParticleSystemsData(const char *filename);
LIB_EXP int SaveCombustionData(const char *file_name);
LIB_EXP int LoadCombustionData(const char *file_name);
LIB_EXP void ReassignCombustionData(void);
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
LIB_EXP void LoopGSQR();
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
LIB_EXP void SetGameSpySupport(boolean enabled);
LIB_EXP void StartGSQR(void);

#ifdef __cplusplus
}
#endif


#endif /* BLADE_EXT_H */
