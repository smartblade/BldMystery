
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

#ifdef BLD_NATIVE
// TODO fix prototype
void SetGameSpySupport()
{
        assert("SetGameSpySupport" == NULL);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B534D
*/

#ifdef BLD_NATIVE
// TODO fix prototype
void GetGameSpySupport()
{
        assert("GetGameSpySupport" == NULL);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5357
*/

#ifdef BLD_NATIVE

void StartGSQR(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "StartGSQR");
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
* Entry point:            0x005B5582
*/

#ifdef BLD_NATIVE
// TODO fix prototype
void EndGSQR()
{
        assert("EndGSQR" == NULL);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B55ED
*/

#ifdef BLD_NATIVE
// TODO fix prototype
void LoopGSQR()
{
        assert("LoopGSQR" == NULL);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5647
*/

#ifdef BLD_NATIVE

void PersonChangeAnmSoundIndex(const char *person_name, int index)
{
        void (*bld_proc)(const char *person_name, int index);
        bld_proc = (void (*)(const char *person_name, int index))GetProcAddress(blade, "PersonChangeAnmSoundIndex");
        bld_proc(person_name, index);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B565C
*/

#ifdef BLD_NATIVE

void SetDedicatedServerState(int dedicated)
{
        void (*bld_proc)(int dedicated);
        bld_proc = (void (*)(int dedicated))GetProcAddress(blade, "SetDedicatedServerState");
        bld_proc(dedicated);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5673
*/

#ifdef BLD_NATIVE

int GetDedicatedServerState(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "GetDedicatedServerState");
        return bld_proc();
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B568F
*/

#ifdef BLD_NATIVE

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

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5716
*/

#ifdef BLD_NATIVE

const char *ServerInfoBlock(void)
{
        const char *(*bld_proc)(void);
        bld_proc = (const char *(*)(void))GetProcAddress(blade, "ServerInfoBlock");
        return bld_proc();
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5720
*/

#ifdef BLD_NATIVE

void ClientSetPyClientSoundFunc(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ClientSetPyClientSoundFunc");
        bld_proc(func);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5731
*/

#ifdef BLD_NATIVE

void CallNetEventSound(const char *entity_name, byte id)
{
        void (*bld_proc)(const char *entity_name, byte id);
        bld_proc = (void (*)(const char *entity_name, byte id))GetProcAddress(blade, "CallNetEventSound");
        bld_proc(entity_name, id);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5959
*/

#ifdef BLD_NATIVE

void ClientSetPyClientMutilaFunc(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ClientSetPyClientMutilaFunc");
        bld_proc(func);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B596A
*/

#ifdef BLD_NATIVE

void ClientSetPyClientDamageFunc(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ClientSetPyClientDamageFunc");
        bld_proc(func);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B597B
*/

#ifdef BLD_NATIVE

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

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5BB2
*/

#ifdef BLD_NATIVE

const char *NetGetClientId(void)
{
        const char *(*bld_proc)(void);
        bld_proc = (const char *(*)(void))GetProcAddress(blade, "NetGetClientId");
        return bld_proc();
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5BBC
*/

#ifdef BLD_NATIVE

boolean NetSetObjectState(const char *entity_name, boolean state)
{
        boolean (*bld_proc)(const char *entity_name, boolean state);
        bld_proc = (boolean (*)(const char *entity_name, boolean state))GetProcAddress(blade, "NetSetObjectState");
        return bld_proc(entity_name, state);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5BD1
*/

#ifdef BLD_NATIVE

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

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5BF0
*/

#ifdef BLD_NATIVE

void NetAddPosition(double x, double y, double z)
{
        void (*bld_proc)(double x, double y, double z);
        bld_proc = (void (*)(double x, double y, double z))GetProcAddress(blade, "NetAddPosition");
        bld_proc(x, y, z);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5C15
*/

#ifdef BLD_NATIVE

void NetSetPersonView(const char *entity_name)
{
        void (*bld_proc)(const char *entity_name);
        bld_proc = (void (*)(const char *entity_name))GetProcAddress(blade, "NetSetPersonView");
        bld_proc(entity_name);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5DE9
*/

#ifdef BLD_NATIVE

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

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5E06
*/

#ifdef BLD_NATIVE

void GetNextPosition(double *x, double *y, double *z)
{
        void (*bld_proc)(double *x, double *y, double *z);
        bld_proc = (void (*)(double *x, double *y, double *z))GetProcAddress(blade, "GetNextPosition");
        bld_proc(x, y, z);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5E74
*/

#ifdef BLD_NATIVE

void ServerSetPyByePlayerFunc(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ServerSetPyByePlayerFunc");
        bld_proc(func);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5E85
*/

#ifdef BLD_NATIVE

void ServerSetPyGetUserString(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ServerSetPyGetUserString");
        bld_proc(func);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5E96
*/

#ifdef BLD_NATIVE

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

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5EB4
*/

#ifdef BLD_NATIVE

void GetLifeAndLevel(const char *entity_name, int *energy, int *life)
{
        void (*bld_proc)(const char *entity_name, int *energy, int *life);
        bld_proc = (void (*)(const char *entity_name, int *energy, int *life))GetProcAddress(blade, "GetLifeAndLevel");
        bld_proc(entity_name, energy, life);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B6146
*/

#ifdef BLD_NATIVE

void ServerSetPyCreatePlayerFunc(PyObject *func)
{
        void (*bld_proc)(PyObject *func);
        bld_proc = (void (*)(PyObject *func))GetProcAddress(blade, "ServerSetPyCreatePlayerFunc");
        bld_proc(func);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B6157
*/

#ifdef BLD_NATIVE

boolean ClientStartMainChar(void)
{
        boolean (*bld_proc)(void);
        bld_proc = (boolean (*)(void))GetProcAddress(blade, "ClientStartMainChar");
        return bld_proc();
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B6188
*/

#ifdef BLD_NATIVE

int ServerSetSendDataState(int state)
{
        int (*bld_proc)(int state);
        bld_proc = (int (*)(int state))GetProcAddress(blade, "ServerSetSendDataState");
        return bld_proc(state);
}

#endif


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

int GetNetState(void)
{
        if (gbl_net->is_net_game()) {
                if (gbl_net->is_server())
                        return 1;

                return 2;
        }

        return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B61FD
*/

#ifdef BLD_NATIVE

void ClearPools(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "ClearPools");
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
* Entry point:            0x005B637B
*/

boolean StartServer(
        const char *game_name, const char *player_name, int max_players,
        boolean TCP
)
{
        bool status;

        status = gbl_net->start_server(game_name, player_name, max_players, TCP != FALSE);

        strcpy(net_game_name, (game_name + 3));
        gbl_net_max_players = max_players - 1;

        return status;
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B63E4
*/

boolean BrowseSessions(const char *ip_address)
{
        return gbl_net->browse_sessions(ip_address);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B63FE
*/

boolean GetBrowseResult(int index, bld_server_info *info)
{
        return gbl_net->get_browse_result(index, info);
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B641C
*/

boolean JoinSession(int index, const char *player_name)
{
        bool status;

        reset_client_map_name();

        status = gbl_net->join_session(index, player_name);

        return status;
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B6448
*/

#ifdef BLD_NATIVE

void RestartNet(void)
{
        void (*bld_proc)(void);
        bld_proc = (void (*)(void))GetProcAddress(blade, "RestartNet");
        bld_proc();
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B6464
*/

#ifdef BLD_NATIVE

void NetServerChangeLevel(const char *level_name)
{
        void (*bld_proc)(const char *level_name);
        bld_proc = (void (*)(const char *level_name))GetProcAddress(blade, "NetServerChangeLevel");
        bld_proc(level_name);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B6475
*/

#ifdef BLD_NATIVE

float NetGetTime(void)
{
        float (*bld_proc)(void);
        bld_proc = (float (*)(void))GetProcAddress(blade, "NetGetTime");
        return bld_proc();
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B647F
*/

#ifdef BLD_NATIVE

int NetSetPPS(int PPS)
{
        int (*bld_proc)(int PPS);
        bld_proc = (int (*)(int PPS))GetProcAddress(blade, "NetSetPPS");
        return bld_proc(PPS);
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B6490
*/

int IsValidProtocol(int protocol)
{
        return gbl_net->is_valid_protocol(protocol != FALSE);
}

