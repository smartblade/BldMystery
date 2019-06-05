
#include <bld_system.h>
#include <bld_python.h>
#define BUILD_LIB
#include <blade_ext.h>

extern HMODULE blade;

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00427750
*/

#ifdef BLD_NATIVE

int PlayCDTrack(int ntrack)
{
        int (*bld_proc)(int ntrack);
        bld_proc = (int (*)(int ntrack))GetProcAddress(blade, "PlayCDTrack");
        return bld_proc(ntrack);
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
* Entry point:            0x00427777
*/

#ifdef BLD_NATIVE

int nCDTracks(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "nCDTracks");
        return bld_proc();
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
* Entry point:            0x00427799
*/

#ifdef BLD_NATIVE

int CDLenght(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "CDLenght");
        return bld_proc();
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
* Entry point:            0x004277BB
*/

#ifdef BLD_NATIVE

int CDTrackLenght(int ntrack)
{
        int (*bld_proc)(int ntrack);
        bld_proc = (int (*)(int ntrack))GetProcAddress(blade, "CDTrackLenght");
        return bld_proc(ntrack);
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
* Entry point:            0x004277E2
*/

#ifdef BLD_NATIVE

int CDPresent(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "CDPresent");
        return bld_proc();
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
* Entry point:            0x00427804
*/

#ifdef BLD_NATIVE

int CDStop(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "CDStop");
        return bld_proc();
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
* Entry point:            0x00427826
*/

#ifdef BLD_NATIVE

int CDPause(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "CDPause");
        return bld_proc();
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
* Entry point:            0x00427848
*/

#ifdef BLD_NATIVE

int CDSetCallBack(PyObject *func)
{
        int (*bld_proc)(PyObject *func);
        bld_proc = (int (*)(PyObject *func))GetProcAddress(blade, "CDSetCallBack");
        return bld_proc(func);
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
* Entry point:            0x00427880
*/

#ifdef BLD_NATIVE

int SetAppMode(const char *mode)
{
        int (*bld_proc)(const char *mode);
        bld_proc = (int (*)(const char *mode))GetProcAddress(blade, "SetAppMode");
        return bld_proc(mode);
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
* Entry point:            0x004278D5
*/

#ifdef BLD_NATIVE

const char *GetAppMode(void)
{
        const char *(*bld_proc)(void);
        bld_proc = (const char *(*)(void))GetProcAddress(blade, "GetAppMode");
        return bld_proc();
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
* Entry point:            0x00427910
*/

#ifdef BLD_NATIVE

void BeginLoadGame(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "BeginLoadGame");
        bld_proc();
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
* Entry point:            0x00427943
*/

#ifdef BLD_NATIVE

void DoneLoadGame(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "DoneLoadGame");
        bld_proc();
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
* Entry point:            0x00427976
*/

#ifdef BLD_NATIVE

int SetSaveInfo(PyObject *info)
{
        int (*bld_proc)(PyObject *info);
        bld_proc = (int (*)(PyObject *info))GetProcAddress(blade, "SetSaveInfo");
        return bld_proc(info);
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
* Entry point:            0x004279E1
*/

#ifdef BLD_NATIVE

PyObject *GetSaveInfo(void)
{
        PyObject *(*bld_proc)(void);
        bld_proc = (PyObject *(*)(void))GetProcAddress(blade, "GetSaveInfo");
        return bld_proc();
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
* Entry point:            0x00427A0D
*/

#ifdef BLD_NATIVE

int SaveEntitiesData(const char *filename)
{
        int (*bld_proc)(const char *filename);
        bld_proc = (int (*)(const char *filename))GetProcAddress(blade, "SaveEntitiesData");
        return bld_proc(filename);
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
* Entry point:            0x00427A20
*/

#ifdef BLD_NATIVE

int LoadEntitiesData(const char *filename)
{
        int (*bld_proc)(const char *filename);
        bld_proc = (int (*)(const char *filename))GetProcAddress(blade, "LoadEntitiesData");
        return bld_proc(filename);
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
* Entry point:            0x00427A33
*/

#ifdef BLD_NATIVE

int SaveParticleSystemsData(const char *filename)
{
        int (*bld_proc)(const char *filename);
        bld_proc = (int (*)(const char *filename))GetProcAddress(blade, "SaveParticleSystemsData");
        return bld_proc(filename);
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
* Entry point:            0x00427B03
*/

#ifdef BLD_NATIVE

int LoadParticleSystemsData(const char *filename)
{
        int (*bld_proc)(const char *filename);
        bld_proc = (int (*)(const char *filename))GetProcAddress(blade, "LoadParticleSystemsData");
        return bld_proc(filename);
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
* Entry point:            0x00427DE8
*/

#ifdef BLD_NATIVE

int SaveCombustionData(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "SaveCombustionData");
        return bld_proc(file_name);
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
* Entry point:            0x00427EB7
*/

#ifdef BLD_NATIVE

int LoadCombustionData(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "LoadCombustionData");
        return bld_proc(file_name);
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
* Entry point:            0x0042819A
*/

#ifdef BLD_NATIVE

int ReassignCombustionData(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "ReassignCombustionData");
        return bld_proc();
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
* Entry point:            0x004281D3
*/

#ifdef BLD_NATIVE

int SaveAnmRaceData(const char *file_name, const char *race)
{
        int (*bld_proc)(const char *file_name, const char *race);
        bld_proc = (int (*)(const char *file_name, const char *race))GetProcAddress(blade, "SaveAnmRaceData");
        return bld_proc(file_name, race);
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
* Entry point:            0x0042857B
*/

#ifdef BLD_NATIVE

int LoadAnmRaceData(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "LoadAnmRaceData");
        return bld_proc(file_name);
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
* Entry point:            0x004289E0
*/

#ifdef BLD_NATIVE

int GetnRaces(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetnRaces");
        return bld_proc();
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
* Entry point:            0x004289EA
*/

#ifdef BLD_NATIVE

const char *GetRaceName(int index)
{
        const char *(*bld_proc)(int index);
        bld_proc = (const char *(*)(int index))GetProcAddress(blade, "GetRaceName");
        return bld_proc(index);
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
* Entry point:            0x00428A22
*/

#ifdef BLD_NATIVE

int SaveAnmSoundData(const char *file_name, const char *race)
{
        int (*bld_proc)(const char *file_name, const char *race);
        bld_proc = (int (*)(const char *file_name, const char *race))GetProcAddress(blade, "SaveAnmSoundData");
        return bld_proc(file_name, race);
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
* Entry point:            0x00428BEE
*/

#ifdef BLD_NATIVE

int LoadAnmSoundData(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "LoadAnmSoundData");
        return bld_proc(file_name);
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
* Entry point:            0x00428FD6
*/

#ifdef BLD_NATIVE

const char *GetCommandLine(void)
{
        const char *(*bld_proc)(void);
        bld_proc = (const char *(*)(void))GetProcAddress(blade, "GetCommandLine");
        return bld_proc();
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
* Entry point:            0x0042900C
*/

#ifdef BLD_NATIVE

const char *GetCurrentMap(void)
{
        const char *(*bld_proc)(void);
        bld_proc = (const char *(*)(void))GetProcAddress(blade, "GetCurrentMap");
        return bld_proc();
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
* Entry point:            0x00429049
*/

#ifdef BLD_NATIVE

int SetCurrentMap(const char *map)
{
        int (*bld_proc)(const char *map);
        bld_proc = (int (*)(const char *map))GetProcAddress(blade, "SetCurrentMap");
        return bld_proc(map);
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
* Entry point:            0x00429210
*/

#ifdef BLD_NATIVE

double GetTime(void)
{
        double (*bld_proc)(void);
        bld_proc = (double (*)(void))GetProcAddress(blade, "GetTime");
        return bld_proc();
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
* Entry point:            0x0042921F
*/

#ifdef BLD_NATIVE

void StopTime(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "StopTime");
        bld_proc();
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
* Entry point:            0x00429255
*/

#ifdef BLD_NATIVE

void RestartTime(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "RestartTime");
        bld_proc();
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
* Entry point:            0x0042928B
*/

#ifdef BLD_NATIVE

void SetTimeSpeed(double speed)
{
        void (*bld_proc)(double speed);
        bld_proc = (void (*)(double speed))GetProcAddress(blade, "SetTimeSpeed");
        bld_proc(speed);
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
* Entry point:            0x004292C9
*/

#ifdef BLD_NATIVE

double GetTimeSpeed(void)
{
        double (*bld_proc)(void);
        bld_proc = (double (*)(void))GetProcAddress(blade, "GetTimeSpeed");
        return bld_proc();
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
* Entry point:            0x004292FF
*/

#ifdef BLD_NATIVE

int AddInputAction(const char *action_name, int npi)
{
        int (*bld_proc)(const char *action_name, int npi);
        bld_proc = (int (*)(const char *action_name, int npi))GetProcAddress(blade, "AddInputAction");
        return bld_proc(action_name, npi);
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
* Entry point:            0x00429342
*/

#ifdef BLD_NATIVE

int RemoveInputAction(const char *action_name)
{
        int (*bld_proc)(const char *action_name);
        bld_proc = (int (*)(const char *action_name))GetProcAddress(blade, "RemoveInputAction");
        return bld_proc(action_name);
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
* Entry point:            0x00429381
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004293C7
*/

#ifdef BLD_NATIVE

int Bind(const char *action_name, PyObject *proc)
{
        int (*bld_proc)(const char *action_name, PyObject *proc);
        bld_proc = (int (*)(const char *action_name, PyObject *proc))GetProcAddress(blade, "Bind");
        return bld_proc(action_name, proc);
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
* Entry point:            0x00429446
*/

#ifdef BLD_NATIVE

int UnBind(const char *action_name, PyObject *proc)
{
        int (*bld_proc)(const char *action_name, PyObject *proc);
        bld_proc = (int (*)(const char *action_name, PyObject *proc))GetProcAddress(blade, "UnBind");
        return bld_proc(action_name, proc);
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
* Entry point:            0x004294C5
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0042956A
*/

#ifdef BLD_NATIVE

double GetTimeActionHeld(const char *action_name)
{
        double (*bld_proc)(const char *action_name);
        bld_proc = (double (*)(const char *action_name))GetProcAddress(blade, "GetTimeActionHeld");
        return bld_proc(action_name);
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
* Entry point:            0x00429641
*/

#ifdef BLD_NATIVE

int UnBindPred(const char *action_name, const char *predproc)
{
        int (*bld_proc)(const char *action_name, const char *predproc);
        bld_proc = (int (*)(const char *action_name, const char *predproc))GetProcAddress(blade, "UnBindPred");
        return bld_proc(action_name, predproc);
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
* Entry point:            0x004296C0
*/

#ifdef BLD_NATIVE

void UnBindAll(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "UnBindAll");
        bld_proc();
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
* Entry point:            0x004296F6
*/

#ifdef BLD_NATIVE

const char *Input(const char *text)
{
        const char *(*bld_proc)(const char *text);
        bld_proc = (const char *(*)(const char *text))GetProcAddress(blade, "Input");
        return bld_proc(text);
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
* Entry point:            0x00429733
*/

#ifdef BLD_NATIVE

void MarkLevelToLoad(const char *dir_name)
{
        void (*bld_proc)(const char *dir_name);
        bld_proc = (void (*)(const char *dir_name))GetProcAddress(blade, "MarkLevelToLoad");
        bld_proc(dir_name);
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
* Entry point:            0x00429793
*/

#ifdef BLD_NATIVE

void ReadLevel(const char *file_name)
{
        void (*bld_proc)(const char *file_name);
        bld_proc = (void (*)(const char *file_name))GetProcAddress(blade, "ReadLevel");
        bld_proc(file_name);
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
* Entry point:            0x004297F3
*/

#ifdef BLD_NATIVE

void ReadBitMap(const char *file_name, const char *internal_name)
{
        void (*bld_proc)(const char *file_name, const char *internal_name);
        bld_proc = (void (*)(const char *file_name, const char *internal_name))GetProcAddress(blade, "ReadBitMap");
        bld_proc(file_name, internal_name);
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
* Entry point:            0x00429863
*/

#ifdef BLD_NATIVE

void ReadAlphaBitMap(const char *file_name, const char *internal_name)
{
        void (*bld_proc)(const char *file_name, const char *internal_name);
        bld_proc = (void (*)(const char *file_name, const char *internal_name))GetProcAddress(blade, "ReadAlphaBitMap");
        bld_proc(file_name, internal_name);
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
* Entry point:            0x004298D3
*/

#ifdef BLD_NATIVE

void CloseLevel(const char *statement1, const char *statement2)
{
        void (*bld_proc)(const char *statement1, const char *statement2);
        bld_proc = (void (*)(const char *statement1, const char *statement2))GetProcAddress(blade, "CloseLevel");
        bld_proc(statement1, statement2);
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
* Entry point:            0x00429914
*/

#ifdef BLD_NATIVE
// TODO fix prototype
void StartRecordingDemo()
{
        assert("StartRecordingDemo" == NULL);
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
* Entry point:            0x00429923
*/

#ifdef BLD_NATIVE
// TODO fix prototype
void EndRecordingDemo()
{
        assert("EndRecordingDemo" == NULL);
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
* Entry point:            0x00429936
*/

#ifdef BLD_NATIVE
// TODO fix prototype
void PlayDemo()
{
        assert("PlayDemo" == NULL);
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
* Entry point:            0x00429949
*/

#ifdef BLD_NATIVE

int DeactivateInput(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "DeactivateInput");
        return bld_proc();
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
* Entry point:            0x0042997F
*/

#ifdef BLD_NATIVE

int ActivateInput(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "ActivateInput");
        return bld_proc();
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
* Entry point:            0x004299B5
*/

#ifdef BLD_NATIVE

int OutSound(int soundId, double x, double y, double z, int unknown)
{
        int (*bld_proc)(int soundId, double x, double y, double z, int unknown);
        bld_proc = (int (*)(int soundId, double x, double y, double z, int unknown))GetProcAddress(blade, "OutSound");
        return bld_proc(soundId, x, y, z, unknown);
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
* Entry point:            0x00429A10
*/

#ifdef BLD_NATIVE

int SetDefaultMass(const char *entity_kind, double mass)
{
        int (*bld_proc)(const char *entity_kind, double mass);
        bld_proc = (int (*)(const char *entity_kind, double mass))GetProcAddress(blade, "SetDefaultMass");
        return bld_proc(entity_kind, mass);
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
* Entry point:            0x00429C4F
*/

#ifdef BLD_NATIVE

int SetDefaultMaterial(const char *entity_kind, const char *material)
{
        int (*bld_proc)(const char *entity_kind, const char *material);
        bld_proc = (int (*)(const char *entity_kind, const char *material))GetProcAddress(blade, "SetDefaultMaterial");
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
        bld_proc = (void (*)(int exists, double x, double y, double z))GetProcAddress(blade, "SetSun");
        bld_proc(exists, x, y, z);
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
* Entry point:            0x00429F71
*/

#ifdef BLD_NATIVE

int InsideAA(int AA, double x, double y, double z)
{
        int (*bld_proc)(int AA, double x, double y, double z);
        bld_proc = (int (*)(int AA, double x, double y, double z))GetProcAddress(blade, "InsideAA");
        return bld_proc(AA, x, y, z);
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
* Entry point:            0x00429FDF
*/

#ifdef BLD_NATIVE

int SetDrawObjectShadows(int draw)
{
        int (*bld_proc)(int draw);
        bld_proc = (int (*)(int draw))GetProcAddress(blade, "SetDrawObjectShadows");
        return bld_proc(draw);
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
* Entry point:            0x0042A000
*/

#ifdef BLD_NATIVE

int GetDrawObjectShadows(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetDrawObjectShadows");
        return bld_proc();
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
* Entry point:            0x0042A019
*/

#ifdef BLD_NATIVE

int SetAutoEngageCombat(int auto_engage_combat)
{
        int (*bld_proc)(int auto_engage_combat);
        bld_proc = (int (*)(int auto_engage_combat))GetProcAddress(blade, "SetAutoEngageCombat");
        return bld_proc(auto_engage_combat);
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
* Entry point:            0x0042A03A
*/

#ifdef BLD_NATIVE

int GetAutoEngageCombat(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetAutoEngageCombat");
        return bld_proc();
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
* Entry point:            0x0042A053
*/

#ifdef BLD_NATIVE

int SetAecGap(double aec_gap)
{
        int (*bld_proc)(double aec_gap);
        bld_proc = (int (*)(double aec_gap))GetProcAddress(blade, "SetAecGap");
        return bld_proc(aec_gap);
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
* Entry point:            0x0042A07D
*/

#ifdef BLD_NATIVE

double GetAecGap(void)
{
        double (*bld_proc)(void);
        bld_proc = (double (*)(void))GetProcAddress(blade, "GetAecGap");
        return bld_proc();
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
* Entry point:            0x0042A095
*/

#ifdef BLD_NATIVE

int SetBloodLevel(int blood_level)
{
        int (*bld_proc)(int blood_level);
        bld_proc = (int (*)(int blood_level))GetProcAddress(blade, "SetBloodLevel");
        return bld_proc(blood_level);
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
* Entry point:            0x0042A0CF
*/

#ifdef BLD_NATIVE

int GetBloodLevel(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetBloodLevel");
        return bld_proc();
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
* Entry point:            0x0042A105
*/

#ifdef BLD_NATIVE

int SetMutilationLevel(int mutilation_level)
{
        int (*bld_proc)(int mutilation_level);
        bld_proc = (int (*)(int mutilation_level))GetProcAddress(blade, "SetMutilationLevel");
        return bld_proc(mutilation_level);
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
* Entry point:            0x0042A13F
*/

#ifdef BLD_NATIVE

int GetMutilationLevel(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetMutilationLevel");
        return bld_proc();
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
* Entry point:            0x0042A175
*/

#ifdef BLD_NATIVE

void AnmAddEvent(const char *anm_name, const char *event_name, double event_frame)
{
        void (*bld_proc)(const char *anm_name, const char *event_name, double event_frame);
        bld_proc = (void (*)(const char *anm_name, const char *event_name, double event_frame))GetProcAddress(blade, "AnmAddEvent");
        bld_proc(anm_name, event_name, event_frame);
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
* Entry point:            0x0042A232
*/

#ifdef BLD_NATIVE

void AnmDelEvent(const char *anm_name, const char *event_name)
{
        void (*bld_proc)(const char *anm_name, const char *event_name);
        bld_proc = (void (*)(const char *anm_name, const char *event_name))GetProcAddress(blade, "AnmDelEvent");
        bld_proc(anm_name, event_name);
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
* Entry point:            0x0042A2D0
*/

#ifdef BLD_NATIVE

void AnmClearEvents(const char *anm_name)
{
        void (*bld_proc)(const char *anm_name);
        bld_proc = (void (*)(const char *anm_name))GetProcAddress(blade, "AnmClearEvents");
        bld_proc(anm_name);
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
* Entry point:            0x0042A354
*/

#ifdef BLD_NATIVE

double AnmGetEventFrame(const char *anm_name, const char *event_name)
{
        double (*bld_proc)(const char *anm_name, const char *event_name);
        bld_proc = (double (*)(const char *anm_name, const char *event_name))GetProcAddress(blade, "AnmGetEventFrame");
        return bld_proc(anm_name, event_name);
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
        bld_proc = (int (*)(
        const char *new_type, const char *parent_type, int operation_type,
        int duration
))GetProcAddress(blade, "AddParticleGType");
        return bld_proc(new_type, parent_type, operation_type, duration);
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
        bld_proc = (int (*)(
        const char *type, int i, int r, int g, int b, int alpha, double size
))GetProcAddress(blade, "SetParticleGVal");
        return bld_proc(type, i, r, g, b, alpha, size);
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
* Entry point:            0x0042A775
*/

#ifdef BLD_NATIVE

int GetnParticleGType(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetnParticleGType");
        return bld_proc();
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
        bld_proc = (int (*)(
        int index, const char **type, const char **parent_type,
        int *operation_type, int *duration
))GetProcAddress(blade, "GetParticleGType");
        return bld_proc(index, type, parent_type, operation_type, duration);
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
        bld_proc = (int (*)(
        const char *type, int index, int *r, int *g, int *b, int *alpha,
        double *size
))GetProcAddress(blade, "GetParticleGVal");
        return bld_proc(type, index, r, g, b, alpha, size);
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
* Entry point:            0x0042A915
*/

#ifdef BLD_NATIVE

void SetTurnSpeed(const char *race_name, double new_speed)
{
        void (*bld_proc)(const char *race_name, double new_speed);
        bld_proc = (void (*)(const char *race_name, double new_speed))GetProcAddress(blade, "SetTurnSpeed");
        bld_proc(race_name, new_speed);
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
* Entry point:            0x0042A930
*/

#ifdef BLD_NATIVE

int SetAnimationFactor(const char *mov, double new_speed_factor)
{
        int (*bld_proc)(const char *mov, double new_speed_factor);
        bld_proc = (int (*)(const char *mov, double new_speed_factor))GetProcAddress(blade, "SetAnimationFactor");
        return bld_proc(mov, new_speed_factor);
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
* Entry point:            0x0042A94B
*/

#ifdef BLD_NATIVE

int SetAutoGenTexture(const char *textureName, int textureEffect)
{
        int (*bld_proc)(const char *textureName, int textureEffect);
        bld_proc = (int (*)(const char *textureName, int textureEffect))GetProcAddress(blade, "SetAutoGenTexture");
        return bld_proc(textureName, textureEffect);
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
* Entry point:            0x0042A98E
*/

#ifdef BLD_NATIVE

const char *GenerateEntityName(void)
{
        const char *(*bld_proc)(void);
        bld_proc = (const char *(*)(void))GetProcAddress(blade, "GenerateEntityName");
        return bld_proc();
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
* Entry point:            0x0042A9A2
*/

#ifdef BLD_NATIVE

int AddWatchAnim(const char *anim)
{
        int (*bld_proc)(const char *anim);
        bld_proc = (int (*)(const char *anim))GetProcAddress(blade, "AddWatchAnim");
        return bld_proc(anim);
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
        bld_proc = (int (*)(
        const char *anim, int wuea, int mdf_y, int solf, int copy_rot,
        int bng_mov, int head_f
))GetProcAddress(blade, "AddAnimFlags");
        return bld_proc(anim, wuea, mdf_y, solf, copy_rot, bng_mov, head_f);
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
        bld_proc = (int (*)(
        const char *action_name, double angle, double start_pos, double end_pos
))GetProcAddress(blade, "SetActionCameraMovement");
        return bld_proc(action_name, angle, start_pos, end_pos);
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
* Entry point:            0x0042ABBA
*/

#ifdef BLD_NATIVE

int SetRootWidget(long int widget)
{
        int (*bld_proc)(long int widget);
        bld_proc = (int (*)(long int widget))GetProcAddress(blade, "SetRootWidget");
        return bld_proc(widget);
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
* Entry point:            0x0042ABF6
*/

#ifdef BLD_NATIVE

long int GetRootWidget(void)
{
        long int (*bld_proc)(void);
        bld_proc = (long int (*)(void))GetProcAddress(blade, "GetRootWidget");
        return bld_proc();
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
        bld_proc = (int (*)(
        const char *object_kind, const char *fire_kind, double upper_treshol,
        double lower_treshold, double flame_height, double flame_size,
        double speed, double livetime
))GetProcAddress(blade, "AddCombustionDataFor");
        return bld_proc(object_kind, fire_kind, upper_treshol, lower_treshold, flame_height, flame_size, speed, livetime);
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
* Entry point:            0x0042AE7A
*/

#ifdef BLD_NATIVE
// TODO fix prototype
void RM_FreeResource()
{
        assert("RM_FreeResource" == NULL);
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
* Entry point:            0x0042AEAE
*/

#ifdef BLD_NATIVE
// TODO fix prototype
void RM_GetResource()
{
        assert("RM_GetResource" == NULL);
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
* Entry point:            0x0042B0F4
*/

#ifdef BLD_NATIVE
// TODO fix prototype
void UpdateAGTexture()
{
        assert("UpdateAGTexture" == NULL);
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
* Entry point:            0x0042B1A5
*/

#ifdef BLD_NATIVE

int SetAfterFrameFunc(const char *name, PyObject *function)
{
        int (*bld_proc)(const char *name, PyObject *function);
        bld_proc = (int (*)(const char *name, PyObject *function))GetProcAddress(blade, "SetAfterFrameFunc");
        return bld_proc(name, function);
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
* Entry point:            0x0042B1E8
*/

#ifdef BLD_NATIVE

int RemoveAfterFrameFunc(const char *name)
{
        int (*bld_proc)(const char *name);
        bld_proc = (int (*)(const char *name))GetProcAddress(blade, "RemoveAfterFrameFunc");
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
* Entry point:            0x0042B227
*/

#ifdef BLD_NATIVE

PyObject *GetAfterFrameFunc(const char *name)
{
        PyObject *(*bld_proc)(const char *name);
        bld_proc = (PyObject *(*)(const char *name))GetProcAddress(blade, "GetAfterFrameFunc");
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
* Entry point:            0x0042B261
*/

#ifdef BLD_NATIVE

const char *GetAfterFrameFuncName(int index)
{
        const char *(*bld_proc)(int index);
        bld_proc = (const char *(*)(int index))GetProcAddress(blade, "GetAfterFrameFuncName");
        return bld_proc(index);
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
* Entry point:            0x0042B29B
*/

#ifdef BLD_NATIVE

int GetnAfterFrameFuncs(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetnAfterFrameFuncs");
        return bld_proc();
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
* Entry point:            0x0042B2D1
*/

#ifdef BLD_NATIVE

int SetMenuTgapFunc(PyObject *func)
{
        int (*bld_proc)(PyObject *func);
        bld_proc = (int (*)(PyObject *func))GetProcAddress(blade, "SetMenuTgapFunc");
        return bld_proc(func);
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
* Entry point:            0x0042B310
*/

#ifdef BLD_NATIVE

PyObject *GetMenuTgapFunc(void)
{
        PyObject *(*bld_proc)(void);
        bld_proc = (PyObject *(*)(void))GetProcAddress(blade, "GetMenuTgapFunc");
        return bld_proc();
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
* Entry point:            0x0042B346
*/

#ifdef BLD_NATIVE

int SetCallCheck(int check)
{
        int (*bld_proc)(int check);
        bld_proc = (int (*)(int check))GetProcAddress(blade, "SetCallCheck");
        return bld_proc(check);
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
* Entry point:            0x0042B366
*/

#ifdef BLD_NATIVE

int OpenDebugChannel(const char *channel_name)
{
        int (*bld_proc)(const char *channel_name);
        bld_proc = (int (*)(const char *channel_name))GetProcAddress(blade, "OpenDebugChannel");
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
* Entry point:            0x0042B39C
*/

#ifdef BLD_NATIVE

int CloseDebugChannel(const char *channel_name)
{
        int (*bld_proc)(const char *channel_name);
        bld_proc = (int (*)(const char *channel_name))GetProcAddress(blade, "CloseDebugChannel");
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
        bld_proc = (int (*)(int action_areas_bit_mask))GetProcAddress(blade, "SetShowAreas");
        return bld_proc(action_areas_bit_mask);
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
* Entry point:            0x0042B453
*/

#ifdef BLD_NATIVE

int WriteText(double x, double y, const char *text)
{
        int (*bld_proc)(double x, double y, const char *text);
        bld_proc = (int (*)(double x, double y, const char *text))GetProcAddress(blade, "WriteText");
        return bld_proc(x, y, text);
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
* Entry point:            0x0042B4EC
*/

#ifdef BLD_NATIVE

void GetTextWH(const char *text, double *w, double *h)
{
        void (*bld_proc)(const char *text, double *w, double *h);
        bld_proc = (void (*)(const char *text, double *w, double *h))GetProcAddress(blade, "GetTextWH");
        bld_proc(text, w, h);
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
        bld_proc = (void (*)(
        double *x_min, double *y_min, double *x_max, double *y_max
))GetProcAddress(blade, "GetScreenRect");
        bld_proc(x_min, y_min, x_max, y_max);
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
        bld_proc = (void (*)(
        double map_x, double map_y, double map_z, double *screen_x,
        double *screen_y
))GetProcAddress(blade, "GetScreenXY");
        bld_proc(map_x, map_y, map_z, screen_x, screen_y);
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
        bld_proc = (int (*)(
        const char *BODName, int x, int y, int w, int h, double scale,
        int i_unknown
))GetProcAddress(blade, "DrawBOD");
        return bld_proc(BODName, x, y, w, h, scale, i_unknown);
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
        bld_proc = (int (*)(
	const char *trigger_sector_name, const char *group_name,
	double floor_height, double roof_height, int num_points,
	point_2d_t *points
))GetProcAddress(blade, "CreateTriggerSector");
        return bld_proc(trigger_sector_name, group_name, floor_height, roof_height, num_points, points);
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
        bld_proc = (int (*)(
        const char *trigger_sector_name, const char *func_type, PyObject *func
))GetProcAddress(blade, "SetTriggerSectorFunc");
        return bld_proc(trigger_sector_name, func_type, func);
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
        bld_proc = (PyObject *(*)(
        const char *trigger_sector_name, const char *func_type
))GetProcAddress(blade, "GetTriggerSectorFunc");
        return bld_proc(trigger_sector_name, func_type);
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
* Entry point:            0x0042BCCC
*/

#ifdef BLD_NATIVE

int GetTriggerSectorFloorHeight(const char *trigger_sector_name)
{
        int (*bld_proc)(const char *trigger_sector_name);
        bld_proc = (int (*)(const char *trigger_sector_name))GetProcAddress(blade, "GetTriggerSectorFloorHeight");
        return bld_proc(trigger_sector_name);
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
* Entry point:            0x0042BCDF
*/

#ifdef BLD_NATIVE

int GetTriggerSectorRoofHeight(const char *trigger_sector_name)
{
        int (*bld_proc)(const char *trigger_sector_name);
        bld_proc = (int (*)(const char *trigger_sector_name))GetProcAddress(blade, "GetTriggerSectorRoofHeight");
        return bld_proc(trigger_sector_name);
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
* Entry point:            0x0042BCF2
*/

#ifdef BLD_NATIVE

const char *GetTriggerSectorGroup(const char *trigger_sector_name)
{
        const char *(*bld_proc)(const char *trigger_sector_name);
        bld_proc = (const char *(*)(const char *trigger_sector_name))GetProcAddress(blade, "GetTriggerSectorGroup");
        return bld_proc(trigger_sector_name);
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
* Entry point:            0x0042BD05
*/

#ifdef BLD_NATIVE

double *GetTriggerSectorPoints(const char *trigger_sector_name)
{
        double *(*bld_proc)(const char *trigger_sector_name);
        bld_proc = (double *(*)(const char *trigger_sector_name))GetProcAddress(blade, "GetTriggerSectorPoints");
        return bld_proc(trigger_sector_name);
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
        bld_proc = (int (*)(
        const char *trigger_sector_name, PyObject *data
))GetProcAddress(blade, "SetTriggerSectorData");
        return bld_proc(trigger_sector_name, data);
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
* Entry point:            0x0042BD2F
*/

#ifdef BLD_NATIVE

PyObject *GetTriggerSectorData(const char *trigger_sector_name)
{
        PyObject *(*bld_proc)(const char *trigger_sector_name);
        bld_proc = (PyObject *(*)(const char *trigger_sector_name))GetProcAddress(blade, "GetTriggerSectorData");
        return bld_proc(trigger_sector_name);
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
* Entry point:            0x0042BD42
*/

#ifdef BLD_NATIVE

int nTriggerSectors(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "nTriggerSectors");
        return bld_proc();
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
* Entry point:            0x0042BD55
*/

#ifdef BLD_NATIVE

const char *GetTriggerSectorName(int index)
{
        const char *(*bld_proc)(int index);
        bld_proc = (const char *(*)(int index))GetProcAddress(blade, "GetTriggerSectorName");
        return bld_proc(index);
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
* Entry point:            0x0042BD68
*/

#ifdef BLD_NATIVE

int GetModelPos(const char *person, double *x, double *y, double *z)
{
        int (*bld_proc)(const char *person, double *x, double *y, double *z);
        bld_proc = (int (*)(const char *person, double *x, double *y, double *z))GetProcAddress(blade, "GetModelPos");
        return bld_proc(person, x, y, z);
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
* Entry point:            0x0042BFF8
*/

#ifdef BLD_NATIVE

int GetWindowId(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetWindowId");
        return bld_proc();
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
* Entry point:            0x0042C031
*/

#ifdef BLD_NATIVE

int GetProgramId(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetProgramId");
        return bld_proc();
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
* Entry point:            0x0042C06A
*/

#ifdef BLD_NATIVE

void TakeSnapShot(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "TakeSnapShot");
        bld_proc();
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
* Entry point:            0x0042C0A5
*/

#ifdef BLD_NATIVE

int nSectors(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "nSectors");
        return bld_proc();
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
* Entry point:            0x0042C0AF
*/

#ifdef BLD_NATIVE

void SetRunString(const char *variable)
{
        void (*bld_proc)(const char *variable);
        bld_proc = (void (*)(const char *variable))GetProcAddress(blade, "SetRunString");
        bld_proc(variable);
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
* Entry point:            0x0042C0EC
*/

#ifdef BLD_NATIVE

int SetStringValue(const char *variable, const char *value)
{
        int (*bld_proc)(const char *variable, const char *value);
        bld_proc = (int (*)(const char *variable, const char *value))GetProcAddress(blade, "SetStringValue");
        return bld_proc(variable, value);
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
* Entry point:            0x0042C12A
*/

#ifdef BLD_NATIVE

const char *GetStringValue(const char *variable)
{
        const char *(*bld_proc)(const char *variable);
        bld_proc = (const char *(*)(const char *variable))GetProcAddress(blade, "GetStringValue");
        return bld_proc(variable);
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
* Entry point:            0x0042C164
*/

#ifdef BLD_NATIVE

int DeleteStringValue(const char *variable)
{
        int (*bld_proc)(const char *variable);
        bld_proc = (int (*)(const char *variable))GetProcAddress(blade, "DeleteStringValue");
        return bld_proc(variable);
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
* Entry point:            0x0042C19E
*/

#ifdef BLD_NATIVE

int SaveProfileData(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "SaveProfileData");
        return bld_proc(file_name);
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
* Entry point:            0x0042C1B9
*/

#ifdef BLD_NATIVE

int OpenProfileSection(int section, const char *comment)
{
        int (*bld_proc)(int section, const char *comment);
        bld_proc = (int (*)(int section, const char *comment))GetProcAddress(blade, "OpenProfileSection");
        return bld_proc(section, comment);
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
* Entry point:            0x0042C1D4
*/

#ifdef BLD_NATIVE

int CloseProfileSection(int section)
{
        int (*bld_proc)(int section);
        bld_proc = (int (*)(int section))GetProcAddress(blade, "CloseProfileSection");
        return bld_proc(section);
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
* Entry point:            0x0042C1EF
*/

#ifdef BLD_NATIVE

int StartProfile(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "StartProfile");
        return bld_proc();
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
* Entry point:            0x0042C20A
*/

#ifdef BLD_NATIVE

int EnableProfiler(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "EnableProfiler");
        return bld_proc();
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
* Entry point:            0x0042C225
*/

#ifdef BLD_NATIVE

int DisableProfiler(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "DisableProfiler");
        return bld_proc();
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
* Entry point:            0x0042C240
*/

#ifdef BLD_NATIVE

int SetInputMode(const char *device, const char *mode)
{
        int (*bld_proc)(const char *device, const char *mode);
        bld_proc = (int (*)(const char *device, const char *mode))GetProcAddress(blade, "SetInputMode");
        return bld_proc(device, mode);
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
* Entry point:            0x0042C281
*/

#ifdef BLD_NATIVE

const char *GetInputMode(const char *device)
{
        const char *(*bld_proc)(const char *device);
        bld_proc = (const char *(*)(const char *device))GetProcAddress(blade, "GetInputMode");
        return bld_proc(device);
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
* Entry point:            0x0042C2BE
*/

#ifdef BLD_NATIVE

const char *GetLastPlayerCType(void)
{
        const char *(*bld_proc)(void);
        bld_proc = (const char *(*)(void))GetProcAddress(blade, "GetLastPlayerCType");
        return bld_proc();
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
* Entry point:            0x004431DE
*/

#ifdef BLD_NATIVE

int WorldToMBW(const char *world)
{
        int (*bld_proc)(const char *world);
        bld_proc = (int (*)(const char *world))GetProcAddress(blade, "WorldToMBW");
        return bld_proc(world);
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
* Entry point:            0x0044E9A0
*/

#ifdef BLD_NATIVE

int nMaterials(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "nMaterials");
        return bld_proc();
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
* Entry point:            0x0044E9AA
*/

#ifdef BLD_NATIVE

material_t *CreateMaterial(const char *name)
{
        material_t *(*bld_proc)(const char *name);
        bld_proc = (material_t *(*)(const char *name))GetProcAddress(blade, "CreateMaterial");
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
* Entry point:            0x0044EB5A
*/

#ifdef BLD_NATIVE

material_t *GetMaterial(const char *name)
{
        material_t *(*bld_proc)(const char *name);
        bld_proc = (material_t *(*)(const char *name))GetProcAddress(blade, "GetMaterial");
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
* Entry point:            0x0044EBD3
*/

#ifdef BLD_NATIVE

material_t *GetMaterialI(int index)
{
        material_t *(*bld_proc)(int index);
        bld_proc = (material_t *(*)(int index))GetProcAddress(blade, "GetMaterialI");
        return bld_proc(index);
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
* Entry point:            0x0044EC02
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0044EC62
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0044ECC5
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0044ECF8
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0044ED29
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0044ED6A
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045C040
*/

#ifdef BLD_NATIVE

int GetSectorByPosition(double x, double y, double z)
{
        int (*bld_proc)(double x, double y, double z);
        bld_proc = (int (*)(double x, double y, double z))GetProcAddress(blade, "GetSectorByPosition");
        return bld_proc(x, y, z);
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
* Entry point:            0x0045C080
*/

#ifdef BLD_NATIVE

int GetSectorByIndex(int index)
{
        int (*bld_proc)(int index);
        bld_proc = (int (*)(int index))GetProcAddress(blade, "GetSectorByIndex");
        return bld_proc(index);
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
* Entry point:            0x0045C0A3
*/

#ifdef BLD_NATIVE
// TODO fix prototype
void GetNumberOfSectors()
{
        assert("GetNumberOfSectors" == NULL);
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
* Entry point:            0x0045C0AD
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045C159
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045C1F5
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045C34D
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045C415
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045C5A6
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045C735
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045C8B0
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045C9A0
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045CA86
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045CB7C
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0045CCD8
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0046AB6A
*/

#ifdef BLD_NATIVE

int GetAnimationDuration(const char *animation_name, double *duration)
{
        int (*bld_proc)(const char *animation_name, double *duration);
        bld_proc = (int (*)(const char *animation_name, double *duration))GetProcAddress(blade, "GetAnimationDuration");
        return bld_proc(animation_name, duration);
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
* Entry point:            0x0046AC16
*/

#ifdef BLD_NATIVE

int RStepEvents(const char *s_unknown1, const char *s_unknown2)
{
        int (*bld_proc)(const char *s_unknown1, const char *s_unknown2);
        bld_proc = (int (*)(const char *s_unknown1, const char *s_unknown2))GetProcAddress(blade, "RStepEvents");
        return bld_proc(s_unknown1, s_unknown2);
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
* Entry point:            0x0046AEEC
*/

#ifdef BLD_NATIVE

int LStepEvents(const char *s_unknown1, const char *s_unknown2)
{
        int (*bld_proc)(const char *s_unknown1, const char *s_unknown2);
        bld_proc = (int (*)(const char *s_unknown1, const char *s_unknown2))GetProcAddress(blade, "LStepEvents");
        return bld_proc(s_unknown1, s_unknown2);
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
* Entry point:            0x0046B885
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0046C4D9
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0046CAFB
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0046D1F0
*/

#ifdef BLD_NATIVE

int AddRStepEvent(const char *animation_name, double d_unknown)
{
        int (*bld_proc)(const char *animation_name, double d_unknown);
        bld_proc = (int (*)(const char *animation_name, double d_unknown))GetProcAddress(blade, "AddRStepEvent");
        return bld_proc(animation_name, d_unknown);
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
* Entry point:            0x0046D3DE
*/

#ifdef BLD_NATIVE

int AddLStepEvent(const char *animation_name, double d_unknown)
{
        int (*bld_proc)(const char *animation_name, double d_unknown);
        bld_proc = (int (*)(const char *animation_name, double d_unknown))GetProcAddress(blade, "AddLStepEvent");
        return bld_proc(animation_name, d_unknown);
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
* Entry point:            0x0046D5CC
*/

#ifdef BLD_NATIVE

int AddRReleaseEvent(const char *animation_name, double d_unknown)
{
        int (*bld_proc)(const char *animation_name, double d_unknown);
        bld_proc = (int (*)(const char *animation_name, double d_unknown))GetProcAddress(blade, "AddRReleaseEvent");
        return bld_proc(animation_name, d_unknown);
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
* Entry point:            0x0046D7BA
*/

#ifdef BLD_NATIVE

int AddLReleaseEvent(const char *animation_name, double d_unknown)
{
        int (*bld_proc)(const char *animation_name, double d_unknown);
        bld_proc = (int (*)(const char *animation_name, double d_unknown))GetProcAddress(blade, "AddLReleaseEvent");
        return bld_proc(animation_name, d_unknown);
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
* Entry point:            0x0046D9A8
*/

#ifdef BLD_NATIVE

void AddAnmEvent(const char *anm_name, const char *event_name, double event_frame)
{
        void (*bld_proc)(const char *anm_name, const char *event_name, double event_frame);
        bld_proc = (void (*)(const char *anm_name, const char *event_name, double event_frame))GetProcAddress(blade, "AddAnmEvent");
        bld_proc(anm_name, event_name, event_frame);
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
* Entry point:            0x0046E1AB
*/

#ifdef BLD_NATIVE

void AddStopTests(const char *animation_name)
{
        void (*bld_proc)(const char *animation_name);
        bld_proc = (void (*)(const char *animation_name))GetProcAddress(blade, "AddStopTests");
        bld_proc(animation_name);
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
* Entry point:            0x0046E4AC
*/

#ifdef BLD_NATIVE

void AddFloorCTolerance(const char *animation_name, double tolerance)
{
        void (*bld_proc)(const char *animation_name, double tolerance);
        bld_proc = (void (*)(const char *animation_name, double tolerance))GetProcAddress(blade, "AddFloorCTolerance");
        bld_proc(animation_name, tolerance);
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
* Entry point:            0x0046E57A
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0046E93B
*/

#ifdef BLD_NATIVE

int CheckAnims(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "CheckAnims");
        return bld_proc();
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
* Entry point:            0x0046EBFD
*/

#ifdef BLD_NATIVE

int GiveAnims(const char *race_name)
{
        int (*bld_proc)(const char *race_name);
        bld_proc = (int (*)(const char *race_name))GetProcAddress(blade, "GiveAnims");
        return bld_proc(race_name);
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
* Entry point:            0x00491B70
*/

#ifdef BLD_NATIVE

int AddStepSound(const char *name, int soundID)
{
        int (*bld_proc)(const char *name, int soundID);
        bld_proc = (int (*)(const char *name, int soundID))GetProcAddress(blade, "AddStepSound");
        return bld_proc(name, soundID);
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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE

int AddTextureMaterial(const char *texture, const char *material)
{
        int (*bld_proc)(const char *texture, const char *material);
        bld_proc = (int (*)(const char *texture, const char *material))GetProcAddress(blade, "AddTextureMaterial");
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

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004BF1EF
*/

#ifdef BLD_NATIVE

int CreateSound(const char *file_name, const char *sound_name)
{
        int (*bld_proc)(const char *file_name, const char *sound_name);
        bld_proc = (int (*)(const char *file_name, const char *sound_name))GetProcAddress(blade, "CreateSound");
        return bld_proc(file_name, sound_name);
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
* Entry point:            0x004BF236
*/

#ifdef BLD_NATIVE

int CreateSoundS(int soundID)
{
        int (*bld_proc)(int soundID);
        bld_proc = (int (*)(int soundID))GetProcAddress(blade, "CreateSoundS");
        return bld_proc(soundID);
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
* Entry point:            0x004BF25D
*/

#ifdef BLD_NATIVE

void DestroySound(int soundID)
{
        void (*bld_proc)(int soundID);
        bld_proc = (void (*)(int soundID))GetProcAddress(blade, "DestroySound");
        bld_proc(soundID);
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
* Entry point:            0x004BF2A4
*/

#ifdef BLD_NATIVE

int SetSoundVolume(double volume)
{
        int (*bld_proc)(double volume);
        bld_proc = (int (*)(double volume))GetProcAddress(blade, "SetSoundVolume");
        return bld_proc(volume);
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
* Entry point:            0x004BF2D8
*/

#ifdef BLD_NATIVE

double GetSoundVolume(void)
{
        double (*bld_proc)(void);
        bld_proc = (double (*)(void))GetProcAddress(blade, "GetSoundVolume");
        return bld_proc();
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
* Entry point:            0x004BF2FE
*/

#ifdef BLD_NATIVE

int SoundSystemActive(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "SoundSystemActive");
        return bld_proc();
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
* Entry point:            0x004BF31A
*/

#ifdef BLD_NATIVE

int SetSSFrecuency(int frequency)
{
        int (*bld_proc)(int frequency);
        bld_proc = (int (*)(int frequency))GetProcAddress(blade, "SetSSFrecuency");
        return bld_proc(frequency);
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
* Entry point:            0x004BF34D
*/

#ifdef BLD_NATIVE

int SetSS2dChannels(int num_ch)
{
        int (*bld_proc)(int num_ch);
        bld_proc = (int (*)(int num_ch))GetProcAddress(blade, "SetSS2dChannels");
        return bld_proc(num_ch);
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
* Entry point:            0x004BF380
*/

#ifdef BLD_NATIVE

int SetSS3dChannels(int num_ch)
{
        int (*bld_proc)(int num_ch);
        bld_proc = (int (*)(int num_ch))GetProcAddress(blade, "SetSS3dChannels");
        return bld_proc(num_ch);
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
* Entry point:            0x004BF3B3
*/

#ifdef BLD_NATIVE

int SetSSFilter(int filter_output)
{
        int (*bld_proc)(int filter_output);
        bld_proc = (int (*)(int filter_output))GetProcAddress(blade, "SetSSFilter");
        return bld_proc(filter_output);
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
* Entry point:            0x004BF3E6
*/

#ifdef BLD_NATIVE

int KillMusic(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "KillMusic");
        return bld_proc();
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
* Entry point:            0x004BF410
*/

#ifdef BLD_NATIVE

int ShutDownSoundChannels(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "ShutDownSoundChannels");
        return bld_proc();
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
* Entry point:            0x004BF43A
*/

#ifdef BLD_NATIVE

int PauseSoundSystem(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "PauseSoundSystem");
        return bld_proc();
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
* Entry point:            0x004BF470
*/

#ifdef BLD_NATIVE

int PauseSoundSystemButMusic(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "PauseSoundSystemButMusic");
        return bld_proc();
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
* Entry point:            0x004BF492
*/

#ifdef BLD_NATIVE

int ResumeSoundSystem(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "ResumeSoundSystem");
        return bld_proc();
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
* Entry point:            0x004BF4C8
*/

#ifdef BLD_NATIVE

int SetMusicVolume(float volume)
{
        int (*bld_proc)(float volume);
        bld_proc = (int (*)(float volume))GetProcAddress(blade, "SetMusicVolume");
        return bld_proc(volume);
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
* Entry point:            0x004BF4F4
*/

#ifdef BLD_NATIVE

double GetMusicVolume(void)
{
        double (*bld_proc)(void);
        bld_proc = (double (*)(void))GetProcAddress(blade, "GetMusicVolume");
        return bld_proc();
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
* Entry point:            0x004BF51A
*/

#ifdef BLD_NATIVE

int GetSSQuality(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetSSQuality");
        return bld_proc();
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
* Entry point:            0x004BF53C
*/

#ifdef BLD_NATIVE

int SetSSQuality(int SSQuality)
{
        int (*bld_proc)(int SSQuality);
        bld_proc = (int (*)(int SSQuality))GetProcAddress(blade, "SetSSQuality");
        return bld_proc(SSQuality);
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
* Entry point:            0x004BF563
*/

#ifdef BLD_NATIVE

int GetSSSpeakerConfig(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetSSSpeakerConfig");
        return bld_proc();
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
* Entry point:            0x004BF5E2
*/

#ifdef BLD_NATIVE

int SetEAXOverride(int EAXOverride)
{
        int (*bld_proc)(int EAXOverride);
        bld_proc = (int (*)(int EAXOverride))GetProcAddress(blade, "SetEAXOverride");
        return bld_proc(EAXOverride);
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
* Entry point:            0x004BF63F
*/

#ifdef BLD_NATIVE

int GetEAXOverride(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetEAXOverride");
        return bld_proc();
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
* Entry point:            0x004BF656
*/

#ifdef BLD_NATIVE

int SaveSSConfig(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "SaveSSConfig");
        return bld_proc();
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
* Entry point:            0x004BF678
*/

#ifdef BLD_NATIVE

int SetSSSpeakerConfig(int config)
{
        int (*bld_proc)(int config);
        bld_proc = (int (*)(int config))GetProcAddress(blade, "SetSSSpeakerConfig");
        return bld_proc(config);
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
* Entry point:            0x004BF75B
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004BF957
*/

#ifdef BLD_NATIVE

int SetEAX(int eax_flag)
{
        int (*bld_proc)(int eax_flag);
        bld_proc = (int (*)(int eax_flag))GetProcAddress(blade, "SetEAX");
        return bld_proc(eax_flag);
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
* Entry point:            0x004BF95E
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004BFEAB
*/

#ifdef BLD_NATIVE

int GetGhostSectorSound(const char *gs_name)
{
        int (*bld_proc)(const char *gs_name);
        bld_proc = (int (*)(const char *gs_name))GetProcAddress(blade, "GetGhostSectorSound");
        return bld_proc(gs_name);
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
* Entry point:            0x004BFEEA
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004BFEF1
*/

#ifdef BLD_NATIVE

int SetShowSounds(int showSounds)
{
        int (*bld_proc)(int showSounds);
        bld_proc = (int (*)(int showSounds))GetProcAddress(blade, "SetShowSounds");
        return bld_proc(showSounds);
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
* Entry point:            0x004BFEFB
*/

#ifdef BLD_NATIVE

int GetSoundDevInstace(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetSoundDevInstace");
        return bld_proc();
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
* Entry point:            0x004BFF02
*/

#ifdef BLD_NATIVE

int nSounds(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "nSounds");
        return bld_proc();
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
* Entry point:            0x004BFF27
*/

#ifdef BLD_NATIVE

const char *GetSoundName(int soundId)
{
        const char *(*bld_proc)(int soundId);
        bld_proc = (const char *(*)(int soundId))GetProcAddress(blade, "GetSoundName");
        return bld_proc(soundId);
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
* Entry point:            0x004BFF44
*/

#ifdef BLD_NATIVE

const char *GetSoundFileName(int soundId)
{
        const char *(*bld_proc)(int soundId);
        bld_proc = (const char *(*)(int soundId))GetProcAddress(blade, "GetSoundFileName");
        return bld_proc(soundId);
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
* Entry point:            0x004BFF6E
*/

#ifdef BLD_NATIVE

int PlaySoundM(int soundID, double x, double y, double z, int i_unknown)
{
        int (*bld_proc)(int soundID, double x, double y, double z, int i_unknown);
        bld_proc = (int (*)(int soundID, double x, double y, double z, int i_unknown))GetProcAddress(blade, "PlaySoundM");
        return bld_proc(soundID, x, y, z, i_unknown);
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
* Entry point:            0x004BFFEE
*/

#ifdef BLD_NATIVE

int PlaySoundStereo(int soundID, int i_unknown)
{
        int (*bld_proc)(int soundID, int i_unknown);
        bld_proc = (int (*)(int soundID, int i_unknown))GetProcAddress(blade, "PlaySoundStereo");
        return bld_proc(soundID, i_unknown);
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
* Entry point:            0x004C003B
*/

#ifdef BLD_NATIVE

int StopSound(int soundID)
{
        int (*bld_proc)(int soundID);
        bld_proc = (int (*)(int soundID))GetProcAddress(blade, "StopSound");
        return bld_proc(soundID);
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
* Entry point:            0x004C0082
*/

#ifdef BLD_NATIVE

double GetSoundFloatProperty(int property_kind, int soundID)
{
        double (*bld_proc)(int property_kind, int soundID);
        bld_proc = (double (*)(int property_kind, int soundID))GetProcAddress(blade, "GetSoundFloatProperty");
        return bld_proc(property_kind, soundID);
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
* Entry point:            0x004C0143
*/

#ifdef BLD_NATIVE

void SetSoundFloatProperty(int property_kind, int soundID, double value)
{
        void (*bld_proc)(int property_kind, int soundID, double value);
        bld_proc = (void (*)(int property_kind, int soundID, double value))GetProcAddress(blade, "SetSoundFloatProperty");
        bld_proc(property_kind, soundID, value);
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
* Entry point:            0x004C0293
*/

#ifdef BLD_NATIVE

char *GetSoundStringProperty(int property_kind, int soundID)
{
        char *(*bld_proc)(int property_kind, int soundID);
        bld_proc = (char *(*)(int property_kind, int soundID))GetProcAddress(blade, "GetSoundStringProperty");
        return bld_proc(property_kind, soundID);
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
* Entry point:            0x004C02E9
*/

#ifdef BLD_NATIVE
// TODO fix prototype
void SetSoundStringProperty()
{
        assert("SetSoundStringProperty" == NULL);
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
* Entry point:            0x004C02F0
*/

#ifdef BLD_NATIVE
// TODO fix prototype
void GetSoundIntProperty()
{
        assert("GetSoundIntProperty" == NULL);
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
* Entry point:            0x004C033D
*/

#ifdef BLD_NATIVE

void SetSoundIntProperty(int property_kind, int soundID, int value)
{
        void (*bld_proc)(int property_kind, int soundID, int value);
        bld_proc = (void (*)(int property_kind, int soundID, int value))GetProcAddress(blade, "SetSoundIntProperty");
        bld_proc(property_kind, soundID, value);
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
* Entry point:            0x004C0394
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004C03B7
*/

#ifdef BLD_NATIVE
// TODO fix prototype
void GetSoundFuncProperty()
{
        assert("GetSoundFuncProperty" == NULL);
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
* Entry point:            0x004C0436
*/

#ifdef BLD_NATIVE
// TODO fix prototype
void SetSoundFuncProperty()
{
        assert("SetSoundFuncProperty" == NULL);
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
* Entry point:            0x004C0508
*/

#ifdef BLD_NATIVE

int dropDebugInfo(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "dropDebugInfo");
        return bld_proc();
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
* Entry point:            0x004C052F
*/

#ifdef BLD_NATIVE

int GetMusicEventPriority(int unknown)
{
        int (*bld_proc)(int unknown);
        bld_proc = (int (*)(int unknown))GetProcAddress(blade, "GetMusicEventPriority");
        return bld_proc(unknown);
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
* Entry point:            0x004C0550
*/

#ifdef BLD_NATIVE

int getMusicEvent(const char *event_name)
{
        int (*bld_proc)(const char *event_name);
        bld_proc = (int (*)(const char *event_name))GetProcAddress(blade, "getMusicEvent");
        return bld_proc(event_name);
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
* Entry point:            0x004C0571
*/

#ifdef BLD_NATIVE

int exeMusicEvent(int unknown1, int unknown2)
{
        int (*bld_proc)(int unknown1, int unknown2);
        bld_proc = (int (*)(int unknown1, int unknown2))GetProcAddress(blade, "exeMusicEvent");
        return bld_proc(unknown1, unknown2);
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
* Entry point:            0x004C05A0
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004C05F5
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004C064B
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004C06A1
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004C06F7
*/

#ifdef BLD_NATIVE

int GetSound(const char *sound_name)
{
        int (*bld_proc)(const char *sound_name);
        bld_proc = (int (*)(const char *sound_name))GetProcAddress(blade, "GetSound");
        return bld_proc(sound_name);
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
* Entry point:            0x004C071E
*/

#ifdef BLD_NATIVE

int addSoundVar(int soundID, const char *alt_sound)
{
        int (*bld_proc)(int soundID, const char *alt_sound);
        bld_proc = (int (*)(int soundID, const char *alt_sound))GetProcAddress(blade, "addSoundVar");
        return bld_proc(soundID, alt_sound);
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
* Entry point:            0x004C0750
*/

#ifdef BLD_NATIVE

void saveSoundStats(const char *file_name)
{
        void (*bld_proc)(const char *file_name);
        bld_proc = (void (*)(const char *file_name))GetProcAddress(blade, "saveSoundStats");
        bld_proc(file_name);
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
* Entry point:            0x004C0779
*/

#ifdef BLD_NATIVE

int loadMusicState(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "loadMusicState");
        return bld_proc(file_name);
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
* Entry point:            0x004C07D1
*/

#ifdef BLD_NATIVE

int saveMusicState(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "saveMusicState");
        return bld_proc(file_name);
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
* Entry point:            0x004C0897
*/

#ifdef BLD_NATIVE

int loadSoundDataBase(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "loadSoundDataBase");
        return bld_proc(file_name);
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
* Entry point:            0x004C08F0
*/

#ifdef BLD_NATIVE

int saveSoundDataBase(const char *file_name)
{
        int (*bld_proc)(const char *file_name);
        bld_proc = (int (*)(const char *file_name))GetProcAddress(blade, "saveSoundDataBase");
        return bld_proc(file_name);
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
* Entry point:            0x004FFEA0
*/

#ifdef BLD_NATIVE

int GetSplinePos(void *spline, float time, void *pos)
{
        int (*bld_proc)(void *spline, float time, void *pos);
        bld_proc = (int (*)(void *spline, float time, void *pos))GetProcAddress(blade, "GetSplinePos");
        return bld_proc(spline, time, pos);
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
* Entry point:            0x004FFEBA
*/

#ifdef BLD_NATIVE

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

#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004FFEF3
*/

#ifdef BLD_NATIVE

int CloseSpline(void *spline)
{
        int (*bld_proc)(void *spline);
        bld_proc = (int (*)(void *spline))GetProcAddress(blade, "CloseSpline");
        return bld_proc(spline);
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
* Entry point:            0x004FFF00
*/

#ifdef BLD_NATIVE

int ClearSpline(void *spline)
{
        int (*bld_proc)(void *spline);
        bld_proc = (int (*)(void *spline))GetProcAddress(blade, "ClearSpline");
        return bld_proc(spline);
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
* Entry point:            0x004FFF0D
*/

#ifdef BLD_NATIVE

entity_t *CreateSpark(
        const char *name, point_3d_t *spark_point, point_3d_t *spark_dir,
        double d_unknown1, double d_unknown2, double d_unknown3,
        double d_unknown4, double d_unknown5, int i_unknown6, int i_unknown7,
        int i_unknown8, int i_unknown9, int i_unknown10, int i_unknown11,
        float d_unknown12, float d_unknown13, float d_unknown14, int i_unknown15
)
{
        entity_t *(*bld_proc)(
        const char *name, point_3d_t *spark_point, point_3d_t *spark_dir,
        double d_unknown1, double d_unknown2, double d_unknown3,
        double d_unknown4, double d_unknown5, int i_unknown6, int i_unknown7,
        int i_unknown8, int i_unknown9, int i_unknown10, int i_unknown11,
        float d_unknown12, float d_unknown13, float d_unknown14, int i_unknown15
);
        bld_proc = (entity_t *(*)(
        const char *name, point_3d_t *spark_point, point_3d_t *spark_dir,
        double d_unknown1, double d_unknown2, double d_unknown3,
        double d_unknown4, double d_unknown5, int i_unknown6, int i_unknown7,
        int i_unknown8, int i_unknown9, int i_unknown10, int i_unknown11,
        float d_unknown12, float d_unknown13, float d_unknown14, int i_unknown15
))GetProcAddress(blade, "CreateSpark");
        return bld_proc(name, spark_point, spark_dir, d_unknown1, d_unknown2, d_unknown3, d_unknown4, d_unknown5, i_unknown6, i_unknown7, i_unknown8, i_unknown9, i_unknown10, i_unknown11, d_unknown12, d_unknown13, d_unknown14, i_unknown15);
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
* Entry point:            0x00500036
*/

#ifdef BLD_NATIVE

entity_t *CreateEntity(
        const char *name, const char *kind, double x, double y, double z,
        const char *parent_class, const char *unknown
)
{
        entity_t *(*bld_proc)(
        const char *name, const char *kind, double x, double y, double z,
        const char *parent_class, const char *unknown
);
        bld_proc = (entity_t *(*)(
        const char *name, const char *kind, double x, double y, double z,
        const char *parent_class, const char *unknown
))GetProcAddress(blade, "CreateEntity");
        return bld_proc(name, kind, x, y, z, parent_class, unknown);
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
* Entry point:            0x00501FE9
*/

#ifdef BLD_NATIVE

int DeleteEntity(const char *name)
{
        int (*bld_proc)(const char *name);
        bld_proc = (int (*)(const char *name))GetProcAddress(blade, "DeleteEntity");
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

entity_t *CreateEntityDecal(
        const char *name, double x, double y, double z, int i_unknown,
        double d_unknown1, double d_unknown2
)
{
        entity_t *(*bld_proc)(
        const char *name, double x, double y, double z, int i_unknown,
        double d_unknown1, double d_unknown2
);
        bld_proc = (entity_t *(*)(
        const char *name, double x, double y, double z, int i_unknown,
        double d_unknown1, double d_unknown2
))GetProcAddress(blade, "CreateEntityDecal");
        return bld_proc(name, x, y, z, i_unknown, d_unknown1, d_unknown2);
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
* Entry point:            0x0050340C
*/

#ifdef BLD_NATIVE

entity_t *GetEntity(const char *name)
{
        entity_t *(*bld_proc)(const char *name);
        bld_proc = (entity_t *(*)(const char *name))GetProcAddress(blade, "GetEntity");
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
* Entry point:            0x0050360D
*/

#ifdef BLD_NATIVE

entity_t *GetEntityI(int index)
{
        entity_t *(*bld_proc)(int index);
        bld_proc = (entity_t *(*)(int index))GetProcAddress(blade, "GetEntityI");
        return bld_proc(index);
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
* Entry point:            0x005036B2
*/

#ifdef BLD_NATIVE

const char *GetEntityName(entity_t *entity)
{
        const char *(*bld_proc)(entity_t *entity);
        bld_proc = (const char *(*)(entity_t *entity))GetProcAddress(blade, "GetEntityName");
        return bld_proc(entity);
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
* Entry point:            0x005036E1
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***entity_names
))GetProcAddress(blade, "GetEntitiesVisibleFrom");
        return bld_proc(xc, yc, zc, radius, xdir, ydir, zdir, angle, entity_names);
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
);
        bld_proc = (int (*)(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***entity_names
))GetProcAddress(blade, "GetObjectEntitiesVisibleFrom");
        return bld_proc(xc, yc, zc, radius, xdir, ydir, zdir, angle, entity_names);
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
);
        bld_proc = (int (*)(
        double xc, double yc, double zc, double radius, double xdir,
        double ydir, double zdir, double angle, char ***enemy_names
))GetProcAddress(blade, "GetEnemiesVisibleFrom");
        return bld_proc(xc, yc, zc, radius, xdir, ydir, zdir, angle, enemy_names);
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
);
        bld_proc = (int (*)(
        const char *person_name, int num_combos, char **combos_names,
        int *combos_executed
))GetProcAddress(blade, "SetCombos");
        return bld_proc(person_name, num_combos, combos_names, combos_executed);
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
* Entry point:            0x00504527
*/

#ifdef BLD_NATIVE

int GetCombos(const char *person_name, combo_t **combos)
{
        int (*bld_proc)(const char *person_name, combo_t **combos);
        bld_proc = (int (*)(const char *person_name, combo_t **combos))GetProcAddress(blade, "GetCombos");
        return bld_proc(person_name, combos);
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
* Entry point:            0x005045A6
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00504629
*/

#ifdef BLD_NATIVE

int nEntities(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "nEntities");
        return bld_proc();
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
* Entry point:            0x0050463C
*/

#ifdef BLD_NATIVE

int GetNewExclusionGroupId(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetNewExclusionGroupId");
        return bld_proc();
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
* Entry point:            0x00504646
*/

#ifdef BLD_NATIVE

int AddCameraEvent(const char *entity_name, int frame, PyObject *func)
{
        int (*bld_proc)(const char *entity_name, int frame, PyObject *func);
        bld_proc = (int (*)(const char *entity_name, int frame, PyObject *func))GetProcAddress(blade, "AddCameraEvent");
        return bld_proc(entity_name, frame, func);
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
* Entry point:            0x00504695
*/

#ifdef BLD_NATIVE

int DeleteCameraEvent(const char *entity_name, int frame)
{
        int (*bld_proc)(const char *entity_name, int frame);
        bld_proc = (int (*)(const char *entity_name, int frame))GetProcAddress(blade, "DeleteCameraEvent");
        return bld_proc(entity_name, frame);
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
* Entry point:            0x005046DB
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0050472F
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00504783
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x005047D2
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
))GetProcAddress(blade, "CameraSetStartTangentTargetNode");
        return bld_proc(entity_name, unknown1, unknown2, unknown3, unknown4);
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
);
        bld_proc = (int (*)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
))GetProcAddress(blade, "CameraSetEndTangentTargetNode");
        return bld_proc(entity_name, unknown1, unknown2, unknown3, unknown4);
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
* Entry point:            0x005048BF
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        const char *entity_name, const char *cam_file_name, int i_unknown,
        int num_frames
))GetProcAddress(blade, "CameraSetMaxCamera");
        return bld_proc(entity_name, cam_file_name, i_unknown, num_frames);
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
* Entry point:            0x00504953
*/

#ifdef BLD_NATIVE

int CameraCut(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "CameraCut");
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
* Entry point:            0x005049E2
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00504A2C
*/

#ifdef BLD_NATIVE

int CameraClearPath(const char *entity_name, int node)
{
        int (*bld_proc)(const char *entity_name, int node);
        bld_proc = (int (*)(const char *entity_name, int node))GetProcAddress(blade, "CameraClearPath");
        return bld_proc(entity_name, node);
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
* Entry point:            0x00504ABA
*/

#ifdef BLD_NATIVE

int CameraStartPath(const char *entity_name, int node)
{
        int (*bld_proc)(const char *entity_name, int node);
        bld_proc = (int (*)(const char *entity_name, int node))GetProcAddress(blade, "CameraStartPath");
        return bld_proc(entity_name, node);
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
* Entry point:            0x00504B29
*/

#ifdef BLD_NATIVE

int UseEntity(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "UseEntity");
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
* Entry point:            0x00504B5F
*/

#ifdef BLD_NATIVE

int ChangeEntityStatic(const char *entity_name, int is_static)
{
        int (*bld_proc)(const char *entity_name, int is_static);
        bld_proc = (int (*)(const char *entity_name, int is_static))GetProcAddress(blade, "ChangeEntityStatic");
        return bld_proc(entity_name, is_static);
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
* Entry point:            0x005050DD
*/

#ifdef BLD_NATIVE

int ChangeEntityActor(const char *entity_name, int is_actor)
{
        int (*bld_proc)(const char *entity_name, int is_actor);
        bld_proc = (int (*)(const char *entity_name, int is_actor))GetProcAddress(blade, "ChangeEntityActor");
        return bld_proc(entity_name, is_actor);
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
* Entry point:            0x00505F63
*/

#ifdef BLD_NATIVE

int ChangeEntityPerson(const char *entity_name, int is_person)
{
        int (*bld_proc)(const char *entity_name, int is_person);
        bld_proc = (int (*)(const char *entity_name, int is_person))GetProcAddress(blade, "ChangeEntityPerson");
        return bld_proc(entity_name, is_person);
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
* Entry point:            0x00506E31
*/

#ifdef BLD_NATIVE

int ChangeEntityWeapon(const char *entity_name, int is_weapon)
{
        int (*bld_proc)(const char *entity_name, int is_weapon);
        bld_proc = (int (*)(const char *entity_name, int is_weapon))GetProcAddress(blade, "ChangeEntityWeapon");
        return bld_proc(entity_name, is_weapon);
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
* Entry point:            0x00507A06
*/

#ifdef BLD_NATIVE

int ChangeEntityArrow(const char *entity_name, int is_arrow)
{
        int (*bld_proc)(const char *entity_name, int is_arrow);
        bld_proc = (int (*)(const char *entity_name, int is_arrow))GetProcAddress(blade, "ChangeEntityArrow");
        return bld_proc(entity_name, is_arrow);
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
* Entry point:            0x0050888E
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x005088E8
*/

#ifdef BLD_NATIVE

entity_t *SeverLimb(const char *entity_name, int limb)
{
        entity_t *(*bld_proc)(const char *entity_name, int limb);
        bld_proc = (entity_t *(*)(const char *entity_name, int limb))GetProcAddress(blade, "SeverLimb");
        return bld_proc(entity_name, limb);
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
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        const char *entity_name, const char *timer_name
))GetProcAddress(blade, "SubscribeEntityToList");
        return bld_proc(entity_name, timer_name);
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
* Entry point:            0x00508B80
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00508BBB
*/

#ifdef BLD_NATIVE

int InterruptCombat(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "InterruptCombat");
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
* Entry point:            0x00508CD9
*/

#ifdef BLD_NATIVE

const char *GetParticleEntity(const char *entity_name)
{
        const char *(*bld_proc)(const char *entity_name);
        bld_proc = (const char *(*)(const char *entity_name))GetProcAddress(blade, "GetParticleEntity");
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
);
        bld_proc = (int (*)(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
))GetProcAddress(blade, "Rel2AbsVector");
        return bld_proc(entity_name, x_rel, y_rel, z_rel, x_abs, y_abs, z_abs);
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
);
        bld_proc = (int (*)(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        double *x_abs, double *y_abs, double *z_abs
))GetProcAddress(blade, "Rel2AbsPoint");
        return bld_proc(entity_name, x_rel, y_rel, z_rel, x_abs, y_abs, z_abs);
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
);
        bld_proc = (int (*)(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
))GetProcAddress(blade, "Rel2AbsVectorN");
        return bld_proc(entity_name, x_rel, y_rel, z_rel, anchor_name, x_abs, y_abs, z_abs);
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
);
        bld_proc = (int (*)(
        const char *entity_name, double x_rel, double y_rel, double z_rel,
        const char *anchor_name, double *x_abs, double *y_abs, double *z_abs
))GetProcAddress(blade, "Rel2AbsPointN");
        return bld_proc(entity_name, x_rel, y_rel, z_rel, anchor_name, x_abs, y_abs, z_abs);
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
);
        bld_proc = (int (*)(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
))GetProcAddress(blade, "Abs2RelVector");
        return bld_proc(entity_name, x_abs, y_abs, z_abs, x_rel, y_rel, z_rel);
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
);
        bld_proc = (int (*)(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        double *x_rel, double *y_rel, double *z_rel
))GetProcAddress(blade, "Abs2RelPoint");
        return bld_proc(entity_name, x_abs, y_abs, z_abs, x_rel, y_rel, z_rel);
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
);
        bld_proc = (int (*)(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
))GetProcAddress(blade, "Abs2RelVectorN");
        return bld_proc(entity_name, x_abs, y_abs, z_abs, anchor_name, x_rel, y_rel, z_rel);
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
);
        bld_proc = (int (*)(
        const char *entity_name, double x_abs, double y_abs, double z_abs,
        const char *anchor_name, double *x_rel, double *y_rel, double *z_rel
))GetProcAddress(blade, "Abs2RelPointN");
        return bld_proc(entity_name, x_abs, y_abs, z_abs, anchor_name, x_rel, y_rel, z_rel);
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
* Entry point:            0x0050966F
*/

#ifdef BLD_NATIVE

double SQDistance2(const char *entity_name1, const char *entity_name2)
{
        double (*bld_proc)(const char *entity_name1, const char *entity_name2);
        bld_proc = (double (*)(const char *entity_name1, const char *entity_name2))GetProcAddress(blade, "SQDistance2");
        return bld_proc(entity_name1, entity_name2);
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
* Entry point:            0x0050973E
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x005097AD
*/

#ifdef BLD_NATIVE

int CreateTimer(const char *timer_name, double period)
{
        int (*bld_proc)(const char *timer_name, double period);
        bld_proc = (int (*)(const char *timer_name, double period))GetProcAddress(blade, "CreateTimer");
        return bld_proc(timer_name, period);
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
* Entry point:            0x005097EB
*/

#ifdef BLD_NATIVE

int GetnTimers(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetnTimers");
        return bld_proc();
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
* Entry point:            0x005097FA
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index, int *value
))GetProcAddress(blade, "GetEntityIntProperty");
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
* Entry point:            0x0050B513
*/

#ifdef BLD_NATIVE

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
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index,
        const char **value
))GetProcAddress(blade, "GetEntityStringProperty");
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
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index,
        double *x, double *y, double *z
))GetProcAddress(blade, "GetEntityVectorProperty");
        return bld_proc(entity_name, property_kind, index, x, y, z);
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
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index, double *quat1,
        double *quat2, double *quat3, double *quat4
))GetProcAddress(blade, "GetEntityQuatProperty");
        return bld_proc(entity_name, property_kind, index, quat1, quat2, quat3, quat4);
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
* Entry point:            0x0050F8B9
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index, int value
))GetProcAddress(blade, "SetEntityIntProperty");
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
* Entry point:            0x00511DB7
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index,
        const char *value
))GetProcAddress(blade, "SetEntityStringProperty");
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
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index,
        double x, double y, double z
))GetProcAddress(blade, "SetEntityVectorProperty");
        return bld_proc(entity_name, property_kind, index, x, y, z);
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
);
        bld_proc = (int (*)(
        const char *entity_name, int property_kind, int index, double quat1,
        double quat2, double quat3, double quat4
))GetProcAddress(blade, "SetEntityQuatProperty");
        return bld_proc(entity_name, property_kind, index, quat1, quat2, quat3, quat4);
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
* Entry point:            0x005163AA
*/

#ifdef BLD_NATIVE

int SetEntityData(const char *entity_name, PyObject *data)
{
        int (*bld_proc)(const char *entity_name, PyObject *data);
        bld_proc = (int (*)(const char *entity_name, PyObject *data))GetProcAddress(blade, "SetEntityData");
        return bld_proc(entity_name, data);
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
* Entry point:            0x0051645D
*/

#ifdef BLD_NATIVE

PyObject *GetEntityData(const char *entity_name)
{
        PyObject *(*bld_proc)(const char *entity_name);
        bld_proc = (PyObject *(*)(const char *entity_name))GetProcAddress(blade, "GetEntityData");
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
* Entry point:            0x005164FD
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        const char *entity_name, PyObject *internal_state
))GetProcAddress(blade, "SetEntityInternalState");
        return bld_proc(entity_name, internal_state);
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
* Entry point:            0x0051758B
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x005175E8
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00517688
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00517718
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00517740
*/

#ifdef BLD_NATIVE

int RemoveScheduledFunc(const char *name)
{
        int (*bld_proc)(const char *name);
        bld_proc = (int (*)(const char *name))GetProcAddress(blade, "RemoveScheduledFunc");
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
* Entry point:            0x00517758
*/

#ifdef BLD_NATIVE

int GetnScheduledFuncs(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetnScheduledFuncs");
        return bld_proc();
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
);
        bld_proc = (int (*)(
        int index, PyObject **func, PyObject **args, const char **name,
        double *time
))GetProcAddress(blade, "GetScheduledFunc");
        return bld_proc(index, func, args, name, time);
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
);
        bld_proc = (int (*)(
        const char *entity_name, double x_dir, double y_dir, double z_dir,
        double velocity, int unknown
))GetProcAddress(blade, "EntityRotate");
        return bld_proc(entity_name, x_dir, y_dir, z_dir, velocity, unknown);
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
);
        bld_proc = (int (*)(
        const char *entity_name, double x, double y, double z, double x_dir,
        double y_dir, double z_dir, double angle, int i_unknown
))GetProcAddress(blade, "EntityRotateAbs");
        return bld_proc(entity_name, x, y, z, x_dir, y_dir, z_dir, angle, i_unknown);
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
);
        bld_proc = (int (*)(
        const char *entity_name, double x, double y, double z, double x_dir,
        double y_dir, double z_dir, double angle, int i_unknown
))GetProcAddress(blade, "EntityRotateRel");
        return bld_proc(entity_name, x, y, z, x_dir, y_dir, z_dir, angle, i_unknown);
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
* Entry point:            0x00517B67
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        const char *entity_name, double x, double y, double z, int unknown
))GetProcAddress(blade, "EntitySetPosition");
        return bld_proc(entity_name, x, y, z, unknown);
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
);
        bld_proc = (int (*)(
        const char *entity_name, double quat1, double quat2, double quat3,
        double quat4, int unknown
))GetProcAddress(blade, "EntitySetOrientation");
        return bld_proc(entity_name, quat1, quat2, quat3, quat4, unknown);
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
* Entry point:            0x00517E42
*/

#ifdef BLD_NATIVE

int EntityPutToWorld(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "EntityPutToWorld");
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
* Entry point:            0x00517E97
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        const char *entity_name, const char *anm_event
))GetProcAddress(blade, "EntityDelAnmEventFunc");
        return bld_proc(entity_name, anm_event);
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
* Entry point:            0x00517FB9
*/

#ifdef BLD_NATIVE

int EntityClearAnmEventFuncs(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "EntityClearAnmEventFuncs");
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
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "ClearActorPath");
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
* Entry point:            0x005180A2
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00518148
*/

#ifdef BLD_NATIVE

int StartActorPath(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "StartActorPath");
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
* Entry point:            0x005181BA
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        const char *entity_name, double x, double y, double z, double max_fall,
        int action_area, int *isCorrect
))GetProcAddress(blade, "TestPos");
        return bld_proc(entity_name, x, y, z, max_fall, action_area, isCorrect);
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
);
        bld_proc = (int (*)(
        const char *entity_name, double x, double y, double z, double box_size,
        int *isCorrect
))GetProcAddress(blade, "TestPosInOwnBox");
        return bld_proc(entity_name, x, y, z, box_size, isCorrect);
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
* Entry point:            0x005184E8
*/

#ifdef BLD_NATIVE

int TurnOnActor(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "TurnOnActor");
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
* Entry point:            0x0051855A
*/

#ifdef BLD_NATIVE

int TurnOffActor(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "TurnOffActor");
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
* Entry point:            0x005185CC
*/

#ifdef BLD_NATIVE

int SetAttackList(const char *entity_name, PyObject *attack_list)
{
        int (*bld_proc)(const char *entity_name, PyObject *attack_list);
        bld_proc = (int (*)(const char *entity_name, PyObject *attack_list))GetProcAddress(blade, "SetAttackList");
        return bld_proc(entity_name, attack_list);
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
* Entry point:            0x005186BA
*/

#ifdef BLD_NATIVE

PyObject *GetAttackList(const char *entity_name)
{
        PyObject *(*bld_proc)(const char *entity_name);
        bld_proc = (PyObject *(*)(const char *entity_name))GetProcAddress(blade, "GetAttackList");
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
* Entry point:            0x0051872A
*/

#ifdef BLD_NATIVE

PyObject *GetGroupMembers(const char *entity_name)
{
        PyObject *(*bld_proc)(const char *entity_name);
        bld_proc = (PyObject *(*)(const char *entity_name))GetProcAddress(blade, "GetGroupMembers");
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
* Entry point:            0x00518910
*/

#ifdef BLD_NATIVE

PyObject *GetCombatants(const char *entity_name)
{
        PyObject *(*bld_proc)(const char *entity_name);
        bld_proc = (PyObject *(*)(const char *entity_name))GetProcAddress(blade, "GetCombatants");
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
);
        bld_proc = (int (*)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
))GetProcAddress(blade, "SetActorNodeStartTangent");
        return bld_proc(entity_name, unknown1, unknown2, unknown3, unknown4);
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
);
        bld_proc = (int (*)(
        const char *entity_name, int unknown1, double unknown2, double unknown3,
        double unknown4
))GetProcAddress(blade, "SetActorNodeEndTangent");
        return bld_proc(entity_name, unknown1, unknown2, unknown3, unknown4);
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
* Entry point:            0x00518ACF
*/

#ifdef BLD_NATIVE

int SetSound(const char *entity_name, const char *sound)
{
        int (*bld_proc)(const char *entity_name, const char *sound);
        bld_proc = (int (*)(const char *entity_name, const char *sound))GetProcAddress(blade, "SetSound");
        return bld_proc(entity_name, sound);
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
* Entry point:            0x00518B45
*/

#ifdef BLD_NATIVE

int SetObjectSound(const char *entity_name, const char *sound)
{
        int (*bld_proc)(const char *entity_name, const char *sound);
        bld_proc = (int (*)(const char *entity_name, const char *sound))GetProcAddress(blade, "SetObjectSound");
        return bld_proc(entity_name, sound);
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
* Entry point:            0x00518BBB
*/

#ifdef BLD_NATIVE

int PlayEntitySound(const char *entity_name, int i_unknown)
{
        int (*bld_proc)(const char *entity_name, int i_unknown);
        bld_proc = (int (*)(const char *entity_name, int i_unknown))GetProcAddress(blade, "PlayEntitySound");
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
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "Stop");
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
* Entry point:            0x00518D90
*/

#ifdef BLD_NATIVE

int StopAt(const char *entity_name, double x, double y, double z)
{
        int (*bld_proc)(const char *entity_name, double x, double y, double z);
        bld_proc = (int (*)(const char *entity_name, double x, double y, double z))GetProcAddress(blade, "StopAt");
        return bld_proc(entity_name, x, y, z);
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
);
        bld_proc = (int (*)(
        const char *entity_name, const char *anm_name, const char *obj_name,
        int unknown, int *res
))GetProcAddress(blade, "CheckAnimCol");
        return bld_proc(entity_name, anm_name, obj_name, unknown, res);
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
* Entry point:            0x00518F1A
*/

#ifdef BLD_NATIVE

int RemoveFromInvent(const char *entity_name, const char *obj_name)
{
        int (*bld_proc)(const char *entity_name, const char *obj_name);
        bld_proc = (int (*)(const char *entity_name, const char *obj_name))GetProcAddress(blade, "RemoveFromInvent");
        return bld_proc(entity_name, obj_name);
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
* Entry point:            0x0051919B
*/

#ifdef BLD_NATIVE

int ResetWounds(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "ResetWounds");
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
* Entry point:            0x0051920D
*/

#ifdef BLD_NATIVE

int RemoveFromInventRight(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "RemoveFromInventRight");
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
* Entry point:            0x00519285
*/

#ifdef BLD_NATIVE

int RemoveFromInventLeft(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "RemoveFromInventLeft");
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
* Entry point:            0x005192FD
*/

#ifdef BLD_NATIVE

int RemoveFromInventLeft2(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "RemoveFromInventLeft2");
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
* Entry point:            0x00519375
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        const char *entity_name, const char *seen_entity_name,
        double x, double y, double z, int *canISee
))GetProcAddress(blade, "CanISeeFrom");
        return bld_proc(entity_name, seen_entity_name, x, y, z, canISee);
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
* Entry point:            0x005194EE
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        const char *entity_name, const char *exclude_hit_for_name,
        void *unknown
))GetProcAddress(blade, "ExcludeHitFor");
        return bld_proc(entity_name, exclude_hit_for_name, unknown);
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
* Entry point:            0x00519697
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        const char *entity_name, const char *child_entity_name, void *unknown
))GetProcAddress(blade, "Link");
        return bld_proc(entity_name, child_entity_name, unknown);
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
);
        bld_proc = (int (*)(
        const char *entity_name, const char *child_name, int node_index,
        void *unknown
))GetProcAddress(blade, "LinkToNode");
        return bld_proc(entity_name, child_name, node_index, unknown);
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
);
        bld_proc = (int (*)(
        const char *entity_name, const char *entity_anchor_name,
        const char *child_name, const char *child_anchor_name, void *unknown
))GetProcAddress(blade, "LinkAnchors");
        return bld_proc(entity_name, entity_anchor_name, child_name, child_anchor_name, unknown);
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
* Entry point:            0x00519A7D
*/

#ifdef BLD_NATIVE

int UnlinkChilds(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "UnlinkChilds");
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
* Entry point:            0x00519ACF
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        const char *entity_name, const char *child_entity_name, void *unknown
))GetProcAddress(blade, "UnlinkChild");
        return bld_proc(entity_name, child_entity_name, unknown);
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
* Entry point:            0x00519C0D
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        const char *entity_name, int wuea, int mod_y, int solf, int copy_rot,
        int bng_mov, int headf, int unknown
))GetProcAddress(blade, "SetTmpAnmFlags");
        return bld_proc(entity_name, wuea, mod_y, solf, copy_rot, bng_mov, headf, unknown);
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
);
        bld_proc = (int (*)(
        const char *entity_name, const char *anm_name, int wuea, int mod_y,
        int solf, int copy_rot, int bng_mov, int headf
))GetProcAddress(blade, "SetAnmFlags");
        return bld_proc(entity_name, anm_name, wuea, mod_y, solf, copy_rot, bng_mov, headf);
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
* Entry point:            0x00519DDF
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x00519E5F
*/

#ifdef BLD_NATIVE

int SetEnemy(const char *entity_name, const char *enemy_name)
{
        int (*bld_proc)(const char *entity_name, const char *enemy_name);
        bld_proc = (int (*)(const char *entity_name, const char *enemy_name))GetProcAddress(blade, "SetEnemy");
        return bld_proc(entity_name, enemy_name);
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
* Entry point:            0x00519F38
*/

#ifdef BLD_NATIVE

const char *GetEnemy(const char *entity_name)
{
        const char *(*bld_proc)(const char *entity_name);
        bld_proc = (const char *(*)(const char *entity_name))GetProcAddress(blade, "GetEnemy");
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
* Entry point:            0x00519FD6
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0051A0A5
*/

#ifdef BLD_NATIVE

int ResetChase(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "ResetChase");
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
* Entry point:            0x0051A14B
*/

#ifdef BLD_NATIVE

int GoTo(const char *entity_name, int x, int y, int z)
{
        int (*bld_proc)(const char *entity_name, int x, int y, int z);
        bld_proc = (int (*)(const char *entity_name, int x, int y, int z))GetProcAddress(blade, "GoTo");
        return bld_proc(entity_name, x, y, z);
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
* Entry point:            0x0051A1FC
*/

#ifdef BLD_NATIVE

int CanGoTo(const char *entity_name, int x, int y, int z)
{
        int (*bld_proc)(const char *entity_name, int x, int y, int z);
        bld_proc = (int (*)(const char *entity_name, int x, int y, int z))GetProcAddress(blade, "CanGoTo");
        return bld_proc(entity_name, x, y, z);
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
* Entry point:            0x0051A2A8
*/

#ifdef BLD_NATIVE

int QuickFace(const char *entity_name, double angle)
{
        int (*bld_proc)(const char *entity_name, double angle);
        bld_proc = (int (*)(const char *entity_name, double angle))GetProcAddress(blade, "QuickFace");
        return bld_proc(entity_name, angle);
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
* Entry point:            0x0051A32A
*/

#ifdef BLD_NATIVE

int Face(const char *entity_name, double angle)
{
        int (*bld_proc)(const char *entity_name, double angle);
        bld_proc = (int (*)(const char *entity_name, double angle))GetProcAddress(blade, "Face");
        return bld_proc(entity_name, angle);
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
* Entry point:            0x0051A3E3
*/

#ifdef BLD_NATIVE

int StartLooking(const char *entity_name, int x, int y, int z)
{
        int (*bld_proc)(const char *entity_name, int x, int y, int z);
        bld_proc = (int (*)(const char *entity_name, int x, int y, int z))GetProcAddress(blade, "StartLooking");
        return bld_proc(entity_name, x, y, z);
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
* Entry point:            0x0051A3ED
*/

#ifdef BLD_NATIVE

int StopLooking(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "StopLooking");
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
* Entry point:            0x0051A47A
*/

#ifdef BLD_NATIVE

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
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "LaunchWatch");
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
* Entry point:            0x0051A68A
*/

#ifdef BLD_NATIVE

int GetActionMode(const char *entity_name, int *action_mode)
{
        int (*bld_proc)(const char *entity_name, int *action_mode);
        bld_proc = (int (*)(const char *entity_name, int *action_mode))GetProcAddress(blade, "GetActionMode");
        return bld_proc(entity_name, action_mode);
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
* Entry point:            0x0051A74D
*/

#ifdef BLD_NATIVE

int StartGrabbing(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "StartGrabbing");
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
* Entry point:            0x0051A789
*/

#ifdef BLD_NATIVE

int StopGrabbing(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "StopGrabbing");
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
* Entry point:            0x0051A7C5
*/

#ifdef BLD_NATIVE

int AddEntWatchAnim(const char *entity_name, const char *anm_name)
{
        int (*bld_proc)(const char *entity_name, const char *anm_name);
        bld_proc = (int (*)(const char *entity_name, const char *anm_name))GetProcAddress(blade, "AddEntWatchAnim");
        return bld_proc(entity_name, anm_name);
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
* Entry point:            0x0051A841
*/

#ifdef BLD_NATIVE

int Freeze(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "Freeze");
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
* Entry point:            0x0051A8D7
*/

#ifdef BLD_NATIVE

int UnFreeze(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "UnFreeze");
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
* Entry point:            0x0051A96A
*/

#ifdef BLD_NATIVE

int SwitchTo1H(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "SwitchTo1H");
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
);
        bld_proc = (int (*)(
        const char *entity_name, const char *anchor_name, double x_dir,
        double y_dir, double z_dir, double *x_dummy_axis, double *y_dummy_axis,
        double *z_dummy_axis, int unknown
))GetProcAddress(blade, "GetDummyAxis");
        return bld_proc(entity_name, anchor_name, x_dir, y_dir, z_dir, x_dummy_axis, y_dummy_axis, z_dummy_axis, unknown);
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
);
        bld_proc = (int (*)(
        const char *entity_name, const char *grasp, double *x, double *y,
        double *z
))GetProcAddress(blade, "GraspPos");
        return bld_proc(entity_name, grasp, x, y, z);
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
* Entry point:            0x0051AF97
*/

#ifdef BLD_NATIVE

int SwitchToBow(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "SwitchToBow");
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
* Entry point:            0x0051B00F
*/

#ifdef BLD_NATIVE

int LaunchBayRoute(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "LaunchBayRoute");
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
* Entry point:            0x0051B09A
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0051B18D
*/

#ifdef BLD_NATIVE

int GetNChildren(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "GetNChildren");
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
* Entry point:            0x0051B1DB
*/

#ifdef BLD_NATIVE

const char *GetChild(const char *entity_name, int index)
{
        const char *(*bld_proc)(const char *entity_name, int index);
        bld_proc = (const char *(*)(const char *entity_name, int index))GetProcAddress(blade, "GetChild");
        return bld_proc(entity_name, index);
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
* Entry point:            0x0051B225
*/

#ifdef BLD_NATIVE

int CreateBipedData(const char *biped_name, const char *kind)
{
        int (*bld_proc)(const char *biped_name, const char *kind);
        bld_proc = (int (*)(const char *biped_name, const char *kind))GetProcAddress(blade, "CreateBipedData");
        return bld_proc(biped_name, kind);
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
);
        bld_proc = (int (*)(
        const char *char_name, const char *action_name,
        const char *animation_name, double d_unknown1, double d_unknown2,
        int i_unknown
))GetProcAddress(blade, "AddBipedAction");
        return bld_proc(char_name, action_name, animation_name, d_unknown1, d_unknown2, i_unknown);
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
* Entry point:            0x0051B971
*/

#ifdef BLD_NATIVE

int RemoveBipedAction(const char *s_unknown1, const char *s_unknown2)
{
        int (*bld_proc)(const char *s_unknown1, const char *s_unknown2);
        bld_proc = (int (*)(const char *s_unknown1, const char *s_unknown2))GetProcAddress(blade, "RemoveBipedAction");
        return bld_proc(s_unknown1, s_unknown2);
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
);
        bld_proc = (int (*)(
        const char *char_name, const char *action_name,
        const char *animation_name, const char *s_unknown, double d_unknown1,
        double d_unknown2, int i_unknown
))GetProcAddress(blade, "AddBipedActionC");
        return bld_proc(char_name, action_name, animation_name, s_unknown, d_unknown1, d_unknown2, i_unknown);
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
* Entry point:            0x0051BEF4
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

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
);
        bld_proc = (int (*)(
        const char *s_unknown1, const char *s_unknown2, const char *s_unknown3
))GetProcAddress(blade, "SetEventTableFuncC");
        return bld_proc(s_unknown1, s_unknown2, s_unknown3);
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
* Entry point:            0x0051CA1C
*/

#ifdef BLD_NATIVE

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

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x0051CE46
*/

#ifdef BLD_NATIVE

int DoAction(const char *entity_name, const char *action_name)
{
        int (*bld_proc)(const char *entity_name, const char *action_name);
        bld_proc = (int (*)(const char *entity_name, const char *action_name))GetProcAddress(blade, "DoAction");
        return bld_proc(entity_name, action_name);
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
);
        bld_proc = (int (*)(
        const char *entity_name, const char *action_name,
        int interpolation_type, double time, double unknown1
))GetProcAddress(blade, "DoActionWI");
        return bld_proc(entity_name, action_name, interpolation_type, time, unknown1);
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
* Entry point:            0x0051CF72
*/

#ifdef BLD_NATIVE

int SetOnFloor(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "SetOnFloor");
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
* Entry point:            0x0051CFE4
*/

#ifdef BLD_NATIVE

int RaiseEvent(const char *entity_name, const char *event_name)
{
        int (*bld_proc)(const char *entity_name, const char *event_name);
        bld_proc = (int (*)(const char *entity_name, const char *event_name))GetProcAddress(blade, "RaiseEvent");
        return bld_proc(entity_name, event_name);
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
* Entry point:            0x0051D065
*/

#ifdef BLD_NATIVE

int SetSolidMask(const char *kind, int mask)
{
        int (*bld_proc)(const char *kind, int mask);
        bld_proc = (int (*)(const char *kind, int mask))GetProcAddress(blade, "SetSolidMask");
        return bld_proc(kind, mask);
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
* Entry point:            0x0051D25D
*/

#ifdef BLD_NATIVE

int IsValidEntity(const char *entity_name)
{
        int (*bld_proc)(const char *entity_name);
        bld_proc = (int (*)(const char *entity_name))GetProcAddress(blade, "IsValidEntity");
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
* Entry point:            0x0051D283
*/

#ifdef BLD_NATIVE

void EntityRemoveFromWorld(const char *entity_name)
{
        void (*bld_proc)(const char *entity_name);
        bld_proc = (void (*)(const char *entity_name))GetProcAddress(blade, "EntityRemoveFromWorld");
        bld_proc(entity_name);
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
* Entry point:            0x0051D2D7
*/

#ifdef BLD_NATIVE

void EntityRemoveFromWorldWithChilds(const char *entity_name)
{
        void (*bld_proc)(const char *entity_name);
        bld_proc = (void (*)(const char *entity_name))GetProcAddress(blade, "EntityRemoveFromWorldWithChilds");
        bld_proc(entity_name);
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
);
        bld_proc = (int (*)(
        const char *entity_name, double x, double y, double z, double x_vec,
        double y_vec, double z_vec
))GetProcAddress(blade, "ImpulseC");
        return bld_proc(entity_name, x, y, z, x_vec, y_vec, z_vec);
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
* Entry point:            0x0051D3FA
*/

#ifdef BLD_NATIVE

int SetAuraActive(const char *entity_name, int is_active)
{
        int (*bld_proc)(const char *entity_name, int is_active);
        bld_proc = (int (*)(const char *entity_name, int is_active))GetProcAddress(blade, "SetAuraActive");
        return bld_proc(entity_name, is_active);
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
);
        bld_proc = (int (*)(
        const char *entity_name, double size, double alpha,
        double colour_intensity, int hide_front_faces, int hide_back_faces,
        int alpha_mode
))GetProcAddress(blade, "SetAuraParams");
        return bld_proc(entity_name, size, alpha, colour_intensity, hide_front_faces, hide_back_faces, alpha_mode);
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
);
        bld_proc = (int (*)(
        const char *entity_name, int gap, double r1, double g1, double b1,
        double alpha1, double starting_point, double r2, double g2, double b2,
        double alpha2, double ending_point
))GetProcAddress(blade, "SetAuraGradient");
        return bld_proc(entity_name, gap, r1, g1, b1, alpha1, starting_point, r2, g2, b2, alpha2, ending_point);
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
* Entry point:            0x0051D63D
*/

#ifdef BLD_NATIVE

void GetMouseState(int *invert, double *xsens, double *ysens)
{
        void (*bld_proc)(int *invert, double *xsens, double *ysens);
        bld_proc = (void (*)(int *invert, double *xsens, double *ysens))GetProcAddress(blade, "GetMouseState");
        bld_proc(invert, xsens, ysens);
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
* Entry point:            0x0051D677
*/

#ifdef BLD_NATIVE

void SetMouseState(int invert, double xsens, double ysens)
{
        void (*bld_proc)(int invert, double xsens, double ysens);
        bld_proc = (void (*)(int invert, double xsens, double ysens))GetProcAddress(blade, "SetMouseState");
        bld_proc(invert, xsens, ysens);
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
* Entry point:            0x0051D6B1
*/

#ifdef BLD_NATIVE

double GetPSeconds(void)
{
        double (*bld_proc)(void);
        bld_proc = (double (*)(void))GetProcAddress(blade, "GetPSeconds");
        return bld_proc();
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
* Entry point:            0x0051D6D4
*/

#ifdef BLD_NATIVE

void BodInspector(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "BodInspector");
        bld_proc();
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
* Entry point:            0x0051D6DE
*/

#ifdef BLD_NATIVE

void SaveScreeShoot(const char *filename, int width, int height)
{
        void (*bld_proc)(const char *filename, int width, int height);
        bld_proc = (void (*)(const char *filename, int width, int height))GetProcAddress(blade, "SaveScreeShoot");
        bld_proc(filename, width, height);
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
* Entry point:            0x0051D6FB
*/

#ifdef BLD_NATIVE

void CleanArea(double x, double y, double z, float distance)
{
        void (*bld_proc)(double x, double y, double z, float distance);
        bld_proc = (void (*)(double x, double y, double z, float distance))GetProcAddress(blade, "CleanArea");
        bld_proc(x, y, z, distance);
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

#ifdef BLD_NATIVE

int GetCharByName(const char *name, const char *short_name)
{
        int (*bld_proc)(const char *name, const char *short_name);
        bld_proc = (int (*)(const char *name, const char *short_name))GetProcAddress(blade, "GetCharByName");
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

#ifdef BLD_NATIVE

int LoadAllAnimations(int charID)
{
        int (*bld_proc)(int charID);
        bld_proc = (int (*)(int charID))GetProcAddress(blade, "LoadAllAnimations");
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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE

int SetAnmDefaultPrefix(int charID, const char *prefix)
{
        int (*bld_proc)(int charID, const char *prefix);
        bld_proc = (int (*)(int charID, const char *prefix))GetProcAddress(blade, "SetAnmDefaultPrefix");
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

#ifdef BLD_NATIVE

int AddAttack(int charID, const char *attack_name, const char *anm_name)
{
        int (*bld_proc)(int charID, const char *attack_name, const char *anm_name);
        bld_proc = (int (*)(int charID, const char *attack_name, const char *anm_name))GetProcAddress(blade, "AddAttack");
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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE
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

#ifdef BLD_NATIVE

int AttackTypeFlag(int charID, const char *attack_name, int flag)
{
        int (*bld_proc)(int charID, const char *attack_name, int flag);
        bld_proc = (int (*)(int charID, const char *attack_name, int flag))GetProcAddress(blade, "AttackTypeFlag");
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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE

int SetNCDSpheres(int charID, int NCDSpheres)
{
        int (*bld_proc)(int charID, int NCDSpheres);
        bld_proc = (int (*)(int charID, int NCDSpheres))GetProcAddress(blade, "SetNCDSpheres");
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

#ifdef BLD_NATIVE

int SetCDSphere(int charID, int index, double h, double r)
{
        int (*bld_proc)(int charID, int index, double h, double r);
        bld_proc = (int (*)(int charID, int index, double h, double r))GetProcAddress(blade, "SetCDSphere");
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

#ifdef BLD_NATIVE

int GetCharIntProperty(int charID, int property_kind, int index, int *value)
{
        int (*bld_proc)(int charID, int property_kind, int index, int *value);
        bld_proc = (int (*)(int charID, int property_kind, int index, int *value))GetProcAddress(blade, "GetCharIntProperty");
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

#ifdef BLD_NATIVE

int SetCharIntProperty(int charID, int property_kind, int index, int value)
{
        int (*bld_proc)(int charID, int property_kind, int index, int value);
        bld_proc = (int (*)(int charID, int property_kind, int index, int value))GetProcAddress(blade, "SetCharIntProperty");
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

#ifdef BLD_NATIVE

int GetCharFloatProperty(int charID, int property_kind, int index, double *value)
{
        int (*bld_proc)(int charID, int property_kind, int index, double *value);
        bld_proc = (int (*)(int charID, int property_kind, int index, double *value))GetProcAddress(blade, "GetCharFloatProperty");
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

#ifdef BLD_NATIVE

int SetCharFloatProperty(int charID, int property_kind, int index, double value)
{
        int (*bld_proc)(int charID, int property_kind, int index, double value);
        bld_proc = (int (*)(int charID, int property_kind, int index, double value))GetProcAddress(blade, "SetCharFloatProperty");
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

#ifdef BLD_NATIVE

int GetCharStringProperty(int charID, int property_kind, int index, const char **value)
{
        int (*bld_proc)(int charID, int property_kind, int index, const char **value);
        bld_proc = (int (*)(int charID, int property_kind, int index, const char **value))GetProcAddress(blade, "GetCharStringProperty");
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

#ifdef BLD_NATIVE

int SetCharStringProperty(int charID, int property_kind, int index, const char *value)
{
        int (*bld_proc)(int charID, int property_kind, int index, const char *value);
        bld_proc = (int (*)(int charID, int property_kind, int index, const char *value))GetProcAddress(blade, "SetCharStringProperty");
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

#ifdef BLD_NATIVE

int SetCharFuncProperty(int charID, int property_kind, int index, PyObject *func)
{
        int (*bld_proc)(int charID, int property_kind, int index, PyObject *func);
        bld_proc = (int (*)(int charID, int property_kind, int index, PyObject *func))GetProcAddress(blade, "SetCharFuncProperty");
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

#ifdef BLD_NATIVE

int GetTrailByName(const char *name)
{
        int (*bld_proc)(const char *name);
        bld_proc = (int (*)(const char *name))GetProcAddress(blade, "GetTrailByName");
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

#ifdef BLD_NATIVE
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

#ifdef BLD_NATIVE
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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE
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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE
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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE
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

#ifdef BLD_NATIVE
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

#ifdef BLD_NATIVE
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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE
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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE

int LinkRightHand(const char *inv_name, const char *obj_name)
{
        int (*bld_proc)(const char *inv_name, const char *obj_name);
        bld_proc = (int (*)(const char *inv_name, const char *obj_name))GetProcAddress(blade, "LinkRightHand");
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

#ifdef BLD_NATIVE

int LinkLeftHand(const char *inv_name, const char *obj_name)
{
        int (*bld_proc)(const char *inv_name, const char *obj_name);
        bld_proc = (int (*)(const char *inv_name, const char *obj_name))GetProcAddress(blade, "LinkLeftHand");
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

#ifdef BLD_NATIVE

int LinkLeftHand2(const char *inv_name, const char *obj_name)
{
        int (*bld_proc)(const char *inv_name, const char *obj_name);
        bld_proc = (int (*)(const char *inv_name, const char *obj_name))GetProcAddress(blade, "LinkLeftHand2");
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

#ifdef BLD_NATIVE

int LinkRightBack(const char *inv_name, const char *obj_name)
{
        int (*bld_proc)(const char *inv_name, const char *obj_name);
        bld_proc = (int (*)(const char *inv_name, const char *obj_name))GetProcAddress(blade, "LinkRightBack");
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

#ifdef BLD_NATIVE

int LinkLeftBack(const char *inv_name, const char *obj_name)
{
        int (*bld_proc)(const char *inv_name, const char *obj_name);
        bld_proc = (int (*)(const char *inv_name, const char *obj_name))GetProcAddress(blade, "LinkLeftBack");
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

#ifdef BLD_NATIVE

int LinkBack(const char *inv_name, const char *obj_name)
{
        int (*bld_proc)(const char *inv_name, const char *obj_name);
        bld_proc = (int (*)(const char *inv_name, const char *obj_name))GetProcAddress(blade, "LinkBack");
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

#ifdef BLD_NATIVE

int SetCurrentQuiver(const char *inv_name, const char *quiver_name)
{
        int (*bld_proc)(const char *inv_name, const char *quiver_name);
        bld_proc = (int (*)(const char *inv_name, const char *quiver_name))GetProcAddress(blade, "SetCurrentQuiver");
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

#ifdef BLD_NATIVE

int AddWeapon(const char *inv_name, int flag, const char *weapon_name)
{
        int (*bld_proc)(const char *inv_name, int flag, const char *weapon_name);
        bld_proc = (int (*)(const char *inv_name, int flag, const char *weapon_name))GetProcAddress(blade, "AddWeapon");
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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE

const char *GetObject(const char *inv_name, int obj_type, int index)
{
        const char *(*bld_proc)(const char *inv_name, int obj_type, int index);
        bld_proc = (const char *(*)(const char *inv_name, int obj_type, int index))GetProcAddress(blade, "GetObject");
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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE

const char *GetRightBack(const char *inv_name)
{
        const char *(*bld_proc)(const char *inv_name);
        bld_proc = (const char *(*)(const char *inv_name))GetProcAddress(blade, "GetRightBack");
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

#ifdef BLD_NATIVE

const char *GetLeftBack(const char *inv_name)
{
        const char *(*bld_proc)(const char *inv_name);
        bld_proc = (const char *(*)(const char *inv_name))GetProcAddress(blade, "GetLeftBack");
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

#ifdef BLD_NATIVE

const char *GetSelectedObject(const char *inv_name, int obj_type)
{
        const char *(*bld_proc)(const char *inv_name, int obj_type);
        bld_proc = (const char *(*)(const char *inv_name, int obj_type))GetProcAddress(blade, "GetSelectedObject");
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

#ifdef BLD_NATIVE

const char *GetActiveShield(const char *inv_name)
{
        const char *(*bld_proc)(const char *inv_name);
        bld_proc = (const char *(*)(const char *inv_name))GetProcAddress(blade, "GetActiveShield");
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

#ifdef BLD_NATIVE

const char *GetActiveWeapon(const char *inv_name)
{
        const char *(*bld_proc)(const char *inv_name);
        bld_proc = (const char *(*)(const char *inv_name))GetProcAddress(blade, "GetActiveWeapon");
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

#ifdef BLD_NATIVE
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

#ifdef BLD_NATIVE

const char *GetActiveQuiver(const char *inv_name)
{
        const char *(*bld_proc)(const char *inv_name);
        bld_proc = (const char *(*)(const char *inv_name))GetProcAddress(blade, "GetActiveQuiver");
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

#ifdef BLD_NATIVE

void Cycle(const char *inv_name, int obj_type)
{
        void (*bld_proc)(const char *inv_name, int obj_type);
        bld_proc = (void (*)(const char *inv_name, int obj_type))GetProcAddress(blade, "Cycle");
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

#ifdef BLD_NATIVE

int GetNumberObjectsAt(const char *inv_name, int obj_type, int index)
{
        int (*bld_proc)(const char *inv_name, int obj_type, int index);
        bld_proc = (int (*)(const char *inv_name, int obj_type, int index))GetProcAddress(blade, "GetNumberObjectsAt");
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

#ifdef BLD_NATIVE

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

#ifdef BLD_NATIVE

int IsSelected(const char *inv_name, int obj_type, int obj_index)
{
        int (*bld_proc)(const char *inv_name, int obj_type, int obj_index);
        bld_proc = (int (*)(const char *inv_name, int obj_type, int obj_index))GetProcAddress(blade, "IsSelected");
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

#ifdef BLD_NATIVE

int CarringObject(const char *inv_name, const char *obj_name)
{
        int (*bld_proc)(const char *inv_name, const char *obj_name);
        bld_proc = (int (*)(const char *inv_name, const char *obj_name))GetProcAddress(blade, "CarringObject");
        return bld_proc(inv_name, obj_name);
}

#endif


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


