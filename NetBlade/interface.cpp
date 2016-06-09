
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
static int gbl_num_sessions = 0;
static SESSION_INFO gbl_sessions[MAX_SESSIONS_NUM];
LPDIRECTPLAY4A gbl_dp_interface = NULL;


static HRESULT bld_create_player(
        LPDIRECTPLAY4A dp_interface, const char *game_name,
        const char *player_name, PLAYER_INFO *player_info
);
static HRESULT bld_enum_sessions(LPDIRECTPLAY4A dp_interface);
static BOOL PASCAL bld_enum_sessions_cb(
        LPCDPSESSIONDESC2 lpThisSD, LPDWORD lpdwTimeOut, DWORD dwFlags,
        LPVOID lpContext);


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

bool bld_start_server(
        const char *game_name, const char *player_name, int max_players,
        bool TCP
) {
        HRESULT hr;
        GUID dp_provider;

        hr = bld_create_thread();
        if (FAILED(hr))
                goto finish;

        if (gbl_dp_interface == NULL) {
                if (TCP)
                        dp_provider = DPSPGUID_TCPIP;
                else
                        dp_provider = DPSPGUID_IPX;

                hr = bld_create_dp_interface(&dp_provider, &gbl_dp_interface);
                bld_assert_result(hr);
                if (FAILED(hr))
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

        if (FAILED(hr))
                goto finish;

        hr = bld_update_player_data();

finish:
        if (FAILED(hr)) {
                bld_destroy_dp_interface(gbl_dp_interface);
                gbl_dp_interface = NULL;
                is_net_game = false;
                return false;
        } else {
                bld_net::cb_unknown00C(0, 1, 0, player_name);
                is_net_game = true;
                is_server = true;
                return true;
        }
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
        if (FAILED(hr))
                goto close;

        ZeroMemory(&name,sizeof(DPNAME));
        name.dwSize = sizeof(DPNAME);
        name.lpszShortNameA = (char *)player_name;
        name.lpszLongNameA = NULL;

        dp_interface->CreatePlayer(
                &dpid, &name, player_info->event, NULL, 0, DPPLAYER_SERVERPLAYER
        );
        if (FAILED(hr))
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
        if (FAILED(hr))
                goto cleanup;

        /* Get interface of required  version */
        hr = lpdp->QueryInterface(IID_IDirectPlay4A, (VOID**)&lpdp4);
        if (FAILED(hr))
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
* Entry point:            0x10003107
*/

bool bld_browse_sessions(const char *ip_address)
{
        DWORD lpConnectionSize;
        char lpConnection[128];
        HRESULT hr;
        LPDIRECTPLAYLOBBYA lpdplobby;
        GUID dp_provider;

        lpConnectionSize = sizeof(lpConnection);

        hr = bld_create_thread();
        if (FAILED(hr))
                goto cleanup;

        if (gbl_dp_interface == NULL) {
                if (ip_address)
                        dp_provider = GUID_NULL;
                else
                        dp_provider = DPSPGUID_IPX;

                hr = bld_create_dp_interface(&dp_provider, &gbl_dp_interface);
                bld_assert_result(hr);
                if (FAILED(hr))
                        goto cleanup;
        }

        if (ip_address)
        {
                if (gbl_dp_lobby == NULL)
                {
                        // creating lobby object
                        hr = DirectPlayLobbyCreateA(
                                NULL, &lpdplobby, NULL, NULL, 0
                        );
                        if (FAILED(hr))
                                goto cleanup;

                        // get new interface of lobby
	                    hr = lpdplobby->QueryInterface(
                                IID_IDirectPlayLobby3A, (LPVOID *)&gbl_dp_lobby
                        );

                        // release old interface since we have new one
                        lpdplobby->Release();
                        if (FAILED(hr))
                                goto cleanup;
                }

                hr = gbl_dp_lobby->CreateAddress(
                        DPSPGUID_TCPIP, DPAID_INet, ip_address,
                        strlen(ip_address), &lpConnection, &lpConnectionSize
                );
                if (FAILED(hr))
                        goto cleanup;

                hr = gbl_dp_interface->InitializeConnection(&lpConnection, 0);
                bld_assert_result(hr);
                if (FAILED(hr))
                        goto cleanup;
        }

        hr = bld_enum_sessions(gbl_dp_interface);
        if (FAILED(hr))
                goto cleanup;

        return true;

cleanup:
        if (gbl_dp_lobby)
                gbl_dp_lobby->Release();

        gbl_dp_lobby = NULL;

        bld_destroy_dp_interface(gbl_dp_interface);

        gbl_dp_interface = NULL;

        return false;
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x1000346E
*/

HRESULT bld_enum_sessions(LPDIRECTPLAY4A dp_interface)
{
        HRESULT hr;
        DPSESSIONDESC2 session_desc;

        if (dp_interface == NULL)
                return DPERR_INVALIDOBJECT;

        gbl_num_sessions = 0;

        ZeroMemory(&session_desc, sizeof(DPSESSIONDESC2));
        session_desc.dwSize = sizeof(DPSESSIONDESC2);
        session_desc.guidApplication = AppGUID;

        hr = dp_interface->EnumSessions(
                &session_desc, 0, bld_enum_sessions_cb, NULL,
                DPENUMSESSIONS_AVAILABLE
        );

        return hr;
}

/*
* Module:                 NetBlade.dll
* Entry point:            0x100034E7
*/

BOOL PASCAL bld_enum_sessions_cb(
        LPCDPSESSIONDESC2 lpThisSD, LPDWORD lpdwTimeOut, DWORD dwFlags,
        LPVOID lpContext)
{
        BOOL code;

        if (dwFlags & DPESC_TIMEDOUT)
            return FALSE;

        if (gbl_num_sessions < MAX_SESSIONS_NUM)
        {
            gbl_sessions[gbl_num_sessions].desc = *lpThisSD;
            strcpy(
                    gbl_sessions[gbl_num_sessions].session_name,
                    lpThisSD->lpszSessionNameA
            );
            gbl_sessions[gbl_num_sessions].desc.lpszSessionNameA =
                    gbl_sessions[gbl_num_sessions].session_name;

            gbl_num_sessions++;
            code = TRUE;
        }
        else
            code = FALSE;

        return code;
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

        if (FAILED(bld_create_dp_interface(&dp_provider, &gbl_dp_interface)))
                return false;

        bld_destroy_dp_interface(gbl_dp_interface);
        gbl_dp_interface = NULL;

        return true;
}

