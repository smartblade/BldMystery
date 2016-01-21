
#include "netblade_int.h"

LPDIRECTPLAYLOBBY3A gbl_dp_lobby = NULL;
LPDIRECTPLAY4A gbl_dp_interface = NULL;


/*
* Module:                 NetBlade.dll
* Entry point:            0x10002C70
*/
// TODO implement
bool bld_start_server(
        const char *game_name, const char *player_name, int max_players,
        bool TCP
) {
        assert("bld_start_server" == NULL);
        return false;
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10002EE5
*/
// TODO implement
void unknown(
        LPDIRECTPLAY4A dp_interface, const char *game_name,
        const char *player_name
) {
        //dp_interface->Open();
        //dp_interface->CreatePlayer();
        //dp_interface->Close();
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

