//---------------------------------------------------------------------------

#include <Control/AnimationExt.h>
#include <Sound/SoundFuncs.h>
#include <Entities/EntityFuncs.h>
#include "bladex_int.h"


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


static void (*init_funcs[])(void) = {
    init_char, init_entity, init_inventory, init_material,
    init_route, init_sector, init_sound, init_trail, NULL
};

static PyMethodDef methods[] = {
    { "nEntities",                      bex_nEntities,                      METH_VARARGS, "int nEntities(void) \n Devuelve el n""\xba"" de entidades en el mapa.\n" },
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
    { "GetnScheduledFuncs",             bex_GetnScheduledFuncs,             METH_VARARGS, "int GetnScheduledFuncs(void) \n Devuelve el n""\xba"" de funciones diferidas.\n" },
    { "GetScheduledFunc",               bex_GetScheduledFunc,               METH_VARARGS, "(func,arg,name,time) GetScheduledFunc(int index) \n Devuelve una tupla con la funci""\xf3""n, los argumentos, el nombre y cuando se ejecuta.\n" },
    { "SetListenerPosition",            bex_SetListenerPosition,            METH_VARARGS, "SetListenerPosition(int modo[,double x,double y,double z]) \n Cambia posicion o modo del oyente.\n mode : 0 - Punto en el mapa\n        1 - Personaje\n        2 - C""\xe1""mara" },
    { "CreateSpark",                    bex_CreateSpark,                    METH_VARARGS, "CreateSpark(string name,double x,double y,double z,) \n Crea un efecto de chispas.\n" },
    { "CreateSound",                    bex_CreateSound,                    METH_VARARGS, "CreateSound(string filename,string soundname) \n Crea un sonido a partir del filename y con nombre name.\n" },
    { "CreateRoute",                    bex_CreateRoute,                    METH_VARARGS, "CreateRoute() \n Crea una ruta vac""\xed""a nueva.\n" },
    { "CreateTimer",                    bex_CreateTimer,                    METH_VARARGS, "CreateTimer(string TimerName,double period) \n Crea un Timer de nombre TimerName con periodo period.\n" },
    { "GetnTimers",                     bex_GetnTimers,                     METH_VARARGS, "int GetnTimers(void) \n Devuelve el n""\xfa""mero de timers del sistema.\n" },
    { "GetTimerInfo",                   bex_GetTimerInfo,                   METH_VARARGS, "(name,period) GetTimerInfo(int iTimer) \n Devuelve informaci""\xf3""n sobre el timer de ""\xed""ndice iTimer.\n" },
    { "GetTimeActionHeld",              bex_GetTimeActionHeld,              METH_VARARGS, "Return the amount of milliseconds a key has been hald down, or zero if it is currently considered released" },
    { "AddInputAction",                 bex_AddInputAction,                 METH_VARARGS, "AddInputAction(string action_name,int npi) \n Crea una acci""\xf3""n nueva.\n" },
    { "RemoveInputAction",              bex_RemoveInputAction,              METH_VARARGS, "RemoveInputAction(string action_name) \n Quita una acci""\xf3""n existente.\n" },
    { "AddBoundFunc",                   bex_AddBoundFunc,                   METH_VARARGS, "AddBoundFunc(string key,proc) \n Asigna el procedimiento pr al suceso key.\nAddBoundFunc(string key,string predproc) \n Asigna el procedimiento predefinifo predproc  al suceso key.\n predproc puede ser: Forward, Backwards, Up, Down, Left, Right, RotateLeft, RotateRight, RotateUp, RotateDown (m""\xe1""s, preguntar a Jose)" },
    { "Bind2",                          bex_Bind2,                          METH_VARARGS, "Bind2(void) \nAssociate a combination of 2 Actions keys to a new Action, time window settings." },
    { "AssocKey",                       bex_AssocKey,                       METH_VARARGS, "bool AssocKey(string action,string input_device,string key[,int press]) \nAsocia la acci""\xf3""n action con la tecla key del dispositivo input_device\n" },
    { "RemoveBoundFunc",                bex_RemoveBoundFunc,                METH_VARARGS, "RemoveBoundFunc(string key,proc) \n Quita el procedimiento pr del suceso key.\nRemoveBoundFunc(string key,string predproc) \n Quita el procedimiento predefinifo predproc  del suceso key.\n predproc puede ser: Forward, Backwards, Up, Down, Left, Right, RotateLeft, RotateRight, RotateUp, RotateDown (m""\xe1""s, preguntar a Jose)" },
    { "UnBindAll",                      bex_UnBindAll,                      METH_VARARGS, "UnBindAll() \n Borra la configuraci""\xf3""n de teclado.\n" },
    { "Input",                          bex_Input,                          METH_VARARGS, "Input(string texto) \n Crea una ventana de introducci""\xf3""n de datos.\n" },
    { "LoadLevel",                      bex_LoadLevel,                      METH_VARARGS, "LoadLevel(string dir_name) \n Lee de disco el nivel en el directorio dir_name.\n" },
    { "ReadLevel",                      bex_ReadLevel,                      METH_VARARGS, "ReadLevel(string filename) \n Lee de disco el nivel (.lvl) filename.\n" },
    { "CloseLevel",                     bex_CloseLevel,                     METH_VARARGS, "CloseLevel([string statement]) \n Cierra el nivel actual y ejecuta la instrucci""\xf3""n statement.\n" },
    { "PlaySound",                      bex_PlaySound,                      METH_VARARGS, "PlaySound(int i,double x,double y,double z) \n Reproduce el sonido i en la posici""\xf3""n (x,y,z).\n" },
    { "ShowSounds",                     bex_ShowSounds,                     METH_VARARGS, "ShowSounds(int sh) \n Establece si se debe mostrar un objeto para indicar donde estan los sonido ambiente.\n" },
    { "nSounds",                        bex_nSounds,                        METH_VARARGS, "int nSounds(void) \n Devuelve el n""\xba"" de sonidos en el mapa.\n" },
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
    { "GetEntity",                      bex_GetEntity,                      METH_VARARGS, "GetEntity(int n) \n Crea una entidad de Python que referencia a la entidad Blade de ""\xed""ndice n.\nGetEntity(string name) \n Crea una entidad de Python que referencia a la entidad Blade de nombre name.\n" },
    { "GetEntitiesAt",                  bex_GetEntitiesAt,                  METH_VARARGS, "tuple GetEntitiesAt(double x,double y,double z,double radius) \n Obtiene las entidades que est""\xe1""n en un radio radius de la posici""\xf3""n (x,y,z)\n" },
    { "GetEntitiesVisibleFrom",         bex_GetEntitiesVisibleFrom,         METH_VARARGS, "tuple GetEntitiesVisibleFrom(tuple center,double radius,tuple direction,double angle) \n" },
    { "GetObjectEntitiesVisibleFrom",   bex_GetObjectEntitiesVisibleFrom,   METH_VARARGS, "tuple GetObjectEntitiesVisibleFrom(tuple center,double radius,tuple direction,double angle) \n" },
    { "GetEnemiesVisibleFrom",          bex_GetEnemiesVisibleFrom,          METH_VARARGS, "tuple GetEnemiesVisibleFrom(tuple center,double radius,tuple direction,double angle) \n" },
    { "GetCombos",                      bex_GetCombos,                      METH_VARARGS, "tuple GetCombos(blah blah BLAH!) \n" },
    { "SetCombos",                      bex_SetCombos,                      METH_VARARGS, "bool SetCombos(tuple combos) \n" },
    { "GetWeaponCombos",                bex_GetWeaponCombos,                METH_VARARGS, "tuple GetWeaponCombos(blah blah BLAH!) \n" },
    { "GetLastPlayerCType",             bex_GetLastPlayerCType,             METH_VARARGS, "string GetLastPlayerCType() \n" },
    { "nSectors",                       bex_nSectors,                       METH_VARARGS, "int nEntities(void) \n Devuelve el n""\xba"" de sectors en el mapa.\n" },
    { "GetSector",                      bex_GetSector,                      METH_VARARGS, "GetSector(int n) \n Crea un sector de Python que referencia al sector Blade de ""\xed""ndice n.\nGetSector(double x,double y,double z) \n Crea un sector de Python que referencia al sector Blade que contiene al punto (x,y,z).\n" },
    { "GetCharType",                    bex_GetCharType,                    METH_VARARGS, "GetCharType(Barbarian,Bar) \n Crea un CharType , o raza de personaje.\n" },
    { "GetTrailType",                   bex_GetTrailType,                   METH_VARARGS, "GetTrailType(esteraCorta) \n Crea un TrailType , o tipo de estelas.\n" },
    { "SetDefaultMass",                 bex_SetDefaultMass,                 METH_VARARGS, "SetDefaultMass(string entity_kind,double mass) \n Establece la masa mass predefinida para las nuevas entidades de tipo kind.\n" },
    { "SetDefaultMaterial",             bex_SetDefaultMaterial,             METH_VARARGS, "SetDefaultMaterial(string entity_kind,double material) \n Establece el material predefinido para las nuevas entidades de tipo kind.\n" },
    { "CreateMaterial",                 bex_CreateMaterial,                 METH_VARARGS, "CreateMaterial(string name) \n Crea un nuevo material con nombre name.\n" },
    { "GetMaterial",                    bex_GetMaterial,                    METH_VARARGS, "GetMaterial(int n) \n Crea un objeto Python que referencia al material Blade de ""\xed""ndice n.\nGetMaterial(string name) \n Crea un objeto Python que referencia al material Blade de nombre name.\n" },
    { "nMaterials",                     bex_nMaterials,                     METH_VARARGS, "nMaterials(void) \n Devuelve el n""\xba"" de materiales.\n" },
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
    { "nTriggerSectors",                bex_nTriggerSectors,                METH_VARARGS, "int nTriggerSectors(void)\n Desvincula el n""\xfa""mero de triggersectors en el mapa.\n" },
    { "GetTriggerSectorName",           bex_GetTriggerSectorName,           METH_VARARGS, "string GetTriggerSectorName(int idx)\n Devuelve el triggersector de ""\xed""ndice idx, None si no existe.\n" },
    { "CDPlayTrack",                    bex_CDPlayTrack,                    METH_VARARGS, "PlayCDTrack(int ntrack) \n Reproduce la pista ntrack del CD.\n Si ntrack==1 reproduce todo el CD.\n" },
    { "CDnTracks",                      bex_CDnTracks,                      METH_VARARGS, "int nCDTracks() \n Devuelve el n""\xfa""mero de pistas del CD.\n" },
    { "CDLenght",                       bex_CDLenght,                       METH_VARARGS, "int CDLenght() \n Devuelve la duraci""\xf3""n del CD en milisegundos.\n" },
    { "CDTrackLenght",                  bex_CDTrackLenght,                  METH_VARARGS, "CDTrackLenght(int ntrack) \n Devuelve la duraci""\xf3""n en milisegundos de la pista ntrack.\n" },
    { "CDPresent",                      bex_CDPresent,                      METH_VARARGS, "int CDPresent() \n Indica si est""\xe1"" el CD.\n" },
    { "CDStop",                         bex_CDStop,                         METH_VARARGS, "int CDStop() \n Detiene el CD.\n" },
    { "CDPause",                        bex_CDPause,                        METH_VARARGS, "int CDPause() \n Detiene el CD.\n" },
    { "CDCallBack",                     bex_CDCallBack,                     METH_VARARGS, "int CDCallBack(func f) \n Establece la funci""\xf3""n CD.\n" },
    { "SetSun",                         bex_SetSun,                         METH_VARARGS, "SetSun(int exists,double x,double y,double z) \n Establece la posicion del sol mediante la direccion de la luz exterior. exists indica si se dibuja (1) o no (0) \n" },
    { "InsideActionArea",               bex_InsideActionArea,               METH_VARARGS, "InsideActionArea(int AA,double x,double y,double z) \n....blah blah !\n" },
    { "AnmAddEvent",                    bex_AnmAddEvent,                    METH_VARARGS, "AnmAddEvent(anm_name,event_name,event_frame) \nDeclara en la animacion de nombre anm_name un evento de nombre event_name en el frame event_frame" },
    { "AddAnmEvent",                    bex_AddAnmEvent,                    METH_VARARGS, "AnmAddEvent(anm_name,event_name,event_frame) \n" },
    { "AnmDelEvent",                    bex_AnmDelEvent,                    METH_VARARGS, "AnmDelEvent(anm_name,event_name) \nBorra en la animacion de nombre anm_name el evento de nombre event_name" },
    { "AnmClearEvents",                 bex_AnmClearEvents,                 METH_VARARGS, "AnmClearEvents(anm_name) \nBorra en la animacion de nombre anm_name todos los eventos" },
    { "AnmGetEventFrame",               bex_AnmGetEventFrame,               METH_VARARGS, "AnmGetEventFrame(anm_name,event_name) \nDevuelve en la animacion de nombre anm_name frame del evento de nombre event_name y si no existe devuelve -1" },
    { "AddParticleGType",               bex_AddParticleGType,               METH_VARARGS, "" },
    { "SetParticleGVal",                bex_SetParticleGVal,                METH_VARARGS, "" },
    { "GetnParticleGType",              bex_GetnParticleGType,              METH_VARARGS, "int GetnParticleGType(void)\n  Devuelve el n""\xba"" de tipos de part""\xed""culas.\n" },
    { "GetParticleGType",               bex_GetParticleGType,               METH_VARARGS, "Preguntar a Angel" },
    { "GetParticleGVal",                bex_GetParticleGVal,                METH_VARARGS, "Preguntar a Angel" },
    { "AddCombustionDataFor",           bex_AddCombustionDataFor,           METH_VARARGS, "AddCombustionDataFor(object_kind,upper_treshol,lower_treshold,flame_height,flame_size,speed,livetime) \n" },
    { "SetRootWidget",                  bex_SetRootWidget,                  METH_VARARGS, "SetRootWidget(widget w) \n Establece el Widget raiz.\n" },
    { "GetRootWidget",                  bex_GetRootWidget,                  METH_VARARGS, "SetRootWidget(widget w) \n Establece el Widget raiz.\n" },
    { "SetCallCheck",                   bex_SetCallCheck,                   METH_VARARGS, "SetCallCheck(int check) \n Activa/desactiva la comprobaci""\xf3""n de errores de Python en las llamadas que hace Blade.\nDevuelve el estado anterior\n" },
    { "DrawBOD",                        bex_DrawBOD,                        METH_VARARGS, "DrawBOD(string BODName,int x,int y,int ancho,int alto) \n Dibuja el BOD de nombre BODName en el rect""\xe1""ngulo x,y,ancho,alto.\n" },
    { "SetAfterFrameFunc",              bex_SetAfterFrameFunc,              METH_VARARGS, "SetAfterFrameFunc(name,function)\n Sets a function referenced with name that is going to be called at the end of each frame." },
    { "GetAfterFrameFunc",              bex_GetAfterFrameFunc,              METH_VARARGS, "GetAfterFrameFunc(name)\n Devuelve la funci""\xf3""n AfterFrame de nombre name.\n" },
    { "GetAfterFrameFuncName",          bex_GetAfterFrameFuncName,          METH_VARARGS, "string GetAfterFrameFuncName(int idx)\n Devuelve el nombre de la funci""\xf3""n AfterFrame del sistema de ""\xed""ndice idx.\n" },
    { "GetnAfterFrameFuncs",            bex_GetnAfterFrameFuncs,            METH_VARARGS, "int GetnAfterFrameFuncs()\n Devuelve el n""\xba"" de funciones AfterFrame en el sistema.\n" },
    { "RemoveAfterFrameFunc",           bex_RemoveAfterFrameFunc,           METH_VARARGS, "GetAfterFrameFunc(name)\n Devuelve la funci""\xf3""n AfterFrame del sistema de nombre name.\n" },
    { "SetMenuTgapFunc",                bex_SetMenuTgapFunc,                METH_VARARGS, "SetMenuTgapFunc(function)\n Sets a function blah blah blah...\n" },
    { "GetMenuTgapFunc",                bex_GetMenuTgapFunc,                METH_VARARGS, "GetMenuTgapFunc()\n Devuelve .....\n" },
    { "WriteText",                      bex_WriteText,                      METH_VARARGS, "" },
    { "GetTextWH",                      bex_GetTextWH,                      METH_VARARGS, "" },
    { "GetScreenRect",                  bex_GetScreenRect,                  METH_VARARGS, "" },
    { "GetScreenXY",                    bex_GetScreenXY,                    METH_VARARGS, "" },
    { "ShowActionAreas",                bex_ShowActionAreas,                METH_VARARGS, "" },
    { "ExportWorld",                    bex_ExportWorld,                    METH_VARARGS, "ExportWorld () \n Export the world to owner Max format.\n" },
    { "CheckPyErrors",                  bex_CheckPyErrors,                  METH_VARARGS, "returns whether a python error has occured." },
    { "SetAppMode",                     bex_SetAppMode,                     METH_VARARGS, "bool SetAppMode(string mode) \n Establece el modo de la aplicaci""\xf3""n (Game, Menu,...).\n" },
    { "GetAppMode",                     bex_GetAppMode,                     METH_VARARGS, "string GetAppMode() \n Obtiene el modo de la aplicaci""\xf3""n (Game, Menu,...).\n" },
    { "Quit",                           bex_Quit,                           METH_VARARGS, "bool Quit() \n Termina el programa.\n" },
    { "OpenDebugChannel",               bex_OpenDebugChannel,               METH_VARARGS, "bool OpenDebugChannel(string channel_name) \n Abre el canal de depuraci""\xf3""n de nombre channel_name.\n" },
    { "CloseDebugChannel",              bex_CloseDebugChannel,              METH_VARARGS, "bool CloseDebugChannel(string channel_name) \n Cierra el canal de depuraci""\xf3""n de nombre channel_name.\n" },
    { "LoadSampledAnimation",           bex_LoadSampledAnimation,           METH_VARARGS, "LoadSampledAnm(str File,str InternalName,int Type)" },
    { "CreateFCAnimation",              bex_CreateFCAnimation,              METH_VARARGS, "CreateFCAnmimation(str File,str InternalName,int n_armonics)" },
    { "CreateDFCAnimation",             bex_CreateDFCAnimation,             METH_VARARGS, "CreateDFCAnmimation(str File1,str File2,str InternalName,int n_armonics)" },
    { "GetAnmRaces",                    bex_GetAnmRaces,                    METH_VARARGS, "list GetAnmRaces(void) \n  Devuelve una lista con los nombres de las razas cargadas en memoria.\n" },
    { "CreateBipedData",                bex_CreateBipedData,                METH_VARARGS, "" },
    { "AddBipedAction",                 bex_AddBipedAction,                 METH_VARARGS, "" },
    { "RemoveBipedAction",              bex_RemoveBipedAction,              METH_VARARGS, "" },
    { "GetWorldFileName",               bex_GetWorldFileName,               METH_VARARGS, "string GetWorldFileName()\n Obtiene el nombre del archivo del que se ha cargado el mundo actual.\n" },
    { "LoadWorld",                      bex_LoadWorld,                      METH_VARARGS, "LoadWorld(string filename) \n Lee de disco el mapa (.bw) de nombre filename.\n" },
    { "DoneLoadGame",                   bex_DoneLoadGame,                   METH_VARARGS, "void DoneLoadGame() \n Indica a la engine que se ha cargado una partida grabada para que pueda ajustar par""\xe1""metros.\n" },
    { "BeginLoadGame",                  bex_BeginLoadGame,                  METH_VARARGS, "void BeginLoadGame() \n Indica a la engine que se va a cargar una partida grabada para que pueda ajustar par""\xe1""metros.\n" },
    { "SetSaveInfo",                    bex_SetSaveInfo,                    METH_VARARGS, "int SetSaveInfo(tuple info) \n  Establece informaci""\xf3""n de estado.\n" },
    { "GetSaveInfo",                    bex_GetSaveInfo,                    METH_VARARGS, "tuple GetSaveInfo(void) \n  Obtiene informaci""\xf3""n de estado.\n" },
    { "LoadEntitiesData",               bex_LoadEntitiesData,               METH_VARARGS, "bool LoadEntitiesData(string filename) \n  Carga los datos de las entidades del archivo filename.\n" },
    { "SaveEntitiesData",               bex_SaveEntitiesData,               METH_VARARGS, "bool SaveEntitiesData(string filename) \n  Guarda los datos de las entidades en el archivo filename.\n" },
    { "LoadParticleSystemsData",        bex_LoadParticleSystemsData,        METH_VARARGS, "bool LoadParticleSystemsData(string filename) \n  Carga los datos de los sistemas de part""\xed""culas del archivo filename.\n" },
    { "SaveParticleSystemsData",        bex_SaveParticleSystemsData,        METH_VARARGS, "bool SaveParticleSystemsData(string filename) \n  Guarda los datos de los sistemas de part""\xed""culas en el archivo filename.\n" },
    { "LoadAnmRaceData",                bex_LoadAnmRaceData,                METH_VARARGS, "bool LoadAnmRaceData(string filename,string race) \n  Carga las animaciones de la raza en el archivo filename.\n" },
    { "SaveAnmRaceData",                bex_SaveAnmRaceData,                METH_VARARGS, "bool SaveAnmRaceData(string filename,string race) \n  Guarda las animaciones de la raza race en el archivo filename.\n" },
    { "LoadAnmSoundData",               bex_LoadAnmSoundData,               METH_VARARGS, "bool LoadAnmSoundData(string filename,string race) \n  Carga la informaci""\xf3""n de sonido de las animaciones de la raza en el archivo filename.\n" },
    { "SaveAnmSoundData",               bex_SaveAnmSoundData,               METH_VARARGS, "bool SaveAnmSoundData(string filename,string race) \n  Guarda informaci""\xf3""n de sonido de las animaciones de la raza race en el archivo filename.\n" },
    { "SaveProfileData",                bex_SaveProfileData,                METH_VARARGS, "bool SaveProfileData(string filename) \n  Tiene que estar activado el profiler interno.\n  Guarda informaci""\xf3""n de los tiempos de las secciones activas en el archivo filename.\n" },
    { "OpenProfileSection",             bex_OpenProfileSection,             METH_VARARGS, "bool OpenProfileSection(int section[,string comment]) \n  Tiene que estar activado el profiler interno.\n  Abre la secci""\xf3""n i.\n" },
    { "CloseProfileSection",            bex_CloseProfileSection,            METH_VARARGS, "bool CloseProfileSection(int section) \n  Tiene que estar activado el profiler interno.\n  Cierra la secci""\xf3""n i.\n" },
    { "StartProfile",                   bex_StartProfile,                   METH_VARARGS, "bool StartProfile(void) \n  Tiene que estar activado el profiler interno.\n  Reinicia sesi""\xf3""n.\n" },
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
    { "GetCommandLine",                 bex_GetCommandLine,                 METH_VARARGS, "string GetCommandLine() \n Obtiene la l""\xed""nea de ""\xf3""rdenes que se ha pasado a la aplicaci""\xf3""n.\n" },
    { "GetProgramId",                   bex_GetProgramId,                   METH_VARARGS, "int GetProgramId()\n Devuelve identificador de la aplicaci""\xf3""n.\n (HWND en Windows)" },
    { "GetWindowId",                    bex_GetWindowId,                    METH_VARARGS, "int GetWindowId()\n Devuelve identificador de la ventana de la aplicaci""\xf3""n.\n (HWND en Windows)" },
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


/*
* Module:                 Bladex.dll
* Entry point:            0x10001000
*/

PyObject *bex_ExportWorld(PyObject *self, PyObject *args) {
        const char *world;
        int ret = 0;

        if (PyArg_ParseTuple(args, "s", &world))
                ret = WorldToMBW(world);

        return Py_BuildValue("i", ret);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000104D
*/

PyObject *bex_SoundSystemActive(PyObject *self, PyObject *args) {

        if (SoundSystemActive() != 1) {
                return Py_BuildValue("i", 0);
        } else {
                return Py_BuildValue("i", 1);
        }
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10001086
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100010E6
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10001146
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100011A6
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10001206
*/

PyObject *bex_KillMusic(PyObject *self, PyObject *args) {
        int ret;

        ret = KillMusic();

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000123F
*/

PyObject *bex_ShutDownSoundChannels(PyObject *self, PyObject *args) {
        int ret;

        ret = ShutDownSoundChannels();

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10001278
*/

PyObject *bex_PauseSoundSystem(PyObject *self, PyObject *args) {
        int ret;

        ret = PauseSoundSystem();

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100012B1
*/

PyObject *bex_PauseSoundSystemButMusic(PyObject *self, PyObject *args) {
        int ret;

        ret = PauseSoundSystemButMusic();

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100012EA
*/

PyObject *bex_ResumeSoundSystem(PyObject *self, PyObject *args) {
        int ret;

        ret = ResumeSoundSystem();

        if (ret != 1)
                return Py_BuildValue("i", 0);
        else
                return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10001323
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10001397
*/

PyObject *bex_GetMusicVolume(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("d", GetMusicVolume());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100013DA
*/

PyObject *bex_SetSoundVolume(PyObject *self, PyObject *args) {
        double volume = 1.0;

        if (!PyArg_ParseTuple(args, "d", &volume))
                return NULL;

        return Py_BuildValue("i", SetSoundVolume(volume));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10001436
*/

PyObject *bex_GetSoundVolume(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("d", GetSoundVolume());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10001479
*/

PyObject *bex_GetSpeakerConfig(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetSSSpeakerConfig());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100014B6
*/

PyObject *bex_SetEAXOverride(PyObject *self, PyObject *args) {
        int EAXOverride = 1;

        if (!PyArg_ParseTuple(args, "i", &EAXOverride))
                return NULL;

        return Py_BuildValue("i", SetEAXOverride(EAXOverride));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10001507
*/

PyObject *bex_GetEAXOverride(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetEAXOverride());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10001544
*/

PyObject *bex_SaveSSConfig(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", SaveSSConfig());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10001581
*/

PyObject *bex_SetSpeakerConfig(PyObject *self, PyObject *args) {
        int config = 1;

        if (!PyArg_ParseTuple(args, "i", &config))
                return NULL;

        return Py_BuildValue("i", SetSSSpeakerConfig(config));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100015D2
*/

PyObject *bex_GetSSQuality(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetSSQuality());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000160F
*/

PyObject *bex_SetSSQuality(PyObject *self, PyObject *args) {
        int SSQuality = 1;

        if (!PyArg_ParseTuple(args, "i", &SSQuality))
                return NULL;

        return Py_BuildValue("i", SetSSQuality(SSQuality));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10001660
*/

PyObject *bex_SetAutoGenTexture(PyObject *self, PyObject *args) {
        const char *textureName;
        int textureEffect;

        if (!PyArg_ParseTuple(args, "si", &textureName, &textureEffect))
                return NULL;

        return Py_BuildValue("i", SetAutoGenTexture(textureName, textureEffect));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100016B2
*/

PyObject *bex_SetBloodLevel(PyObject *self, PyObject *args) {
        double blood_level = 1.0;

        if (!PyArg_ParseTuple(args, "d", &blood_level))
                return NULL;

        return Py_BuildValue("i", SetBloodLevel(blood_level));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000170F
*/

PyObject *bex_GetBloodLevel(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetBloodLevel());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000174C
*/

PyObject *bex_SetMutilationLevel(PyObject *self, PyObject *args) {
        double mutilation_level = 1.0;

        if (!PyArg_ParseTuple(args, "d", &mutilation_level))
                return NULL;

        return Py_BuildValue("i", SetMutilationLevel(mutilation_level));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100017A9
*/

PyObject *bex_GetMutilationLevel(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetMutilationLevel());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100017E6
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10001842
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100018B7
*/

PyObject *bex_CheckAnims(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", CheckAnims());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100018F4
*/

PyObject *bex_GiveAnims(PyObject *self, PyObject *args) {
        const char *race_name;

        if (!PyArg_ParseTuple(args, "s", &race_name))
                return NULL;

        return Py_BuildValue("i", GiveAnims(race_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000193E
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100019AA
*/

PyObject *bex_SetAnimationFactor(PyObject *self, PyObject *args) {
        const char *mov;
        double new_speed_factor;

        if (!PyArg_ParseTuple(args, "sd", &mov, &new_speed_factor))
                return NULL;

        return Py_BuildValue("i", SetAnimationFactor(mov, new_speed_factor));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10001A00
*/

PyObject *bex_SetTurnSpeed(PyObject *self, PyObject *args) {
        const char *race_name;
        double new_speed;

        if (!PyArg_ParseTuple(args, "sd", &race_name, &new_speed))
                return NULL;

        SetTurnSpeed(race_name, new_speed);

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10001A51
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10001BA3
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10001C5E
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10001D0A
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10001E46
*/

PyObject *bex_SetListenerPosition(PyObject *self, PyObject *args) {
        int mode;
        double x = 0.0, y = 0.0, z = 0.0;

        if (!PyArg_ParseTuple(args, "i|ddd", &mode, &x, &y, &z))
                return NULL;

        return Py_BuildValue("i", SetListenerMode(mode, x, y, z));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10001EE7
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10001FAF
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10002011
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x1000206A
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100020B6
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10002118
*/

PyObject *bex_CreateTimer(PyObject *self, PyObject *args) {
        const char *timer_name;
        double period;

        if (!PyArg_ParseTuple(args, "sd", &timer_name, &period))
                return NULL;

        return Py_BuildValue("i", CreateTimer(timer_name, period));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000216E
*/

PyObject *bex_GetnTimers(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetnTimers());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100021AB
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10002255
*/

PyObject *bex_AddScheduledFunc(PyObject *self, PyObject *args) {
        double time;
        PyObject *func, *func_args;
        const char *name = "Unnamed";

        if (!PyArg_ParseTuple(args, "dOO|s", &time, &func, &func_args, &name))
                return NULL;

        return Py_BuildValue("i", AddScheduledFunc(time, func, func_args, name));
}

/*
* Module:                 Bladex.dll
* Entry point:            0x100022C2
*/

PyObject *bex_RemoveScheduledFunc(PyObject *self, PyObject *args) {
        const char *name;

        if (!PyArg_ParseTuple(args, "s", &name))
                return NULL;

        return Py_BuildValue("i", RemoveScheduledFunc(name));
}

/*
* Module:                 Bladex.dll
* Entry point:            0x1000230C
*/

PyObject *bex_GetnScheduledFuncs(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetnScheduledFuncs());
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10002349
*/

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

/*
* Module:                 Bladex.dll
* Entry point:            0x10002499
*/

PyObject *bex_nEntities(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", nEntities());
}

/*
* Module:                 Bladex.dll
* Entry point:            0x100024D6
*/

PyObject *bex_nSectors(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i",  nSectors());
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10002513
*/

PyObject *bex_GetTime(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("d", GetTime());
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10002556
*/

PyObject *bex_SetTime(PyObject *self, PyObject *args) {
        double time;

        if(!PyArg_ParseTuple(args, "d", &time))
                return NULL;

        return Py_BuildValue("i", SetTime(time));
}

/*
* Module:                 Bladex.dll
* Entry point:            0x100025A4
*/

PyObject *bex_GoToTime(PyObject *self, PyObject *args) {
        double time;

        if(!PyArg_ParseTuple(args, "d", &time))
                return NULL;

        return Py_BuildValue("i", GoToTime(time));
}

/*
* Module:                 Bladex.dll
* Entry point:            0x100025F2
*/

PyObject *bex_StopTime(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        StopTime();

        Py_INCREF(Py_None);
        return Py_None;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x1000262E
*/

PyObject *bex_RestartTime(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        RestartTime();

        Py_INCREF(Py_None);
        return Py_None;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x1000266A
*/

PyObject *bex_GetTimeSpeed(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("d", GetTimeSpeed());
}

/*
* Module:                 Bladex.dll
* Entry point:            0x100026AD
*/

PyObject *bex_SetTimeSpeed(PyObject *self, PyObject *args) {
        double speed;

        if(!PyArg_ParseTuple(args, "d", &speed))
                return NULL;

        SetTimeSpeed(speed);
    
        return Py_BuildValue("i", 1);
}

/*
* Module:                 Bladex.dll
* Entry point:            0x100026F6
*/

PyObject *bex_GetNewExclusionGroupId(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetNewExclusionGroupId());
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10002733
*/

PyObject *bex_AssocKey(PyObject *self, PyObject *args) {
        const char *action, *input_device, *key;
        int press = 1;

        if(!PyArg_ParseTuple(args, "sss|i", &action, &input_device, &key, &press))
                return NULL;

        return Py_BuildValue("i", AssocKey(action, input_device, key, press));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000279C
*/

PyObject* bex_GetTimeActionHeld(PyObject* self, PyObject* args) {
        const char *action_name;

        if(!PyArg_ParseTuple(args, "s", &action_name))
                return NULL;

        return Py_BuildValue("d", GetTimeActionHeld(action_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100027EA
*/

PyObject* bex_AddInputAction(PyObject* self, PyObject* args) {
        const char *action_name;
        int npi;

        if(!PyArg_ParseTuple(args, "si", &action_name, &npi))
                return NULL;

        return Py_BuildValue("i", AddInputAction(action_name, npi));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000283C
*/

PyObject* bex_RemoveInputAction(PyObject* self, PyObject* args) {
        const char *action_name;

        if(!PyArg_ParseTuple(args, "s", &action_name))
                return NULL;

        return Py_BuildValue("i", RemoveInputAction(action_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10002886
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10002924
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10002993
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10002A31
*/

PyObject *bex_UnBindAll(PyObject* self, PyObject* args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        UnBindAll();

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10002A6D
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10002ACF
*/

PyObject *bex_LoadLevel(PyObject* self, PyObject* args) {
        const char *dir_name;

        if(!PyArg_ParseTuple(args, "s", &dir_name))
                return NULL;

        MarkLevelToLoad(dir_name);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10002B19
*/

PyObject *bex_ReadLevel(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        ReadLevel(file_name);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10002B63
*/

PyObject *bex_CloseLevel(PyObject *self, PyObject *args) {
        const char *statement = NULL, *newMap = NULL;

        if(!PyArg_ParseTuple(args, "|ss", &statement, &newMap))
                return NULL;

        CloseLevel(statement, newMap);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10002BC6
*/

PyObject *bex_PlaySound(PyObject *self, PyObject *args) {
        int soundId, unknown = 0;
        double x, y, z;

        if(!PyArg_ParseTuple(args, "iddd|i", &soundId, &x, &y, &z, &unknown))
                return NULL;

        return Py_BuildValue("i", OutSound(soundId, x, y, z, unknown));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10002C43
*/

PyObject *bex_ShowSounds(PyObject *self, PyObject *args) {
        int showSounds;

        if(!PyArg_ParseTuple(args, "i", &showSounds))
                return NULL;

        return Py_BuildValue("i", SetShowSounds(showSounds));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10002C8D
*/

PyObject *bex_nSounds(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", nSounds());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10002CCA
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10002D33
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10002D9C
*/

PyObject *bex_ReadBitMap(PyObject *self, PyObject *args) {
        const char *file_name;
        const char *internal_name;

        if(!PyArg_ParseTuple(args, "ss", &file_name, &internal_name))
                return NULL;

        ReadBitMap(file_name, internal_name);

        Py_INCREF(Py_None);
        return Py_None;
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10002DF1
*/

PyObject *bex_ReadAlphaBitMap(PyObject *self, PyObject *args) {
        const char *file_name;
        const char *internal_name;

        if(!PyArg_ParseTuple(args, "ss", &file_name, &internal_name))
                return NULL;

        ReadAlphaBitMap(file_name, internal_name);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10002E46
*/

PyObject *bex_SetSun(PyObject *self, PyObject *args) {
        int exists;
        double x, y, z;

        if(!PyArg_ParseTuple(args, "iddd", &exists, &x, &y, &z))
                return NULL;

        SetSun(exists, x, y, z);

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10002EAF
*/

PyObject *bex_InsideActionArea(PyObject *self, PyObject *args) {
        int AA;
        double x, y, z;

        if(!PyArg_ParseTuple(args, "iddd", &AA, &x, &y, &z))
                return NULL;

        return Py_BuildValue("i", InsideAA(AA, x, y, z));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10002F1D
*/

PyObject *bex_AnmAddEvent(PyObject *self, PyObject *args) {
        const char *anm_name, *event_name;
        double event_frame;

        if(!PyArg_ParseTuple(args, "ssd", &anm_name, &event_name, &event_frame))
                return NULL;

        AnmAddEvent(anm_name, event_name, event_frame);

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10002F76
*/

PyObject *bex_AddAnmEvent(PyObject *self, PyObject *args) {
        const char *anm_name, *event_name;
        double event_frame;

        if(!PyArg_ParseTuple(args, "ssd", &anm_name, &event_name, &event_frame))
                return NULL;

        AddAnmEvent(anm_name, event_name, event_frame);

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10002FCF
*/

PyObject *bex_AnmDelEvent(PyObject *self, PyObject *args) {
        const char *anm_name, *event_name;

        if(!PyArg_ParseTuple(args, "ss", &anm_name, &event_name))
                return NULL;

        AnmDelEvent(anm_name, event_name);

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000301C
*/

PyObject *bex_AnmClearEvents(PyObject *self, PyObject *args) {
        const char *anm_name;

        if(!PyArg_ParseTuple(args, "s", &anm_name))
                return NULL;

        AnmClearEvents(anm_name);

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000305F
*/

PyObject *bex_AnmGetEventFrame(PyObject *self, PyObject *args) {
        const char *anm_name, *event_name;

        if(!PyArg_ParseTuple(args, "ss", &anm_name, &event_name))
                return NULL;

        return Py_BuildValue("d", AnmGetEventFrame(anm_name, event_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100030B5
*/

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

/*
* Module:                 Bladex.dll
* Entry point:            0x10003117
*/

PyObject *bex_SetParticleGVal(PyObject *self, PyObject *args) {
        const char *type;
        int i, r, g, b, alpha;
        double size;

        if(!PyArg_ParseTuple(args, "siiiiid", &type, &i, &r, &g, &b, &alpha, &size))
                return NULL;

        return Py_BuildValue("i", SetParticleGVal(type, i, r, g, b, alpha, size));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10003195
*/

PyObject *bex_GetnParticleGType(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetnParticleGType());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100031D2
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100032B1
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100033BC
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x1000348F
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100035E2
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10003735
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10003814
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100039FD
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10003AE4
*/

PyObject *bex_GetLastPlayerCType(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("s", GetLastPlayerCType());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10003B28
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10003C7B
*/

PyObject *bex_CDPlayTrack(PyObject *self, PyObject *args) {
        int ntrack;

        if(!PyArg_ParseTuple(args, "i", &ntrack))
                return NULL;

        return Py_BuildValue("i", PlayCDTrack(ntrack));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10003CC5
*/

PyObject *bex_CDnTracks(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", nCDTracks());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10003D02
*/

PyObject *bex_CheckPyErrors(PyObject *self, PyObject *args) {

    if (PyErr_Occurred()) {
        PyErr_Print();
        PyErr_Clear();
        return Py_BuildValue("i", 1);
    }

    return Py_BuildValue("i", 0);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10003D47
*/

PyObject *bex_CDLenght(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", CDLenght());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10003D84
*/

PyObject *bex_CDTrackLenght(PyObject *self, PyObject *args) {
        int ntrack;

        if(!PyArg_ParseTuple(args, "i", &ntrack))
                return NULL;

        return Py_BuildValue("i", CDTrackLenght(ntrack));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10003DCE
*/

PyObject *bex_CDPresent(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", CDPresent());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10003E0B
*/

PyObject *bex_CDStop(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", CDStop());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10003E48
*/

PyObject *bex_CDPause(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", CDPause());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10003E85
*/

PyObject *bex_CDCallBack(PyObject *self, PyObject *args) {
        PyObject *func;

        if(!PyArg_ParseTuple(args, "O", &func))
                return NULL;

        return Py_BuildValue("i", CDSetCallBack(func));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10003ECF
*/

PyObject *bex_SetDefaultMass(PyObject *self, PyObject *args) {
        const char *entity_kind;
        double mass;

        if(!PyArg_ParseTuple(args, "sd", &entity_kind, &mass))
                return NULL;

        return Py_BuildValue("i", SetDefaultMass(entity_kind, mass));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10003F25
*/

PyObject *bex_SetDefaultMaterial(PyObject *self, PyObject *args) {
        const char *entity_kind, *material;

        if(!PyArg_ParseTuple(args, "ss", &entity_kind, &material))
                return NULL;

        return Py_BuildValue("i", SetDefaultMaterial(entity_kind, material));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10003F77
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10003FD0
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x1000407C
*/

PyObject *bex_nMaterials(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", nMaterials());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100040B9
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x1000426F
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10004425
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10004497
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100044FA
*/

PyObject *bex_SetTriggerSectorData(PyObject *self, PyObject *args) {
        const char *trigger_sector_name;
        PyObject *data;

        if (!PyArg_ParseTuple(args, "sO", &trigger_sector_name, &data))
                return NULL;

        return Py_BuildValue(
                "i", SetTriggerSectorData(trigger_sector_name, data)
        );
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000454C
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100045A6
*/

PyObject *bex_RemoveTriggerSectorFunc(PyObject *self, PyObject *args) {
        const char *trigger_sector_name, *func_type;

        if (!PyArg_ParseTuple(args, "ss", &trigger_sector_name, &func_type))
                return NULL;

        return Py_BuildValue(
                "i", SetTriggerSectorFunc(trigger_sector_name, func_type, NULL)
        );
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100045FA
*/

PyObject *bex_GetTriggerSectorFloorHeight(PyObject *self, PyObject *args) {
        const char *trigger_sector_name;

        if (!PyArg_ParseTuple(args, "s", &trigger_sector_name))
                return NULL;

        return Py_BuildValue(
                "i", GetTriggerSectorFloorHeight(trigger_sector_name)
        );
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10004644
*/

PyObject *bex_GetTriggerSectorRoofHeight(PyObject *self, PyObject *args) {
        const char *trigger_sector_name;

        if (!PyArg_ParseTuple(args, "s", &trigger_sector_name))
                return NULL;

        return Py_BuildValue(
                "i", GetTriggerSectorRoofHeight(trigger_sector_name)
        );
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000468E
*/

PyObject *bex_GetTriggerSectorGroup(PyObject *self, PyObject *args) {
        const char *trigger_sector_name;

        if (!PyArg_ParseTuple(args, "s", &trigger_sector_name))
                return NULL;

        return Py_BuildValue("s", GetTriggerSectorGroup(trigger_sector_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100046D8
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100047F4
*/

PyObject *bex_nTriggerSectors(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", nTriggerSectors());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10004831
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x1000489A
*/

PyObject *bex_GenerateEntityName(PyObject *self, PyObject *args) {

        return Py_BuildValue("s", GenerateEntityName());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100048C6
*/

PyObject *bex_AddWatchAnim(PyObject *self, PyObject *args) {
        const char *anim;

        if (!PyArg_ParseTuple(args, "s", &anim))
                return NULL;

        return Py_BuildValue("i", AddWatchAnim(anim));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10004910
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x1000498A
*/

PyObject *bex_SetEAX(PyObject *self, PyObject *args) {
        int eax_flag;

        if (!PyArg_ParseTuple(args, "i", &eax_flag))
                return NULL;

        return Py_BuildValue("i", SetEAX(eax_flag));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100049D4
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10004A42
*/

PyObject *bex_DeactivateInput(PyObject *self, PyObject *args) {
        return Py_BuildValue("i", DeactivateInput());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10004A65
*/

PyObject *bex_ActivateInput(PyObject *self, PyObject *args) {
        return Py_BuildValue("i", ActivateInput());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10004A88
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10004B76
*/

PyObject *bex_GetSound(PyObject *self, PyObject *args) {
        B_Sound *sound;
        bld_py_sound_t *sound_obj;
        const char *sound_name;

        if (!PyArg_ParseTuple(args, "s", &sound_name)) {
                PyErr_SetString(
                        PyExc_RuntimeError,
                        "Wrong number of arguments in tuple."
                );
                return NULL;
        }

        sound = GetSound(sound_name);
        if (sound == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        sound_obj = PyObject_NEW(bld_py_sound_t, &soundTypeObject);
        if (sound_obj == NULL) {
                Py_INCREF(Py_None);
                return Py_None;
        }

        sound_obj->sound = sound;
        sound_obj->soundDev = GetSoundDevInstace();

        return (PyObject *)sound_obj;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10004C41
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10004D2F
*/

PyObject *bex_SetRootWidget(PyObject *self, PyObject *args) {
        long int widget;

        if (!PyArg_ParseTuple(args, "l", &widget))
                return NULL;

        return Py_BuildValue("i", SetRootWidget(INT_TO_PTR(widget, B_Widget)));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10004D79
*/

PyObject *bex_GetRootWidget(PyObject *self, PyObject *args) {
        long int rootWidget = 0;
        if (!PyArg_ParseTuple(args, ""))
                return NULL;
        rootWidget = PTR_TO_INT(GetRootWidget());
        return Py_BuildValue("l", rootWidget);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10004DBD
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10004E57
*/

PyObject *bex_SetAfterFrameFunc(PyObject *self, PyObject *args) {
        const char *name;
        PyObject *function = NULL;

        if (!PyArg_ParseTuple(args, "sO", &name, &function))
                return NULL;

        return Py_BuildValue("i", SetAfterFrameFunc(name, function));
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10004EB0
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10004F17
*/

PyObject *bex_GetnAfterFrameFuncs(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetnAfterFrameFuncs());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10004F54
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10004FBD
*/

PyObject *bex_RemoveAfterFrameFunc(PyObject *self, PyObject *args) {
        const char *name;

        if (!PyArg_ParseTuple(args, "s", &name))
                return NULL;

        return Py_BuildValue("i", RemoveAfterFrameFunc(name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005007
*/

PyObject *bex_SetMenuTgapFunc(PyObject *self, PyObject *args) {
        PyObject *tgapFunc = NULL;

        if (!PyArg_ParseTuple(args, "O", &tgapFunc))
                return NULL;

        return Py_BuildValue("i", SetMenuTgapFunc(tgapFunc));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005058
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100050B2
*/

PyObject *bex_SetCallCheck(PyObject *self, PyObject *args) {
        int check;

        if (!PyArg_ParseTuple(args, "i", &check))
                return NULL;

        return Py_BuildValue("i", SetCallCheck(check));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100050FC
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10005188
*/

PyObject *bex_ShowActionAreas(PyObject *self, PyObject *args) {
        int action_areas_bit_mask;

        if (!PyArg_ParseTuple(args, "i", &action_areas_bit_mask))
                return NULL;

        return Py_BuildValue("i", SetShowAreas(action_areas_bit_mask));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100051D2
*/

PyObject *bex_WriteText(PyObject *self, PyObject *args) {
        const char *text = NULL;
        double x, y;

        if (!PyArg_ParseTuple(args, "dds", &x, &y, &text))
                return NULL;

        return Py_BuildValue("i", WriteText(x, y, text));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000523B
*/

PyObject *bex_GetTextWH(PyObject *self, PyObject *args) {
        const char *text = NULL;
        double w, h;

        if (!PyArg_ParseTuple(args, "s", &text))
                return NULL;

        GetTextWH(text, &w, &h);

        return Py_BuildValue("dd", w, h);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000529D
*/

PyObject *bex_GetScreenRect(PyObject *self, PyObject *args) {
        double x_min, y_min, x_max, y_max;

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        GetScreenRect(&x_min, &y_min, &x_max, &y_max);

        return Py_BuildValue("dddd", x_min, y_min, x_max, y_max);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005308
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100053A0
*/

PyObject *bex_CloseDebugChannel(PyObject *self, PyObject *args) {
        const char *channel_name;

        if(!PyArg_ParseTuple(args, "s", &channel_name))
                return NULL;

        return Py_BuildValue("i", CloseDebugChannel(channel_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100053F1
*/

PyObject *bex_DumpMemoryLeaks(PyObject *self, PyObject *args) {
        const char *s;

        if (!PyArg_ParseTuple(args, "s", &s))
                return NULL;

        return Py_BuildValue("i", dump_memory_leaks(s));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005441
*/

PyObject *bex_OpenDebugChannel(PyObject *self, PyObject *args) {
        const char *channel_name;

        if(!PyArg_ParseTuple(args, "s", &channel_name))
                return NULL;

        return Py_BuildValue("i", OpenDebugChannel(channel_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005492
*/

PyObject *bex_SetAppMode(PyObject *self, PyObject *args) {
        const char *mode;

        if(!PyArg_ParseTuple(args, "s", &mode))
                return NULL;

        return Py_BuildValue("i", SetAppMode(mode));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100054E3
*/

PyObject *bex_GetAppMode(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("s", GetAppMode());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005529
*/

PyObject *bex_GetCommandLine(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("s", GetCommandLine());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000556F
*/

PyObject *bex_Quit(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", Quit());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100055AC
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10005624
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x1000567E
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100056E0
*/

PyObject *bex_CreateBipedData(PyObject *self, PyObject *args) {
        const char *biped_name, *kind;

        if (!PyArg_ParseTuple(args, "ss", &biped_name, &kind))
                return NULL;

        return Py_BuildValue("i", CreateBipedData(biped_name, kind));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005732
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10005828
*/

PyObject *bex_RemoveBipedAction(PyObject *self, PyObject *args) {
        const char *s_unknown1, *s_unknown2;

        if (!PyArg_ParseTuple(args, "ss", &s_unknown1, &s_unknown2))
                return NULL;

        return Py_BuildValue("i", RemoveBipedAction(s_unknown1, s_unknown2));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000587A
*/

PyObject *bex_AddAnmRStep(PyObject *self, PyObject *args) {
        const char *animation_name;
        double d_unknown;

        if (!PyArg_ParseTuple(args, "sd", &animation_name, &d_unknown))
                return NULL;

        return Py_BuildValue("i", AddRStepEvent(animation_name, d_unknown));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100058D0
*/

PyObject *bex_AnmTypeRSteps(PyObject *self, PyObject *args) {
        const char *s_unknown1, *s_unknown2;

        if (!PyArg_ParseTuple(args, "ss", &s_unknown1, &s_unknown2))
                return NULL;

        return Py_BuildValue("i", RStepEvents(s_unknown1, s_unknown2));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005922
*/

PyObject *bex_AnmTypeLSteps(PyObject *self, PyObject *args) {
        const char *s_unknown1, *s_unknown2;

        if (!PyArg_ParseTuple(args, "ss", &s_unknown1, &s_unknown2))
                return NULL;

        return Py_BuildValue("i", LStepEvents(s_unknown1, s_unknown2));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005974
*/

PyObject *bex_SetActionEventTable(PyObject *self, PyObject *args) {
        const char *race_name, *action_name, *table_name;

        if (!PyArg_ParseTuple(args, "sss", &race_name, &action_name, &table_name))
                return NULL;

        return Py_BuildValue(
                "i", SetActionEventTable(race_name, action_name, table_name)
        );
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100059CE
*/

PyObject *bex_SetEventTableFuncC(PyObject *self, PyObject *args) {
        const char *event_table_name, *event_type, *funcC;

        if (!PyArg_ParseTuple(args, "sss", &event_table_name, &event_type, &funcC))
                return NULL;

        return Py_BuildValue(
                "i", SetEventTableFuncC(event_table_name, event_type, funcC)
        );
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005A28
*/

PyObject *bex_SetEventTableFunc(PyObject *self, PyObject *args) {
        const char *event_table_name, *event_type;
        PyObject *func;

        if (!PyArg_ParseTuple(args, "ssO", &event_table_name, &event_type, &func))
                return NULL;

        return Py_BuildValue(
                "i", SetEventTableFunc(event_table_name, event_type, func)
        );
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005A82
*/

PyObject *bex_AddAnmLStep(PyObject *self, PyObject *args) {
        const char *animation_name;
        double d_unknown;

        if (!PyArg_ParseTuple(args, "sd", &animation_name, &d_unknown))
                return NULL;

        return Py_BuildValue("i", AddLStepEvent(animation_name, d_unknown));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005AD8
*/

PyObject *bex_AddAnmRRelease(PyObject *self, PyObject *args) {
        const char *animation_name;
        double d_unknown;

        if (!PyArg_ParseTuple(args, "sd", &animation_name, &d_unknown))
                return NULL;

        return Py_BuildValue("i", AddRReleaseEvent(animation_name, d_unknown));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005B2E
*/

PyObject *bex_AddAnmLRelease(PyObject *self, PyObject *args) {
        const char *animation_name;
        double d_unknown;

        if (!PyArg_ParseTuple(args, "sd", &animation_name, &d_unknown))
                return NULL;

        return Py_BuildValue("i", AddLReleaseEvent(animation_name, d_unknown));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005B84
*/

PyObject *bex_AddStopTests(PyObject *self, PyObject *args) {
        const char *animation_name;

        if (!PyArg_ParseTuple(args, "s", &animation_name))
                return NULL;

        AddStopTests(animation_name);

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005BC7
*/

PyObject *bex_AddFloorCTolerance(PyObject *self, PyObject *args) {
        const char *animation_name;
        double tolerance;

        if (!PyArg_ParseTuple(args, "sd", &animation_name, &tolerance))
                return NULL;

        AddFloorCTolerance(animation_name, tolerance);

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005C18
*/

PyObject *bex_SetSolidMask(PyObject *self, PyObject *args) {
        const char *kind;
        int mask;

        if(!PyArg_ParseTuple(args, "si", &kind, &mask))
                return NULL;

        return Py_BuildValue("i", SetSolidMask(kind, mask));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005C6A
*/

PyObject *bex_SetDrawObjectShadows(PyObject *self, PyObject *args) {
        int draw;

        if(!PyArg_ParseTuple(args, "i", &draw))
                return NULL;

        return Py_BuildValue("i", SetDrawObjectShadows(draw));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005CB4
*/

PyObject *bex_GetAutoEngageCombat(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetAutoEngageCombat());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005CF1
*/

PyObject *bex_SetAutoEngageCombat(PyObject *self, PyObject *args) {
        int auto_engage_combat;

        if(!PyArg_ParseTuple(args, "i", &auto_engage_combat))
                return NULL;

        return Py_BuildValue("i", SetAutoEngageCombat(auto_engage_combat));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005D3B
*/

PyObject *bex_GetAecGap(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("d", GetAecGap());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005D7E
*/

PyObject *bex_SetAecGap(PyObject *self, PyObject *args) {
        double aec_gap;

        if(!PyArg_ParseTuple(args, "d", &aec_gap))
                return NULL;

        return Py_BuildValue("i", SetAecGap(aec_gap));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005DCC
*/

PyObject *bex_GetDrawObjectShadows(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetDrawObjectShadows());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005E09
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10005E8D
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10005EE6
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10005F42
*/

PyObject *bex_SetCurrentMap(PyObject *self, PyObject *args) {
        const char *map;

        if(!PyArg_ParseTuple(args, "s", &map))
                return NULL;

        return Py_BuildValue("i", SetCurrentMap(map));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005F8C
*/

PyObject *bex_LoadWorld(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", LoadWorld(file_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10005FD6
*/

PyObject *bex_DoneLoadGame(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        DoneLoadGame();

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006012
*/

PyObject *bex_BeginLoadGame(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        BeginLoadGame();

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000604E
*/

PyObject *bex_GetWindowId(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetWindowId());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000608B
*/

PyObject *bex_GetProgramId(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", GetProgramId());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100060C8
*/

PyObject *bex_AddStepSound(PyObject *self, PyObject *args) {
        const char *name;
        bld_py_sound_t *sound;

        if(!PyArg_ParseTuple(args, "sO", &name, &sound))
                return NULL;

        return Py_BuildValue("i", AddStepSound(name, sound->sound));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000611D
*/

PyObject *bex_AddMaterialStepSound(PyObject *self, PyObject *args) {
        const char *table, *material, *step_sound;

        if(!PyArg_ParseTuple(args, "sss", &table, &material, &step_sound))
                return NULL;

        return Py_BuildValue("i", AddMaterialStepSound(table, material, step_sound));
}

/*
* Module:                 Bladex.dll
* Entry point:            0x10006177
*/

PyObject *bex_AddActionStepSound(PyObject *self, PyObject *args) {
        const char *table, *action, *step_sound_table;

        if(!PyArg_ParseTuple(args, "sss", &table, &action, &step_sound_table))
                return NULL;

        return Py_BuildValue(
                "i",
                AddActionStepSound(table, action, step_sound_table)
        );
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100061D1
*/

PyObject *bex_AddTextureMaterial(PyObject *self, PyObject *args) {
        const char *texture, *material;

        if (!PyArg_ParseTuple(args, "ss", &texture, &material))
                return NULL;

        return Py_BuildValue("i", AddTextureMaterial(texture, material));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006223
*/

PyObject *bex_GetMusicEventPriority(PyObject *self, PyObject *args) {
        int unknown;

        if (!PyArg_ParseTuple(args, "i", &unknown))
                return NULL;

        return Py_BuildValue("i", GetMusicEventPriority(unknown));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000626D
*/

PyObject *bex_GetMusicEvent(PyObject *self, PyObject *args) {
        const char *event_name;

        if (!PyArg_ParseTuple(args, "s", &event_name))
                return NULL;

        return Py_BuildValue("i", getMusicEvent(event_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100062B7
*/

PyObject *bex_ExeMusicEvent(PyObject *self, PyObject *args) {
        int unknown1, unknown2 = 0;

        if (!PyArg_ParseTuple(args, "i|i", &unknown1, &unknown2))
                return NULL;

        return Py_BuildValue("i", exeMusicEvent(unknown1, (unknown2 != 0) ));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006316
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100063B2
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x1000645D
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10006508
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100065B3
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10006607
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10006668
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100066C9
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x1000672A
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x1000678B
*/

PyObject *bex_TakeSnapShot(PyObject *self, PyObject *args) {

        TakeSnapShot();

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100067A6
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100067FA
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x1000686C
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100068DE
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x1000692E
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x100069B9
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10006A03
*/

PyObject *bex_SetRunString(PyObject *self, PyObject *args) {
        const char *variable;

        if(!PyArg_ParseTuple(args, "s", &variable))
                return NULL;

        SetRunString(variable);

        Py_INCREF(Py_None);
        return Py_None;
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006A4D
*/

PyObject *bex_SetStringValue(PyObject *self, PyObject *args) {
        const char *variable, *value;

        if(!PyArg_ParseTuple(args, "ss", &variable, &value))
                return NULL;

        return Py_BuildValue("i", SetStringValue(variable, value));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006A9F
*/

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


/*
* Module:                 Bladex.dll
* Entry point:            0x10006B08
*/

PyObject *bex_DeleteStringValue(PyObject *self, PyObject *args) {
        const char *variable;

        if(!PyArg_ParseTuple(args, "s", &variable))
                return NULL;

        return Py_BuildValue("i", DeleteStringValue(variable));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006B52
*/

PyObject *bex_SaveEntitiesData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", SaveEntitiesData(file_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006B9C
*/

PyObject *bex_LoadEntitiesData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", LoadEntitiesData(file_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006BE6
*/

PyObject *bex_SaveParticleSystemsData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", SaveParticleSystemsData(file_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006C30
*/

PyObject *bex_LoadParticleSystemsData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", LoadParticleSystemsData(file_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006C7A
*/

PyObject *bex_SaveCombustionData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", SaveCombustionData(file_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006CC4
*/

PyObject *bex_LoadCombustionData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", LoadCombustionData(file_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006D0E
*/

PyObject *bex_ReassignCombustionData(PyObject *self, PyObject *args) {

        ReassignCombustionData();

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006D29
*/

PyObject *bex_SaveAnmRaceData(PyObject *self, PyObject *args) {
        const char *file_name, *race;

        if(!PyArg_ParseTuple(args, "ss", &file_name, &race))
                return NULL;

        return Py_BuildValue("i", SaveAnmRaceData(file_name, race));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006D7B
*/

PyObject *bex_LoadAnmRaceData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", LoadAnmRaceData(file_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006DC5
*/

PyObject *bex_SaveAnmSoundData(PyObject *self, PyObject *args) {
        const char *file_name, *race;

        if(!PyArg_ParseTuple(args, "ss", &file_name, &race))
                return NULL;

        return Py_BuildValue("i", SaveAnmSoundData(file_name, race));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006E17
*/

PyObject *bex_LoadAnmSoundData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i",  LoadAnmSoundData(file_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006E61
*/

PyObject *bex_GetSaveInfo(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return GetSaveInfo();
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006E86
*/

PyObject *bex_SetSaveInfo(PyObject *self, PyObject *args) {
        PyObject *info;

        if(!PyArg_ParseTuple(args, "O", &info))
                return NULL;

        return Py_BuildValue("i", SetSaveInfo(info));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006ED0
*/

PyObject *bex_HeapCheckSetMark(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", heap_check_set_mark());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006F0C
*/

PyObject *bex_PerformHeapCheck(PyObject *self, PyObject *args) {

        if (!PyArg_ParseTuple(args, ""))
                return NULL;

        perform_heap_check();

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006F40
*/

PyObject *bex_HeapCheckAllAllocations(PyObject *self, PyObject *args) {
        int i;

        if (!PyArg_ParseTuple(args, "i", &i))
                return NULL;

        heap_check_all_allocations(i);

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006F82
*/

PyObject *bex_HeapCheckDelayFree(PyObject *self, PyObject *args) {
        int i;

        if (!PyArg_ParseTuple(args, "i", &i))
                return NULL;

        heap_check_delay_free(i);

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10006FC4
*/

PyObject *bex_HeapCheckSystemMemory(PyObject *self, PyObject *args) {
        int i;

        if (!PyArg_ParseTuple(args, "i", &i))
                return NULL;

        heap_check_system_memory(i);

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10007006
*/

PyObject *bex_HeapCheckLeaks(PyObject *self, PyObject *args) {
        int i;

        if (!PyArg_ParseTuple(args, "i", &i))
                return NULL;

        heap_check_leaks(i);

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10007048
*/

PyObject *bex_OpenProfileSection(PyObject *self, PyObject *args) {
        int section;
        const char *comment = "";

        if(!PyArg_ParseTuple(args, "i|s", &section, &comment))
                return NULL;

        return Py_BuildValue("i", OpenProfileSection(section, comment));
}

/*
* Module:                 Bladex.dll
* Entry point:            0x100070A1
*/

PyObject *bex_CloseProfileSection(PyObject *self, PyObject *args) {
        int section;

        if(!PyArg_ParseTuple(args, "i", &section))
                return NULL;

        return Py_BuildValue("i", CloseProfileSection(section));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100070EB
*/

PyObject *bex_StartProfile(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", StartProfile());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10007128
*/

PyObject *bex_EnableProfiler(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", EnableProfiler());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10007165
*/

PyObject *bex_DisableProfiler(PyObject *self, PyObject *args) {

        if(!PyArg_ParseTuple(args, ""))
                return NULL;

        return Py_BuildValue("i", DisableProfiler());
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100071A2
*/

PyObject *bex_SaveProfileData(PyObject *self, PyObject *args) {
        const char *file_name;

        if(!PyArg_ParseTuple(args, "s", &file_name))
                return NULL;

        return Py_BuildValue("i", SaveProfileData(file_name));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100071EC
*/

PyObject *bex_SetInputMode(PyObject *self, PyObject *args) {
        const char *device, *mode;

        if(!PyArg_ParseTuple(args, "ss", &device, &mode))
                return NULL;

        return Py_BuildValue("i", SetInputMode(device, mode));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000723E
*/

PyObject *bex_GetInputMode(PyObject *self, PyObject *args) {
        const char *device;

        if(!PyArg_ParseTuple(args, "s", &device))
                return NULL;

        return Py_BuildValue("s", GetInputMode(device));
}


/*
* Module:                 Bladex.dll
* Entry point:            0x10007288
*/

PyObject *bex_SaveScreenShot(PyObject *self, PyObject *args) {
        const char *file_name;
        int width, height;

        if(!PyArg_ParseTuple(args, "sii", &file_name, &width, &height))
                return NULL;

        SaveScreeShoot(file_name, width, height);

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x100072DD
*/

PyObject *bex_CleanArea(PyObject *self, PyObject *args) {
        float x, y, z, distance;

        if(!PyArg_ParseTuple(args, "ffff", &x, &y, &z, &distance))
                return NULL;

        CleanArea(x, y, z, distance);

        return Py_BuildValue("i", 1);
}


/*
* Module:                 Bladex.dll
* Entry point:            0x1000737B
*/

INIT_PY_MODULE_FUNC initBladex()
{
        int i;

        for( i = 0; i < sizeof(init_funcs)/sizeof(init_funcs[0]); i++)
                if (init_funcs[i])
                        init_funcs[i]();

        Py_InitModule("Bladex", methods);
}


