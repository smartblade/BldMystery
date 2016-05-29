
#include "netblade_int.h"

static GUID AppGUID = {
        0x5BFDB060, 0x06A4, 0x11D0,
        {
                0x9C, 0x4F, 0x00, 0xA0, 0xC9, 0x05, 0x42, 0x5E
        }
};
static int gbl_max_players = 5;
PLAYER_INFO gbl_player_info = {NULL, NULL, NULL, NULL, 0};
LPDIRECTPLAYLOBBY3A gbl_dp_lobby = NULL;
LPDIRECTPLAY4A gbl_dp_interface = NULL;


static HRESULT bld_create_player(
        LPDIRECTPLAY4A dp_interface, const char *game_name,
        const char *player_name, PLAYER_INFO *player_info
);


inline void bld_assert_result(HRESULT hr) {
        assert(DPERR_BUFFERTOOSMALL!=hr);
        assert(DPERR_UNAVAILABLE!=hr);
        assert(DPERR_INVALIDPARAMS!=hr);
        assert(DPERR_INVALIDFLAGS!=hr);
        assert(DPERR_ALREADYINITIALIZED!=hr);
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10002C70
*/
// TODO implement
bool bld_start_server(
        const char *game_name, const char *player_name, int max_players,
        bool TCP
) {
        HRESULT hr;
        GUID dp_provider;

        hr = bld_create_thread();
        if (hr < DP_OK)
                goto finish;

        if (gbl_dp_interface == NULL) {
                if (TCP)
                        dp_provider = DPSPGUID_TCPIP;
                else
                        dp_provider = DPSPGUID_IPX;

                hr = bld_create_dp_interface(&dp_provider, &gbl_dp_interface);
                bld_assert_result(hr);
                if (hr < DP_OK)
                        goto finish;
        }

        gbl_max_players = max_players;
        if (gbl_max_players > 100)
                gbl_max_players = 100;
        if (gbl_max_players < 2)
                gbl_max_players = 2;

        hr = bld_create_player(
                gbl_dp_interface, game_name, player_name, &gbl_player_info
        );
        bld_assert_result(hr);

        bld_set_gbl_player_info(&gbl_player_info);

        if (hr < DP_OK)
                goto finish;

        hr = bld_update_player_data();

finish:
        if (hr < DP_OK) {
                bld_destroy_dp_interface(gbl_dp_interface);
                gbl_dp_interface = NULL;
                is_net_game = false;
                return false;
        }

        assert("bld_start_server" == NULL);

        return false;
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10002EE5
*/

HRESULT bld_create_player(
        LPDIRECTPLAY4A dp_interface, const char *game_name,
        const char *player_name, PLAYER_INFO *player_info
) {
        DPID dpid;/* the dpid of the player created given by directplay */
        DPNAME name;
        HRESULT hr;
        DPSESSIONDESC2 session_desc;

        if (dp_interface == NULL)
                return DPERR_INVALIDOBJECT;

        ZeroMemory(&session_desc, sizeof(DPSESSIONDESC2));
        session_desc.dwSize = sizeof(DPSESSIONDESC2);
        session_desc.dwFlags = (DPSESSION_KEEPALIVE | DPSESSION_MIGRATEHOST);
        session_desc.guidApplication = AppGUID;
        session_desc.dwMaxPlayers = gbl_max_players;
        session_desc.lpszSessionNameA = (char *)game_name;

        hr = dp_interface->Open(&session_desc, DPOPEN_CREATE);
        if (hr < DP_OK)
                goto close;

        ZeroMemory(&name,sizeof(DPNAME));
        name.dwSize = sizeof(DPNAME);
        name.lpszShortNameA = (char *)player_name;
        name.lpszLongNameA = NULL;

        dp_interface->CreatePlayer(
                &dpid, &name, player_info->event, NULL, 0, DPPLAYER_SERVERPLAYER
        );
        if (hr < DP_OK)
                goto close;

        player_info->dp_interface = dp_interface;
        player_info->dpid = dpid;
        player_info->unknown10 = 1;

        return DP_OK;
close:
        dp_interface->Close();

        return hr;
}

/*
* Module:                 NetBlade.dll
* Entry point:            0x10002FF1
*/

HRESULT bld_create_dp_interface(
        LPGUID dp_provider, LPDIRECTPLAY4A *dp_interface
) {
        LPDIRECTPLAY lpdp = NULL;
        LPDIRECTPLAY4A lpdp4 = NULL;
        HRESULT hr;

        /* Creation IDirectPlay interface */
        hr = DirectPlayCreate(dp_provider, &lpdp, NULL);
        if (hr < DP_OK)
                goto cleanup;

        /* Get interface of required  version */
        hr = lpdp->QueryInterface(IID_IDirectPlay4A, (VOID**)&lpdp4);
        if (hr < DP_OK)
                goto cleanup;

        *dp_interface = lpdp4;

cleanup:
        /* Destroy interface */
        if (lpdp)
                lpdp->Release();

        return hr;
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003065
*/

HRESULT bld_destroy_dp_interface(LPDIRECTPLAY4A dp_interface) {
        HRESULT hr = DP_OK;

        if (dp_interface)
                hr = dp_interface->Release();

        return hr;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 NetBlade.dll
* Entry point:            0x100036FC
*/

bool bld_check_protocol(bool tcp) {
        GUID dp_provider;

        if (gbl_dp_interface) {
                if (is_net_game)
                        return false;

                if (gbl_dp_lobby)
                        gbl_dp_lobby->Release();
                gbl_dp_lobby = NULL;

                bld_destroy_dp_interface(gbl_dp_interface);

                gbl_dp_interface = NULL;
        }

        if (tcp)
                dp_provider = DPSPGUID_TCPIP;
        else
                dp_provider = DPSPGUID_IPX;

        if (bld_create_dp_interface(&dp_provider, &gbl_dp_interface) < DP_OK)
                return false;

        bld_destroy_dp_interface(gbl_dp_interface);
        gbl_dp_interface = NULL;

        return true;
}

