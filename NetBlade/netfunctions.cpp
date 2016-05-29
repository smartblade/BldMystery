
#include "netblade_int.h"


static char gbl_unknown_names[3][40] = {"", "", ""};
static bool is_server = false;
bool is_net_game = false;


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001000
*/

bool bld_is_server() {
        return is_server;
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x1000100A
*/

bool bld_is_net_game() {
        return is_net_game;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 NetBlade.dll
* Entry point:            0x1000101E
*/

void bld_set_gbl_player_info(PLAYER_INFO *player_info) {
        gbl_player_info = *player_info;
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001036
*/

DPID bld_get_player_dpid() {
        return gbl_player_info.dpid;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 NetBlade.dll
* Entry point:            0x10001253
*/

HRESULT bld_get_player_name(
        LPDIRECTPLAY4A dp_interface, DPID dpid, LPDPNAME *lpdpname
) {
        HRESULT hr;
        DWORD len;
        LPVOID nameMem = NULL;

        hr = dp_interface->GetPlayerName(dpid, NULL, &len);
        if (hr != DPERR_BUFFERTOOSMALL)
                goto cleanup;

        nameMem = GlobalLock(GlobalAlloc(GHND, len));
        if (nameMem == NULL) {
                hr = DPERR_NOMEMORY;
                goto cleanup;
        }

        hr = dp_interface->GetPlayerName(dpid, nameMem, &len);
        if (hr < DP_OK)
                goto cleanup;

        *lpdpname = (LPDPNAME)nameMem;
        return DP_OK;

cleanup:
        if (nameMem != NULL) {
                GlobalUnlock(GlobalHandle(nameMem));
                GlobalFree(GlobalHandle(nameMem));
        }

        return hr;
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001312
*/

int bld_destroy_handles() {
        assert("bld_destroy_handles" == NULL);
        return 0;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 NetBlade.dll
* Entry point:            0x10001744
*/

void bld_shift_unknown_names(const char *name) {
        for(int i = 0; i < 2; i++)
                lstrcpy(gbl_unknown_names[i], gbl_unknown_names[i + 1]);
        lstrcpy(gbl_unknown_names[2], name);
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001BFB
*/
// TODO implement
HRESULT bld_create_thread() {
        assert("bld_create_thread" == NULL);
        return 0;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 NetBlade.dll
* Entry point:            0x10001CD7
*/

HRESULT bld_update_player_data() {
        HRESULT hr;
        char *player_name;
        LPDPNAME lpdpname;

        hr = bld_get_player_name(
                gbl_player_info.dp_interface, gbl_player_info.dpid, &lpdpname
        );
        if (hr < DP_OK)
                goto cleanup;

        if (lpdpname->lpszShortNameA)
                player_name = lpdpname->lpszShortNameA;
        else
                player_name = "unknown";

        hr = gbl_player_info.dp_interface->SetPlayerData(
                gbl_player_info.dpid, player_name, lstrlen(player_name) + 1,
                DPSET_GUARANTEED
        );
        GlobalUnlock(GlobalHandle(lpdpname));
        GlobalFree(GlobalHandle(lpdpname));
        if (hr < DP_OK)
                goto cleanup;

        bld_shift_unknown_names("Net Game");
        is_net_game = true;
        bld_enum_players(gbl_player_info.dp_interface);
        return DP_OK;

cleanup:
        bld_destroy_handles();
        return hr;
}

