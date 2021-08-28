
#include <bld_system.h>
#include <bld_python.h>
#include <NetMod/gamenet.h>
#include "bld_misc_funcs.h"
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
void SetGameSpySupport(boolean enabled)
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
}

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
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B565C
*/

#ifdef BLD_NATIVE

void SetDedicatedServerState(int dedicated)
{
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5673
*/

#ifdef BLD_NATIVE

int GetDedicatedServerState(void)
{
    return 0;
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
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5716
*/

#ifdef BLD_NATIVE

const char *ServerInfoBlock(void)
{
    return NULL;
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5720
*/

#ifdef BLD_NATIVE

void ClientSetPyClientSoundFunc(PyObject *func)
{
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5731
*/

#ifdef BLD_NATIVE

void CallNetEventSound(const char *entity_name, byte id)
{
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5959
*/

#ifdef BLD_NATIVE

void ClientSetPyClientMutilaFunc(PyObject *func)
{
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B596A
*/

#ifdef BLD_NATIVE

void ClientSetPyClientDamageFunc(PyObject *func)
{
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
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5BB2
*/

#ifdef BLD_NATIVE

const char *NetGetClientId(void)
{
    return NULL;
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5BBC
*/

#ifdef BLD_NATIVE

boolean NetSetObjectState(const char *entity_name, boolean state)
{
    return false;
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
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5BF0
*/

#ifdef BLD_NATIVE

void NetAddPosition(double x, double y, double z)
{
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5C15
*/

#ifdef BLD_NATIVE

void NetSetPersonView(const char *entity_name)
{
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
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5E06
*/

#ifdef BLD_NATIVE

void GetNextPosition(double *x, double *y, double *z)
{
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5E74
*/

#ifdef BLD_NATIVE

void ServerSetPyByePlayerFunc(PyObject *func)
{
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5E85
*/

#ifdef BLD_NATIVE

void ServerSetPyGetUserString(PyObject *func)
{
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
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B5EB4
*/

#ifdef BLD_NATIVE

void GetLifeAndLevel(const char *entity_name, int *energy, int *life)
{
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B6146
*/

#ifdef BLD_NATIVE

void ServerSetPyCreatePlayerFunc(PyObject *func)
{
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B6157
*/

#ifdef BLD_NATIVE

boolean ClientStartMainChar(void)
{
    return false;
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B6188
*/

#ifdef BLD_NATIVE

int ServerSetSendDataState(int state)
{
    return 0;
}

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
}

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

        ResetClientMapName();

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
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B6464
*/

#ifdef BLD_NATIVE

void NetServerChangeLevel(const char *level_name)
{
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B6475
*/

#ifdef BLD_NATIVE

float NetGetTime(void)
{
    return 0.0;
}

#endif



/*
* Module:                 Blade.exe
* Entry point:            0x005B647F
*/

#ifdef BLD_NATIVE

int NetSetPPS(int PPS)
{
    return 0;
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

