
#include <bld_system.h>
#include <bld_python.h>
#define BUILD_LIB
#include <blade_ext.h>

extern HMODULE blade;


int PlayCDTrack(int ntrack)
{
        int (*bld_proc)(int ntrack);
        bld_proc = (int (*)(int ntrack))GetProcAddress(blade, "PlayCDTrack");
        return bld_proc(ntrack);
}


int nCDTracks(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "nCDTracks");
        return bld_proc();
}


int CDLenght(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "CDLenght");
        return bld_proc();
}


int CDTrackLenght(int ntrack)
{
        int (*bld_proc)(int ntrack);
        bld_proc = (int (*)(int ntrack))GetProcAddress(blade, "CDTrackLenght");
        return bld_proc(ntrack);
}


int CDPresent(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "CDPresent");
        return bld_proc();
}


int CDStop(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "CDStop");
        return bld_proc();
}


int CDPause(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "CDPause");
        return bld_proc();
}


int CDSetCallBack(PyObject *func)
{
        int (*bld_proc)(PyObject *func);
        bld_proc = (int (*)(PyObject *func))GetProcAddress(blade, "CDSetCallBack");
        return bld_proc(func);
}


int SetAppMode(const char *mode)
{
        int (*bld_proc)(const char *mode);
        bld_proc = (int (*)(const char *mode))GetProcAddress(blade, "SetAppMode");
        return bld_proc(mode);
}


const char *GetAppMode(void)
{
        const char *(*bld_proc)(void);
        bld_proc = (const char *(*)(void))GetProcAddress(blade, "GetAppMode");
        return bld_proc();
}


void BeginLoadGame(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "BeginLoadGame");
        bld_proc();
}


void DoneLoadGame(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "DoneLoadGame");
        bld_proc();
}


int SetSaveInfo(PyObject *info)
{
        int (*bld_proc)(PyObject *info);
        bld_proc = (int (*)(PyObject *info))GetProcAddress(blade, "SetSaveInfo");
        return bld_proc(info);
}


PyObject *GetSaveInfo(void)
{
        PyObject *(*bld_proc)(void);
        bld_proc = (PyObject *(*)(void))GetProcAddress(blade, "GetSaveInfo");
        return bld_proc();
}


int SaveEntitiesData(const char *filename)
{
        int (*bld_proc)(const char *filename);
        bld_proc = (int (*)(const char *filename))GetProcAddress(blade, "SaveEntitiesData");
        return bld_proc(filename);
}


int LoadEntitiesData(const char *filename)
{
        int (*bld_proc)(const char *filename);
        bld_proc = (int (*)(const char *filename))GetProcAddress(blade, "LoadEntitiesData");
        return bld_proc(filename);
}


int SaveParticleSystemsData(const char *filename)
{
        int (*bld_proc)(const char *filename);
        bld_proc = (int (*)(const char *filename))GetProcAddress(blade, "SaveParticleSystemsData");
        return bld_proc(filename);
}


int LoadParticleSystemsData(const char *filename)
{
        int (*bld_proc)(const char *filename);
        bld_proc = (int (*)(const char *filename))GetProcAddress(blade, "LoadParticleSystemsData");
        return bld_proc(filename);
}


int SaveCombustionData(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "SaveCombustionData");
        return bld_proc(file_name);
}


int LoadCombustionData(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "LoadCombustionData");
        return bld_proc(file_name);
}


int ReassignCombustionData(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "ReassignCombustionData");
        return bld_proc();
}


int SaveAnmRaceData(const char *file_name, const char *race)
{
        int (*bld_proc)(const char *file_name, const char *race);
        bld_proc = (int (*)(const char *file_name, const char *race))GetProcAddress(blade, "SaveAnmRaceData");
        return bld_proc(file_name, race);
}


int LoadAnmRaceData(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "LoadAnmRaceData");
        return bld_proc(file_name);
}


int GetnRaces(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetnRaces");
        return bld_proc();
}


const char *GetRaceName(int index)
{
        const char *(*bld_proc)(int index);
        bld_proc = (const char *(*)(int index))GetProcAddress(blade, "GetRaceName");
        return bld_proc(index);
}


int SaveAnmSoundData(const char *file_name, const char *race)
{
        int (*bld_proc)(const char *file_name, const char *race);
        bld_proc = (int (*)(const char *file_name, const char *race))GetProcAddress(blade, "SaveAnmSoundData");
        return bld_proc(file_name, race);
}


int LoadAnmSoundData(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "LoadAnmSoundData");
        return bld_proc(file_name);
}


const char *GetCommandLine(void)
{
        const char *(*bld_proc)(void);
        bld_proc = (const char *(*)(void))GetProcAddress(blade, "GetCommandLine");
        return bld_proc();
}


const char *GetCurrentMap(void)
{
        const char *(*bld_proc)(void);
        bld_proc = (const char *(*)(void))GetProcAddress(blade, "GetCurrentMap");
        return bld_proc();
}


int SetCurrentMap(const char *map)
{
        int (*bld_proc)(const char *map);
        bld_proc = (int (*)(const char *map))GetProcAddress(blade, "SetCurrentMap");
        return bld_proc(map);
}


double GetTime(void)
{
        double (*bld_proc)(void);
        bld_proc = (double (*)(void))GetProcAddress(blade, "GetTime");
        return bld_proc();
}


void StopTime(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "StopTime");
        bld_proc();
}


void RestartTime(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "RestartTime");
        bld_proc();
}


void SetTimeSpeed(double speed)
{
        void (*bld_proc)(double speed);
        bld_proc = (void (*)(double speed))GetProcAddress(blade, "SetTimeSpeed");
        bld_proc(speed);
}


double GetTimeSpeed(void)
{
        double (*bld_proc)(void);
        bld_proc = (double (*)(void))GetProcAddress(blade, "GetTimeSpeed");
        return bld_proc();
}


int AddInputAction(const char *action_name, int npi)
{
        int (*bld_proc)(const char *action_name, int npi);
        bld_proc = (int (*)(const char *action_name, int npi))GetProcAddress(blade, "AddInputAction");
        return bld_proc(action_name, npi);
}


int RemoveInputAction(const char *action_name)
{
        int (*bld_proc)(const char *action_name);
        bld_proc = (int (*)(const char *action_name))GetProcAddress(blade, "RemoveInputAction");
        return bld_proc(action_name);
}


int AssocKey(
        const char *action, const char *input_device, const char *key,
        int press
)
{
        int (*bld_proc)(
        const char *action, const char *input_device, const char *key,
        int press
);
        bld_proc = (int (*)(
        const char *action, const char *input_device, const char *key,
        int press
))GetProcAddress(blade, "AssocKey");
        return bld_proc(action, input_device, key, press);
}


int Bind(const char *action_name, PyObject *proc)
{
        int (*bld_proc)(const char *action_name, PyObject *proc);
        bld_proc = (int (*)(const char *action_name, PyObject *proc))GetProcAddress(blade, "Bind");
        return bld_proc(action_name, proc);
}


int UnBind(const char *action_name, PyObject *proc)
{
        int (*bld_proc)(const char *action_name, PyObject *proc);
        bld_proc = (int (*)(const char *action_name, PyObject *proc))GetProcAddress(blade, "UnBind");
        return bld_proc(action_name, proc);
}


int Bind2(
        const char *action_name1, const char *action_name2,
        const char *new_action, int unknown
)
{
        int (*bld_proc)(
        const char *action_name1, const char *action_name2,
        const char *new_action, int unknown
);
        bld_proc = (int (*)(
        const char *action_name1, const char *action_name2,
        const char *new_action, int unknown
))GetProcAddress(blade, "Bind2");
        return bld_proc(action_name1, action_name2, new_action, unknown);
}


double GetTimeActionHeld(const char *action_name)
{
        double (*bld_proc)(const char *action_name);
        bld_proc = (double (*)(const char *action_name))GetProcAddress(blade, "GetTimeActionHeld");
        return bld_proc(action_name);
}


int UnBindPred(const char *action_name, const char *predproc)
{
        int (*bld_proc)(const char *action_name, const char *predproc);
        bld_proc = (int (*)(const char *action_name, const char *predproc))GetProcAddress(blade, "UnBindPred");
        return bld_proc(action_name, predproc);
}


void UnBindAll(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "UnBindAll");
        bld_proc();
}


const char *Input(const char *text)
{
        const char *(*bld_proc)(const char *text);
        bld_proc = (const char *(*)(const char *text))GetProcAddress(blade, "Input");
        return bld_proc(text);
}


void MarkLevelToLoad(const char *dir_name)
{
        void (*bld_proc)(const char *dir_name);
        bld_proc = (void (*)(const char *dir_name))GetProcAddress(blade, "MarkLevelToLoad");
        bld_proc(dir_name);
}


void ReadLevel(const char *file_name)
{
        void (*bld_proc)(const char *file_name);
        bld_proc = (void (*)(const char *file_name))GetProcAddress(blade, "ReadLevel");
        bld_proc(file_name);
}


void ReadBitMap(const char *file_name, const char *internal_name)
{
        void (*bld_proc)(const char *file_name, const char *internal_name);
        bld_proc = (void (*)(const char *file_name, const char *internal_name))GetProcAddress(blade, "ReadBitMap");
        bld_proc(file_name, internal_name);
}


void ReadAlphaBitMap(const char *file_name, const char *internal_name)
{
        void (*bld_proc)(const char *file_name, const char *internal_name);
        bld_proc = (void (*)(const char *file_name, const char *internal_name))GetProcAddress(blade, "ReadAlphaBitMap");
        bld_proc(file_name, internal_name);
}


void CloseLevel(const char *statement1, const char *statement2)
{
        void (*bld_proc)(const char *statement1, const char *statement2);
        bld_proc = (void (*)(const char *statement1, const char *statement2))GetProcAddress(blade, "CloseLevel");
        bld_proc(statement1, statement2);
}

// TODO fix prototype
void StartRecordingDemo()
{
        assert("StartRecordingDemo" == NULL);
}

// TODO fix prototype
void EndRecordingDemo()
{
        assert("EndRecordingDemo" == NULL);
}

// TODO fix prototype
void PlayDemo()
{
        assert("PlayDemo" == NULL);
}


int DeactivateInput(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "DeactivateInput");
        return bld_proc();
}


int ActivateInput(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "ActivateInput");
        return bld_proc();
}


int OutSound(int soundId, double x, double y, double z, int unknown)
{
        int (*bld_proc)(int soundId, double x, double y, double z, int unknown);
        bld_proc = (int (*)(int soundId, double x, double y, double z, int unknown))GetProcAddress(blade, "OutSound");
        return bld_proc(soundId, x, y, z, unknown);
}


int SetDefaultMass(const char *entity_kind, double mass)
{
        int (*bld_proc)(const char *entity_kind, double mass);
        bld_proc = (int (*)(const char *entity_kind, double mass))GetProcAddress(blade, "SetDefaultMass");
        return bld_proc(entity_kind, mass);
}


int SetDefaultMaterial(const char *entity_kind, const char *material)
{
        int (*bld_proc)(const char *entity_kind, const char *material);
        bld_proc = (int (*)(const char *entity_kind, const char *material))GetProcAddress(blade, "SetDefaultMaterial");
        return bld_proc(entity_kind, material);
}


void SetSun(int exists, double x, double y, double z)
{
        void (*bld_proc)(int exists, double x, double y, double z);
        bld_proc = (void (*)(int exists, double x, double y, double z))GetProcAddress(blade, "SetSun");
        bld_proc(exists, x, y, z);
}


int InsideAA(int AA, double x, double y, double z)
{
        int (*bld_proc)(int AA, double x, double y, double z);
        bld_proc = (int (*)(int AA, double x, double y, double z))GetProcAddress(blade, "InsideAA");
        return bld_proc(AA, x, y, z);
}


int SetDrawObjectShadows(int draw)
{
        int (*bld_proc)(int draw);
        bld_proc = (int (*)(int draw))GetProcAddress(blade, "SetDrawObjectShadows");
        return bld_proc(draw);
}


int GetDrawObjectShadows(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetDrawObjectShadows");
        return bld_proc();
}


int SetAutoEngageCombat(int auto_engage_combat)
{
        int (*bld_proc)(int auto_engage_combat);
        bld_proc = (int (*)(int auto_engage_combat))GetProcAddress(blade, "SetAutoEngageCombat");
        return bld_proc(auto_engage_combat);
}


int GetAutoEngageCombat(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetAutoEngageCombat");
        return bld_proc();
}


int SetAecGap(double aec_gap)
{
        int (*bld_proc)(double aec_gap);
        bld_proc = (int (*)(double aec_gap))GetProcAddress(blade, "SetAecGap");
        return bld_proc(aec_gap);
}


double GetAecGap(void)
{
        double (*bld_proc)(void);
        bld_proc = (double (*)(void))GetProcAddress(blade, "GetAecGap");
        return bld_proc();
}


int SetBloodLevel(int blood_level)
{
        int (*bld_proc)(int blood_level);
        bld_proc = (int (*)(int blood_level))GetProcAddress(blade, "SetBloodLevel");
        return bld_proc(blood_level);
}


int GetBloodLevel(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetBloodLevel");
        return bld_proc();
}


int SetMutilationLevel(int mutilation_level)
{
        int (*bld_proc)(int mutilation_level);
        bld_proc = (int (*)(int mutilation_level))GetProcAddress(blade, "SetMutilationLevel");
        return bld_proc(mutilation_level);
}


int GetMutilationLevel(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetMutilationLevel");
        return bld_proc();
}


void AnmAddEvent(const char *anm_name, const char *event_name, double event_frame)
{
        void (*bld_proc)(const char *anm_name, const char *event_name, double event_frame);
        bld_proc = (void (*)(const char *anm_name, const char *event_name, double event_frame))GetProcAddress(blade, "AnmAddEvent");
        bld_proc(anm_name, event_name, event_frame);
}


void AnmDelEvent(const char *anm_name, const char *event_name)
{
        void (*bld_proc)(const char *anm_name, const char *event_name);
        bld_proc = (void (*)(const char *anm_name, const char *event_name))GetProcAddress(blade, "AnmDelEvent");
        bld_proc(anm_name, event_name);
}


void AnmClearEvents(const char *anm_name)
{
        void (*bld_proc)(const char *anm_name);
        bld_proc = (void (*)(const char *anm_name))GetProcAddress(blade, "AnmClearEvents");
        bld_proc(anm_name);
}


double AnmGetEventFrame(const char *anm_name, const char *event_name)
{
        double (*bld_proc)(const char *anm_name, const char *event_name);
        bld_proc = (double (*)(const char *anm_name, const char *event_name))GetProcAddress(blade, "AnmGetEventFrame");
        return bld_proc(anm_name, event_name);
}


int AddParticleGType(
        const char *new_type, const char *parent_type, int operation_type,
        int duration
)
{
        int (*bld_proc)(
        const char *new_type, const char *parent_type, int operation_type,
        int duration
);
        bld_proc = (int (*)(
        const char *new_type, const char *parent_type, int operation_type,
        int duration
))GetProcAddress(blade, "AddParticleGType");
        return bld_proc(new_type, parent_type, operation_type, duration);
}


int SetParticleGVal(
        const char *type, int i, int r, int g, int b, int alpha, double size
)
{
        int (*bld_proc)(
        const char *type, int i, int r, int g, int b, int alpha, double size
);
        bld_proc = (int (*)(
        const char *type, int i, int r, int g, int b, int alpha, double size
))GetProcAddress(blade, "SetParticleGVal");
        return bld_proc(type, i, r, g, b, alpha, size);
}


int GetnParticleGType(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetnParticleGType");
        return bld_proc();
}


int GetParticleGType(
        int index, const char **type, const char **parent_type,
        int *operation_type, int *duration
)
{
        int (*bld_proc)(
        int index, const char **type, const char **parent_type,
        int *operation_type, int *duration
);
        bld_proc = (int (*)(
        int index, const char **type, const char **parent_type,
        int *operation_type, int *duration
))GetProcAddress(blade, "GetParticleGType");
        return bld_proc(index, type, parent_type, operation_type, duration);
}


int GetParticleGVal(
        const char *type, int index, int *r, int *g, int *b, int *alpha,
        double *size
)
{
        int (*bld_proc)(
        const char *type, int index, int *r, int *g, int *b, int *alpha,
        double *size
);
        bld_proc = (int (*)(
        const char *type, int index, int *r, int *g, int *b, int *alpha,
        double *size
))GetProcAddress(blade, "GetParticleGVal");
        return bld_proc(type, index, r, g, b, alpha, size);
}


void SetTurnSpeed(const char *race_name, double new_speed)
{
        void (*bld_proc)(const char *race_name, double new_speed);
        bld_proc = (void (*)(const char *race_name, double new_speed))GetProcAddress(blade, "SetTurnSpeed");
        bld_proc(race_name, new_speed);
}


int SetAnimationFactor(const char *mov, double new_speed_factor)
{
        int (*bld_proc)(const char *mov, double new_speed_factor);
        bld_proc = (int (*)(const char *mov, double new_speed_factor))GetProcAddress(blade, "SetAnimationFactor");
        return bld_proc(mov, new_speed_factor);
}


int SetAutoGenTexture(const char *textureName, int textureEffect)
{
        int (*bld_proc)(const char *textureName, int textureEffect);
        bld_proc = (int (*)(const char *textureName, int textureEffect))GetProcAddress(blade, "SetAutoGenTexture");
        return bld_proc(textureName, textureEffect);
}


const char *GenerateEntityName(void)
{
        const char *(*bld_proc)(void);
        bld_proc = (const char *(*)(void))GetProcAddress(blade, "GenerateEntityName");
        return bld_proc();
}


int AddWatchAnim(const char *anim)
{
        int (*bld_proc)(const char *anim);
        bld_proc = (int (*)(const char *anim))GetProcAddress(blade, "AddWatchAnim");
        return bld_proc(anim);
}


int AddAnimFlags(
        const char *anim, int wuea, int mdf_y, int solf, int copy_rot,
        int bng_mov, int head_f
)
{
        int (*bld_proc)(
        const char *anim, int wuea, int mdf_y, int solf, int copy_rot,
        int bng_mov, int head_f
);
        bld_proc = (int (*)(
        const char *anim, int wuea, int mdf_y, int solf, int copy_rot,
        int bng_mov, int head_f
))GetProcAddress(blade, "AddAnimFlags");
        return bld_proc(anim, wuea, mdf_y, solf, copy_rot, bng_mov, head_f);
}


int SetActionCameraMovement(
        const char *action_name, double angle, double start_pos, double end_pos
)
{
        int (*bld_proc)(
        const char *action_name, double angle, double start_pos, double end_pos
);
        bld_proc = (int (*)(
        const char *action_name, double angle, double start_pos, double end_pos
))GetProcAddress(blade, "SetActionCameraMovement");
        return bld_proc(action_name, angle, start_pos, end_pos);
}


int SetRootWidget(long int widget)
{
        int (*bld_proc)(long int widget);
        bld_proc = (int (*)(long int widget))GetProcAddress(blade, "SetRootWidget");
        return bld_proc(widget);
}


long int GetRootWidget(void)
{
        long int (*bld_proc)(void);
        bld_proc = (long int (*)(void))GetProcAddress(blade, "GetRootWidget");
        return bld_proc();
}


int AddCombustionDataFor(
        const char *object_kind, const char *fire_kind, double upper_treshol,
        double lower_treshold, double flame_height, double flame_size,
        double speed, double livetime
)
{
        int (*bld_proc)(
        const char *object_kind, const char *fire_kind, double upper_treshol,
        double lower_treshold, double flame_height, double flame_size,
        double speed, double livetime
);
        bld_proc = (int (*)(
        const char *object_kind, const char *fire_kind, double upper_treshol,
        double lower_treshold, double flame_height, double flame_size,
        double speed, double livetime
))GetProcAddress(blade, "AddCombustionDataFor");
        return bld_proc(object_kind, fire_kind, upper_treshol, lower_treshold, flame_height, flame_size, speed, livetime);
}

// TODO fix prototype
void RM_FreeResource()
{
        assert("RM_FreeResource" == NULL);
}

// TODO fix prototype
void RM_GetResource()
{
        assert("RM_GetResource" == NULL);
}

// TODO fix prototype
void UpdateAGTexture()
{
        assert("UpdateAGTexture" == NULL);
}


int SetAfterFrameFunc(const char *name, PyObject *function)
{
        int (*bld_proc)(const char *name, PyObject *function);
        bld_proc = (int (*)(const char *name, PyObject *function))GetProcAddress(blade, "SetAfterFrameFunc");
        return bld_proc(name, function);
}


int RemoveAfterFrameFunc(const char *name)
{
        int (*bld_proc)(const char *name);
        bld_proc = (int (*)(const char *name))GetProcAddress(blade, "RemoveAfterFrameFunc");
        return bld_proc(name);
}


PyObject *GetAfterFrameFunc(const char *name)
{
        PyObject *(*bld_proc)(const char *name);
        bld_proc = (PyObject *(*)(const char *name))GetProcAddress(blade, "GetAfterFrameFunc");
        return bld_proc(name);
}


const char *GetAfterFrameFuncName(int index)
{
        const char *(*bld_proc)(int index);
        bld_proc = (const char *(*)(int index))GetProcAddress(blade, "GetAfterFrameFuncName");
        return bld_proc(index);
}


int GetnAfterFrameFuncs(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetnAfterFrameFuncs");
        return bld_proc();
}


int SetMenuTgapFunc(PyObject *func)
{
        int (*bld_proc)(PyObject *func);
        bld_proc = (int (*)(PyObject *func))GetProcAddress(blade, "SetMenuTgapFunc");
        return bld_proc(func);
}


PyObject *GetMenuTgapFunc(void)
{
        PyObject *(*bld_proc)(void);
        bld_proc = (PyObject *(*)(void))GetProcAddress(blade, "GetMenuTgapFunc");
        return bld_proc();
}


int SetCallCheck(int check)
{
        int (*bld_proc)(int check);
        bld_proc = (int (*)(int check))GetProcAddress(blade, "SetCallCheck");
        return bld_proc(check);
}


int OpenDebugChannel(const char *channel_name)
{
        int (*bld_proc)(const char *channel_name);
        bld_proc = (int (*)(const char *channel_name))GetProcAddress(blade, "OpenDebugChannel");
        return bld_proc(channel_name);
}


int CloseDebugChannel(const char *channel_name)
{
        int (*bld_proc)(const char *channel_name);
        bld_proc = (int (*)(const char *channel_name))GetProcAddress(blade, "CloseDebugChannel");
        return bld_proc(channel_name);
}


int SetShowAreas(int action_areas_bit_mask)
{
        int (*bld_proc)(int action_areas_bit_mask);
        bld_proc = (int (*)(int action_areas_bit_mask))GetProcAddress(blade, "SetShowAreas");
        return bld_proc(action_areas_bit_mask);
}


int WriteText(double x, double y, const char *text)
{
        int (*bld_proc)(double x, double y, const char *text);
        bld_proc = (int (*)(double x, double y, const char *text))GetProcAddress(blade, "WriteText");
        return bld_proc(x, y, text);
}


void GetTextWH(const char *text, double *w, double *h)
{
        void (*bld_proc)(const char *text, double *w, double *h);
        bld_proc = (void (*)(const char *text, double *w, double *h))GetProcAddress(blade, "GetTextWH");
        bld_proc(text, w, h);
}


void GetScreenRect(
        double *x_min, double *y_min, double *x_max, double *y_max
)
{
        void (*bld_proc)(
        double *x_min, double *y_min, double *x_max, double *y_max
);
        bld_proc = (void (*)(
        double *x_min, double *y_min, double *x_max, double *y_max
))GetProcAddress(blade, "GetScreenRect");
        bld_proc(x_min, y_min, x_max, y_max);
}


void GetScreenXY(
        double map_x, double map_y, double map_z, double *screen_x,
        double *screen_y
)
{
        void (*bld_proc)(
        double map_x, double map_y, double map_z, double *screen_x,
        double *screen_y
);
        bld_proc = (void (*)(
        double map_x, double map_y, double map_z, double *screen_x,
        double *screen_y
))GetProcAddress(blade, "GetScreenXY");
        bld_proc(map_x, map_y, map_z, screen_x, screen_y);
}


int DrawBOD(
        const char *BODName, int x, int y, int w, int h, double scale,
        int i_unknown
)
{
        int (*bld_proc)(
        const char *BODName, int x, int y, int w, int h, double scale,
        int i_unknown
);
        bld_proc = (int (*)(
        const char *BODName, int x, int y, int w, int h, double scale,
        int i_unknown
))GetProcAddress(blade, "DrawBOD");
        return bld_proc(BODName, x, y, w, h, scale, i_unknown);
}


int CreateTriggerSector(
	const char *trigger_sector_name, const char *group_name,
	double floor_height, double roof_height, int num_points,
	point_2d_t *points
)
{
        int (*bld_proc)(
	const char *trigger_sector_name, const char *group_name,
	double floor_height, double roof_height, int num_points,
	point_2d_t *points
);
        bld_proc = (int (*)(
	const char *trigger_sector_name, const char *group_name,
	double floor_height, double roof_height, int num_points,
	point_2d_t *points
))GetProcAddress(blade, "CreateTriggerSector");
        return bld_proc(trigger_sector_name, group_name, floor_height, roof_height, num_points, points);
}


int SetTriggerSectorFunc(
        const char *trigger_sector_name, const char *func_type, PyObject *func
)
{
        int (*bld_proc)(
        const char *trigger_sector_name, const char *func_type, PyObject *func
);
        bld_proc = (int (*)(
        const char *trigger_sector_name, const char *func_type, PyObject *func
))GetProcAddress(blade, "SetTriggerSectorFunc");
        return bld_proc(trigger_sector_name, func_type, func);
}


PyObject *GetTriggerSectorFunc(
        const char *trigger_sector_name, const char *func_type
)
{
        PyObject *(*bld_proc)(
        const char *trigger_sector_name, const char *func_type
);
        bld_proc = (PyObject *(*)(
        const char *trigger_sector_name, const char *func_type
))GetProcAddress(blade, "GetTriggerSectorFunc");
        return bld_proc(trigger_sector_name, func_type);
}


int GetTriggerSectorFloorHeight(const char *trigger_sector_name)
{
        int (*bld_proc)(const char *trigger_sector_name);
        bld_proc = (int (*)(const char *trigger_sector_name))GetProcAddress(blade, "GetTriggerSectorFloorHeight");
        return bld_proc(trigger_sector_name);
}


int GetTriggerSectorRoofHeight(const char *trigger_sector_name)
{
        int (*bld_proc)(const char *trigger_sector_name);
        bld_proc = (int (*)(const char *trigger_sector_name))GetProcAddress(blade, "GetTriggerSectorRoofHeight");
        return bld_proc(trigger_sector_name);
}


const char *GetTriggerSectorGroup(const char *trigger_sector_name)
{
        const char *(*bld_proc)(const char *trigger_sector_name);
        bld_proc = (const char *(*)(const char *trigger_sector_name))GetProcAddress(blade, "GetTriggerSectorGroup");
        return bld_proc(trigger_sector_name);
}


double *GetTriggerSectorPoints(const char *trigger_sector_name)
{
        double *(*bld_proc)(const char *trigger_sector_name);
        bld_proc = (double *(*)(const char *trigger_sector_name))GetProcAddress(blade, "GetTriggerSectorPoints");
        return bld_proc(trigger_sector_name);
}


int SetTriggerSectorData(
        const char *trigger_sector_name, PyObject *data
)
{
        int (*bld_proc)(
        const char *trigger_sector_name, PyObject *data
);
        bld_proc = (int (*)(
        const char *trigger_sector_name, PyObject *data
))GetProcAddress(blade, "SetTriggerSectorData");
        return bld_proc(trigger_sector_name, data);
}


PyObject *GetTriggerSectorData(const char *trigger_sector_name)
{
        PyObject *(*bld_proc)(const char *trigger_sector_name);
        bld_proc = (PyObject *(*)(const char *trigger_sector_name))GetProcAddress(blade, "GetTriggerSectorData");
        return bld_proc(trigger_sector_name);
}


int nTriggerSectors(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "nTriggerSectors");
        return bld_proc();
}


const char *GetTriggerSectorName(int index)
{
        const char *(*bld_proc)(int index);
        bld_proc = (const char *(*)(int index))GetProcAddress(blade, "GetTriggerSectorName");
        return bld_proc(index);
}


int GetModelPos(const char *person, double *x, double *y, double *z)
{
        int (*bld_proc)(const char *person, double *x, double *y, double *z);
        bld_proc = (int (*)(const char *person, double *x, double *y, double *z))GetProcAddress(blade, "GetModelPos");
        return bld_proc(person, x, y, z);
}


int GetWindowId(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetWindowId");
        return bld_proc();
}


int GetProgramId(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetProgramId");
        return bld_proc();
}


void TakeSnapShot(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "TakeSnapShot");
        bld_proc();
}


int nSectors(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "nSectors");
        return bld_proc();
}


void SetRunString(const char *variable)
{
        void (*bld_proc)(const char *variable);
        bld_proc = (void (*)(const char *variable))GetProcAddress(blade, "SetRunString");
        bld_proc(variable);
}


int SetStringValue(const char *variable, const char *value)
{
        int (*bld_proc)(const char *variable, const char *value);
        bld_proc = (int (*)(const char *variable, const char *value))GetProcAddress(blade, "SetStringValue");
        return bld_proc(variable, value);
}


const char *GetStringValue(const char *variable)
{
        const char *(*bld_proc)(const char *variable);
        bld_proc = (const char *(*)(const char *variable))GetProcAddress(blade, "GetStringValue");
        return bld_proc(variable);
}


int DeleteStringValue(const char *variable)
{
        int (*bld_proc)(const char *variable);
        bld_proc = (int (*)(const char *variable))GetProcAddress(blade, "DeleteStringValue");
        return bld_proc(variable);
}


int SaveProfileData(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "SaveProfileData");
        return bld_proc(file_name);
}


int OpenProfileSection(int section, const char *comment)
{
        int (*bld_proc)(int section, const char *comment);
        bld_proc = (int (*)(int section, const char *comment))GetProcAddress(blade, "OpenProfileSection");
        return bld_proc(section, comment);
}


int CloseProfileSection(int section)
{
        int (*bld_proc)(int section);
        bld_proc = (int (*)(int section))GetProcAddress(blade, "CloseProfileSection");
        return bld_proc(section);
}


int StartProfile(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "StartProfile");
        return bld_proc();
}


int EnableProfiler(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "EnableProfiler");
        return bld_proc();
}


int DisableProfiler(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "DisableProfiler");
        return bld_proc();
}


int SetInputMode(const char *device, const char *mode)
{
        int (*bld_proc)(const char *device, const char *mode);
        bld_proc = (int (*)(const char *device, const char *mode))GetProcAddress(blade, "SetInputMode");
        return bld_proc(device, mode);
}


const char *GetInputMode(const char *device)
{
        const char *(*bld_proc)(const char *device);
        bld_proc = (const char *(*)(const char *device))GetProcAddress(blade, "GetInputMode");
        return bld_proc(device);
}


const char *GetLastPlayerCType(void)
{
        const char *(*bld_proc)(void);
        bld_proc = (const char *(*)(void))GetProcAddress(blade, "GetLastPlayerCType");
        return bld_proc();
}


int WorldToMBW(const char *world)
{
        int (*bld_proc)(const char *world);
        bld_proc = (int (*)(const char *world))GetProcAddress(blade, "WorldToMBW");
        return bld_proc(world);
}


int nMaterials(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "nMaterials");
        return bld_proc();
}


material_t *CreateMaterial(const char *name)
{
        material_t *(*bld_proc)(const char *name);
        bld_proc = (material_t *(*)(const char *name))GetProcAddress(blade, "CreateMaterial");
        return bld_proc(name);
}


material_t *GetMaterial(const char *name)
{
        material_t *(*bld_proc)(const char *name);
        bld_proc = (material_t *(*)(const char *name))GetProcAddress(blade, "GetMaterial");
        return bld_proc(name);
}


material_t *GetMaterialI(int index)
{
        material_t *(*bld_proc)(int index);
        bld_proc = (material_t *(*)(int index))GetProcAddress(blade, "GetMaterialI");
        return bld_proc(index);
}


int SetMaterialSoundProperty(
        material_t *material, int property_kind, int index, int soundID
)
{
        int (*bld_proc)(
        material_t *material, int property_kind, int index, int soundID
);
        bld_proc = (int (*)(
        material_t *material, int property_kind, int index, int soundID
))GetProcAddress(blade, "SetMaterialSoundProperty");
        return bld_proc(material, property_kind, index, soundID);
}


int GetMaterialSoundProperty(
        material_t *material, int property_kind, int index, int *soundID
)
{
        int (*bld_proc)(
        material_t *material, int property_kind, int index, int *soundID
);
        bld_proc = (int (*)(
        material_t *material, int property_kind, int index, int *soundID
))GetProcAddress(blade, "GetMaterialSoundProperty");
        return bld_proc(material, property_kind, index, soundID);
}


int GetMaterialStringProperty(
        material_t *material, int property_kind, int index, const char **value
)
{
        int (*bld_proc)(
        material_t *material, int property_kind, int index, const char **value
);
        bld_proc = (int (*)(
        material_t *material, int property_kind, int index, const char **value
))GetProcAddress(blade, "GetMaterialStringProperty");
        return bld_proc(material, property_kind, index, value);
}


int SetMaterialFloatProperty(
        material_t *material, int property_kind, int index, double value
)
{
        int (*bld_proc)(
        material_t *material, int property_kind, int index, double value
);
        bld_proc = (int (*)(
        material_t *material, int property_kind, int index, double value
))GetProcAddress(blade, "SetMaterialFloatProperty");
        return bld_proc(material, property_kind, index, value);
}


int GetMaterialFloatProperty(
        material_t *material, int property_kind, int index, double *value
)
{
        int (*bld_proc)(
        material_t *material, int property_kind, int index, double *value
);
        bld_proc = (int (*)(
        material_t *material, int property_kind, int index, double *value
))GetProcAddress(blade, "GetMaterialFloatProperty");
        return bld_proc(material, property_kind, index, value);
}


int AddHitSoundComb(
        material_t *material1, material_t *material2, int soundID
)
{
        int (*bld_proc)(
        material_t *material1, material_t *material2, int soundID
);
        bld_proc = (int (*)(
        material_t *material1, material_t *material2, int soundID
))GetProcAddress(blade, "AddHitSoundComb");
        return bld_proc(material1, material2, soundID);
}


int GetSectorByPosition(double x, double y, double z)
{
        int (*bld_proc)(double x, double y, double z);
        bld_proc = (int (*)(double x, double y, double z))GetProcAddress(blade, "GetSectorByPosition");
        return bld_proc(x, y, z);
}


int GetSectorByIndex(int index)
{
        int (*bld_proc)(int index);
        bld_proc = (int (*)(int index))GetProcAddress(blade, "GetSectorByIndex");
        return bld_proc(index);
}

// TODO fix prototype
void GetNumberOfSectors()
{
        assert("GetNumberOfSectors" == NULL);
}


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
);
        bld_proc = (int (*)(
        int sectorID, double x_vec1, double y_vec1, double z_vec1,
        double x_vec2, double y_vec2, double z_vec2, double x_vec3,
        double y_vec3, double z_vec3, const char *s_unknown, double d_unknown,
        int i_unknown
))GetProcAddress(blade, "InitBreakSector");
        return bld_proc(sectorID, x_vec1, y_vec1, z_vec1, x_vec2, y_vec2, z_vec2, x_vec3, y_vec3, z_vec3, s_unknown, d_unknown, i_unknown);
}


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
);
        bld_proc = (int (*)(
        int sectorID, double x_impulse, double y_impulse, double z_impulse,
        double x, double y, double z, double x_unknown, double y_unknown,
        double z_unknown
))GetProcAddress(blade, "DoBreakSector");
        return bld_proc(sectorID, x_impulse, y_impulse, z_impulse, x, y, z, x_unknown, y_unknown, z_unknown);
}


int GetSectorIntProperty(
        int sectorID, int property_kind, int index, int *value
)
{
        int (*bld_proc)(
        int sectorID, int property_kind, int index, int *value
);
        bld_proc = (int (*)(
        int sectorID, int property_kind, int index, int *value
))GetProcAddress(blade, "GetSectorIntProperty");
        return bld_proc(sectorID, property_kind, index, value);
}


int SetSectorIntProperty(
        int sectorID, int property_kind, int index, int value
)
{
        int (*bld_proc)(
        int sectorID, int property_kind, int index, int value
);
        bld_proc = (int (*)(
        int sectorID, int property_kind, int index, int value
))GetProcAddress(blade, "SetSectorIntProperty");
        return bld_proc(sectorID, property_kind, index, value);
}


int GetSectorFloatProperty(
        int sectorID, int property_kind, int index, double *value
)
{
        int (*bld_proc)(
        int sectorID, int property_kind, int index, double *value
);
        bld_proc = (int (*)(
        int sectorID, int property_kind, int index, double *value
))GetProcAddress(blade, "GetSectorFloatProperty");
        return bld_proc(sectorID, property_kind, index, value);
}


int SetSectorFloatProperty(
        int sectorID, int property_kind, int index, double value
)
{
        int (*bld_proc)(
        int sectorID, int property_kind, int index, double value
);
        bld_proc = (int (*)(
        int sectorID, int property_kind, int index, double value
))GetProcAddress(blade, "SetSectorFloatProperty");
        return bld_proc(sectorID, property_kind, index, value);
}


int GetSectorStringProperty(
        int sectorID, int property_kind, int index, const char **value
)
{
        int (*bld_proc)(
        int sectorID, int property_kind, int index, const char **value
);
        bld_proc = (int (*)(
        int sectorID, int property_kind, int index, const char **value
))GetProcAddress(blade, "GetSectorStringProperty");
        return bld_proc(sectorID, property_kind, index, value);
}


int SetSectorStringProperty(
        int sectorID, int property_kind, int index, const char *value
)
{
        int (*bld_proc)(
        int sectorID, int property_kind, int index, const char *value
);
        bld_proc = (int (*)(
        int sectorID, int property_kind, int index, const char *value
))GetProcAddress(blade, "SetSectorStringProperty");
        return bld_proc(sectorID, property_kind, index, value);
}


int SetSectorVectorProperty(
        int sectorID, int property_kind, int index, double x,
        double y, double z
)
{
        int (*bld_proc)(
        int sectorID, int property_kind, int index, double x,
        double y, double z
);
        bld_proc = (int (*)(
        int sectorID, int property_kind, int index, double x,
        double y, double z
))GetProcAddress(blade, "SetSectorVectorProperty");
        return bld_proc(sectorID, property_kind, index, x, y, z);
}


int GetSectorVectorProperty(
        int sectorID, int property_kind, int index,
        double *x, double *y, double *z
)
{
        int (*bld_proc)(
        int sectorID, int property_kind, int index,
        double *x, double *y, double *z
);
        bld_proc = (int (*)(
        int sectorID, int property_kind, int index,
        double *x, double *y, double *z
))GetProcAddress(blade, "GetSectorVectorProperty");
        return bld_proc(sectorID, property_kind, index, x, y, z);
}


int SetSectorFuncProperty(
        int sectorID, int property_kind, int index, PyObject *value
)
{
        int (*bld_proc)(
        int sectorID, int property_kind, int index, PyObject *value
);
        bld_proc = (int (*)(
        int sectorID, int property_kind, int index, PyObject *value
))GetProcAddress(blade, "SetSectorFuncProperty");
        return bld_proc(sectorID, property_kind, index, value);
}


int GetSectorFuncProperty(
        int sectorID, int property_kind, int index, PyObject **value
)
{
        int (*bld_proc)(
        int sectorID, int property_kind, int index, PyObject **value
);
        bld_proc = (int (*)(
        int sectorID, int property_kind, int index, PyObject **value
))GetProcAddress(blade, "GetSectorFuncProperty");
        return bld_proc(sectorID, property_kind, index, value);
}


int GetAnimationDuration(const char *animation_name, double *duration)
{
        int (*bld_proc)(const char *animation_name, double *duration);
        bld_proc = (int (*)(const char *animation_name, double *duration))GetProcAddress(blade, "GetAnimationDuration");
        return bld_proc(animation_name, duration);
}


int RStepEvents(const char *s_unknown1, const char *s_unknown2)
{
        int (*bld_proc)(const char *s_unknown1, const char *s_unknown2);
        bld_proc = (int (*)(const char *s_unknown1, const char *s_unknown2))GetProcAddress(blade, "RStepEvents");
        return bld_proc(s_unknown1, s_unknown2);
}


int LStepEvents(const char *s_unknown1, const char *s_unknown2)
{
        int (*bld_proc)(const char *s_unknown1, const char *s_unknown2);
        bld_proc = (int (*)(const char *s_unknown1, const char *s_unknown2))GetProcAddress(blade, "LStepEvents");
        return bld_proc(s_unknown1, s_unknown2);
}


int LoadSampledAnimation(
        const char *file, const char *internal_name, int type,
        const char *s_unknown, int i_unknown
)
{
        int (*bld_proc)(
        const char *file, const char *internal_name, int type,
        const char *s_unknown, int i_unknown
);
        bld_proc = (int (*)(
        const char *file, const char *internal_name, int type,
        const char *s_unknown, int i_unknown
))GetProcAddress(blade, "LoadSampledAnimation");
        return bld_proc(file, internal_name, type, s_unknown, i_unknown);
}


int CreateFCAnimation(
        const char *file, const char *internal_name, int n_armonics
)
{
        int (*bld_proc)(
        const char *file, const char *internal_name, int n_armonics
);
        bld_proc = (int (*)(
        const char *file, const char *internal_name, int n_armonics
))GetProcAddress(blade, "CreateFCAnimation");
        return bld_proc(file, internal_name, n_armonics);
}


int CreateDFCAnimation(
        const char *file1, const char *file2, const char *internal_name,
        int n_armonics
)
{
        int (*bld_proc)(
        const char *file1, const char *file2, const char *internal_name,
        int n_armonics
);
        bld_proc = (int (*)(
        const char *file1, const char *file2, const char *internal_name,
        int n_armonics
))GetProcAddress(blade, "CreateDFCAnimation");
        return bld_proc(file1, file2, internal_name, n_armonics);
}


int AddRStepEvent(const char *animation_name, double d_unknown)
{
        int (*bld_proc)(const char *animation_name, double d_unknown);
        bld_proc = (int (*)(const char *animation_name, double d_unknown))GetProcAddress(blade, "AddRStepEvent");
        return bld_proc(animation_name, d_unknown);
}


int AddLStepEvent(const char *animation_name, double d_unknown)
{
        int (*bld_proc)(const char *animation_name, double d_unknown);
        bld_proc = (int (*)(const char *animation_name, double d_unknown))GetProcAddress(blade, "AddLStepEvent");
        return bld_proc(animation_name, d_unknown);
}


int AddRReleaseEvent(const char *animation_name, double d_unknown)
{
        int (*bld_proc)(const char *animation_name, double d_unknown);
        bld_proc = (int (*)(const char *animation_name, double d_unknown))GetProcAddress(blade, "AddRReleaseEvent");
        return bld_proc(animation_name, d_unknown);
}


int AddLReleaseEvent(const char *animation_name, double d_unknown)
{
        int (*bld_proc)(const char *animation_name, double d_unknown);
        bld_proc = (int (*)(const char *animation_name, double d_unknown))GetProcAddress(blade, "AddLReleaseEvent");
        return bld_proc(animation_name, d_unknown);
}


void AddAnmEvent(const char *anm_name, const char *event_name, double event_frame)
{
        void (*bld_proc)(const char *anm_name, const char *event_name, double event_frame);
        bld_proc = (void (*)(const char *anm_name, const char *event_name, double event_frame))GetProcAddress(blade, "AddAnmEvent");
        bld_proc(anm_name, event_name, event_frame);
}


void AddStopTests(const char *animation_name)
{
        void (*bld_proc)(const char *animation_name);
        bld_proc = (void (*)(const char *animation_name))GetProcAddress(blade, "AddStopTests");
        bld_proc(animation_name);
}


void AddFloorCTolerance(const char *animation_name, double tolerance)
{
        void (*bld_proc)(const char *animation_name, double tolerance);
        bld_proc = (void (*)(const char *animation_name, double tolerance))GetProcAddress(blade, "AddFloorCTolerance");
        bld_proc(animation_name, tolerance);
}


int AddTranTime(
        const char *biped_name, const char *next_anm , const char *prev_anm,
        double time, int unknown
)
{
        int (*bld_proc)(
        const char *biped_name, const char *next_anm , const char *prev_anm,
        double time, int unknown
);
        bld_proc = (int (*)(
        const char *biped_name, const char *next_anm , const char *prev_anm,
        double time, int unknown
))GetProcAddress(blade, "AddTranTime");
        return bld_proc(biped_name, next_anm, prev_anm, time, unknown);
}


int CheckAnims(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "CheckAnims");
        return bld_proc();
}


int GiveAnims(const char *race_name)
{
        int (*bld_proc)(const char *race_name);
        bld_proc = (int (*)(const char *race_name))GetProcAddress(blade, "GiveAnims");
        return bld_proc(race_name);
}


int AddStepSound(const char *name, int soundID)
{
        int (*bld_proc)(const char *name, int soundID);
        bld_proc = (int (*)(const char *name, int soundID))GetProcAddress(blade, "AddStepSound");
        return bld_proc(name, soundID);
}


int AddMaterialStepSound(
        const char *table, const char *material, const char *step_sound
)
{
        int (*bld_proc)(
        const char *table, const char *material, const char *step_sound
);
        bld_proc = (int (*)(
        const char *table, const char *material, const char *step_sound
))GetProcAddress(blade, "AddMaterialStepSound");
        return bld_proc(table, material, step_sound);
}


int AddTextureMaterial(const char *texture, const char *material)
{
        int (*bld_proc)(const char *texture, const char *material);
        bld_proc = (int (*)(const char *texture, const char *material))GetProcAddress(blade, "AddTextureMaterial");
        return bld_proc(texture, material);
}


int AddActionStepSound(
        const char *table, const char *action, const char *step_sound_table
)
{
        int (*bld_proc)(
        const char *table, const char *action, const char *step_sound_table
);
        bld_proc = (int (*)(
        const char *table, const char *action, const char *step_sound_table
))GetProcAddress(blade, "AddActionStepSound");
        return bld_proc(table, action, step_sound_table);
}


int CreateSound(const char *file_name, const char *sound_name)
{
        int (*bld_proc)(const char *file_name, const char *sound_name);
        bld_proc = (int (*)(const char *file_name, const char *sound_name))GetProcAddress(blade, "CreateSound");
        return bld_proc(file_name, sound_name);
}


int CreateSoundS(int soundID)
{
        int (*bld_proc)(int soundID);
        bld_proc = (int (*)(int soundID))GetProcAddress(blade, "CreateSoundS");
        return bld_proc(soundID);
}


void DestroySound(int soundID)
{
        void (*bld_proc)(int soundID);
        bld_proc = (void (*)(int soundID))GetProcAddress(blade, "DestroySound");
        bld_proc(soundID);
}


int SetSoundVolume(double volume)
{
        int (*bld_proc)(double volume);
        bld_proc = (int (*)(double volume))GetProcAddress(blade, "SetSoundVolume");
        return bld_proc(volume);
}


double GetSoundVolume(void)
{
        double (*bld_proc)(void);
        bld_proc = (double (*)(void))GetProcAddress(blade, "GetSoundVolume");
        return bld_proc();
}


int SoundSystemActive(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "SoundSystemActive");
        return bld_proc();
}


int SetSSFrecuency(int frequency)
{
        int (*bld_proc)(int frequency);
        bld_proc = (int (*)(int frequency))GetProcAddress(blade, "SetSSFrecuency");
        return bld_proc(frequency);
}


int SetSS2dChannels(int num_ch)
{
        int (*bld_proc)(int num_ch);
        bld_proc = (int (*)(int num_ch))GetProcAddress(blade, "SetSS2dChannels");
        return bld_proc(num_ch);
}


int SetSS3dChannels(int num_ch)
{
        int (*bld_proc)(int num_ch);
        bld_proc = (int (*)(int num_ch))GetProcAddress(blade, "SetSS3dChannels");
        return bld_proc(num_ch);
}


int SetSSFilter(int filter_output)
{
        int (*bld_proc)(int filter_output);
        bld_proc = (int (*)(int filter_output))GetProcAddress(blade, "SetSSFilter");
        return bld_proc(filter_output);
}


int KillMusic(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "KillMusic");
        return bld_proc();
}


int ShutDownSoundChannels(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "ShutDownSoundChannels");
        return bld_proc();
}


int PauseSoundSystem(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "PauseSoundSystem");
        return bld_proc();
}


int PauseSoundSystemButMusic(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "PauseSoundSystemButMusic");
        return bld_proc();
}


int ResumeSoundSystem(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "ResumeSoundSystem");
        return bld_proc();
}


int SetMusicVolume(float volume)
{
        int (*bld_proc)(float volume);
        bld_proc = (int (*)(float volume))GetProcAddress(blade, "SetMusicVolume");
        return bld_proc(volume);
}


double GetMusicVolume(void)
{
        double (*bld_proc)(void);
        bld_proc = (double (*)(void))GetProcAddress(blade, "GetMusicVolume");
        return bld_proc();
}


int GetSSQuality(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetSSQuality");
        return bld_proc();
}


int SetSSQuality(int SSQuality)
{
        int (*bld_proc)(int SSQuality);
        bld_proc = (int (*)(int SSQuality))GetProcAddress(blade, "SetSSQuality");
        return bld_proc(SSQuality);
}


int GetSSSpeakerConfig(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetSSSpeakerConfig");
        return bld_proc();
}


int SetEAXOverride(int EAXOverride)
{
        int (*bld_proc)(int EAXOverride);
        bld_proc = (int (*)(int EAXOverride))GetProcAddress(blade, "SetEAXOverride");
        return bld_proc(EAXOverride);
}


int GetEAXOverride(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetEAXOverride");
        return bld_proc();
}


int SaveSSConfig(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "SaveSSConfig");
        return bld_proc();
}


int SetSSSpeakerConfig(int config)
{
        int (*bld_proc)(int config);
        bld_proc = (int (*)(int config))GetProcAddress(blade, "SetSSSpeakerConfig");
        return bld_proc(config);
}


int CreateGhostSector(
	const char *ghost_sector_name, const char *group_name,
	double floor_height, double roof_height, int num_points,
	point_2d_t *points
)
{
        int (*bld_proc)(
	const char *ghost_sector_name, const char *group_name,
	double floor_height, double roof_height, int num_points,
	point_2d_t *points
);
        bld_proc = (int (*)(
	const char *ghost_sector_name, const char *group_name,
	double floor_height, double roof_height, int num_points,
	point_2d_t *points
))GetProcAddress(blade, "CreateGhostSector");
        return bld_proc(ghost_sector_name, group_name, floor_height, roof_height, num_points, points);
}


int SetEAX(int eax_flag)
{
        int (*bld_proc)(int eax_flag);
        bld_proc = (int (*)(int eax_flag))GetProcAddress(blade, "SetEAX");
        return bld_proc(eax_flag);
}


int SetGhostSectorSound(
        const char *aghost_name, const char *file_name, double volume,
        double base_volume, double min_dist, double max_dist, double v_max_dist,
        double scale
)
{
        int (*bld_proc)(
        const char *aghost_name, const char *file_name, double volume,
        double base_volume, double min_dist, double max_dist, double v_max_dist,
        double scale
);
        bld_proc = (int (*)(
        const char *aghost_name, const char *file_name, double volume,
        double base_volume, double min_dist, double max_dist, double v_max_dist,
        double scale
))GetProcAddress(blade, "SetGhostSectorSound");
        return bld_proc(aghost_name, file_name, volume, base_volume, min_dist, max_dist, v_max_dist, scale);
}


int GetGhostSectorSound(const char *gs_name)
{
        int (*bld_proc)(const char *gs_name);
        bld_proc = (int (*)(const char *gs_name))GetProcAddress(blade, "GetGhostSectorSound");
        return bld_proc(gs_name);
}


int SetGhostSectorGroupSound(
        const char *group_name, const char *file_name, double volume,
        double base_volume, double min_dist, double max_dist, double unknown,
        double scale
)
{
        int (*bld_proc)(
        const char *group_name, const char *file_name, double volume,
        double base_volume, double min_dist, double max_dist, double unknown,
        double scale
);
        bld_proc = (int (*)(
        const char *group_name, const char *file_name, double volume,
        double base_volume, double min_dist, double max_dist, double unknown,
        double scale
))GetProcAddress(blade, "SetGhostSectorGroupSound");
        return bld_proc(group_name, file_name, volume, base_volume, min_dist, max_dist, unknown, scale);
}


int SetShowSounds(int showSounds)
{
        int (*bld_proc)(int showSounds);
        bld_proc = (int (*)(int showSounds))GetProcAddress(blade, "SetShowSounds");
        return bld_proc(showSounds);
}


int GetSoundDevInstace(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetSoundDevInstace");
        return bld_proc();
}


int nSounds(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "nSounds");
        return bld_proc();
}


const char *GetSoundName(int soundId)
{
        const char *(*bld_proc)(int soundId);
        bld_proc = (const char *(*)(int soundId))GetProcAddress(blade, "GetSoundName");
        return bld_proc(soundId);
}


const char *GetSoundFileName(int soundId)
{
        const char *(*bld_proc)(int soundId);
        bld_proc = (const char *(*)(int soundId))GetProcAddress(blade, "GetSoundFileName");
        return bld_proc(soundId);
}


int PlaySoundM(int soundID, double x, double y, double z, int i_unknown)
{
        int (*bld_proc)(int soundID, double x, double y, double z, int i_unknown);
        bld_proc = (int (*)(int soundID, double x, double y, double z, int i_unknown))GetProcAddress(blade, "PlaySoundM");
        return bld_proc(soundID, x, y, z, i_unknown);
}


int PlaySoundStereo(int soundID, int i_unknown)
{
        int (*bld_proc)(int soundID, int i_unknown);
        bld_proc = (int (*)(int soundID, int i_unknown))GetProcAddress(blade, "PlaySoundStereo");
        return bld_proc(soundID, i_unknown);
}


int StopSound(int soundID)
{
        int (*bld_proc)(int soundID);
        bld_proc = (int (*)(int soundID))GetProcAddress(blade, "StopSound");
        return bld_proc(soundID);
}


double GetSoundFloatProperty(int property_kind, int soundID)
{
        double (*bld_proc)(int property_kind, int soundID);
        bld_proc = (double (*)(int property_kind, int soundID))GetProcAddress(blade, "GetSoundFloatProperty");
        return bld_proc(property_kind, soundID);
}


void SetSoundFloatProperty(int property_kind, int soundID, double value)
{
        void (*bld_proc)(int property_kind, int soundID, double value);
        bld_proc = (void (*)(int property_kind, int soundID, double value))GetProcAddress(blade, "SetSoundFloatProperty");
        bld_proc(property_kind, soundID, value);
}


char *GetSoundStringProperty(int property_kind, int soundID)
{
        char *(*bld_proc)(int property_kind, int soundID);
        bld_proc = (char *(*)(int property_kind, int soundID))GetProcAddress(blade, "GetSoundStringProperty");
        return bld_proc(property_kind, soundID);
}

// TODO fix prototype
void SetSoundStringProperty()
{
        assert("SetSoundStringProperty" == NULL);
}

// TODO fix prototype
void GetSoundIntProperty()
{
        assert("GetSoundIntProperty" == NULL);
}


void SetSoundIntProperty(int property_kind, int soundID, int value)
{
        void (*bld_proc)(int property_kind, int soundID, int value);
        bld_proc = (void (*)(int property_kind, int soundID, int value))GetProcAddress(blade, "SetSoundIntProperty");
        bld_proc(property_kind, soundID, value);
}


void SetSoundPitchVar(
        int soundID, int i_unknown, float f_unknown1, float f_unknown2,
        float f_unknown3, float f_unknown4
)
{
        void (*bld_proc)(
        int soundID, int i_unknown, float f_unknown1, float f_unknown2,
        float f_unknown3, float f_unknown4
);
        bld_proc = (void (*)(
        int soundID, int i_unknown, float f_unknown1, float f_unknown2,
        float f_unknown3, float f_unknown4
))GetProcAddress(blade, "SetSoundPitchVar");
        bld_proc(soundID, i_unknown, f_unknown1, f_unknown2, f_unknown3, f_unknown4);
}

// TODO fix prototype
void GetSoundFuncProperty()
{
        assert("GetSoundFuncProperty" == NULL);
}

// TODO fix prototype
void SetSoundFuncProperty()
{
        assert("SetSoundFuncProperty" == NULL);
}


int dropDebugInfo(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "dropDebugInfo");
        return bld_proc();
}


int GetMusicEventPriority(int unknown)
{
        int (*bld_proc)(int unknown);
        bld_proc = (int (*)(int unknown))GetProcAddress(blade, "GetMusicEventPriority");
        return bld_proc(unknown);
}


int getMusicEvent(const char *event_name)
{
        int (*bld_proc)(const char *event_name);
        bld_proc = (int (*)(const char *event_name))GetProcAddress(blade, "getMusicEvent");
        return bld_proc(event_name);
}


int exeMusicEvent(int unknown1, int unknown2)
{
        int (*bld_proc)(int unknown1, int unknown2);
        bld_proc = (int (*)(int unknown1, int unknown2))GetProcAddress(blade, "exeMusicEvent");
        return bld_proc(unknown1, unknown2);
}


int addMusicEventCD(
        const char *lpszEventName, int iTrack, double dFIn, double dFOut,
        float fVolume, float fPriority, int bBackGround, int iNext
)
{
        int (*bld_proc)(
        const char *lpszEventName, int iTrack, double dFIn, double dFOut,
        float fVolume, float fPriority, int bBackGround, int iNext
);
        bld_proc = (int (*)(
        const char *lpszEventName, int iTrack, double dFIn, double dFOut,
        float fVolume, float fPriority, int bBackGround, int iNext
))GetProcAddress(blade, "addMusicEventCD");
        return bld_proc(lpszEventName, iTrack, dFIn, dFOut, fVolume, fPriority, bBackGround, iNext);
}


int addMusicEventMP3(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int unknown
)
{
        int (*bld_proc)(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int unknown
);
        bld_proc = (int (*)(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int unknown
))GetProcAddress(blade, "addMusicEventMP3");
        return bld_proc(lpszEventName, lpszFile, dFIn, fVolume, dFOut, fPriority, bBackGround, iNext, unknown);
}


int addMusicEventWAV(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int opened
)
{
        int (*bld_proc)(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int opened
);
        bld_proc = (int (*)(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int opened
))GetProcAddress(blade, "addMusicEventWAV");
        return bld_proc(lpszEventName, lpszFile, dFIn, fVolume, dFOut, fPriority, bBackGround, iNext, opened);
}


int addMusicEventADPCM(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int unknown
)
{
        int (*bld_proc)(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int unknown
);
        bld_proc = (int (*)(
        const char *lpszEventName, const char *lpszFile, double dFIn,
        float fVolume, double dFOut, float fPriority, int bBackGround,
        int iNext, int unknown
))GetProcAddress(blade, "addMusicEventADPCM");
        return bld_proc(lpszEventName, lpszFile, dFIn, fVolume, dFOut, fPriority, bBackGround, iNext, unknown);
}


int GetSound(const char *sound_name)
{
        int (*bld_proc)(const char *sound_name);
        bld_proc = (int (*)(const char *sound_name))GetProcAddress(blade, "GetSound");
        return bld_proc(sound_name);
}


int addSoundVar(int soundID, const char *alt_sound)
{
        int (*bld_proc)(int soundID, const char *alt_sound);
        bld_proc = (int (*)(int soundID, const char *alt_sound))GetProcAddress(blade, "addSoundVar");
        return bld_proc(soundID, alt_sound);
}


void saveSoundStats(const char *file_name)
{
        void (*bld_proc)(const char *file_name);
        bld_proc = (void (*)(const char *file_name))GetProcAddress(blade, "saveSoundStats");
        bld_proc(file_name);
}


int loadMusicState(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "loadMusicState");
        return bld_proc(file_name);
}


int saveMusicState(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "saveMusicState");
        return bld_proc(file_name);
}


int loadSoundDataBase(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "loadSoundDataBase");
        return bld_proc(file_name);
}


int saveSoundDataBase(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "saveSoundDataBase");
        return bld_proc(file_name);
}


int GetSplinePos(void *spline, float time, void *pos)
{
        int (*bld_proc)(void *spline, float time, void *pos);
        bld_proc = (int (*)(void *spline, float time, void *pos))GetProcAddress(blade, "GetSplinePos");
        return bld_proc(spline, time, pos);
}


int AddNodeSpline(
        void *spline, int num_node, double time, double pos_x, double pos_y,
        double pos_z, double tang_i_x, double tang_i_y, double tang_i_z,
        double tang_j_x, double tang_j_y, double tang_j_z)
{
        int (*bld_proc)(void *spline, int num_node, double time, double pos_x, double pos_y,
        double pos_z, double tang_i_x, double tang_i_y, double tang_i_z,
        double tang_j_x, double tang_j_y, double tang_j_z);
        bld_proc = (int (*)(void *spline, int num_node, double time, double pos_x, double pos_y,
        double pos_z, double tang_i_x, double tang_i_y, double tang_i_z,
        double tang_j_x, double tang_j_y, double tang_j_z))GetProcAddress(blade, "AddNodeSpline");
        return bld_proc(spline, num_node, time, pos_x, pos_y,
                pos_z, tang_i_x, tang_i_y, tang_i_z,
                tang_j_x, tang_j_y, tang_j_z);
}


int CloseSpline(void *spline)
{
        int (*bld_proc)(void *spline);
        bld_proc = (int (*)(void *spline))GetProcAddress(blade, "CloseSpline");
        return bld_proc(spline);
}


int ClearSpline(void *spline)
{
        int (*bld_proc)(void *spline);
        bld_proc = (int (*)(void *spline))GetProcAddress(blade, "ClearSpline");
        return bld_proc(spline);
}


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
);
        bld_proc = (B_Entity *(*)(
        const char *name, point_3d_t *spark_point, point_3d_t *spark_dir,
        double d_unknown1, double d_unknown2, double d_unknown3,
        double d_unknown4, double d_unknown5, int i_unknown6, int i_unknown7,
        int i_unknown8, int i_unknown9, int i_unknown10, int i_unknown11,
        float d_unknown12, float d_unknown13, float d_unknown14, int i_unknown15
))GetProcAddress(blade, "CreateSpark");
        return bld_proc(name, spark_point, spark_dir, d_unknown1, d_unknown2, d_unknown3, d_unknown4, d_unknown5, i_unknown6, i_unknown7, i_unknown8, i_unknown9, i_unknown10, i_unknown11, d_unknown12, d_unknown13, d_unknown14, i_unknown15);
}


B_Entity *CreateEntity(
        const char *name, const char *kind, double x, double y, double z,
        const char *parent_class, const char *unknown
)
{
        B_Entity *(*bld_proc)(
        const char *name, const char *kind, double x, double y, double z,
        const char *parent_class, const char *unknown
);
        bld_proc = (B_Entity *(*)(
        const char *name, const char *kind, double x, double y, double z,
        const char *parent_class, const char *unknown
))GetProcAddress(blade, "CreateEntity");
        return bld_proc(name, kind, x, y, z, parent_class, unknown);
}


int DeleteEntity(const char *name)
{
        int (*bld_proc)(const char *name);
        bld_proc = (int (*)(const char *name))GetProcAddress(blade, "DeleteEntity");
        return bld_proc(name);
}


B_Entity *CreateEntityDecal(
        const char *name, double x, double y, double z, int i_unknown,
        double d_unknown1, double d_unknown2
)
{
        B_Entity *(*bld_proc)(
        const char *name, double x, double y, double z, int i_unknown,
        double d_unknown1, double d_unknown2
);
        bld_proc = (B_Entity *(*)(
        const char *name, double x, double y, double z, int i_unknown,
        double d_unknown1, double d_unknown2
))GetProcAddress(blade, "CreateEntityDecal");
        return bld_proc(name, x, y, z, i_unknown, d_unknown1, d_unknown2);
}


B_Entity *GetEntity(const char *name)
{
        B_Entity *(*bld_proc)(const char *name);
        bld_proc = (B_Entity *(*)(const char *name))GetProcAddress(blade, "GetEntity");
        return bld_proc(name);
}


B_Entity *GetEntityI(int index)
{
        B_Entity *(*bld_proc)(int index);
        bld_proc = (B_Entity *(*)(int index))GetProcAddress(blade, "GetEntityI");
        return bld_proc(index);
}


const char *GetEntityName(B_Entity *entity)
{
        const char *(*bld_proc)(B_Entity *entity);
        bld_proc = (const char *(*)(B_Entity *entity))GetProcAddress(blade, "GetEntityName");
        return bld_proc(entity);
}


int GetEntitiesAt(
        double x, double y, double z, double radius, char ***entity_names
)
{
        int (*bld_proc)(
        double x, double y, double z, double radius, char ***entity_names
);
        bld_proc = (int (*)(
        double x, double y, double z, double radius, char ***entity_names
))GetProcAddress(blade, "GetEntitiesAt");
        return bld_proc(x, y, z, radius, entity_names);
}


int GetEntitiesVisibleFrom(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***entity_names
)
{
        int (*bld_proc)(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***entity_names
);
        bld_proc = (int (*)(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***entity_names
))GetProcAddress(blade, "GetEntitiesVisibleFrom");
        return bld_proc(xc, yc, zc, radius, xdir, ydir, zdir, angle, entity_names);
}


int GetObjectEntitiesVisibleFrom(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***entity_names
)
{
        int (*bld_proc)(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***entity_names
);
        bld_proc = (int (*)(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***entity_names
))GetProcAddress(blade, "GetObjectEntitiesVisibleFrom");
        return bld_proc(xc, yc, zc, radius, xdir, ydir, zdir, angle, entity_names);
}


int GetEnemiesVisibleFrom(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***enemy_names
)
{
        int (*bld_proc)(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***enemy_names
);
        bld_proc = (int (*)(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***enemy_names
))GetProcAddress(blade, "GetEnemiesVisibleFrom");
        return bld_proc(xc, yc, zc, radius, xdir, ydir, zdir, angle, enemy_names);
}


int SetCombos(
        const char *person_name, int num_combos, char **combos_names,
        int *combos_executed
)
{
        int (*bld_proc)(
        const char *person_name, int num_combos, char **combos_names,
        int *combos_executed
);
        bld_proc = (int (*)(
        const char *person_name, int num_combos, char **combos_names,
        int *combos_executed
))GetProcAddress(blade, "SetCombos");
        return bld_proc(person_name, num_combos, combos_names, combos_executed);
}


int GetCombos(const char *person_name, combo_t **combos)
{
        int (*bld_proc)(const char *person_name, combo_t **combos);
        bld_proc = (int (*)(const char *person_name, combo_t **combos))GetProcAddress(blade, "GetCombos");
        return bld_proc(person_name, combos);
}


int GetWeaponCombos(
        const char *person_name, const char *weapon_kind, combo_t **combos
)
{
        int (*bld_proc)(
        const char *person_name, const char *weapon_kind, combo_t **combos
);
        bld_proc = (int (*)(
        const char *person_name, const char *weapon_kind, combo_t **combos
))GetProcAddress(blade, "GetWeaponCombos");
        return bld_proc(person_name, weapon_kind, combos);
}


int nEntities(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "nEntities");
        return bld_proc();
}


int GetNewExclusionGroupId(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetNewExclusionGroupId");
        return bld_proc();
}


int AddCameraEvent(const char *entity_name, int frame, PyObject *func)
{
        int (*bld_proc)(const char *entity_name, int frame, PyObject *func);
        bld_proc = (int (*)(const char *entity_name, int frame, PyObject *func))GetProcAddress(blade, "AddCameraEvent");
        return bld_proc(entity_name, frame, func);
}


int DeleteCameraEvent(const char *entity_name, int frame)
{
        int (*bld_proc)(const char *entity_name, int frame);
        bld_proc = (int (*)(const char *entity_name, int frame))GetProcAddress(blade, "DeleteCameraEvent");
        return bld_proc(entity_name, frame);
}


int CameraAddSourceNode(
        const char *entity_name, float time, double x, double y, double z
)
{
        int (*bld_proc)(
        const char *entity_name, float time, double x, double y, double z
);
        bld_proc = (int (*)(
        const char *entity_name, float time, double x, double y, double z
))GetProcAddress(blade, "CameraAddSourceNode");
        return bld_proc(entity_name, time, x, y, z);
}


int CameraAddTargetNode(
        const char *entity_name, float time, double x, double y, double z
)
{
        int (*bld_proc)(
        const char *entity_name, float time, double x, double y, double z
);
        bld_proc = (int (*)(
        const char *entity_name, float time, double x, double y, double z
))GetProcAddress(blade, "CameraAddTargetNode");
        return bld_proc(entity_name, time, x, y, z);
}


int CameraSetStartTangentSourceNode(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
)
{
        int (*bld_proc)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
);
        bld_proc = (int (*)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
))GetProcAddress(blade, "CameraSetStartTangentSourceNode");
        return bld_proc(entity_name, unknown1, unknown2, unknown3, unknown4);
}


int CameraSetEndTangentSourceNode(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
)
{
        int (*bld_proc)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
);
        bld_proc = (int (*)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
))GetProcAddress(blade, "CameraSetEndTangentSourceNode");
        return bld_proc(entity_name, unknown1, unknown2, unknown3, unknown4);
}


int CameraSetStartTangentTargetNode(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
)
{
        int (*bld_proc)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
);
        bld_proc = (int (*)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
))GetProcAddress(blade, "CameraSetStartTangentTargetNode");
        return bld_proc(entity_name, unknown1, unknown2, unknown3, unknown4);
}


int CameraSetEndTangentTargetNode(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
)
{
        int (*bld_proc)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
);
        bld_proc = (int (*)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
))GetProcAddress(blade, "CameraSetEndTangentTargetNode");
        return bld_proc(entity_name, unknown1, unknown2, unknown3, unknown4);
}


int CameraSetPersonView(
        const char *entity_name, const char *person_name
)
{
        int (*bld_proc)(
        const char *entity_name, const char *person_name
);
        bld_proc = (int (*)(
        const char *entity_name, const char *person_name
))GetProcAddress(blade, "CameraSetPersonView");
        return bld_proc(entity_name, person_name);
}


int CameraSetMaxCamera(
        const char *entity_name, const char *cam_file_name, int i_unknown,
        int num_frames
)
{
        int (*bld_proc)(
        const char *entity_name, const char *cam_file_name, int i_unknown,
        int num_frames
);
        bld_proc = (int (*)(
        const char *entity_name, const char *cam_file_name, int i_unknown,
        int num_frames
))GetProcAddress(blade, "CameraSetMaxCamera");
        return bld_proc(entity_name, cam_file_name, i_unknown, num_frames);
}


int CameraCut(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "CameraCut");
        return bld_proc(entity_name);
}


int CameraSetTravelingView(
        const char *entity_name, int unknown1, int unknown2
)
{
        int (*bld_proc)(
        const char *entity_name, int unknown1, int unknown2
);
        bld_proc = (int (*)(
        const char *entity_name, int unknown1, int unknown2
))GetProcAddress(blade, "CameraSetTravelingView");
        return bld_proc(entity_name, unknown1, unknown2);
}


int CameraClearPath(const char *entity_name, int node)
{
        int (*bld_proc)(const char *entity_name, int node);
        bld_proc = (int (*)(const char *entity_name, int node))GetProcAddress(blade, "CameraClearPath");
        return bld_proc(entity_name, node);
}


int CameraStartPath(const char *entity_name, int node)
{
        int (*bld_proc)(const char *entity_name, int node);
        bld_proc = (int (*)(const char *entity_name, int node))GetProcAddress(blade, "CameraStartPath");
        return bld_proc(entity_name, node);
}


int UseEntity(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "UseEntity");
        return bld_proc(entity_name);
}


int ChangeEntityStatic(const char *entity_name, int is_static)
{
        int (*bld_proc)(const char *entity_name, int is_static);
        bld_proc = (int (*)(const char *entity_name, int is_static))GetProcAddress(blade, "ChangeEntityStatic");
        return bld_proc(entity_name, is_static);
}


int ChangeEntityActor(const char *entity_name, int is_actor)
{
        int (*bld_proc)(const char *entity_name, int is_actor);
        bld_proc = (int (*)(const char *entity_name, int is_actor))GetProcAddress(blade, "ChangeEntityActor");
        return bld_proc(entity_name, is_actor);
}


int ChangeEntityPerson(const char *entity_name, int is_person)
{
        int (*bld_proc)(const char *entity_name, int is_person);
        bld_proc = (int (*)(const char *entity_name, int is_person))GetProcAddress(blade, "ChangeEntityPerson");
        return bld_proc(entity_name, is_person);
}


int ChangeEntityWeapon(const char *entity_name, int is_weapon)
{
        int (*bld_proc)(const char *entity_name, int is_weapon);
        bld_proc = (int (*)(const char *entity_name, int is_weapon))GetProcAddress(blade, "ChangeEntityWeapon");
        return bld_proc(entity_name, is_weapon);
}


int ChangeEntityArrow(const char *entity_name, int is_arrow)
{
        int (*bld_proc)(const char *entity_name, int is_arrow);
        bld_proc = (int (*)(const char *entity_name, int is_arrow))GetProcAddress(blade, "ChangeEntityArrow");
        return bld_proc(entity_name, is_arrow);
}


int SetNextAttack(
        const char *entity_name, const char *attack, int *res
)
{
        int (*bld_proc)(
        const char *entity_name, const char *attack, int *res
);
        bld_proc = (int (*)(
        const char *entity_name, const char *attack, int *res
))GetProcAddress(blade, "SetNextAttack");
        return bld_proc(entity_name, attack, res);
}


B_Entity *SeverLimb(const char *entity_name, int limb)
{
        B_Entity *(*bld_proc)(const char *entity_name, int limb);
        bld_proc = (B_Entity *(*)(const char *entity_name, int limb))GetProcAddress(blade, "SeverLimb");
        return bld_proc(entity_name, limb);
}

// TODO fix prototype
void SetCombatGroup()
{
        assert("SetCombatGroup" == NULL);
}


int SubscribeEntityToList(
        const char *entity_name, const char *timer_name
)
{
        int (*bld_proc)(
        const char *entity_name, const char *timer_name
);
        bld_proc = (int (*)(
        const char *entity_name, const char *timer_name
))GetProcAddress(blade, "SubscribeEntityToList");
        return bld_proc(entity_name, timer_name);
}


int MessageEvent(
        const char *entity_name, int message_type, int unknown1, int unknown2
)
{
        int (*bld_proc)(
        const char *entity_name, int message_type, int unknown1, int unknown2
);
        bld_proc = (int (*)(
        const char *entity_name, int message_type, int unknown1, int unknown2
))GetProcAddress(blade, "MessageEvent");
        return bld_proc(entity_name, message_type, unknown1, unknown2);
}


int InterruptCombat(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "InterruptCombat");
        return bld_proc(entity_name);
}


const char *GetParticleEntity(const char *entity_name)
{
        const char *(*bld_proc)(const char *entity_name);
        bld_proc = (const char *(*)(const char *entity_name))GetProcAddress(blade, "GetParticleEntity");
        return bld_proc(entity_name);
}


int Rel2AbsVector(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
)
{
        int (*bld_proc)(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
);
        bld_proc = (int (*)(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
))GetProcAddress(blade, "Rel2AbsVector");
        return bld_proc(entity_name, x_rel, y_rel, z_rel, x_abs, y_abs, z_abs);
}


int Rel2AbsPoint(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
)
{
        int (*bld_proc)(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
);
        bld_proc = (int (*)(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
))GetProcAddress(blade, "Rel2AbsPoint");
        return bld_proc(entity_name, x_rel, y_rel, z_rel, x_abs, y_abs, z_abs);
}


int Rel2AbsVectorN(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
)
{
        int (*bld_proc)(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
);
        bld_proc = (int (*)(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
))GetProcAddress(blade, "Rel2AbsVectorN");
        return bld_proc(entity_name, x_rel, y_rel, z_rel, anchor_name, x_abs, y_abs, z_abs);
}


int Rel2AbsPointN(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
)
{
        int (*bld_proc)(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
);
        bld_proc = (int (*)(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
))GetProcAddress(blade, "Rel2AbsPointN");
        return bld_proc(entity_name, x_rel, y_rel, z_rel, anchor_name, x_abs, y_abs, z_abs);
}


int Abs2RelVector(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
)
{
        int (*bld_proc)(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
);
        bld_proc = (int (*)(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
))GetProcAddress(blade, "Abs2RelVector");
        return bld_proc(entity_name, x_abs, y_abs, z_abs, x_rel, y_rel, z_rel);
}


int Abs2RelPoint(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
)
{
        int (*bld_proc)(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
);
        bld_proc = (int (*)(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
))GetProcAddress(blade, "Abs2RelPoint");
        return bld_proc(entity_name, x_abs, y_abs, z_abs, x_rel, y_rel, z_rel);
}


int Abs2RelVectorN(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
)
{
        int (*bld_proc)(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
);
        bld_proc = (int (*)(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
))GetProcAddress(blade, "Abs2RelVectorN");
        return bld_proc(entity_name, x_abs, y_abs, z_abs, anchor_name, x_rel, y_rel, z_rel);
}


int Abs2RelPointN(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
)
{
        int (*bld_proc)(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
);
        bld_proc = (int (*)(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
))GetProcAddress(blade, "Abs2RelPointN");
        return bld_proc(entity_name, x_abs, y_abs, z_abs, anchor_name, x_rel, y_rel, z_rel);
}


double SQDistance2(const char *entity_name1, const char *entity_name2)
{
        double (*bld_proc)(const char *entity_name1, const char *entity_name2);
        bld_proc = (double (*)(const char *entity_name1, const char *entity_name2))GetProcAddress(blade, "SQDistance2");
        return bld_proc(entity_name1, entity_name2);
}


int RemoveEntityFromList(
        const char *entity_name, const char *timer_name
)
{
        int (*bld_proc)(
        const char *entity_name, const char *timer_name
);
        bld_proc = (int (*)(
        const char *entity_name, const char *timer_name
))GetProcAddress(blade, "RemoveEntityFromList");
        return bld_proc(entity_name, timer_name);
}


int CreateTimer(const char *timer_name, double period)
{
        int (*bld_proc)(const char *timer_name, double period);
        bld_proc = (int (*)(const char *timer_name, double period))GetProcAddress(blade, "CreateTimer");
        return bld_proc(timer_name, period);
}


int GetnTimers(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetnTimers");
        return bld_proc();
}


int GetTimerInfo(
        int timer_index, const char **timer_name, double *period
)
{
        int (*bld_proc)(
        int timer_index, const char **timer_name, double *period
);
        bld_proc = (int (*)(
        int timer_index, const char **timer_name, double *period
))GetProcAddress(blade, "GetTimerInfo");
        return bld_proc(timer_index, timer_name, period);
}


int GetEntityIntProperty(
        const char *entity_name, int property_kind, int index, int *value
)
{
        int (*bld_proc)(
        const char *entity_name, int property_kind, int index, int *value
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index, int *value
))GetProcAddress(blade, "GetEntityIntProperty");
        return bld_proc(entity_name, property_kind, index, value);
}


int GetEntityFloatProperty(
        const char *entity_name, int property_kind, int index, double *value
)
{
        int (*bld_proc)(
        const char *entity_name, int property_kind, int index, double *value
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index, double *value
))GetProcAddress(blade, "GetEntityFloatProperty");
        return bld_proc(entity_name, property_kind, index, value);
}


int GetEntityStringProperty(
        const char *entity_name, int property_kind, int index,
        const char **value
)
{
        int (*bld_proc)(
        const char *entity_name, int property_kind, int index,
        const char **value
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index,
        const char **value
))GetProcAddress(blade, "GetEntityStringProperty");
        return bld_proc(entity_name, property_kind, index, value);
}


int GetEntityVectorProperty(
        const char *entity_name, int property_kind, int index,
        double *x, double *y, double *z
)
{
        int (*bld_proc)(
        const char *entity_name, int property_kind, int index,
        double *x, double *y, double *z
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index,
        double *x, double *y, double *z
))GetProcAddress(blade, "GetEntityVectorProperty");
        return bld_proc(entity_name, property_kind, index, x, y, z);
}


int GetEntityQuatProperty(
        const char *entity_name, int property_kind, int index, double *quat1,
        double *quat2, double *quat3, double *quat4
)
{
        int (*bld_proc)(
        const char *entity_name, int property_kind, int index, double *quat1,
        double *quat2, double *quat3, double *quat4
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index, double *quat1,
        double *quat2, double *quat3, double *quat4
))GetProcAddress(blade, "GetEntityQuatProperty");
        return bld_proc(entity_name, property_kind, index, quat1, quat2, quat3, quat4);
}


int GetEntityFuncProperty(
        const char *entity_name, int property_kind, int index, PyObject **func
)
{
        int (*bld_proc)(
        const char *entity_name, int property_kind, int index, PyObject **func
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index, PyObject **func
))GetProcAddress(blade, "GetEntityFuncProperty");
        return bld_proc(entity_name, property_kind, index, func);
}


int SetEntityIntProperty(
        const char *entity_name, int property_kind, int index, int value
)
{
        int (*bld_proc)(
        const char *entity_name, int property_kind, int index, int value
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index, int value
))GetProcAddress(blade, "SetEntityIntProperty");
        return bld_proc(entity_name, property_kind, index, value);
}


int SetEntityFloatProperty(
        const char *entity_name, int property_kind, int index, double value
)
{
        int (*bld_proc)(
        const char *entity_name, int property_kind, int index, double value
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index, double value
))GetProcAddress(blade, "SetEntityFloatProperty");
        return bld_proc(entity_name, property_kind, index, value);
}


int SetEntityStringProperty(
        const char *entity_name, int property_kind, int index,
        const char *value
)
{
        int (*bld_proc)(
        const char *entity_name, int property_kind, int index,
        const char *value
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index,
        const char *value
))GetProcAddress(blade, "SetEntityStringProperty");
        return bld_proc(entity_name, property_kind, index, value);
}


int SetEntityVectorProperty(
        const char *entity_name, int property_kind, int index,
        double x, double y, double z
)
{
        int (*bld_proc)(
        const char *entity_name, int property_kind, int index,
        double x, double y, double z
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index,
        double x, double y, double z
))GetProcAddress(blade, "SetEntityVectorProperty");
        return bld_proc(entity_name, property_kind, index, x, y, z);
}


int SetEntityQuatProperty(
        const char *entity_name, int property_kind, int index, double quat1,
        double quat2, double quat3, double quat4
)
{
        int (*bld_proc)(
        const char *entity_name, int property_kind, int index, double quat1,
        double quat2, double quat3, double quat4
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index, double quat1,
        double quat2, double quat3, double quat4
))GetProcAddress(blade, "SetEntityQuatProperty");
        return bld_proc(entity_name, property_kind, index, quat1, quat2, quat3, quat4);
}


int SetEntityData(const char *entity_name, PyObject *data)
{
        int (*bld_proc)(const char *entity_name, PyObject *data);
        bld_proc = (int (*)(const char *entity_name, PyObject *data))GetProcAddress(blade, "SetEntityData");
        return bld_proc(entity_name, data);
}


PyObject *GetEntityData(const char *entity_name)
{
        PyObject *(*bld_proc)(const char *entity_name);
        bld_proc = (PyObject *(*)(const char *entity_name))GetProcAddress(blade, "GetEntityData");
        return bld_proc(entity_name);
}


int SetEntityFuncProperty(
        const char *entity_name, int property_kind, int index, PyObject *func
)
{
        int (*bld_proc)(
        const char *entity_name, int property_kind, int index, PyObject *func
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index, PyObject *func
))GetProcAddress(blade, "SetEntityFuncProperty");
        return bld_proc(entity_name, property_kind, index, func);
}


int SetEntityInternalState(
        const char *entity_name, PyObject *internal_state
)
{
        int (*bld_proc)(
        const char *entity_name, PyObject *internal_state
);
        bld_proc = (int (*)(
        const char *entity_name, PyObject *internal_state
))GetProcAddress(blade, "SetEntityInternalState");
        return bld_proc(entity_name, internal_state);
}


int GetEntityInternalState(
        const char *entity_name, PyObject **internal_state
)
{
        int (*bld_proc)(
        const char *entity_name, PyObject **internal_state
);
        bld_proc = (int (*)(
        const char *entity_name, PyObject **internal_state
))GetProcAddress(blade, "GetEntityInternalState");
        return bld_proc(entity_name, internal_state);
}


int AddSoundAnim(
        const char *entity_name, const char *anm_event, double time, int soundID
)
{
        int (*bld_proc)(
        const char *entity_name, const char *anm_event, double time, int soundID
);
        bld_proc = (int (*)(
        const char *entity_name, const char *anm_event, double time, int soundID
))GetProcAddress(blade, "AddSoundAnim");
        return bld_proc(entity_name, anm_event, time, soundID);
}


int AddSoundEvent(
        const char *entity_name, const char *event, int soundID
)
{
        int (*bld_proc)(
        const char *entity_name, const char *event, int soundID
);
        bld_proc = (int (*)(
        const char *entity_name, const char *event, int soundID
))GetProcAddress(blade, "AddSoundEvent");
        return bld_proc(entity_name, event, soundID);
}


int AddScheduledFunc(
        double time, PyObject *func, PyObject *args, const char *name
)
{
        int (*bld_proc)(
        double time, PyObject *func, PyObject *args, const char *name
);
        bld_proc = (int (*)(
        double time, PyObject *func, PyObject *args, const char *name
))GetProcAddress(blade, "AddScheduledFunc");
        return bld_proc(time, func, args, name);
}


int RemoveScheduledFunc(const char *name)
{
        int (*bld_proc)(const char *name);
        bld_proc = (int (*)(const char *name))GetProcAddress(blade, "RemoveScheduledFunc");
        return bld_proc(name);
}


int GetnScheduledFuncs(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetnScheduledFuncs");
        return bld_proc();
}


int GetScheduledFunc(
        int index, PyObject **func, PyObject **args, const char **name,
        double *time
)
{
        int (*bld_proc)(
        int index, PyObject **func, PyObject **args, const char **name,
        double *time
);
        bld_proc = (int (*)(
        int index, PyObject **func, PyObject **args, const char **name,
        double *time
))GetProcAddress(blade, "GetScheduledFunc");
        return bld_proc(index, func, args, name, time);
}


int EntityRotate(
        const char *entity_name, double x_dir, double y_dir, double z_dir,
        double velocity, int unknown
)
{
        int (*bld_proc)(
        const char *entity_name, double x_dir, double y_dir, double z_dir,
        double velocity, int unknown
);
        bld_proc = (int (*)(
        const char *entity_name, double x_dir, double y_dir, double z_dir,
        double velocity, int unknown
))GetProcAddress(blade, "EntityRotate");
        return bld_proc(entity_name, x_dir, y_dir, z_dir, velocity, unknown);
}


int EntityRotateAbs(
        const char *entity_name, double x, double y, double z, double x_dir,
        double y_dir, double z_dir, double angle, int i_unknown
)
{
        int (*bld_proc)(
        const char *entity_name, double x, double y, double z, double x_dir,
        double y_dir, double z_dir, double angle, int i_unknown
);
        bld_proc = (int (*)(
        const char *entity_name, double x, double y, double z, double x_dir,
        double y_dir, double z_dir, double angle, int i_unknown
))GetProcAddress(blade, "EntityRotateAbs");
        return bld_proc(entity_name, x, y, z, x_dir, y_dir, z_dir, angle, i_unknown);
}


int EntityRotateRel(
        const char *entity_name, double x, double y, double z, double x_dir,
        double y_dir, double z_dir, double angle, int i_unknown
)
{
        int (*bld_proc)(
        const char *entity_name, double x, double y, double z, double x_dir,
        double y_dir, double z_dir, double angle, int i_unknown
);
        bld_proc = (int (*)(
        const char *entity_name, double x, double y, double z, double x_dir,
        double y_dir, double z_dir, double angle, int i_unknown
))GetProcAddress(blade, "EntityRotateRel");
        return bld_proc(entity_name, x, y, z, x_dir, y_dir, z_dir, angle, i_unknown);
}


int EntityMove(
        const char *entity_name, double x, double y, double z, int unknown
)
{
        int (*bld_proc)(
        const char *entity_name, double x, double y, double z, int unknown
);
        bld_proc = (int (*)(
        const char *entity_name, double x, double y, double z, int unknown
))GetProcAddress(blade, "EntityMove");
        return bld_proc(entity_name, x, y, z, unknown);
}


int EntitySetPosition(
        const char *entity_name, double x, double y, double z, int unknown
)
{
        int (*bld_proc)(
        const char *entity_name, double x, double y, double z, int unknown
);
        bld_proc = (int (*)(
        const char *entity_name, double x, double y, double z, int unknown
))GetProcAddress(blade, "EntitySetPosition");
        return bld_proc(entity_name, x, y, z, unknown);
}


int EntitySetOrientation(
        const char *entity_name, double quat1, double quat2, double quat3,
        double quat4, int unknown
)
{
        int (*bld_proc)(
        const char *entity_name, double quat1, double quat2, double quat3,
        double quat4, int unknown
);
        bld_proc = (int (*)(
        const char *entity_name, double quat1, double quat2, double quat3,
        double quat4, int unknown
))GetProcAddress(blade, "EntitySetOrientation");
        return bld_proc(entity_name, quat1, quat2, quat3, quat4, unknown);
}


int EntityPutToWorld(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "EntityPutToWorld");
        return bld_proc(entity_name);
}


int EntityAddAnmEventFunc(
        const char *entity_name, const char *anm_event, PyObject *func
)
{
        int (*bld_proc)(
        const char *entity_name, const char *anm_event, PyObject *func
);
        bld_proc = (int (*)(
        const char *entity_name, const char *anm_event, PyObject *func
))GetProcAddress(blade, "EntityAddAnmEventFunc");
        return bld_proc(entity_name, anm_event, func);
}


int EntityDelAnmEventFunc(
        const char *entity_name, const char *anm_event
)
{
        int (*bld_proc)(
        const char *entity_name, const char *anm_event
);
        bld_proc = (int (*)(
        const char *entity_name, const char *anm_event
))GetProcAddress(blade, "EntityDelAnmEventFunc");
        return bld_proc(entity_name, anm_event);
}


int EntityClearAnmEventFuncs(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "EntityClearAnmEventFuncs");
        return bld_proc(entity_name);
}


int ClearActorPath(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "ClearActorPath");
        return bld_proc(entity_name);
}


int AddActorPathnode(
        const char *entity_name, double time, double x, double y, double z
)
{
        int (*bld_proc)(
        const char *entity_name, double time, double x, double y, double z
);
        bld_proc = (int (*)(
        const char *entity_name, double time, double x, double y, double z
))GetProcAddress(blade, "AddActorPathnode");
        return bld_proc(entity_name, time, x, y, z);
}


int StartActorPath(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "StartActorPath");
        return bld_proc(entity_name);
}


int GoToActorPath(
        const char *entity_name, int i_unknown, double d_unknown
)
{
        int (*bld_proc)(
        const char *entity_name, int i_unknown, double d_unknown
);
        bld_proc = (int (*)(
        const char *entity_name, int i_unknown, double d_unknown
))GetProcAddress(blade, "GoToActorPath");
        return bld_proc(entity_name, i_unknown, d_unknown);
}


int TestPos(
        const char *entity_name, double x, double y, double z, double max_fall,
        int action_area, int *isCorrect
)
{
        int (*bld_proc)(
        const char *entity_name, double x, double y, double z, double max_fall,
        int action_area, int *isCorrect
);
        bld_proc = (int (*)(
        const char *entity_name, double x, double y, double z, double max_fall,
        int action_area, int *isCorrect
))GetProcAddress(blade, "TestPos");
        return bld_proc(entity_name, x, y, z, max_fall, action_area, isCorrect);
}


int TestPosInOwnBox(
        const char *entity_name, double x, double y, double z, double box_size,
        int *isCorrect
)
{
        int (*bld_proc)(
        const char *entity_name, double x, double y, double z, double box_size,
        int *isCorrect
);
        bld_proc = (int (*)(
        const char *entity_name, double x, double y, double z, double box_size,
        int *isCorrect
))GetProcAddress(blade, "TestPosInOwnBox");
        return bld_proc(entity_name, x, y, z, box_size, isCorrect);
}


int TurnOnActor(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "TurnOnActor");
        return bld_proc(entity_name);
}


int TurnOffActor(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "TurnOffActor");
        return bld_proc(entity_name);
}


int SetAttackList(const char *entity_name, PyObject *attack_list)
{
        int (*bld_proc)(const char *entity_name, PyObject *attack_list);
        bld_proc = (int (*)(const char *entity_name, PyObject *attack_list))GetProcAddress(blade, "SetAttackList");
        return bld_proc(entity_name, attack_list);
}


PyObject *GetAttackList(const char *entity_name)
{
        PyObject *(*bld_proc)(const char *entity_name);
        bld_proc = (PyObject *(*)(const char *entity_name))GetProcAddress(blade, "GetAttackList");
        return bld_proc(entity_name);
}


PyObject *GetGroupMembers(const char *entity_name)
{
        PyObject *(*bld_proc)(const char *entity_name);
        bld_proc = (PyObject *(*)(const char *entity_name))GetProcAddress(blade, "GetGroupMembers");
        return bld_proc(entity_name);
}


PyObject *GetCombatants(const char *entity_name)
{
        PyObject *(*bld_proc)(const char *entity_name);
        bld_proc = (PyObject *(*)(const char *entity_name))GetProcAddress(blade, "GetCombatants");
        return bld_proc(entity_name);
}


int SetActorNodeStartTangent(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
)
{
        int (*bld_proc)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
);
        bld_proc = (int (*)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
))GetProcAddress(blade, "SetActorNodeStartTangent");
        return bld_proc(entity_name, unknown1, unknown2, unknown3, unknown4);
}


int SetActorNodeEndTangent(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
)
{
        int (*bld_proc)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
);
        bld_proc = (int (*)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
))GetProcAddress(blade, "SetActorNodeEndTangent");
        return bld_proc(entity_name, unknown1, unknown2, unknown3, unknown4);
}


int SetSound(const char *entity_name, const char *sound)
{
        int (*bld_proc)(const char *entity_name, const char *sound);
        bld_proc = (int (*)(const char *entity_name, const char *sound))GetProcAddress(blade, "SetSound");
        return bld_proc(entity_name, sound);
}


int SetObjectSound(const char *entity_name, const char *sound)
{
        int (*bld_proc)(const char *entity_name, const char *sound);
        bld_proc = (int (*)(const char *entity_name, const char *sound))GetProcAddress(blade, "SetObjectSound");
        return bld_proc(entity_name, sound);
}


int PlayEntitySound(const char *entity_name, int i_unknown)
{
        int (*bld_proc)(const char *entity_name, int i_unknown);
        bld_proc = (int (*)(const char *entity_name, int i_unknown))GetProcAddress(blade, "PlayEntitySound");
        return bld_proc(entity_name, i_unknown);
}


int Stop(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "Stop");
        return bld_proc(entity_name);
}


int StopAt(const char *entity_name, double x, double y, double z)
{
        int (*bld_proc)(const char *entity_name, double x, double y, double z);
        bld_proc = (int (*)(const char *entity_name, double x, double y, double z))GetProcAddress(blade, "StopAt");
        return bld_proc(entity_name, x, y, z);
}


int CheckAnimCol(
        const char *entity_name, const char *anm_name, const char *obj_name,
        int unknown, int *res
)
{
        int (*bld_proc)(
        const char *entity_name, const char *anm_name, const char *obj_name,
        int unknown, int *res
);
        bld_proc = (int (*)(
        const char *entity_name, const char *anm_name, const char *obj_name,
        int unknown, int *res
))GetProcAddress(blade, "CheckAnimCol");
        return bld_proc(entity_name, anm_name, obj_name, unknown, res);
}


int RemoveFromInvent(const char *entity_name, const char *obj_name)
{
        int (*bld_proc)(const char *entity_name, const char *obj_name);
        bld_proc = (int (*)(const char *entity_name, const char *obj_name))GetProcAddress(blade, "RemoveFromInvent");
        return bld_proc(entity_name, obj_name);
}


int ResetWounds(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "ResetWounds");
        return bld_proc(entity_name);
}


int RemoveFromInventRight(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "RemoveFromInventRight");
        return bld_proc(entity_name);
}


int RemoveFromInventLeft(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "RemoveFromInventLeft");
        return bld_proc(entity_name);
}


int RemoveFromInventLeft2(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "RemoveFromInventLeft2");
        return bld_proc(entity_name);
}


int CanISee(
        const char *entity_name, const char *seen_entity_name, int *canISee
)
{
        int (*bld_proc)(
        const char *entity_name, const char *seen_entity_name, int *canISee
);
        bld_proc = (int (*)(
        const char *entity_name, const char *seen_entity_name, int *canISee
))GetProcAddress(blade, "CanISee");
        return bld_proc(entity_name, seen_entity_name, canISee);
}


int CanISeeFrom(
        const char *entity_name, const char *seen_entity_name,
        double x, double y, double z, int *canISee
)
{
        int (*bld_proc)(
        const char *entity_name, const char *seen_entity_name,
        double x, double y, double z, int *canISee
);
        bld_proc = (int (*)(
        const char *entity_name, const char *seen_entity_name,
        double x, double y, double z, int *canISee
))GetProcAddress(blade, "CanISeeFrom");
        return bld_proc(entity_name, seen_entity_name, x, y, z, canISee);
}


int SetActiveEnemy(
        const char *entity_name, const char *active_enemy_name, int *unknown
)
{
        int (*bld_proc)(
        const char *entity_name, const char *active_enemy_name, int *unknown
);
        bld_proc = (int (*)(
        const char *entity_name, const char *active_enemy_name, int *unknown
))GetProcAddress(blade, "SetActiveEnemy");
        return bld_proc(entity_name, active_enemy_name, unknown);
}


int ExcludeHitFor(
        const char *entity_name, const char *exclude_hit_for_name,
        void *unknown
)
{
        int (*bld_proc)(
        const char *entity_name, const char *exclude_hit_for_name,
        void *unknown
);
        bld_proc = (int (*)(
        const char *entity_name, const char *exclude_hit_for_name,
        void *unknown
))GetProcAddress(blade, "ExcludeHitFor");
        return bld_proc(entity_name, exclude_hit_for_name, unknown);
}


int ExcludeHitInAnimationFor(
        const char *entity_name, const char *exclude_hit_for_name, void *unknown
)
{
        int (*bld_proc)(
        const char *entity_name, const char *exclude_hit_for_name, void *unknown
);
        bld_proc = (int (*)(
        const char *entity_name, const char *exclude_hit_for_name, void *unknown
))GetProcAddress(blade, "ExcludeHitInAnimationFor");
        return bld_proc(entity_name, exclude_hit_for_name, unknown);
}


int Link(
        const char *entity_name, const char *child_entity_name, void *unknown
)
{
        int (*bld_proc)(
        const char *entity_name, const char *child_entity_name, void *unknown
);
        bld_proc = (int (*)(
        const char *entity_name, const char *child_entity_name, void *unknown
))GetProcAddress(blade, "Link");
        return bld_proc(entity_name, child_entity_name, unknown);
}


int LinkToNode(
        const char *entity_name, const char *child_name, int node_index,
        void *unknown
)
{
        int (*bld_proc)(
        const char *entity_name, const char *child_name, int node_index,
        void *unknown
);
        bld_proc = (int (*)(
        const char *entity_name, const char *child_name, int node_index,
        void *unknown
))GetProcAddress(blade, "LinkToNode");
        return bld_proc(entity_name, child_name, node_index, unknown);
}


int LinkAnchors(
        const char *entity_name, const char *entity_anchor_name,
        const char *child_name, const char *child_anchor_name, void *unknown
)
{
        int (*bld_proc)(
        const char *entity_name, const char *entity_anchor_name,
        const char *child_name, const char *child_anchor_name, void *unknown
);
        bld_proc = (int (*)(
        const char *entity_name, const char *entity_anchor_name,
        const char *child_name, const char *child_anchor_name, void *unknown
))GetProcAddress(blade, "LinkAnchors");
        return bld_proc(entity_name, entity_anchor_name, child_name, child_anchor_name, unknown);
}


int UnlinkChilds(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "UnlinkChilds");
        return bld_proc(entity_name);
}


int GetNodeIndex(
        const char *entity_name, const char *node_name, int *index
)
{
        int (*bld_proc)(
        const char *entity_name, const char *node_name, int *index
);
        bld_proc = (int (*)(
        const char *entity_name, const char *node_name, int *index
))GetProcAddress(blade, "GetNodeIndex");
        return bld_proc(entity_name, node_name, index);
}


int UnlinkChild(
        const char *entity_name, const char *child_entity_name, void *unknown
)
{
        int (*bld_proc)(
        const char *entity_name, const char *child_entity_name, void *unknown
);
        bld_proc = (int (*)(
        const char *entity_name, const char *child_entity_name, void *unknown
))GetProcAddress(blade, "UnlinkChild");
        return bld_proc(entity_name, child_entity_name, unknown);
}


int InsideActionArea(
        const char *entity_name, int action_area, int *is_inside
)
{
        int (*bld_proc)(
        const char *entity_name, int action_area, int *is_inside
);
        bld_proc = (int (*)(
        const char *entity_name, int action_area, int *is_inside
))GetProcAddress(blade, "InsideActionArea");
        return bld_proc(entity_name, action_area, is_inside);
}


int SetTmpAnmFlags(
        const char *entity_name, int wuea, int mod_y, int solf, int copy_rot,
        int bng_mov, int headf, int unknown
)
{
        int (*bld_proc)(
        const char *entity_name, int wuea, int mod_y, int solf, int copy_rot,
        int bng_mov, int headf, int unknown
);
        bld_proc = (int (*)(
        const char *entity_name, int wuea, int mod_y, int solf, int copy_rot,
        int bng_mov, int headf, int unknown
))GetProcAddress(blade, "SetTmpAnmFlags");
        return bld_proc(entity_name, wuea, mod_y, solf, copy_rot, bng_mov, headf, unknown);
}


int SetAnmFlags(
        const char *entity_name, const char *anm_name, int wuea, int mod_y,
        int solf, int copy_rot, int bng_mov, int headf
)
{
        int (*bld_proc)(
        const char *entity_name, const char *anm_name, int wuea, int mod_y,
        int solf, int copy_rot, int bng_mov, int headf
);
        bld_proc = (int (*)(
        const char *entity_name, const char *anm_name, int wuea, int mod_y,
        int solf, int copy_rot, int bng_mov, int headf
))GetProcAddress(blade, "SetAnmFlags");
        return bld_proc(entity_name, anm_name, wuea, mod_y, solf, copy_rot, bng_mov, headf);
}


int LaunchAnimation2(
        const char *entity_name, const char *anm_name1, const char *anm_name2
)
{
        int (*bld_proc)(
        const char *entity_name, const char *anm_name1, const char *anm_name2
);
        bld_proc = (int (*)(
        const char *entity_name, const char *anm_name1, const char *anm_name2
))GetProcAddress(blade, "LaunchAnimation2");
        return bld_proc(entity_name, anm_name1, anm_name2);
}


int SetEnemy(const char *entity_name, const char *enemy_name)
{
        int (*bld_proc)(const char *entity_name, const char *enemy_name);
        bld_proc = (int (*)(const char *entity_name, const char *enemy_name))GetProcAddress(blade, "SetEnemy");
        return bld_proc(entity_name, enemy_name);
}


const char *GetEnemy(const char *entity_name)
{
        const char *(*bld_proc)(const char *entity_name);
        bld_proc = (const char *(*)(const char *entity_name))GetProcAddress(blade, "GetEnemy");
        return bld_proc(entity_name);
}


int Chase(
        const char *entity_name, const char *enemy_name, int action_area
)
{
        int (*bld_proc)(
        const char *entity_name, const char *enemy_name, int action_area
);
        bld_proc = (int (*)(
        const char *entity_name, const char *enemy_name, int action_area
))GetProcAddress(blade, "Chase");
        return bld_proc(entity_name, enemy_name, action_area);
}


int ResetChase(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "ResetChase");
        return bld_proc(entity_name);
}


int GoTo(const char *entity_name, int x, int y, int z)
{
        int (*bld_proc)(const char *entity_name, int x, int y, int z);
        bld_proc = (int (*)(const char *entity_name, int x, int y, int z))GetProcAddress(blade, "GoTo");
        return bld_proc(entity_name, x, y, z);
}


int CanGoTo(const char *entity_name, int x, int y, int z)
{
        int (*bld_proc)(const char *entity_name, int x, int y, int z);
        bld_proc = (int (*)(const char *entity_name, int x, int y, int z))GetProcAddress(blade, "CanGoTo");
        return bld_proc(entity_name, x, y, z);
}


int QuickFace(const char *entity_name, double angle)
{
        int (*bld_proc)(const char *entity_name, double angle);
        bld_proc = (int (*)(const char *entity_name, double angle))GetProcAddress(blade, "QuickFace");
        return bld_proc(entity_name, angle);
}


int Face(const char *entity_name, double angle)
{
        int (*bld_proc)(const char *entity_name, double angle);
        bld_proc = (int (*)(const char *entity_name, double angle))GetProcAddress(blade, "Face");
        return bld_proc(entity_name, angle);
}


int StartLooking(const char *entity_name, int x, int y, int z)
{
        int (*bld_proc)(const char *entity_name, int x, int y, int z);
        bld_proc = (int (*)(const char *entity_name, int x, int y, int z))GetProcAddress(blade, "StartLooking");
        return bld_proc(entity_name, x, y, z);
}


int StopLooking(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "StopLooking");
        return bld_proc(entity_name);
}


int LookAtEntity(
        const char *entity_name, const char *look_at_entity_name
)
{
        int (*bld_proc)(
        const char *entity_name, const char *look_at_entity_name
);
        bld_proc = (int (*)(
        const char *entity_name, const char *look_at_entity_name
))GetProcAddress(blade, "LookAtEntity");
        return bld_proc(entity_name, look_at_entity_name);
}


int LaunchWatch(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "LaunchWatch");
        return bld_proc(entity_name);
}


int GetActionMode(const char *entity_name, int *action_mode)
{
        int (*bld_proc)(const char *entity_name, int *action_mode);
        bld_proc = (int (*)(const char *entity_name, int *action_mode))GetProcAddress(blade, "GetActionMode");
        return bld_proc(entity_name, action_mode);
}


int StartGrabbing(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "StartGrabbing");
        return bld_proc(entity_name);
}


int StopGrabbing(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "StopGrabbing");
        return bld_proc(entity_name);
}


int AddEntWatchAnim(const char *entity_name, const char *anm_name)
{
        int (*bld_proc)(const char *entity_name, const char *anm_name);
        bld_proc = (int (*)(const char *entity_name, const char *anm_name))GetProcAddress(blade, "AddEntWatchAnim");
        return bld_proc(entity_name, anm_name);
}


int Freeze(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "Freeze");
        return bld_proc(entity_name);
}


int UnFreeze(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "UnFreeze");
        return bld_proc(entity_name);
}


int SwitchTo1H(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "SwitchTo1H");
        return bld_proc(entity_name);
}


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
);
        bld_proc = (int (*)(
        const char *entity_name, const char *anchor_name, double x_dir,
        double y_dir, double z_dir, double *x_dummy_axis, double *y_dummy_axis,
        double *z_dummy_axis, int unknown
))GetProcAddress(blade, "GetDummyAxis");
        return bld_proc(entity_name, anchor_name, x_dir, y_dir, z_dir, x_dummy_axis, y_dummy_axis, z_dummy_axis, unknown);
}


int GraspPos(
        const char *entity_name, const char *grasp, double *x, double *y,
        double *z
)
{
        int (*bld_proc)(
        const char *entity_name, const char *grasp, double *x, double *y,
        double *z
);
        bld_proc = (int (*)(
        const char *entity_name, const char *grasp, double *x, double *y,
        double *z
))GetProcAddress(blade, "GraspPos");
        return bld_proc(entity_name, grasp, x, y, z);
}


int SwitchToBow(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "SwitchToBow");
        return bld_proc(entity_name);
}


int LaunchBayRoute(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "LaunchBayRoute");
        return bld_proc(entity_name);
}


int EntityCatchOnFire(
        const char *entity_name, double x, double y, double z
)
{
        int (*bld_proc)(
        const char *entity_name, double x, double y, double z
);
        bld_proc = (int (*)(
        const char *entity_name, double x, double y, double z
))GetProcAddress(blade, "EntityCatchOnFire");
        return bld_proc(entity_name, x, y, z);
}


int GetNChildren(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "GetNChildren");
        return bld_proc(entity_name);
}


const char *GetChild(const char *entity_name, int index)
{
        const char *(*bld_proc)(const char *entity_name, int index);
        bld_proc = (const char *(*)(const char *entity_name, int index))GetProcAddress(blade, "GetChild");
        return bld_proc(entity_name, index);
}


int CreateBipedData(const char *biped_name, const char *kind)
{
        int (*bld_proc)(const char *biped_name, const char *kind);
        bld_proc = (int (*)(const char *biped_name, const char *kind))GetProcAddress(blade, "CreateBipedData");
        return bld_proc(biped_name, kind);
}


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
);
        bld_proc = (int (*)(
        const char *char_name, const char *action_name,
        const char *animation_name, double d_unknown1, double d_unknown2,
        int i_unknown
))GetProcAddress(blade, "AddBipedAction");
        return bld_proc(char_name, action_name, animation_name, d_unknown1, d_unknown2, i_unknown);
}


int RemoveBipedAction(const char *s_unknown1, const char *s_unknown2)
{
        int (*bld_proc)(const char *s_unknown1, const char *s_unknown2);
        bld_proc = (int (*)(const char *s_unknown1, const char *s_unknown2))GetProcAddress(blade, "RemoveBipedAction");
        return bld_proc(s_unknown1, s_unknown2);
}


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
);
        bld_proc = (int (*)(
        const char *char_name, const char *action_name,
        const char *animation_name, const char *s_unknown, double d_unknown1,
        double d_unknown2, int i_unknown
))GetProcAddress(blade, "AddBipedActionC");
        return bld_proc(char_name, action_name, animation_name, s_unknown, d_unknown1, d_unknown2, i_unknown);
}


int SetActionEventTable(
        const char *race_name, const char *action_name, const char *table_name
)
{
        int (*bld_proc)(
        const char *race_name, const char *action_name, const char *table_name
);
        bld_proc = (int (*)(
        const char *race_name, const char *action_name, const char *table_name
))GetProcAddress(blade, "SetActionEventTable");
        return bld_proc(race_name, action_name, table_name);
}


int SetEventTableFuncC(
        const char *s_unknown1, const char *s_unknown2, const char *s_unknown3
)
{
        int (*bld_proc)(
        const char *s_unknown1, const char *s_unknown2, const char *s_unknown3
);
        bld_proc = (int (*)(
        const char *s_unknown1, const char *s_unknown2, const char *s_unknown3
))GetProcAddress(blade, "SetEventTableFuncC");
        return bld_proc(s_unknown1, s_unknown2, s_unknown3);
}


int SetEventTableFunc(
        const char *event_table_name, const char *event_type, PyObject *func
)
{
        int (*bld_proc)(
        const char *event_table_name, const char *event_type, PyObject *func
);
        bld_proc = (int (*)(
        const char *event_table_name, const char *event_type, PyObject *func
))GetProcAddress(blade, "SetEventTableFunc");
        return bld_proc(event_table_name, event_type, func);
}


int DoAction(const char *entity_name, const char *action_name)
{
        int (*bld_proc)(const char *entity_name, const char *action_name);
        bld_proc = (int (*)(const char *entity_name, const char *action_name))GetProcAddress(blade, "DoAction");
        return bld_proc(entity_name, action_name);
}


int DoActionWI(
        const char *entity_name, const char *action_name,
        int interpolation_type, double time, double unknown1
)
{
        int (*bld_proc)(
        const char *entity_name, const char *action_name,
        int interpolation_type, double time, double unknown1
);
        bld_proc = (int (*)(
        const char *entity_name, const char *action_name,
        int interpolation_type, double time, double unknown1
))GetProcAddress(blade, "DoActionWI");
        return bld_proc(entity_name, action_name, interpolation_type, time, unknown1);
}


int SetOnFloor(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "SetOnFloor");
        return bld_proc(entity_name);
}


int RaiseEvent(const char *entity_name, const char *event_name)
{
        int (*bld_proc)(const char *entity_name, const char *event_name);
        bld_proc = (int (*)(const char *entity_name, const char *event_name))GetProcAddress(blade, "RaiseEvent");
        return bld_proc(entity_name, event_name);
}


int SetSolidMask(const char *kind, int mask)
{
        int (*bld_proc)(const char *kind, int mask);
        bld_proc = (int (*)(const char *kind, int mask))GetProcAddress(blade, "SetSolidMask");
        return bld_proc(kind, mask);
}


int IsValidEntity(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "IsValidEntity");
        return bld_proc(entity_name);
}


void EntityRemoveFromWorld(const char *entity_name)
{
        void (*bld_proc)(const char *entity_name);
        bld_proc = (void (*)(const char *entity_name))GetProcAddress(blade, "EntityRemoveFromWorld");
        bld_proc(entity_name);
}


void EntityRemoveFromWorldWithChilds(const char *entity_name)
{
        void (*bld_proc)(const char *entity_name);
        bld_proc = (void (*)(const char *entity_name))GetProcAddress(blade, "EntityRemoveFromWorldWithChilds");
        bld_proc(entity_name);
}


int ImpulseC(
        const char *entity_name, double x, double y, double z, double x_vec,
        double y_vec, double z_vec
)
{
        int (*bld_proc)(
        const char *entity_name, double x, double y, double z, double x_vec,
        double y_vec, double z_vec
);
        bld_proc = (int (*)(
        const char *entity_name, double x, double y, double z, double x_vec,
        double y_vec, double z_vec
))GetProcAddress(blade, "ImpulseC");
        return bld_proc(entity_name, x, y, z, x_vec, y_vec, z_vec);
}


int SetAuraActive(const char *entity_name, int is_active)
{
        int (*bld_proc)(const char *entity_name, int is_active);
        bld_proc = (int (*)(const char *entity_name, int is_active))GetProcAddress(blade, "SetAuraActive");
        return bld_proc(entity_name, is_active);
}


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
);
        bld_proc = (int (*)(
        const char *entity_name, double size, double alpha,
        double colour_intensity, int hide_front_faces, int hide_back_faces,
        int alpha_mode
))GetProcAddress(blade, "SetAuraParams");
        return bld_proc(entity_name, size, alpha, colour_intensity, hide_front_faces, hide_back_faces, alpha_mode);
}


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
);
        bld_proc = (int (*)(
        const char *entity_name, int gap, double r1, double g1, double b1,
        double alpha1, double starting_point, double r2, double g2, double b2,
        double alpha2, double ending_point
))GetProcAddress(blade, "SetAuraGradient");
        return bld_proc(entity_name, gap, r1, g1, b1, alpha1, starting_point, r2, g2, b2, alpha2, ending_point);
}


void GetMouseState(int *invert, double *xsens, double *ysens)
{
        void (*bld_proc)(int *invert, double *xsens, double *ysens);
        bld_proc = (void (*)(int *invert, double *xsens, double *ysens))GetProcAddress(blade, "GetMouseState");
        bld_proc(invert, xsens, ysens);
}


void SetMouseState(int invert, double xsens, double ysens)
{
        void (*bld_proc)(int invert, double xsens, double ysens);
        bld_proc = (void (*)(int invert, double xsens, double ysens))GetProcAddress(blade, "SetMouseState");
        bld_proc(invert, xsens, ysens);
}


double GetPSeconds(void)
{
        double (*bld_proc)(void);
        bld_proc = (double (*)(void))GetProcAddress(blade, "GetPSeconds");
        return bld_proc();
}


void BodInspector(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "BodInspector");
        bld_proc();
}


void SaveScreeShoot(const char *filename, int width, int height)
{
        void (*bld_proc)(const char *filename, int width, int height);
        bld_proc = (void (*)(const char *filename, int width, int height))GetProcAddress(blade, "SaveScreeShoot");
        bld_proc(filename, width, height);
}


void CleanArea(double x, double y, double z, float distance)
{
        void (*bld_proc)(double x, double y, double z, float distance);
        bld_proc = (void (*)(double x, double y, double z, float distance))GetProcAddress(blade, "CleanArea");
        bld_proc(x, y, z, distance);
}


int GetCharByName(const char *name, const char *short_name)
{
        int (*bld_proc)(const char *name, const char *short_name);
        bld_proc = (int (*)(const char *name, const char *short_name))GetProcAddress(blade, "GetCharByName");
        return bld_proc(name, short_name);
}


int LoadAllAnimations(int charID)
{
        int (*bld_proc)(int charID);
        bld_proc = (int (*)(int charID))GetProcAddress(blade, "LoadAllAnimations");
        return bld_proc(charID);
}


int ChangeAnimation(
        int charID, const char *old_anm_name, const char *new_anm_name
)
{
        int (*bld_proc)(
        int charID, const char *old_anm_name, const char *new_anm_name
);
        bld_proc = (int (*)(
        int charID, const char *old_anm_name, const char *new_anm_name
))GetProcAddress(blade, "ChangeAnimation");
        return bld_proc(charID, old_anm_name, new_anm_name);
}


int SetAnmDefaultPrefix(int charID, const char *prefix)
{
        int (*bld_proc)(int charID, const char *prefix);
        bld_proc = (int (*)(int charID, const char *prefix))GetProcAddress(blade, "SetAnmDefaultPrefix");
        return bld_proc(charID, prefix);
}


int AddAttack(int charID, const char *attack_name, const char *anm_name)
{
        int (*bld_proc)(int charID, const char *attack_name, const char *anm_name);
        bld_proc = (int (*)(int charID, const char *attack_name, const char *anm_name))GetProcAddress(blade, "AddAttack");
        return bld_proc(charID, attack_name, anm_name);
}


int AttackWindow(
        int charID, const char *anm_name, float window1, float window2,
        const char *window_name
)
{
        int (*bld_proc)(
        int charID, const char *anm_name, float window1, float window2,
        const char *window_name
);
        bld_proc = (int (*)(
        int charID, const char *anm_name, float window1, float window2,
        const char *window_name
))GetProcAddress(blade, "AttackWindow");
        return bld_proc(charID, anm_name, window1, window2, window_name);
}


int AttackLevels(
        int charID, const char *anm_name, float level1, float level2
)
{
        int (*bld_proc)(
        int charID, const char *anm_name, float level1, float level2
);
        bld_proc = (int (*)(
        int charID, const char *anm_name, float level1, float level2
))GetProcAddress(blade, "AttackLevels");
        return bld_proc(charID, anm_name, level1, level2);
}


int AttackEnergyLevel(
        int charID, const char *anm_name, float  level
)
{
        int (*bld_proc)(
        int charID, const char *anm_name, float  level
);
        bld_proc = (int (*)(
        int charID, const char *anm_name, float  level
))GetProcAddress(blade, "AttackEnergyLevel");
        return bld_proc(charID, anm_name, level);
}

// TODO fix prototype
void ForwardsOffset()
{
        assert("ForwardsOffset" == NULL);
}


int AttackTypeFlag(int charID, const char *attack_name, int flag)
{
        int (*bld_proc)(int charID, const char *attack_name, int flag);
        bld_proc = (int (*)(int charID, const char *attack_name, int flag))GetProcAddress(blade, "AttackTypeFlag");
        return bld_proc(charID, attack_name, flag);
}


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
);
        bld_proc = (int (*)(
        int charID, const char *attack_name, const char *keys,
        const char *previous, const char *previous_negative,
        const char *window_name, const char *weapon_kind
))GetProcAddress(blade, "AllowAttack");
        return bld_proc(charID, attack_name, keys, previous, previous_negative, window_name, weapon_kind);
}


int MetaAttack(
        int charID, const char *meta_attack_name, const char *attack_name
)
{
        int (*bld_proc)(
        int charID, const char *meta_attack_name, const char *attack_name
);
        bld_proc = (int (*)(
        int charID, const char *meta_attack_name, const char *attack_name
))GetProcAddress(blade, "MetaAttack");
        return bld_proc(charID, meta_attack_name, attack_name);
}


int AssignTrail(
        int charID, const char *attack_name, const char *unknown,
        const char *trail_name
)
{
        int (*bld_proc)(
        int charID, const char *attack_name, const char *unknown,
        const char *trail_name
);
        bld_proc = (int (*)(
        int charID, const char *attack_name, const char *unknown,
        const char *trail_name
))GetProcAddress(blade, "AssignTrail");
        return bld_proc(charID, attack_name, unknown, trail_name);
}


int SetNCDSpheres(int charID, int NCDSpheres)
{
        int (*bld_proc)(int charID, int NCDSpheres);
        bld_proc = (int (*)(int charID, int NCDSpheres))GetProcAddress(blade, "SetNCDSpheres");
        return bld_proc(charID, NCDSpheres);
}


int SetCDSphere(int charID, int index, double h, double r)
{
        int (*bld_proc)(int charID, int index, double h, double r);
        bld_proc = (int (*)(int charID, int index, double h, double r))GetProcAddress(blade, "SetCDSphere");
        return bld_proc(charID, index, h, r);
}


int GetCharIntProperty(int charID, int property_kind, int index, int *value)
{
        int (*bld_proc)(int charID, int property_kind, int index, int *value);
        bld_proc = (int (*)(int charID, int property_kind, int index, int *value))GetProcAddress(blade, "GetCharIntProperty");
        return bld_proc(charID, property_kind, index, value);
}


int SetCharIntProperty(int charID, int property_kind, int index, int value)
{
        int (*bld_proc)(int charID, int property_kind, int index, int value);
        bld_proc = (int (*)(int charID, int property_kind, int index, int value))GetProcAddress(blade, "SetCharIntProperty");
        return bld_proc(charID, property_kind, index, value);
}


int GetCharFloatProperty(int charID, int property_kind, int index, double *value)
{
        int (*bld_proc)(int charID, int property_kind, int index, double *value);
        bld_proc = (int (*)(int charID, int property_kind, int index, double *value))GetProcAddress(blade, "GetCharFloatProperty");
        return bld_proc(charID, property_kind, index, value);
}


int SetCharFloatProperty(int charID, int property_kind, int index, double value)
{
        int (*bld_proc)(int charID, int property_kind, int index, double value);
        bld_proc = (int (*)(int charID, int property_kind, int index, double value))GetProcAddress(blade, "SetCharFloatProperty");
        return bld_proc(charID, property_kind, index, value);
}


int GetCharStringProperty(int charID, int property_kind, int index, const char **value)
{
        int (*bld_proc)(int charID, int property_kind, int index, const char **value);
        bld_proc = (int (*)(int charID, int property_kind, int index, const char **value))GetProcAddress(blade, "GetCharStringProperty");
        return bld_proc(charID, property_kind, index, value);
}


int SetCharStringProperty(int charID, int property_kind, int index, const char *value)
{
        int (*bld_proc)(int charID, int property_kind, int index, const char *value);
        bld_proc = (int (*)(int charID, int property_kind, int index, const char *value))GetProcAddress(blade, "SetCharStringProperty");
        return bld_proc(charID, property_kind, index, value);
}


int SetCharFuncProperty(int charID, int property_kind, int index, PyObject *func)
{
        int (*bld_proc)(int charID, int property_kind, int index, PyObject *func);
        bld_proc = (int (*)(int charID, int property_kind, int index, PyObject *func))GetProcAddress(blade, "SetCharFuncProperty");
        return bld_proc(charID, property_kind, index, func);
}


int GetTrailByName(const char *name)
{
        int (*bld_proc)(const char *name);
        bld_proc = (int (*)(const char *name))GetProcAddress(blade, "GetTrailByName");
        return bld_proc(name);
}

// TODO fix prototype
void GetTrailIntProperty()
{
        assert("GetTrailIntProperty" == NULL);
}

// TODO fix prototype
void SetTrailIntProperty()
{
        assert("SetTrailIntProperty" == NULL);
}


int GetTrailFloatProperty(
        int trailID, int property_kind, int index, double *value
)
{
        int (*bld_proc)(
        int trailID, int property_kind, int index, double *value
);
        bld_proc = (int (*)(
        int trailID, int property_kind, int index, double *value
))GetProcAddress(blade, "GetTrailFloatProperty");
        return bld_proc(trailID, property_kind, index, value);
}


int SetTrailFloatProperty(
        int trailID, int property_kind, int index, double value
)
{
        int (*bld_proc)(
        int trailID, int property_kind, int index, double value
);
        bld_proc = (int (*)(
        int trailID, int property_kind, int index, double value
))GetProcAddress(blade, "SetTrailFloatProperty");
        return bld_proc(trailID, property_kind, index, value);
}

// TODO fix prototype
void GetTrailStringProperty()
{
        assert("GetTrailStringProperty" == NULL);
}


int GetTrailVectorProperty(
        int trailID, int property_kind, int index,
        double *x, double *y, double *z
)
{
        int (*bld_proc)(
        int trailID, int property_kind, int index,
        double *x, double *y, double *z
);
        bld_proc = (int (*)(
        int trailID, int property_kind, int index,
        double *x, double *y, double *z
))GetProcAddress(blade, "GetTrailVectorProperty");
        return bld_proc(trailID, property_kind, index, x, y, z);
}

// TODO fix prototype
void SetTrailFuncProperty()
{
        assert("SetTrailFuncProperty" == NULL);
}


int SetTrailVectorProperty(
        int trailID, int property_kind, int index, double x, double y, double z
)
{
        int (*bld_proc)(
        int trailID, int property_kind, int index, double x, double y, double z
);
        bld_proc = (int (*)(
        int trailID, int property_kind, int index, double x, double y, double z
))GetProcAddress(blade, "SetTrailVectorProperty");
        return bld_proc(trailID, property_kind, index, x, y, z);
}

// TODO fix prototype
void GetInventory()
{
        assert("GetInventory" == NULL);
}

// TODO fix prototype
void GetInventoryFloatProperty()
{
        assert("GetInventoryFloatProperty" == NULL);
}

// TODO fix prototype
void SetInventoryFloatProperty()
{
        assert("SetInventoryFloatProperty" == NULL);
}


int GetInventoryStringProperty(
	const char *name, int property_kind, const char **value
)
{
        int (*bld_proc)(
	const char *name, int property_kind, const char **value
);
        bld_proc = (int (*)(
	const char *name, int property_kind, const char **value
))GetProcAddress(blade, "GetInventoryStringProperty");
        return bld_proc(name, property_kind, value);
}

// TODO fix prototype
void SetInventoryStringProperty()
{
        assert("SetInventoryStringProperty" == NULL);
}


int GetInventoryIntProperty(
        const char *name, int property_kind, int *value
)
{
        int (*bld_proc)(
        const char *name, int property_kind, int *value
);
        bld_proc = (int (*)(
        const char *name, int property_kind, int *value
))GetProcAddress(blade, "GetInventoryIntProperty");
        return bld_proc(name, property_kind, value);
}


int SetInventoryIntProperty(
        const char *name, int property_kind, int value
)
{
        int (*bld_proc)(
        const char *name, int property_kind, int value
);
        bld_proc = (int (*)(
        const char *name, int property_kind, int value
))GetProcAddress(blade, "SetInventoryIntProperty");
        return bld_proc(name, property_kind, value);
}


int LinkRightHand(const char *inv_name, const char *obj_name)
{
        int (*bld_proc)(const char *inv_name, const char *obj_name);
        bld_proc = (int (*)(const char *inv_name, const char *obj_name))GetProcAddress(blade, "LinkRightHand");
        return bld_proc(inv_name, obj_name);
}


int LinkLeftHand(const char *inv_name, const char *obj_name)
{
        int (*bld_proc)(const char *inv_name, const char *obj_name);
        bld_proc = (int (*)(const char *inv_name, const char *obj_name))GetProcAddress(blade, "LinkLeftHand");
        return bld_proc(inv_name, obj_name);
}


int LinkLeftHand2(const char *inv_name, const char *obj_name)
{
        int (*bld_proc)(const char *inv_name, const char *obj_name);
        bld_proc = (int (*)(const char *inv_name, const char *obj_name))GetProcAddress(blade, "LinkLeftHand2");
        return bld_proc(inv_name, obj_name);
}


int LinkRightBack(const char *inv_name, const char *obj_name)
{
        int (*bld_proc)(const char *inv_name, const char *obj_name);
        bld_proc = (int (*)(const char *inv_name, const char *obj_name))GetProcAddress(blade, "LinkRightBack");
        return bld_proc(inv_name, obj_name);
}


int LinkLeftBack(const char *inv_name, const char *obj_name)
{
        int (*bld_proc)(const char *inv_name, const char *obj_name);
        bld_proc = (int (*)(const char *inv_name, const char *obj_name))GetProcAddress(blade, "LinkLeftBack");
        return bld_proc(inv_name, obj_name);
}


int LinkBack(const char *inv_name, const char *obj_name)
{
        int (*bld_proc)(const char *inv_name, const char *obj_name);
        bld_proc = (int (*)(const char *inv_name, const char *obj_name))GetProcAddress(blade, "LinkBack");
        return bld_proc(inv_name, obj_name);
}


int SetCurrentQuiver(const char *inv_name, const char *quiver_name)
{
        int (*bld_proc)(const char *inv_name, const char *quiver_name);
        bld_proc = (int (*)(const char *inv_name, const char *quiver_name))GetProcAddress(blade, "SetCurrentQuiver");
        return bld_proc(inv_name, quiver_name);
}


int AddWeapon(const char *inv_name, int flag, const char *weapon_name)
{
        int (*bld_proc)(const char *inv_name, int flag, const char *weapon_name);
        bld_proc = (int (*)(const char *inv_name, int flag, const char *weapon_name))GetProcAddress(blade, "AddWeapon");
        return bld_proc(inv_name, flag, weapon_name);
}


int AddObject(
        const char *inv_name, int obj_type, int unknown, const char *obj_name
)
{
        int (*bld_proc)(
        const char *inv_name, int obj_type, int unknown, const char *obj_name
);
        bld_proc = (int (*)(
        const char *inv_name, int obj_type, int unknown, const char *obj_name
))GetProcAddress(blade, "AddObject");
        return bld_proc(inv_name, obj_type, unknown, obj_name);
}


int RemoveObject(
        const char *inv_name, int obj_type, const char *obj_name
)
{
        int (*bld_proc)(
        const char *inv_name, int obj_type, const char *obj_name
);
        bld_proc = (int (*)(
        const char *inv_name, int obj_type, const char *obj_name
))GetProcAddress(blade, "RemoveObject");
        return bld_proc(inv_name, obj_type, obj_name);
}


const char *GetObject(const char *inv_name, int obj_type, int index)
{
        const char *(*bld_proc)(const char *inv_name, int obj_type, int index);
        bld_proc = (const char *(*)(const char *inv_name, int obj_type, int index))GetProcAddress(blade, "GetObject");
        return bld_proc(inv_name, obj_type, index);
}


const char *GetObjectByName(
        const char *inv_name, int obj_type, const char *obj_name
)
{
        const char *(*bld_proc)(
        const char *inv_name, int obj_type, const char *obj_name
);
        bld_proc = (const char *(*)(
        const char *inv_name, int obj_type, const char *obj_name
))GetProcAddress(blade, "GetObjectByName");
        return bld_proc(inv_name, obj_type, obj_name);
}


const char *GetRightBack(const char *inv_name)
{
        const char *(*bld_proc)(const char *inv_name);
        bld_proc = (const char *(*)(const char *inv_name))GetProcAddress(blade, "GetRightBack");
        return bld_proc(inv_name);
}


const char *GetLeftBack(const char *inv_name)
{
        const char *(*bld_proc)(const char *inv_name);
        bld_proc = (const char *(*)(const char *inv_name))GetProcAddress(blade, "GetLeftBack");
        return bld_proc(inv_name);
}


const char *GetSelectedObject(const char *inv_name, int obj_type)
{
        const char *(*bld_proc)(const char *inv_name, int obj_type);
        bld_proc = (const char *(*)(const char *inv_name, int obj_type))GetProcAddress(blade, "GetSelectedObject");
        return bld_proc(inv_name, obj_type);
}


const char *GetActiveShield(const char *inv_name)
{
        const char *(*bld_proc)(const char *inv_name);
        bld_proc = (const char *(*)(const char *inv_name))GetProcAddress(blade, "GetActiveShield");
        return bld_proc(inv_name);
}


const char *GetActiveWeapon(const char *inv_name)
{
        const char *(*bld_proc)(const char *inv_name);
        bld_proc = (const char *(*)(const char *inv_name))GetProcAddress(blade, "GetActiveWeapon");
        return bld_proc(inv_name);
}

// TODO fix prototype
void ActiveWeaponActive()
{
        assert("ActiveWeaponActive" == NULL);
}


const char *GetActiveQuiver(const char *inv_name)
{
        const char *(*bld_proc)(const char *inv_name);
        bld_proc = (const char *(*)(const char *inv_name))GetProcAddress(blade, "GetActiveQuiver");
        return bld_proc(inv_name);
}


void Cycle(const char *inv_name, int obj_type)
{
        void (*bld_proc)(const char *inv_name, int obj_type);
        bld_proc = (void (*)(const char *inv_name, int obj_type))GetProcAddress(blade, "Cycle");
        bld_proc(inv_name, obj_type);
}


int GetNumberObjectsAt(const char *inv_name, int obj_type, int index)
{
        int (*bld_proc)(const char *inv_name, int obj_type, int index);
        bld_proc = (int (*)(const char *inv_name, int obj_type, int index))GetProcAddress(blade, "GetNumberObjectsAt");
        return bld_proc(inv_name, obj_type, index);
}


int GetMaxNumberObjectsAt(
        const char *inv_name, int obj_type, int index
)
{
        int (*bld_proc)(
        const char *inv_name, int obj_type, int index
);
        bld_proc = (int (*)(
        const char *inv_name, int obj_type, int index
))GetProcAddress(blade, "GetMaxNumberObjectsAt");
        return bld_proc(inv_name, obj_type, index);
}


int IsSelected(const char *inv_name, int obj_type, int obj_index)
{
        int (*bld_proc)(const char *inv_name, int obj_type, int obj_index);
        bld_proc = (int (*)(const char *inv_name, int obj_type, int obj_index))GetProcAddress(blade, "IsSelected");
        return bld_proc(inv_name, obj_type, obj_index);
}


int CarringObject(const char *inv_name, const char *obj_name)
{
        int (*bld_proc)(const char *inv_name, const char *obj_name);
        bld_proc = (int (*)(const char *inv_name, const char *obj_name))GetProcAddress(blade, "CarringObject");
        return bld_proc(inv_name, obj_name);
}


int LoadWorld(const char *file_name)
{
        int (*bld_proc)(const char *);
        bld_proc = (int (*)(const char *))GetProcAddress(blade, "LoadWorld");
        return bld_proc(file_name);
}

int SetListenerMode(int mode, double x, double y, double z)
{
        int (*bld_proc)(int mode, double x, double y, double z);
        bld_proc = (int (*)(int mode, double x, double y, double z))GetProcAddress(blade, "SetListenerMode");
        return bld_proc(mode, x, y, z);
}

int Quit(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "Quit");
        return bld_proc();
}

int SetTime(double time)
{
        int (*bld_proc)(double time);
        bld_proc = (int (*)(double time))GetProcAddress(blade, "SetTime");
        return bld_proc(time);
}

int GoToTime(double time)
{
        int (*bld_proc)(double time);
        bld_proc = (int (*)(double time))GetProcAddress(blade, "GoToTime");
        return bld_proc(time);
}

int BindPred(const char *action_name, const char *predproc)
{
        int (*bld_proc)(const char *action_name, const char *predproc);
        bld_proc = (int (*)(const char *action_name, const char *predproc))GetProcAddress(blade, "BindPred");
        return bld_proc(action_name, predproc);
}

const char *GetWorldFileName(void)
{
        const char * (*bld_proc)(void);
        bld_proc = (const char * (*)(void))GetProcAddress(blade, "GetWorldFileName");
        return bld_proc();
}

void SetGameSpySupport()
{
        assert("SetGameSpySupport" == NULL);
}

void GetGameSpySupport()
{
        assert("GetGameSpySupport" == NULL);
}

void StartGSQR(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "StartGSQR");
        bld_proc();
}

void EndGSQR()
{
        assert("EndGSQR" == NULL);
}

void LoopGSQR()
{
        assert("LoopGSQR" == NULL);
}

void PersonChangeAnmSoundIndex(const char *person_name, int index)
{
        void (*bld_proc)(const char *person_name, int index);
        bld_proc = (void (*)(const char *person_name, int index))GetProcAddress(blade, "PersonChangeAnmSoundIndex");
        bld_proc(person_name, index);
}

void SetDedicatedServerState(int dedicated)
{
        void (*bld_proc)(int dedicated);
        bld_proc = (void (*)(int dedicated))GetProcAddress(blade, "SetDedicatedServerState");
        bld_proc(dedicated);
}

int GetDedicatedServerState(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetDedicatedServerState");
        return bld_proc();
}

void SetLocalOptions(
        const char *name, const char *kind, const char *weapon,
        const char *shield, const char *map
)
{
        void (*bld_proc)(
        const char *name, const char *kind, const char *weapon,
        const char *shield, const char *map
);
        bld_proc = (void (*)(
        const char *name, const char *kind, const char *weapon,
        const char *shield, const char *map
))GetProcAddress(blade, "SetLocalOptions");
        bld_proc(name, kind, weapon, shield, map);
}

const char *ServerInfoBlock(void)
{
        const char *(*bld_proc)(void);
        bld_proc = (const char *(*)(void))GetProcAddress(blade, "ServerInfoBlock");
        return bld_proc();
}

void ClientSetPyClientSoundFunc(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ClientSetPyClientSoundFunc");
        bld_proc(func);
}

void CallNetEventSound(const char *entity_name, byte id)
{
        void (*bld_proc)(const char *entity_name, byte id);
        bld_proc = (void (*)(const char *entity_name, byte id))GetProcAddress(blade, "CallNetEventSound");
        bld_proc(entity_name, id);
}


void ClientSetPyClientMutilaFunc(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ClientSetPyClientMutilaFunc");
        bld_proc(func);
}

void ClientSetPyClientDamageFunc(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ClientSetPyClientDamageFunc");
        bld_proc(func);
}

void NetAddSoundToClient(
        const char *entity_name, const char *animation_name,
        PyObject *sound_object
)
{
        void (*bld_proc)(
        const char *entity_name, const char *animation_name,
        PyObject *sound_object
);
        bld_proc = (void (*)(
        const char *entity_name, const char *animation_name,
        PyObject *sound_object
))GetProcAddress(blade, "NetAddSoundToClient");
        bld_proc(entity_name, animation_name, sound_object);
}

const char *NetGetClientId(void)
{
        const char *(*bld_proc)(void);
        bld_proc = (const char *(*)(void))GetProcAddress(blade, "NetGetClientId");
        return bld_proc();
}


boolean NetSetObjectState(const char *entity_name, boolean state)
{
        boolean (*bld_proc)(const char *entity_name, boolean state);
        bld_proc = (boolean (*)(const char *entity_name, boolean state))GetProcAddress(blade, "NetSetObjectState");
        return bld_proc(entity_name, state);
}

void NetAddEventUserFunc(
        const char *action, PyObject *func, int ignore_host
)
{
        void (*bld_proc)(
        const char *action, PyObject *func, int ignore_host
);
        bld_proc = (void (*)(
        const char *action, PyObject *func, int ignore_host
))GetProcAddress(blade, "NetAddEventUserFunc");
        bld_proc(action, func, ignore_host);
}

void NetAddPosition(double x, double y, double z)
{
        void (*bld_proc)(double x, double y, double z);
        bld_proc = (void (*)(double x, double y, double z))GetProcAddress(blade, "NetAddPosition");
        bld_proc(x, y, z);
}

void NetSetPersonView(const char *entity_name)
{
        void (*bld_proc)(const char *entity_name);
        bld_proc = (void (*)(const char *entity_name))GetProcAddress(blade, "NetSetPersonView");
        bld_proc(entity_name);
}

void GetLocalOptionsNet(
        const char **name, const char **kind, const char **weapon,
        const char **shield
)
{
        void (*bld_proc)(
        const char **name, const char **kind, const char **weapon,
        const char **shield
);
        bld_proc = (void (*)(
        const char **name, const char **kind, const char **weapon,
        const char **shield
))GetProcAddress(blade, "GetLocalOptionsNet");
        bld_proc(name, kind, weapon, shield);
}

void GetNextPosition(double *x, double *y, double *z)
{
        void (*bld_proc)(double *x, double *y, double *z);
        bld_proc = (void (*)(double *x, double *y, double *z))GetProcAddress(blade, "GetNextPosition");
        bld_proc(x, y, z);
}

void ServerSetPyByePlayerFunc(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ServerSetPyByePlayerFunc");
        bld_proc(func);
}

void ServerSetPyGetUserString(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ServerSetPyGetUserString");
        bld_proc(func);
}

void SendNetUserString(
        short kind, const char *str, int guaranteed, const char *str_unknown
)
{
        void (*bld_proc)(
        short kind, const char *str, int guaranteed, const char *str_unknown
);
        bld_proc = (void (*)(
        short kind, const char *str, int guaranteed, const char *str_unknown
))GetProcAddress(blade, "SendNetUserString");
        bld_proc(kind, str, guaranteed, str_unknown);
}

void GetLifeAndLevel(const char *entity_name, int *energy, int *life)
{
        void (*bld_proc)(const char *entity_name, int *energy, int *life);
        bld_proc = (void (*)(const char *entity_name, int *energy, int *life))GetProcAddress(blade, "GetLifeAndLevel");
        bld_proc(entity_name, energy, life);
}

void ServerSetPyCreatePlayerFunc(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ServerSetPyCreatePlayerFunc");
        bld_proc(func);
}

boolean ClientStartMainChar(void)
{
        boolean (*bld_proc)(void);
        bld_proc = (boolean (*)(void))GetProcAddress(blade, "ClientStartMainChar");
        return bld_proc();
}

int ServerSetSendDataState(int state)
{
        int (*bld_proc)(int state);
        bld_proc = (int (*)(int state))GetProcAddress(blade, "ServerSetSendDataState");
        return bld_proc(state);
}


int GetNetState(void)
{
        int (*bld_proc)();
        bld_proc = (int (*)())GetProcAddress(blade, "GetNetState");
        return bld_proc();
}

void ClearPools(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "ClearPools");
        bld_proc();
}

boolean StartServer(
        const char *game_name, const char *player_name, int max_players,
        boolean TCP
)
{
        boolean (*bld_proc)(const char *game_name, const char *player_name, int max_players,
            boolean TCP);
        bld_proc = (boolean (*)(const char *game_name, const char *player_name, int max_players,
            boolean TCP))GetProcAddress(blade, "StartServer");
        return bld_proc(game_name,player_name, max_players, TCP);
}

boolean BrowseSessions(const char *ip_address)
{
        boolean (*bld_proc)(const char *ip_address);
        bld_proc = (boolean (*)(const char *ip_address))GetProcAddress(blade, "BrowseSessions");
        return bld_proc(ip_address);
}

boolean GetBrowseResult(int index, bld_server_info *info)
{
        boolean (*bld_proc)(int index, bld_server_info *info);
        bld_proc = (boolean (*)(int index, bld_server_info *info))GetProcAddress(blade, "GetBrowseResult");
        return bld_proc(index, info);
}

boolean JoinSession(int index, const char *player_name)
{
        boolean (*bld_proc)(int index, const char *player_name);
        bld_proc = (boolean (*)(int index, const char *player_name))GetProcAddress(blade, "JoinSession");
        return bld_proc(index, player_name);
}


void RestartNet(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "RestartNet");
        bld_proc();
}

void NetServerChangeLevel(const char *level_name)
{
        void (*bld_proc)(const char *level_name);
        bld_proc = (void (*)(const char *level_name))GetProcAddress(blade, "NetServerChangeLevel");
        bld_proc(level_name);
}


float NetGetTime(void)
{
        float (*bld_proc)(void);
        bld_proc = (float (*)(void))GetProcAddress(blade, "NetGetTime");
        return bld_proc();
}

int NetSetPPS(int PPS)
{
        int (*bld_proc)(int PPS);
        bld_proc = (int (*)(int PPS))GetProcAddress(blade, "NetSetPPS");
        return bld_proc(PPS);
}

int IsValidProtocol(int protocol)
{
        int (*bld_proc)(int protocol);
        bld_proc = (int (*)(int protocol))GetProcAddress(blade, "IsValidProtocol");
        return bld_proc(protocol);
}

