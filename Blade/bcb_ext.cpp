
#include <bld_system.h>
#include <bld_python.h>
#define BUILD_LIB
#include <blade_ext.h>

extern HMODULE blade;


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

