//---------------------------------------------------------------------------

#include "bladex_int.h"


#define PROP_TYPE_OBJ                           0
#define PROP_TYPE_INT                           1
#define PROP_TYPE_FLT                           2
#define PROP_TYPE_STR                           3
#define PROP_TYPE_VEC                           4

#define PROP_ONLY_GET                           1
#define PROP_ONLY_SET                           2
#define PROP_GET_AND_SET                        3


typedef struct {
        PyObject_HEAD
        char *name;
} bld_py_entity_t;

typedef struct {
        PyObject_HEAD
        char *name;
} bld_py_inventory_t;

typedef struct {
        PyObject_HEAD
        material_t *material;
} bld_py_material_t;

typedef struct {
        PyObject_HEAD
        void *unknown;
} bld_py_route_t;

typedef struct {
        PyObject_HEAD
        int sectorID;
} bld_py_sector_t;

typedef struct {
        PyObject_HEAD
        int soundID;
        int soundDev;
} bld_py_sound_t;

//TODO remove
#define NOT_IMPLEMENTED_FUNC(msg, ret) {\
        char buffer[512];\
        sprintf(buffer, "print \"%s not implemented\"", msg);\
        PyRun_SimpleString("print \"*********************************\"");\
        PyRun_SimpleString("print \"*********************************\"");\
        PyRun_SimpleString("print \"*********************************\"");\
        PyRun_SimpleString("print \"*************ERROR***************\"");\
        PyRun_SimpleString(buffer);\
        PyRun_SimpleString("print \"*********************************\"");\
        PyRun_SimpleString("print \"*********************************\"");\
        PyRun_SimpleString("print \"*********************************\"");\
        return ret;\
}
//TODO remove
#define NOT_IMPLEMENTED_ATTR(func_name, attr_name) {\
        char buffer[512];\
        sprintf(buffer, "print \"%s: %s not implemented\"", func_name, attr_name);\
        PyRun_SimpleString("print \"*********************************\"");\
        PyRun_SimpleString("print \"*********************************\"");\
        PyRun_SimpleString("print \"*********************************\"");\
        PyRun_SimpleString("print \"*************ERROR***************\"");\
        PyRun_SimpleString(buffer);\
        PyRun_SimpleString("print \"*********************************\"");\
        PyRun_SimpleString("print \"*********************************\"");\
        PyRun_SimpleString("print \"*********************************\"");\
}

static PyObject* bex_nEntities(PyObject* self, PyObject* args);
static PyObject* bex_GetTime(PyObject* self, PyObject* args);
static PyObject* bex_SetTime(PyObject* self, PyObject* args);
static PyObject* bex_GoToTime(PyObject* self, PyObject* args);
static PyObject* bex_StopTime(PyObject* self, PyObject* args);
static PyObject* bex_RestartTime(PyObject* self, PyObject* args);
static PyObject* bex_SetTimeSpeed(PyObject* self, PyObject* args);
static PyObject* bex_GetTimeSpeed(PyObject* self, PyObject* args);
static PyObject* bex_GetNewExclusionGroupId(PyObject* self, PyObject* args);
static PyObject* bex_AddScheduledFunc(PyObject* self, PyObject* args);
static PyObject* bex_RemoveScheduledFunc(PyObject* self, PyObject* args);
static PyObject* bex_GetnScheduledFuncs(PyObject* self, PyObject* args);
static PyObject* bex_GetScheduledFunc(PyObject* self, PyObject* args);
static PyObject* bex_SetListenerPosition(PyObject* self, PyObject* args);
static PyObject* bex_CreateSpark(PyObject* self, PyObject* args);
static PyObject* bex_CreateSound(PyObject* self, PyObject* args);
static PyObject* bex_CreateRoute(PyObject* self, PyObject* args);
static PyObject* bex_CreateTimer(PyObject* self, PyObject* args);
static PyObject* bex_GetnTimers(PyObject* self, PyObject* args);
static PyObject* bex_GetTimerInfo(PyObject* self, PyObject* args);
static PyObject* bex_GetTimeActionHeld(PyObject* self, PyObject* args);
static PyObject* bex_AddInputAction(PyObject* self, PyObject* args);
static PyObject* bex_RemoveInputAction(PyObject* self, PyObject* args);
static PyObject* bex_AddBoundFunc(PyObject* self, PyObject* args);
static PyObject* bex_Bind2(PyObject* self, PyObject* args);
static PyObject* bex_AssocKey(PyObject* self, PyObject* args);
static PyObject* bex_RemoveBoundFunc(PyObject* self, PyObject* args);
static PyObject* bex_UnBindAll(PyObject* self, PyObject* args);
static PyObject* bex_Input(PyObject* self, PyObject* args);
static PyObject* bex_LoadLevel(PyObject* self, PyObject* args);
static PyObject* bex_ReadLevel(PyObject* self, PyObject* args);
static PyObject* bex_CloseLevel(PyObject* self, PyObject* args);
static PyObject* bex_PlaySound(PyObject* self, PyObject* args);
static PyObject* bex_ShowSounds(PyObject* self, PyObject* args);
static PyObject* bex_nSounds(PyObject* self, PyObject* args);
static PyObject* bex_ReadBitMap(PyObject* self, PyObject* args);
static PyObject* bex_ReadAlphaBitMap(PyObject* self, PyObject* args);
static PyObject* bex_SetSoundVolume(PyObject* self, PyObject* args);
static PyObject* bex_GetSoundVolume(PyObject* self, PyObject* args);
static PyObject* bex_SetBloodLevel(PyObject* self, PyObject* args);
static PyObject* bex_GetBloodLevel(PyObject* self, PyObject* args);
static PyObject* bex_SetMutilationLevel(PyObject* self, PyObject* args);
static PyObject* bex_GetMutilationLevel(PyObject* self, PyObject* args);
static PyObject* bex_CreateEntity(PyObject* self, PyObject* args);
static PyObject* bex_DeleteEntity(PyObject* self, PyObject* args);
static PyObject* bex_SoundSystemActive(PyObject* self, PyObject* args);
static PyObject* bex_SetSSFrecuency(PyObject* self, PyObject* args);
static PyObject* bex_SetSS2dChannels(PyObject* self, PyObject* args);
static PyObject* bex_SetSS3dChannels(PyObject* self, PyObject* args);
static PyObject* bex_SetSSFilter(PyObject* self, PyObject* args);
static PyObject* bex_KillMusic(PyObject* self, PyObject* args);
static PyObject* bex_ResumeSoundSystem(PyObject* self, PyObject* args);
static PyObject* bex_PauseSoundSystem(PyObject* self, PyObject* args);
static PyObject* bex_PauseSoundSystemButMusic(PyObject* self, PyObject* args);
static PyObject* bex_ShutDownSoundChannels(PyObject* self, PyObject* args);
static PyObject* bex_SetMusicVolume(PyObject* self, PyObject* args);
static PyObject* bex_GetMusicVolume(PyObject* self, PyObject* args);
static PyObject* bex_SetSSQuality(PyObject* self, PyObject* args);
static PyObject* bex_GetSSQuality(PyObject* self, PyObject* args);
static PyObject* bex_SetSpeakerConfig(PyObject* self, PyObject* args);
static PyObject* bex_GetSpeakerConfig(PyObject* self, PyObject* args);
static PyObject* bex_SetEAXOverride(PyObject* self, PyObject* args);
static PyObject* bex_GetEAXOverride(PyObject* self, PyObject* args);
static PyObject* bex_SaveSSConfig(PyObject* self, PyObject* args);
static PyObject* bex_SetAutoGenTexture(PyObject* self, PyObject* args);
static PyObject* bex_AddTranTime(PyObject* self, PyObject* args);
static PyObject* bex_CheckAnims(PyObject* self, PyObject* args);
static PyObject* bex_GiveAnims(PyObject* self, PyObject* args);
static PyObject* bex_GetAnimationDuration(PyObject* self, PyObject* args);
static PyObject* bex_SetAnimationFactor(PyObject* self, PyObject* args);
static PyObject* bex_SetTurnSpeed(PyObject* self, PyObject* args);
static PyObject* bex_GetEntity(PyObject* self, PyObject* args);
static PyObject* bex_GetEntitiesAt(PyObject* self, PyObject* args);
static PyObject* bex_GetEntitiesVisibleFrom(PyObject* self, PyObject* args);
static PyObject* bex_GetObjectEntitiesVisibleFrom(PyObject* self, PyObject* args);
static PyObject* bex_GetEnemiesVisibleFrom(PyObject* self, PyObject* args);
static PyObject* bex_GetCombos(PyObject* self, PyObject* args);
static PyObject* bex_SetCombos(PyObject* self, PyObject* args);
static PyObject* bex_GetWeaponCombos(PyObject* self, PyObject* args);
static PyObject* bex_GetLastPlayerCType(PyObject* self, PyObject* args);
static PyObject* bex_nSectors(PyObject* self, PyObject* args);
static PyObject* bex_GetSector(PyObject* self, PyObject* args);
static PyObject* bex_GetCharType(PyObject* self, PyObject* args);
static PyObject* bex_GetTrailType(PyObject* self, PyObject* args);
static PyObject* bex_SetDefaultMass(PyObject* self, PyObject* args);
static PyObject* bex_SetDefaultMaterial(PyObject* self, PyObject* args);
static PyObject* bex_CreateMaterial(PyObject* self, PyObject* args);
static PyObject* bex_GetMaterial(PyObject* self, PyObject* args);
static PyObject* bex_nMaterials(PyObject* self, PyObject* args);
static PyObject* bex_GenerateEntityName(PyObject* self, PyObject* args);
static PyObject* bex_AddWatchAnim(PyObject* self, PyObject* args);
static PyObject* bex_AddAnimFlags(PyObject* self, PyObject* args);
static PyObject* bex_SetEAX(PyObject* self, PyObject* args);
static PyObject* bex_GetSound(PyObject* self, PyObject* args);
static PyObject* bex_SetActionCameraMovement(PyObject* self, PyObject* args);
static PyObject* bex_DeactivateInput(PyObject* self, PyObject* args);
static PyObject* bex_ActivateInput(PyObject* self, PyObject* args);
static PyObject* bex_AddGhostSector(PyObject* self, PyObject* args);
static PyObject* bex_SetGhostSectorSound(PyObject* self, PyObject* args);
static PyObject* bex_SetGhostSectorGroupSound(PyObject* self, PyObject* args);
static PyObject* bex_AddTriggerSector(PyObject* self, PyObject* args);
static PyObject* bex_SetTriggerSectorFunc(PyObject* self, PyObject* args);
static PyObject* bex_GetTriggerSectorFunc(PyObject* self, PyObject* args);
static PyObject* bex_RemoveTriggerSectorFunc(PyObject* self, PyObject* args);
static PyObject* bex_SetTriggerSectorData(PyObject* self, PyObject* args);
static PyObject* bex_GetTriggerSectorData(PyObject* self, PyObject* args);
static PyObject* bex_GetTriggerSectorFloorHeight(PyObject* self, PyObject* args);
static PyObject* bex_GetTriggerSectorRoofHeight(PyObject* self, PyObject* args);
static PyObject* bex_GetTriggerSectorGroup(PyObject* self, PyObject* args);
static PyObject* bex_GetTriggerSectorPoints(PyObject* self, PyObject* args);
static PyObject* bex_nTriggerSectors(PyObject* self, PyObject* args);
static PyObject* bex_GetTriggerSectorName(PyObject* self, PyObject* args);
static PyObject* bex_CDPlayTrack(PyObject* self, PyObject* args);
static PyObject* bex_CDnTracks(PyObject* self, PyObject* args);
static PyObject* bex_CDLenght(PyObject* self, PyObject* args);
static PyObject* bex_CDTrackLenght(PyObject* self, PyObject* args);
static PyObject* bex_CDPresent(PyObject* self, PyObject* args);
static PyObject* bex_CDStop(PyObject* self, PyObject* args);
static PyObject* bex_CDPause(PyObject* self, PyObject* args);
static PyObject* bex_CDCallBack(PyObject* self, PyObject* args);
static PyObject* bex_SetSun(PyObject* self, PyObject* args);
static PyObject* bex_InsideActionArea(PyObject* self, PyObject* args);
static PyObject* bex_AnmAddEvent(PyObject* self, PyObject* args);
static PyObject* bex_AddAnmEvent(PyObject* self, PyObject* args);
static PyObject* bex_AnmDelEvent(PyObject* self, PyObject* args);
static PyObject* bex_AnmClearEvents(PyObject* self, PyObject* args);
static PyObject* bex_AnmGetEventFrame(PyObject* self, PyObject* args);
static PyObject* bex_AddParticleGType(PyObject* self, PyObject* args);
static PyObject* bex_SetParticleGVal(PyObject* self, PyObject* args);
static PyObject* bex_GetnParticleGType(PyObject* self, PyObject* args);
static PyObject* bex_GetParticleGType(PyObject* self, PyObject* args);
static PyObject* bex_GetParticleGVal(PyObject* self, PyObject* args);
static PyObject* bex_AddCombustionDataFor(PyObject* self, PyObject* args);
static PyObject* bex_SetRootWidget(PyObject* self, PyObject* args);
static PyObject* bex_GetRootWidget(PyObject* self, PyObject* args);
static PyObject* bex_SetCallCheck(PyObject* self, PyObject* args);
static PyObject* bex_DrawBOD(PyObject* self, PyObject* args);
static PyObject* bex_SetAfterFrameFunc(PyObject* self, PyObject* args);
static PyObject* bex_GetAfterFrameFunc(PyObject* self, PyObject* args);
static PyObject* bex_GetAfterFrameFuncName(PyObject* self, PyObject* args);
static PyObject* bex_GetnAfterFrameFuncs(PyObject* self, PyObject* args);
static PyObject* bex_RemoveAfterFrameFunc(PyObject* self, PyObject* args);
static PyObject* bex_SetMenuTgapFunc(PyObject* self, PyObject* args);
static PyObject* bex_GetMenuTgapFunc(PyObject* self, PyObject* args);
static PyObject* bex_WriteText(PyObject* self, PyObject* args);
static PyObject* bex_GetTextWH(PyObject* self, PyObject* args);
static PyObject* bex_GetScreenRect(PyObject* self, PyObject* args);
static PyObject* bex_GetScreenXY(PyObject* self, PyObject* args);
static PyObject* bex_ShowActionAreas(PyObject* self, PyObject* args);
static PyObject* bex_ExportWorld(PyObject* self, PyObject* args);
static PyObject* bex_CheckPyErrors(PyObject* self, PyObject* args);
static PyObject* bex_SetAppMode(PyObject* self, PyObject* args);
static PyObject* bex_GetAppMode(PyObject* self, PyObject* args);
static PyObject* bex_Quit(PyObject* self, PyObject* args);
static PyObject* bex_OpenDebugChannel(PyObject* self, PyObject* args);
static PyObject* bex_CloseDebugChannel(PyObject* self, PyObject* args);
static PyObject* bex_LoadSampledAnimation(PyObject* self, PyObject* args);
static PyObject* bex_CreateFCAnimation(PyObject* self, PyObject* args);
static PyObject* bex_CreateDFCAnimation(PyObject* self, PyObject* args);
static PyObject* bex_GetAnmRaces(PyObject* self, PyObject* args);
static PyObject* bex_CreateBipedData(PyObject* self, PyObject* args);
static PyObject* bex_AddBipedAction(PyObject* self, PyObject* args);
static PyObject* bex_RemoveBipedAction(PyObject* self, PyObject* args);
static PyObject* bex_GetWorldFileName(PyObject* self, PyObject* args);
static PyObject* bex_LoadWorld(PyObject* self, PyObject* args);
static PyObject* bex_DoneLoadGame(PyObject* self, PyObject* args);
static PyObject* bex_BeginLoadGame(PyObject* self, PyObject* args);
static PyObject* bex_SetSaveInfo(PyObject* self, PyObject* args);
static PyObject* bex_GetSaveInfo(PyObject* self, PyObject* args);
static PyObject* bex_LoadEntitiesData(PyObject* self, PyObject* args);
static PyObject* bex_SaveEntitiesData(PyObject* self, PyObject* args);
static PyObject* bex_LoadParticleSystemsData(PyObject* self, PyObject* args);
static PyObject* bex_SaveParticleSystemsData(PyObject* self, PyObject* args);
static PyObject* bex_LoadAnmRaceData(PyObject* self, PyObject* args);
static PyObject* bex_SaveAnmRaceData(PyObject* self, PyObject* args);
static PyObject* bex_LoadAnmSoundData(PyObject* self, PyObject* args);
static PyObject* bex_SaveAnmSoundData(PyObject* self, PyObject* args);
static PyObject* bex_SaveProfileData(PyObject* self, PyObject* args);
static PyObject* bex_OpenProfileSection(PyObject* self, PyObject* args);
static PyObject* bex_CloseProfileSection(PyObject* self, PyObject* args);
static PyObject* bex_StartProfile(PyObject* self, PyObject* args);
static PyObject* bex_EnableProfiler(PyObject* self, PyObject* args);
static PyObject* bex_DisableProfiler(PyObject* self, PyObject* args);
static PyObject* bex_ReassignCombustionData(PyObject* self, PyObject* args);
static PyObject* bex_LoadCombustionData(PyObject* self, PyObject* args);
static PyObject* bex_SaveCombustionData(PyObject* self, PyObject* args);
static PyObject* bex_SetDrawObjectShadows(PyObject* self, PyObject* args);
static PyObject* bex_GetDrawObjectShadows(PyObject* self, PyObject* args);
static PyObject* bex_SetAutoEngageCombat(PyObject* self, PyObject* args);
static PyObject* bex_GetAutoEngageCombat(PyObject* self, PyObject* args);
static PyObject* bex_SetAecGap(PyObject* self, PyObject* args);
static PyObject* bex_GetAecGap(PyObject* self, PyObject* args);
static PyObject* bex_SetActionEventTable(PyObject* self, PyObject* args);
static PyObject* bex_SetEventTableFuncC(PyObject* self, PyObject* args);
static PyObject* bex_SetEventTableFunc(PyObject* self, PyObject* args);
static PyObject* bex_SetSolidMask(PyObject* self, PyObject* args);
static PyObject* bex_AddAnmRStep(PyObject* self, PyObject* args);
static PyObject* bex_AddAnmLStep(PyObject* self, PyObject* args);
static PyObject* bex_AnmTypeRSteps(PyObject* self, PyObject* args);
static PyObject* bex_AnmTypeLSteps(PyObject* self, PyObject* args);
static PyObject* bex_AddAnmRRelease(PyObject* self, PyObject* args);
static PyObject* bex_AddAnmLRelease(PyObject* self, PyObject* args);
static PyObject* bex_AddStopTests(PyObject* self, PyObject* args);
static PyObject* bex_AddFloorCTolerance(PyObject* self, PyObject* args);
static PyObject* bex_GetModelPos(PyObject* self, PyObject* args);
static PyObject* bex_GetGhostSectorSound(PyObject* self, PyObject* args);
static PyObject* bex_GetSoundName(PyObject* self, PyObject* args);
static PyObject* bex_GetSoundFileName(PyObject* self, PyObject* args);
static PyObject* bex_GetCurrentMap(PyObject* self, PyObject* args);
static PyObject* bex_SetCurrentMap(PyObject* self, PyObject* args);
static PyObject* bex_GetCommandLine(PyObject* self, PyObject* args);
static PyObject* bex_GetProgramId(PyObject* self, PyObject* args);
static PyObject* bex_GetWindowId(PyObject* self, PyObject* args);
static PyObject* bex_AddStepSound(PyObject* self, PyObject* args);
static PyObject* bex_AddMaterialStepSound(PyObject* self, PyObject* args);
static PyObject* bex_AddTextureMaterial(PyObject* self, PyObject* args);
static PyObject* bex_AddActionStepSound(PyObject* self, PyObject* args);
static PyObject* bex_GetGhostSectorSound(PyObject* self, PyObject* args);
static PyObject* bex_GetSoundName(PyObject* self, PyObject* args);
static PyObject* bex_GetSoundFileName(PyObject* self, PyObject* args);
static PyObject* bex_GetSoundName(PyObject* self, PyObject* args);
static PyObject* bex_GetSoundFileName(PyObject* self, PyObject* args);
static PyObject* bex_GetMusicEventPriority(PyObject* self, PyObject* args);
static PyObject* bex_GetMusicEvent(PyObject* self, PyObject* args);
static PyObject* bex_ExeMusicEvent(PyObject* self, PyObject* args);
static PyObject* bex_AddMusicEventCD(PyObject* self, PyObject* args);
static PyObject* bex_AddMusicEventMP3(PyObject* self, PyObject* args);
static PyObject* bex_AddMusicEventWAV(PyObject* self, PyObject* args);
static PyObject* bex_AddMusicEventADPCM(PyObject* self, PyObject* args);
static PyObject* bex_YSSInfo(PyObject* self, PyObject* args);
static PyObject* bex_LoadSoundDataBase(PyObject* self, PyObject* args);
static PyObject* bex_SaveSoundDataBase(PyObject* self, PyObject* args);
static PyObject* bex_LoadMusicState(PyObject* self, PyObject* args);
static PyObject* bex_SaveMusicState(PyObject* self, PyObject* args);
static PyObject* bex_SaveStats(PyObject* self, PyObject* args);
static PyObject* bex_TakeSnapShot(PyObject* self, PyObject* args);
static PyObject* bex_GetMouseState(PyObject* self, PyObject* args);
static PyObject* bex_SetMouseState(PyObject* self, PyObject* args);
static PyObject* bex_GetPTime(PyObject* self, PyObject* args);
static PyObject* bex_BodInspector(PyObject* self, PyObject* args);
static PyObject* bex_SetRunString(PyObject* self, PyObject* args);
static PyObject* bex_SetStringValue(PyObject* self, PyObject* args);
static PyObject* bex_GetStringValue(PyObject* self, PyObject* args);
static PyObject* bex_DeleteStringValue(PyObject* self, PyObject* args);
static PyObject* bex_PerformHeapCheck(PyObject* self, PyObject* args);
static PyObject* bex_HeapCheckSetMark(PyObject* self, PyObject* args);
static PyObject* bex_HeapCheckAllAllocations(PyObject* self, PyObject* args);
static PyObject* bex_HeapCheckDelayFree(PyObject* self, PyObject* args);
static PyObject* bex_HeapCheckSystemMemory(PyObject* self, PyObject* args);
static PyObject* bex_HeapCheckLeaks(PyObject* self, PyObject* args);
static PyObject* bex_DumpMemoryLeaks(PyObject* self, PyObject* args);
static PyObject* bex_SetInputMode(PyObject* self, PyObject* args);
static PyObject* bex_GetInputMode(PyObject* self, PyObject* args);
static PyObject* bex_SaveScreenShot(PyObject* self, PyObject* args);
static PyObject* bex_CleanArea(PyObject* self, PyObject* args);

static PyObject *get_entity_by_name(const char *name);
static PyObject *get_entity_by_index(int index);
static PyObject *create_entity(
        const char *name, const char *kind, double x, double y, double z,
        const char *parent_class, const char *unknown
);
static PyObject *create_entity_decal(
        const char *name, double x, double y, double z, int i_unknown,
        double d_unknown1, double d_unknown2
);
static PyObject *create_spark(
        const char *name, double x, double y, double z, double x_spark_dir,
        double y_spark_dir, double z_spark_dir, double d_unknown1,
        double d_unknown2, double d_unknown3, double d_unknown4,
        double d_unknown5, int i_unknown6, int i_unknown7, int i_unknown8,
        int i_unknown9, int i_unknown10, int i_unknown11, double d_unknown12,
        double d_unknown13, double d_unknown14, int i_unknown15
);
static PyObject* bex_ent_GetParticleEntity(PyObject* self, PyObject* args);
static PyObject* bex_ent_SeverLimb(PyObject* self, PyObject* args);
static PyObject* bex_ent_ResetWounds(PyObject* self, PyObject* args);
static PyObject* bex_ent_Impulse(PyObject* self, PyObject* args);
static PyObject* bex_ent_ImpulseC(PyObject* self, PyObject* args);
static PyObject* bex_ent_Fly(PyObject* self, PyObject* args);
static PyObject* bex_ent_SubscribeToList(PyObject* self, PyObject* args);
static PyObject* bex_ent_RemoveFromList(PyObject* self, PyObject* args);
static PyObject* bex_ent_RemoveFromInvent(PyObject* self, PyObject* args);
static PyObject* bex_ent_RemoveFromInventRight(PyObject* self, PyObject* args);
static PyObject* bex_ent_RemoveFromInventLeft(PyObject* self, PyObject* args);
static PyObject* bex_ent_RemoveFromInventLeft2(PyObject* self, PyObject* args);
static PyObject* bex_ent_RemoveFromWorld(PyObject* self, PyObject* args);
static PyObject* bex_ent_RemoveFromWorldWithChilds(PyObject* self, PyObject* args);
static PyObject* bex_ent_LaunchAnimation(PyObject* self, PyObject* args);
static PyObject* bex_ent_LaunchAnimation2(PyObject* self, PyObject* args);
static PyObject* bex_ent_LaunchAnmType(PyObject* self, PyObject* args);
static PyObject* bex_ent_GotAnmType(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetMesh(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetAnmFlags(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetTmpAnmFlags(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetActiveEnemy(PyObject* self, PyObject* args);
static PyObject* bex_ent_CanISee(PyObject* self, PyObject* args);
static PyObject* bex_ent_CanISeeFrom(PyObject* self, PyObject* args);
static PyObject* bex_ent_InsideActionArea(PyObject* self, PyObject* args);
static PyObject* bex_ent_CheckAnimCol(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetEnemy(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetEnemyName(PyObject* self, PyObject* args);
static PyObject* bex_ent_Chase(PyObject* self, PyObject* args);
static PyObject* bex_ent_ResetChase(PyObject* self, PyObject* args);
static PyObject* bex_ent_GoTo(PyObject* self, PyObject* args);
static PyObject* bex_ent_CanGoTo(PyObject* self, PyObject* args);
static PyObject* bex_ent_QuickFace(PyObject* self, PyObject* args);
static PyObject* bex_ent_Face(PyObject* self, PyObject* args);
static PyObject* bex_ent_LookAtEntity(PyObject* self, PyObject* args);
static PyObject* bex_ent_StartLooking(PyObject* self, PyObject* args);
static PyObject* bex_ent_StopLooking(PyObject* self, PyObject* args);
static PyObject* bex_ent_AddWatchAnim(PyObject* self, PyObject* args);
static PyObject* bex_ent_GraspPos(PyObject* self, PyObject* args);
static PyObject* bex_ent_Freeze(PyObject* self, PyObject* args);
static PyObject* bex_ent_UnFreeze(PyObject* self, PyObject* args);
static PyObject* bex_ent_SwitchTo1H(PyObject* self, PyObject* args);
static PyObject* bex_ent_SwitchToBow(PyObject* self, PyObject* args);
static PyObject* bex_ent_LaunchBayRoute(PyObject* self, PyObject* args);
static PyObject* bex_ent_LaunchWatch(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetActionMode(PyObject* self, PyObject* args);
static PyObject* bex_ent_StartGrabbing(PyObject* self, PyObject* args);
static PyObject* bex_ent_StopGrabbing(PyObject* self, PyObject* args);
static PyObject* bex_ent_LookAt(PyObject* self, PyObject* args);
static PyObject* bex_ent_LookAtPerson(PyObject* self, PyObject* args);
static PyObject* bex_ent_AddAnmEventFunc(PyObject* self, PyObject* args);
static PyObject* bex_ent_DelAnmEventFunc(PyObject* self, PyObject* args);
static PyObject* bex_ent_ClearAnmEventFuncs(PyObject* self, PyObject* args);
static PyObject* bex_ent_AddAnimSound(PyObject* self, PyObject* args);
static PyObject* bex_ent_AddEventSound(PyObject* self, PyObject* args);
static PyObject* bex_ent_SlideTo(PyObject* self, PyObject* args);
static PyObject* bex_ent_ClearPath(PyObject* self, PyObject* args);
static PyObject* bex_ent_StartPath(PyObject* self, PyObject* args);
static PyObject* bex_ent_GoToPath(PyObject* self, PyObject* args);
static PyObject* bex_ent_TurnOn(PyObject* self, PyObject* args);
static PyObject* bex_ent_TurnOff(PyObject* self, PyObject* args);
static PyObject* bex_ent_AddPathNode(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetNodeStartTangent(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetNodeEndTangent(PyObject* self, PyObject* args);
static PyObject* bex_ent_Rotate(PyObject* self, PyObject* args);
static PyObject* bex_ent_RotateAbs(PyObject* self, PyObject* args);
static PyObject* bex_ent_RotateRel(PyObject* self, PyObject* args);
static PyObject* bex_ent_Move(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetPosition(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetOrientation(PyObject* self, PyObject* args);
static PyObject* bex_ent_PutToWorld(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetInventoryEntity(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetInventorySelected(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetInventory(PyObject* self, PyObject* args);
static PyObject* bex_ent_Use(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetSound(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetObjectSound(PyObject* self, PyObject* args);
static PyObject* bex_ent_PlaySound(PyObject* self, PyObject* args);
static PyObject* bex_ent_StopSound(PyObject* self, PyObject* args);
static PyObject* bex_ent_MessageEvent(PyObject* self, PyObject* args);
static PyObject* bex_ent_Rel2AbsPoint(PyObject* self, PyObject* args);
static PyObject* bex_ent_Rel2AbsVector(PyObject* self, PyObject* args);
static PyObject* bex_ent_Abs2RelPoint(PyObject* self, PyObject* args);
static PyObject* bex_ent_Abs2RelVector(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetDummyAxis(PyObject* self, PyObject* args);
static PyObject* bex_ent_SQDistance2(PyObject* self, PyObject* args);
static PyObject* bex_ent_CatchOnFire(PyObject* self, PyObject* args);
static PyObject* bex_ent_ExcludeHitFor(PyObject* self, PyObject* args);
static PyObject* bex_ent_Unlink(PyObject* self, PyObject* args);
static PyObject* bex_ent_Link(PyObject* self, PyObject* args);
static PyObject* bex_ent_LinkToNode(PyObject* self, PyObject* args);
static PyObject* bex_ent_LinkAnchors(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetNodeIndex(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetNChildren(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetChild(PyObject* self, PyObject* args);
static PyObject* bex_ent_AddCameraEvent(PyObject* self, PyObject* args);
static PyObject* bex_ent_RemoveCameraEvent(PyObject* self, PyObject* args);
static PyObject* bex_ent_AddCameraNode(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetCameraStartTangentNode(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetCameraEndTangentNode(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetTravellingView(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetPersonView(PyObject* self, PyObject* args);
static PyObject* bex_ent_CameraClearPath(PyObject* self, PyObject* args);
static PyObject* bex_ent_CameraStartPath(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetMaxCamera(PyObject* self, PyObject* args);
static PyObject* bex_ent_Cut(PyObject* self, PyObject* args);
static PyObject* bex_ent_DoAction(PyObject* self, PyObject* args);
static PyObject* bex_ent_DoActionWI(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetOnFloor(PyObject* self, PyObject* args);
static PyObject* bex_ent_RaiseEvent(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetWoundedZone(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetWoundedZone(PyObject* self, PyObject* args);
static PyObject* bex_ent_InterruptCombat(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetGroupMembers(PyObject* self, PyObject* args);
static PyObject* bex_ent_GetCombatants(PyObject* self, PyObject* args);
static PyObject* bex_ent_ExcludeHitInAnimationFor(PyObject* self, PyObject* args);
static PyObject* bex_ent_TestPos(PyObject* self, PyObject* args);
static PyObject* bex_ent_TestPosInOwnBox(PyObject* self, PyObject* args);
static PyObject* bex_ent_UnlinkChildren(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetNextAttack(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetAuraActive(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetAuraParams(PyObject* self, PyObject* args);
static PyObject* bex_ent_SetAuraGradient(PyObject* self, PyObject* args);
static PyObject* bex_ent_IsValid(PyObject* self, PyObject* args);

static PyObject *bex_ent_doc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_Data_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_TimerFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_HitFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_InflictHitFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_HitShieldFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_DamageFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_StickFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_FrameFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_HearFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_SeeFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_UseFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_ChangeNodeFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_TouchFluidFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_EnterPrimaryAAFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_EnterSecondaryAAFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_EnterCloseFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_EnterLargeFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_AnmEndedFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_DelayNoSeenFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_RouteEndedFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_ImHurtFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_ImDeadFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_EnemyDeadFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_NoAllowedAreaFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_EnemyNoAllowedAreaFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_CharSeeingEnemyFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_AnmTranFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_NewComboFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_BigFallFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_AttackFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_ToggleCombatFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_TakeFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_ThrowFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_MutilateFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_AttackList_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_OnHitFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_OnStopFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_OnStepFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_OnAnimationEndFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_OnPathNodeFunc_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_RAttackMin_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_RAttackMax_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_ActionAreaMin_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_ActionAreaMax_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_Arrow_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_Static_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_Actor_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_Person_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_Weapon_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_Orientation_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_SubscribedLists_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_FiresIntensity_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_LightIntensity_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_LightPrecission_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_LightColor_get(PyObject *self, char *attr_name);
static PyObject *bex_ent_LightGlow_get(PyObject *self, char *attr_name);
static int bex_ent_Static_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_Actor_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_Person_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_Weapon_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_Arrow_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_Data_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_FiresIntensity_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_Lights_set(PyObject *self, char *attr_name, PyObject *value);
static PyObject *bex_ent_Lights_get(PyObject *self, char *attr_name);
static int bex_ent_RAttackMin_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_RAttackMax_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_ActionAreaMin_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_ActionAreaMax_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_Orientation_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_TimerFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_HitFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_InflictHitFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_HitShieldFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_DamageFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_StickFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_FrameFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_HearFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_SeeFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_UseFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_ChangeNodeFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_TouchFluidFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_EnterPrimaryAAFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_EnterSecondaryAAFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_EnterCloseFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_EnterLargeFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_AnmEndedFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_DelayNoSeenFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_RouteEndedFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_ImHurtFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_ImDeadFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_EnemyDeadFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_NoAllowedAreaFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_EnemyNoAllowedAreaFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_CharSeeingEnemyFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_AnmTranFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_NewComboFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_BigFallFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_AttackFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_ToggleCombatFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_TakeFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_ThrowFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_MutilateFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_AttackList_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_OnHitFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_OnStopFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_OnStepFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_OnAnimationEndFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_OnPathNodeFunc_set(PyObject *self, char *attr_name, PyObject *value);
static int bex_ent_InternalState_set(PyObject *self, char *attr_name, PyObject *value);
static PyObject *bex_ent_InternalState_get(PyObject *self, char *attr_name);
static void init_entity_type(void);
static void bld_py_entity_dealloc(PyObject *self);
static int bld_py_entity_print(PyObject *self, FILE *file, int flags);
static PyObject *bld_py_entity_getattr(PyObject *self, char *attr_name);
static int bld_py_entity_setattr(PyObject *self, char *attr_name, PyObject *value);

static PyObject *get_inventory(const char *name);
static PyObject* bex_inv_CarringObject(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetRightBack(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetLeftBack(PyObject* self, PyObject* args);
static PyObject* bex_inv_LinkRightHand(PyObject* self, PyObject* args);
static PyObject* bex_inv_LinkLeftHand(PyObject* self, PyObject* args);
static PyObject* bex_inv_LinkLeftHand2(PyObject* self, PyObject* args);
static PyObject* bex_inv_LinkRightBack(PyObject* self, PyObject* args);
static PyObject* bex_inv_LinkLeftBack(PyObject* self, PyObject* args);
static PyObject* bex_inv_LinkBack(PyObject* self, PyObject* args);
static PyObject* bex_inv_SetCurrentQuiver(PyObject* self, PyObject* args);
static PyObject* bex_inv_AddObject(PyObject* self, PyObject* args);
static PyObject* add_object(PyObject *self, PyObject *args, int obj_type);
static PyObject* bex_inv_RemoveObject(PyObject* self, PyObject* args);
static PyObject *remove_object(PyObject *self, PyObject *args, int obj_type);
static PyObject* bex_inv_GetObject(PyObject* self, PyObject* args);
static PyObject* get_object(PyObject *self, PyObject *args, int obj_type);
static PyObject* bex_inv_GetSelectedObject(PyObject* self, PyObject* args);
static PyObject* get_selected_object(
        PyObject *self, PyObject *args, int obj_type
);
static PyObject* bex_inv_CycleObjects(PyObject* self, PyObject* args);
static PyObject *cycle_objects(PyObject *self, PyObject *args, int obj_type);
static PyObject* bex_inv_IsObjectSelected(PyObject* self, PyObject* args);
static PyObject *is_object_selected(
        PyObject *self, PyObject *args, int obj_type
);
static PyObject* bex_inv_GetNumberObjectsAt(PyObject* self, PyObject* args);
static PyObject *get_number_objects_at(
        PyObject *self, PyObject *args, int obj_type
);
static PyObject* bex_inv_GetMaxNumberObjectsAt(PyObject* self, PyObject* args);
static PyObject *get_max_number_objects_at(
        PyObject *self, PyObject *args, int obj_type
);
static PyObject* bex_inv_AddShield(PyObject* self, PyObject* args);
static PyObject* bex_inv_RemoveShield(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetShield(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetSelectedShield(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetActiveShield(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetActiveWeapon(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetActiveQuiver(PyObject* self, PyObject* args);
static PyObject* bex_inv_CycleShields(PyObject* self, PyObject* args);
static PyObject* bex_inv_IsShieldSelected(PyObject* self, PyObject* args);
static PyObject* bex_inv_AddWeapon(PyObject* self, PyObject* args);
static PyObject* bex_inv_RemoveWeapon(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetWeapon(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetBow(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetMagicShield(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetSelectedWeapon(PyObject* self, PyObject* args);
static PyObject* bex_inv_CycleWeapons(PyObject* self, PyObject* args);
static PyObject* bex_inv_IsWeaponSelected(PyObject* self, PyObject* args);
static PyObject* bex_inv_AddBow(PyObject* self, PyObject* args);
static PyObject* bex_inv_RemoveBow(PyObject* self, PyObject* args);
static PyObject* bex_inv_AddMagicShield(PyObject* self, PyObject* args);
static PyObject* bex_inv_RemoveMagicShield(PyObject* self, PyObject* args);
static PyObject* bex_inv_AddQuiver(PyObject* self, PyObject* args);
static PyObject* bex_inv_RemoveQuiver(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetQuiver(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetSelectedQuiver(PyObject* self, PyObject* args);
static PyObject* bex_inv_CycleQuivers(PyObject* self, PyObject* args);
static PyObject* bex_inv_IsQuiverSelected(PyObject* self, PyObject* args);
static PyObject* bex_inv_AddKey(PyObject* self, PyObject* args);
static PyObject* bex_inv_RemoveKey(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetKey(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetSelectedKey(PyObject* self, PyObject* args);
static PyObject* bex_inv_CycleKeys(PyObject* self, PyObject* args);
static PyObject* bex_inv_IsKeySelected(PyObject* self, PyObject* args);
static PyObject* bex_inv_AddSpecialKey(PyObject* self, PyObject* args);
static PyObject* bex_inv_RemoveSpecialKey(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetSpecialKey(PyObject* self, PyObject* args);
static PyObject* bex_inv_AddTablet(PyObject* self, PyObject* args);
static PyObject* bex_inv_RemoveTablet(PyObject* self, PyObject* args);
static PyObject* bex_inv_GetTablet(PyObject* self, PyObject* args);
static void init_inventory_type(void);
static void bld_py_inventory_dealloc(PyObject *self);
static int bld_py_inventory_print(PyObject *self, FILE *file, int flags);
static PyObject *bld_py_inventory_getattr(PyObject *self, char *attr_name);
static int bld_py_inventory_setattr(PyObject *self, char *attr_name, PyObject *value);

static PyObject *get_material_by_name(const char *name);
static PyObject *get_material_by_index(int index);
static PyObject *create_material(const char *name);
static PyObject* bex_mat_AddHitSoundComb(PyObject* self, PyObject* args);
static void init_material_type(void);
static void bld_py_material_dealloc(PyObject *self);
static int bld_py_material_print(PyObject *self, FILE *file, int flags);
static PyObject *bld_py_material_getattr(PyObject *self, char *attr_name);
static int bld_py_material_setattr(PyObject *self, char *attr_name, PyObject *value);

static PyObject *create_route(void);
static PyObject* bex_route_AddPoint(PyObject* self, PyObject* args);
static void init_route_type(void);
static void bld_py_route_dealloc(PyObject *self);
static int bld_py_route_print(PyObject *self, FILE *file, int flags);
static PyObject *bld_py_route_getattr(PyObject *self, char *attr_name);
static int bld_py_route_setattr(PyObject *self, char *attr_name, PyObject *value);

static PyObject* get_sector_by_index(int index);
static PyObject* get_sector_by_position(double x, double y, double z);
static PyObject* bex_sec_InitBreak(PyObject* self, PyObject* args);
static PyObject* bex_sec_DoBreak(PyObject* self, PyObject* args);
static PyObject* bex_sec_SetSurfaceTexture(PyObject* self, PyObject* args);
static PyObject* bex_sec_SetSurfaceTextureZoomX(PyObject* self, PyObject* args);
static PyObject* bex_sec_SetSurfaceTextureZoomY(PyObject* self, PyObject* args);
static PyObject* bex_sec_SetSurfaceTextureX(PyObject* self, PyObject* args);
static PyObject* bex_sec_SetSurfaceTextureY(PyObject* self, PyObject* args);
static PyObject* bex_sec_GetSurfaceTexture(PyObject* self, PyObject* args);
static PyObject* bex_sec_GetSurfaceTextureZoomX(PyObject* self, PyObject* args);
static PyObject* bex_sec_GetSurfaceTextureZoomY(PyObject* self, PyObject* args);
static PyObject* bex_sec_GetSurfaceTextureX(PyObject* self, PyObject* args);
static PyObject* bex_sec_GetSurfaceTextureY(PyObject* self, PyObject* args);
static PyObject* bex_sec_SetSpecularLight(PyObject* self, PyObject* args);
static PyObject* bex_sec_GetSpecularLight(PyObject* self, PyObject* args);
static PyObject* bex_sec_SetSpecularShininess(PyObject* self, PyObject* args);
static PyObject* bex_sec_GetSpecularShininess(PyObject* self, PyObject* args);
static PyObject* bex_sec_SetSelfLight(PyObject* self, PyObject* args);
static PyObject* bex_sec_GetSelfLight(PyObject* self, PyObject* args);
static void init_sector_type(void);
static void bld_py_sector_dealloc(PyObject *self);
static int bld_py_sector_print(PyObject *self, FILE *file, int flags);
static PyObject *bld_py_sector_getattr(PyObject *self, char *attr_name);
static int bld_py_sector_setattr(PyObject *self, char *attr_name, PyObject *value);

static PyObject *create_sound(const char *file_name, const char *sound_name);
static PyObject *create_sound_s(int id);
static PyObject *get_ghost_sector_sound(const char *gs_name);
static PyObject* bex_snd_Play(PyObject* self, PyObject* args);
static PyObject* bex_snd_PlayStereo(PyObject* self, PyObject* args);
static PyObject* bex_snd_SetPitchVar(PyObject* self, PyObject* args);
static PyObject* bex_snd_AddAltSound(PyObject* self, PyObject* args);
static PyObject* bex_snd_Stop(PyObject* self, PyObject* args);
static void init_sound_type(void);
static void bld_py_sound_dealloc(PyObject *self);
static int bld_py_sound_print(PyObject *self, FILE *file, int flags);
static boolean bld_py_sound_check(PyObject *self);
static PyObject *bld_py_sound_repr(PyObject *self);
static PyObject *bld_py_sound_getattr(PyObject *self, char *attr_name);
static int bld_py_sound_setattr(PyObject *self, char *attr_name, PyObject *value);


static PyTypeObject entityTypeObject;
static PyTypeObject inventoryTypeObject;
static PyTypeObject materialTypeObject;
static PyTypeObject routeTypeObject;
static PyTypeObject sectorTypeObject;
static PyTypeObject soundTypeObject;

static void (*init_funcs[])(void) = {
    init_char, init_entity_type, init_inventory_type, init_material_type,
    init_route_type, init_sector_type, init_sound_type, init_trail, NULL
};

static PyMethodDef methods[] = {
    { "nEntities",                      bex_nEntities,                      METH_VARARGS, "int nEntities(void) \n Devuelve el nxffffffba de entidades en el mapa.\n" },
    { "GetTime",                        bex_GetTime,                        METH_VARARGS, "float GetTime(void) \n Devuelve el tiempo del juego en segundos.\n" },
    { "SetTime",                        bex_SetTime,                        METH_VARARGS, "bool SetTime(float time) \n Establece el tiempo del juego en segundos.\n" },
    { "GoToTime",                       bex_GoToTime,                       METH_VARARGS, "bool SetClockTime(float time) \n Establece el tiempo del juego en segundos....\n" },
    { "StopTime",                       bex_StopTime,                       METH_VARARGS, "StopTime(void) \n Detiene el tiempo del juego.\n" },
    { "RestartTime",                    bex_RestartTime,                    METH_VARARGS, "RestartTime(void) \n Reinicia el tiempo del juego.\n" },
    { "SetTimeSpeed",                   bex_SetTimeSpeed,                   METH_VARARGS, "GetTimeSpeed(void) \n Devuelve la velocidad tiempo del juego.\n" },
    { "GetTimeSpeed",                   bex_GetTimeSpeed,                   METH_VARARGS, "float GetTimeSpeed(void) \n Devuelve la velocidad tiempo del juego.\n" },
    { "GetNewExclusionGroupId",         bex_GetNewExclusionGroupId,         METH_VARARGS, "int GetNewExclusionGroupId()(void) \n Devuelve un nuevo y unico identificador para los grupos de exclusion.\n" },
    { "AddScheduledFunc",               bex_AddScheduledFunc,               METH_VARARGS, "AddScheduledFunc(double time,Func,Args) \nLlama a la funcion Func con los argumentos Args en el tiempo time" },
    { "RemoveScheduledFunc",            bex_RemoveScheduledFunc,            METH_VARARGS, "RemoveScheduledFunc(atring FuncName) \nRemoves a previously named sceduled function.  Removes first func found with this name." },
    { "GetnScheduledFuncs",             bex_GetnScheduledFuncs,             METH_VARARGS, "int GetnScheduledFuncs(void) \n Devuelve el nxffffffba de funciones diferidas.\n" },
    { "GetScheduledFunc",               bex_GetScheduledFunc,               METH_VARARGS, "(func,arg,name,time) GetScheduledFunc(int index) \n Devuelve una tupla con la funcixfffffff3n, los argumentos, el nombre y cuando se ejecuta.\n" },
    { "SetListenerPosition",            bex_SetListenerPosition,            METH_VARARGS, "SetListenerPosition(int modo[,double x,double y,double z]) \n Cambia posicion o modo del oyente.\n mode : 0 - Punto en el mapa\n        1 - Personaje\n        2 - Cxffffffe1mara" },
    { "CreateSpark",                    bex_CreateSpark,                    METH_VARARGS, "CreateSpark(string name,double x,double y,double z,) \n Crea un efecto de chispas.\n" },
    { "CreateSound",                    bex_CreateSound,                    METH_VARARGS, "CreateSound(string filename,string soundname) \n Crea un sonido a partir del filename y con nombre name.\n" },
    { "CreateRoute",                    bex_CreateRoute,                    METH_VARARGS, "CreateRoute() \n Crea una ruta vacxffffffeda nueva.\n" },
    { "CreateTimer",                    bex_CreateTimer,                    METH_VARARGS, "CreateTimer(string TimerName,double period) \n Crea un Timer de nombre TimerName con periodo period.\n" },
    { "GetnTimers",                     bex_GetnTimers,                     METH_VARARGS, "int GetnTimers(void) \n Devuelve el nxfffffffamero de timers del sistema.\n" },
    { "GetTimerInfo",                   bex_GetTimerInfo,                   METH_VARARGS, "(name,period) GetTimerInfo(int iTimer) \n Devuelve informacixfffffff3n sobre el timer de xffffffedndice iTimer.\n" },
    { "GetTimeActionHeld",              bex_GetTimeActionHeld,              METH_VARARGS, "Return the amount of milliseconds a key has been hald down, or zero if it is currently considered released" },
    { "AddInputAction",                 bex_AddInputAction,                 METH_VARARGS, "AddInputAction(string action_name,int npi) \n Crea una accixfffffff3n nueva.\n" },
    { "RemoveInputAction",              bex_RemoveInputAction,              METH_VARARGS, "RemoveInputAction(string action_name) \n Quita una accixfffffff3n existente.\n" },
    { "AddBoundFunc",                   bex_AddBoundFunc,                   METH_VARARGS, "AddBoundFunc(string key,proc) \n Asigna el procedimiento pr al suceso key.\nAddBoundFunc(string key,string predproc) \n Asigna el procedimiento predefinifo predproc  al suceso key.\n predproc puede ser: Forward, Backwards, Up, Down, Left, Right, RotateLeft, RotateRight, RotateUp, RotateDown (mxffffffe1s, preguntar a Jose)" },
    { "Bind2",                          bex_Bind2,                          METH_VARARGS, "Bind2(void) \nAssociate a combination of 2 Actions keys to a new Action, time window settings." },
    { "AssocKey",                       bex_AssocKey,                       METH_VARARGS, "bool AssocKey(string action,string input_device,string key[,int press]) \nAsocia la accixfffffff3n action con la tecla key del dispositivo input_device\n" },
    { "RemoveBoundFunc",                bex_RemoveBoundFunc,                METH_VARARGS, "RemoveBoundFunc(string key,proc) \n Quita el procedimiento pr del suceso key.\nRemoveBoundFunc(string key,string predproc) \n Quita el procedimiento predefinifo predproc  del suceso key.\n predproc puede ser: Forward, Backwards, Up, Down, Left, Right, RotateLeft, RotateRight, RotateUp, RotateDown (mxffffffe1s, preguntar a Jose)" },
    { "UnBindAll",                      bex_UnBindAll,                      METH_VARARGS, "UnBindAll() \n Borra la configuracixfffffff3n de teclado.\n" },
    { "Input",                          bex_Input,                          METH_VARARGS, "Input(string texto) \n Crea una ventana de introduccixfffffff3n de datos.\n" },
    { "LoadLevel",                      bex_LoadLevel,                      METH_VARARGS, "LoadLevel(string dir_name) \n Lee de disco el nivel en el directorio dir_name.\n" },
    { "ReadLevel",                      bex_ReadLevel,                      METH_VARARGS, "ReadLevel(string filename) \n Lee de disco el nivel (.lvl) filename.\n" },
    { "CloseLevel",                     bex_CloseLevel,                     METH_VARARGS, "CloseLevel([string statement]) \n Cierra el nivel actual y ejecuta la instruccixfffffff3n statement.\n" },
    { "PlaySound",                      bex_PlaySound,                      METH_VARARGS, "PlaySound(int i,double x,double y,double z) \n Reproduce el sonido i en la posicixfffffff3n (x,y,z).\n" },
    { "ShowSounds",                     bex_ShowSounds,                     METH_VARARGS, "ShowSounds(int sh) \n Establece si se debe mostrar un objeto para indicar donde estan los sonido ambiente.\n" },
    { "nSounds",                        bex_nSounds,                        METH_VARARGS, "int nSounds(void) \n Devuelve el nxffffffba de sonidos en el mapa.\n" },
    { "ReadBitMap",                     bex_ReadBitMap,                     METH_VARARGS, "ReadBitMap(string file_name,string internal_name) \n Lee de disco una textura.\n" },
    { "ReadAlphaBitMap",                bex_ReadAlphaBitMap,                METH_VARARGS, "ReadAlphaBitMap(string file_name,string internal_name) \n Lee de disco una textura alpha.\n" },
    { "SetSoundVolume",                 bex_SetSoundVolume,                 METH_VARARGS, "SetSoundVolume(double Volume) \n Establece el volumen del sistema de sonido.\n" },
    { "GetSoundVolume",                 bex_GetSoundVolume,                 METH_VARARGS, "float GetSoundVolume() \n Obtiene el volumen del sistema de sonido.\n" },
    { "SetBloodLevel",                  bex_SetBloodLevel,                  METH_VARARGS, "bool SetBloodLevel(int level) \n Establece el nivel de sangre.\n" },
    { "GetBloodLevel",                  bex_GetBloodLevel,                  METH_VARARGS, "int GetBloodLevel() \n Obtiene el nivel de sangre.\n" },
    { "SetMutilationLevel",             bex_SetMutilationLevel,             METH_VARARGS, "bool SetMutilationLevel(int level) \n Establece el nivel de mutilaciones.\n" },
    { "GetMutilationLevel",             bex_GetMutilationLevel,             METH_VARARGS, "int GetMutilationLevel() \n Obtiene el nivel de mutilaciones.\n" },
    { "CreateEntity",                   bex_CreateEntity,                   METH_VARARGS, "CreateEntity(string name,string kind,double x,double y,double z) \n Crea una entidad nueva.\n" },
    { "DeleteEntity",                   bex_DeleteEntity,                   METH_VARARGS, "DeleteEntity(string name/object entity) \n Delete existing object.  Use with care.  Subscribe to Pin if unsure.\n" },
    { "SoundSystemActive",              bex_SoundSystemActive,              METH_VARARGS, "SoundSystemActive () \n Tells if the sound system if active or not .\n" },
    { "SetSSFrecuency",                 bex_SetSSFrecuency,                 METH_VARARGS, "SetSSFrecuency (int frec) \n Tells the sound system the base frecuency to use .\n" },
    { "SetSS2dChannels",                bex_SetSS2dChannels,                METH_VARARGS, "SetSS2dChannels (int num_ch) \n Tells the sound system the number of 2d channels .\n" },
    { "SetSS3dChannels",                bex_SetSS3dChannels,                METH_VARARGS, "SetSS3dChannels (int num_ch) \n Tells the sound system the number of 3d channels .\n" },
    { "SetSSFilter",                    bex_SetSSFilter,                    METH_VARARGS, "SetSSFilter (bool) \n Tells the sound system to filter the output or not .\n" },
    { "KillMusic",                      bex_KillMusic,                      METH_VARARGS, "KillMusic () \n Guess...;) .n" },
    { "ResumeSoundSystem",              bex_ResumeSoundSystem,              METH_VARARGS, "ResumeSoundSystem () \n Guess...;) .n" },
    { "PauseSoundSystem",               bex_PauseSoundSystem,               METH_VARARGS, "PauseSoundSystem () \n Guess...;) .n" },
    { "PauseSoundSystemButMusic",       bex_PauseSoundSystemButMusic,       METH_VARARGS, "PauseSoundSystemButMusic () \n Idem than pauseSoundSystem BUt with muzic .\n" },
    { "ShutDownSoundChannels",          bex_ShutDownSoundChannels,          METH_VARARGS, "ShutDownSoundChannels () \n Guess...;) .n" },
    { "SetMusicVolume",                 bex_SetMusicVolume,                 METH_VARARGS, "SetMusicVolume (float factor) \n Guess...;) .n" },
    { "GetMusicVolume",                 bex_GetMusicVolume,                 METH_VARARGS, "float GetMusicVolume() \n Obtiene el volumen de la musica.\n" },
    { "SetSSQuality",                   bex_SetSSQuality,                   METH_VARARGS, "Undoc(0-2)\n" },
    { "GetSSQuality",                   bex_GetSSQuality,                   METH_VARARGS, "Undoc(0-2)\n" },
    { "SetSpeakerConfig",               bex_SetSpeakerConfig,               METH_VARARGS, "Undoc(0-3)\n" },
    { "GetSpeakerConfig",               bex_GetSpeakerConfig,               METH_VARARGS, "Undoc(0-3)\n" },
    { "SetEAXOverride",                 bex_SetEAXOverride,                 METH_VARARGS, "SetEAXOverride(0/1) \n" },
    { "GetEAXOverride",                 bex_GetEAXOverride,                 METH_VARARGS, "float GetEAXOverride() \n" },
    { "SaveSSConfig",                   bex_SaveSSConfig,                   METH_VARARGS, "Undoc\n" },
    { "SetAutoGenTexture",              bex_SetAutoGenTexture,              METH_VARARGS, "SetAutoGenTexture (string TexturName , integer TextEfecct ) \nA la texture con dicho nombre se le aplica el efecto dado .\n" },
    { "AddTranTime",                    bex_AddTranTime,                    METH_VARARGS, "AddTranTime (string biped_name,string next_anm , string prev_anm , double time ) \n Al pasar de animacion prev_anm a next_anm la transicion dura t segs . 0 si no transicion .\n" },
    { "CheckAnims",                     bex_CheckAnims,                     METH_VARARGS, "Gives a report of anims not assigned\n" },
    { "GiveAnims",                      bex_GiveAnims,                      METH_VARARGS, "GiveAnims(race_name). Da las anims de la raza en cuestion\n" },
    { "GetAnimationDuration",           bex_GetAnimationDuration,           METH_VARARGS, "GetAnimationDuration (string sampled animation name ) \n Resturns the duration in seconds of the full animation disregarding interpolation.\n" },
    { "SetAnimationFactor",             bex_SetAnimationFactor,             METH_VARARGS, "SetAnimationFactor(string mov , float new_speed_factor ) \n Cambia la velocidad del movimiento dado .\n" },
    { "SetTurnSpeed",                   bex_SetTurnSpeed,                   METH_VARARGS, "SetTurnSpeed(string name_raza,float new_speed ) \n Cambia la velocidad de giro de una raza . En radianes.\n" },
    { "GetEntity",                      bex_GetEntity,                      METH_VARARGS, "GetEntity(int n) \n Crea una entidad de Python que referencia a la entidad Blade de xffffffedndice n.\nGetEntity(string name) \n Crea una entidad de Python que referencia a la entidad Blade de nombre name.\n" },
    { "GetEntitiesAt",                  bex_GetEntitiesAt,                  METH_VARARGS, "tuple GetEntitiesAt(double x,double y,double z,double radius) \n Obtiene las entidades que estxffffffe1n en un radio radius de la posicixfffffff3n (x,y,z)\n" },
    { "GetEntitiesVisibleFrom",         bex_GetEntitiesVisibleFrom,         METH_VARARGS, "tuple GetEntitiesVisibleFrom(tuple center,double radius,tuple direction,double angle) \n" },
    { "GetObjectEntitiesVisibleFrom",   bex_GetObjectEntitiesVisibleFrom,   METH_VARARGS, "tuple GetObjectEntitiesVisibleFrom(tuple center,double radius,tuple direction,double angle) \n" },
    { "GetEnemiesVisibleFrom",          bex_GetEnemiesVisibleFrom,          METH_VARARGS, "tuple GetEnemiesVisibleFrom(tuple center,double radius,tuple direction,double angle) \n" },
    { "GetCombos",                      bex_GetCombos,                      METH_VARARGS, "tuple GetCombos(blah blah BLAH!) \n" },
    { "SetCombos",                      bex_SetCombos,                      METH_VARARGS, "bool SetCombos(tuple combos) \n" },
    { "GetWeaponCombos",                bex_GetWeaponCombos,                METH_VARARGS, "tuple GetWeaponCombos(blah blah BLAH!) \n" },
    { "GetLastPlayerCType",             bex_GetLastPlayerCType,             METH_VARARGS, "string GetLastPlayerCType() \n" },
    { "nSectors",                       bex_nSectors,                       METH_VARARGS, "int nEntities(void) \n Devuelve el nxffffffba de sectors en el mapa.\n" },
    { "GetSector",                      bex_GetSector,                      METH_VARARGS, "GetSector(int n) \n Crea un sector de Python que referencia al sector Blade de xffffffedndice n.\nGetSector(double x,double y,double z) \n Crea un sector de Python que referencia al sector Blade que contiene al punto (x,y,z).\n" },
    { "GetCharType",                    bex_GetCharType,                    METH_VARARGS, "GetCharType(Barbarian,Bar) \n Crea un CharType , o raza de personaje.\n" },
    { "GetTrailType",                   bex_GetTrailType,                   METH_VARARGS, "GetTrailType(esteraCorta) \n Crea un TrailType , o tipo de estelas.\n" },
    { "SetDefaultMass",                 bex_SetDefaultMass,                 METH_VARARGS, "SetDefaultMass(string entity_kind,double mass) \n Establece la masa mass predefinida para las nuevas entidades de tipo kind.\n" },
    { "SetDefaultMaterial",             bex_SetDefaultMaterial,             METH_VARARGS, "SetDefaultMaterial(string entity_kind,double material) \n Establece el material predefinido para las nuevas entidades de tipo kind.\n" },
    { "CreateMaterial",                 bex_CreateMaterial,                 METH_VARARGS, "CreateMaterial(string name) \n Crea un nuevo material con nombre name.\n" },
    { "GetMaterial",                    bex_GetMaterial,                    METH_VARARGS, "GetMaterial(int n) \n Crea un objeto Python que referencia al material Blade de xffffffedndice n.\nGetMaterial(string name) \n Crea un objeto Python que referencia al material Blade de nombre name.\n" },
    { "nMaterials",                     bex_nMaterials,                     METH_VARARGS, "nMaterials(void) \n Devuelve el nxffffffba de materiales.\n" },
    { "GenerateEntityName",             bex_GenerateEntityName,             METH_VARARGS, "string GenerateEntityName() \n Generates a new and unique entity name.\n" },
    { "AddWatchAnim",                   bex_AddWatchAnim,                   METH_VARARGS, "AddWatchAnim(string) \n Establece esa animacion como una de las incluidas en modo watch.\nNOTA : NO es ejecutada por defecto por ningun personaje , para eso hay otra funcion !.\n" },
    { "AddAnimFlags",                   bex_AddAnimFlags,                   METH_VARARGS, "AddAnimFlags(string,wuea,mdf_y,solf,copy_rot,bng_mov,head_f) \n" },
    { "SetEAX",                         bex_SetEAX,                         METH_VARARGS, "SetEAX(integer eax_flag) \n Establece la distorsion eax indicada.\n" },
    { "GetSound",                       bex_GetSound,                       METH_VARARGS, "GetSound(name)\n" },
    { "SetActionCameraMovement",        bex_SetActionCameraMovement,        METH_VARARGS, "SetActionCameraMovement(char* action_name,double angle,double start_pos,double end_pos) \n Interpolates the camera in the given action , the given angle in the given gap\n" },
    { "DeactivateInput",                bex_DeactivateInput,                METH_VARARGS, "DeactivateInput() \n Disabled the input for the main player.\n" },
    { "ActivateInput",                  bex_ActivateInput,                  METH_VARARGS, "ActivateInput() \n Reactivate the input for the main player.\n" },
    { "AddGhostSector",                 bex_AddGhostSector,                 METH_VARARGS, "AddGhostSector(string GhostName,string GroupName,float FloorHeight,float RoofHeight,List points) \n Crea.\n" },
    { "SetGhostSectorSound",            bex_SetGhostSectorSound,            METH_VARARGS, "SetGhostSectorSound(string GhostName,string filename,double Volume,double BaseVolume,double MinDist,double MaxDist,double vMaxDist,double Scale) \n Establece el sonido del archivo filename al sector fantasma GhostName.\n" },
    { "SetGhostSectorGroupSound",       bex_SetGhostSectorGroupSound,       METH_VARARGS, "SetGhostSectorGroupSound(string GroupName,string filename,double Volume,double BaseVolume,double MinDist,double MaxDist,double Scale) \n Establece el sonido del archivo filename al grupo de sectores fantasma GhostName.\n" },
    { "AddTriggerSector",               bex_AddTriggerSector,               METH_VARARGS, "AddTriggerSector(string TriggerSectorName,string GroupName,float FloorHeight,float RoofHeight,List points) \n Crea.\n" },
    { "SetTriggerSectorFunc",           bex_SetTriggerSectorFunc,           METH_VARARGS, "SetTriggerSectorFunc(string TriggerSectorName,string FuncType,Func) \nAsigna la funcion Func al evento FuncType del triggersector TriggerSectorName.\n" },
    { "GetTriggerSectorFunc",           bex_GetTriggerSectorFunc,           METH_VARARGS, "GetTriggerSectorFunc(string TriggerSectorName,string FuncType) \nDevuelve la funcion asociada al evento FuncType del triggersector TriggerSectorName.\n" },
    { "RemoveTriggerSectorFunc",        bex_RemoveTriggerSectorFunc,        METH_VARARGS, "RemoveTriggerSectorFunc(string TriggerSectorName,string FuncType) \n Desvincula la funcion asociada al evento FuncType del triggersector TriggerSectorName.\n" },
    { "SetTriggerSectorData",           bex_SetTriggerSectorData,           METH_VARARGS, "SetTriggerSectorData(string TriggerSectorName,Data) \nAsigna el objeto Python Data al campo Data del triggersector TriggerSectorName.\n" },
    { "GetTriggerSectorData",           bex_GetTriggerSectorData,           METH_VARARGS, "GetTriggerSectorFunc(string TriggerSectorName) \n Devuelve el objeto Python asociado al campo Data del triggersector TriggerSectorName.\n" },
    { "GetTriggerSectorFloorHeight",    bex_GetTriggerSectorFloorHeight,    METH_VARARGS, "GetTriggerSectorFloorHeight(string TriggerSectorName) \n Devuelve la altura del suelo asociada al trigersector TriggerSectorName.\n" },
    { "GetTriggerSectorRoofHeight",     bex_GetTriggerSectorRoofHeight,     METH_VARARGS, "GetTriggerSectorRoofHeight(string TriggerSectorName) \n Devuelve la altura del techo asociada al trigersector TriggerSectorName.\n" },
    { "GetTriggerSectorGroup",          bex_GetTriggerSectorGroup,          METH_VARARGS, "GetTriggerSectorGroup(string TriggerSectorName) \n Devuelve el grupo asociado al trigersector TriggerSectorName.\n" },
    { "GetTriggerSectorPoints",         bex_GetTriggerSectorPoints,         METH_VARARGS, "GetTriggerSectorPoints(string TriggerSectorName) \n Devuelve los puntos asociados al trigersector TriggerSectorName.\n" },
    { "nTriggerSectors",                bex_nTriggerSectors,                METH_VARARGS, "int nTriggerSectors(void)\n Desvincula el nxfffffffamero de triggersectors en el mapa.\n" },
    { "GetTriggerSectorName",           bex_GetTriggerSectorName,           METH_VARARGS, "string GetTriggerSectorName(int idx)\n Devuelve el triggersector de xffffffedndice idx, None si no existe.\n" },
    { "CDPlayTrack",                    bex_CDPlayTrack,                    METH_VARARGS, "PlayCDTrack(int ntrack) \n Reproduce la pista ntrack del CD.\n Si ntrack==1 reproduce todo el CD.\n" },
    { "CDnTracks",                      bex_CDnTracks,                      METH_VARARGS, "int nCDTracks() \n Devuelve el nxfffffffamero de pistas del CD.\n" },
    { "CDLenght",                       bex_CDLenght,                       METH_VARARGS, "int CDLenght() \n Devuelve la duracixfffffff3n del CD en milisegundos.\n" },
    { "CDTrackLenght",                  bex_CDTrackLenght,                  METH_VARARGS, "CDTrackLenght(int ntrack) \n Devuelve la duracixfffffff3n en milisegundos de la pista ntrack.\n" },
    { "CDPresent",                      bex_CDPresent,                      METH_VARARGS, "int CDPresent() \n Indica si estxffffffe1 el CD.\n" },
    { "CDStop",                         bex_CDStop,                         METH_VARARGS, "int CDStop() \n Detiene el CD.\n" },
    { "CDPause",                        bex_CDPause,                        METH_VARARGS, "int CDPause() \n Detiene el CD.\n" },
    { "CDCallBack",                     bex_CDCallBack,                     METH_VARARGS, "int CDCallBack(func f) \n Establece la funcixfffffff3n CD.\n" },
    { "SetSun",                         bex_SetSun,                         METH_VARARGS, "SetSun(int exists,double x,double y,double z) \n Establece la posicion del sol mediante la direccion de la luz exterior. exists indica si se dibuja (1) o no (0) \n" },
    { "InsideActionArea",               bex_InsideActionArea,               METH_VARARGS, "InsideActionArea(int AA,double x,double y,double z) \n....blah blah !\n" },
    { "AnmAddEvent",                    bex_AnmAddEvent,                    METH_VARARGS, "AnmAddEvent(anm_name,event_name,event_frame) \nDeclara en la animacion de nombre anm_name un evento de nombre event_name en el frame event_frame" },
    { "AddAnmEvent",                    bex_AddAnmEvent,                    METH_VARARGS, "AnmAddEvent(anm_name,event_name,event_frame) \n" },
    { "AnmDelEvent",                    bex_AnmDelEvent,                    METH_VARARGS, "AnmDelEvent(anm_name,event_name) \nBorra en la animacion de nombre anm_name el evento de nombre event_name" },
    { "AnmClearEvents",                 bex_AnmClearEvents,                 METH_VARARGS, "AnmClearEvents(anm_name) \nBorra en la animacion de nombre anm_name todos los eventos" },
    { "AnmGetEventFrame",               bex_AnmGetEventFrame,               METH_VARARGS, "AnmGetEventFrame(anm_name,event_name) \nDevuelve en la animacion de nombre anm_name frame del evento de nombre event_name y si no existe devuelve -1" },
    { "AddParticleGType",               bex_AddParticleGType,               METH_VARARGS, "" },
    { "SetParticleGVal",                bex_SetParticleGVal,                METH_VARARGS, "" },
    { "GetnParticleGType",              bex_GetnParticleGType,              METH_VARARGS, "int GetnParticleGType(void)\n  Devuelve el nxffffffba de tipos de partxffffffedculas.\n" },
    { "GetParticleGType",               bex_GetParticleGType,               METH_VARARGS, "Preguntar a Angel" },
    { "GetParticleGVal",                bex_GetParticleGVal,                METH_VARARGS, "Preguntar a Angel" },
    { "AddCombustionDataFor",           bex_AddCombustionDataFor,           METH_VARARGS, "AddCombustionDataFor(object_kind,upper_treshol,lower_treshold,flame_height,flame_size,speed,livetime) \n" },
    { "SetRootWidget",                  bex_SetRootWidget,                  METH_VARARGS, "SetRootWidget(widget w) \n Establece el Widget raiz.\n" },
    { "GetRootWidget",                  bex_GetRootWidget,                  METH_VARARGS, "SetRootWidget(widget w) \n Establece el Widget raiz.\n" },
    { "SetCallCheck",                   bex_SetCallCheck,                   METH_VARARGS, "SetCallCheck(int check) \n Activa/desactiva la comprobacixfffffff3n de errores de Python en las llamadas que hace Blade.\nDevuelve el estado anterior\n" },
    { "DrawBOD",                        bex_DrawBOD,                        METH_VARARGS, "DrawBOD(string BODName,int x,int y,int ancho,int alto) \n Dibuja el BOD de nombre BODName en el rectxffffffe1ngulo x,y,ancho,alto.\n" },
    { "SetAfterFrameFunc",              bex_SetAfterFrameFunc,              METH_VARARGS, "SetAfterFrameFunc(name,function)\n Sets a function referenced with name that is going to be called at the end of each frame." },
    { "GetAfterFrameFunc",              bex_GetAfterFrameFunc,              METH_VARARGS, "GetAfterFrameFunc(name)\n Devuelve la funcixfffffff3n AfterFrame de nombre name.\n" },
    { "GetAfterFrameFuncName",          bex_GetAfterFrameFuncName,          METH_VARARGS, "string GetAfterFrameFuncName(int idx)\n Devuelve el nombre de la funcixfffffff3n AfterFrame del sistema de xffffffedndice idx.\n" },
    { "GetnAfterFrameFuncs",            bex_GetnAfterFrameFuncs,            METH_VARARGS, "int GetnAfterFrameFuncs()\n Devuelve el nxffffffba de funciones AfterFrame en el sistema.\n" },
    { "RemoveAfterFrameFunc",           bex_RemoveAfterFrameFunc,           METH_VARARGS, "GetAfterFrameFunc(name)\n Devuelve la funcixfffffff3n AfterFrame del sistema de nombre name.\n" },
    { "SetMenuTgapFunc",                bex_SetMenuTgapFunc,                METH_VARARGS, "SetMenuTgapFunc(function)\n Sets a function blah blah blah...\n" },
    { "GetMenuTgapFunc",                bex_GetMenuTgapFunc,                METH_VARARGS, "GetMenuTgapFunc()\n Devuelve .....\n" },
    { "WriteText",                      bex_WriteText,                      METH_VARARGS, "" },
    { "GetTextWH",                      bex_GetTextWH,                      METH_VARARGS, "" },
    { "GetScreenRect",                  bex_GetScreenRect,                  METH_VARARGS, "" },
    { "GetScreenXY",                    bex_GetScreenXY,                    METH_VARARGS, "" },
    { "ShowActionAreas",                bex_ShowActionAreas,                METH_VARARGS, "" },
    { "ExportWorld",                    bex_ExportWorld,                    METH_VARARGS, "ExportWorld () \n Export the world to owner Max format.\n" },
    { "CheckPyErrors",                  bex_CheckPyErrors,                  METH_VARARGS, "returns whether a python error has occured." },
    { "SetAppMode",                     bex_SetAppMode,                     METH_VARARGS, "bool SetAppMode(string mode) \n Establece el modo de la aplicacixfffffff3n (Game, Menu,...).\n" },
    { "GetAppMode",                     bex_GetAppMode,                     METH_VARARGS, "string GetAppMode() \n Obtiene el modo de la aplicacixfffffff3n (Game, Menu,...).\n" },
    { "Quit",                           bex_Quit,                           METH_VARARGS, "bool Quit() \n Termina el programa.\n" },
    { "OpenDebugChannel",               bex_OpenDebugChannel,               METH_VARARGS, "bool OpenDebugChannel(string channel_name) \n Abre el canal de depuracixfffffff3n de nombre channel_name.\n" },
    { "CloseDebugChannel",              bex_CloseDebugChannel,              METH_VARARGS, "bool CloseDebugChannel(string channel_name) \n Cierra el canal de depuracixfffffff3n de nombre channel_name.\n" },
    { "LoadSampledAnimation",           bex_LoadSampledAnimation,           METH_VARARGS, "LoadSampledAnm(str File,str InternalName,int Type)" },
    { "CreateFCAnimation",              bex_CreateFCAnimation,              METH_VARARGS, "CreateFCAnmimation(str File,str InternalName,int n_armonics)" },
    { "CreateDFCAnimation",             bex_CreateDFCAnimation,             METH_VARARGS, "CreateDFCAnmimation(str File1,str File2,str InternalName,int n_armonics)" },
    { "GetAnmRaces",                    bex_GetAnmRaces,                    METH_VARARGS, "list GetAnmRaces(void) \n  Devuelve una lista con los nombres de las razas cargadas en memoria.\n" },
    { "CreateBipedData",                bex_CreateBipedData,                METH_VARARGS, "" },
    { "AddBipedAction",                 bex_AddBipedAction,                 METH_VARARGS, "" },
    { "RemoveBipedAction",              bex_RemoveBipedAction,              METH_VARARGS, "" },
    { "GetWorldFileName",               bex_GetWorldFileName,               METH_VARARGS, "string GetWorldFileName()\n Obtiene el nombre del archivo del que se ha cargado el mundo actual.\n" },
    { "LoadWorld",                      bex_LoadWorld,                      METH_VARARGS, "LoadWorld(string filename) \n Lee de disco el mapa (.bw) de nombre filename.\n" },
    { "DoneLoadGame",                   bex_DoneLoadGame,                   METH_VARARGS, "void DoneLoadGame() \n Indica a la engine que se ha cargado una partida grabada para que pueda ajustar parxffffffe1metros.\n" },
    { "BeginLoadGame",                  bex_BeginLoadGame,                  METH_VARARGS, "void BeginLoadGame() \n Indica a la engine que se va a cargar una partida grabada para que pueda ajustar parxffffffe1metros.\n" },
    { "SetSaveInfo",                    bex_SetSaveInfo,                    METH_VARARGS, "int SetSaveInfo(tuple info) \n  Establece informacixfffffff3n de estado.\n" },
    { "GetSaveInfo",                    bex_GetSaveInfo,                    METH_VARARGS, "tuple GetSaveInfo(void) \n  Obtiene informacixfffffff3n de estado.\n" },
    { "LoadEntitiesData",               bex_LoadEntitiesData,               METH_VARARGS, "bool LoadEntitiesData(string filename) \n  Carga los datos de las entidades del archivo filename.\n" },
    { "SaveEntitiesData",               bex_SaveEntitiesData,               METH_VARARGS, "bool SaveEntitiesData(string filename) \n  Guarda los datos de las entidades en el archivo filename.\n" },
    { "LoadParticleSystemsData",        bex_LoadParticleSystemsData,        METH_VARARGS, "bool LoadParticleSystemsData(string filename) \n  Carga los datos de los sistemas de partxffffffedculas del archivo filename.\n" },
    { "SaveParticleSystemsData",        bex_SaveParticleSystemsData,        METH_VARARGS, "bool SaveParticleSystemsData(string filename) \n  Guarda los datos de los sistemas de partxffffffedculas en el archivo filename.\n" },
    { "LoadAnmRaceData",                bex_LoadAnmRaceData,                METH_VARARGS, "bool LoadAnmRaceData(string filename,string race) \n  Carga las animaciones de la raza en el archivo filename.\n" },
    { "SaveAnmRaceData",                bex_SaveAnmRaceData,                METH_VARARGS, "bool SaveAnmRaceData(string filename,string race) \n  Guarda las animaciones de la raza race en el archivo filename.\n" },
    { "LoadAnmSoundData",               bex_LoadAnmSoundData,               METH_VARARGS, "bool LoadAnmSoundData(string filename,string race) \n  Carga la informacixfffffff3n de sonido de las animaciones de la raza en el archivo filename.\n" },
    { "SaveAnmSoundData",               bex_SaveAnmSoundData,               METH_VARARGS, "bool SaveAnmSoundData(string filename,string race) \n  Guarda informacixfffffff3n de sonido de las animaciones de la raza race en el archivo filename.\n" },
    { "SaveProfileData",                bex_SaveProfileData,                METH_VARARGS, "bool SaveProfileData(string filename) \n  Tiene que estar activado el profiler interno.\n  Guarda informacixfffffff3n de los tiempos de las secciones activas en el archivo filename.\n" },
    { "OpenProfileSection",             bex_OpenProfileSection,             METH_VARARGS, "bool OpenProfileSection(int section[,string comment]) \n  Tiene que estar activado el profiler interno.\n  Abre la seccixfffffff3n i.\n" },
    { "CloseProfileSection",            bex_CloseProfileSection,            METH_VARARGS, "bool CloseProfileSection(int section) \n  Tiene que estar activado el profiler interno.\n  Cierra la seccixfffffff3n i.\n" },
    { "StartProfile",                   bex_StartProfile,                   METH_VARARGS, "bool StartProfile(void) \n  Tiene que estar activado el profiler interno.\n  Reinicia sesixfffffff3n.\n" },
    { "EnableProfiler",                 bex_EnableProfiler,                 METH_VARARGS, "bool EnableProfiler(void) \n  activar profiler interno.\n" },
    { "DisableProfiler",                bex_DisableProfiler,                METH_VARARGS, "bool DisableProfiler(void) \n  desactivar profiler interno.\n" },
    { "ReassignCombustionData",         bex_ReassignCombustionData,         METH_VARARGS, "bool ReassignCombustionData(void) \n  Reasigna los datos de los combustion data del archivo filename.\n" },
    { "LoadCombustionData",             bex_LoadCombustionData,             METH_VARARGS, "bool LoadCombustionData(string filename) \n  Carga los datos de los combustion data del archivo filename.\n" },
    { "SaveCombustionData",             bex_SaveCombustionData,             METH_VARARGS, "bool SaveCombustionData(string filename) \n  Guarda los datos de los combustion  data en el archivo filename.\n" },
    { "SetDrawObjectShadows",           bex_SetDrawObjectShadows,           METH_VARARGS, "bool SetDrawObjectShadows(bool draw)\nEstablece si se deben dibujar las sombras de los objetos/personajes.\n" },
    { "GetDrawObjectShadows",           bex_GetDrawObjectShadows,           METH_VARARGS, "bool GetDrawObjectShadows()\nDevuelve si se dibujan las sombras de los objetos/personajes.\n" },
    { "SetAutoEngageCombat",            bex_SetAutoEngageCombat,            METH_VARARGS, "bool SetAutoEngageCombat(bool auto)\nEstablece si se encara automaticamente los enemigos.\n" },
    { "GetAutoEngageCombat",            bex_GetAutoEngageCombat,            METH_VARARGS, "bool GetAutoEngageCombat()\nDevuelve true si se encara automaticanmente si se puede.\n" },
    { "SetAecGap",                      bex_SetAecGap,                      METH_VARARGS, "bool SetAutoEngageCombat(double aec_gap)\nEstablece tiempo auto encaramiento.\n" },
    { "GetAecGap",                      bex_GetAecGap,                      METH_VARARGS, "bool GetAecGap()\nDevuelve tiempo de auto encaramientpo.....\n" },
    { "SetActionEventTable",            bex_SetActionEventTable,            METH_VARARGS, "" },
    { "SetEventTableFuncC",             bex_SetEventTableFuncC,             METH_VARARGS, "" },
    { "SetEventTableFunc",              bex_SetEventTableFunc,              METH_VARARGS, "" },
    { "SetSolidMask",                   bex_SetSolidMask,                   METH_VARARGS, "" },
    { "AddAnmRStep",                    bex_AddAnmRStep,                    METH_VARARGS, "" },
    { "AddAnmLStep",                    bex_AddAnmLStep,                    METH_VARARGS, "" },
    { "AnmTypeRSteps",                  bex_AnmTypeRSteps,                  METH_VARARGS, "" },
    { "AnmTypeLSteps",                  bex_AnmTypeLSteps,                  METH_VARARGS, "" },
    { "AddAnmRRelease",                 bex_AddAnmRRelease,                 METH_VARARGS, "" },
    { "AddAnmLRelease",                 bex_AddAnmLRelease,                 METH_VARARGS, "" },
    { "AddStopTests",                   bex_AddStopTests,                   METH_VARARGS, "AnmStopTests(anm_name) \n" },
    { "AddFloorCTolerance",             bex_AddFloorCTolerance,             METH_VARARGS, "AddFloorCTolerance(anm_name,float) \n" },
    { "GetModelPos",                    bex_GetModelPos,                    METH_VARARGS, "GetModelPos(string Person)\nDevuelve la posicion del modelo 3D del Person especificado\n" },
    { "GetGhostSectorSound",            bex_GetGhostSectorSound,            METH_VARARGS, "GetGhostSectorSound(string gsname) \n Devuelve el sonido ambiente perteneciente al sector fantasma de nombre gsname.\n" },
    { "GetSoundName",                   bex_GetSoundName,                   METH_VARARGS, "string GetSoundName(int idx) \n Devuelve el nombre del sonido idx.\n" },
    { "GetSoundFileName",               bex_GetSoundFileName,               METH_VARARGS, "string GetSoundFileName(int idx) \n Devuelve el archivo del sonido idx.\n" },
    { "GetCurrentMap",                  bex_GetCurrentMap,                  METH_VARARGS, "string GetCurrentMap() \n Devuelve el mapa actual.\n" },
    { "SetCurrentMap",                  bex_SetCurrentMap,                  METH_VARARGS, "bool SetCurrentMap(string dir_map) \n Establece el directorio de mapa actual.\n" },
    { "GetCommandLine",                 bex_GetCommandLine,                 METH_VARARGS, "string GetCommandLine() \n Obtiene la lxffffffednea de xfffffff3rdenes que se ha pasado a la aplicacixfffffff3n.\n" },
    { "GetProgramId",                   bex_GetProgramId,                   METH_VARARGS, "int GetProgramId()\n Devuelve identificador de la aplicacixfffffff3n.\n (HWND en Windows)" },
    { "GetWindowId",                    bex_GetWindowId,                    METH_VARARGS, "int GetWindowId()\n Devuelve identificador de la ventana de la aplicacixfffffff3n.\n (HWND en Windows)" },
    { "AddStepSound",                   bex_AddStepSound,                   METH_VARARGS, "AddStepSound(name,sound) \n" },
    { "AddMaterialStepSound",           bex_AddMaterialStepSound,           METH_VARARGS, "AddMaterialStepSound(table,material,step_sound) \n" },
    { "AddTextureMaterial",             bex_AddTextureMaterial,             METH_VARARGS, "AddTextureMaterial(texture,material) \n" },
    { "AddActionStepSound",             bex_AddActionStepSound,             METH_VARARGS, "AddActionStepSound(table,action,step_sound_table) \n" },
    { "GetGhostSectorSound",            bex_GetGhostSectorSound,            METH_VARARGS, "GetGhostSectorSound(string gsname) \n Devuelve el sonido ambiente perteneciente al sector fantasma de nombre gsname.\n" },
    { "GetSoundName",                   bex_GetSoundName,                   METH_VARARGS, "string GetSoundName(int idx) \n Devuelve el nombre del sonido idx.\n" },
    { "GetSoundFileName",               bex_GetSoundFileName,               METH_VARARGS, "string GetSoundFileName(int idx) \n Devuelve el archivo del sonido idx.\n" },
    { "GetSoundName",                   bex_GetSoundName,                   METH_VARARGS, "string GetSoundName(int idx) \n Devuelve el nombre del sonido idx.\n" },
    { "GetSoundFileName",               bex_GetSoundFileName,               METH_VARARGS, "string GetSoundFileName(int idx) \n Devuelve el archivo del sonido idx.\n" },
    { "GetMusicEventPriority",          bex_GetMusicEventPriority,          METH_VARARGS, "" },
    { "GetMusicEvent",                  bex_GetMusicEvent,                  METH_VARARGS, "GetMusicEvent(lpszEventName)\n" },
    { "ExeMusicEvent",                  bex_ExeMusicEvent,                  METH_VARARGS, "" },
    { "AddMusicEventCD",                bex_AddMusicEventCD,                METH_VARARGS, "AddMusicEventCD(lpszEventName, iTrack, dFIn, dFOut, fVolume, fPriority, bBackGround, iNext)\n" },
    { "AddMusicEventMP3",               bex_AddMusicEventMP3,               METH_VARARGS, "AddMusicEventMP3( lpszEventName, lpszFile, dFIn, fVolume, dFOut, fPriority, bBackGround, iNext )\n" },
    { "AddMusicEventWAV",               bex_AddMusicEventWAV,               METH_VARARGS, "AddMusicEventWAV( lpszEventName, lpszFile, dFIn, fVolume, dFOut, fPriority, bBackGround, iNext, [opened])\n" },
    { "AddMusicEventADPCM",             bex_AddMusicEventADPCM,             METH_VARARGS, "AddMusicEventADPCM( lpszEventName, lpszFile, dFIn, fVolume, dFOut, fPriority, bBackGround, iNext )\n" },
    { "YSSInfo",                        bex_YSSInfo,                        METH_VARARGS, "YSSInfo()\n" },
    { "LoadSoundDataBase",              bex_LoadSoundDataBase,              METH_VARARGS, "loadSoundDataBase(filename)\n" },
    { "SaveSoundDataBase",              bex_SaveSoundDataBase,              METH_VARARGS, "saveSoundDataBase(filename)\n" },
    { "LoadMusicState",                 bex_LoadMusicState,                 METH_VARARGS, "loadMusicState(filename)\n" },
    { "SaveMusicState",                 bex_SaveMusicState,                 METH_VARARGS, "saveMusicState(filename)\n" },
    { "SaveStats",                      bex_SaveStats,                      METH_VARARGS, "Save statistics\n" },
    { "TakeSnapShot",                   bex_TakeSnapShot,                   METH_VARARGS, "Takes a snapshot\n" },
    { "GetMouseState",                  bex_GetMouseState,                  METH_VARARGS, "GetMouseState()\n retorna invert,xsens,ysens" },
    { "SetMouseState",                  bex_SetMouseState,                  METH_VARARGS, "SetMouseState(invert,xsens,ysens)\n" },
    { "GetPTime",                       bex_GetPTime,                       METH_VARARGS, "GetPTime()\n real timer" },
    { "BodInspector",                   bex_BodInspector,                   METH_VARARGS, "BodInspector()\n" },
    { "SetRunString",                   bex_SetRunString,                   METH_VARARGS, "void SetRunString(string variable) \n  Ejecuta la cadena de caracteres variable.\n" },
    { "SetStringValue",                 bex_SetStringValue,                 METH_VARARGS, "bool SetStringValue(string variable,string value) \n  Guarda la cadena de caracteres value cobn el nombre variable.\n" },
    { "GetStringValue",                 bex_GetStringValue,                 METH_VARARGS, "string GetStringValue(string variable) \n  Devuelve el valor de variable, None si no esta definida.\n" },
    { "DeleteStringValue",              bex_DeleteStringValue,              METH_VARARGS, "string DeleteStringValue(string variable) \n  Elimina variable.\n" },
    { "PerformHeapCheck",               bex_PerformHeapCheck,               METH_VARARGS, "PerformHeapCheck() \nPerforms an integrity check on the heap now.  Integrity assertion only working in DEBUG\n" },
    { "HeapCheckSetMark",               bex_HeapCheckSetMark,               METH_VARARGS, "HeapCheckSetMark() \nSets a memory checkpoint.  Reterns current bytes allocated. Only working in DEBUG\n" },
    { "HeapCheckAllAllocations",        bex_HeapCheckAllAllocations,        METH_VARARGS, "HeapCheckAllAllocations(integer) \n  Sets the Heap Checking to be performed on every allocation.  Functions only in debug.\n" },
    { "HeapCheckDelayFree",             bex_HeapCheckDelayFree,             METH_VARARGS, "HeapCheckDelayFree(integer) \n  Simulates low memory conditions by delaying freeing until program termination.  Functions only in debug.\n" },
    { "HeapCheckSystemMemory",          bex_HeapCheckSystemMemory,          METH_VARARGS, "HeapCheckSystemMemory(integer) \n  Includes memory used in runtime libraries for checking.  Functions only in debug.\n" },
    { "HeapCheckLeaks",                 bex_HeapCheckLeaks,                 METH_VARARGS, "HeapCheckSystemMemory(integer) \n  Enables leak checking on program termination.  Functions only in debug.\n" },
    { "DumpMemoryLeaks",                bex_DumpMemoryLeaks,                METH_VARARGS, "bool DumpMemoryLeaks(string filename) \n Dumps cuurent memory allocations to filename.\n" },
    { "SetInputMode",                   bex_SetInputMode,                   METH_VARARGS, "bool SetInputMode(string device,string mode) \n  Establece el modo del dispositivo device.\n" },
    { "GetInputMode",                   bex_GetInputMode,                   METH_VARARGS, "string GetInputMode(string device) \n  Obtiene el modo del dispositivo device.\n" },
    { "SaveScreenShot",                 bex_SaveScreenShot,                 METH_VARARGS, "SaveScreenShot(filename,width,height) \n  Acaso necesita descripcion?\n" },
    { "CleanArea",                      bex_CleanArea,                      METH_VARARGS, "CleanArea(x,y,z,distance) \n  Limpia una zona esferica con centro en 'x,y,z'\ny distancia 'distance' de sangre.\n" },
    { NULL,                             NULL,                               0,            NULL },
};

static PyMethodDef entity_methods[] = {
    { "GetParticleEntity",              bex_ent_GetParticleEntity,          METH_VARARGS, NULL },
    { "SeverLimb",                      bex_ent_SeverLimb,                  METH_VARARGS, NULL },
    { "ResetWounds",                    bex_ent_ResetWounds,                METH_VARARGS, NULL },
    { "Impulse",                        bex_ent_Impulse,                    METH_VARARGS, NULL },
    { "ImpulseC",                       bex_ent_ImpulseC,                   METH_VARARGS, NULL },
    { "Fly",                            bex_ent_Fly,                        METH_VARARGS, NULL },
    { "SubscribeToList",                bex_ent_SubscribeToList,            METH_VARARGS, NULL },
    { "RemoveFromList",                 bex_ent_RemoveFromList,             METH_VARARGS, NULL },
    { "RemoveFromInvent",               bex_ent_RemoveFromInvent,           METH_VARARGS, NULL },
    { "RemoveFromInventRight",          bex_ent_RemoveFromInventRight,      METH_VARARGS, NULL },
    { "RemoveFromInventLeft",           bex_ent_RemoveFromInventLeft,       METH_VARARGS, NULL },
    { "RemoveFromInventLeft2",          bex_ent_RemoveFromInventLeft2,      METH_VARARGS, NULL },
    { "RemoveFromWorld",                bex_ent_RemoveFromWorld,            METH_VARARGS, NULL },
    { "RemoveFromWorldWithChilds",      bex_ent_RemoveFromWorldWithChilds,  METH_VARARGS, NULL },
    { "LaunchAnimation",                bex_ent_LaunchAnimation,            METH_VARARGS, NULL },
    { "LaunchAnimation2",               bex_ent_LaunchAnimation2,           METH_VARARGS, NULL },
    { "LaunchAnmType",                  bex_ent_LaunchAnmType,              METH_VARARGS, NULL },
    { "GotAnmType",                     bex_ent_GotAnmType,                 METH_VARARGS, NULL },
    { "SetMesh",                        bex_ent_SetMesh,                    METH_VARARGS, NULL },
    { "SetAnmFlags",                    bex_ent_SetAnmFlags,                METH_VARARGS, NULL },
    { "SetTmpAnmFlags",                 bex_ent_SetTmpAnmFlags,             METH_VARARGS, NULL },
    { "SetActiveEnemy",                 bex_ent_SetActiveEnemy,             METH_VARARGS, NULL },
    { "CanISee",                        bex_ent_CanISee,                    METH_VARARGS, NULL },
    { "CanISeeFrom",                    bex_ent_CanISeeFrom,                METH_VARARGS, NULL },
    { "InsideActionArea",               bex_ent_InsideActionArea,           METH_VARARGS, NULL },
    { "CheckAnimCol",                   bex_ent_CheckAnimCol,               METH_VARARGS, NULL },
    { "SetEnemy",                       bex_ent_SetEnemy,                   METH_VARARGS, NULL },
    { "GetEnemyName",                   bex_ent_GetEnemyName,               METH_VARARGS, NULL },
    { "Chase",                          bex_ent_Chase,                      METH_VARARGS, NULL },
    { "ResetChase",                     bex_ent_ResetChase,                 METH_VARARGS, NULL },
    { "GoTo",                           bex_ent_GoTo,                       METH_VARARGS, NULL },
    { "CanGoTo",                        bex_ent_CanGoTo,                    METH_VARARGS, NULL },
    { "QuickFace",                      bex_ent_QuickFace,                  METH_VARARGS, NULL },
    { "Face",                           bex_ent_Face,                       METH_VARARGS, NULL },
    { "LookAtEntity",                   bex_ent_LookAtEntity,               METH_VARARGS, NULL },
    { "StartLooking",                   bex_ent_StartLooking,               METH_VARARGS, NULL },
    { "StopLooking",                    bex_ent_StopLooking,                METH_VARARGS, NULL },
    { "AddWatchAnim",                   bex_ent_AddWatchAnim,               METH_VARARGS, NULL },
    { "GraspPos",                       bex_ent_GraspPos,                   METH_VARARGS, NULL },
    { "Freeze",                         bex_ent_Freeze,                     METH_VARARGS, NULL },
    { "UnFreeze",                       bex_ent_UnFreeze,                   METH_VARARGS, NULL },
    { "SwitchTo1H",                     bex_ent_SwitchTo1H,                 METH_VARARGS, NULL },
    { "SwitchToBow",                    bex_ent_SwitchToBow,                METH_VARARGS, NULL },
    { "LaunchBayRoute",                 bex_ent_LaunchBayRoute,             METH_VARARGS, NULL },
    { "LaunchWatch",                    bex_ent_LaunchWatch,                METH_VARARGS, NULL },
    { "GetActionMode",                  bex_ent_GetActionMode,              METH_VARARGS, NULL },
    { "StartGrabbing",                  bex_ent_StartGrabbing,              METH_VARARGS, NULL },
    { "StopGrabbing",                   bex_ent_StopGrabbing,               METH_VARARGS, NULL },
    { "LookAt",                         bex_ent_LookAt,                     METH_VARARGS, NULL },
    { "LookAtPerson",                   bex_ent_LookAtPerson,               METH_VARARGS, NULL },
    { "AddAnmEventFunc",                bex_ent_AddAnmEventFunc,            METH_VARARGS, NULL },
    { "DelAnmEventFunc",                bex_ent_DelAnmEventFunc,            METH_VARARGS, NULL },
    { "ClearAnmEventFuncs",             bex_ent_ClearAnmEventFuncs,         METH_VARARGS, NULL },
    { "AddAnimSound",                   bex_ent_AddAnimSound,               METH_VARARGS, NULL },
    { "AddEventSound",                  bex_ent_AddEventSound,              METH_VARARGS, NULL },
    { "SlideTo",                        bex_ent_SlideTo,                    METH_VARARGS, NULL },
    { "ClearPath",                      bex_ent_ClearPath,                  METH_VARARGS, NULL },
    { "StartPath",                      bex_ent_StartPath,                  METH_VARARGS, NULL },
    { "GoToPath",                       bex_ent_GoToPath,                   METH_VARARGS, NULL },
    { "TurnOn",                         bex_ent_TurnOn,                     METH_VARARGS, NULL },
    { "TurnOff",                        bex_ent_TurnOff,                    METH_VARARGS, NULL },
    { "AddPathNode",                    bex_ent_AddPathNode,                METH_VARARGS, NULL },
    { "SetNodeStartTangent",            bex_ent_SetNodeStartTangent,        METH_VARARGS, NULL },
    { "SetNodeEndTangent",              bex_ent_SetNodeEndTangent,          METH_VARARGS, NULL },
    { "Rotate",                         bex_ent_Rotate,                     METH_VARARGS, NULL },
    { "RotateAbs",                      bex_ent_RotateAbs,                  METH_VARARGS, NULL },
    { "RotateRel",                      bex_ent_RotateRel,                  METH_VARARGS, NULL },
    { "Move",                           bex_ent_Move,                       METH_VARARGS, NULL },
    { "SetPosition",                    bex_ent_SetPosition,                METH_VARARGS, NULL },
    { "SetOrientation",                 bex_ent_SetOrientation,             METH_VARARGS, NULL },
    { "PutToWorld",                     bex_ent_PutToWorld,                 METH_VARARGS, NULL },
    { "GetInventoryEntity",             bex_ent_GetInventoryEntity,         METH_VARARGS, NULL },
    { "GetInventorySelected",           bex_ent_GetInventorySelected,       METH_VARARGS, NULL },
    { "GetInventory",                   bex_ent_GetInventory,               METH_VARARGS, NULL },
    { "Use",                            bex_ent_Use,                        METH_VARARGS, NULL },
    { "SetSound",                       bex_ent_SetSound,                   METH_VARARGS, NULL },
    { "SetObjectSound",                 bex_ent_SetObjectSound,             METH_VARARGS, NULL },
    { "PlaySound",                      bex_ent_PlaySound,                  METH_VARARGS, NULL },
    { "StopSound",                      bex_ent_StopSound,                  METH_VARARGS, NULL },
    { "Stop",                           bex_ent_StopSound,                  METH_VARARGS, NULL },
    { "MessageEvent",                   bex_ent_MessageEvent,               METH_VARARGS, NULL },
    { "Rel2AbsPoint",                   bex_ent_Rel2AbsPoint,               METH_VARARGS, NULL },
    { "Rel2AbsVector",                  bex_ent_Rel2AbsVector,              METH_VARARGS, NULL },
    { "Abs2RelPoint",                   bex_ent_Abs2RelPoint,               METH_VARARGS, NULL },
    { "Abs2RelVector",                  bex_ent_Abs2RelVector,              METH_VARARGS, NULL },
    { "GetDummyAxis",                   bex_ent_GetDummyAxis,               METH_VARARGS, NULL },
    { "SQDistance2",                    bex_ent_SQDistance2,                METH_VARARGS, NULL },
    { "CatchOnFire",                    bex_ent_CatchOnFire,                METH_VARARGS, NULL },
    { "ExcludeHitFor",                  bex_ent_ExcludeHitFor,              METH_VARARGS, NULL },
    { "Unlink",                         bex_ent_Unlink,                     METH_VARARGS, NULL },
    { "Link",                           bex_ent_Link,                       METH_VARARGS, NULL },
    { "LinkToNode",                     bex_ent_LinkToNode,                 METH_VARARGS, NULL },
    { "LinkAnchors",                    bex_ent_LinkAnchors,                METH_VARARGS, NULL },
    { "GetNodeIndex",                   bex_ent_GetNodeIndex,               METH_VARARGS, NULL },
    { "GetNChildren",                   bex_ent_GetNChildren,               METH_VARARGS, NULL },
    { "GetChild",                       bex_ent_GetChild,                   METH_VARARGS, NULL },
    { "AddCameraEvent",                 bex_ent_AddCameraEvent,             METH_VARARGS, NULL },
    { "RemoveCameraEvent",              bex_ent_RemoveCameraEvent,          METH_VARARGS, NULL },
    { "AddCameraNode",                  bex_ent_AddCameraNode,              METH_VARARGS, NULL },
    { "SetCameraStartTangentNode",      bex_ent_SetCameraStartTangentNode,  METH_VARARGS, NULL },
    { "SetCameraEndTangentNode",        bex_ent_SetCameraEndTangentNode,    METH_VARARGS, NULL },
    { "SetTravellingView",              bex_ent_SetTravellingView,          METH_VARARGS, NULL },
    { "SetPersonView",                  bex_ent_SetPersonView,              METH_VARARGS, NULL },
    { "CameraClearPath",                bex_ent_CameraClearPath,            0,            NULL },
    { "CameraStartPath",                bex_ent_CameraStartPath,            0,            NULL },
    { "SetMaxCamera",                   bex_ent_SetMaxCamera,               METH_VARARGS, NULL },
    { "Cut",                            bex_ent_Cut,                        METH_VARARGS, NULL },
    { "DoAction",                       bex_ent_DoAction,                   METH_VARARGS, NULL },
    { "DoActionWI",                     bex_ent_DoActionWI,                 METH_VARARGS, NULL },
    { "SetOnFloor",                     bex_ent_SetOnFloor,                 METH_VARARGS, NULL },
    { "RaiseEvent",                     bex_ent_RaiseEvent,                 METH_VARARGS, NULL },
    { "SetWoundedZone",                 bex_ent_SetWoundedZone,             METH_VARARGS, NULL },
    { "GetWoundedZone",                 bex_ent_GetWoundedZone,             METH_VARARGS, NULL },
    { "InterruptCombat",                bex_ent_InterruptCombat,            METH_VARARGS, NULL },
    { "GetGroupMembers",                bex_ent_GetGroupMembers,            METH_VARARGS, NULL },
    { "GetCombatants",                  bex_ent_GetCombatants,              METH_VARARGS, NULL },
    { "ExcludeHitInAnimationFor",       bex_ent_ExcludeHitInAnimationFor,   METH_VARARGS, NULL },
    { "TestPos",                        bex_ent_TestPos,                    METH_VARARGS, NULL },
    { "TestPosInOwnBox",                bex_ent_TestPosInOwnBox,            METH_VARARGS, NULL },
    { "UnlinkChildren",                 bex_ent_UnlinkChildren,             METH_VARARGS, NULL },
    { "SetNextAttack",                  bex_ent_SetNextAttack,              METH_VARARGS, NULL },
    { "SetAuraActive",                  bex_ent_SetAuraActive,              METH_VARARGS, NULL },
    { "SetAuraParams",                  bex_ent_SetAuraParams,              METH_VARARGS, NULL },
    { "SetAuraGradient",                bex_ent_SetAuraGradient,            METH_VARARGS, NULL },
    { "IsValid",                        bex_ent_IsValid,                    METH_VARARGS, NULL },
    { NULL,                             NULL,                               0,            NULL },
};

static PyMethodDef inventory_methods[] = {
    { "LinkRightHand",                  bex_inv_LinkRightHand,              METH_VARARGS, NULL },
    { "LinkLeftHand",                   bex_inv_LinkLeftHand,               METH_VARARGS, NULL },
    { "LinkLeftHand2",                  bex_inv_LinkLeftHand2,              METH_VARARGS, NULL },
    { "LinkRight",                      bex_inv_LinkRightHand,              METH_VARARGS, NULL },
    { "LinkLeft",                       bex_inv_LinkLeftHand,               METH_VARARGS, NULL },
    { "LinkRightBack",                  bex_inv_LinkRightBack,              METH_VARARGS, NULL },
    { "LinkLeftBack",                   bex_inv_LinkLeftBack,               METH_VARARGS, NULL },
    { "LinkBack",                       bex_inv_LinkBack,                   METH_VARARGS, NULL },
    { "SetCurrentQuiver",               bex_inv_SetCurrentQuiver,           METH_VARARGS, NULL },
    { "AddObject",                      bex_inv_AddObject,                  METH_VARARGS, NULL },
    { "RemoveObject",                   bex_inv_RemoveObject,               METH_VARARGS, NULL },
    { "GetObject",                      bex_inv_GetObject,                  METH_VARARGS, NULL },
    { "GetSelectedObject",              bex_inv_GetSelectedObject,          METH_VARARGS, NULL },
    { "CycleObjects",                   bex_inv_CycleObjects,               METH_VARARGS, NULL },
    { "GetNumberObjectsAt",             bex_inv_GetNumberObjectsAt,         METH_VARARGS, NULL },
    { "GetMaxNumberObjectsAt",          bex_inv_GetMaxNumberObjectsAt,      METH_VARARGS, NULL },
    { "IsObjectSelected",               bex_inv_IsObjectSelected,           METH_VARARGS, NULL },
    { "AddShield",                      bex_inv_AddShield,                  METH_VARARGS, NULL },
    { "RemoveShield",                   bex_inv_RemoveShield,               METH_VARARGS, NULL },
    { "GetShield",                      bex_inv_GetShield,                  METH_VARARGS, NULL },
    { "GetSelectedShield",              bex_inv_GetSelectedShield,          METH_VARARGS, NULL },
    { "GetActiveShield",                bex_inv_GetActiveShield,            METH_VARARGS, NULL },
    { "CycleShields",                   bex_inv_CycleShields,               METH_VARARGS, NULL },
    { "IsShieldSelected",               bex_inv_IsShieldSelected,           METH_VARARGS, NULL },
    { "AddWeapon",                      bex_inv_AddWeapon,                  METH_VARARGS, NULL },
    { "RemoveWeapon",                   bex_inv_RemoveWeapon,               METH_VARARGS, NULL },
    { "AddBow",                         bex_inv_AddBow,                     METH_VARARGS, NULL },
    { "RemoveBow",                      bex_inv_RemoveBow,                  METH_VARARGS, NULL },
    { "AddMagicShield",                 bex_inv_AddMagicShield,             METH_VARARGS, NULL },
    { "RemoveMagicShield",              bex_inv_RemoveMagicShield,          METH_VARARGS, NULL },
    { "GetMagicShield",                 bex_inv_GetMagicShield,             METH_VARARGS, NULL },
    { "GetWeapon",                      bex_inv_GetWeapon,                  METH_VARARGS, NULL },
    { "GetSelectedWeapon",              bex_inv_GetSelectedWeapon,          METH_VARARGS, NULL },
    { "GetActiveWeapon",                bex_inv_GetActiveWeapon,            METH_VARARGS, NULL },
    { "CycleWeapons",                   bex_inv_CycleWeapons,               METH_VARARGS, NULL },
    { "IsWeaponSelected",               bex_inv_IsWeaponSelected,           METH_VARARGS, NULL },
    { "GetBow",                         bex_inv_GetBow,                     METH_VARARGS, NULL },
    { "AddQuiver",                      bex_inv_AddQuiver,                  METH_VARARGS, NULL },
    { "RemoveQuiver",                   bex_inv_RemoveQuiver,               METH_VARARGS, NULL },
    { "GetQuiver",                      bex_inv_GetQuiver,                  METH_VARARGS, NULL },
    { "GetSelectedQuiver",              bex_inv_GetSelectedQuiver,          METH_VARARGS, NULL },
    { "GetActiveQuiver",                bex_inv_GetActiveQuiver,            METH_VARARGS, NULL },
    { "CycleQuivers",                   bex_inv_CycleQuivers,               METH_VARARGS, NULL },
    { "IsQuiverSelected",               bex_inv_IsQuiverSelected,           METH_VARARGS, NULL },
    { "AddKey",                         bex_inv_AddKey,                     METH_VARARGS, NULL },
    { "RemoveKey",                      bex_inv_RemoveKey,                  METH_VARARGS, NULL },
    { "GetKey",                         bex_inv_GetKey,                     METH_VARARGS, NULL },
    { "GetSelectedKey",                 bex_inv_GetSelectedKey,             METH_VARARGS, NULL },
    { "CycleKeys",                      bex_inv_CycleKeys,                  METH_VARARGS, NULL },
    { "IsKeySelected",                  bex_inv_IsKeySelected,              METH_VARARGS, NULL },
    { "AddSpecialKey",                  bex_inv_AddSpecialKey,              METH_VARARGS, NULL },
    { "RemoveSpecialKey",               bex_inv_RemoveSpecialKey,           METH_VARARGS, NULL },
    { "GetSpecialKey",                  bex_inv_GetSpecialKey,              METH_VARARGS, NULL },
    { "AddTablet",                      bex_inv_AddTablet,                  METH_VARARGS, NULL },
    { "RemoveTablet",                   bex_inv_RemoveTablet,               METH_VARARGS, NULL },
    { "GetTablet",                      bex_inv_GetTablet,                  METH_VARARGS, NULL },
    { "GetRightBack",                   bex_inv_GetRightBack,               METH_VARARGS, NULL },
    { "GetLeftBack",                    bex_inv_GetLeftBack,                METH_VARARGS, NULL },
    { "CarringObject",                  bex_inv_CarringObject,              METH_VARARGS, NULL },
    { NULL,                             NULL,                               0,            NULL },
};

static PyMethodDef material_methods[] = {
    { "AddHitSoundComb",                bex_mat_AddHitSoundComb,            METH_VARARGS, NULL },
    { NULL,                             NULL,                               0,            NULL },
};


static PyMethodDef route_methods[] = {
    { "AddPoint",                       bex_route_AddPoint,                 METH_VARARGS, NULL },
    { NULL,                             NULL,                               0,            NULL },
};


static PyMethodDef sector_methods[] = {
    { "InitBreak",                      bex_sec_InitBreak,                  METH_VARARGS, NULL },
    { "DoBreak",                        bex_sec_DoBreak,                    METH_VARARGS, NULL },
    { "SetSurfaceTexture",              bex_sec_SetSurfaceTexture,          METH_VARARGS, NULL },
    { "GetSurfaceTexture",              bex_sec_GetSurfaceTexture,          METH_VARARGS, NULL },
    { "SetSurfaceTextureZoomX",         bex_sec_SetSurfaceTextureZoomX,     METH_VARARGS, NULL },
    { "GetSurfaceTextureZoomX",         bex_sec_GetSurfaceTextureZoomX,     METH_VARARGS, NULL },
    { "SetSurfaceTextureZoomY",         bex_sec_SetSurfaceTextureZoomY,     METH_VARARGS, NULL },
    { "GetSurfaceTextureZoomY",         bex_sec_GetSurfaceTextureZoomY,     METH_VARARGS, NULL },
    { "SetSurfaceTextureX",             bex_sec_SetSurfaceTextureX,         METH_VARARGS, NULL },
    { "GetSurfaceTextureX",             bex_sec_GetSurfaceTextureX,         METH_VARARGS, NULL },
    { "SetSurfaceTextureY",             bex_sec_SetSurfaceTextureY,         METH_VARARGS, NULL },
    { "GetSurfaceTextureY",             bex_sec_GetSurfaceTextureY,         METH_VARARGS, NULL },
    { "GetSpecularLight",               bex_sec_GetSpecularLight,           METH_VARARGS, NULL },
    { "SetSpecularLight",               bex_sec_SetSpecularLight,           METH_VARARGS, NULL },
    { "GetSpecularShininess",           bex_sec_GetSpecularShininess,       METH_VARARGS, NULL },
    { "SetSpecularShininess",           bex_sec_SetSpecularShininess,       METH_VARARGS, NULL },
    { "GetSelfLight",                   bex_sec_GetSelfLight,               METH_VARARGS, NULL },
    { "SetSelfLight",                   bex_sec_SetSelfLight,               METH_VARARGS, NULL },
    { NULL,                             NULL,                               0,            NULL },
};

static PyMethodDef sound_methods[] = {
    { "Play",                           bex_snd_Play,                       METH_VARARGS, NULL },
    { "PlayStereo",                     bex_snd_PlayStereo,                 METH_VARARGS, NULL },
    { "SetPitchVar",                    bex_snd_SetPitchVar,                METH_VARARGS, NULL },
    { "AddAltSound",                    bex_snd_AddAltSound,                METH_VARARGS, NULL },
    { "Stop",                           bex_snd_Stop,                       METH_VARARGS, NULL },
    { NULL,                             NULL,                               0,            NULL },
};



// address: 0x10001000
PyObject *bex_ExportWorld(PyObject *self, PyObject *args) {
        const char *world;
        int ret = 0;

        if (PyArg_ParseTuple(args, "s", &world))
                ret = WorldToMBW(world);

        return Py_BuildValue("i", ret);
}


// address: 0x1000104d
PyObject *bex_SoundSystemActive(PyObject *self, PyObject *args) {

        if (SoundSystemActive() != 1) {
                return Py_BuildValue("i", 0);
        } else {
                return Py_BuildValue("i", 1);
        }
}


// address: 0x10001086
PyObject *bex_SetSSFrecuency(PyObject *self, PyObject *args) {
        int frequency, ret;

        if (!PyArg_ParseTuple(args, "i", &frequency))
                return NULL;

        ret = SetSSFrecuency(frequency);

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x100010e6
PyObject *bex_SetSS2dChannels(PyObject *self, PyObject *args) {
        int num_ch, ret;

        if (!PyArg_ParseTuple(args, "i", &num_ch))
                return NULL;

        ret = SetSS2dChannels(num_ch);

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x10001146
PyObject *bex_SetSS3dChannels(PyObject *self, PyObject *args) {
        int num_ch, ret;

        if (!PyArg_ParseTuple(args, "i", &num_ch))
                return NULL;

        ret = SetSS3dChannels(num_ch);

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x100011a6
PyObject *bex_SetSSFilter(PyObject *self, PyObject *args) {
        int filter_output, ret;

        if (!PyArg_ParseTuple(args, "i", &filter_output))
                return NULL;

        ret = SetSSFilter(filter_output);

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x10001206
PyObject *bex_KillMusic(PyObject *self, PyObject *args) {
        int ret;

        ret = KillMusic();

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000123f
PyObject *bex_ShutDownSoundChannels(PyObject *self, PyObject *args) {
        int ret;

        ret = ShutDownSoundChannels();

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x10001278
PyObject *bex_PauseSoundSystem(PyObject *self, PyObject *args) {
        int ret;

        ret = PauseSoundSystem();

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x100012b1
PyObject *bex_PauseSoundSystemButMusic(PyObject *self, PyObject *args) {
        int ret;

        ret = PauseSoundSystemButMusic();

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x100012ea
PyObject *bex_ResumeSoundSystem(PyObject *self, PyObject *args) {
        int ret;

        ret = ResumeSoundSystem();

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x10001323
PyObject *bex_SetMusicVolume(PyObject *self, PyObject *args) {
        double volume = 1.0;
        int ret;

        if (!PyArg_ParseTuple(args, "d", &volume))
                return NULL;

        ret = SetMusicVolume(volume);
        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x10001397
PyObject *bex_GetMusicVolume(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("d", GetMusicVolume());
}


// address: 0x100013da
PyObject *bex_SetSoundVolume(PyObject *self, PyObject *args) {
        double volume = 1.0;

        if (!PyArg_ParseTuple(args, "d", &volume))
                return NULL;

        return Py_BuildValue("i", SetSoundVolume(volume));
}


// address: 0x10001436
PyObject *bex_GetSoundVolume(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("d", GetSoundVolume());
}


// address: 0x10001479
PyObject *bex_GetSpeakerConfig(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetSSSpeakerConfig());
}


// address: 0x100014b6
PyObject *bex_SetEAXOverride(PyObject *self, PyObject *args) {
        int EAXOverride = 1;

        if (!PyArg_ParseTuple(args, "i", &EAXOverride))
                return NULL;

        return Py_BuildValue("i", SetEAXOverride(EAXOverride));
}


// address: 0x10001507
PyObject *bex_GetEAXOverride(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetEAXOverride());
}


// address: 0x10001544
PyObject *bex_SaveSSConfig(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", SaveSSConfig());
}


// address: 0x10001581
PyObject *bex_SetSpeakerConfig(PyObject *self, PyObject *args) {
        int config = 1;

        if (!PyArg_ParseTuple(args, "i", &config))
                return NULL;

        return Py_BuildValue("i", SetSSSpeakerConfig(config));
}


// address: 0x100015d2
PyObject *bex_GetSSQuality(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetSSQuality());
}


// address: 0x1000160f
PyObject *bex_SetSSQuality(PyObject *self, PyObject *args) {
        int SSQuality = 1;

        if (!PyArg_ParseTuple(args, "i", &SSQuality))
                return NULL;

        return Py_BuildValue("i", SetSSQuality(SSQuality));
}


// address: 0x10001660
PyObject *bex_SetAutoGenTexture(PyObject *self, PyObject *args) {
        const char *textureName;
        int textureEffect;

        if (!PyArg_ParseTuple(args, "si", &textureName, &textureEffect))
                return NULL;

        return Py_BuildValue("i", SetAutoGenTexture(textureName, textureEffect));
}


// address: 0x100016b2
PyObject *bex_SetBloodLevel(PyObject *self, PyObject *args) {
        double blood_level = 1.0;

        if (!PyArg_ParseTuple(args, "d", &blood_level))
                return NULL;

        return Py_BuildValue("i", SetBloodLevel(blood_level));
}


// address: 0x1000170f
PyObject *bex_GetBloodLevel(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetBloodLevel());
}


// address: 0x1000174c
PyObject *bex_SetMutilationLevel(PyObject *self, PyObject *args) {
        double mutilation_level = 1.0;

        if (!PyArg_ParseTuple(args, "d", &mutilation_level))
                return NULL;

        return Py_BuildValue("i", SetMutilationLevel(mutilation_level));
}


// address: 0x100017a9
PyObject *bex_GetMutilationLevel(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetMutilationLevel());
}


// address: 0x100017e6
PyObject *bex_GetWorldFileName(PyObject *self, PyObject *args) {
        const char *world_file_name;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        world_file_name = GetWorldFileName();
        if (!world_file_name) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", world_file_name);
}


// address: 0x10001842
PyObject *bex_AddTranTime(PyObject *self, PyObject *args) {
        const char *biped_name, *next_anm , *prev_anm;
        double time;
        int unknown = 1;

        if (!PyArg_ParseTuple(
                args, "sssd|i", &biped_name, &next_anm , &prev_anm, &time,
                &unknown)
        )
                return NULL;

        return Py_BuildValue(
                "i",
                AddTranTime(biped_name, next_anm , prev_anm, time, unknown)
        );
}


// address: 0x100018b7
PyObject *bex_CheckAnims(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", CheckAnims());
}


// address: 0x100018f4
PyObject *bex_GiveAnims(PyObject *self, PyObject *args) {
        const char *race_name;

        if (!PyArg_ParseTuple(args, "s", &race_name))
                return NULL;

        return Py_BuildValue("i", GiveAnims(race_name));
}


// address: 0x1000193e
PyObject *bex_GetAnimationDuration(PyObject *self, PyObject *args) {
        const char *animation_name;
        double duration;
        int ret;

        if (!PyArg_ParseTuple(args, "s", &animation_name))
                return NULL;

        ret = GetAnimationDuration(animation_name, &duration);
        if (!ret)
                return Py_BuildValue("d", 0.0);

        return Py_BuildValue("d", duration);
}


// address: 0x100019aa
PyObject *bex_SetAnimationFactor(PyObject *self, PyObject *args) {
        const char *mov;
        double new_speed_factor;

        if (!PyArg_ParseTuple(args, "sd", &mov, &new_speed_factor))
                return NULL;

        return Py_BuildValue("i", SetAnimationFactor(mov, new_speed_factor));
}


// address: 0x10001a00
PyObject *bex_SetTurnSpeed(PyObject *self, PyObject *args) {
        const char *race_name;
        double new_speed;

        if (!PyArg_ParseTuple(args, "sd", &race_name, &new_speed))
                return NULL;

        SetTurnSpeed(race_name, new_speed);

        return Py_BuildValue("i", 1);
}


// address: 0x10001a51
PyObject *bex_CreateEntity(PyObject *self, PyObject *args) {
        const char *name, *kind, *parent_class = "", *unknown = NULL;
        int i_unknown;
        double d_unknown1, d_unknown2 = 0.0;
        double x, y, z;
        PyObject *type, *value, *traceback;

        if (
                PyArg_ParseTuple(
                        args, "ssddd|ss", &name, &kind, &x, &y, &z,
                        &parent_class, &unknown
                )
        ) {
                return create_entity(name, kind, x, y, z, parent_class, unknown);
        }

        PyErr_Fetch(&type, &value, &traceback);

        PyErr_Clear();

        if (
                !PyArg_ParseTuple(
                        args, "ssdddid|d", &name, &kind, &x, &y, &z, &i_unknown,
                        &d_unknown1, &d_unknown2
                ) ||
                strcmp(kind, "Entity Decal")
        ) {
                PyErr_Restore(type, value, traceback);
                return NULL;
        }

        return create_entity_decal(
                name, x, y, z, i_unknown, d_unknown1, d_unknown2
        );
}


// address: 0x10001ba3
PyObject *bex_DeleteEntity(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity;
        const char *name;
        PyObject *type, *value, *traceback;

        if (PyArg_ParseTuple(args, "s", &name))
                return Py_BuildValue("i", DeleteEntity(name));

        PyErr_Fetch(&type, &value, &traceback);
        PyErr_Clear();

        if (PyArg_ParseTuple(args, "O", &entity))
                return Py_BuildValue("i", DeleteEntity(entity->name));

        PyErr_Restore(type, value, traceback);
        return NULL;
}


// address: 0x10001c5e
PyObject *bex_GetEntity(PyObject *self, PyObject *args) {
        const char *name;
        int index;
        PyObject *entity;

        if (!PyArg_ParseTuple(args, "s", &name)) {
                PyErr_Clear();

                if (!PyArg_ParseTuple(args, "i", &index))
                        return NULL;

                entity = get_entity_by_index(index);
                if (entity == NULL) {
                        Py_INCREF(Py_None);
                        return Py_None;
                }
        } else {
                entity = get_entity_by_name(name);
                if (entity == NULL) {
                        Py_INCREF(Py_None);
                        return Py_None;
                }
        }

        return entity;
}


// address: 0x10001d0a
PyObject *bex_CreateSpark(PyObject *self, PyObject *args) {
        const char *name;
        double x, y, z, x_spark_dir, y_spark_dir, z_spark_dir, d_unknown1;
        double d_unknown2, d_unknown3, d_unknown4, d_unknown5;
        int i_unknown6, i_unknown7, i_unknown8, i_unknown9;
        int i_unknown10, i_unknown11, i_unknown15;
        double d_unknown12, d_unknown13, d_unknown14;

        if (!PyArg_ParseTuple(
                args, "sdddddddddddiiiiiidddi", &name, &x, &y, &z, &x_spark_dir,
                &y_spark_dir, &z_spark_dir, &d_unknown1, &d_unknown2,
                &d_unknown3, &d_unknown4, &d_unknown5, &i_unknown6, &i_unknown7,
                &i_unknown8, &i_unknown9, &i_unknown10, &i_unknown11,
                &d_unknown12, &d_unknown13, &d_unknown14, &i_unknown15
        ))
                return NULL;


        return create_spark(
                name, x, y, z, x_spark_dir, y_spark_dir, z_spark_dir,
                d_unknown1, d_unknown2, d_unknown3, d_unknown4, d_unknown5,
                i_unknown6, i_unknown7, i_unknown8, i_unknown9, i_unknown10,
                i_unknown11, d_unknown12, d_unknown13, d_unknown14, i_unknown15
        );
}


// address: 0x10001e46
PyObject *bex_SetListenerPosition(PyObject *self, PyObject *args) {
        int mode;
        double x = 0.0, y = 0.0, z = 0.0;

        if (!PyArg_ParseTuple(args, "i|ddd", &mode, &x, &y, &z))
                return NULL;

        return Py_BuildValue("i", SetListenerMode(mode, x, y, z));
}


// address: 0x10001ee7
PyObject *bex_GetSector(PyObject *self, PyObject *args) {
        int index;
        double x, y, z;
        PyObject *sector;

        if (!PyArg_ParseTuple(args, "i", &index)) {
                PyErr_Clear();

                if (!PyArg_ParseTuple(args, "ddd", &x, &y, &z))
                        return NULL;

                sector = get_sector_by_position(x, y, z);
                if (sector == NULL) {
                        Py_INCREF(Py_None);
                        return Py_None;
                }

        } else {
                sector = get_sector_by_index(index);
                if (sector == NULL) {
                        Py_INCREF(Py_None);
                        return Py_None;
                }
        }
        return sector;
}


// address: 0x10001faf
PyObject *bex_GetCharType(PyObject *self, PyObject *args) {
        const char *name, *short_name;
        PyObject *character;

        if (!PyArg_ParseTuple(args, "ss", &name, &short_name))
                return NULL;


        character = get_char_by_name(name, short_name);
        if (character == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return character;
}


// address: 0x10002011
PyObject *bex_GetTrailType(PyObject *self, PyObject *args) {
        const char *name;
        PyObject *trail;

        if (!PyArg_ParseTuple(args, "s", &name))
                return NULL;

        trail = get_trail_type(name);
        if (trail == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return trail;
}


// address: 0x1000206a
PyObject *bex_CreateRoute(PyObject *self, PyObject *args) {
        PyObject *route;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        route = create_route();
        if (route == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return route;
}


// address: 0x100020b6
PyObject *bex_CreateSound(PyObject *self, PyObject *args) {
        const char * file_name;
        const char * sound_name;
        PyObject *sound;

        if (!PyArg_ParseTuple(args, "ss", &file_name, &sound_name))
                return NULL;

        sound = create_sound(file_name, sound_name);
        if (sound == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return sound;
}


// address: 0x10002118
PyObject *bex_CreateTimer(PyObject *self, PyObject *args) {
        const char *timer_name;
        double period;

        if (!PyArg_ParseTuple(args, "sd", &timer_name, &period))
                return NULL;

        return Py_BuildValue("i", CreateTimer(timer_name, period));
}


// address: 0x1000216e
PyObject *bex_GetnTimers(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetnTimers());
}


// address: 0x100021ab
PyObject *bex_GetTimerInfo(PyObject *self, PyObject *args) {
        int timer_index;
        const char *timer_name;
        double period;
        PyObject *tuple, *nameObj, *periodObj;

        if (!PyArg_ParseTuple(args, "i", &timer_index))
                return NULL;

        if (!GetTimerInfo(timer_index, &timer_name, &period)) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        tuple = PyTuple_New(2);

        nameObj = PyString_FromString(timer_name);
        periodObj = PyFloat_FromDouble(period);

        PyTuple_SET_ITEM(tuple, 0, nameObj);
        PyTuple_SET_ITEM(tuple, 1, periodObj);

        return tuple;
}


// address: 0x10002255
PyObject *bex_AddScheduledFunc(PyObject *self, PyObject *args) {
        double time;
        PyObject *func, *func_args;
        const char *name = "Unnamed";

        if (!PyArg_ParseTuple(args, "dOO|s", &time, &func, &func_args, &name))
                return NULL;

        return Py_BuildValue("i", AddScheduledFunc(time, func, func_args, name));
}

// address: 0x100022c2
PyObject *bex_RemoveScheduledFunc(PyObject *self, PyObject *args) {
        const char *name;

        if (!PyArg_ParseTuple(args, "s", &name))
                return NULL;

        return Py_BuildValue("i", RemoveScheduledFunc(name));
}

// address: 0x1000230c
PyObject *bex_GetnScheduledFuncs(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetnScheduledFuncs());
}

// address: 0x10002349
PyObject *bex_GetScheduledFunc(PyObject * self, PyObject *args) {
        int index, ret;
        PyObject *func, *arg;
        const char *name;
        double time;
        PyObject *tuple, *nameObj, *timeObj;

        if (!PyArg_ParseTuple(args, "i", &index))
                return NULL;

        if ((ret = GetScheduledFunc(index, &func, &arg, &name, &time)) != 0) {
                assert(func);
                assert(arg);
                assert(name);

                tuple = PyTuple_New(4);

                nameObj = PyString_FromString(name);
                timeObj = PyFloat_FromDouble(time);

                Py_INCREF(func);
                Py_INCREF(arg);
                Py_INCREF(nameObj);
                Py_INCREF(timeObj);

                PyTuple_SET_ITEM(tuple, 0, func);
                PyTuple_SET_ITEM(tuple, 1, arg);
                PyTuple_SET_ITEM(tuple, 2, nameObj);
                PyTuple_SET_ITEM(tuple, 3, timeObj);

                return tuple;
        }
        
        return Py_BuildValue("i", ret);
}

// address: 0x10002499
PyObject *bex_nEntities(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", nEntities());
}

// address: 0x100024d6
PyObject *bex_nSectors(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i",  nSectors());
}

// address: 0x10002513
PyObject *bex_GetTime(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("d", GetTime());
}

// address: 0x10002556
PyObject *bex_SetTime(PyObject *self, PyObject *args) {
        double time;

        if(!PyArg_ParseTuple(args, "d", &time))
                return NULL;

        return Py_BuildValue("i", SetTime(time));
}

// address: 0x100025a4
PyObject *bex_GoToTime(PyObject *self, PyObject *args) {
        double time;

        if(!PyArg_ParseTuple(args, "d", &time))
                return NULL;

        return Py_BuildValue("i", GoToTime(time));
}

// address: 0x100025f2
PyObject *bex_StopTime(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        StopTime();

        Py_INCREF(Py_None);
        return Py_None;
}

// address: 0x1000262e
PyObject *bex_RestartTime(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        RestartTime();

        Py_INCREF(Py_None);
        return Py_None;
}

// address: 0x1000266a
PyObject *bex_GetTimeSpeed(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("d", GetTimeSpeed());
}

// address: 0x100026ad
PyObject *bex_SetTimeSpeed(PyObject *self, PyObject *args) {
        double speed;

        if(!PyArg_ParseTuple(args, "d", &speed))
                return NULL;

        SetTimeSpeed(speed);
    
        return Py_BuildValue("i", 1);
}

// address: 0x100026f6
PyObject *bex_GetNewExclusionGroupId(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetNewExclusionGroupId());
}

// address: 0x10002733
PyObject *bex_AssocKey(PyObject *self, PyObject *args) {
        const char *action, *input_device, *key;
        int press = 1;

        if(!PyArg_ParseTuple(args, "sss|i", &action, &input_device, &key, &press))
                return NULL;

        return Py_BuildValue("i", AssocKey(action, input_device, key, press));
}


// address: 0x1000279C
PyObject* bex_GetTimeActionHeld(PyObject* self, PyObject* args) {
        const char *action_name;

        if(!PyArg_ParseTuple(args, "s", &action_name))
                return NULL;

        return Py_BuildValue("d", GetTimeActionHeld(action_name));
}


// address: 0x100027EA
PyObject* bex_AddInputAction(PyObject* self, PyObject* args) {
        const char *action_name;
        int npi;

        if(!PyArg_ParseTuple(args, "si", &action_name, &npi))
                return NULL;

        return Py_BuildValue("i", AddInputAction(action_name, npi));
}


// address: 0x1000283C
PyObject* bex_RemoveInputAction(PyObject* self, PyObject* args) {
        const char *action_name;

        if(!PyArg_ParseTuple(args, "s", &action_name))
                return NULL;

        return Py_BuildValue("i", RemoveInputAction(action_name));
}


// address: 0x10002886
PyObject *bex_AddBoundFunc(PyObject *self, PyObject *args) {
        const char *action_name;
        const char *predproc;
        PyObject *proc;

        if(!PyArg_ParseTuple(args, "ss", &action_name, &predproc)) {
                PyErr_Clear();

                if(!PyArg_ParseTuple(args, "sO", &action_name, &proc))
                        return NULL;

                return Py_BuildValue("i", Bind(action_name, proc));
        }

        return Py_BuildValue("i", BindPred(action_name, predproc));
}


// address: 0x10002924
PyObject *bex_Bind2(PyObject *self, PyObject *args) {
        const char *action_name1, *action_name2, *new_action;
        int unknown = 100;

        if(!PyArg_ParseTuple(args, "sss|i", &action_name1, &action_name2, &new_action, &unknown))
                return NULL;

        PyErr_Clear();

        return Py_BuildValue(
                "i",
                Bind2(action_name1, action_name2, new_action, unknown)
        );
}


// address: 0x10002993
PyObject *bex_RemoveBoundFunc(PyObject *self, PyObject *args) {
        const char *action_name, *predproc;
        PyObject *proc;

        if(!PyArg_ParseTuple(args, "ss", &action_name, &predproc)) {
                PyErr_Clear();

                if(!PyArg_ParseTuple(args, "sO", &action_name, &proc))
                        return NULL;

                return Py_BuildValue("i", UnBind(action_name, proc));
        }

        return Py_BuildValue("i", UnBindPred(action_name, predproc));
}


// address: 0x10002A31
PyObject *bex_UnBindAll(PyObject* self, PyObject* args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        UnBindAll();

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x10002a6d
PyObject *bex_Input(PyObject *self, PyObject *args) {
        const char *output;
        const char *text;

        if(!PyArg_ParseTuple(args, "s", &text))
                return NULL;

        output = Input(text);
        if (output == NULL)
            return Py_BuildValue("i", 0);

        return Py_BuildValue("s", output);
}


// address: 0x10002ACF
PyObject *bex_LoadLevel(PyObject* self, PyObject* args) {
        const char *dir_name;

        if(!PyArg_ParseTuple(args, "s", &dir_name))
                return NULL;

        MarkLevelToLoad(dir_name);

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x10002b19
PyObject *bex_ReadLevel(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        ReadLevel(file_name);

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x10002b63
PyObject *bex_CloseLevel(PyObject *self, PyObject *args) {
        const char *statement1 = NULL, *statement2 = NULL;

        if(!PyArg_ParseTuple(args, "|ss", &statement1, &statement2))
                return NULL;

        CloseLevel(statement1, statement2);

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x10002bc6
PyObject *bex_PlaySound(PyObject *self, PyObject *args) {
        int soundId, unknown = 0;
        double x, y, z;

        if(!PyArg_ParseTuple(args, "iddd|i", &soundId, &x, &y, &z, &unknown))
                return NULL;

        return Py_BuildValue("i", OutSound(soundId, x, y, z, unknown));
}


// address: 0x10002c43
PyObject *bex_ShowSounds(PyObject *self, PyObject *args) {
        int showSounds;

        if(!PyArg_ParseTuple(args, "i", &showSounds))
                return NULL;

        return Py_BuildValue("i", SetShowSounds(showSounds));
}


// address: 0x10002c8d
PyObject *bex_nSounds(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", nSounds());
}


// address: 0x10002cca
PyObject *bex_GetSoundName(PyObject *self, PyObject *args) {
        int soundId;
        const char *soundName;

        if(!PyArg_ParseTuple(args, "i", &soundId))
                return NULL;

        soundName = GetSoundName(soundId);
        if (soundName == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", soundName);
}


// address: 0x10002d33
PyObject *bex_GetSoundFileName(PyObject *self, PyObject *args) {
        int soundId;
        const char *soundFileName;

        if(!PyArg_ParseTuple(args, "i", &soundId))
                return NULL;

        soundFileName = GetSoundFileName(soundId);
        if (soundFileName == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", soundFileName);
}


// address: 0x10002d9c
PyObject *bex_ReadBitMap(PyObject *self, PyObject *args) {
        const char *file_name;
        const char *internal_name;

        if(!PyArg_ParseTuple(args, "ss", &file_name, &internal_name))
                return NULL;

        ReadBitMap(file_name, internal_name);

        Py_INCREF(Py_None);
        return Py_None;
}

// address: 0x10002df1
PyObject *bex_ReadAlphaBitMap(PyObject *self, PyObject *args) {
        const char *file_name;
        const char *internal_name;

        if(!PyArg_ParseTuple(args, "ss", &file_name, &internal_name))
                return NULL;

        ReadAlphaBitMap(file_name, internal_name);

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x10002e46
PyObject *bex_SetSun(PyObject *self, PyObject *args) {
        int exists;
        double x, y, z;

        if(!PyArg_ParseTuple(args, "iddd", &exists, &x, &y, &z))
                return NULL;

        SetSun(exists, x, y, z);

        return Py_BuildValue("i", 1);
}


// address: 0x10002eaf
PyObject *bex_InsideActionArea(PyObject *self, PyObject *args) {
        int AA;
        double x, y, z;

        if(!PyArg_ParseTuple(args, "iddd", &AA, &x, &y, &z))
                return NULL;

        return Py_BuildValue("i", InsideAA(AA, x, y, z));
}


// address: 0x10002f1d
PyObject *bex_AnmAddEvent(PyObject *self, PyObject *args) {
        const char *anm_name, *event_name;
        double event_frame;

        if(!PyArg_ParseTuple(args, "ssd", &anm_name, &event_name, &event_frame))
                return NULL;

        AnmAddEvent(anm_name, event_name, event_frame);

        return Py_BuildValue("i", 1);
}


// address: 0x10002f76
PyObject *bex_AddAnmEvent(PyObject *self, PyObject *args) {
        const char *anm_name, *event_name;
        double event_frame;

        if(!PyArg_ParseTuple(args, "ssd", &anm_name, &event_name, &event_frame))
                return NULL;

        AddAnmEvent(anm_name, event_name, event_frame);

        return Py_BuildValue("i", 1);
}


// address: 0x10002fcf
PyObject *bex_AnmDelEvent(PyObject *self, PyObject *args) {
        const char *anm_name, *event_name;

        if(!PyArg_ParseTuple(args, "ss", &anm_name, &event_name))
                return NULL;

        AnmDelEvent(anm_name, event_name);

        return Py_BuildValue("i", 1);
}


// address: 0x1000301c
PyObject *bex_AnmClearEvents(PyObject *self, PyObject *args) {
        const char *anm_name;

        if(!PyArg_ParseTuple(args, "s", &anm_name))
                return NULL;

        AnmClearEvents(anm_name);

        return Py_BuildValue("i", 1);
}


// address: 0x1000305f
PyObject *bex_AnmGetEventFrame(PyObject *self, PyObject *args) {
        const char *anm_name, *event_name;

        if(!PyArg_ParseTuple(args, "ss", &anm_name, &event_name))
                return NULL;

        return Py_BuildValue("d", AnmGetEventFrame(anm_name, event_name));
}


// address: 0x100030b5
PyObject *bex_AddParticleGType(PyObject *self, PyObject *args) {
        const char *new_type;
        const char *parent_type;
        int operation_type;
        int duration;

        if(!PyArg_ParseTuple(
                args, "ssii", &new_type, &parent_type, &operation_type,
                &duration
        ))
                return NULL;

        return Py_BuildValue(
                "i", AddParticleGType(
                        new_type, parent_type, operation_type, duration
                )
        );
}

// address: 0x10003117
PyObject *bex_SetParticleGVal(PyObject *self, PyObject *args) {
        const char *type;
        int i, r, g, b, alpha;
        double size;

        if(!PyArg_ParseTuple(args, "siiiiid", &type, &i, &r, &g, &b, &alpha, &size))
                return NULL;

        return Py_BuildValue("i", SetParticleGVal(type, i, r, g, b, alpha, size));
}


// address: 0x10003195
PyObject *bex_GetnParticleGType(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetnParticleGType());
}


// address: 0x100031d2
PyObject *bex_GetParticleGType(PyObject *self, PyObject *args) {
        int index, operation_type, duration, ret;
        const char *type, *parent_type;
        PyObject *tuple, *typeObj, *parentTypeObj, *opTypeObject, *durationObj;

        if(!PyArg_ParseTuple(args, "i", &index))
                return NULL;

        ret = GetParticleGType(
                index, &type, &parent_type, &operation_type, &duration
        );
        if (!ret) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        tuple = PyTuple_New(4);

        typeObj = PyString_FromString(type);
        PyTuple_SET_ITEM(tuple, 0, typeObj);

        parentTypeObj = PyString_FromString(parent_type);
        PyTuple_SET_ITEM(tuple, 1, parentTypeObj);

        opTypeObject = PyInt_FromLong(operation_type);
        PyTuple_SET_ITEM(tuple, 2, opTypeObject);

        durationObj = PyInt_FromLong(duration);
        PyTuple_SET_ITEM(tuple, 3, durationObj);

        return tuple;
}


// address: 0x100032b1
PyObject *bex_GetParticleGVal(PyObject *self, PyObject *args) {
        const char *type;
        double size;
        int index, ret, r, g, b, alpha;
        PyObject *tuple, *rObj, *gObj, *bObject, *alphaObj, *sizeObj;

        if(!PyArg_ParseTuple(args, "si", &type, &index))
                return NULL;

        ret = GetParticleGVal(type, index, &r, &g, &b, &alpha, &size);
        if (!ret) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        tuple = PyTuple_New(5);

        rObj = PyInt_FromLong(r);
        PyTuple_SET_ITEM(tuple, 0, rObj);

        gObj = PyInt_FromLong(g);
        PyTuple_SET_ITEM(tuple, 1, gObj);

        bObject = PyInt_FromLong(b);
        PyTuple_SET_ITEM(tuple, 2, bObject);

        alphaObj = PyInt_FromLong(alpha);
        PyTuple_SET_ITEM(tuple, 3, alphaObj);

        sizeObj = PyFloat_FromDouble(size);
        PyTuple_SET_ITEM(tuple, 4, sizeObj);

        return tuple;
}


// address: 0x100033bc
PyObject *bex_GetEntitiesAt(PyObject *self, PyObject *args) {
        double x, y, z, radius;
        char **entity_names;
        int num_entities, i;
        PyObject *tuple, *nameObj;

        if(!PyArg_ParseTuple(args, "dddd", &x, &y, &z, &radius))
                return NULL;

        entity_names = NULL;
        num_entities = GetEntitiesAt(x, y, z, radius, &entity_names);

        tuple = PyTuple_New(num_entities);

        for (i = 0; i < num_entities; i++) {
                nameObj = PyString_FromString(entity_names[i]);
                PyTuple_SET_ITEM(tuple, i, nameObj);
        }

        if (entity_names)
                free(entity_names);

        return tuple;
}


// address: 0x1000348f
PyObject *bex_GetEntitiesVisibleFrom(PyObject *self, PyObject *args) {
        char **entity_names;
        int num_entities, i;
        PyObject *center = NULL, *direction = NULL, *tuple, *nameObj;
        double radius, angle, xc, yc, zc, xdir, ydir, zdir;

        if(!PyArg_ParseTuple(args, "OdOd", &center, &radius, &direction, &angle))
                return NULL;

        if(!PyArg_ParseTuple(center, "ddd", &xc, &yc, &zc))
                return NULL;

        if(!PyArg_ParseTuple(direction, "ddd", &xdir, &ydir, &zdir))
                return NULL;

        entity_names = NULL;
        num_entities = GetEntitiesVisibleFrom(
                xc, yc, zc, radius, xdir, ydir, zdir, angle, &entity_names
        );

        tuple = PyTuple_New(num_entities);

        for (i = 0; i < num_entities; i++) {
                nameObj = PyString_FromString(entity_names[i]);
                PyTuple_SET_ITEM(tuple, i, nameObj);
        }

        if (entity_names)
                free(entity_names);

        return tuple;
}


// address: 0x100035e2
PyObject *bex_GetObjectEntitiesVisibleFrom(PyObject *self, PyObject *args) {
        char **entity_names;
        int num_entities, i;
        PyObject *center = NULL, *direction = NULL, *tuple, *nameObj;
        double radius, angle, xc, yc, zc, xdir, ydir, zdir;

        if(!PyArg_ParseTuple(args, "OdOd", &center, &radius, &direction, &angle))
                return NULL;

        if(!PyArg_ParseTuple(center, "ddd", &xc, &yc, &zc))
                return NULL;

        if(!PyArg_ParseTuple(direction, "ddd", &xdir, &ydir, &zdir))
                return NULL;

        entity_names = NULL;
        num_entities = GetObjectEntitiesVisibleFrom(
                xc, yc, zc, radius, xdir, ydir, zdir, angle, &entity_names
        );

        tuple = PyTuple_New(num_entities);

        for (i = 0; i < num_entities; i++) {
                nameObj = PyString_FromString(entity_names[i]);
                PyTuple_SET_ITEM(tuple, i, nameObj);
        }

        if (entity_names)
                free(entity_names);

        return tuple;
}


// address: 0x10003735
PyObject *bex_GetCombos(PyObject *self, PyObject *args) {
        combo_t *combos;
        int num_combos, i;
        PyObject *tuple, *list, *nameObj, *executedObj;
        const char *person_name;

        if(!PyArg_ParseTuple(args, "s", &person_name))
                return NULL;

        num_combos = GetCombos(person_name, &combos);

        list = PyList_New(num_combos);

        for (i = 0; i < num_combos; i++) {
                tuple = PyTuple_New(2);

                nameObj = PyString_FromString(combos[i].name);
                PyTuple_SET_ITEM(tuple, 0, nameObj);

                executedObj = PyFloat_FromDouble(combos[i].executed);
                PyTuple_SET_ITEM(tuple, 1, executedObj);

                PyList_SET_ITEM(list, i, tuple);
        }

        return list;
}


// address: 0x10003814
PyObject *bex_SetCombos(PyObject *self, PyObject *args) {
        int num_combos, i, ret;
        char **combos_names;
        int *combos_executed;
        const char *person_name;
        PyObject *combos_obj, *tuple;

        if(!PyArg_ParseTuple(args, "sO", &person_name, &combos_obj))
                return NULL;


        if (!PyList_Check(combos_obj)) {
                PyErr_SetString(
                        PyExc_RuntimeError, "Error 2nd element must be a list."
                );
                return NULL;
        }

        num_combos = PyList_Size(combos_obj);

        combos_names = (char **) malloc(num_combos * sizeof(char *));
        combos_executed = (int *) malloc(num_combos * sizeof(int));

        assert(combos_names);
        assert(combos_executed);

        for (i = 0; i < num_combos; i++) {
                tuple = PyList_GET_ITEM(combos_obj, i);

                if (!PyTuple_Check(tuple)) {
                        PyErr_SetString(
                                PyExc_RuntimeError, "Error getting element."
                        );
                        return NULL;
                }

                combos_names[i] = strdup(PyString_AsString(PyTuple_GET_ITEM(tuple, 0)));

                combos_executed[i] = PyInt_AsLong(PyTuple_GET_ITEM(tuple, 1));

        }

        ret = SetCombos(person_name, num_combos, combos_names, combos_executed);

        for (i = 0; i < num_combos; i++) {
                free(combos_names[i]);
        }

        free(combos_names);
        free(combos_executed);

        return Py_BuildValue("i", ret);
}


// address: 0x100039fd
PyObject *bex_GetWeaponCombos(PyObject *self, PyObject *args) {
        combo_t *combos;
        int num_combos, i;
        PyObject *tuple, *list, *nameObj, *executedObj;
        const char *person_name, *weapon_kind;

        if(!PyArg_ParseTuple(args, "ss", &person_name, &weapon_kind))
                return NULL;

        num_combos = GetWeaponCombos(person_name, weapon_kind, &combos);

        list = PyList_New(num_combos);

        for (i = 0; i < num_combos; i++) {
                tuple = PyTuple_New(2);

                nameObj = PyString_FromString(combos[i].name);
                PyTuple_SET_ITEM(tuple, 0, nameObj);

                executedObj = PyFloat_FromDouble(combos[i].executed);
                PyTuple_SET_ITEM(tuple, 1, executedObj);

                PyList_SET_ITEM(list, i, tuple);
        }

        return list;
}


// address: 0x10003ae4
PyObject *bex_GetLastPlayerCType(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("s", GetLastPlayerCType());
}


// address: 0x10003b28
PyObject *bex_GetEnemiesVisibleFrom(PyObject *self, PyObject *args) {
        char **enemy_names;
        int num_enemies, i;
        PyObject *center = NULL, *direction = NULL, *tuple, *nameObj;
        double radius, angle, xc, yc, zc, xdir, ydir, zdir;

        if(!PyArg_ParseTuple(args, "OdOd", &center, &radius, &direction, &angle))
                return NULL;

        if(!PyArg_ParseTuple(center, "ddd", &xc, &yc, &zc))
                return NULL;

        if(!PyArg_ParseTuple(direction, "ddd", &xdir, &ydir, &zdir))
                return NULL;

        enemy_names = NULL;
        num_enemies = GetEnemiesVisibleFrom(
                xc, yc, zc, radius, xdir, ydir, zdir, angle, &enemy_names
        );

        tuple = PyTuple_New(num_enemies);

        for (i = 0; i < num_enemies; i++) {
                nameObj = PyString_FromString(enemy_names[i]);
                PyTuple_SET_ITEM(tuple, i, nameObj);
        }

        if (enemy_names)
                free(enemy_names);

        return tuple;
}


// address: 0x10003c7b
PyObject *bex_CDPlayTrack(PyObject *self, PyObject *args) {
        int ntrack;

        if(!PyArg_ParseTuple(args, "i", &ntrack))
                return NULL;

        return Py_BuildValue("i", PlayCDTrack(ntrack));
}


// address: 0x10003cc5
PyObject *bex_CDnTracks(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", nCDTracks());
}


// address: 0x10003d02
PyObject *bex_CheckPyErrors(PyObject *self, PyObject *args) {

    if (PyErr_Occurred()) {
        PyErr_Print();
        PyErr_Clear();
        return Py_BuildValue("i", 1);
    }

    return Py_BuildValue("i", 0);
}


// address: 0x10003d47
PyObject *bex_CDLenght(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", CDLenght());
}


// address: 0x10003d84
PyObject *bex_CDTrackLenght(PyObject *self, PyObject *args) {
        int ntrack;

        if(!PyArg_ParseTuple(args, "i", &ntrack))
                return NULL;

        return Py_BuildValue("i", CDTrackLenght(ntrack));
}


// address: 0x10003dce
PyObject *bex_CDPresent(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", CDPresent());
}


// address: 0x10003e0b
PyObject *bex_CDStop(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", CDStop());
}


// address: 0x10003e48
PyObject *bex_CDPause(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", CDPause());
}


// address: 0x10003e85
PyObject *bex_CDCallBack(PyObject *self, PyObject *args) {
        PyObject *func;

        if(!PyArg_ParseTuple(args, "O", &func))
                return NULL;

        return Py_BuildValue("i", CDSetCallBack(func));
}


// address: 0x10003ecf
PyObject *bex_SetDefaultMass(PyObject *self, PyObject *args) {
        const char *entity_kind;
        double mass;

        if(!PyArg_ParseTuple(args, "sd", &entity_kind, &mass))
                return NULL;

        return Py_BuildValue("i", SetDefaultMass(entity_kind, mass));
}


// address: 0x10003f25
PyObject *bex_SetDefaultMaterial(PyObject *self, PyObject *args) {
        const char *entity_kind, *material;

        if(!PyArg_ParseTuple(args, "ss", &entity_kind, &material))
                return NULL;

        return Py_BuildValue("i", SetDefaultMaterial(entity_kind, material));
}


// address: 0x10003f77
PyObject *bex_CreateMaterial(PyObject *self, PyObject *args) {
        const char *name;
        PyObject *material;

        if(!PyArg_ParseTuple(args, "s", &name))
                return NULL;

        material = create_material(name);
        if (material == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return material;
}


// address: 0x10003fd0
PyObject *bex_GetMaterial(PyObject *self, PyObject *args) {
        const char *name;
        int index;
        PyObject *material;

        if (!PyArg_ParseTuple(args, "s", &name)) {
                PyErr_Clear();
                if (!PyArg_ParseTuple(args, "i", &index))
                        return NULL;

                material = get_material_by_index(index);
                if (material == NULL) {
                        Py_INCREF(Py_None);
                        return Py_None;
                }

                return material;

        }
        material = get_material_by_name(name);
        if (material == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return material;
}


// address: 0x1000407c
PyObject *bex_nMaterials(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", nMaterials());
}


// address: 0x100040b9
PyObject *bex_AddGhostSector(PyObject *self, PyObject *args) {
        const char *ghost_sector_name, *group_name;
        double floor_height, roof_height;
        PyObject *pointsList, *tuple, *xObj, *yObj;
        point_2d_t *points;
        int num_points, i, code;

        if (!PyArg_ParseTuple(
                args, "ssddO", &ghost_sector_name, &group_name, &floor_height,
                &roof_height, &pointsList
        ))
                return NULL;

        if (!PyList_Check(pointsList))
                return Py_BuildValue("i", 0);

        num_points = PyList_Size(pointsList);
        points = (point_2d_t *)malloc(num_points * sizeof(point_2d_t));
        if (points == NULL)
                return Py_BuildValue("i", 0);

        for (i = 0; i < num_points; i++) {
                tuple = PyList_GetItem(pointsList, i);
                if (!PyTuple_Check(tuple)) {
                        free(points);
                        PyErr_SetString(PyExc_RuntimeError, "Wrong number of arguments in tuple.");
                        return NULL;
                }

                xObj = PyTuple_GetItem(tuple, 0);
                yObj = PyTuple_GetItem(tuple, 1);

                points[i].x = PyFloat_AsDouble(xObj);
                points[i].y = PyFloat_AsDouble(yObj);
        }

        code = CreateGhostSector(
                ghost_sector_name, group_name, floor_height, roof_height,
                num_points, points
        );

        free(points);

        return Py_BuildValue("i", code);
}


// address: 0x1000426f
PyObject *bex_AddTriggerSector(PyObject *self, PyObject *args) {
        const char *trigger_sector_name, *group_name;
        double floor_height, roof_height;
        PyObject *pointsList, *tuple, *xObj, *yObj;
        point_2d_t *points;
        int num_points, i, code;

        if (!PyArg_ParseTuple(
                args, "ssddO", &trigger_sector_name, &group_name, &floor_height,
                &roof_height, &pointsList
        ))
                return NULL;

        if (!PyList_Check(pointsList))
                return Py_BuildValue("i", 0);


        num_points = PyList_Size(pointsList);
        points = (point_2d_t *)malloc(num_points * sizeof(point_2d_t));
        if (points == NULL)
                return Py_BuildValue("i", 0);

        for (i = 0; i < num_points; i++) {
                tuple = PyList_GetItem(pointsList, i);
                if (!PyTuple_Check(tuple)) {
                        free(points);
                        PyErr_SetString(PyExc_RuntimeError, "Wrong number of arguments in tuple.");
                        return NULL;
                }

                xObj = PyTuple_GetItem(tuple, 0);
                yObj = PyTuple_GetItem(tuple, 1);

                points[i].x = PyFloat_AsDouble(xObj);
                points[i].y = PyFloat_AsDouble(yObj);
        }

        code = CreateTriggerSector(
                trigger_sector_name, group_name, floor_height, roof_height,
                num_points, points
        );

        free(points);

        return Py_BuildValue("i", code);
}


// address: 0x10004425
PyObject *bex_SetTriggerSectorFunc(PyObject *self, PyObject *args) {
        const char *trigger_sector_name, *func_type;
        PyObject *func;

        if (!PyArg_ParseTuple(
                args, "ssO", &trigger_sector_name, &func_type, &func
        ))
                return NULL;

        if (!PyCallable_Check(func))
                func = NULL;

        return Py_BuildValue(
                "i", SetTriggerSectorFunc(trigger_sector_name, func_type, func)
        );
}


// address: 0x10004497
PyObject *bex_GetTriggerSectorFunc(PyObject *self, PyObject *args) {
        const char *trigger_sector_name, *func_type;
        PyObject *func;

        if (!PyArg_ParseTuple(args, "ss", &trigger_sector_name, &func_type))
                return NULL;

        func = GetTriggerSectorFunc(trigger_sector_name, func_type);
        if (func)
                return func;

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x100044fa
PyObject *bex_SetTriggerSectorData(PyObject *self, PyObject *args) {
        const char *trigger_sector_name;
        PyObject *data;

        if (!PyArg_ParseTuple(args, "sO", &trigger_sector_name, &data))
                return NULL;

        return Py_BuildValue(
                "i", SetTriggerSectorData(trigger_sector_name, data)
        );
}


// address: 0x1000454c
PyObject *bex_GetTriggerSectorData(PyObject *self, PyObject *args) {
        const char *trigger_sector_name;
        PyObject *data;

        if (!PyArg_ParseTuple(args, "s", &trigger_sector_name))
                return NULL;

        data = GetTriggerSectorData(trigger_sector_name);
        if (data)
                return data;

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x100045a6
PyObject *bex_RemoveTriggerSectorFunc(PyObject *self, PyObject *args) {
        const char *trigger_sector_name, *func_type;

        if (!PyArg_ParseTuple(args, "ss", &trigger_sector_name, &func_type))
                return NULL;

        return Py_BuildValue(
                "i", SetTriggerSectorFunc(trigger_sector_name, func_type, NULL)
        );
}


// address: 0x100045fa
PyObject *bex_GetTriggerSectorFloorHeight(PyObject *self, PyObject *args) {
        const char *trigger_sector_name;

        if (!PyArg_ParseTuple(args, "s", &trigger_sector_name))
                return NULL;

        return Py_BuildValue(
                "i", GetTriggerSectorFloorHeight(trigger_sector_name)
        );
}


// address: 0x10004644
PyObject *bex_GetTriggerSectorRoofHeight(PyObject *self, PyObject *args) {
        const char *trigger_sector_name;

        if (!PyArg_ParseTuple(args, "s", &trigger_sector_name))
                return NULL;

        return Py_BuildValue(
                "i", GetTriggerSectorRoofHeight(trigger_sector_name)
        );
}


// address: 0x1000468e
PyObject *bex_GetTriggerSectorGroup(PyObject *self, PyObject *args) {
        const char *trigger_sector_name;

        if (!PyArg_ParseTuple(args, "s", &trigger_sector_name))
                return NULL;

        return Py_BuildValue("s", GetTriggerSectorGroup(trigger_sector_name));
}


// address: 0x100046d8
PyObject *bex_GetTriggerSectorPoints(PyObject *self, PyObject *args) {
        PyObject *list, *tuple, *xObj, *yObj;
        const char *trigger_sector_name;
        int num_points, i;
        double *points;

        if (!PyArg_ParseTuple(args, "s", &trigger_sector_name))
                return NULL;

        points = GetTriggerSectorPoints(trigger_sector_name);

        num_points = points[0];
        points++;

        list = PyList_New(num_points);

        for (i = 0; i < num_points; i++) {
            tuple = PyTuple_New(2);

            xObj = PyFloat_FromDouble(*points);
            points++;

            yObj = PyFloat_FromDouble(*points);
            points++;

            PyTuple_SET_ITEM(tuple, 0, xObj);
            PyTuple_SET_ITEM(tuple, 1, yObj);

            PyList_SetItem(list, i, tuple);
        }

        return Py_BuildValue("O", list);
}


// address: 0x100047f4
PyObject *bex_nTriggerSectors(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", nTriggerSectors());
}


// address: 0x10004831
PyObject *bex_GetTriggerSectorName(PyObject *self, PyObject *args) {
        int index;
        const char *name;

        if (!PyArg_ParseTuple(args, "i", &index))
                return NULL;

        name = GetTriggerSectorName(index);
        if (name)
                return Py_BuildValue("s", name);

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x1000489a
PyObject *bex_GenerateEntityName(PyObject *self, PyObject *args) {

        return Py_BuildValue("s", GenerateEntityName());
}


// address: 0x100048c6
PyObject *bex_AddWatchAnim(PyObject *self, PyObject *args) {
        const char *anim;

        if (!PyArg_ParseTuple(args, "s", &anim))
                return NULL;

        return Py_BuildValue("i", AddWatchAnim(anim));
}


// address: 0x10004910
PyObject *bex_AddAnimFlags(PyObject *self, PyObject *args) {
        const char *anim;
        int wuea, mdf_y, solf, copy_rot, bng_mov, head_f;

        if (!PyArg_ParseTuple(
                args, "siiiiii", &anim, &wuea, &mdf_y, &solf, &copy_rot,
                &bng_mov, &head_f
        ))
                return NULL;

        return Py_BuildValue(
                "i",
                AddAnimFlags(anim, wuea, mdf_y, solf, copy_rot, bng_mov, head_f)
        );
}


// address: 0x1000498a
PyObject *bex_SetEAX(PyObject *self, PyObject *args) {
        int eax_flag;

        if (!PyArg_ParseTuple(args, "i", &eax_flag))
                return NULL;

        return Py_BuildValue("i", SetEAX(eax_flag));
}


// address: 0x100049d4
PyObject *bex_SetActionCameraMovement(PyObject *self, PyObject *args) {
        const char* action_name;
        double angle, start_pos, end_pos;

        if (!PyArg_ParseTuple(
                args, "sddd", &action_name, &angle, &start_pos, &end_pos
        ))
                return NULL;

        return Py_BuildValue(
                "i",
                SetActionCameraMovement(action_name, angle, start_pos, end_pos)
        );
}


// address: 0x10004a42
PyObject *bex_DeactivateInput(PyObject *self, PyObject *args) {
        return Py_BuildValue("i", DeactivateInput());
}


// address: 0x10004a65
PyObject *bex_ActivateInput(PyObject *self, PyObject *args) {
        return Py_BuildValue("i", ActivateInput());
}


// address: 0x10004a88
PyObject *bex_SetGhostSectorSound(PyObject *self, PyObject *args) {
        const char *ghost_name, *file_name;
        double volume = 1.0, base_volume = 1.0, min_dist = 1000.0;
        double max_dist = 20000.0, v_max_dist = 10000.0, scale = 1.0;

        if (!PyArg_ParseTuple(
                args, "ss|dddddd", &ghost_name, &file_name, &volume,
                &base_volume, &min_dist, &max_dist, &v_max_dist, &scale
        ))
                return NULL;

        return Py_BuildValue(
                "i",
                SetGhostSectorSound(
                        ghost_name, file_name, volume, base_volume, min_dist,
                        max_dist, v_max_dist, scale
                )
        );
}


// address: 0x10004b76
PyObject *bex_GetSound(PyObject *self, PyObject *args) {
        int soundID;
        bld_py_sound_t *sound_obj;
        const char *sound_name;

        if (!PyArg_ParseTuple(args, "s", &sound_name)) {
                PyErr_SetString(
                        PyExc_RuntimeError,
                        "Wrong number of arguments in tuple."
                );
                return NULL;
        }

        soundID = GetSound(sound_name);
        if (soundID == 0) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        sound_obj = PyObject_NEW(bld_py_sound_t, &soundTypeObject);
        if (sound_obj == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        sound_obj->soundID = soundID;
        sound_obj->soundDev = GetSoundDevInstace();

        return (PyObject *)sound_obj;
}


// address: 0x10004c41
PyObject *bex_SetGhostSectorGroupSound(PyObject *self, PyObject *args) {
        const char *group_name, *file_name;
        double volume = 1.0, base_volume = 1.0, min_dist = 1000.0;
        double max_dist = 20000.0, unknown = 20000.0, scale = 1.0;

        /* FIXME Too many arguments: should be 7 gets 8 */
        if (!PyArg_ParseTuple(
                args, "ss|ddddd", &group_name, &file_name, &volume,
                &base_volume, &min_dist, &max_dist, &unknown, &scale
        ))
                return NULL;

        return Py_BuildValue(
                "i",
                SetGhostSectorGroupSound(
                        group_name, file_name, volume,
                        base_volume, min_dist, max_dist, unknown, scale
                )
        );
}


// address: 0x10004d2f
PyObject *bex_SetRootWidget(PyObject *self, PyObject *args) {
        long int widget;

        if (!PyArg_ParseTuple(args, "l", &widget))
                return NULL;

        return Py_BuildValue("i", SetRootWidget(widget));
}


// address: 0x10004d79
PyObject *bex_GetRootWidget(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("l", GetRootWidget());
}


// address: 0x10004dbd
PyObject *bex_AddCombustionDataFor(PyObject *self, PyObject *args) {
        const char *object_kind, *fire_kind;
        double upper_treshol, lower_treshold, flame_height, flame_size, speed;
        double livetime;

        if (!PyArg_ParseTuple(
                args, "ssdddddd", &object_kind, &fire_kind, &upper_treshol,
                &lower_treshold, &flame_height, &flame_size, &speed, &livetime
        ))
                return NULL;

        return Py_BuildValue(
                "i", AddCombustionDataFor(
                        object_kind, fire_kind, upper_treshol, lower_treshold,
                        flame_height, flame_size, speed, livetime
                )
        );
}


// address: 0x10004e57
PyObject *bex_SetAfterFrameFunc(PyObject *self, PyObject *args) {
        const char *name;
        PyObject *function = NULL;

        if (!PyArg_ParseTuple(args, "sO", &name, &function))
                return NULL;

        return Py_BuildValue("i", SetAfterFrameFunc(name, function));
}

// address: 0x10004eb0
PyObject *bex_GetAfterFrameFunc(PyObject *self, PyObject *args) {
        const char *name;
        PyObject *function;

        if (!PyArg_ParseTuple(args, "s", &name))
                return NULL;

        function = GetAfterFrameFunc(name);
        if (function == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        Py_INCREF(function);
        return function;
}


// address: 0x10004f17
PyObject *bex_GetnAfterFrameFuncs(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetnAfterFrameFuncs());
}


// address: 0x10004f54
PyObject *bex_GetAfterFrameFuncName(PyObject *self, PyObject *args) {
        int index;
        const char *func_name;

        if (!PyArg_ParseTuple(args, "i", &index))
                return NULL;

        func_name = GetAfterFrameFuncName(index);
        if (func_name)
                return Py_BuildValue("s", func_name);

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x10004fbd
PyObject *bex_RemoveAfterFrameFunc(PyObject *self, PyObject *args) {
        const char *name;

        if (!PyArg_ParseTuple(args, "s", &name))
                return NULL;

        return Py_BuildValue("i", RemoveAfterFrameFunc(name));
}


// address: 0x10005007
PyObject *bex_SetMenuTgapFunc(PyObject *self, PyObject *args) {
        PyObject *tgapFunc = NULL;

        if (!PyArg_ParseTuple(args, "O", &tgapFunc))
                return NULL;

        return Py_BuildValue("i", SetMenuTgapFunc(tgapFunc));
}


// address: 0x10005058
PyObject *bex_GetMenuTgapFunc(PyObject *self, PyObject *args) {
        PyObject *tgapFunc;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        tgapFunc = GetMenuTgapFunc();
        if (tgapFunc == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        Py_INCREF(tgapFunc);
        return tgapFunc;
}


// address: 0x100050b2
PyObject *bex_SetCallCheck(PyObject *self, PyObject *args) {
        int check;

        if (!PyArg_ParseTuple(args, "i", &check))
                return NULL;

        return Py_BuildValue("i", SetCallCheck(check));
}


// address: 0x100050fc
PyObject *bex_DrawBOD(PyObject *self, PyObject *args) {
        const char *BODName;
        int x, y, w, h, i_unknown;
        double scale = 1.0;

        if (!PyArg_ParseTuple(args, "siiiidi", &BODName, &x, &y, &w, &h, &scale, &i_unknown))
                return NULL;

        return Py_BuildValue(
                "i", DrawBOD(BODName, x, y, w, h, scale, i_unknown)
        );
}


// address: 0x10005188
PyObject *bex_ShowActionAreas(PyObject *self, PyObject *args) {
        int action_areas_bit_mask;

        if (!PyArg_ParseTuple(args, "i", &action_areas_bit_mask))
                return NULL;

        return Py_BuildValue("i", SetShowAreas(action_areas_bit_mask));
}


// address: 0x100051d2
PyObject *bex_WriteText(PyObject *self, PyObject *args) {
        const char *text = NULL;
        double x, y;

        if (!PyArg_ParseTuple(args, "dds", &x, &y, &text))
                return NULL;

        return Py_BuildValue("i", WriteText(x, y, text));
}


// address: 0x1000523b
PyObject *bex_GetTextWH(PyObject *self, PyObject *args) {
        const char *text = NULL;
        double w, h;

        if (!PyArg_ParseTuple(args, "s", &text))
                return NULL;

        GetTextWH(text, &w, &h);

        return Py_BuildValue("dd", w, h);
}


// address: 0x1000529d
PyObject *bex_GetScreenRect(PyObject *self, PyObject *args) {
        double x_min, y_min, x_max, y_max;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        GetScreenRect(&x_min, &y_min, &x_max, &y_max);

        return Py_BuildValue("dddd", x_min, y_min, x_max, y_max);
}


// address: 0x10005308
PyObject *bex_GetScreenXY(PyObject *self, PyObject *args) {
        PyObject *tuple;
        double map_x, map_y, map_z, screen_x, screen_y;

        if (!PyArg_ParseTuple(args, "O", &tuple))
                return NULL;

        if (!PyArg_ParseTuple(tuple, "ddd", &map_x, &map_y, &map_z))
                return NULL;

        GetScreenXY(map_x, map_y, map_z, &screen_x, &screen_y);

        return Py_BuildValue("dd", screen_x, screen_y);
}


// address: 0x100053a0
PyObject *bex_CloseDebugChannel(PyObject *self, PyObject *args) {
        const char *channel_name;

        if(!PyArg_ParseTuple(args, "s", &channel_name))
                return NULL;

        return Py_BuildValue("i", CloseDebugChannel(channel_name));
}


// address: 0x100053f1
PyObject *bex_DumpMemoryLeaks(PyObject *self, PyObject *args) {
        const char *s;

        if (!PyArg_ParseTuple(args, "s", &s))
                return NULL;

        return Py_BuildValue("i", dump_memory_leaks(s));
}


// address: 0x10005441
PyObject *bex_OpenDebugChannel(PyObject *self, PyObject *args) {
        const char *channel_name;

        if(!PyArg_ParseTuple(args, "s", &channel_name))
                return NULL;

        return Py_BuildValue("i", OpenDebugChannel(channel_name));
}


// address: 0x10005492
PyObject *bex_SetAppMode(PyObject *self, PyObject *args) {
        const char *mode;

        if(!PyArg_ParseTuple(args, "s", &mode))
                return NULL;

        return Py_BuildValue("i", SetAppMode(mode));
}


// address: 0x100054e3
PyObject *bex_GetAppMode(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("s", GetAppMode());
}


// address: 0x10005529
PyObject *bex_GetCommandLine(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("s", GetCommandLine());
}


// address: 0x1000556f
PyObject *bex_Quit(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", Quit());
}


// address: 0x100055ac
PyObject *bex_LoadSampledAnimation(PyObject *self, PyObject *args) {
        const char* file, *internal_name, *race_name = "";
        int type, i_unknown = 20;

        if (!PyArg_ParseTuple(
                args, "ss|isi", &file, &internal_name, &type, &race_name,
                &i_unknown
        ))
                return NULL;

        return Py_BuildValue(
                "i",
                LoadSampledAnimation(
                        file, internal_name, type, race_name, i_unknown
                )
        );
}


// address: 0x10005624
PyObject *bex_CreateFCAnimation(PyObject *self, PyObject *args) {
        const char* file, *internal_name;
        int n_armonics;

        if (!PyArg_ParseTuple(args, "ss|i", &file, &internal_name, &n_armonics))
                return NULL;

        return Py_BuildValue(
                "i",
                CreateFCAnimation(file, internal_name, n_armonics)
        );
}


// address: 0x1000567e
PyObject *bex_CreateDFCAnimation(PyObject *self, PyObject *args) {
        const char* file1, *file2, *internal_name;
        int n_armonics;

        if (!PyArg_ParseTuple(
                args, "sss|i", &file1, &file2, &internal_name, &n_armonics
        ))
                return NULL;

        return Py_BuildValue(
                "i",
                CreateDFCAnimation(file1, file2, internal_name, n_armonics)
        );
}


// address: 0x100056e0
PyObject *bex_CreateBipedData(PyObject *self, PyObject *args) {
        const char *biped_name, *kind;

        if (!PyArg_ParseTuple(args, "ss", &biped_name, &kind))
                return NULL;

        return Py_BuildValue("i", CreateBipedData(biped_name, kind));
}


// address: 0x10005732
PyObject *bex_AddBipedAction(PyObject *self, PyObject *args) {
        const char *char_name, *action_name, *animation_name, *s_unknown;
        double d_unknown1, d_unknown2;
        int i_unknown;

        if (PyArg_ParseTuple(
                args, "sssddi", &char_name, &action_name, &animation_name,
                &d_unknown1, &d_unknown2, &i_unknown
        ))
                return Py_BuildValue(
                        "i",
                        AddBipedAction(
                                char_name, action_name, animation_name,
                                d_unknown1, d_unknown2, i_unknown
                        )
                );

        PyErr_Clear();
        if(!PyArg_ParseTuple(
                args, "ssssddi", &char_name, &action_name, &animation_name,
                &s_unknown, &d_unknown1, &d_unknown2, &i_unknown
        ))
                return NULL;

        return Py_BuildValue(
                "i", 
                AddBipedActionC(
                        char_name, action_name, animation_name, s_unknown,
                        d_unknown1, d_unknown2, i_unknown
                )
        );
}


// address: 0x10005828
PyObject *bex_RemoveBipedAction(PyObject *self, PyObject *args) {
        const char *s_unknown1, *s_unknown2;

        if (!PyArg_ParseTuple(args, "ss", &s_unknown1, &s_unknown2))
                return NULL;

        return Py_BuildValue("i", RemoveBipedAction(s_unknown1, s_unknown2));
}


// address: 0x1000587a
PyObject *bex_AddAnmRStep(PyObject *self, PyObject *args) {
        const char *animation_name;
        double d_unknown;

        if (!PyArg_ParseTuple(args, "sd", &animation_name, &d_unknown))
                return NULL;

        return Py_BuildValue("i", AddRStepEvent(animation_name, d_unknown));
}


// address: 0x100058d0
PyObject *bex_AnmTypeRSteps(PyObject *self, PyObject *args) {
        const char *s_unknown1, *s_unknown2;

        if (!PyArg_ParseTuple(args, "ss", &s_unknown1, &s_unknown2))
                return NULL;

        return Py_BuildValue("i", RStepEvents(s_unknown1, s_unknown2));
}


// address: 0x10005922
PyObject *bex_AnmTypeLSteps(PyObject *self, PyObject *args) {
        const char *s_unknown1, *s_unknown2;

        if (!PyArg_ParseTuple(args, "ss", &s_unknown1, &s_unknown2))
                return NULL;

        return Py_BuildValue("i", LStepEvents(s_unknown1, s_unknown2));
}


// address: 0x10005974
PyObject *bex_SetActionEventTable(PyObject *self, PyObject *args) {
        const char *race_name, *action_name, *table_name;

        if (!PyArg_ParseTuple(args, "sss", &race_name, &action_name, &table_name))
                return NULL;

        return Py_BuildValue(
                "i", SetActionEventTable(race_name, action_name, table_name)
        );
}


// address: 0x100059ce
PyObject *bex_SetEventTableFuncC(PyObject *self, PyObject *args) {
        const char *event_table_name, *event_type, *funcC;

        if (!PyArg_ParseTuple(args, "sss", &event_table_name, &event_type, &funcC))
                return NULL;

        return Py_BuildValue(
                "i", SetEventTableFuncC(event_table_name, event_type, funcC)
        );
}


// address: 0x10005a28
PyObject *bex_SetEventTableFunc(PyObject *self, PyObject *args) {
        const char *event_table_name, *event_type;
        PyObject *func;

        if (!PyArg_ParseTuple(args, "ssO", &event_table_name, &event_type, &func))
                return NULL;

        return Py_BuildValue(
                "i", SetEventTableFunc(event_table_name, event_type, func)
        );
}


// address: 0x10005a82
PyObject *bex_AddAnmLStep(PyObject *self, PyObject *args) {
        const char *animation_name;
        double d_unknown;

        if (!PyArg_ParseTuple(args, "sd", &animation_name, &d_unknown))
                return NULL;

        return Py_BuildValue("i", AddLStepEvent(animation_name, d_unknown));
}


// address: 0x10005ad8
PyObject *bex_AddAnmRRelease(PyObject *self, PyObject *args) {
        const char *animation_name;
        double d_unknown;

        if (!PyArg_ParseTuple(args, "sd", &animation_name, &d_unknown))
                return NULL;

        return Py_BuildValue("i", AddRReleaseEvent(animation_name, d_unknown));
}


// address: 0x10005b2e
PyObject *bex_AddAnmLRelease(PyObject *self, PyObject *args) {
        const char *animation_name;
        double d_unknown;

        if (!PyArg_ParseTuple(args, "sd", &animation_name, &d_unknown))
                return NULL;

        return Py_BuildValue("i", AddLReleaseEvent(animation_name, d_unknown));
}


// address: 0x10005b84
PyObject *bex_AddStopTests(PyObject *self, PyObject *args) {
        const char *animation_name;

        if (!PyArg_ParseTuple(args, "s", &animation_name))
                return NULL;

        AddStopTests(animation_name);

        return Py_BuildValue("i", 1);
}


// address: 0x10005bc7
PyObject *bex_AddFloorCTolerance(PyObject *self, PyObject *args) {
        const char *animation_name;
        double tolerance;

        if (!PyArg_ParseTuple(args, "sd", &animation_name, &tolerance))
                return NULL;

        AddFloorCTolerance(animation_name, tolerance);

        return Py_BuildValue("i", 1);
}


// address: 0x10005c18
PyObject *bex_SetSolidMask(PyObject *self, PyObject *args) {
        const char *kind;
        int mask;

        if(!PyArg_ParseTuple(args, "si", &kind, &mask))
                return NULL;

        return Py_BuildValue("i", SetSolidMask(kind, mask));
}


// address: 0x10005c6a
PyObject *bex_SetDrawObjectShadows(PyObject *self, PyObject *args) {
        int draw;

        if(!PyArg_ParseTuple(args, "i", &draw))
                return NULL;

        return Py_BuildValue("i", SetDrawObjectShadows(draw));
}


// address: 0x10005cb4
PyObject *bex_GetAutoEngageCombat(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetAutoEngageCombat());
}


// address: 0x10005cf1
PyObject *bex_SetAutoEngageCombat(PyObject *self, PyObject *args) {
        int auto_engage_combat;

        if(!PyArg_ParseTuple(args, "i", &auto_engage_combat))
                return NULL;

        return Py_BuildValue("i", SetAutoEngageCombat(auto_engage_combat));
}


// address: 0x10005d3b
PyObject *bex_GetAecGap(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("d", GetAecGap());
}


// address: 0x10005d7e
PyObject *bex_SetAecGap(PyObject *self, PyObject *args) {
        double aec_gap;

        if(!PyArg_ParseTuple(args, "d", &aec_gap))
                return NULL;

        return Py_BuildValue("i", SetAecGap(aec_gap));
}


// address: 0x10005dcc
PyObject *bex_GetDrawObjectShadows(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetDrawObjectShadows());
}


// address: 0x10005e09
PyObject *bex_GetModelPos(PyObject *self, PyObject *args) {
        const char *person = NULL;
        int ret;
        double x, y, z;

        if(!PyArg_ParseTuple(args, "s", &person))
                return NULL;

        ret = GetModelPos(person, &x, &y, &z);
        if (!ret)
                return Py_BuildValue("i", 0);

        return Py_BuildValue("ddd", x, y, z);
}


// address: 0x10005e8d
PyObject *bex_GetGhostSectorSound(PyObject *self, PyObject *args) {
        const char *gs_name;
        PyObject *sound;

        if (!PyArg_ParseTuple(args, "s", &gs_name))
                return NULL;

        sound = get_ghost_sector_sound(gs_name);
        if (sound == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return sound;
}


// address: 0x10005ee6
PyObject *bex_GetCurrentMap(PyObject *self, PyObject *args) {
        const char *map;

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        map = GetCurrentMap();
        if (map == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", map);
}


// address: 0x10005f42
PyObject *bex_SetCurrentMap(PyObject *self, PyObject *args) {
        const char *map;

        if(!PyArg_ParseTuple(args, "s", &map))
                return NULL;

        return Py_BuildValue("i", SetCurrentMap(map));
}


// address: 0x10005f8c
PyObject *bex_LoadWorld(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", LoadWorld(file_name));
}


// address: 0x10005fd6
PyObject *bex_DoneLoadGame(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        DoneLoadGame();

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x10006012
PyObject *bex_BeginLoadGame(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        BeginLoadGame();

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x1000604e
PyObject *bex_GetWindowId(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetWindowId());
}


// address: 0x1000608b
PyObject *bex_GetProgramId(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetProgramId());
}


// address: 0x100060c8
PyObject *bex_AddStepSound(PyObject *self, PyObject *args) {
        const char *name;
        bld_py_sound_t *sound;

        if(!PyArg_ParseTuple(args, "sO", &name, &sound))
                return NULL;

        return Py_BuildValue("i", AddStepSound(name, sound->soundID));
}


// address: 0x1000611d
PyObject *bex_AddMaterialStepSound(PyObject *self, PyObject *args) {
        const char *table, *material, *step_sound;

        if(!PyArg_ParseTuple(args, "sss", &table, &material, &step_sound))
                return NULL;

        return Py_BuildValue("i", AddMaterialStepSound(table, material, step_sound));
}

// address: 0x10006177
PyObject *bex_AddActionStepSound(PyObject *self, PyObject *args) {
        const char *table, *action, *step_sound_table;

        if(!PyArg_ParseTuple(args, "sss", &table, &action, &step_sound_table))
                return NULL;

        return Py_BuildValue(
                "i",
                AddActionStepSound(table, action, step_sound_table)
        );
}


// address: 0x100061d1
PyObject *bex_AddTextureMaterial(PyObject *self, PyObject *args) {
        const char *texture, *material;

        if (!PyArg_ParseTuple(args, "ss", &texture, &material))
                return NULL;

        return Py_BuildValue("i", AddTextureMaterial(texture, material));
}


// address: 0x10006223
PyObject *bex_GetMusicEventPriority(PyObject *self, PyObject *args) {
        int unknown;

        if (!PyArg_ParseTuple(args, "i", &unknown))
                return NULL;

        return Py_BuildValue("i", GetMusicEventPriority(unknown));
}


// address: 0x1000626d
PyObject *bex_GetMusicEvent(PyObject *self, PyObject *args) {
        const char *event_name;

        if (!PyArg_ParseTuple(args, "s", &event_name))
                return NULL;

        return Py_BuildValue("i", getMusicEvent(event_name));
}


// address: 0x100062b7
PyObject *bex_ExeMusicEvent(PyObject *self, PyObject *args) {
        int unknown1, unknown2 = 0;

        if (!PyArg_ParseTuple(args, "i|i", &unknown1, &unknown2))
                return NULL;

        return Py_BuildValue("i", exeMusicEvent(unknown1, (unknown2 != 0) ));
}


// address: 0x10006316
PyObject *bex_AddMusicEventCD(PyObject *self, PyObject *args) {
        const char *lpszEventName;
        int iTrack, bBackGround, iNext;
        double dFIn, dFOut, fVolume, fPriority; 

        if (!PyArg_ParseTuple(
                args, "siddddii", &lpszEventName, &iTrack, &dFIn, &dFOut,
                &fVolume, &fPriority, &bBackGround, &iNext
        ))
                return NULL;

        return Py_BuildValue(
                "i", addMusicEventCD(
                        lpszEventName, iTrack, dFIn, dFOut, fVolume, fPriority,
                        (bBackGround != 0), iNext
                )
        );
}


// address: 0x100063b2
PyObject *bex_AddMusicEventMP3(PyObject *self, PyObject *args) {
        const char *lpszEventName, *lpszFile;
        int bBackGround, iNext, unknown = 0;
        double dFIn, fVolume, dFOut, fPriority; 

        if (!PyArg_ParseTuple(
                args, "ssddddii|i", &lpszEventName, &lpszFile, &dFIn, &dFOut,
                &fVolume, &fPriority, &bBackGround, &iNext, &unknown
        ))
                return NULL;

        return Py_BuildValue(
                "i", addMusicEventMP3(
                        lpszEventName, lpszFile, dFIn, fVolume, dFOut,
                        fPriority, (bBackGround != 0), iNext, unknown
                )
        );
}


// address: 0x1000645d
PyObject *bex_AddMusicEventWAV(PyObject *self, PyObject *args) {
        const char *lpszEventName, *lpszFile;
        int bBackGround, iNext, opened = 0;
        double dFIn, fVolume, dFOut, fPriority; 

        if (!PyArg_ParseTuple(
                args, "ssddddii|i", &lpszEventName, &lpszFile, &dFIn, &dFOut,
                &fVolume, &fPriority, &bBackGround, &iNext, &opened
        ))
                return NULL;

        return Py_BuildValue(
                "i", addMusicEventWAV(
                        lpszEventName, lpszFile, dFIn, fVolume, dFOut,
                        fPriority, (bBackGround != 0), iNext, opened
                )
        );
}


// address: 0x10006508
PyObject *bex_AddMusicEventADPCM(PyObject *self, PyObject *args) {
        const char *lpszEventName, *lpszFile;
        int bBackGround, iNext, unknown = 0;
        double dFIn, fVolume, dFOut, fPriority; 

        if (!PyArg_ParseTuple(
                args, "ssddddii|i", &lpszEventName, &lpszFile, &dFIn, &dFOut,
                &fVolume, &fPriority, &bBackGround, &iNext, &unknown
        ))
                return NULL;

        return Py_BuildValue(
                "i", addMusicEventADPCM(
                        lpszEventName, lpszFile, dFIn, fVolume, dFOut,
                        fPriority, (bBackGround != 0), iNext, unknown
                )
        );
}


// address: 0x100065b3
PyObject *bex_YSSInfo(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, "")) {
                PyErr_SetString(
                        PyExc_RuntimeError,
                        "Wrong number of arguments in tuple."
                );
                return NULL;
        }

        return Py_BuildValue("i", dropDebugInfo());
}


// address: 0x10006607
PyObject *bex_LoadSoundDataBase(PyObject *self, PyObject *args) {
        const char *file_name;

        if (!PyArg_ParseTuple(args, "s", &file_name)) {
                PyErr_SetString(
                        PyExc_RuntimeError,
                        "Wrong number of arguments in tuple."
                );
                return NULL;
        }

        return Py_BuildValue("i", loadSoundDataBase(file_name));
}


// address: 0x10006668
PyObject *bex_SaveSoundDataBase(PyObject *self, PyObject *args) {
        const char *file_name;

        if (!PyArg_ParseTuple(args, "s", &file_name)) {
                PyErr_SetString(
                        PyExc_RuntimeError,
                        "Wrong number of arguments in tuple."
                );
                return NULL;
        }

        return Py_BuildValue("i", saveSoundDataBase(file_name));
}


// address: 0x100066c9
PyObject *bex_LoadMusicState(PyObject *self, PyObject *args) {
        const char *file_name;

        if (!PyArg_ParseTuple(args, "s", &file_name)) {
                PyErr_SetString(
                        PyExc_RuntimeError,
                        "Wrong number of arguments in tuple."
                );
                return NULL;
        }

        return Py_BuildValue("i", loadMusicState(file_name));
}


// address: 0x1000672a
PyObject *bex_SaveMusicState(PyObject *self, PyObject *args) {
        const char *file_name;

        if (!PyArg_ParseTuple(args, "s", &file_name)) {
                PyErr_SetString(
                        PyExc_RuntimeError,
                        "Wrong number of arguments in tuple."
                );
                return NULL;
        }

        return Py_BuildValue("i", saveMusicState(file_name));
}


// address: 0x1000678b
PyObject *bex_TakeSnapShot(PyObject *self, PyObject *args) {

        TakeSnapShot();

        return Py_BuildValue("i", 1);
}


// address: 0x100067a6
PyObject *bex_SaveStats(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, "")) {
                PyErr_SetString(
                        PyExc_RuntimeError,
                        "Wrong number of arguments in tuple."
                );
                return NULL;
        }

        saveSoundStats("sndinfo.txt");

        return Py_BuildValue("i", 1);
}


// address: 0x100067fa
PyObject *bex_GetMouseState(PyObject *self, PyObject *args) {
        int invert;
        double xsens, ysens;

        if (!PyArg_ParseTuple(args, "")) {
                PyErr_SetString(
                        PyExc_RuntimeError,
                        "Wrong number of arguments in tuple."
                );
                return NULL;
        }

        GetMouseState(&invert, &xsens, &ysens);

        return Py_BuildValue("idd", invert, xsens, ysens);
}


// address: 0x1000686c
PyObject *bex_SetMouseState(PyObject *self, PyObject *args) {
        int invert;
        double xsens, ysens;

        if (!PyArg_ParseTuple(args, "idd", &invert, &xsens, &ysens)) {
                PyErr_SetString(
                        PyExc_RuntimeError,
                        "Wrong number of arguments in tuple."
                );
                return NULL;
        }

        SetMouseState(invert, xsens, ysens);

        return Py_BuildValue("");
}


// address: 0x100068de
PyObject *bex_GetPTime(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, "")) {
                PyErr_SetString(
                        PyExc_RuntimeError,
                        "Wrong number of arguments in tuple."
                );
                return NULL;
        }

        return Py_BuildValue("d", GetPSeconds());
}


// address: 0x1000692e
PyObject *bex_GetAnmRaces(PyObject *self, PyObject *args) {
        int num_races, i;
        PyObject *list, *race_name_obj;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        num_races = GetnRaces();

        list = PyList_New(num_races);

        for (i = 0; i < num_races; i++) {
            race_name_obj = PyString_FromString(GetRaceName(i));
            PyList_SetItem(list, i, race_name_obj);
        }

        return list;
}


// address: 0x100069b9
PyObject *bex_BodInspector(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, "")) {
                PyErr_SetString(
                        PyExc_RuntimeError,
                        "Wrong number of arguments in tuple."
                );
                return NULL;
        }

        BodInspector();
        return Py_BuildValue("");
}


// address: 0x10006a03
PyObject *bex_SetRunString(PyObject *self, PyObject *args) {
        const char *variable;

        if(!PyArg_ParseTuple(args, "s", &variable))
                return NULL;

        SetRunString(variable);

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x10006a4d
PyObject *bex_SetStringValue(PyObject *self, PyObject *args) {
        const char *variable, *value;

        if(!PyArg_ParseTuple(args, "ss", &variable, &value))
                return NULL;

        return Py_BuildValue("i", SetStringValue(variable, value));
}


// address: 0x10006a9f
PyObject *bex_GetStringValue(PyObject *self, PyObject *args) {
        const char *variable, *value;

        if(!PyArg_ParseTuple(args, "s", &variable))
                return NULL;

        value = GetStringValue(variable);
        if (value)
            return Py_BuildValue("s", value);

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x10006b08
PyObject *bex_DeleteStringValue(PyObject *self, PyObject *args) {
        const char *variable;

        if(!PyArg_ParseTuple(args, "s", &variable))
                return NULL;

        return Py_BuildValue("i", DeleteStringValue(variable));
}


// address: 0x10006b52
PyObject *bex_SaveEntitiesData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", SaveEntitiesData(file_name));
}


// address: 0x10006b9c
PyObject *bex_LoadEntitiesData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", LoadEntitiesData(file_name));
}


// address: 0x10006be6
PyObject *bex_SaveParticleSystemsData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", SaveParticleSystemsData(file_name));
}


// address: 0x10006c30
PyObject *bex_LoadParticleSystemsData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", LoadParticleSystemsData(file_name));
}


// address: 0x10006c7a
PyObject *bex_SaveCombustionData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", SaveCombustionData(file_name));
}


// address: 0x10006cc4
PyObject *bex_LoadCombustionData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", LoadCombustionData(file_name));
}


// address: 0x10006d0e
PyObject *bex_ReassignCombustionData(PyObject *self, PyObject *args) {

        ReassignCombustionData();

        return Py_BuildValue("i", 1);
}


// address: 0x10006d29
PyObject *bex_SaveAnmRaceData(PyObject *self, PyObject *args) {
        const char *file_name, *race;

        if(!PyArg_ParseTuple(args, "ss", &file_name, &race))
                return NULL;

        return Py_BuildValue("i", SaveAnmRaceData(file_name, race));
}


// address: 0x10006d7b
PyObject *bex_LoadAnmRaceData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", LoadAnmRaceData(file_name));
}


// address: 0x10006dc5
PyObject *bex_SaveAnmSoundData(PyObject *self, PyObject *args) {
        const char *file_name, *race;

        if(!PyArg_ParseTuple(args, "ss", &file_name, &race))
                return NULL;

        return Py_BuildValue("i", SaveAnmSoundData(file_name, race));
}


// address: 0x10006e17
PyObject *bex_LoadAnmSoundData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i",  LoadAnmSoundData(file_name));
}


// address: 0x10006e61
PyObject *bex_GetSaveInfo(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return GetSaveInfo();
}


// address: 0x10006e86
PyObject *bex_SetSaveInfo(PyObject *self, PyObject *args) {
        PyObject *info;

        if(!PyArg_ParseTuple(args, "O", &info))
                return NULL;

        return Py_BuildValue("i", SetSaveInfo(info));
}


// address: 0x10006ed0
PyObject *bex_HeapCheckSetMark(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", heap_check_set_mark());
}


// address: 0x10006f0c
PyObject *bex_PerformHeapCheck(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        perform_heap_check();

        return Py_BuildValue("i", 1);
}


// address: 0x10006f40
PyObject *bex_HeapCheckAllAllocations(PyObject *self, PyObject *args) {
        int i;

        if (!PyArg_ParseTuple(args, "i", &i))
                return NULL;

        heap_check_all_allocations(i);

        return Py_BuildValue("i", 1);
}


// address: 0x10006f82
PyObject *bex_HeapCheckDelayFree(PyObject *self, PyObject *args) {
        int i;

        if (!PyArg_ParseTuple(args, "i", &i))
                return NULL;

        heap_check_delay_free(i);

        return Py_BuildValue("i", 1);
}


// address: 0x10006fc4
PyObject *bex_HeapCheckSystemMemory(PyObject *self, PyObject *args) {
        int i;

        if (!PyArg_ParseTuple(args, "i", &i))
                return NULL;

        heap_check_system_memory(i);

        return Py_BuildValue("i", 1);
}


// address: 0x10007006
PyObject *bex_HeapCheckLeaks(PyObject *self, PyObject *args) {
        int i;

        if (!PyArg_ParseTuple(args, "i", &i))
                return NULL;

        heap_check_leaks(i);

        return Py_BuildValue("i", 1);
}


// address: 0x10007048
PyObject *bex_OpenProfileSection(PyObject *self, PyObject *args) {
        int section;
        const char *comment = "";

        if(!PyArg_ParseTuple(args, "i|s", &section, &comment))
                return NULL;

        return Py_BuildValue("i", OpenProfileSection(section, comment));
}

// address: 0x100070a1
PyObject *bex_CloseProfileSection(PyObject *self, PyObject *args) {
        int section;

        if(!PyArg_ParseTuple(args, "i", &section))
                return NULL;

        return Py_BuildValue("i", CloseProfileSection(section));
}


// address: 0x100070eb
PyObject *bex_StartProfile(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", StartProfile());
}


// address: 0x10007128
PyObject *bex_EnableProfiler(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", EnableProfiler());
}


// address: 0x10007165
PyObject *bex_DisableProfiler(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", DisableProfiler());
}


// address: 0x100071a2
PyObject *bex_SaveProfileData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", SaveProfileData(file_name));
}


// address: 0x100071ec
PyObject *bex_SetInputMode(PyObject *self, PyObject *args) {
        const char *device, *mode;

        if(!PyArg_ParseTuple(args, "ss", &device, &mode))
                return NULL;

        return Py_BuildValue("i", SetInputMode(device, mode));
}


// address: 0x1000723e
PyObject *bex_GetInputMode(PyObject *self, PyObject *args) {
        const char *device;

        if(!PyArg_ParseTuple(args, "s", &device))
                return NULL;

        return Py_BuildValue("s", GetInputMode(device));
}


// address: 0x10007288
PyObject *bex_SaveScreenShot(PyObject *self, PyObject *args) {
        const char *file_name;
        int width, height;

        if(!PyArg_ParseTuple(args, "sii", &file_name, &width, &height))
                return NULL;

        SaveScreeShoot(file_name, width, height);

        return Py_BuildValue("i", 1);
}


// address: 0x100072dd
PyObject *bex_CleanArea(PyObject *self, PyObject *args) {
        float x, y, z, distance;

        if(!PyArg_ParseTuple(args, "ffff", &x, &y, &z, &distance))
                return NULL;

        CleanArea(x, y, z, distance);

        return Py_BuildValue("i", 1);
}


// address: 0x1000737B

/* Use stdcall to avoid generation underscores */
LIB_EXP __stdcall void initBladex()
{
        int i;

        for( i = 0; i < sizeof(init_funcs)/sizeof(init_funcs[0]); i++)
                if (init_funcs[i])
                        init_funcs[i]();

        Py_InitModule4("Bladex", methods, NULL, NULL, PYTHON_API_VERSION);
}




// address: 0x1000a010
PyObject *get_entity_by_name(const char *name) {
        entity_t *entity;
        bld_py_entity_t *entity_obj;

        entity = GetEntity(name);
        if (entity != NULL) {
                entity_obj = PyObject_NEW(bld_py_entity_t, &entityTypeObject);
                if (entity_obj != NULL) {
                        entity_obj->name = strdup(name);
                        return (PyObject *)entity_obj;
                } else {
                        return NULL;
                }
        }

        return NULL;
}

// address: 0x1000a076
PyObject *get_entity_by_index(int index) {
        entity_t *entity;
        bld_py_entity_t *entity_obj;

        entity = GetEntityI(index);
        if (entity != NULL) {
                entity_obj = PyObject_NEW(bld_py_entity_t, &entityTypeObject);
                if (entity_obj != NULL) {
                        entity_obj->name = strdup(GetEntityName(entity));
                        return (PyObject *)entity_obj;
                } else {
                        return NULL;
                }
        }

        return NULL;
}


// address: 0x1000a0e6
PyObject *create_entity(
        const char *name, const char *kind, double x, double y, double z,
        const char *parent_class, const char *unknown
) {
        entity_t *entity;
        bld_py_entity_t *entity_obj;

        entity_obj = PyObject_NEW(bld_py_entity_t, &entityTypeObject);
        if (entity_obj == NULL)
                return NULL;

        entity = CreateEntity(name, kind, x, y, z, parent_class, unknown);
        if (entity == NULL)
                return NULL;

        entity_obj->name = strdup(GetEntityName(entity));
        return (PyObject *)entity_obj;
}


// address: 0x1000a179
PyObject *create_entity_decal(
        const char *name, double x, double y, double z, int i_unknown,
        double d_unknown1, double d_unknown2
) {
        entity_t *entity;
        bld_py_entity_t *entity_obj;

        entity_obj = PyObject_NEW(bld_py_entity_t, &entityTypeObject);
        if (entity_obj == NULL)
                return NULL;



        entity = CreateEntityDecal(
                name, x, y, z, i_unknown, d_unknown1, d_unknown2
        );
        if (entity == NULL)
                return NULL;

        entity_obj->name = strdup(GetEntityName(entity));
        return (PyObject *)entity_obj;
}


// address: 0x1000a214
PyObject *create_spark(
        const char *name, double x, double y, double z, double x_spark_dir,
        double y_spark_dir, double z_spark_dir, double d_unknown1,
        double d_unknown2, double d_unknown3, double d_unknown4,
        double d_unknown5, int i_unknown6, int i_unknown7, int i_unknown8,
        int i_unknown9, int i_unknown10, int i_unknown11, double d_unknown12,
        double d_unknown13, double d_unknown14, int i_unknown15
) {
        entity_t *entity;
        bld_py_entity_t *entity_obj;
        point_3d_t spark_point, spark_dir;

        entity_obj = PyObject_NEW(bld_py_entity_t, &entityTypeObject);
        if (entity_obj == NULL)
                return NULL;

        spark_dir.x = x_spark_dir;
        spark_dir.y = y_spark_dir;
        spark_dir.z = z_spark_dir;

        spark_point.x = x;
        spark_point.y = y;
        spark_point.z = z;

        entity = CreateSpark(
                name, &spark_point, &spark_dir, d_unknown1, d_unknown2,
                d_unknown3, d_unknown4, d_unknown5, i_unknown6, i_unknown7,
                i_unknown8, i_unknown9, i_unknown10, i_unknown11, d_unknown12,
                d_unknown13, d_unknown14, i_unknown15
        );
        if (entity == NULL)
                return NULL;

        entity_obj->name = strdup(GetEntityName(entity));

        return (PyObject *)entity_obj;
}


// address: 0x1000a349
PyObject *bex_ent_SeverLimb(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        entity_t *limb_entity;
        bld_py_entity_t *limb_entity_obj;
        int limb;

        if(!PyArg_ParseTuple(args, "i", &limb))
                return Py_BuildValue("i", 0);

        limb_entity = SeverLimb(entity->name, limb);
        if (limb_entity == NULL)
                return Py_BuildValue("i", 0);


        limb_entity_obj = PyObject_NEW(bld_py_entity_t, &entityTypeObject);
        if (limb_entity_obj == NULL)
                return Py_BuildValue("i", 0);

        limb_entity_obj->name = strdup(GetEntityName(limb_entity));
        return (PyObject *)limb_entity_obj;
}


// address: 0x1000a410
PyObject *bex_ent_ResetWounds(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        code = ResetWounds(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000a45b
PyObject *bex_ent_Impulse(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double x, y, z;

        if (!PyArg_ParseTuple(args, "ddd", &x, &y, &z))
                return NULL;

        code = SetEntityVectorProperty(
                entity->name, ENT_VEC_IMPULSE, 0, x, y, z
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000a4e8
PyObject *bex_ent_ImpulseC(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double x, y, z, x_vec, y_vec, z_vec;

        if (!PyArg_ParseTuple(
                args, "dddddd", &x, &y, &z, &x_vec, &y_vec, &z_vec
        ))
                return NULL;

        code = ImpulseC(entity->name, x, y, z, x_vec, y_vec, z_vec);

        return Py_BuildValue("i", code);
}


// address: 0x1000a57f
PyObject *bex_ent_Fly(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double velocity_x, velocity_y, velocity_z;

        if (!PyArg_ParseTuple(
                args, "ddd", &velocity_x, &velocity_y, &velocity_z
        ))
                return NULL;

        code = SetEntityVectorProperty(
                entity->name, ENT_VEC_FLY_VELOCITY, 0, velocity_x, velocity_y,
                velocity_z
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000a60c
PyObject *bex_ent_AddCameraEvent(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int frame;
        PyObject *func;

        if (!PyArg_ParseTuple(args, "iO", &frame, &func))
                return NULL;

        code = AddCameraEvent(entity->name, frame, func);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000a6ee
PyObject *bex_ent_SubscribeToList(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *timer_name;

        if (!PyArg_ParseTuple(args, "s", &timer_name))
                return NULL;

        code = SubscribeEntityToList(entity->name, timer_name);
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000a75b
PyObject *bex_ent_MessageEvent(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int message_type, unknown1, unknown2;

        if (!PyArg_ParseTuple(args, "iii", &message_type, &unknown1, &unknown2))
                return NULL;

        code = MessageEvent(entity->name, message_type, unknown1, unknown2);

        return Py_BuildValue("i", code);
}


// address: 0x1000a7c2
PyObject *bex_ent_Rel2AbsPoint(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *anchor_name = NULL;
        double x_rel, y_rel, z_rel, x_abs, y_abs, z_abs;
        PyObject *tuple, *xObj, *yObj, *zObj;

        if(!PyArg_ParseTuple(
                args, "ddd|s", &x_rel, &y_rel, &z_rel, &anchor_name
        ))
                return NULL;

        if (anchor_name) {
                Rel2AbsPointN(
                        entity->name, x_rel, y_rel, z_rel, anchor_name,
                        &x_abs, &y_abs, &z_abs
                );

                tuple = PyTuple_New(3);

                xObj = PyFloat_FromDouble(x_abs);
                yObj = PyFloat_FromDouble(y_abs);
                zObj = PyFloat_FromDouble(z_abs);

                PyTuple_SET_ITEM(tuple, 0, xObj);
                PyTuple_SET_ITEM(tuple, 1, yObj);
                PyTuple_SET_ITEM(tuple, 2, zObj);

                return tuple;
        }

        Rel2AbsPoint(entity->name, x_rel, y_rel, z_rel, &x_abs, &y_abs, &z_abs);

        tuple = PyTuple_New(3);

        xObj = PyFloat_FromDouble(x_abs);
        yObj = PyFloat_FromDouble(y_abs);
        zObj = PyFloat_FromDouble(z_abs);

        PyTuple_SET_ITEM(tuple, 0, xObj);
        PyTuple_SET_ITEM(tuple, 1, yObj);
        PyTuple_SET_ITEM(tuple, 2, zObj);

        return tuple;
}


// address: 0x1000a95f
PyObject *bex_ent_Rel2AbsVector(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *anchor_name;
        double x_rel, y_rel, z_rel, x_abs, y_abs, z_abs;
        PyObject *tuple, *xObj, *yObj, *zObj;

        if (!PyArg_ParseTuple(args, "ddd", &x_rel, &y_rel, &z_rel)) {
                PyErr_Clear();

                if (!PyArg_ParseTuple(args, "ddds", &x_rel, &y_rel, &z_rel, &anchor_name))
                        return Py_BuildValue("i", 0);

                Rel2AbsVectorN(
                        entity->name, x_rel, y_rel, z_rel, anchor_name, &x_abs,
                        &y_abs, &z_abs
                );

                tuple = PyTuple_New(3);

                xObj = PyFloat_FromDouble(x_abs);
                yObj = PyFloat_FromDouble(y_abs);
                zObj = PyFloat_FromDouble(z_abs);

                PyTuple_SET_ITEM(tuple, 0, xObj);
                PyTuple_SET_ITEM(tuple, 1, yObj);
                PyTuple_SET_ITEM(tuple, 2, zObj);

                return tuple;
        }

        Rel2AbsVector(entity->name, x_rel, y_rel, z_rel, &x_abs, &y_abs, &z_abs);

        tuple = PyTuple_New(3);

        xObj = PyFloat_FromDouble(x_abs);
        yObj = PyFloat_FromDouble(y_abs);
        zObj = PyFloat_FromDouble(z_abs);

        PyTuple_SET_ITEM(tuple, 0, xObj);
        PyTuple_SET_ITEM(tuple, 1, yObj);
        PyTuple_SET_ITEM(tuple, 2, zObj);

        return tuple;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000af0c
PyObject *bex_ent_GetDummyAxis(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *anchor_name;
        double x_dir, y_dir, z_dir, x_dummy_axis, y_dummy_axis, z_dummy_axis;
        PyObject *tuple, *xObj, *yObj, *zObj;
        int unknown = 1;

        if (!PyArg_ParseTuple(
                args, "sddd|i", &anchor_name, &x_dir, &y_dir, &z_dir, &unknown
        ))
                return NULL;

        GetDummyAxis(
                entity->name, anchor_name, x_dir, y_dir, z_dir, &x_dummy_axis,
                &y_dummy_axis, &z_dummy_axis, unknown
        );

        tuple = PyTuple_New(3);

        xObj = PyFloat_FromDouble(x_dummy_axis);
        yObj = PyFloat_FromDouble(y_dummy_axis);
        zObj = PyFloat_FromDouble(z_dummy_axis);

        PyTuple_SET_ITEM(tuple, 0, xObj);
        PyTuple_SET_ITEM(tuple, 1, yObj);
        PyTuple_SET_ITEM(tuple, 2, zObj);

        return tuple;
}


// address: 0x1000b003
PyObject *bex_ent_SQDistance2(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity1 = (bld_py_entity_t *)self;
        bld_py_entity_t *entity2 = NULL;

        if (!PyArg_ParseTuple(args, "O", &entity2))
                return NULL;

        return PyFloat_FromDouble(SQDistance2(entity1->name, entity2->name));
}


// address: 0x1000b069
PyObject *bex_ent_RemoveFromList(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *timer_name;

        if (!PyArg_ParseTuple(args, "s", &timer_name))
                return NULL;

        code = RemoveEntityFromList(entity->name, timer_name);
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000b145
PyObject *bex_ent_RemoveFromInventRight(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = RemoveFromInventRight(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000b1aa
PyObject *bex_ent_RemoveFromInventLeft(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = RemoveFromInventLeft(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000b274
PyObject *bex_ent_LaunchAnimation(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *anm_name;

        if (!PyArg_ParseTuple(args, "s", &anm_name))
                return NULL;


        code = SetEntityStringProperty(
                entity->name, ENT_STR_ANIM_FULL_NAME, 0, anm_name
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000b35e
PyObject *bex_ent_LaunchAnmType(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *anm_type;
        int index = 0;

        if (!PyArg_ParseTuple(args, "s|i", &anm_type, &index))
                return NULL;

        code = SetEntityStringProperty(
                entity->name, ENT_STR_ANIM_NAME, index, anm_type
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000b3de
PyObject *bex_ent_GotAnmType(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *anm_type;

        if (!PyArg_ParseTuple(args, "s", &anm_type))
                return NULL;

        code = SetEntityStringProperty(
                entity->name, ENT_STR_GOT_ANM_TYPE, 0, anm_type
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000b451
PyObject *bex_ent_SetMesh(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *mesh;

        if (!PyArg_ParseTuple(args, "s", &mesh))
                return NULL;

        code = SetEntityStringProperty(entity->name, ENT_STR_MESH, 0, mesh);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000b4c4
PyObject *bex_ent_SetTmpAnmFlags(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int wuea, mod_y, solf, copy_rot, bng_mov, headf;
        int unknown = 1;

        if (!PyArg_ParseTuple(
                args, "iiiiii|i", &wuea, &mod_y, &solf, &copy_rot, &bng_mov,
                &headf, &unknown
        ))
                return NULL;

        code = SetTmpAnmFlags(
                entity->name, wuea, mod_y, solf, copy_rot, bng_mov, headf,
                unknown
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000b609
PyObject *bex_ent_SetActiveEnemy(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        bld_py_entity_t *active_enemy;
        const char *active_enemy_name;
        int unknown;

        if (!PyArg_ParseTuple(args, "O", &active_enemy))
                return NULL;

        active_enemy_name = NULL;
        if ( active_enemy && (active_enemy->ob_type == &entityTypeObject))
                active_enemy_name = active_enemy->name;

        code = SetActiveEnemy(entity->name, active_enemy_name, &unknown);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", unknown);
}


// address: 0x1000b6a0
PyObject *bex_ent_CanISee(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        bld_py_entity_t *seen_entity;
        int canISee;
        int code;
        const char *seen_entity_name;

        if (!PyArg_ParseTuple(args, "O", &seen_entity))
                return NULL;

        seen_entity_name = NULL;
        if (seen_entity != NULL)
                seen_entity_name = seen_entity->name;

        code = CanISee(entity->name, seen_entity_name, &canISee);
        if (code != 1)
                return Py_BuildValue("i", 0);

        return Py_BuildValue("i", canISee);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000b7da
PyObject *bex_ent_ExcludeHitFor(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        bld_py_entity_t *exclude_for_entity;
        void *unknown;
        int code;

        if(!PyArg_ParseTuple(args, "O", &exclude_for_entity))
                return NULL;

        if (exclude_for_entity && (PyObject *)exclude_for_entity != Py_None)
                code = ExcludeHitFor(
                        entity->name, exclude_for_entity->name, &unknown
                );
        else
                code = -1;

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000b914
PyObject *bex_ent_Unlink(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        bld_py_entity_t *child;
        void *unknown;

        if (!PyArg_ParseTuple(args, "O", &child))
                return NULL;

        if (child == NULL)
                code = -1;
        else
                code = UnlinkChild(entity->name, child->name, &unknown);

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000b9a6
PyObject *bex_ent_Link(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        bld_py_entity_t *child;
        void *unknown;

        if (!PyArg_ParseTuple(args, "O", &child))
                return NULL;

        if (child == NULL)
                code = -1;
        else
                code = Link(entity->name, child->name, &unknown);

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000ba38
PyObject *bex_ent_LinkAnchors(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;/* FIXME uninitialised code */
        const char *entity_anchor, *child_anchor;
        bld_py_entity_t *child;
        void *unknown;

        if (PyArg_ParseTuple(args, "sOs", &entity_anchor, &child, &child_anchor)) {
                if (child == NULL)
                        code = -1;
                else
                        code = LinkAnchors(
                                entity->name, entity_anchor, child->name,
                                child_anchor, &unknown
                        );
        }

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000bad4
PyObject *bex_ent_LinkToNode(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int node_index;
        bld_py_entity_t *child;
        void *unknown;

        if (!PyArg_ParseTuple(args, "Oi", &child, &node_index))
                return NULL;

        if (child)
                code = LinkToNode(
                        entity->name, child->name, node_index, &unknown
                );
        else
                code = -1;

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000bb6e
PyObject *bex_ent_GetNodeIndex(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *node_name;
        int index = -1;

        if (!PyArg_ParseTuple(args, "s", &node_name))
                return NULL;

        GetNodeIndex(entity->name, node_name, &index);

        return Py_BuildValue("i", index);
}


// address: 0x1000bbd9
PyObject *bex_ent_GetNChildren(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetNChildren(entity->name));
}


// address: 0x1000bc31
PyObject *bex_ent_GetChild(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int index;

        if (!PyArg_ParseTuple(args, "i", &index))
                return NULL;

        return Py_BuildValue("s", GetChild(entity->name, index));
}


// address: 0x1000bc8a
PyObject *bex_ent_InsideActionArea(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int action_area, is_inside;

        if (!PyArg_ParseTuple(args, "i", &action_area))
                return NULL;

        code = InsideActionArea(entity->name, action_area, &is_inside);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", is_inside);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000bffb
PyObject *bex_ent_UnlinkChildren(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = UnlinkChilds(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000c168
PyObject *bex_ent_GetEnemyName(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *enemy_name;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        enemy_name = GetEnemy(entity->name);
        if (enemy_name == NULL)
                return PyString_FromString("");

        return PyString_FromString(enemy_name);
}


// address: 0x1000c1c8
PyObject *bex_ent_Chase(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        bld_py_entity_t *enemy;
        const char *enemy_name;
        int action_area;

        if (!PyArg_ParseTuple(args, "Oi", &enemy, &action_area))
                return NULL;

        enemy_name = NULL;
        if (enemy != NULL)
                enemy_name = enemy->name;

        code = Chase(entity->name, enemy_name, action_area);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);

}


// address: 0x1000c255
PyObject *bex_ent_ResetChase(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = ResetChase(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000c2ba
PyObject *bex_ent_GoTo(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int x, y, z;

        if (!PyArg_ParseTuple(args, "iii", &x, &y, &z))
                return NULL;

        code = GoTo(entity->name, x, y, z);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000c339
PyObject *bex_ent_CanGoTo(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int x, y, z;

        if (!PyArg_ParseTuple(args, "iii", &x, &y, &z))
                return NULL;

        code = CanGoTo(entity->name, x, y, z);
        if (code != 1) {
                return Py_BuildValue("i", 0);
        } else {
                return Py_BuildValue("i", 1);
        }
}


// address: 0x1000c3b8
PyObject *bex_ent_LookAtEntity(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *look_at_entity_name;

        if (!PyArg_ParseTuple(args, "s", &look_at_entity_name))
                return NULL;

        code = LookAtEntity(entity->name, look_at_entity_name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000c427
PyObject *bex_ent_QuickFace(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double angle;

        if (!PyArg_ParseTuple(args, "d", &angle))
                return NULL;

        code = QuickFace(entity->name, angle);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000c49a
PyObject *bex_ent_Face(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double angle;

        if (!PyArg_ParseTuple(args, "d", &angle))
                return NULL;

        code = Face(entity->name, angle);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000c50d
PyObject *bex_ent_StartLooking(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int x, y, z;

        if (!PyArg_ParseTuple(args, "iii", &x, &y, &z))
                return NULL;

        code = StartLooking(entity->name, x, y, z);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}



// address: 0x1000c58c
PyObject *bex_ent_StopLooking(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;


        code = StopLooking(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/



// address: 0x1000c660
PyObject *bex_ent_GraspPos(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *grasp;
        double x, y, z;
        PyObject *tuple, *xObj, *yObj, *zObj;

        if (!PyArg_ParseTuple(args, "s", &grasp))
                return NULL;

        code = GraspPos(entity->name, grasp, &x, &y, &z);
        if (code != 1)
                return Py_BuildValue("i", 0);

        tuple = PyTuple_New(3);
        xObj = PyFloat_FromDouble(x);
        yObj = PyFloat_FromDouble(y);
        zObj = PyFloat_FromDouble(z);
        PyTuple_SetItem(tuple, 0, xObj);
        PyTuple_SetItem(tuple, 1, yObj);
        PyTuple_SetItem(tuple, 2, zObj);

        return tuple;
}


// address: 0x1000c785
PyObject *bex_ent_Freeze(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = Freeze(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000c7ea
PyObject *bex_ent_UnFreeze(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = UnFreeze(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000c84f
PyObject *bex_ent_SwitchTo1H(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = SwitchTo1H(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000c8b4
PyObject *bex_ent_SwitchToBow(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = SwitchToBow(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000c97e
PyObject *bex_ent_LaunchWatch(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = LaunchWatch(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000c9e3
PyObject *bex_ent_GetActionMode(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int action_mode;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = GetActionMode(entity->name, &action_mode);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", action_mode);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000cc55
PyObject *bex_ent_AddAnimSound(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *animation;
        bld_py_sound_t *sound;
        double time;

        if (!PyArg_ParseTuple(args, "sOd", &animation, &sound, &time)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return NULL;
        }

        if (sound->ob_type != &soundTypeObject) {
                PyErr_SetString(
                        PyExc_AttributeError, "Invalid Param: Not a sound."
                );
                return NULL;
        }

        code = AddSoundAnim(entity->name, animation, time, sound->soundID);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000cd17
PyObject *bex_ent_AddAnmEventFunc(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *anm_event;
        PyObject *func;

        if (!PyArg_ParseTuple(args, "sO", &anm_event, &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return NULL;
        }

        code = EntityAddAnmEventFunc(entity->name, anm_event, func);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000cda3
PyObject *bex_ent_DelAnmEventFunc(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *anm_event;

        if (!PyArg_ParseTuple(args, "s", &anm_event)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return NULL;
        }

        code = EntityDelAnmEventFunc(entity->name, anm_event);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000ce8b
PyObject *bex_ent_AddEventSound(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *event_name;
        bld_py_sound_t *sound;

        if (!PyArg_ParseTuple(args, "sO", &event_name, &sound)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return NULL;
        }

        if (sound->ob_type != &soundTypeObject) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param: Not a sound.");
                return NULL;
        }

        code = AddSoundEvent(entity->name, event_name, sound->soundID);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000cf41
PyObject *bex_ent_SlideTo(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double displacement, velocity, unknown;

        if (!PyArg_ParseTuple(args, "ddd", &displacement, &velocity, &unknown))
                return NULL;

        code = SetEntityVectorProperty(
                entity->name, ENT_VEC_SLIDE_TO, 0, displacement, velocity, unknown
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000d033
PyObject *bex_ent_CameraClearPath(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int node;

        if (!PyArg_Parse(args, "i", &node))
                return NULL;

        code = CameraClearPath(entity->name, node);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000d0a0
PyObject *bex_ent_CameraStartPath(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int node;

        if (!PyArg_Parse(args, "i", &node))
                return NULL;

        code = CameraStartPath(entity->name, node);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000d280
PyObject *bex_ent_TurnOn(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = TurnOnActor(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000d2e5
PyObject *bex_ent_TurnOff(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = TurnOffActor(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000d46c
PyObject *bex_ent_AddCameraNode(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int node;
        double time, x, y, z;

        if (!PyArg_ParseTuple(args, "idddd", &node, &time, &x, &y, &z))
                return NULL;

        if (node != 0)
                code = CameraAddTargetNode(entity->name, time, x, y, z);
        else
                code = CameraAddSourceNode(entity->name, time, x, y, z);

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000d5fa
PyObject *bex_ent_SetCameraStartTangentNode(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int node, unknown1;
        double unknown2, unknown3, unknown4;

        if (! PyArg_ParseTuple(
                args, "iiddd", &node, &unknown1, &unknown2, &unknown3, &unknown4
        ))
                return NULL;

        if (node != 0)
                code = CameraSetStartTangentTargetNode(
                        entity->name, unknown1, unknown2, unknown3, unknown4
                );
        else
                code = CameraSetStartTangentSourceNode(
                        entity->name, unknown1, unknown2, unknown3, unknown4
                );

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000d769
PyObject *bex_ent_SetCameraEndTangentNode(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code = 1;
        int node, unknown1;
        double unknown2, unknown3, unknown4;

        if (!PyArg_ParseTuple(
                args, "iiddd", &node, &unknown1, &unknown2, &unknown3, &unknown4
        ))
                return NULL;

        if (node != 0)
                CameraSetEndTangentTargetNode(
                        entity->name, unknown1, unknown2, unknown3, unknown4
                );
        else
                CameraSetEndTangentSourceNode(
                        entity->name, unknown1, unknown2, unknown3, unknown4
                );

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000d8d2
PyObject *bex_ent_SetPersonView(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *person_name;

        if (!PyArg_ParseTuple(args, "s", &person_name))
                return NULL;

        code = CameraSetPersonView(entity->name, person_name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000d93f
PyObject *bex_ent_SetMaxCamera(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        const char *cam_file_name;
        int i_unknown, num_frames;

        if (!PyArg_ParseTuple(args, "sii", &cam_file_name, &i_unknown, &num_frames))
                return NULL;

        code = CameraSetMaxCamera(entity->name, cam_file_name, i_unknown, num_frames);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000d9bc
PyObject *bex_ent_Cut(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = CameraCut(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000da21
PyObject *bex_ent_SetTravellingView(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int unknown1, unknown2;

        if (!PyArg_ParseTuple(args, "ii", &unknown1, &unknown2))
                return NULL;

        code = CameraSetTravelingView(entity->name, unknown1, unknown2);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000da96
PyObject *bex_ent_Rotate(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double x_dir, y_dir, z_dir, velocity;
        int unknown = 1;

        if (!PyArg_ParseTuple(
                args, "dddd|i", &x_dir, &y_dir, &z_dir, &velocity, &unknown
        ))
                return NULL;

        code = EntityRotate(
                entity->name, x_dir, y_dir, z_dir, velocity, unknown
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000dc02
PyObject *bex_ent_RotateRel(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double x, y, z, x_dir, y_dir, z_dir, angle;
        int i_unknown = 1;

        if (!PyArg_ParseTuple(
                args, "ddddddd|i", &x, &y, &z, &x_dir, &y_dir, &z_dir, &angle,
                &i_unknown
        ))
                return NULL;

        code = EntityRotateRel(
                entity->name, x, y, z, x_dir, y_dir, z_dir, angle, i_unknown
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000dcca
PyObject *bex_ent_Move(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double x, y, z;
        int unknown = 1;

        if (!PyArg_ParseTuple(args, "ddd|i", &x, &y, &z, &unknown))
                return NULL;

        code = EntityMove(entity->name, x, y, z, unknown);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000de9e
PyObject *bex_ent_GetGroupMembers(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *members;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        members = GetGroupMembers(entity->name);
        if (members == NULL)
                return Py_BuildValue("i", 0);

        return members;
}


// address: 0x1000def6
PyObject *bex_ent_GetCombatants(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *combatants;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        combatants = GetCombatants(entity->name);
        if (combatants == NULL) {
                return Py_BuildValue("i", 0);
        }

        return combatants;
}


// address: 0x1000df4e
PyObject *bex_ent_PutToWorld(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = EntityPutToWorld(entity->name);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000dfb3
PyObject *bex_ent_GetInventoryEntity(PyObject * self, PyObject * args) {
        assert(NULL);
        return NULL;
}


// address: 0x1000dfd8
PyObject *bex_ent_GetInventorySelected(PyObject * self, PyObject * args) {
        assert(NULL);
        return NULL;
}


// address: 0x1000dffd
PyObject *bex_ent_GetInventory(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *inventory;
        const char *name;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = GetEntityStringProperty(entity->name, ENT_STR_NAME, 0, &name);
        if ((code != 1) || (inventory = get_inventory(name)) == NULL) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Entity.");
                return NULL;
        }

        return inventory;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000e081
PyObject *bex_ent_RemoveFromWorld(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        EntityRemoveFromWorld(entity->name);

        return Py_BuildValue("i", 1);
}


// address: 0x1000e0c9
PyObject *bex_ent_RemoveFromWorldWithChilds(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        EntityRemoveFromWorldWithChilds(entity->name);

        return Py_BuildValue("i", 1);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000e17d
PyObject *bex_ent_SetSound(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *sound;
        int ret;

        if (!PyArg_ParseTuple(args, "s", &sound))
                return NULL;

        ret = SetSound(entity->name, sound);
        if (ret != 1)
            return Py_BuildValue("i", 0);
        else
            return Py_BuildValue("i", 1);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000e257
PyObject *bex_ent_PlaySound(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int i_unknown = -1;
        int code;

        if (!PyArg_ParseTuple(args, "|i", &i_unknown))
                return NULL;

        code = PlayEntitySound(entity->name, i_unknown);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000e2cb
PyObject *bex_ent_StopSound(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        double x, y, z;
        int code;

        if (!PyArg_ParseTuple(args, "ddd", &x, &y, &z)) {
                PyErr_Clear();
                if (!PyArg_ParseTuple(args, ""))
                        return NULL;

                code = Stop(entity->name);

        } else
                code = StopAt(entity->name, x, y, z);

        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000e385
PyObject *bex_ent_CatchOnFire(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        double x, y, z;
        int code;

        if (!PyArg_ParseTuple(args, "ddd", &x, &y, &z))
                return NULL;

        code = EntityCatchOnFire(entity->name, x, y, z);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000e40e
PyObject *bex_ent_GetParticleEntity(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *particle_entity_name;
        bld_py_entity_t *particle_entity;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        particle_entity = PyObject_NEW(bld_py_entity_t, &entityTypeObject);

        particle_entity_name = GetParticleEntity(entity->name);
        if (particle_entity_name == NULL)
                return Py_BuildValue("i", 0);

        particle_entity->name = strdup(particle_entity_name);

        return (PyObject *)particle_entity;
}


// address: 0x1000e49b
PyObject *bex_ent_DoAction(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *action_name;
        int code;

        if (!PyArg_ParseTuple(args, "s", &action_name))
                return NULL;

        code = DoAction(entity->name, action_name);

        return Py_BuildValue("i", code);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

// address: 0x1000e577
PyObject *bex_ent_SetOnFloor(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", SetOnFloor(entity->name));
}


// address: 0x1000e5c6
PyObject *bex_ent_RaiseEvent(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        const char *event_name;

        if (!PyArg_ParseTuple(args, "s", &event_name))
                return Py_BuildValue("i", 0);

        return Py_BuildValue("i", RaiseEvent(entity->name, event_name));
}


// address: 0x1000e62b
PyObject *bex_ent_SetWoundedZone(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int zone, is_active;

        if (!PyArg_ParseTuple(args, "ii", &zone, &is_active))
                return NULL;

        code = SetEntityIntProperty(
                entity->name, ENT_INT_WOUNDED_ZONES, zone, is_active
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000e6a2
PyObject *bex_ent_InterruptCombat(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;

        code = InterruptCombat(entity->name);
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000e6ed
PyObject *bex_ent_GetWoundedZone(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int zone, is_active;
        char buffer[512];

        if (PyArg_ParseTuple(args, "i", &zone)) {
                code = GetEntityIntProperty(
                        entity->name, ENT_INT_WOUNDED_ZONES, zone, &is_active
                );
                if (code == 1)
                        return PyInt_FromLong(is_active);

                if (code == -2) {
                        sprintf(
                                buffer,
                                "Unsupported error in BLADE_Entity_GetWoundedZone..."
                        );
                        PyErr_SetString(PyExc_AttributeError, buffer);
                        /*FIXME should be return*/
                }
        }

        PyErr_SetString(PyExc_AttributeError, "BLADE_Entity_GetWoundedZone");
        return NULL;
}


// address: 0x1000e798
PyObject *bex_ent_SetAuraActive(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int is_active;

        if (!PyArg_ParseTuple(args, "i", &is_active))
                return NULL;

        code = SetAuraActive(entity->name, is_active);
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}



// address: 0x1000e805
PyObject *bex_ent_SetAuraParams(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double size, alpha, colour_intensity;
        int hide_front_faces, hide_back_faces, alpha_mode;

        if (!PyArg_ParseTuple(
                args, "dddiii", &size, &alpha, &colour_intensity,
                &hide_front_faces, &hide_back_faces, &alpha_mode
        ))
                return NULL;

        code = SetAuraParams(
                entity->name, size, alpha, colour_intensity, hide_front_faces,
                hide_back_faces, alpha_mode
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x1000e8a6
PyObject *bex_ent_SetAuraGradient(PyObject *self, PyObject *args) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int gap;
        double r1, g1, b1, alpha1, starting_point;
        double r2, g2, b2, alpha2, ending_point;

        if (!PyArg_ParseTuple(
                args, "idddddddddd", &gap, &r1, &g1, &b1, &alpha1,
                &starting_point, &r2, &g2, &b2, &alpha2, &ending_point
        ))
                return NULL;

        code = SetAuraGradient(
                entity->name, gap, r1, g1, b1, alpha1, starting_point,
                r2, g2, b2, alpha2, ending_point
        );
        if (code != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

//TODO implement entity methods

PyObject* bex_ent_RemoveFromInvent(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_RemoveFromInvent", NULL);
}

PyObject* bex_ent_RemoveFromInventLeft2(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_RemoveFromInventLeft2", NULL);
}

PyObject* bex_ent_LaunchAnimation2(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_LaunchAnimation2", NULL);
}

PyObject* bex_ent_SetAnmFlags(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_SetAnmFlags", NULL);
}

PyObject* bex_ent_CanISeeFrom(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_CanISeeFrom", NULL);
}

PyObject* bex_ent_CheckAnimCol(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_CheckAnimCol", NULL);
}

PyObject* bex_ent_SetEnemy(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_SetEnemy", NULL);
}

PyObject* bex_ent_AddWatchAnim(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_AddWatchAnim", NULL);
}

PyObject* bex_ent_LaunchBayRoute(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_LaunchBayRoute", NULL);
}

PyObject* bex_ent_StartGrabbing(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_StartGrabbing", NULL);
}

PyObject* bex_ent_StopGrabbing(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_StopGrabbing", NULL);
}

PyObject* bex_ent_LookAt(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_LookAt", NULL);
}

PyObject* bex_ent_LookAtPerson(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_LookAtPerson", NULL);
}

PyObject* bex_ent_ClearAnmEventFuncs(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_ClearAnmEventFuncs", NULL);
}

PyObject* bex_ent_ClearPath(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_ClearPath", NULL);
}

PyObject* bex_ent_StartPath(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_StartPath", NULL);
}

PyObject* bex_ent_GoToPath(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_GoToPath", NULL);
}

PyObject* bex_ent_AddPathNode(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_AddPathNode", NULL);
}

PyObject* bex_ent_SetNodeStartTangent(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_SetNodeStartTangent", NULL);
}

PyObject* bex_ent_SetNodeEndTangent(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_SetNodeEndTangent", NULL);
}

PyObject* bex_ent_RotateAbs(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_RotateAbs", NULL);
}

PyObject* bex_ent_SetPosition(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_SetPosition", NULL);
}

PyObject* bex_ent_SetOrientation(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_SetOrientation", NULL);
}

PyObject* bex_ent_Use(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_Use", NULL);
}

PyObject* bex_ent_SetObjectSound(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_SetObjectSound", NULL);
}

PyObject* bex_ent_Abs2RelPoint(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_Abs2RelPoint", NULL);
}

PyObject* bex_ent_Abs2RelVector(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_Abs2RelVector", NULL);
}

PyObject* bex_ent_RemoveCameraEvent(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_RemoveCameraEvent", NULL);
}

PyObject* bex_ent_DoActionWI(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_DoActionWI", NULL);
}

PyObject* bex_ent_ExcludeHitInAnimationFor(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_ExcludeHitInAnimationFor", NULL);
}

PyObject* bex_ent_TestPos(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_TestPos", NULL);
}

PyObject* bex_ent_TestPosInOwnBox(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_TestPosInOwnBox", NULL);
}

PyObject* bex_ent_SetNextAttack(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_SetNextAttack", NULL);
}

PyObject* bex_ent_IsValid(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_ent_IsValid", NULL);
}


// address: 0x1000e9dd
void init_entity_properties() {
        property_kinds = (property_info_t *)malloc(
                MAX_PROPERTY_KINDS * sizeof(property_info_t)
        );
        insert_property("Data",                   -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_Data_get                  , bex_ent_Data_set);
        insert_property("__doc__",                -1                              , PROP_TYPE_OBJ, PROP_ONLY_GET   , bex_ent_doc_get                   , NULL);
        insert_property("Name",                   ENT_STR_NAME                    , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Kind",                   ENT_STR_KIND                    , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("SendSectorMsgs",         ENT_INT_SEND_SECTOR_MSGS        , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SendTriggerSectorMsgs",  ENT_INT_SEND_TRIGGER_SECTOR_MSGS, PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Scale",                  ENT_FLT_SCALE                   , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Position",               ENT_VEC_POSITION                , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("D",                      ENT_VEC_D                       , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("D1",                     ENT_VEC_D1                      , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("D2",                     ENT_VEC_D2                      , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Velocity",               ENT_VEC_VELOCITY                , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Gravity",                ENT_VEC_GRAVITY                 , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("AngularVelocity",        ENT_VEC_ANGULAR_VELOCITY        , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Life",                   ENT_FLT_LIFE                    , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Energy",                 ENT_FLT_ENERGY                  , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Level",                  ENT_INT_LEVEL                   , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("PartialLevel",           ENT_INT_PARTIAL_LEVEL           , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("InAttack",               ENT_INT_IN_ATTACK               , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InDestructorAttack",     ENT_INT_IN_DESTRUCTOR_ATTACK    , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("CombatDistFlag",         ENT_INT_COMBAT_DIST_FLAG        , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
/* FIXME two "Angle" properties */
        insert_property("Angle",                  ENT_FLT_ANGLE                   , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("T2Fall",                 ENT_FLT_T2_FALL                 , PROP_TYPE_FLT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Flick",                  ENT_INT_FLICK                   , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Intensity2",             ENT_FLT_INTENSITY2              , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("FlickPeriod",            ENT_FLT_FLICK_PERIOD            , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("LookAtTime",             ENT_FLT_LOOK_AT_TIME            , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Mass",                   ENT_FLT_MASS                    , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("TrailLifeTime",          ENT_FLT_TRAIL_LIFE_TIME         , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("TrailColor",             ENT_VEC_TRAIL_COLOR             , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("InventoryVisible",       ENT_INT_INVENTORY_VISIBLE       , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Visible",                ENT_INT_VISIBLE                 , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("CastShadows",            ENT_INT_CAST_SHADOWS            , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Gof",                    ENT_INT_GOF                     , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Gob",                    ENT_INT_GOB                     , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Aim",                    ENT_INT_AIM                     , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Tr",                     ENT_INT_TR                      , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Tl",                     ENT_INT_TL                      , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Run",                    ENT_INT_RUN                     , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Sneak",                  ENT_INT_SNEAK                   , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Attack",                 ENT_INT_ATTACK                  , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Block",                  ENT_INT_BLOCK                   , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ContinuousBlock",        ENT_INT_CONTINUOUS_BLOCK        , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Active",                 ENT_INT_ACTIVE                  , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Target",                 ENT_VEC_TARGET                  , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("MinSectorLength",        ENT_FLT_MIN_SECTOR_LENGTH       , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("MaxAmplitude",           ENT_FLT_MAX_AMPLITUDE           , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Damage",                 ENT_INT_DAMAGE                  , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("DamageRadius",           ENT_FLT_DAMAGE_RADIUS           , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SimpleSections",         ENT_INT_SIMPLE_SECTIONS         , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("OuterGlowColor",         ENT_VEC_OUTER_GLOW_COLOR        , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("InnerGlowColor",         ENT_VEC_INNER_GLOW_COLOR        , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("CoreGlowColor",          ENT_VEC_CORE_GLOW_COLOR         , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SendNotify",             ENT_INT_SEND_NOTIFY             , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Playing",                ENT_INT_PLAYING                 , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Blind",                  ENT_INT_BLIND                   , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Deaf",                   ENT_INT_DEAF                    , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("WillCrashInFloor",       ENT_INT_WILL_CRASH_IN_FLOOR     , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("GoToSneaking",           ENT_INT_GO_TO_SNEAKING          , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("GoToJogging",            ENT_INT_GO_TO_JOGGING           , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("OnFloor",                ENT_INT_ON_FLOOR                , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("TestHit",                ENT_INT_TEST_HIT                , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Displacement",           ENT_FLT_DISPLACEMENT            , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("DisplacementLimit",      ENT_FLT_DISPLACEMENT_LIMIT      , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("V_D",                    ENT_FLT_V_D                     , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("A_D",                    ENT_FLT_A_D                     , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("IsStopped",              ENT_INT_IS_STOPPED              , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Material",               ENT_STR_MATERIAL                , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Animation",              ENT_STR_ANIMATION               , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("FPS",                    ENT_FLT_F_P_S                   , PROP_TYPE_FLT, PROP_ONLY_SET   , NULL                              , NULL);
        insert_property("CurrentAreas",           ENT_INT_CURRENT_AREAS           , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("CharType",               ENT_STR_CHAR_TYPE               , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("CharTypeExt",            ENT_STR_CHAR_TYPE_EXT           , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Parent",                 ENT_STR_PARENT                  , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InitPos",                ENT_VEC_INIT_POS                , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("EnemyLastSeen",          ENT_VEC_ENEMY_LAST_SEEN         , PROP_TYPE_VEC, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("AstarState",             ENT_FLT_ASTAR_STATE             , PROP_TYPE_FLT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Will1aaTo2aa",           ENT_INT_WILL1AA_TO2AA           , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Wuea",                   ENT_FLT_WUEA                    , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("AnmPos",                 ENT_FLT_ANM_POS                 , PROP_TYPE_FLT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("RouteType",              ENT_FLT_ROUTE_TYPE              , PROP_TYPE_FLT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("BayRoute",               ENT_FLT_BAY_ROUTE               , PROP_TYPE_FLT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Intensity",              ENT_FLT_INTENSITY               , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Precission",             ENT_FLT_PRECISSION              , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("AngVel",                 ENT_FLT_ANG_VEL                 , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SizeFactor",             ENT_FLT_SIZE_FACTOR             , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("GlowTexture",            ENT_STR_GLOW_TEXTURE            , PROP_TYPE_STR, PROP_ONLY_SET   , NULL                              , NULL);
        insert_property("GlowTestZ",              ENT_INT_GLOW_TEST_Z             , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("GlowSizeDist",           ENT_INT_GLOW_SIZE_DIST          , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("MinDistance",            ENT_FLT_MIN_DISTANCE            , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("MaxDistance",            ENT_FLT_MAX_DISTANCE            , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Volume",                 ENT_FLT_VOLUME                  , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("BaseVolume",             ENT_FLT_BASE_VOLUME             , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Pitch",                  ENT_FLT_PITCH                   , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SoundScale",             ENT_FLT_SOUND_SCALE             , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("CanUse",                 ENT_INT_CAN_USE                 , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InventorySelection",     ENT_STR_INVENTORY_SELECTION     , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("Physic",                 ENT_INT_PHYSIC                  , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("nLights",                ENT_INT_N_LIGHTS                , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("nFires",                 ENT_INT_N_FIRES                 , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("AnimFullName",           ENT_STR_ANIM_FULL_NAME          , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("AnimName",               ENT_STR_ANIM_NAME               , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("PrevAnimName",           ENT_STR_PREV_ANIM_NAME          , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("TimerFunc",              -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_TimerFunc_get             , bex_ent_TimerFunc_set);
        insert_property("HitFunc",                -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_HitFunc_get               , bex_ent_HitFunc_set);
        insert_property("InflictHitFunc",         -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_InflictHitFunc_get        , bex_ent_InflictHitFunc_set);
        insert_property("DamageFunc",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_DamageFunc_get            , bex_ent_DamageFunc_set);
        insert_property("StickFunc",              -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_StickFunc_get             , bex_ent_StickFunc_set);
        insert_property("FrameFunc",              -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_FrameFunc_get             , bex_ent_FrameFunc_set);
        insert_property("HearFunc",               -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_HearFunc_get              , bex_ent_HearFunc_set);
        insert_property("SeeFunc",                -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_SeeFunc_get               , bex_ent_SeeFunc_set);
        insert_property("UseFunc",                -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_UseFunc_get               , bex_ent_UseFunc_set);
        insert_property("TouchFluidFunc",         -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_TouchFluidFunc_get        , bex_ent_TouchFluidFunc_set);
        insert_property("EnterPrimaryAAFunc",     -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_EnterPrimaryAAFunc_get    , bex_ent_EnterPrimaryAAFunc_set);
        insert_property("EnterSecondaryAAFunc",   -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_EnterSecondaryAAFunc_get  , bex_ent_EnterSecondaryAAFunc_set);
        insert_property("EnterCloseFunc",         -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_EnterCloseFunc_get        , bex_ent_EnterCloseFunc_set);
        insert_property("EnterLargeFunc",         -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_EnterLargeFunc_get        , bex_ent_EnterLargeFunc_set);
        insert_property("AnmEndedFunc",           -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_AnmEndedFunc_get          , bex_ent_AnmEndedFunc_set);
        insert_property("DelayNoSeenFunc",        -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_DelayNoSeenFunc_get       , bex_ent_DelayNoSeenFunc_set);
        insert_property("RouteEndedFunc",         -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_RouteEndedFunc_get        , bex_ent_RouteEndedFunc_set);
        insert_property("ImHurtFunc",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_ImHurtFunc_get            , bex_ent_ImHurtFunc_set);
        insert_property("ImDeadFunc",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_ImDeadFunc_get            , bex_ent_ImDeadFunc_set);
        insert_property("EnemyDeadFunc",          -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_EnemyDeadFunc_get         , bex_ent_EnemyDeadFunc_set);
        insert_property("NoAllowedAreaFunc",      -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_NoAllowedAreaFunc_get     , bex_ent_NoAllowedAreaFunc_set);
        insert_property("EnemyNoAllowedAreaFunc", -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_EnemyNoAllowedAreaFunc_get, bex_ent_EnemyNoAllowedAreaFunc_set);
        insert_property("CharSeeingEnemyFunc",    -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_CharSeeingEnemyFunc_get   , bex_ent_CharSeeingEnemyFunc_set);
        insert_property("AnmTranFunc",            -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_AnmTranFunc_get           , bex_ent_AnmTranFunc_set);
        insert_property("NewComboFunc",           -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_NewComboFunc_get          , bex_ent_NewComboFunc_set);
        insert_property("BigFallFunc",            -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_BigFallFunc_get           , bex_ent_BigFallFunc_set);
        insert_property("AttackFunc",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_AttackFunc_get            , bex_ent_AttackFunc_set);
        insert_property("ToggleCombatFunc",       -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_ToggleCombatFunc_get      , bex_ent_ToggleCombatFunc_set);
        insert_property("TakeFunc",               -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_TakeFunc_get              , bex_ent_TakeFunc_set);
        insert_property("ThrowFunc",              -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_ThrowFunc_get             , bex_ent_ThrowFunc_set);
        insert_property("OnHitFunc",              -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_OnHitFunc_get             , bex_ent_OnHitFunc_set);
        insert_property("OnStopFunc",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_OnStopFunc_get            , bex_ent_OnStopFunc_set);
        insert_property("OnAnimationEndFunc",     -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_OnAnimationEndFunc_get    , bex_ent_OnAnimationEndFunc_set);
        insert_property("OnPathNodeFunc",         -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_OnPathNodeFunc_get        , bex_ent_OnPathNodeFunc_set);
        insert_property("Orientation",            -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_Orientation_get           , bex_ent_Orientation_set);
        insert_property("FiresIntensity",         -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_FiresIntensity_get        , bex_ent_FiresIntensity_set);
        insert_property("SubscribedLists",        -1                              , PROP_TYPE_OBJ, PROP_ONLY_GET   , bex_ent_SubscribedLists_get       , NULL);
        insert_property("LightIntensity",         -1                              , PROP_TYPE_OBJ, PROP_ONLY_GET   , bex_ent_LightIntensity_get        , NULL);
        insert_property("LightPrecission",        -1                              , PROP_TYPE_OBJ, PROP_ONLY_GET   , bex_ent_LightPrecission_get       , NULL);
        insert_property("LightColor",             -1                              , PROP_TYPE_OBJ, PROP_ONLY_GET   , bex_ent_LightColor_get            , NULL);
        insert_property("LightGlow",              -1                              , PROP_TYPE_OBJ, PROP_ONLY_GET   , bex_ent_LightGlow_get             , NULL);
        insert_property("Lights",                 -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_Lights_get                , bex_ent_Lights_set);
        insert_property("MutilateFunc",           -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_MutilateFunc_get          , bex_ent_MutilateFunc_set);
        insert_property("AttackList",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_AttackList_get            , bex_ent_AttackList_set);
        insert_property("Reflection",             ENT_FLT_REFLECTION              , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Transparency",           ENT_FLT_TRANSPARENCY            , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("DeepColor",              ENT_VEC_DEEP_COLOR              , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Color",                  ENT_VEC_COLOR                   , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Solid",                  ENT_INT_SOLID                   , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SlidingSurface",         ENT_VEC_SLIDING_SURFACE         , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("AddBayPoint",            ENT_VEC_ADD_BAY_POINT           , PROP_TYPE_VEC, PROP_ONLY_SET   , NULL                              , NULL);
        insert_property("LastBayNumAnims",        ENT_INT_LAST_BAY_NUM_ANIMS      , PROP_TYPE_INT, PROP_ONLY_SET   , NULL                              , NULL);
        insert_property("LastBayAngAnims",        ENT_FLT_LAST_BAY_ANG_ANIMS      , PROP_TYPE_FLT, PROP_ONLY_SET   , NULL                              , NULL);
        insert_property("InvertedRoute",          ENT_INT_INVERTED_ROUTE          , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Dist2Floor",             ENT_FLT_DIST2_FLOOR             , PROP_TYPE_FLT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("BlockingPropensity",     ENT_FLT_BLOCKING_PROPENSITY     , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("RangeDefenceCapable",    ENT_INT_RANGE_DEFENCE_CAPABLE   , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ActiveEnemy",            ENT_STR_ACTIVE_ENEMY            , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InvRight",               ENT_STR_INV_RIGHT               , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InvLeft",                ENT_STR_INV_LEFT                , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InvLeft2",               ENT_STR_INV_LEFT2               , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InvRightBack",           ENT_STR_INV_RIGHT_BACK          , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InvLeftBack",            ENT_STR_INV_LEFT_BACK           , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("InCombat",               ENT_INT_IN_COMBAT               , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("DefenceNeeded",          ENT_INT_DEFENCE_NEEDED          , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("MeshName",               ENT_STR_MESH_NAME               , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("PersonNodeName",         ENT_STR_PERSON_NODE_NAME        , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("PersonName",             ENT_STR_PERSON_NAME             , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ObjectName",             ENT_STR_OBJECT_NAME             , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("YGravity",               ENT_FLT_Y_GRAVITY               , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Friction",               ENT_FLT_FRICTION                , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Friction2",              ENT_FLT_FRICTION2               , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("PPS",                    ENT_FLT_P_P_S                   , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("DeathTime",              ENT_FLT_DEATH_TIME              , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("FollowFactor",           ENT_FLT_FOLLOW_FACTOR           , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("NormalVelocity",         ENT_FLT_NORMAL_VELOCITY         , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("RandomVelocity",         ENT_FLT_RANDOM_VELOCITY         , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("RandomVelocity_V",       ENT_FLT_RANDOM_VELOCITY_V       , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Time2Live",              ENT_FLT_TIME2_LIVE              , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Time2Live_V",            ENT_FLT_TIME2_LIVE_V            , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ObjCTest",               ENT_INT_OBJ_C_TEST              , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Static",                 0                               , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_Static_get                , bex_ent_Static_set);
        insert_property("Object",                 ENT_INT_OBJECT                  , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Person",                 4                               , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_Person_get                , bex_ent_Person_set);
        insert_property("Weapon",                 10                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_Weapon_get                , bex_ent_Weapon_set);
        insert_property("Actor",                  11                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_Actor_get                 , bex_ent_Actor_set);
        insert_property("Arrow",                  12                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_Arrow_get                 , bex_ent_Arrow_set);
        insert_property("RAttackMin",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_RAttackMin_get            , bex_ent_RAttackMin_set);
        insert_property("RAttackMax",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_RAttackMax_get            , bex_ent_RAttackMax_set);
        insert_property("ActionAreaMin",          -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_ActionAreaMin_get         , bex_ent_ActionAreaMin_set);
        insert_property("ActionAreaMax",          -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_ActionAreaMax_get         , bex_ent_ActionAreaMax_set);
        insert_property("FireParticleType",       ENT_STR_FIRE_PARTICLE_TYPE      , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ParticleType",           ENT_STR_PARTICLE_TYPE           , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ExclusionGroup",         ENT_INT_EXCLUSION_GROUP         , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("TPos",                   ENT_VEC_T_POS                   , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("TAng",                   ENT_VEC_T_ANG                   , PROP_TYPE_VEC, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("TType",                  ENT_INT_T_TYPE                  , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SType",                  ENT_INT_S_TYPE                  , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("PViewType",              ENT_INT_P_VIEW_TYPE             , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ETarget",                ENT_STR_E_TARGET                , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ESource",                ENT_STR_E_SOURCE                , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Dist",                   ENT_FLT_DIST                    , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Returns",                ENT_INT_RETURNS                 , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("EarthQuake",             ENT_INT_EARTH_QUAKE             , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("EarthQuakeFactor",       ENT_FLT_EARTH_QUAKE_FACTOR      , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ChangeNodeFunc",         -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_ChangeNodeFunc_get        , bex_ent_ChangeNodeFunc_set);
        insert_property("CombatGroup",            ENT_STR_COMBAT_GROUP            , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Heard",                  ENT_INT_HEARD                   , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Seen",                   ENT_INT_SEEN                    , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("LastTimeSeen",           ENT_FLT_LAST_TIME_SEEN          , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Radius",                 ENT_FLT_RADIUS                  , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Cone",                   ENT_FLT_CONE                    , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Height",                 ENT_FLT_HEIGHT                  , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("HitShieldFunc",          -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_HitShieldFunc_get         , bex_ent_HitShieldFunc_set);
        insert_property("Alpha",                  ENT_FLT_ALPHA                   , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SelfIlum",               ENT_FLT_SELF_ILUM               , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Texture",                ENT_INT_TEXTURE                 , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("TextureName",            ENT_STR_TEXTURE_NAME            , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("BlendMode",              ENT_STR_BLEND_MODE              , PROP_TYPE_STR, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Frame",                  ENT_FLT_FRAME                   , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("RasterMode",             ENT_STR_RASTER_MODE             , PROP_TYPE_STR, PROP_ONLY_SET   , NULL                              , NULL);
        insert_property("RasterModeZ",            ENT_STR_RASTER_MODE_Z           , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("RasterModeAlpha",        ENT_STR_RASTER_MODE_ALPHA       , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("MutilationsMask",        ENT_INT_MUTILATIONS_MASK        , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("ExclusionMask",          ENT_INT_EXCLUSION_MASK          , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Zoom",                   ENT_FLT_ZOOM                    , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("SelfLight",              ENT_FLT_SELF_LIGHT              , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ContinuousDamage",       ENT_INT_CONTINUOUS_DAMAGE       , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("TrailMode",              ENT_INT_TRAIL_MODE              , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("WeaponMode",             ENT_INT_WEAPON_MODE             , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("StaticWeaponMode",       ENT_INT_STATIC_WEAPON_MODE      , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("LastSound",              ENT_STR_LAST_SOUND              , PROP_TYPE_STR, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("LastSoundPosition",      ENT_VEC_LAST_SOUND_POSITION     , PROP_TYPE_VEC, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("ZoomS",                  ENT_FLT_ZOOM_S                  , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("ZoomT",                  ENT_FLT_ZOOM_T                  , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("OriginS",                ENT_FLT_ORIGIN_S                , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("OriginT",                ENT_FLT_ORIGIN_T                , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
/* FIXME two "Angle" properties */
        insert_property("Angle",                  ENT_FLT_ANGLE_2                 , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("FixedTarget",            ENT_INT_FIXED_TARGET            , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("InternalState",          -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_InternalState_get         , bex_ent_InternalState_set);
        insert_property("Accuracy",               ENT_FLT_ACCURACY                , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("AimOffTarget",           ENT_FLT_AIM_OFF_TARGET          , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("AimVector",              ENT_VEC_AIM_VECTOR              , PROP_TYPE_VEC, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("LastAttackTime",         ENT_FLT_LAST_ATTACK_TIME        , PROP_TYPE_FLT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("InWorld",                ENT_INT_IN_WORLD                , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("RangeActive",            ENT_INT_RANGE_ACTIVE            , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("MeleeActive",            ENT_INT_MELEE_ACTIVE            , PROP_TYPE_INT, PROP_ONLY_GET   , NULL                              , NULL);
        insert_property("OnStepFunc",             -1                              , PROP_TYPE_OBJ, PROP_GET_AND_SET, bex_ent_OnStepFunc_get            , bex_ent_OnStepFunc_set);
        insert_property("Reflects",               ENT_INT_REFLECTS                , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
        insert_property("Frozen",                 ENT_INT_FROZEN                  , PROP_TYPE_INT, PROP_GET_AND_SET, NULL                              , NULL);
}


// address: 0x10010208
PyObject *bex_ent_doc_get(PyObject *self, char *attr_name) {
        return PyString_FromString("Entidad de Blade.");
}


// address: 0x1001021b
PyObject *bex_ent_Data_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;

        return GetEntityData(entity->name);
}


// address: 0x10010230
PyObject *bex_ent_TimerFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_TIMER_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010278
PyObject *bex_ent_HitFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_HIT_FUNC, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x100102c0
PyObject *bex_ent_InflictHitFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_INFLICT_HIT, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010308
PyObject *bex_ent_HitShieldFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_HIT_SHIELD_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010350
PyObject *bex_ent_DamageFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_DAMAGE_FUNC, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010398
PyObject *bex_ent_StickFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_STICK_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x100103e0
PyObject *bex_ent_FrameFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_FRAME, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010428
PyObject *bex_ent_HearFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_HEAR_FUNC, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010470
PyObject *bex_ent_SeeFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_SEE_FUNC, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x100104b8
PyObject *bex_ent_UseFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_USE_FUNC, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}

// TODO implement
// address: 0x10010500
PyObject *bex_ent_ChangeNodeFunc_get(PyObject *self, char *attr_name) {
        NOT_IMPLEMENTED_FUNC("bex_ent_ChangeNodeFunc_get", NULL);
}


// address: 0x10010548
PyObject *bex_ent_TouchFluidFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_TOUCH_FLUID, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010590
PyObject *bex_ent_EnterPrimaryAAFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ENTER_PRIMARY_AA, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x100105d8
PyObject *bex_ent_EnterSecondaryAAFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ENTER_SECONDARY_AA, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010620
PyObject *bex_ent_EnterCloseFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ENTER_CLOSE, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010668
PyObject *bex_ent_EnterLargeFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ENTER_LARGE, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x100106b0
PyObject *bex_ent_AnmEndedFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_ANM_ENDED, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x100106f8
PyObject *bex_ent_DelayNoSeenFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_DELAY_NO_SEEN_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010740
PyObject *bex_ent_RouteEndedFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ROUTE_ENDED, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010788
PyObject *bex_ent_ImHurtFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_IM_HURT_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x100107d0
PyObject *bex_ent_ImDeadFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_IM_DEAD_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010818
PyObject *bex_ent_EnemyDeadFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ENEMY_DEAD_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010860
PyObject *bex_ent_NoAllowedAreaFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_NO_ALLOWED_AREA_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x100108a8
PyObject *bex_ent_EnemyNoAllowedAreaFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ENEMY_NO_ALLOWED_AREA, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x100108f0
PyObject *bex_ent_CharSeeingEnemyFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_CHAR_SEEING_ENEMY, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010938
PyObject *bex_ent_AnmTranFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_ANM_TRAN, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010980
PyObject *bex_ent_NewComboFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_NEW_COMBO_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x100109c8
PyObject *bex_ent_BigFallFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_BIG_FALL_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010a10
PyObject *bex_ent_AttackFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_ATTACK_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010a58
PyObject *bex_ent_ToggleCombatFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_TOGGLE_COMBAT, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010aa0
PyObject *bex_ent_TakeFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_TAKE_FUNC, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010ae8
PyObject *bex_ent_ThrowFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_THROW_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010b30
PyObject *bex_ent_MutilateFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(
                entity->name, ENT_FNC_MUTILATE_FUNC, 0, &func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// address: 0x10010b78
PyObject *bex_ent_AttackList_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *atack_list;

        atack_list = GetAttackList(entity->name);
        if (atack_list == NULL) {
                if (Py_None)
                        Py_INCREF(Py_None);
                return Py_None;
        }

        if (atack_list)
                Py_INCREF(atack_list);

        return atack_list;
}

// TODO implement
// address: 0x10010bd6
PyObject *bex_ent_OnHitFunc_get(PyObject *self, char *attr_name) {
        NOT_IMPLEMENTED_FUNC("bex_ent_OnHitFunc_get", NULL);
}


// address: 0x10010c1e
PyObject *bex_ent_OnStopFunc_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        PyObject *func;

        code = GetEntityFuncProperty(entity->name, ENT_FNC_ON_STOP, 0, &func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return func;
}


// TODO implement
// address: 0x10010c66
PyObject *bex_ent_OnStepFunc_get(PyObject *self, char *attr_name) {
        NOT_IMPLEMENTED_FUNC("bex_ent_OnStepFunc_get", NULL);
}

// TODO implement
// address: 0x10010cae
PyObject *bex_ent_OnAnimationEndFunc_get(PyObject *self, char *attr_name) {
        NOT_IMPLEMENTED_FUNC("bex_ent_OnAnimationEndFunc_get", NULL);
}

// TODO implement
// address: 0x10010cf6
PyObject *bex_ent_OnPathNodeFunc_get(PyObject *self, char *attr_name) {
        NOT_IMPLEMENTED_FUNC("bex_ent_OnPathNodeFunc_get", NULL);
}

// TODO implement
// address: 0x10010d3e
PyObject *bex_ent_RAttackMin_get(PyObject *self, char *attr_name) {
        NOT_IMPLEMENTED_FUNC("bex_ent_RAttackMin_get", NULL);
}

// TODO implement
// address: 0x10010d90
PyObject *bex_ent_RAttackMax_get(PyObject *self, char *attr_name) {
        NOT_IMPLEMENTED_FUNC("bex_ent_RAttackMax_get", NULL);
}


// address: 0x10010de2
PyObject *bex_ent_ActionAreaMin_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int action_area_min;

        code = GetEntityIntProperty(
                entity->name, ENT_INT_ACTION_AREA, 0, &action_area_min
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return PyInt_FromLong(action_area_min);
}


// address: 0x10010e34
PyObject *bex_ent_ActionAreaMax_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int action_area_max;

        code = GetEntityIntProperty(
                entity->name, ENT_INT_ACTION_AREA, 1, &action_area_max
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return PyInt_FromLong(action_area_max);
}


// address: 0x10010e86
PyObject *bex_ent_Arrow_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int is_arrow;

        code = GetEntityIntProperty(entity->name, ENT_INT_ARROW, 0, &is_arrow);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return PyInt_FromLong(is_arrow);
}

// address: 0x10010ed8
PyObject *bex_ent_Static_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int is_static;

        code = GetEntityIntProperty(entity->name, ENT_INT_STATIC, 0, &is_static);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return PyInt_FromLong(is_static);
}


// address: 0x10010f2a
PyObject *bex_ent_Actor_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int is_actor;

        code = GetEntityIntProperty(entity->name, ENT_INT_ACTOR, 0, &is_actor);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return PyInt_FromLong(is_actor);
}


// address: 0x10010f7c
PyObject *bex_ent_Person_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int is_person;

        code = GetEntityIntProperty(
                entity->name, ENT_INT_PERSON, 0, &is_person
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return PyInt_FromLong(is_person);
}


// address: 0x10010fce
PyObject *bex_ent_Weapon_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int is_weapon;

        code = GetEntityIntProperty(entity->name, ENT_INT_WEAPON, 0, &is_weapon);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        return PyInt_FromLong(is_weapon);
}


// address: 0x10011020
PyObject *bex_ent_Orientation_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        double quat1, quat2, quat3, quat4;
        PyObject *tuple, *quat1Obj, *quat2Obj, *quat3Obj, *quat4Obj;

        code = GetEntityQuatProperty(entity->name, ENT_QUAT_ORIENTATION, 0, &quat1, &quat2, &quat3, &quat4);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        tuple = PyTuple_New(4);

        quat1Obj = PyFloat_FromDouble(quat1);
        quat2Obj = PyFloat_FromDouble(quat2);
        quat3Obj = PyFloat_FromDouble(quat3);
        quat4Obj = PyFloat_FromDouble(quat4);

        PyTuple_SetItem(tuple, 0, quat1Obj);
        PyTuple_SetItem(tuple, 1, quat2Obj);
        PyTuple_SetItem(tuple, 2, quat3Obj);
        PyTuple_SetItem(tuple, 3, quat4Obj);

        return tuple;
}

// TODO implement
// address: 0x10011122
PyObject *bex_ent_SubscribedLists_get(PyObject *self, char *attr_name) {
        NOT_IMPLEMENTED_FUNC("bex_ent_SubscribedLists_get", NULL);
}

// TODO implement
// address: 0x100111fc
PyObject *bex_ent_FiresIntensity_get(PyObject *self, char *attr_name) {
        NOT_IMPLEMENTED_FUNC("bex_ent_FiresIntensity_get", NULL);
}

// TODO implement
// address: 0x100112db
PyObject *bex_ent_LightIntensity_get(PyObject *self, char *attr_name) {
        NOT_IMPLEMENTED_FUNC("bex_ent_LightIntensity_get", NULL);
}

// TODO implement
// address: 0x100113ba
PyObject *bex_ent_LightPrecission_get(PyObject *self, char *attr_name) {
        NOT_IMPLEMENTED_FUNC("bex_ent_LightPrecission_get", NULL);
}

// TODO implement
// address: 0x10011499
PyObject *bex_ent_LightColor_get(PyObject *self, char *attr_name) {
        NOT_IMPLEMENTED_FUNC("bex_ent_LightColor_get", NULL);
}

// TODO implement
// address: 0x100115fa
PyObject *bex_ent_LightGlow_get(PyObject *self, char *attr_name) {
        NOT_IMPLEMENTED_FUNC("bex_ent_LightGlow_get", NULL);
}


// address: 0x100116d4
int bex_ent_Static_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int code;
        int is_static;

        if (!PyArg_Parse(value, "i", &is_static)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = ChangeEntityStatic(entity->name, is_static);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}

// address: 0x1001174e
int bex_ent_Actor_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int is_actor;
        int code;

        if (!PyArg_Parse(value, "i", &is_actor)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = ChangeEntityActor(entity->name, is_actor);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}


// address: 0x100117c8
int bex_ent_Person_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int is_person;
        int code;

        if (!PyArg_Parse(value, "i", &is_person)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = ChangeEntityPerson(entity->name, is_person);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}


// address: 0x10011842
int bex_ent_Weapon_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int is_weapon;
        int code;

        if (!PyArg_Parse(value, "i", &is_weapon)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = ChangeEntityWeapon(entity->name, is_weapon);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}


// address: 0x100118bc
int bex_ent_Arrow_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int is_arrow;
        int code;

        if (!PyArg_Parse(value, "i", &is_arrow)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = ChangeEntityArrow(entity->name, is_arrow);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}


// address: 0x10011936
int bex_ent_Data_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *data;
        int code;

        if (!PyArg_Parse(value, "O", &data)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityData(entity->name, data);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}

// address: 0x100119b1
int bex_ent_FiresIntensity_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int i, num_fires;
        double item;
        PyObject *itemObj;
        int code;

        if (!PyList_Check(value)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param, not a list.");
                return -1;
        }

        num_fires = PyList_Size(value);

        for (i = 0; i < num_fires; i++) {
                itemObj = PyList_GetItem(value, i);
                item = PyFloat_AsDouble(itemObj);

                code = SetEntityFloatProperty(
                        entity->name, ENT_FLT_FIRES_INTENSITY, i, item
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }
        }

        return 0;
}

// address: 0x10011a7e
int bex_ent_Lights_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int i, num_lights;
        PyObject *tuple, *intensityObj, *precisionObj, *colourObj;
        PyObject *rObj, *gObj, *bObj;
        double intensity, precision, r, g, b;
        int code;

        if (!PyList_Check(value)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param, not a list.");
                return -1;
        }

        num_lights = PyList_Size(value);

        for (i = 0; i < num_lights; i++) {
                tuple = PyList_GetItem(value, i);

                if (!PyTuple_Check(tuple)) {
                        PyErr_SetString(
                                PyExc_AttributeError,
                                "Invalid Param, not a tuple."
                        );
                        return -1;
                }

                intensityObj = PyTuple_GetItem(tuple, 0);
                precisionObj = PyTuple_GetItem(tuple, 1);
                colourObj = PyTuple_GetItem(tuple, 2);

                if (!PyTuple_Check(colourObj)) {
                        PyErr_SetString(
                                PyExc_AttributeError,
                                "Invalid Param, color not a tuple."
                        );
                        return -1;
                }

                rObj = PyTuple_GetItem(colourObj, 0);
                gObj = PyTuple_GetItem(colourObj, 1);
                bObj = PyTuple_GetItem(colourObj, 2);

                intensity = PyFloat_AsDouble(intensityObj);
                precision = PyFloat_AsDouble(precisionObj);
                r = PyFloat_AsDouble(rObj);
                g = PyFloat_AsDouble(gObj);
                b = PyFloat_AsDouble(bObj);

                code = SetEntityFloatProperty(
                        entity->name, ENT_FLT_LIGHTS_INTENSITY, i, intensity
                );
                if (code != 1) {
                        PyErr_SetString(
                                PyExc_AttributeError,
                                "Invalid Param - Intensity."
                        );
                        return -1;
                }

                code = SetEntityFloatProperty(
                        entity->name, ENT_FLT_LIGHTS_PRECISION, i, precision
                );
                if (code != 1) {
                        PyErr_SetString(
                                PyExc_AttributeError,
                                "Invalid Param - Precission."
                        );
                        return -1;
                }

                code = SetEntityVectorProperty(
                        entity->name, ENT_VEC_LIGHTS_COLOUR, i, r, g, b
                );
                if (code != 1) {
                        PyErr_SetString(
                                PyExc_AttributeError,
                                "Invalid Param - Color."
                        );
                        return -1;
                }
        }

        return 0;
}


// address: 0x10011ced
PyObject *bex_ent_Lights_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        int i, num_lights;
        PyObject *list, *tuple, *intensityObj, *precisionObj, *colourObj;
        PyObject *rObj, *gObj, *bObj;
        double intensity, precision, r, g, b;
        int code;

        code = GetEntityIntProperty(
                entity->name, ENT_INT_N_LIGHTS, 0, &num_lights
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        list = PyList_New(num_lights);

        for (i = 0; i < num_lights; i++) {
                code = GetEntityFloatProperty(
                        entity->name, ENT_FLT_LIGHTS_INTENSITY, i, &intensity
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                code = GetEntityFloatProperty(entity->name, ENT_FLT_LIGHTS_PRECISION, i, &precision);
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                code = GetEntityVectorProperty(
                        entity->name, ENT_VEC_LIGHTS_COLOUR, i, &r, &g, &b
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                tuple = PyTuple_New(3);

                intensityObj = PyFloat_FromDouble(intensity);
                precisionObj = PyFloat_FromDouble(precision);

                rObj = PyInt_FromLong(r);
                gObj = PyInt_FromLong(g);
                bObj = PyInt_FromLong(b);

                colourObj = PyTuple_New(3);

                PyTuple_SetItem(colourObj, 0, rObj);
                PyTuple_SetItem(colourObj, 1, gObj);
                PyTuple_SetItem(colourObj, 2, bObj);

                PyTuple_SetItem(tuple, 0, intensityObj);
                PyTuple_SetItem(tuple, 1, precisionObj);
                PyTuple_SetItem(tuple, 2, colourObj);

                PyList_SetItem(list, i, tuple);
        }

        return list;
}


// TODO implement
// address: 0x10011f3b
int bex_ent_RAttackMin_set(PyObject *self, char *attr_name, PyObject *value) {
        NOT_IMPLEMENTED_FUNC("bex_ent_RAttackMin_set", -1);
}

// TODO implement
// address: 0x10011fbe
int bex_ent_RAttackMax_set(PyObject *self, char *attr_name, PyObject *value) {
        NOT_IMPLEMENTED_FUNC("bex_ent_RAttackMax_set", -1);
}


// address: 0x10012041
int bex_ent_ActionAreaMin_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        double action_area_min;
        int code;

        if (!PyArg_Parse(value, "d", &action_area_min)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityIntProperty(
                entity->name, ENT_INT_ACTION_AREA, 0, action_area_min
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}

// address: 0x100120c4
int bex_ent_ActionAreaMax_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        double action_area_max;
        int code;

        if (!PyArg_Parse(value, "d", &action_area_max)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityIntProperty(
                entity->name, ENT_INT_ACTION_AREA, 1, action_area_max
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Error changing mode.");
                return -1;
        }

        return 0;
}

// address: 0x10012147
int bex_ent_Orientation_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        double quat1, quat2, quat3, quat4;
        int code;


        if (!PyArg_Parse(value, "(dddd)", &quat1, &quat2, &quat3, &quat4)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityQuatProperty(
                entity->name, ENT_QUAT_ORIENTATION, 0, quat1, quat2, quat3,
                quat4
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}

// address: 0x100121ee
int bex_ent_TimerFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_TIMER_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x1001226d
int bex_ent_HitFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        if (!PyCallable_Check(func))
                func = NULL;

        code = SetEntityFuncProperty(entity->name, ENT_FNC_HIT_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x10012304
int bex_ent_InflictHitFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        if (!PyCallable_Check(func))
                func = NULL;

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_INFLICT_HIT, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}

// address: 0x1001239b
int bex_ent_HitShieldFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_HIT_SHIELD_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x1001241a
int bex_ent_DamageFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_DAMAGE_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x10012499
int bex_ent_StickFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_STICK_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}

// TODO implement
// address: 0x10012518
int bex_ent_FrameFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        NOT_IMPLEMENTED_FUNC("bex_ent_FrameFunc_set", -1);
}

// address: 0x10012597
int bex_ent_HearFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_HEAR_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}

// address: 0x10012616
int bex_ent_SeeFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        if (!PyCallable_Check(func))
                func = NULL;

        code = SetEntityFuncProperty(entity->name, ENT_FNC_SEE_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x100126ad
int bex_ent_UseFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_USE_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x1001272c
int bex_ent_ChangeNodeFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_CHANGE_NODE, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x100127ab
int bex_ent_TouchFluidFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_TOUCH_FLUID, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x1001282a
int bex_ent_EnterPrimaryAAFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_ENTER_PRIMARY_AA, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x100128a9
int bex_ent_EnterSecondaryAAFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_ENTER_SECONDARY_AA, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x10012928
int bex_ent_EnterCloseFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_ENTER_CLOSE, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x100129a7
int bex_ent_EnterLargeFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_ENTER_LARGE, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x10012a26
int bex_ent_AnmEndedFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        if (!PyCallable_Check(func))
                func = NULL;

        code = SetEntityFuncProperty(entity->name, ENT_FNC_ANM_ENDED, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x10012abd
int bex_ent_DelayNoSeenFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_DELAY_NO_SEEN_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x10012b3c
int bex_ent_RouteEndedFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_ROUTE_ENDED, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x10012bbb
int bex_ent_ImHurtFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if(!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_IM_HURT_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x10012c3a
int bex_ent_ImDeadFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_IM_DEAD_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}

// address: 0x10012cb9
int bex_ent_EnemyDeadFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_ENEMY_DEAD_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x10012d38
int bex_ent_NoAllowedAreaFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_NO_ALLOWED_AREA_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x10012db7
int bex_ent_EnemyNoAllowedAreaFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_ENEMY_NO_ALLOWED_AREA, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x10012e36
int bex_ent_CharSeeingEnemyFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_CHAR_SEEING_ENEMY, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x10012eb5
int bex_ent_AnmTranFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_ANM_TRAN, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x10012f34
int bex_ent_NewComboFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_NEW_COMBO_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x10012fb3
int bex_ent_BigFallFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_BIG_FALL_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x10013032
int bex_ent_AttackFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_ATTACK_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x100130b1
int bex_ent_ToggleCombatFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_TOGGLE_COMBAT, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x10013130
int bex_ent_TakeFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_TAKE_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x100131af
int bex_ent_ThrowFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_THROW_FUNC, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x1001322e
int bex_ent_MutilateFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        if (!PyCallable_Check(func))
                func = NULL;

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_MUTILATE_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x100132c5
int bex_ent_AttackList_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *attack_list;
        int code;

        if (!PyArg_Parse(value, "O", &attack_list)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetAttackList(entity->name, attack_list);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}

// TODO implement
// address: 0x10013340
int bex_ent_OnHitFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        NOT_IMPLEMENTED_FUNC("bex_ent_OnHitFunc_set", -1);
}


// address: 0x100133bf
int bex_ent_OnStopFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_ON_STOP, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x1001343e
int bex_ent_OnStepFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityFuncProperty(entity->name, ENT_FNC_ON_STEP, 0, func);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}



// address: 0x100134bd
int bex_ent_OnAnimationEndFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *func;
        int code;

        if (!PyArg_Parse(value, "O", &func)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        if (!PyCallable_Check(func))
            func = NULL;

        code = SetEntityFuncProperty(
                entity->name, ENT_FNC_ON_ANIMATION_END_FUNC, 0, func
        );
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}

// TODO implement
// address: 0x10013554
int bex_ent_OnPathNodeFunc_set(PyObject *self, char *attr_name, PyObject *value) {
        NOT_IMPLEMENTED_FUNC("bex_ent_OnPathNodeFunc_set", -1);
}


// address: 0x100135d3
int bex_ent_InternalState_set(PyObject *self, char *attr_name, PyObject *value) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *internal_state;
        int code;

        if (!PyArg_Parse(value, "O", &internal_state)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        code = SetEntityInternalState(entity->name, internal_state);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return -1;
        }

        return 0;
}


// address: 0x1001364e
PyObject *bex_ent_InternalState_get(PyObject *self, char *attr_name) {
        bld_py_entity_t *entity = (bld_py_entity_t *)self;
        PyObject *internal_state;
        int code;

        code = GetEntityInternalState(entity->name, &internal_state);
        if (code != 1) {
                PyErr_SetString(PyExc_AttributeError, attr_name);
                return NULL;
        }

        if (internal_state == NULL) {
                if (Py_None)
                        Py_INCREF(Py_None);
                return Py_None;
        }

        return internal_state;
}


// address: 0x100136bc
void init_entity() {
        init_entity_type();
}


// address: 0x100136c6
void init_entity_type() {

        memset(&entityTypeObject, 0, sizeof(PyTypeObject));

        entityTypeObject.ob_refcnt = 1;
        entityTypeObject.ob_type = &PyType_Type;
        entityTypeObject.ob_size = 0;
        entityTypeObject.tp_name = "B_PyEntity";
        entityTypeObject.tp_basicsize = sizeof(bld_py_entity_t);
        entityTypeObject.tp_itemsize = 0;
        entityTypeObject.tp_dealloc = bld_py_entity_dealloc;
        entityTypeObject.tp_print = bld_py_entity_print;
        entityTypeObject.tp_getattr = bld_py_entity_getattr;
        entityTypeObject.tp_setattr = bld_py_entity_setattr;
        entityTypeObject.tp_compare  = NULL;
        entityTypeObject.tp_repr = NULL;
        entityTypeObject.tp_as_number = NULL;
        entityTypeObject.tp_as_sequence = NULL;
        entityTypeObject.tp_as_mapping = NULL;
        entityTypeObject.tp_hash = NULL;
}


// address: 0x10013771
void bld_py_entity_dealloc(PyObject *self) {
        free(((bld_py_entity_t *)self)->name);
        free(self);
}


// address: 0x10013793
int bld_py_entity_print(PyObject *self, FILE *file, int flags) {
        int code;
        const char *name;
        static char buffer[512];

        code = GetEntityStringProperty(
                ((bld_py_entity_t *)self)->name, ENT_STR_NAME, 0, &name
        );
        if (code != 1)
                sprintf(buffer, "Entity: Invalid.");
        else
                sprintf(buffer, "Entity: %s", name);

        fprintf(file, buffer);
        return 0;
}


// address: 0x100137fe
PyObject *bld_py_entity_getattr(PyObject *self, char *attr_name)
{
        int prop_index, data_type, code;
        static PyObject * (*get_prop_func)(PyObject *self, char *attr_name);
        int int_value;
        double double_value;
        const char *str_value;
        double x, y, z;
        PyObject *tuple, *xObj, *yObj, *zObj;

        prop_index = find_property(property_kinds, attr_name);
        if (prop_index == -1) {
                return Py_FindMethod(entity_methods, self, attr_name);
        }

        if (
                property_kinds[prop_index].flags == PROP_ONLY_GET ||
                property_kinds[prop_index].flags == PROP_GET_AND_SET
        ) {
                if (property_kinds[prop_index].data_type == PROP_TYPE_OBJ ) {
                        get_prop_func = property_kinds[prop_index].get_func;
                        return get_prop_func(self, attr_name);
                }

                data_type = property_kinds[prop_index].data_type;
                if ((data_type - 1) > 3) {
                        return NULL;
                }
                switch(data_type) {
                        case PROP_TYPE_INT:
                                code = GetEntityIntProperty(
                                        ((bld_py_entity_t *)self)->name,
                                        property_kinds[prop_index].kind, 0,
                                        &int_value
                                );
                                if (code != 1) {
                                        if (code != -2) {
                                                PyErr_SetString(
                                                    PyExc_AttributeError,
                                                    attr_name
                                                );
                                        } else {
                                                char buffer[512];
                                                sprintf(
                                                    buffer, "Unsupported %s",
                                                    attr_name
                                                );
                                                PyErr_SetString(
                                                    PyExc_AttributeError, buffer
                                                );
                                        }
                                        return NULL;
                                }
                                return PyInt_FromLong(int_value);

                        case PROP_TYPE_FLT:
                                code = GetEntityFloatProperty(
                                        ((bld_py_entity_t *)self)->name,
                                        property_kinds[prop_index].kind, 0,
                                        &double_value
                                );
                                if (code != 1) {
                                        if (code != -2) {
                                                PyErr_SetString(
                                                    PyExc_AttributeError,
                                                    attr_name
                                                );
                                        } else {
                                                char buffer[512];
                                                sprintf(
                                                    buffer, "Unsupported %s",
                                                    attr_name
                                                );
                                                PyErr_SetString(
                                                    PyExc_AttributeError, buffer
                                                );
                                        }
                                        return NULL;
                                }
                                return PyFloat_FromDouble(double_value);

                        case PROP_TYPE_STR:
                                code = GetEntityStringProperty(
                                        ((bld_py_entity_t *)self)->name,
                                        property_kinds[prop_index].kind, 0,
                                        &str_value
                                );
                                if (code != 1) {
                                        if (code != -2) {
                                                PyErr_SetString(PyExc_AttributeError, attr_name);
                                        } else {
                                                char buffer[512];
                                                sprintf(buffer, "Unsupported %s", attr_name);
                                                PyErr_SetString(PyExc_AttributeError, buffer);
                                        }
                                        return NULL;
                                }
                                if (str_value == NULL) {
                                        if (Py_None)
                                                Py_INCREF(Py_None);
                                        return Py_None;
                                } else {
                                        return PyString_FromString(str_value);
                                }

                        case PROP_TYPE_VEC:
                                code = GetEntityVectorProperty(
                                        ((bld_py_entity_t *)self)->name,
                                        property_kinds[prop_index].kind, 0,
                                        &x, &y, &z
                                );
                                if (code != 1) {
                                        if (code != -2) {
                                                PyErr_SetString(PyExc_AttributeError, attr_name);
                                        } else {
                                                char buffer[512];
                                                sprintf(buffer, "Unsupported %s", attr_name);
                                                PyErr_SetString(PyExc_AttributeError, buffer);
                                        }
                                        return NULL;
                                } else {
                                        tuple = PyTuple_New(3);

                                        xObj = PyFloat_FromDouble(x);
                                        yObj = PyFloat_FromDouble(y);
                                        zObj = PyFloat_FromDouble(z);

                                        PyTuple_SetItem(tuple, 0, xObj);
                                        PyTuple_SetItem(tuple, 1, yObj);
                                        PyTuple_SetItem(tuple, 2, zObj);

                                        return tuple;
                                }
                }
        }

        return Py_FindMethod(entity_methods, self, attr_name);
}


// address: 0x10013c54
int bld_py_entity_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        int prop_index, data_type, code;
        static int (*set_prop_func)(PyObject *self, char *attr_name, PyObject *value);
        const char *name;
        int int_value;
        double double_value;
        const char *str_value;
        double x, y, z;
        char buffer[512];

        if (value == NULL) {
                PyErr_SetString(
                        PyExc_AttributeError, "can't delete entity attributes"
                );
                return -1;
        }

        prop_index = find_property(property_kinds, attr_name);
        if (
                prop_index != -1 &&
                (property_kinds[prop_index].flags == PROP_ONLY_SET ||
                 property_kinds[prop_index].flags == PROP_GET_AND_SET
                )
        ) {
                if (property_kinds[prop_index].data_type == PROP_TYPE_OBJ) {
                        set_prop_func = property_kinds[prop_index].set_func;
                        return (*set_prop_func)(self, attr_name, value);
                }

                data_type = property_kinds[prop_index].data_type;

                switch(data_type) {
                        case PROP_TYPE_INT:
                                if (!PyArg_Parse(value, "i", &int_value)) {
                                        PyErr_SetString(
                                                PyExc_AttributeError,
                                                "Invalid Param."
                                        );
                                        return -1;
                                }

                                code = SetEntityIntProperty(
                                        ((bld_py_entity_t *)self)->name,
                                        property_kinds[prop_index].kind, 0,
                                        int_value
                                );
                                if (code != 1) {
                                        PyErr_SetString(
                                                PyExc_AttributeError,
                                                "Invalid Param."
                                        );
                                        return -1;
                                }

                                return 0;

                        case PROP_TYPE_FLT:
                                if (!PyArg_Parse(value, "d", &double_value)) {
                                        PyErr_SetString(
                                                PyExc_AttributeError,
                                                "Invalid Param."
                                        );
                                        return -1;
                                }

                                code = SetEntityFloatProperty(
                                        ((bld_py_entity_t *)self)->name,
                                        property_kinds[prop_index].kind, 0,
                                        double_value
                                );
                                if (code != 1) {
                                        PyErr_SetString(
                                                PyExc_AttributeError,
                                                "Invalid Param."
                                        );
                                        return -1;
                                }

                                return 0;

                        case PROP_TYPE_STR:
                                if (!PyArg_Parse(value, "s", &str_value)) {
                                        PyErr_SetString(
                                                PyExc_AttributeError,
                                                "Invalid Param."
                                        );
                                        return -1;
                                }

                                code = SetEntityStringProperty(
                                        ((bld_py_entity_t *)self)->name,
                                        property_kinds[prop_index].kind, 0,
                                        str_value
                                );
                                if (code != 1) {
                                        PyErr_SetString(
                                                PyExc_AttributeError,
                                                "Invalid Param."
                                        );
                                        return -1;
                                }

                                return 0;

                        case PROP_TYPE_VEC:
                                if (!PyArg_Parse(value, "(ddd)", &x, &y, &z)) {
                                        PyErr_SetString(
                                                PyExc_AttributeError,
                                                "Invalid Param."
                                        );
                                        return -1;
                                }

                                code = SetEntityVectorProperty(
                                        ((bld_py_entity_t *)self)->name,
                                        property_kinds[prop_index].kind, 0,
                                        x, y, z
                                );
                                if (code != 1) {
                                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                                        return -1;
                                }

                                return 0;
                }

        }

        code = GetEntityStringProperty(
                ((bld_py_entity_t *)self)->name, ENT_STR_NAME, 0,
                &name
        );
        if (code != 1) {
                sprintf(buffer, "Not implemented: %s", attr_name);
        } else {
                sprintf(buffer, "Not implemented: Attribute %s    Entity: %s", attr_name, name);
        }

        PyErr_SetString(PyExc_AttributeError, buffer);

        return -1;
}


// address: 0x100140a0
PyObject *get_inventory(const char *name) {
        bld_py_inventory_t *inventory_obj;

        inventory_obj = PyObject_NEW(bld_py_inventory_t, &inventoryTypeObject);
        if (inventory_obj == NULL)
                return NULL;

        inventory_obj->name = strdup(name);

        return (PyObject *)inventory_obj;
}


// address: 0x100140e9
PyObject *bex_inv_CarringObject(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        const char *obj_name;

        if (!PyArg_ParseTuple(args, "s", &obj_name))
                return NULL;

        code = CarringObject(inventory->name, obj_name);

        return Py_BuildValue("i", code);
}


// address: 0x10014149
PyObject *bex_inv_GetRightBack(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *obj_name;

        obj_name = GetRightBack(inventory->name);
        if (obj_name == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", obj_name);
}


// address: 0x1001419d
PyObject *bex_inv_GetLeftBack(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *obj_name;

        obj_name = GetLeftBack(inventory->name);
        if (obj_name == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", obj_name);
}


// address: 0x100141f1
PyObject *bex_inv_LinkRightHand(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        const char *obj_name;

        code = 0;
        if (PyArg_ParseTuple(args, "s", &obj_name))
                code = LinkRightHand(inventory->name, obj_name);

        return Py_BuildValue("i", code);
}


// address: 0x1001424b
PyObject *bex_inv_LinkLeftHand(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        const char *obj_name;

        code = 0;

        if (PyArg_ParseTuple(args, "s", &obj_name))
                code = LinkLeftHand(inventory->name, obj_name);

        return Py_BuildValue("i", code);
}

// address: 0x100142a5
PyObject *bex_inv_LinkLeftHand2(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        const char *obj_name;

        code = 0;

        if (PyArg_ParseTuple(args, "s", &obj_name))
                code = LinkLeftHand2(inventory->name, obj_name);

        return Py_BuildValue("i", code);
}


// address: 0x100142ff
PyObject *bex_inv_LinkRightBack(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        const char *obj_name;

        code = 0;

        if (PyArg_ParseTuple(args, "s", &obj_name))
                code = LinkRightBack(inventory->name, obj_name);

        return Py_BuildValue("i", code);
}


// address: 0x10014359
PyObject *bex_inv_LinkLeftBack(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        const char *obj_name;

        code = 0;

        if (PyArg_ParseTuple(args, "s", &obj_name))
                code = LinkLeftBack(inventory->name, obj_name);

        return Py_BuildValue("i", code);
}


// address: 0x100143b3
PyObject *bex_inv_LinkBack(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        const char *obj_name;

        code = 0;

        if (PyArg_ParseTuple(args, "s", &obj_name))
                code = LinkBack(inventory->name, obj_name);

        return Py_BuildValue("i", code);
}


// address: 0x1001440d
PyObject *bex_inv_SetCurrentQuiver(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        const char *quiver_name;

        code = 0;

        if (PyArg_ParseTuple(args, "s", &quiver_name))
                code = SetCurrentQuiver(inventory->name, quiver_name);

        return Py_BuildValue("i", code);
}


// address: 0x10014467
PyObject *bex_inv_AddObject(PyObject *self, PyObject *args) {
        return add_object(self, args, INV_OBJ_TYPE_OBJECT);
}


// address: 0x1001447e
PyObject *add_object(PyObject *self, PyObject *args, int obj_type) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int unknown = 0;
        const char *obj_name;
        int code;

        code = 0;

        if (PyArg_ParseTuple(args, "s|i", &obj_name, &unknown))
                code = AddObject(inventory->name, obj_type, unknown, obj_name);

        return Py_BuildValue("i", code);
}


// address: 0x100144eb
PyObject *bex_inv_RemoveObject(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_OBJECT);
}


// address: 0x10014502
PyObject *remove_object(PyObject *self, PyObject *args, int obj_type) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *obj_name;
        int code;

        if (!PyArg_ParseTuple(args, "s", &obj_name))
                return NULL;

        code = RemoveObject(inventory->name, obj_type, obj_name);

        return Py_BuildValue("i", code);
}


// address: 0x10014566
PyObject* bex_inv_GetObject(PyObject* self, PyObject* args) {
        return get_object(self, args, INV_OBJ_TYPE_OBJECT);
}


// address: 0x1001457d
PyObject *get_object(PyObject *self, PyObject *args, int obj_type) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int obj_index;
        const char *obj_name, *obj;

        if (!PyArg_ParseTuple(args, "i", &obj_index)) {
                PyErr_Clear();
                if (!PyArg_ParseTuple(args, "s", &obj_name))
                        return NULL;

                obj = GetObjectByName(inventory->name, obj_type, obj_name);
                if (obj == NULL) {
                        Py_INCREF(Py_None);
                        return Py_None;
                }

                return Py_BuildValue("s", obj);
        } else {
                obj = GetObject(inventory->name, obj_type, obj_index);
                if (obj == NULL) {
                        Py_INCREF(Py_None);
                        return Py_None;
                }

                return Py_BuildValue("s", obj);
        }
}


// address: 0x10014669
PyObject *bex_inv_GetSelectedObject(PyObject *self, PyObject *args) {
        return get_selected_object(self, args, INV_OBJ_TYPE_OBJECT);
}


// address: 0x10014680
PyObject *get_selected_object(PyObject *self, PyObject *args, int obj_type) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *obj;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        obj = GetSelectedObject(inventory->name, obj_type);
        if (obj == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", obj);
}


// address: 0x100146f2
PyObject *bex_inv_CycleObjects(PyObject *self, PyObject *args) {
        return cycle_objects(self, args, INV_OBJ_TYPE_OBJECT);
}


// address: 0x10014709
PyObject *cycle_objects(PyObject *self, PyObject *args, int obj_type) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        Cycle(inventory->name, obj_type);

        Py_INCREF(Py_None);
        return Py_None;
}


// address: 0x1001475f
PyObject *bex_inv_IsObjectSelected(PyObject *self, PyObject *args) {
        return is_object_selected(self, args, INV_OBJ_TYPE_OBJECT);
}


// address: 0x10014776
PyObject *is_object_selected(PyObject *self, PyObject *args, int obj_type) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int obj_index;

        if (!PyArg_ParseTuple(args, "i", &obj_index))
                return NULL;

        return Py_BuildValue(
                "i", IsSelected(inventory->name, obj_type, obj_index)
        );
}


// address: 0x100147d3
PyObject *bex_inv_GetNumberObjectsAt(PyObject *self, PyObject *args) {
        return get_number_objects_at(self, args, INV_OBJ_TYPE_OBJECT);
}


// address: 0x100147ea
PyObject *get_number_objects_at(PyObject *self, PyObject *args, int obj_type) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int index;

        if (!PyArg_ParseTuple(args, "i", &index))
                return NULL;


        return Py_BuildValue(
                "i", GetNumberObjectsAt(inventory->name, obj_type, index)
        );
}


// address: 0x10014847
PyObject *bex_inv_GetMaxNumberObjectsAt(PyObject *self, PyObject *args) {
        return get_max_number_objects_at(self, args, INV_OBJ_TYPE_OBJECT);
}


// address: 0x1001485e
PyObject *get_max_number_objects_at(
        PyObject *self, PyObject *args, int obj_type
) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int index;

        if (!PyArg_ParseTuple(args, "i", &index))
                return NULL;

        return Py_BuildValue(
                "i", GetMaxNumberObjectsAt(inventory->name, obj_type, index)
        );
}


// address: 0x100148bb
PyObject *bex_inv_AddShield(PyObject *self, PyObject *args) {
        return add_object(self, args, INV_OBJ_TYPE_SHIELD);
}


// address: 0x100148d2
PyObject *bex_inv_RemoveShield(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_SHIELD);
}


// address: 0x100148e9
PyObject* bex_inv_GetShield(PyObject* self, PyObject* args) {
        return get_object(self, args, INV_OBJ_TYPE_SHIELD);
}


// address: 0x10014900
PyObject *bex_inv_GetSelectedShield(PyObject *self, PyObject *args) {
        return get_selected_object(self, args, INV_OBJ_TYPE_SHIELD);
}


// address: 0x10014917
PyObject *bex_inv_GetActiveShield(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *shield_name;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        shield_name = GetActiveShield(inventory->name);
        if (shield_name == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", shield_name);
}


// address: 0x10014986
PyObject *bex_inv_GetActiveWeapon(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *weapon_name;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        weapon_name = GetActiveWeapon(inventory->name);
        if (weapon_name == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", weapon_name);
}


// address: 0x100149f5
PyObject *bex_inv_GetActiveQuiver(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *quiver_name;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        quiver_name = GetActiveQuiver(inventory->name);
        if (quiver_name == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", quiver_name);
}


// address: 0x10014a64
PyObject *bex_inv_CycleShields(PyObject *self, PyObject *args) {
        return cycle_objects(self, args, INV_OBJ_TYPE_SHIELD);
}


// address: 0x10014a7b
PyObject *bex_inv_IsShieldSelected(PyObject *self, PyObject *args) {
        return is_object_selected(self, args, INV_OBJ_TYPE_SHIELD);
}


// address: 0x10014a92
PyObject *bex_inv_AddWeapon(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        int code;
        int flag = 0;
        const char *weapon_name;

        code = 0;

        if (PyArg_ParseTuple(args, "s|i", &weapon_name, &flag))
                code = AddWeapon(inventory->name, flag, weapon_name);

        return Py_BuildValue("i", code);
}


// address: 0x10014afb
PyObject *bex_inv_RemoveWeapon(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_WEAPON);
}


// address: 0x10014b12
PyObject *bex_inv_GetWeapon(PyObject *self, PyObject *args) {
        return get_object(self, args, INV_OBJ_TYPE_WEAPON);
}


// address: 0x10014b29
PyObject *bex_inv_GetBow(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *obj_name;

        obj_name = GetObject(inventory->name, INV_OBJ_TYPE_BOW, 0);
        if (obj_name == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", obj_name);
}


// address: 0x10014b81
PyObject *bex_inv_GetMagicShield(PyObject *self, PyObject *args) {
        bld_py_inventory_t *inventory = (bld_py_inventory_t *)self;
        const char *obj_name;

        obj_name = GetObject(inventory->name, INV_OBJ_TYPE_MAGIC_SHIELD, 0);

        if (obj_name == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        return Py_BuildValue("s", obj_name);
}


// address: 0x10014bd9
PyObject *bex_inv_GetSelectedWeapon(PyObject *self, PyObject *args) {
        return get_selected_object(self, args, INV_OBJ_TYPE_WEAPON);
}


// address: 0x10014bf0
PyObject *bex_inv_CycleWeapons(PyObject *self, PyObject *args) {
        return cycle_objects(self, args, INV_OBJ_TYPE_WEAPON);
}


// address: 0x10014c07
PyObject *bex_inv_IsWeaponSelected(PyObject *self, PyObject *args) {
        return is_object_selected(self, args, INV_OBJ_TYPE_WEAPON);
}


// address: 0x10014c1e
PyObject *bex_inv_AddBow(PyObject *self, PyObject *args) {
        return add_object(self, args, INV_OBJ_TYPE_BOW);
}


// address: 0x10014c35
PyObject *bex_inv_RemoveBow(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_BOW);
}


// address: 0x10014c4c
PyObject *bex_inv_AddMagicShield(PyObject *self, PyObject *args) {
        return add_object(self, args, INV_OBJ_TYPE_MAGIC_SHIELD);
}


// TODO implement
// address: 0x10014c63
PyObject* bex_inv_RemoveMagicShield(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_inv_RemoveMagicShield", NULL);
}


// address: 0x10014c7a
PyObject *bex_inv_AddQuiver(PyObject *self, PyObject *args) {
        return add_object(self, args, INV_OBJ_TYPE_QUIVER);
}


// address: 0x10014c91
PyObject *bex_inv_RemoveQuiver(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_QUIVER);
}


// address: 0x10014ca8
PyObject *bex_inv_GetQuiver(PyObject *self, PyObject *args) {
        return get_object(self, args, INV_OBJ_TYPE_QUIVER);
}


// address: 0x10014cbf
PyObject *bex_inv_GetSelectedQuiver(PyObject *self, PyObject *args) {
        return get_selected_object(self, args, INV_OBJ_TYPE_QUIVER);
}


// address: 0x10014cd6
PyObject *bex_inv_CycleQuivers(PyObject *self, PyObject *args) {
        return cycle_objects(self, args, INV_OBJ_TYPE_QUIVER);
}


// address: 0x10014ced
PyObject *bex_inv_IsQuiverSelected(PyObject *self, PyObject *args) {
        return is_object_selected(self, args, INV_OBJ_TYPE_QUIVER);
}


// address: 0x10014d04
PyObject *bex_inv_AddKey(PyObject *self, PyObject *args) {
        return add_object(self, args, INV_OBJ_TYPE_KEY);
}


// address: 0x10014d1b
PyObject *bex_inv_RemoveKey(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_KEY);
}


// address: 0x10014d32
PyObject *bex_inv_GetKey(PyObject *self, PyObject *args) {
        return get_object(self, args, INV_OBJ_TYPE_KEY);
}


// address: 0x10014d49
PyObject *bex_inv_GetSelectedKey(PyObject *self, PyObject *args) {
        return get_selected_object(self, args, INV_OBJ_TYPE_KEY);
}


// address: 0x10014d60
PyObject *bex_inv_CycleKeys(PyObject *self, PyObject *args) {
        return cycle_objects(self, args, INV_OBJ_TYPE_KEY);
}


// address: 0x10014d77
PyObject *bex_inv_IsKeySelected(PyObject *self, PyObject *args) {
        return is_object_selected(self, args, INV_OBJ_TYPE_KEY);
}


// address: 0x10014d8e
PyObject *bex_inv_AddSpecialKey(PyObject *self, PyObject *args) {
        return add_object(self, args, INV_OBJ_TYPE_SPECIAL_KEY);
}


// address: 0x10014da5
PyObject *bex_inv_RemoveSpecialKey(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_SPECIAL_KEY);
}


// address: 0x10014dbc
PyObject *bex_inv_GetSpecialKey(PyObject *self, PyObject *args) {
        return get_object(self, args, INV_OBJ_TYPE_SPECIAL_KEY);
}


// address: 0x10014dd3
PyObject *bex_inv_AddTablet(PyObject *self, PyObject *args) {
        return add_object(self, args, INV_OBJ_TYPE_TABLET);
}


// address: 0x10014dea
PyObject *bex_inv_RemoveTablet(PyObject *self, PyObject *args) {
        return remove_object(self, args, INV_OBJ_TYPE_TABLET);
}


// address: 0x10014e01
PyObject *bex_inv_GetTablet(PyObject *self, PyObject *args) {
        return get_object(self, args, INV_OBJ_TYPE_TABLET);
}


// address: 0x10014e18
void init_inventory() {
        init_inventory_type();
}


// address: 0x10014e22
void init_inventory_type() {

        memset(&inventoryTypeObject, 0, sizeof(PyTypeObject));

        inventoryTypeObject.ob_refcnt = 1;
        inventoryTypeObject.ob_type = &PyType_Type;
        inventoryTypeObject.ob_size = 0;
        inventoryTypeObject.tp_name = "B_PyInventory";
        inventoryTypeObject.tp_basicsize = sizeof(bld_py_inventory_t);
        inventoryTypeObject.tp_itemsize = 0;
        inventoryTypeObject.tp_dealloc = bld_py_inventory_dealloc;
        inventoryTypeObject.tp_print = bld_py_inventory_print;
        inventoryTypeObject.tp_getattr = bld_py_inventory_getattr;
        inventoryTypeObject.tp_setattr = bld_py_inventory_setattr;
        inventoryTypeObject.tp_compare = NULL;
        inventoryTypeObject.tp_repr = NULL;
        inventoryTypeObject.tp_as_number = NULL;
        inventoryTypeObject.tp_as_sequence = NULL;
        inventoryTypeObject.tp_as_mapping = NULL;
        inventoryTypeObject.tp_hash = NULL;
}


// address: 0x10014ecd
void bld_py_inventory_dealloc(PyObject *self) {
        if (((bld_py_inventory_t *)self)->name)
                free(((bld_py_inventory_t *)self)->name);
        free(self);
        return;
}


// address: 0x10014ef8
int bld_py_inventory_print(PyObject *self, FILE *file, int flags) {
        const char *name;
        int code;
        static char buffer[512];

        code = GetInventoryStringProperty(
                ((bld_py_inventory_t *)self)->name, INV_STR_NAME, &name
        );
        if (code == -1) {
                fprintf(file, "NULL Inventory");
        } else {
                sprintf(buffer, "Inventory:%s\n", name);
                fprintf(file, buffer);
        }

        return 0;
}


// address: 0x10014f60
PyObject *bld_py_inventory_getattr(PyObject *self, char *attr_name)
{
        const char *name, *owner;
        int n_objects, n_weapons, n_shields, n_quivers;
        int max_objects, max_weapons, max_shields, max_quivers;
        int has_bow, holding_bow, has_bow_on_back, n_kind_objects;
        int n_keys, n_special_keys, n_tablets;
        int holding_shield, has_shield_on_back;
        int code;

        if (!strcmp(attr_name, "__doc__"))
                return PyString_FromString("Blade Inventory.");

        if (!strcmp(attr_name, "Name")) {
                code = GetInventoryStringProperty(
                        ((bld_py_inventory_t *)self)->name, INV_STR_NAME,
                        &name
                );
                if (code != -1)
                        return PyString_FromString(name);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "Owner")) {
                code = GetInventoryStringProperty(
                        ((bld_py_inventory_t *)self)->name, INV_STR_OWNER,
                        &owner
                );
                if (code != -1)
                        return PyString_FromString(owner);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "nObjects")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_N_OBJECTS,
                        &n_objects
                );

                if (code != -1)
                        return PyInt_FromLong(n_objects);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "nWeapons")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_N_WEAPONS,
                        &n_weapons
                );

                if (code != -1)
                        return PyInt_FromLong(n_weapons);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "nShields")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_N_SHIELDS,
                        &n_shields
                );

                if (code != -1)
                        return PyInt_FromLong(n_shields);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        /* FIXME double nQuivers */
        if (!strcmp(attr_name, "nQuivers")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_N_QUIVERS,
                        &n_quivers
                );

                if (code != -1)
                        return PyInt_FromLong(n_quivers);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "maxObjects")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_MAX_OBJECTS,
                        &max_objects
                );

                if (code != -1)
                        return PyInt_FromLong(max_objects);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "maxWeapons")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_MAX_WEAPONS,
                        &max_weapons
                );

                if (code != -1)
                        return PyInt_FromLong(max_weapons);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "maxShields")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_MAX_SHIELDS,
                        &max_shields);

                if (code != -1)
                        return PyInt_FromLong(max_shields);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "maxQuivers")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_MAX_QUIVERS,
                        &max_quivers
                );

                if (code != -1)
                        return PyInt_FromLong(max_quivers);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "HasBow")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_HAS_BOW,
                        &has_bow
                );

                if (code != -1)
                        return PyInt_FromLong(has_bow);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "HoldingBow")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_HOLDING_BOW,
                        &holding_bow
                );

                if (code != -1)
                        return PyInt_FromLong(holding_bow);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "HasBowOnBack")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name,
                        INV_INT_HAS_BOW_ON_BACK, &has_bow_on_back
                );

                if (code != -1)
                        return PyInt_FromLong(has_bow_on_back);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "nKindObjects")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_N_KIND_OBJECTS,
                        &n_kind_objects
                );

                if (code != -1)
                        return PyInt_FromLong(n_kind_objects);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        /* FIXME double nQuivers */
        if (!strcmp(attr_name, "nQuivers")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_N_QUIVERS,
                        &n_quivers
                );

                if (code != -1)
                        return PyInt_FromLong(n_quivers);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "nKeys")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_N_KEYS,
                        &n_keys
                );

                if (code != -1)
                        return PyInt_FromLong(n_keys);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "nSpecialKeys")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name,
                        INV_INT_N_SPECIAL_KEYS, &n_special_keys
                );

                if (code != -1)
                        return PyInt_FromLong(n_special_keys);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "nTablets")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_N_TABLETS,
                        &n_tablets
                );

                if (code != -1)
                        return PyInt_FromLong(n_tablets);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "HoldingShield")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name,
                        INV_INT_HOLDING_SHIELD, &holding_shield
                );

                if (code != -1)
                        return PyInt_FromLong(holding_shield);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "HasShieldOnBack")) {
                code = GetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name,
                        INV_INT_HAS_SHIELD_ON_BACK, &has_shield_on_back
                );

                if (code != -1)
                        return PyInt_FromLong(has_shield_on_back);
                
                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        return Py_FindMethod(inventory_methods, self, attr_name);
}


// address: 0x10015768
int bld_py_inventory_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        int max_objects, max_weapons, max_shields, max_quivers;
        int code;

        PyErr_Clear();

        if (value == NULL) {
                PyErr_SetString(
                        PyExc_AttributeError,
                        "can't delete Inventory attributes"
                );
                return -1;
        }

        if (!strcmp(attr_name, "maxObjects")) {
                if (!PyArg_Parse(value, "i", &max_objects)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_MAX_OBJECTS,
                        max_objects
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "maxWeapons")) {
                if (!PyArg_Parse(value, "i", &max_weapons)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_MAX_WEAPONS,
                        max_weapons
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "maxShields")) {
                if (!PyArg_Parse(value, "i", &max_shields)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_MAX_SHIELDS,
                        max_shields
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "maxQuivers")) {
                if (!PyArg_Parse(value, "i", &max_quivers)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetInventoryIntProperty(
                        ((bld_py_inventory_t *)self)->name, INV_INT_MAX_QUIVERS,
                        max_quivers
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        PyErr_SetString(PyExc_AttributeError, "Not implemented");
        return -1;
}


// address: 0x10015a00
PyObject *get_material_by_name(const char *name) {
        material_t *material;
        bld_py_material_t *material_obj;

        material = GetMaterial(name);
        if (!material)
                return NULL;

        material_obj = PyObject_NEW(bld_py_material_t, &materialTypeObject);
        if (!material_obj)
                return NULL;

        material_obj->material = material;

        return (PyObject *)material_obj;
}


// address: 0x10015a5c
PyObject *get_material_by_index(int index) {
        material_t *material;
        bld_py_material_t *material_obj;

        material = GetMaterialI(index);
        if (!material)
                return NULL;

        material_obj = PyObject_NEW(bld_py_material_t, &materialTypeObject);
        if (!material_obj)
                return NULL;

        material_obj->material = material;

        return (PyObject *)material_obj;
}


// address: 0x10015ab8
PyObject *create_material(const char *name) {
        material_t *material;
        bld_py_material_t *material_obj;

        material_obj = PyObject_NEW(bld_py_material_t, &materialTypeObject);
        if (!material_obj)
                return NULL;

        material = CreateMaterial(name);
        if (!material)
                return NULL;

        material_obj->material = material;
        return (PyObject *)material_obj;
}


// address: 0x10015b13
PyObject *bex_mat_AddHitSoundComb(PyObject *self, PyObject *args) {
        bld_py_material_t *material = (bld_py_material_t *)self;
        material_t *material1, *material2;
        int soundID;
        const char *material_name;
        bld_py_sound_t *sound;
        int code;

        if (!PyArg_ParseTuple(args, "sO", &material_name, &sound)) {
                PyErr_SetString(PyExc_RuntimeError, "Invalid Params.");
                return Py_BuildValue("i", 0);
        }

        material1 = material->material;
        material2 = GetMaterial(material_name);
        soundID = sound->soundID;

        code = AddHitSoundComb(material1, material2, soundID);
        if (code != 0)
                return Py_BuildValue("i", 1);
        else
                return Py_BuildValue("i", 0);
}


// address: 0x10015bc0
void init_material() {
        init_material_type();
}


// address: 0x10015bca
void init_material_type() {

        memset(&materialTypeObject, 0, sizeof(PyTypeObject));

        materialTypeObject.ob_refcnt = 1;
        materialTypeObject.ob_type = &PyType_Type;
        materialTypeObject.ob_size = 0;
        materialTypeObject.tp_name = "B_PyMaterial";
        materialTypeObject.tp_basicsize = sizeof(bld_py_material_t);
        materialTypeObject.tp_itemsize = 0;
        materialTypeObject.tp_dealloc = bld_py_material_dealloc;
        materialTypeObject.tp_print = bld_py_material_print;
        materialTypeObject.tp_getattr = bld_py_material_getattr;
        materialTypeObject.tp_setattr = bld_py_material_setattr;
        materialTypeObject.tp_compare = NULL;
        materialTypeObject.tp_repr = NULL;
        materialTypeObject.tp_as_number = NULL;
        materialTypeObject.tp_as_sequence = NULL;
        materialTypeObject.tp_as_mapping = NULL;
        materialTypeObject.tp_hash = NULL;
}


// address: 0x10015c75
void bld_py_material_dealloc(PyObject *self) {
        free(self);
}


// address: 0x10015c87
int bld_py_material_print(PyObject *self, FILE *file, int flags) {
        const char *name;
        int code;
        static char buffer[512] = "";

        code = GetMaterialStringProperty(
                ((bld_py_material_t *)self)->material, MAT_STR_NAME, 0, &name
        );
        if (code != 1) {
                fprintf(file, buffer);/*FIXME buffer could be uninitialised*/
        } else {
                sprintf(buffer, "Material:%s\n", name);
                fprintf(file, buffer);
        }
        return 0;
}


// address: 0x10015cf1
PyObject *bld_py_material_getattr(PyObject *self, char *attr_name)
{
        const char *name;
        int break_sound_id, friction_sound_id, hit_sound_id;
        PyObject *break_sound, *friction_sound, *hit_sound;
        double weight;
        int code;

        if (!strcmp(attr_name, "__doc__"))
                return PyString_FromString("Material de Blade.");

        if (!strcmp(attr_name, "Name")) {
                code = GetMaterialStringProperty(
                        ((bld_py_material_t *)self)->material, MAT_STR_NAME, 0,
                        &name
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, name);/*FIXME should be attr_name*/
                        return NULL;
                }

                return PyString_FromString(name);
        }

        if (!strcmp(attr_name, "BreakSound")) {
                code = GetMaterialSoundProperty(
                        ((bld_py_material_t *)self)->material,
                        MAT_SND_BREAK_SOUND, 0, &break_sound_id
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                break_sound = create_sound_s(break_sound_id);
                if (break_sound == NULL)
                        return PyString_FromString(
                                "Material has no BreakSound."
                        );

                return break_sound;
        }

        if (!strcmp(attr_name, "FrictionSound")) {
                code = GetMaterialSoundProperty(
                        ((bld_py_material_t *)self)->material,
                        MAT_SND_FRICTION_SOUND, 0, &friction_sound_id
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                friction_sound = create_sound_s(friction_sound_id);
                if (friction_sound == NULL)
                        return PyString_FromString(
                                "Material has no FrictionSound."
                        );
                return friction_sound;
        }

        if (!strcmp(attr_name, "HitSound")) {
                code = GetMaterialSoundProperty(
                        ((bld_py_material_t *)self)->material,
                        MAT_SND_HIT_SOUND, 0, &hit_sound_id
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }
                hit_sound = create_sound_s(hit_sound_id);
                if (hit_sound == NULL)
                        return PyString_FromString("Material has no HitSound.");

                return hit_sound;
        }

        if (!strcmp(attr_name, "Weight")) {
                code = GetMaterialFloatProperty(
                        ((bld_py_material_t *)self)->material, MAT_FLT_WEIGHT,
                        0, &weight
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                return PyFloat_FromDouble(weight);
        }

        return Py_FindMethod(material_methods, self, attr_name);
}


// address: 0x10015f7e
int bld_py_material_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        bld_py_sound_t *break_sound, *friction_sound, *hit_sound;
        double weight;
        int code;

        PyErr_Clear();
        if (value == NULL) {
                PyErr_SetString(
                        PyExc_AttributeError,
                        "can't delete Material attributes"
                );
                return -1;
        }

        if (!strcmp(attr_name, "BreakSound")) {
                if (!PyArg_Parse(value, "O", &break_sound)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (break_sound->ob_type != &soundTypeObject) {
                        break_sound = NULL;
                } else if (break_sound->soundID == 0) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Sound.");
                        return -1;
                }

                code = SetMaterialSoundProperty(
                        ((bld_py_material_t *)self)->material,
                        MAT_SND_BREAK_SOUND, 0, break_sound->soundID
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "FrictionSound")) {
                if (!PyArg_Parse(value, "O", &friction_sound)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (friction_sound->ob_type != &soundTypeObject) {
                        friction_sound = NULL;
                } else if (friction_sound->soundID == 0) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Sound.");
                        return -1;
                }

                code = SetMaterialSoundProperty(
                        ((bld_py_material_t *)self)->material,
                        MAT_SND_FRICTION_SOUND, 0, friction_sound->soundID
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "HitSound" )) {
                if (!PyArg_Parse(value, "O", &hit_sound)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (hit_sound->ob_type != &soundTypeObject) {
                        hit_sound = NULL;
                } else if (hit_sound->soundID == 0) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Sound.");
                        return -1;
                }

                if (hit_sound == NULL) {
                        PyErr_SetString(
                                PyExc_AttributeError, "Error? obtaining sound."
                        );
                        return 0;/* FIXME should be -1*/
                }

                code = SetMaterialSoundProperty(
                        ((bld_py_material_t *)self)->material,
                        MAT_SND_HIT_SOUND, 0, hit_sound->soundID
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "Weight")) {
                if (!PyArg_Parse(value, "d", &weight)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetMaterialFloatProperty(
                        ((bld_py_material_t *)self)->material, MAT_FLT_WEIGHT,
                        0, weight
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        PyErr_SetString(PyExc_AttributeError, "Not implemented");
        return -1;
}


// address: 0x10016310
PyObject *create_route() {
        bld_py_route_t *route_obj;

        route_obj = PyObject_NEW(bld_py_route_t, &routeTypeObject);
        if (route_obj == NULL)
                return NULL;

        return (PyObject *)route_obj;
}


// address: 0x10016346
PyObject *bex_route_AddPoint(PyObject *self, PyObject *args) {
        double x, y, z;

        if (self == NULL)
                return NULL;

        if (!PyArg_ParseTuple(args, "ddd", &x, &y, &z))
                return NULL;

        return Py_BuildValue("i", 1);
}


// address: 0x10016396
void init_route() {
        init_route_type();
}


// address: 0x100163a0
void init_route_type() {
        memset(&routeTypeObject, 0, sizeof(PyTypeObject));

        routeTypeObject.ob_refcnt = 1;
        routeTypeObject.ob_type = &PyType_Type;
        routeTypeObject.ob_size = 0;
        routeTypeObject.tp_name = "B_PyRoute";
        routeTypeObject.tp_basicsize = sizeof(bld_py_route_t);
        routeTypeObject.tp_itemsize = 0;
        routeTypeObject.tp_dealloc = bld_py_route_dealloc;
        routeTypeObject.tp_print = bld_py_route_print;
        routeTypeObject.tp_getattr = bld_py_route_getattr;
        routeTypeObject.tp_setattr = bld_py_route_setattr;
        routeTypeObject.tp_compare = NULL;
        routeTypeObject.tp_repr = NULL;
        routeTypeObject.tp_as_number = NULL;
        routeTypeObject.tp_as_sequence = NULL;
        routeTypeObject.tp_as_mapping = NULL;
        routeTypeObject.tp_hash = NULL;
}


// address: 0x1001644b
void bld_py_route_dealloc(PyObject *self) {
        free(self);
}


// address: 0x1001645d
int bld_py_route_print(PyObject *self, FILE *file, int flags) {
        char buffer[128];

        sprintf(buffer, "B_Route: %d", 0);
        fprintf(file, buffer);

        return 0;
}


// address: 0x10016491
PyObject *bld_py_route_getattr(PyObject *self, char *attr_name) {

        if (!strcmp(attr_name, "__doc__"))
                return PyString_FromString("Objeto ruta de Blade.");

        return Py_FindMethod(route_methods, self, attr_name);
}


// address: 0x100164d3
int bld_py_route_setattr(PyObject *self, char *attr_name, PyObject *value) {

        PyErr_Clear();
        if (value == NULL) {
                PyErr_SetString(
                        PyExc_AttributeError, "can't delete route attributes"
                );
                return -1;
        }

        PyErr_SetString(PyExc_AttributeError, "Not implemented");
        return -1;
}


// address: 0x10016520
PyObject *get_sector_by_index(int index) {
        int sectorID;
        bld_py_sector_t *sector_obj;

        sectorID = GetSectorByIndex(index);
        if (sectorID >= 0) {
                sector_obj = PyObject_NEW(bld_py_sector_t, &sectorTypeObject);
                if (sector_obj != NULL) {
                        sector_obj->sectorID = sectorID;
                        return (PyObject *)sector_obj;
                } else {
                        return NULL;
                }
        }

        return NULL;
}

// address: 0x1001657c
PyObject *get_sector_by_position(double x, double y, double z) {
        int index;

        index = GetSectorByPosition(x, y, z);

        return get_sector_by_index(index);
}


// address: 0x100165b4
PyObject *bex_sec_InitBreak(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        double x_vec1, y_vec1, z_vec1, x_vec2, y_vec2, z_vec2, x_vec3, y_vec3, z_vec3;
        const char *s_unknown = "";//TODO check string 0x1002c114
        double d_unknown = 100.0;
        int i_unknown = 1;

        if (!PyArg_ParseTuple(
                args, "(ddd)(ddd)(ddd)|sdi", &x_vec1, &y_vec1, &z_vec1, &x_vec2,
                &y_vec2, &z_vec2, &x_vec3, &y_vec3, &z_vec3, &s_unknown,
                &d_unknown, &i_unknown
        ))
                return NULL;

        code = InitBreakSector(
                sector->sectorID, x_vec1, y_vec1, z_vec1, x_vec2, y_vec2,
                z_vec2, x_vec3, y_vec3, z_vec3, s_unknown, d_unknown, i_unknown
        );
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// address: 0x100166c0
PyObject *bex_sec_DoBreak(PyObject *self, PyObject *args) {
        bld_py_sector_t *sector = (bld_py_sector_t *)self;
        int code;
        double x_impulse, y_impulse, z_impulse, x, y, z;
        double x_unknown, y_unknown, z_unknown;

        if (!PyArg_ParseTuple(
                args, "(ddd)(ddd)(ddd)", &x_impulse, &y_impulse, &z_impulse,
                &x, &y, &z, &x_unknown, &y_unknown, &z_unknown
        ))
                return NULL;

        code = DoBreakSector(
                sector->sectorID, x_impulse, y_impulse, z_impulse, x, y, z,
                x_unknown, y_unknown, z_unknown
        );
        if (code == 0)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


// TODO implement
// address: 0x10016794
PyObject* bex_sec_SetSurfaceTexture(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_sec_SetSurfaceTexture", NULL);
}


// TODO implement
// address: 0x1001680b
PyObject* bex_sec_SetSurfaceTextureZoomX(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_sec_SetSurfaceTextureZoomX", NULL);
}


// TODO implement
// address: 0x10016886
PyObject* bex_sec_SetSurfaceTextureZoomY(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_sec_SetSurfaceTextureZoomY", NULL);
}


// TODO implement
// address: 0x10016901
PyObject* bex_sec_SetSurfaceTextureX(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_sec_SetSurfaceTextureX", NULL);
}


// TODO implement
// address: 0x1001697c
PyObject* bex_sec_SetSurfaceTextureY(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_sec_SetSurfaceTextureY", NULL);
}


// TODO implement
// address: 0x100169f7
PyObject* bex_sec_GetSurfaceTexture(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_sec_GetSurfaceTexture", NULL);
}


// TODO implement
// address: 0x10016a70
PyObject* bex_sec_GetSurfaceTextureZoomX(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_sec_GetSurfaceTextureZoomX", NULL);
}


// TODO implement
// address: 0x10016aec
PyObject* bex_sec_GetSurfaceTextureZoomY(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_sec_GetSurfaceTextureZoomY", NULL);
}


// TODO implement
// address: 0x10016b68
PyObject* bex_sec_GetSurfaceTextureX(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_sec_GetSurfaceTextureX", NULL);
}


// TODO implement
// address: 0x10016be4
PyObject* bex_sec_GetSurfaceTextureY(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_sec_GetSurfaceTextureY", NULL);
}


// TODO implement
// address: 0x10016c60
PyObject* bex_sec_SetSpecularLight(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_sec_SetSpecularLight", NULL);
}


// TODO implement
// address: 0x10016cdb
PyObject* bex_sec_GetSpecularLight(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_sec_GetSpecularLight", NULL);
}


// TODO implement
// address: 0x10016d57
PyObject* bex_sec_SetSpecularShininess(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_sec_SetSpecularShininess", NULL);
}


// TODO implement
// address: 0x10016dd2
PyObject* bex_sec_GetSpecularShininess(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_sec_GetSpecularShininess", NULL);
}


// TODO implement
// address: 0x10016e4e
PyObject* bex_sec_SetSelfLight(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_sec_SetSelfLight", NULL);
}


// TODO implement
// address: 0x10016ec9
PyObject* bex_sec_GetSelfLight(PyObject* self, PyObject* args) {
        NOT_IMPLEMENTED_FUNC("bex_sec_GetSelfLight", NULL);
}

// address: 0x10016f45
void init_sector() {
        init_sector_type();
}

// address: 0x10016f4f
void init_sector_type() {

        memset(&sectorTypeObject, 0, sizeof(PyTypeObject));

        sectorTypeObject.ob_refcnt = 1;
        sectorTypeObject.ob_type = &PyType_Type;
        sectorTypeObject.ob_size = 0;
        sectorTypeObject.tp_name = "B_PySector";
        sectorTypeObject.tp_basicsize = sizeof(bld_py_sector_t);
        sectorTypeObject.tp_itemsize = 0;
        sectorTypeObject.tp_dealloc = bld_py_sector_dealloc;
        sectorTypeObject.tp_print = bld_py_sector_print;
        sectorTypeObject.tp_getattr = bld_py_sector_getattr;
        sectorTypeObject.tp_setattr = bld_py_sector_setattr;
        sectorTypeObject.tp_compare = NULL;
        sectorTypeObject.tp_repr = NULL;
        sectorTypeObject.tp_as_number = NULL;
        sectorTypeObject.tp_as_sequence = NULL;
        sectorTypeObject.tp_as_mapping = NULL;
        sectorTypeObject.tp_hash = NULL;
}


// address: 0x10016ffa
void bld_py_sector_dealloc(PyObject *self) {
        free(self);
}


// address: 0x1001700c
int bld_py_sector_print(PyObject *self, FILE *file, int flags) {
        static char buffer[512];
        sprintf(buffer, "Sector: %d", ((bld_py_sector_t *)self)->sectorID);
        fprintf(file, buffer);
        return 0;
}


// address: 0x1001703f
PyObject *bld_py_sector_getattr(PyObject *self, char *attr_name)
{
        int active, n_surfaces;
        double active_surf_x, active_surf_y, active_surf_z;
        PyObject *active_surface, *surf_x_obj, *surf_y_obj, *surf_z_obj;
        int num_pieces;
        double piece_x, piece_y, piece_z;
        const char *piece_name;
        PyObject *piece_x_obj, *piece_y_obj, *piece_z_obj;
        PyObject *break_info, *piece_obj, *piece_coord_obj, *piece_name_obj;
        PyObject *on_enter, *on_leave, *on_hit, *on_walk_on, *on_walk_out;
        int too_steep, action_area;
        double too_steep_angle;
        int code;

        if (!strcmp(attr_name, "__doc__"))
                return PyString_FromString("Sector de un mapa de Blade.");

        if (!strcmp(attr_name, "Active")) {
                code = GetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_INT_ACTIVE, 0,
                        &active
                );
                if (code == 1)
                        return PyInt_FromLong(active);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "nSurfaces")) {
                code = GetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_INT_N_SURFACES,
                        0, &n_surfaces
                );
                if (code == 1)
                        return PyInt_FromLong(n_surfaces);

                PyErr_SetString(PyExc_AttributeError, attr_name);

                return NULL;
        }

        if (!strcmp(attr_name, "ActiveSurface")) {
                code = GetSectorVectorProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_VEC_ACTIVE_SURFACE, 0, &active_surf_x,
                        &active_surf_y, &active_surf_z
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                active_surface = PyTuple_New(3);

                surf_x_obj = PyFloat_FromDouble(active_surf_x);
                surf_y_obj = PyFloat_FromDouble(active_surf_y);
                surf_z_obj = PyFloat_FromDouble(active_surf_z);

                PyTuple_SET_ITEM(active_surface, 0, surf_x_obj);
                PyTuple_SET_ITEM(active_surface, 1, surf_y_obj);
                PyTuple_SET_ITEM(active_surface, 2, surf_z_obj);

                return active_surface;
        }

        if (!strcmp(attr_name, "BreakInfo")) {
                int i;

                num_pieces = 0;

                code = GetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_INT_NUM_PIECES,
                        0, &num_pieces
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                if (num_pieces == 0) {
                        Py_INCREF(Py_None);
                        return Py_None;
                }

                break_info = PyTuple_New(num_pieces);

                for (i = 0; i < num_pieces; i++) {

                        piece_obj = PyTuple_New(2);
                        piece_coord_obj = PyTuple_New(3);

                        GetSectorVectorProperty(
                                ((bld_py_sector_t *)self)->sectorID,
                                SEC_VEC_PIECE, i, &piece_x, &piece_y, &piece_z
                        );

                        piece_x_obj = PyFloat_FromDouble(piece_x);
                        piece_y_obj = PyFloat_FromDouble(piece_y);
                        piece_z_obj = PyFloat_FromDouble(piece_z);

                        PyTuple_SET_ITEM(piece_coord_obj, 0, piece_x_obj);
                        PyTuple_SET_ITEM(piece_coord_obj, 1, piece_y_obj);
                        PyTuple_SET_ITEM(piece_coord_obj, 2, piece_z_obj);

                        GetSectorStringProperty(
                                ((bld_py_sector_t *)self)->sectorID,
                                SEC_STR_PIECE_NAME, i, &piece_name
                        );

                        piece_name_obj = PyString_FromString(piece_name);

                        PyTuple_SET_ITEM(piece_obj, 0, piece_name_obj);
                        PyTuple_SET_ITEM(piece_obj, 1, piece_coord_obj);

                        PyTuple_SET_ITEM(break_info, i, piece_obj);

                }

                return break_info;
        }

        if (!strcmp(attr_name, "Index")) {
                return PyInt_FromLong(((bld_py_sector_t *)self)->sectorID);
        }

        if (!strcmp(attr_name, "OnEnter")) {
                GetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_FNC_ON_ENTER,
                        0, &on_enter
                );
                return on_enter;
        }

        if (!strcmp(attr_name, "OnLeave")) {
                GetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_FNC_ON_LEAVE,
                        0, &on_leave
                );
                return on_leave;
        }

        if (!strcmp(attr_name, "OnHit")) {
                GetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_FNC_ON_HIT, 0,
                        &on_hit
                );
                return on_hit;
        }

        if (!strcmp(attr_name, "OnWalkOn")) {
                GetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_FNC_ON_WALK_ON,
                        0, &on_walk_on
                );
                return on_walk_on;
        }

        if (!strcmp(attr_name, "OnWalkOut")) {
                GetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_FNC_ON_WALK_OUT, 0, &on_walk_out
                );
                return on_walk_out;
        }

        if (!strcmp(attr_name, "TooSteep")) {
                GetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_INT_TOO_STEEP,
                        0, &too_steep
                );
                return PyInt_FromLong(too_steep);
        }

        if (!strcmp(attr_name, "TooSteepAngle")) {
                GetSectorFloatProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_FLT_TOO_STEEP_ANGLE, 0, &too_steep_angle
                );
                return PyFloat_FromDouble(too_steep_angle);
        }

        if (!strcmp(attr_name, "ActionArea")) {
                code = GetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_INT_ACTION_AREA, 0, &action_area
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, attr_name);
                        return NULL;
                }

                return PyInt_FromLong(action_area);
        }

        return Py_FindMethod(sector_methods, self, attr_name);
}


// address: 0x100175eb
int bld_py_sector_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        int active;
        PyObject *on_enter, *on_leave, *on_hit, *on_walk_on, *on_walk_out;
        double active_surf_x, active_surf_y, active_surf_z;
        int too_steep, action_area;
        double too_steep_angle;
        int num_pieces;
        double piece_x, piece_y, piece_z;
        const char *piece_name;
        PyObject *piece_x_obj, *piece_y_obj, *piece_z_obj;
        PyObject *break_info, *piece_obj, *piece_coord_obj, *piece_name_obj;
        int code;

        PyErr_Clear();
        if (value == NULL) {
                PyErr_SetString(
                        PyExc_AttributeError, "can't delete Sector attributes"
                );
                return -1;
        }

        if (!strcmp(attr_name, "Active")) {
                if (!PyArg_Parse(value, "i", &active)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_INT_ACTIVE, 0,
                        active
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "OnEnter")) {
                if(!PyArg_Parse(value, "O", &on_enter)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (!PyCallable_Check(on_enter))
                        on_enter = NULL;

                code = SetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_FNC_ON_ENTER,
                        0, on_enter
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "OnLeave")) {
                if (!PyArg_Parse(value, "O", &on_leave)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (!PyCallable_Check(on_leave))
                        on_leave = NULL;

                code = SetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_FNC_ON_LEAVE,
                        0, on_leave
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "OnHit")) {
                if (!PyArg_Parse(value, "O", &on_hit)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (!PyCallable_Check(on_hit))
                        on_hit = NULL;

                code = SetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_FNC_ON_HIT, 0,
                        on_hit
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "OnWalkOn")) {
                if (!PyArg_Parse(value, "O", &on_walk_on)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (!PyCallable_Check(on_walk_on))
                        on_walk_on = NULL;

                code = SetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_FNC_ON_WALK_ON, 0, on_walk_on
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "ActiveSurface")) {
                if (!PyArg_Parse(
                        value, "(ddd)", &active_surf_x, &active_surf_y,
                        &active_surf_z
                )) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetSectorVectorProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_VEC_ACTIVE_SURFACE, 0, active_surf_x, active_surf_y,
                        active_surf_z
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "OnWalkOut")) {
                if (!PyArg_Parse(value, "O", &on_walk_out)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (!PyCallable_Check(on_walk_out))
                        on_walk_out = NULL;

                code = SetSectorFuncProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_FNC_ON_WALK_OUT, 0, on_walk_out
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "TooSteep")) {
                if (!PyArg_Parse(value, "i", &too_steep)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_INT_TOO_STEEP,
                        0, too_steep
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "TooSteepAngle")) {
                if (!PyArg_Parse(value, "d", &too_steep_angle)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetSectorFloatProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_FLT_TOO_STEEP_ANGLE, 0, too_steep_angle
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        if (!strcmp(attr_name, "BreakInfo")) {
                int i;

                if (!PyArg_Parse(value, "O", &break_info)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                if (!PyTuple_Check(break_info)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                num_pieces = PyTuple_Size(break_info);

                SetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID, SEC_INT_NUM_PIECES,
                        0, num_pieces
                );

                for(i = 0; i < num_pieces; i++) {
                        piece_obj = PyTuple_GET_ITEM(break_info, i);

                        piece_name_obj = PyTuple_GET_ITEM(piece_obj, 0);
                        piece_coord_obj = PyTuple_GET_ITEM(piece_obj, 1);

                        piece_x_obj = PyTuple_GET_ITEM(piece_coord_obj, 0);
                        piece_y_obj = PyTuple_GET_ITEM(piece_coord_obj, 1);
                        piece_z_obj = PyTuple_GET_ITEM(piece_coord_obj, 2);

                        piece_name = PyString_AsString(piece_name_obj);
                        piece_x = PyFloat_AsDouble(piece_x_obj);
                        piece_y = PyFloat_AsDouble(piece_y_obj);
                        piece_z = PyFloat_AsDouble(piece_z_obj);

                        SetSectorVectorProperty(
                                ((bld_py_sector_t *)self)->sectorID,
                                SEC_VEC_PIECE, i, piece_x, piece_y, piece_z
                        );

                        SetSectorStringProperty(
                                ((bld_py_sector_t *)self)->sectorID,
                                SEC_STR_PIECE_NAME, i, piece_name
                        );
                }

                return 0;
        }

        if (!strcmp(attr_name, "ActionArea")) {
                if (!PyArg_Parse(value, "i", &action_area)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                code = SetSectorIntProperty(
                        ((bld_py_sector_t *)self)->sectorID,
                        SEC_INT_ACTION_AREA, 0, action_area
                );
                if (code != 1) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                return 0;
        }

        PyErr_SetString(PyExc_AttributeError, "Not implemented");
        return -1;
}


// address: 0x10017e50
PyObject *create_sound(const char *file_name, const char *sound_name) {
        int soundID;
        bld_py_sound_t *sound_obj;

        soundID = CreateSound(file_name, sound_name);
        if (soundID != 0) {

                sound_obj = PyObject_NEW(bld_py_sound_t, &soundTypeObject);

                if (sound_obj != NULL) {
                    sound_obj->soundID = soundID;
                    sound_obj->soundDev = GetSoundDevInstace();
                    return (PyObject *)sound_obj;
                } else {
                    DestroySound(soundID);
                    return NULL;
                }
        }
        return NULL;
}


// address: 0x10017ec9
PyObject *create_sound_s(int id) {
        int soundID;
        bld_py_sound_t *sound_obj;

        soundID = CreateSoundS(id);
        if (soundID == 0)
                return NULL;

        sound_obj = PyObject_NEW(bld_py_sound_t, &soundTypeObject);
        if (sound_obj == NULL) {
                DestroySound(soundID);
                return NULL;
        }

        sound_obj->soundID = soundID;
        sound_obj->soundDev = GetSoundDevInstace();

        return (PyObject *)sound_obj;
}


// address: 0x10017f3e
PyObject *get_ghost_sector_sound(const char *gs_name) {
        int soundID;
        bld_py_sound_t *sound_obj;

        soundID = GetGhostSectorSound(gs_name);
        if (soundID == 0)
                return NULL;

        sound_obj = PyObject_NEW(bld_py_sound_t, &soundTypeObject);
        if (sound_obj == NULL) {
                DestroySound(soundID);
                return NULL;
        }

        sound_obj->soundID = soundID;
        sound_obj->soundDev = GetSoundDevInstace();

        return (PyObject *)sound_obj;
}


// address: 0x10017fb3
PyObject *bex_snd_Play(PyObject *self, PyObject *args) {
        bld_py_sound_t *sound = (bld_py_sound_t *)self;
        int i_unknown = 0;
        int code;
        double x, y, z;

        if (!PyArg_ParseTuple(args, "ddd|i", &x, &y, &z, &i_unknown))
                return NULL;

        code = PlaySoundM(sound->soundID, x, y, z, i_unknown);
        if (code != 0)
                return Py_BuildValue("i", 1);
        else
                return Py_BuildValue("i", 0);
}


// address: 0x10018046
PyObject *bex_snd_PlayStereo(PyObject *self, PyObject *args) {
        bld_py_sound_t *sound = (bld_py_sound_t *)self;
        int i_unknown = 0;
        int code;

        if (!PyArg_ParseTuple(args, "|i", &i_unknown))
                return NULL;

        code = PlaySoundStereo(sound->soundID, i_unknown);
        if (code != 0)
                return Py_BuildValue("i", 1);
        else
                return Py_BuildValue("i", 0);
}


// address: 0x100180b5
PyObject *bex_snd_SetPitchVar(PyObject *self, PyObject *args) {
        bld_py_sound_t *sound = (bld_py_sound_t *)self;
        int i_unknown;
        double d_unknown1, d_unknown2, d_unknown3, d_unknown4;


        if (!PyArg_ParseTuple(
                args, "idddd", &i_unknown, &d_unknown1, &d_unknown2,
                &d_unknown3, &d_unknown4
        ))
                return NULL;

        SetSoundPitchVar(sound->soundID, i_unknown, d_unknown1, d_unknown2, d_unknown3, d_unknown4);
        return Py_BuildValue("i", 1);
}


// address: 0x1001813f
PyObject *bex_snd_AddAltSound(PyObject *self, PyObject *args) {
        bld_py_sound_t *sound = (bld_py_sound_t *)self;
        const char *alt_sound;
        int code;

        if (!PyArg_ParseTuple(args, "s", &alt_sound)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                return Py_BuildValue("i", 0);
        }

        code = addSoundVar(sound->soundID, alt_sound);
        if (code != 0)
                return Py_BuildValue("i", 1);
        else
                return Py_BuildValue("i", 0);
}


// address: 0x100181cb
PyObject *bex_snd_Stop(PyObject *self, PyObject *args) {
        bld_py_sound_t *sound = (bld_py_sound_t *)self;
        int code;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        code = StopSound(sound->soundID);
        if (code != 0)
                return Py_BuildValue("i", 1);
        else
                return Py_BuildValue("i", 0);
}


// address: 0x10018229
void init_sound() {
        init_sound_type();
}


// address: 0x10018233
void init_sound_type() {

    memset(&soundTypeObject, 0, sizeof(PyTypeObject));

    soundTypeObject.ob_refcnt = 1;
    soundTypeObject.ob_type = &PyType_Type;
    soundTypeObject.ob_size = 0;
    soundTypeObject.tp_name = "B_PySound";
    soundTypeObject.tp_basicsize = sizeof(bld_py_sound_t);
    soundTypeObject.tp_itemsize = 0;
    soundTypeObject.tp_dealloc = bld_py_sound_dealloc;
    soundTypeObject.tp_print = bld_py_sound_print;
    soundTypeObject.tp_getattr = bld_py_sound_getattr;
    soundTypeObject.tp_setattr = bld_py_sound_setattr;
    soundTypeObject.tp_compare = NULL;
    soundTypeObject.tp_repr = bld_py_sound_repr;
    soundTypeObject.tp_as_number = NULL;
    soundTypeObject.tp_as_sequence = NULL;
    soundTypeObject.tp_as_mapping = NULL;
    soundTypeObject.tp_hash = NULL;
}


// address: 0x100182de
void bld_py_sound_dealloc(PyObject *self)
{
        if (bld_py_sound_check(self))
                free(self);
}


// address: 0x10018307
boolean bld_py_sound_check(PyObject *self) {

        if (self == NULL)
                return FALSE;


        if ( ((bld_py_sound_t *)self)->soundID == 0 )
                return FALSE;

        return TRUE;
}


// address: 0x10018325
int bld_py_sound_print(PyObject *self, FILE *file, int flags)
{
        char buffer[128];

        if (bld_py_sound_check(self)) {
                sprintf(
                        buffer,
                        "Sound: %s (%d)\n",
                        GetSoundStringProperty(
                                SND_STR_NAME, ((bld_py_sound_t *)self)->soundID
                        ),
                        ((bld_py_sound_t *)self)->soundID
                );
                fprintf(file, buffer);
        }

        return 0;
}


// address: 0x1001838a
PyObject *bld_py_sound_repr(PyObject *self)
{
        char buffer[128];

        if (!bld_py_sound_check(self))
                return PyString_FromString("Invalid Sound");

        sprintf(
                buffer,
                "Sound: %s (%d)\n",
                GetSoundStringProperty(
                        SND_STR_NAME, ((bld_py_sound_t *)self)->soundID
                ),
                ((bld_py_sound_t *)self)->soundID
        );

        return PyString_FromString(buffer);
}


// address: 0x100183f5
PyObject *bld_py_sound_getattr(PyObject *self, char *attr_name)
{
        if (!bld_py_sound_check(self))
                return PyString_FromString("Invalid Sound.");

        if (!strcmp(attr_name, "__doc__"))
                return PyString_FromString("Objeto sonido Blade.");

        if (!strcmp(attr_name, "MinDistance"))
                return PyFloat_FromDouble(
                        GetSoundFloatProperty(
                                SND_FLT_MIN_DISTANCE,
                                ((bld_py_sound_t *)self)->soundID
                        )
                );

        if (!strcmp(attr_name, "MaxDistance"))
                return PyFloat_FromDouble(
                        GetSoundFloatProperty(
                                SND_FLT_MAX_DISTANCE,
                                ((bld_py_sound_t *)self)->soundID
                        )
                );

        if (!strcmp(attr_name, "Name"))
                return PyString_FromString(
                        GetSoundStringProperty(
                                SND_STR_NAME,
                                ((bld_py_sound_t *)self)->soundID
                        )
                );

        if (!strcmp(attr_name, "Volume"))
                return PyFloat_FromDouble(
                        GetSoundFloatProperty(
                                SND_FLT_VOLUME,
                                ((bld_py_sound_t *)self)->soundID
                        )
                );

        if (!strcmp(attr_name, "BaseVolume"))
                return PyFloat_FromDouble(
                        GetSoundFloatProperty(
                                SND_FLT_BASE_VOLUME,
                                ((bld_py_sound_t *)self)->soundID
                        )
                );

        if (!strcmp(attr_name, "Pitch"))
                return PyFloat_FromDouble(
                        GetSoundFloatProperty(
                                SND_FLT_PITCH,
                                ((bld_py_sound_t *)self)->soundID
                        )
                );

        if (!strcmp(attr_name, "Scale")) {
                return PyFloat_FromDouble(
                        GetSoundFloatProperty(
                                SND_FLT_SCALE,
                                ((bld_py_sound_t *)self)->soundID
                        )
                );
        }

        if (!strcmp(attr_name, "SendNotify")) {
                return PyFloat_FromDouble(/*FIXME Maybe should be int property*/
                        GetSoundFloatProperty(
                                SND_INT_SEND_NOTIFY,
                                ((bld_py_sound_t *)self)->soundID
                        )
                );
        }

        return Py_FindMethod(sound_methods, self, attr_name);
}


// address: 0x10018624
int bld_py_sound_setattr(PyObject *self, char *attr_name, PyObject *value)
{
        double min_distance, max_distance, volume, base_volume, pitch, scale;
        int send_notify;

        PyErr_Clear();
        if (!bld_py_sound_check(self)) {
                PyErr_SetString(PyExc_AttributeError, "Invalid Sound.");
                return -1;
        }

        if (value == NULL) {
                PyErr_SetString(
                        PyExc_AttributeError, "can't delete sound attributes"
                );
                return -1;
        }

        if (!strcmp(attr_name, "MinDistance")) {
                if (!PyArg_Parse(value, "d", &min_distance)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                SetSoundFloatProperty(
                        SND_FLT_MIN_DISTANCE, ((bld_py_sound_t *)self)->soundID,
                        min_distance
                );
                return 0;
        }

        if (!strcmp(attr_name, "MaxDistance")) {
                if (!PyArg_Parse(value, "d", &max_distance)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                SetSoundFloatProperty(
                        SND_FLT_MAX_DISTANCE, ((bld_py_sound_t *)self)->soundID,
                        max_distance
                );
                return 0;
        }

        if (!strcmp(attr_name, "Volume")) {
                if (!PyArg_Parse(value, "d", &volume)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                SetSoundFloatProperty(
                        SND_FLT_VOLUME, ((bld_py_sound_t *)self)->soundID,
                        volume
                );
                return 0;
        }

        if (!strcmp(attr_name, "BaseVolume")) {
                if (!PyArg_Parse(value, "d", &base_volume)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                SetSoundFloatProperty(
                        SND_FLT_BASE_VOLUME, ((bld_py_sound_t *)self)->soundID,
                        base_volume
                );
                return 0;
        }

        if (!strcmp(attr_name, "Pitch")) {
                if (!PyArg_Parse(value, "d", &pitch)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                SetSoundFloatProperty(
                        SND_FLT_PITCH, ((bld_py_sound_t *)self)->soundID, pitch
                );
                return 0;
        }

        if (!strcmp(attr_name, "Scale")) {
                if (!PyArg_Parse(value, "d", &scale)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                SetSoundFloatProperty(
                        SND_FLT_SCALE, ((bld_py_sound_t *)self)->soundID, scale
                );
                return 0;
        }

        if (!strcmp(attr_name, "SendNotify")) {
                if (!PyArg_Parse(value, "i", &send_notify)) {
                        PyErr_SetString(PyExc_AttributeError, "Invalid Param.");
                        return -1;
                }

                SetSoundIntProperty(
                        SND_INT_SEND_NOTIFY, ((bld_py_sound_t *)self)->soundID,
                        send_notify
                );
                return 0;
        }

        PyErr_SetString(PyExc_AttributeError, "Not implemented");
        return -1;
}


