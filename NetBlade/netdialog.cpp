
#include "netblade_int.h"

static DPID gbl_player_dpid = DPID_SERVERPLAYER;


static BOOL PASCAL bld_enum_players_cb(
        DPID dpId, DWORD dwPlayerType, LPCDPNAME lpName, DWORD dwFlags,
        LPVOID lpContext
);

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 NetBlade.dll
* Entry point:            0x10001DCD
*/

DPID bld_get_session_player_dpid() {
        return gbl_player_dpid;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 NetBlade.dll
* Entry point:            0x10001EE9
*/

BOOL PASCAL bld_enum_players_cb(
        DPID dpId, DWORD dwPlayerType, LPCDPNAME lpName, DWORD dwFlags,
        LPVOID lpContext)
{
        if (dwFlags & 0x01/*TODO use macro*/)
                gbl_player_dpid = dpId;

        return TRUE;
}

/*
* Module:                 NetBlade.dll
* Entry point:            0x10001F08
*/

void bld_enum_players(LPDIRECTPLAY4A dp_interface)
{
        if (bld_is_server())
                gbl_player_dpid = bld_get_player_dpid();
        else
                dp_interface->EnumPlayers(
                        NULL, bld_enum_players_cb, NULL, DPENUMPLAYERS_ALL
                );
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

