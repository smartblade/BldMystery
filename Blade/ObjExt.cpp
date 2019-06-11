
#include <bld_system.h>
#include <bld_python.h>
#include "App.h"
#include "bld_misc_funcs.h"
#define BUILD_LIB
#include <blade_ext.h>


/*
* Module:                 Blade.exe
* Entry point:            0x00427880
*/

int SetAppMode(const char *mode)
{
    B_App * App = get_application();
    int code;
    assert(App);
    code = App->SetAppMode(mode);
    return code;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004278D5
*/

const char *GetAppMode()
{
    B_App * App = get_application();
    assert(App);
    return App->GetAppMode().String();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427910
*/

void BeginLoadGame()
{
    B_App * App = get_application();
    assert(App);
    App->BeginLoadGame();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427943
*/

void DoneLoadGame()
{
    B_App * App = get_application();
    assert(App);
    App->DoneLoadGame();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427976
*/

int SetSaveInfo(PyObject *info)
{
    int saveInfoFlag;
    PyObject *data;
    int nextEntitySuffix;
    if (!PyArg_ParseTuple(info, "iO", &saveInfoFlag, &data))
        return 0;
    if (saveInfoFlag != 1)
        return 0;
    if (!PyArg_ParseTuple(data, "i", &nextEntitySuffix))
        return 0;
    gbl_game_state.nextEntitySuffix = nextEntitySuffix;
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004279E1
*/

PyObject *GetSaveInfo()
{
    PyObject *info;
    int nextEntitySuffix;
    nextEntitySuffix = gbl_game_state.nextEntitySuffix;
    info = Py_BuildValue("(i,(i))", 1, nextEntitySuffix);
    return info;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427A0D
*/

int SaveEntitiesData(const char *filename)
{
    return gbl_game_state.SaveEntitiesData(filename);
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427A20
*/

int LoadEntitiesData(const char *filename)
{
    return gbl_game_state.LoadEntitiesData(filename);
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427A33
*/
#ifdef BLD_NATIVE
int SaveParticleSystemsData(const char *filename)
{
    int (*bld_proc)(const char *filename);
    return bld_proc(filename);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00427B03
*/
#ifdef BLD_NATIVE
int LoadParticleSystemsData(const char *filename)
{
    int (*bld_proc)(const char *filename);
    return bld_proc(filename);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00427DE8
*/
#ifdef BLD_NATIVE
int SaveCombustionData(const char *file_name)
{
    int (*bld_proc)(const char *file_name);
    return bld_proc(file_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00427EB7
*/
#ifdef BLD_NATIVE
int LoadCombustionData(const char *file_name)
{
    int (*bld_proc)(const char *file_name);
    return bld_proc(file_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042819A
*/

int ReassignCombustionData()
{
    B_App * App = get_application();
    assert(App);
    return App->ReassignCombustionData();
}


/*
* Module:                 Blade.exe
* Entry point:            0x004281D3
*/
#ifdef BLD_NATIVE
int SaveAnmRaceData(const char *file_name, const char *race)
{
    int (*bld_proc)(const char *file_name, const char *race);
    return bld_proc(file_name, race);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042857B
*/
#ifdef BLD_NATIVE
int LoadAnmRaceData(const char *file_name)
{
    int (*bld_proc)(const char *file_name);
    return bld_proc(file_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004289E0
*/

int GetnRaces()
{
    return gbl_races.size;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004289EA
*/

const char *GetRaceName(int index)
{
    if (index >= 0 && index < gbl_races.size)
    {
        B_Race *race = gbl_races.elements[index];
        return race->Id().String();
    }
    return NULL;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00428A22
*/
#ifdef BLD_NATIVE
int SaveAnmSoundData(const char *file_name, const char *race)
{
    int (*bld_proc)(const char *file_name, const char *race);
    return bld_proc(file_name, race);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00428BEE
*/
#ifdef BLD_NATIVE
int LoadAnmSoundData(const char *file_name)
{
    int (*bld_proc)(const char *file_name);
    return bld_proc(file_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00428FD6
*/

const char *GetCommandLine()
{
    B_App *App = get_application();
    assert(App);
    return App->GetCmdLine();
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042900C
*/

const char *GetCurrentMap(void)
{
    B_App *App = get_application();
    assert(App);
    return App->mapName.String();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429049
*/

int SetCurrentMap(const char *map)
{
    B_App *App = get_application();
    assert(App);
    return App->set_current_map(map);
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429086
*/

int LoadWorld(const char *file_name)
{
    B_App * app = get_application();
    assert(app);
    return app->load_world(file_name);
}


/*
* Module:                 Blade.exe
* Entry point:            0x004290C0
*/

int SetListenerMode(int mode, double x, double y, double z)
{
    B_App *App = get_application();
    assert(App);
    B_Vector v;
    v.x = x;
    v.y = y;
    v.z = z;
    return App->set_listener_mode(mode, v);
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429128
*/

int GetListenerMode()
{
    B_App *App = get_application();
    assert(App);
    return 1;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042915B
*/

int Quit()
{
    B_App *App = get_application();
    assert(App);
    return App->quit();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429194
*/

int SetTime(double time)
{
    B_App *App = get_application();
    assert(App);
    return App->set_time(time);
}


/*
* Module:                 Blade.exe
* Entry point:            0x004291D2
*/

int GoToTime(double time)
{
    B_App *App = get_application();
    assert(App);
    return App->go_to_time(time);
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429210
*/

double GetTime()
{
    return gbl_game_state.get_time();
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042921F
*/

void StopTime()
{
    B_App *App = get_application();
    assert(App);
    return App->stop_time();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429255
*/

void RestartTime()
{
    B_App *App = get_application();
    assert(App);
    App->RestartTime();
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042928B
*/

void SetTimeSpeed(double speed)
{
    B_App *App = get_application();
    assert(App);
    App->SetTimeSpeed(speed);
}


/*
* Module:                 Blade.exe
* Entry point:            0x004292C9
*/

double GetTimeSpeed()
{
    B_App *App = get_application();
    assert(App);
    return App->GetTimeSpeed();
}


/*
* Module:                 Blade.exe
* Entry point:            0x004292FF
*/

int AddInputAction(const char *action_name, int npi)
{
    B_App *App = get_application();
    assert(App);
    App->AddInputAction(action_name, npi);
    return 1;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429342
*/

int RemoveInputAction(const char *action_name)
{
    B_App *App = get_application();
    assert(App);
    App->RemoveInputAction(action_name);
    return 1;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429381
*/

int AssocKey(
    const char *action, const char *input_device, const char *key,
    int press
)
{
    B_App *App = get_application();
    assert(App);
    return App->AssocKey(action, input_device, key, press);
}


/*
* Module:                 Blade.exe
* Entry point:            0x004293C7
*/

int Bind(const char *key, PyObject *proc)
{
    assert(key);
    assert(proc);
    B_App *App = get_application();
    assert(App);
    return App->Bind(key, proc);
}


/*
* Module:                 Blade.exe
* Entry point:            0x00429446
*/

int UnBind(const char *key, PyObject *proc)
{
    assert(key);
    assert(proc);
    B_App *App = get_application();
    assert(App);
    return App->UnBind(key, proc);
}


/*
* Module:                 Blade.exe
* Entry point:            0x004294C5
*/

int Bind2(
    const char *act, const char *subact1,
    const char *subact2, int unknown
)
{
    B_App *App = get_application();
    assert(App);
    assert(act);
    assert(subact1);
    assert(subact2);
    App->Bind2(act, subact1, subact2, unknown);
    return 1;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042956A
*/

double GetTimeActionHeld(const char *Action)
{
    assert(Action);
    B_App *App = get_application();
    assert(App);
    return App->GetTimeActionHeld(Action);
}


/*
* Module:                 Blade.exe
* Entry point:            0x004295C2
*/

int BindPred(const char *key, const char *pred)
{
    assert(key);
    assert(pred);
    B_App *App = get_application();
    assert(App);
    return App->bind_pred(key, pred);
}





/*
* Module:                 Blade.exe
* Entry point:            0x00429641
*/
#ifdef BLD_NATIVE
int UnBindPred(const char *action_name, const char *predproc)
{
    int (*bld_proc)(const char *action_name, const char *predproc);
    return bld_proc(action_name, predproc);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004296C0
*/
#ifdef BLD_NATIVE
void UnBindAll(void)
{
    void (*bld_proc)(void);
    bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004296F6
*/
#ifdef BLD_NATIVE
const char *Input(const char *text)
{
    const char *(*bld_proc)(const char *text);
    return bld_proc(text);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00429733
*/
#ifdef BLD_NATIVE
void MarkLevelToLoad(const char *dir_name)
{
    void (*bld_proc)(const char *dir_name);
    bld_proc(dir_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00429793
*/
#ifdef BLD_NATIVE
void ReadLevel(const char *file_name)
{
    void (*bld_proc)(const char *file_name);
    bld_proc(file_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004297F3
*/
#ifdef BLD_NATIVE
void ReadBitMap(const char *file_name, const char *internal_name)
{
    void (*bld_proc)(const char *file_name, const char *internal_name);
    bld_proc(file_name, internal_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00429863
*/
#ifdef BLD_NATIVE
void ReadAlphaBitMap(const char *file_name, const char *internal_name)
{
    void (*bld_proc)(const char *file_name, const char *internal_name);
    bld_proc(file_name, internal_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004298D3
*/
#ifdef BLD_NATIVE
void CloseLevel(const char *statement1, const char *statement2)
{
    void (*bld_proc)(const char *statement1, const char *statement2);
    bld_proc(statement1, statement2);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00429914
*/
#ifdef BLD_NATIVE// TODO fix prototype
void StartRecordingDemo()
{
        assert("StartRecordingDemo" == NULL);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00429923
*/
#ifdef BLD_NATIVE// TODO fix prototype
void EndRecordingDemo()
{
        assert("EndRecordingDemo" == NULL);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00429936
*/
#ifdef BLD_NATIVE// TODO fix prototype
void PlayDemo()
{
        assert("PlayDemo" == NULL);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00429949
*/
#ifdef BLD_NATIVE
int DeactivateInput(void)
{
    int (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042997F
*/
#ifdef BLD_NATIVE
int ActivateInput(void)
{
    int (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004299B5
*/
#ifdef BLD_NATIVE
int OutSound(int soundId, double x, double y, double z, int unknown)
{
    int (*bld_proc)(int soundId, double x, double y, double z, int unknown);
    return bld_proc(soundId, x, y, z, unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00429A10
*/
#ifdef BLD_NATIVE
int SetDefaultMass(const char *entity_kind, double mass)
{
    int (*bld_proc)(const char *entity_kind, double mass);
    return bld_proc(entity_kind, mass);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00429C4F
*/
#ifdef BLD_NATIVE
int SetDefaultMaterial(const char *entity_kind, const char *material)
{
    int (*bld_proc)(const char *entity_kind, const char *material);
    return bld_proc(entity_kind, material);
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
* Entry point:            0x00429F2D
*/
#ifdef BLD_NATIVE
void SetSun(int exists, double x, double y, double z)
{
    void (*bld_proc)(int exists, double x, double y, double z);
    bld_proc(exists, x, y, z);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00429F71
*/
#ifdef BLD_NATIVE
int InsideAA(int AA, double x, double y, double z)
{
    int (*bld_proc)(int AA, double x, double y, double z);
    return bld_proc(AA, x, y, z);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00429FDF
*/
#ifdef BLD_NATIVE
int SetDrawObjectShadows(int draw)
{
    int (*bld_proc)(int draw);
    return bld_proc(draw);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A000
*/
#ifdef BLD_NATIVE
int GetDrawObjectShadows(void)
{
    int (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A019
*/
#ifdef BLD_NATIVE
int SetAutoEngageCombat(int auto_engage_combat)
{
    int (*bld_proc)(int auto_engage_combat);
    return bld_proc(auto_engage_combat);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A03A
*/
#ifdef BLD_NATIVE
int GetAutoEngageCombat(void)
{
    int (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A053
*/
#ifdef BLD_NATIVE
int SetAecGap(double aec_gap)
{
    int (*bld_proc)(double aec_gap);
    return bld_proc(aec_gap);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A07D
*/
#ifdef BLD_NATIVE
double GetAecGap(void)
{
    double (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A095
*/
#ifdef BLD_NATIVE
int SetBloodLevel(int blood_level)
{
    int (*bld_proc)(int blood_level);
    return bld_proc(blood_level);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A0CF
*/
#ifdef BLD_NATIVE
int GetBloodLevel(void)
{
    int (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A105
*/
#ifdef BLD_NATIVE
int SetMutilationLevel(int mutilation_level)
{
    int (*bld_proc)(int mutilation_level);
    return bld_proc(mutilation_level);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A13F
*/
#ifdef BLD_NATIVE
int GetMutilationLevel(void)
{
    int (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A175
*/
#ifdef BLD_NATIVE
void AnmAddEvent(const char *anm_name, const char *event_name, double event_frame)
{
    void (*bld_proc)(const char *anm_name, const char *event_name, double event_frame);
    bld_proc(anm_name, event_name, event_frame);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A232
*/
#ifdef BLD_NATIVE
void AnmDelEvent(const char *anm_name, const char *event_name)
{
    void (*bld_proc)(const char *anm_name, const char *event_name);
    bld_proc(anm_name, event_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A2D0
*/
#ifdef BLD_NATIVE
void AnmClearEvents(const char *anm_name)
{
    void (*bld_proc)(const char *anm_name);
    bld_proc(anm_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A354
*/
#ifdef BLD_NATIVE
double AnmGetEventFrame(const char *anm_name, const char *event_name)
{
    double (*bld_proc)(const char *anm_name, const char *event_name);
    return bld_proc(anm_name, event_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A400
*/
#ifdef BLD_NATIVE
int AddParticleGType(
        const char *new_type, const char *parent_type, int operation_type,
        int duration
)
{
    int (*bld_proc)(
        const char *new_type, const char *parent_type, int operation_type,
        int duration
);
        const char *new_type, const char *parent_type, int operation_type,
        int duration
))GetProcAddress(blade, "AddParticleGType");
    return bld_proc(new_type, parent_type, operation_type, duration);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A697
*/
#ifdef BLD_NATIVE
int SetParticleGVal(
        const char *type, int i, int r, int g, int b, int alpha, double size
)
{
    int (*bld_proc)(
        const char *type, int i, int r, int g, int b, int alpha, double size
);
        const char *type, int i, int r, int g, int b, int alpha, double size
))GetProcAddress(blade, "SetParticleGVal");
    return bld_proc(type, i, r, g, b, alpha, size);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A775
*/
#ifdef BLD_NATIVE
int GetnParticleGType(void)
{
    int (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A77F
*/
#ifdef BLD_NATIVE
int GetParticleGType(
        int index, const char **type, const char **parent_type,
        int *operation_type, int *duration
)
{
    int (*bld_proc)(
        int index, const char **type, const char **parent_type,
        int *operation_type, int *duration
);
        int index, const char **type, const char **parent_type,
        int *operation_type, int *duration
))GetProcAddress(blade, "GetParticleGType");
    return bld_proc(index, type, parent_type, operation_type, duration);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A82F
*/
#ifdef BLD_NATIVE
int GetParticleGVal(
        const char *type, int index, int *r, int *g, int *b, int *alpha,
        double *size
)
{
    int (*bld_proc)(
        const char *type, int index, int *r, int *g, int *b, int *alpha,
        double *size
);
        const char *type, int index, int *r, int *g, int *b, int *alpha,
        double *size
))GetProcAddress(blade, "GetParticleGVal");
    return bld_proc(type, index, r, g, b, alpha, size);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A915
*/
#ifdef BLD_NATIVE
void SetTurnSpeed(const char *race_name, double new_speed)
{
    void (*bld_proc)(const char *race_name, double new_speed);
    bld_proc(race_name, new_speed);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A930
*/
#ifdef BLD_NATIVE
int SetAnimationFactor(const char *mov, double new_speed_factor)
{
    int (*bld_proc)(const char *mov, double new_speed_factor);
    return bld_proc(mov, new_speed_factor);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A94B
*/
#ifdef BLD_NATIVE
int SetAutoGenTexture(const char *textureName, int textureEffect)
{
    int (*bld_proc)(const char *textureName, int textureEffect);
    return bld_proc(textureName, textureEffect);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A98E
*/
#ifdef BLD_NATIVE
const char *GenerateEntityName(void)
{
    const char *(*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A9A2
*/
#ifdef BLD_NATIVE
int AddWatchAnim(const char *anim)
{
    int (*bld_proc)(const char *anim);
    return bld_proc(anim);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A9B5
*/
#ifdef BLD_NATIVE
int AddAnimFlags(
        const char *anim, int wuea, int mdf_y, int solf, int copy_rot,
        int bng_mov, int head_f
)
{
    int (*bld_proc)(
        const char *anim, int wuea, int mdf_y, int solf, int copy_rot,
        int bng_mov, int head_f
);
        const char *anim, int wuea, int mdf_y, int solf, int copy_rot,
        int bng_mov, int head_f
))GetProcAddress(blade, "AddAnimFlags");
    return bld_proc(anim, wuea, mdf_y, solf, copy_rot, bng_mov, head_f);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042A9E0
*/
#ifdef BLD_NATIVE
int SetActionCameraMovement(
        const char *action_name, double angle, double start_pos, double end_pos
)
{
    int (*bld_proc)(
        const char *action_name, double angle, double start_pos, double end_pos
);
        const char *action_name, double angle, double start_pos, double end_pos
))GetProcAddress(blade, "SetActionCameraMovement");
    return bld_proc(action_name, angle, start_pos, end_pos);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042ABBA
*/
#ifdef BLD_NATIVE
int SetRootWidget(long int widget)
{
    int (*bld_proc)(long int widget);
    return bld_proc(widget);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042ABF6
*/
#ifdef BLD_NATIVE
long int GetRootWidget(void)
{
    long int (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042AC32
*/
#ifdef BLD_NATIVE
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
        const char *object_kind, const char *fire_kind, double upper_treshol,
        double lower_treshold, double flame_height, double flame_size,
        double speed, double livetime
))GetProcAddress(blade, "AddCombustionDataFor");
    return bld_proc(object_kind, fire_kind, upper_treshol, lower_treshold, flame_height, flame_size, speed, livetime);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042AE7A
*/
#ifdef BLD_NATIVE// TODO fix prototype
void RM_FreeResource()
{
        assert("RM_FreeResource" == NULL);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042AEAE
*/
#ifdef BLD_NATIVE// TODO fix prototype
void RM_GetResource()
{
        assert("RM_GetResource" == NULL);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B0F4
*/
#ifdef BLD_NATIVE// TODO fix prototype
void UpdateAGTexture()
{
        assert("UpdateAGTexture" == NULL);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B192
*/

const char *GetWorldFileName(void)
{
    return gbl_game_state.world_file_name;
}


/*
* Module:                 Blade.exe
* Entry point:            0x0042B1A5
*/
#ifdef BLD_NATIVE
int SetAfterFrameFunc(const char *name, PyObject *function)
{
    int (*bld_proc)(const char *name, PyObject *function);
    return bld_proc(name, function);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B1E8
*/
#ifdef BLD_NATIVE
int RemoveAfterFrameFunc(const char *name)
{
    int (*bld_proc)(const char *name);
    return bld_proc(name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B227
*/
#ifdef BLD_NATIVE
PyObject *GetAfterFrameFunc(const char *name)
{
    PyObject *(*bld_proc)(const char *name);
    return bld_proc(name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B261
*/
#ifdef BLD_NATIVE
const char *GetAfterFrameFuncName(int index)
{
    const char *(*bld_proc)(int index);
    return bld_proc(index);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B29B
*/
#ifdef BLD_NATIVE
int GetnAfterFrameFuncs(void)
{
    int (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B2D1
*/
#ifdef BLD_NATIVE
int SetMenuTgapFunc(PyObject *func)
{
    int (*bld_proc)(PyObject *func);
    return bld_proc(func);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B310
*/
#ifdef BLD_NATIVE
PyObject *GetMenuTgapFunc(void)
{
    PyObject *(*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B346
*/
#ifdef BLD_NATIVE
int SetCallCheck(int check)
{
    int (*bld_proc)(int check);
    return bld_proc(check);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B366
*/
#ifdef BLD_NATIVE
int OpenDebugChannel(const char *channel_name)
{
    int (*bld_proc)(const char *channel_name);
    return bld_proc(channel_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B39C
*/
#ifdef BLD_NATIVE
int CloseDebugChannel(const char *channel_name)
{
    int (*bld_proc)(const char *channel_name);
    return bld_proc(channel_name);
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
* Entry point:            0x0042B444
*/
#ifdef BLD_NATIVE
int SetShowAreas(int action_areas_bit_mask)
{
    int (*bld_proc)(int action_areas_bit_mask);
    return bld_proc(action_areas_bit_mask);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B453
*/
#ifdef BLD_NATIVE
int WriteText(double x, double y, const char *text)
{
    int (*bld_proc)(double x, double y, const char *text);
    return bld_proc(x, y, text);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B4EC
*/
#ifdef BLD_NATIVE
void GetTextWH(const char *text, double *w, double *h)
{
    void (*bld_proc)(const char *text, double *w, double *h);
    bld_proc(text, w, h);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B672
*/
#ifdef BLD_NATIVE
void GetScreenRect(
        double *x_min, double *y_min, double *x_max, double *y_max
)
{
    void (*bld_proc)(
        double *x_min, double *y_min, double *x_max, double *y_max
);
        double *x_min, double *y_min, double *x_max, double *y_max
))GetProcAddress(blade, "GetScreenRect");
    bld_proc(x_min, y_min, x_max, y_max);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B795
*/
#ifdef BLD_NATIVE
void GetScreenXY(
        double map_x, double map_y, double map_z, double *screen_x,
        double *screen_y
)
{
    void (*bld_proc)(
        double map_x, double map_y, double map_z, double *screen_x,
        double *screen_y
);
        double map_x, double map_y, double map_z, double *screen_x,
        double *screen_y
))GetProcAddress(blade, "GetScreenXY");
    bld_proc(map_x, map_y, map_z, screen_x, screen_y);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B8E8
*/
#ifdef BLD_NATIVE
int DrawBOD(
        const char *BODName, int x, int y, int w, int h, double scale,
        int i_unknown
)
{
    int (*bld_proc)(
        const char *BODName, int x, int y, int w, int h, double scale,
        int i_unknown
);
        const char *BODName, int x, int y, int w, int h, double scale,
        int i_unknown
))GetProcAddress(blade, "DrawBOD");
    return bld_proc(BODName, x, y, w, h, scale, i_unknown);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042B97A
*/
#ifdef BLD_NATIVE
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
	const char *trigger_sector_name, const char *group_name,
	double floor_height, double roof_height, int num_points,
	point_2d_t *points
))GetProcAddress(blade, "CreateTriggerSector");
    return bld_proc(trigger_sector_name, group_name, floor_height, roof_height, num_points, points);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042BC9A
*/
#ifdef BLD_NATIVE
int SetTriggerSectorFunc(
        const char *trigger_sector_name, const char *func_type, PyObject *func
)
{
    int (*bld_proc)(
        const char *trigger_sector_name, const char *func_type, PyObject *func
);
        const char *trigger_sector_name, const char *func_type, PyObject *func
))GetProcAddress(blade, "SetTriggerSectorFunc");
    return bld_proc(trigger_sector_name, func_type, func);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042BCB5
*/
#ifdef BLD_NATIVE
PyObject *GetTriggerSectorFunc(
        const char *trigger_sector_name, const char *func_type
)
{
    PyObject *(*bld_proc)(
        const char *trigger_sector_name, const char *func_type
);
        const char *trigger_sector_name, const char *func_type
))GetProcAddress(blade, "GetTriggerSectorFunc");
    return bld_proc(trigger_sector_name, func_type);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042BCCC
*/
#ifdef BLD_NATIVE
int GetTriggerSectorFloorHeight(const char *trigger_sector_name)
{
    int (*bld_proc)(const char *trigger_sector_name);
    return bld_proc(trigger_sector_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042BCDF
*/
#ifdef BLD_NATIVE
int GetTriggerSectorRoofHeight(const char *trigger_sector_name)
{
    int (*bld_proc)(const char *trigger_sector_name);
    return bld_proc(trigger_sector_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042BCF2
*/
#ifdef BLD_NATIVE
const char *GetTriggerSectorGroup(const char *trigger_sector_name)
{
    const char *(*bld_proc)(const char *trigger_sector_name);
    return bld_proc(trigger_sector_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042BD05
*/
#ifdef BLD_NATIVE
double *GetTriggerSectorPoints(const char *trigger_sector_name)
{
    double *(*bld_proc)(const char *trigger_sector_name);
    return bld_proc(trigger_sector_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042BD18
*/
#ifdef BLD_NATIVE
int SetTriggerSectorData(
        const char *trigger_sector_name, PyObject *data
)
{
    int (*bld_proc)(
        const char *trigger_sector_name, PyObject *data
);
        const char *trigger_sector_name, PyObject *data
))GetProcAddress(blade, "SetTriggerSectorData");
    return bld_proc(trigger_sector_name, data);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042BD2F
*/
#ifdef BLD_NATIVE
PyObject *GetTriggerSectorData(const char *trigger_sector_name)
{
    PyObject *(*bld_proc)(const char *trigger_sector_name);
    return bld_proc(trigger_sector_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042BD42
*/
#ifdef BLD_NATIVE
int nTriggerSectors(void)
{
    int (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042BD55
*/
#ifdef BLD_NATIVE
const char *GetTriggerSectorName(int index)
{
    const char *(*bld_proc)(int index);
    return bld_proc(index);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042BD68
*/
#ifdef BLD_NATIVE
int GetModelPos(const char *person, double *x, double *y, double *z)
{
    int (*bld_proc)(const char *person, double *x, double *y, double *z);
    return bld_proc(person, x, y, z);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042BFF8
*/
#ifdef BLD_NATIVE
int GetWindowId(void)
{
    int (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042C031
*/
#ifdef BLD_NATIVE
int GetProgramId(void)
{
    int (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042C06A
*/
#ifdef BLD_NATIVE
void TakeSnapShot(void)
{
    void (*bld_proc)(void);
    bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042C0A5
*/
#ifdef BLD_NATIVE
int nSectors(void)
{
    int (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042C0AF
*/
#ifdef BLD_NATIVE
void SetRunString(const char *variable)
{
    void (*bld_proc)(const char *variable);
    bld_proc(variable);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042C0EC
*/
#ifdef BLD_NATIVE
int SetStringValue(const char *variable, const char *value)
{
    int (*bld_proc)(const char *variable, const char *value);
    return bld_proc(variable, value);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042C12A
*/
#ifdef BLD_NATIVE
const char *GetStringValue(const char *variable)
{
    const char *(*bld_proc)(const char *variable);
    return bld_proc(variable);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042C164
*/
#ifdef BLD_NATIVE
int DeleteStringValue(const char *variable)
{
    int (*bld_proc)(const char *variable);
    return bld_proc(variable);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042C19E
*/
#ifdef BLD_NATIVE
int SaveProfileData(const char *file_name)
{
    int (*bld_proc)(const char *file_name);
    return bld_proc(file_name);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042C1B9
*/
#ifdef BLD_NATIVE
int OpenProfileSection(int section, const char *comment)
{
    int (*bld_proc)(int section, const char *comment);
    return bld_proc(section, comment);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042C1D4
*/
#ifdef BLD_NATIVE
int CloseProfileSection(int section)
{
    int (*bld_proc)(int section);
    return bld_proc(section);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042C1EF
*/
#ifdef BLD_NATIVE
int StartProfile(void)
{
    int (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042C20A
*/
#ifdef BLD_NATIVE
int EnableProfiler(void)
{
    int (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042C225
*/
#ifdef BLD_NATIVE
int DisableProfiler(void)
{
    int (*bld_proc)(void);
    return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042C240
*/
#ifdef BLD_NATIVE
int SetInputMode(const char *device, const char *mode)
{
    int (*bld_proc)(const char *device, const char *mode);
    return bld_proc(device, mode);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042C281
*/
#ifdef BLD_NATIVE
const char *GetInputMode(const char *device)
{
    const char *(*bld_proc)(const char *device);
    return bld_proc(device);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0042C2BE
*/
#ifdef BLD_NATIVE
const char *GetLastPlayerCType(void)
{
    const char *(*bld_proc)(void);
    return bld_proc();
}
#endif
