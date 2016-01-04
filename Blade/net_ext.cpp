
#include <bld_system.h>
#include <bld_python.h>
#include "bld_ext_funcs.h"
#define BUILD_LIB
#include <blade_ext.h>

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x005B5340
*/
// TODO fix prototype
void SetGameSpySupport()
{
        assert("SetGameSpySupport" == NULL);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B534D
*/
// TODO fix prototype
void GetGameSpySupport()
{
        assert("GetGameSpySupport" == NULL);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5357
*/
// TODO implement
void StartGSQR(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "StartGSQR");
        bld_proc();
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x005B5582
*/
// TODO fix prototype
void EndGSQR()
{
        assert("EndGSQR" == NULL);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B55ED
*/
// TODO fix prototype
void LoopGSQR()
{
        assert("LoopGSQR" == NULL);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5647
*/
// TODO implement
void PersonChangeAnmSoundIndex(const char *person_name, int index)
{
        void (*bld_proc)(const char *person_name, int index);
        bld_proc = (void (*)(const char *person_name, int index))GetProcAddress(blade, "PersonChangeAnmSoundIndex");
        bld_proc(person_name, index);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B565C
*/
// TODO implement
void SetDedicatedServerState(int dedicated)
{
        void (*bld_proc)(int dedicated);
        bld_proc = (void (*)(int dedicated))GetProcAddress(blade, "SetDedicatedServerState");
        bld_proc(dedicated);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5673
*/
// TODO implement
int GetDedicatedServerState(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetDedicatedServerState");
        return bld_proc();
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B568F
*/
// TODO implement
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


/*
* Module:                 Blade.exe
* Entry point:            0x005B5716
*/
// TODO implement
const char *ServerInfoBlock(void)
{
        const char *(*bld_proc)(void);
        bld_proc = (const char *(*)(void))GetProcAddress(blade, "ServerInfoBlock");
        return bld_proc();
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5720
*/
// TODO implement
void ClientSetPyClientSoundFunc(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ClientSetPyClientSoundFunc");
        bld_proc(func);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5731
*/
// TODO implement
void CallNetEventSound(const char *entity_name, byte id)
{
        void (*bld_proc)(const char *entity_name, byte id);
        bld_proc = (void (*)(const char *entity_name, byte id))GetProcAddress(blade, "CallNetEventSound");
        bld_proc(entity_name, id);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5959
*/
// TODO implement
void ClientSetPyClientMutilaFunc(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ClientSetPyClientMutilaFunc");
        bld_proc(func);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B596A
*/
// TODO implement
void ClientSetPyClientDamageFunc(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ClientSetPyClientDamageFunc");
        bld_proc(func);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B597B
*/
// TODO implement
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


/*
* Module:                 Blade.exe
* Entry point:            0x005B5BB2
*/
// TODO implement
const char *NetGetClientId(void)
{
        const char *(*bld_proc)(void);
        bld_proc = (const char *(*)(void))GetProcAddress(blade, "NetGetClientId");
        return bld_proc();
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5BBC
*/
// TODO implement
boolean NetSetObjectState(const char *entity_name, boolean state)
{
        boolean (*bld_proc)(const char *entity_name, boolean state);
        bld_proc = (boolean (*)(const char *entity_name, boolean state))GetProcAddress(blade, "NetSetObjectState");
        return bld_proc(entity_name, state);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5BD1
*/
// TODO implement
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


/*
* Module:                 Blade.exe
* Entry point:            0x005B5BF0
*/
// TODO implement
void NetAddPosition(double x, double y, double z)
{
        void (*bld_proc)(double x, double y, double z);
        bld_proc = (void (*)(double x, double y, double z))GetProcAddress(blade, "NetAddPosition");
        bld_proc(x, y, z);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5C15
*/
// TODO implement
void NetSetPersonView(const char *entity_name)
{
        void (*bld_proc)(const char *entity_name);
        bld_proc = (void (*)(const char *entity_name))GetProcAddress(blade, "NetSetPersonView");
        bld_proc(entity_name);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5DE9
*/
// TODO implement
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


/*
* Module:                 Blade.exe
* Entry point:            0x005B5E06
*/
// TODO implement
void GetNextPosition(double *x, double *y, double *z)
{
        void (*bld_proc)(double *x, double *y, double *z);
        bld_proc = (void (*)(double *x, double *y, double *z))GetProcAddress(blade, "GetNextPosition");
        bld_proc(x, y, z);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5E74
*/
// TODO implement
void ServerSetPyByePlayerFunc(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ServerSetPyByePlayerFunc");
        bld_proc(func);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5E85
*/
// TODO implement
void ServerSetPyGetUserString(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ServerSetPyGetUserString");
        bld_proc(func);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B5E96
*/
// TODO implement
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


/*
* Module:                 Blade.exe
* Entry point:            0x005B5EB4
*/
// TODO implement
void GetLifeAndLevel(const char *entity_name, int *energy, int *life)
{
        void (*bld_proc)(const char *entity_name, int *energy, int *life);
        bld_proc = (void (*)(const char *entity_name, int *energy, int *life))GetProcAddress(blade, "GetLifeAndLevel");
        bld_proc(entity_name, energy, life);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6146
*/
// TODO implement
void ServerSetPyCreatePlayerFunc(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ServerSetPyCreatePlayerFunc");
        bld_proc(func);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6157
*/
// TODO implement
boolean ClientStartMainChar(void)
{
        boolean (*bld_proc)(void);
        bld_proc = (boolean (*)(void))GetProcAddress(blade, "ClientStartMainChar");
        return bld_proc();
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6188
*/
// TODO implement
int ServerSetSendDataState(int state)
{
        int (*bld_proc)(int state);
        bld_proc = (int (*)(int state))GetProcAddress(blade, "ServerSetSendDataState");
        return bld_proc(state);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x005B61B6
*/
// TODO implement
int GetNetState(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetNetState");
        return bld_proc();
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B61FD
*/
// TODO implement
void ClearPools(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "ClearPools");
        bld_proc();
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x005B637B
*/
// TODO implement
boolean StartServer(
        const char *game_name, const char *player_name, int max_players,
        boolean TCP
)
{
        boolean (*bld_proc)(
        const char *game_name, const char *player_name, int max_players,
        boolean TCP
);
        bld_proc = (boolean (*)(
        const char *game_name, const char *player_name, int max_players,
        boolean TCP
))GetProcAddress(blade, "StartServer");
        return bld_proc(game_name, player_name, max_players, TCP);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B63E4
*/
// TODO implement
boolean BrowseSessions(const char *ip_address)
{
        boolean (*bld_proc)(const char *ip_address);
        bld_proc = (boolean (*)(const char *ip_address))GetProcAddress(blade, "BrowseSessions");
        return bld_proc(ip_address);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B63FE
*/
// TODO implement
boolean GetBrowseResult(int index, bld_server_info *info)
{
        boolean (*bld_proc)(int index, bld_server_info *info);
        bld_proc = (boolean (*)(int index, bld_server_info *info))GetProcAddress(blade, "GetBrowseResult");
        return bld_proc(index, info);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B641C
*/
// TODO implement
boolean JoinSession(int index, const char *player_name)
{
        boolean (*bld_proc)(int index, const char *player_name);
        bld_proc = (boolean (*)(int index, const char *player_name))GetProcAddress(blade, "JoinSession");
        return bld_proc(index, player_name);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6448
*/
// TODO implement
void RestartNet(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "RestartNet");
        bld_proc();
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6464
*/
// TODO implement
void NetServerChangeLevel(const char *level_name)
{
        void (*bld_proc)(const char *level_name);
        bld_proc = (void (*)(const char *level_name))GetProcAddress(blade, "NetServerChangeLevel");
        bld_proc(level_name);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6475
*/
// TODO implement
float NetGetTime(void)
{
        float (*bld_proc)(void);
        bld_proc = (float (*)(void))GetProcAddress(blade, "NetGetTime");
        return bld_proc();
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B647F
*/
// TODO implement
int NetSetPPS(int PPS)
{
        int (*bld_proc)(int PPS);
        bld_proc = (int (*)(int PPS))GetProcAddress(blade, "NetSetPPS");
        return bld_proc(PPS);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6490
*/

int IsValidProtocol(int protocol)
{
        return net->is_valid_protocol(protocol);
}

