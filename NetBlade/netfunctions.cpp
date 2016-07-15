
#include "netblade_int.h"


static char gbl_unknown_names[3][40] = {"", "", ""};
bool is_server = false;
bool is_net_game = false;
HANDLE gbl_event = NULL;
HANDLE gbl_thread = NULL;
DWORD gbl_thread_id = 0;


static void bld_system_message_received(
        PLAYER_INFO playerInfo, LPVOID message, DWORD messageSize,
        DPID idFrom, DPID idTo
);
static void bld_user_message_received(
        PLAYER_INFO playerInfo, LPVOID message, DWORD messageSize,
        DPID idFrom, DPID idTo
);


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
* Entry point:            0x10001203
*/
// TODO implement
DWORD WINAPI bld_thread_start_cb(LPVOID lpThreadParameter)
{
        assert("bld_thread_start_cb" == NULL);
        return 0;
}


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
        if (FAILED(hr))
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
// TODO implement
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
* Entry point:            0x10001547
*/

void bld_system_message_received(
        PLAYER_INFO playerInfo, LPVOID message, DWORD messageSize,
        DPID idFrom, DPID idTo
) {
        char *strBuf = NULL;
        LPDPMSG_CREATEPLAYERORGROUP cpgMsg;
        const char *cpgFormat;
        const char *cpgName;
        LPDPMSG_DESTROYPLAYERORGROUP dpgMsg;
        const char *dpgFormat;
        const char *dpgName;
        LPDPMSG_ADDPLAYERTOGROUP apMsg;
        LPDPMSG_DELETEPLAYERFROMGROUP dpMsg;
        LPDPMSG_SESSIONLOST slMsg;
        LPDPMSG_SETPLAYERORGROUPDATA spgdMsg;
        LPDPMSG_SETPLAYERORGROUPNAME spgnMsg;
        DWORD dwType;

        dwType = ((LPDPMSG_GENERIC)message)->dwType;

        switch(dwType)
        {
                case DPSYS_CREATEPLAYERORGROUP:

                        cpgMsg = (LPDPMSG_CREATEPLAYERORGROUP)message;
                        cpgFormat = "%s has joined";

                        if (cpgMsg->dpnName.lpszShortNameA)
                                cpgName = cpgMsg->dpnName.lpszShortNameA;
                        else
                                cpgName = "unknown";

                        strBuf = (char *)GlobalLock(
                                GlobalAlloc(
                                        GHND,
                                        lstrlen(cpgFormat) + lstrlen(cpgName) + 1
                                )
                        );
                        if (strBuf == NULL)
                                break;

                        wsprintf(strBuf, cpgFormat, cpgName);
                        bld_shift_unknown_names(strBuf);
                        bld_net::player_created(cpgMsg->dpId, cpgName);
                        break;

                case DPSYS_DESTROYPLAYERORGROUP:

                        dpgMsg = (LPDPMSG_DESTROYPLAYERORGROUP)message;
                        dpgFormat = "%s has left";

                        bld_net::player_destroyed(dpgMsg->dpId);
                        if (
                                dpgMsg->dwRemoteDataSize != 0 &&
                                dpgMsg->lpRemoteData != NULL
                        )
                                dpgName = (char *)dpgMsg->lpRemoteData;
                        else
                                dpgName = "unknown";

                        strBuf = (char *)GlobalLock(
                                GlobalAlloc(
                                        GHND,
                                        lstrlen(dpgFormat) + lstrlen(dpgName) + 1
                                )
                        );
                        if (strBuf == NULL)
                                break;

                        wsprintf(strBuf, dpgFormat, dpgName);
                        bld_shift_unknown_names(strBuf);
                        break;

                case DPSYS_ADDPLAYERTOGROUP:
                        apMsg = (LPDPMSG_ADDPLAYERTOGROUP)message;
                        break;
                case DPSYS_DELETEPLAYERFROMGROUP:
                        dpMsg = (LPDPMSG_DELETEPLAYERFROMGROUP)message;
                        break;
                case DPSYS_SESSIONLOST:
                        slMsg = (LPDPMSG_SESSIONLOST)message;
                        break;
                case DPSYS_SETPLAYERORGROUPDATA:
                        spgdMsg = (LPDPMSG_SETPLAYERORGROUPDATA)message;
                        break;
                case DPSYS_SETPLAYERORGROUPNAME:
                        spgnMsg = (LPDPMSG_SETPLAYERORGROUPNAME)message;
                        break;
        }
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10001711
*/

void bld_user_message_received(
        PLAYER_INFO playerInfo, LPVOID message, DWORD messageSize,
        DPID idFrom, DPID idTo
) {
        bld_net::message_received(idFrom, message, messageSize);
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
* Entry point:            0x1000188C
*/

HRESULT bld_send_message(DPID idTo, LPVOID lpData, DWORD wDataSize) {
        HRESULT hr;
        hr = gbl_player_info.dp_interface->Send(
                gbl_player_info.dpid, idTo, 0, lpData, wDataSize
        );
        return hr;
}

/*
* Module:                 NetBlade.dll
* Entry point:            0x100018BF
*/

HRESULT bld_send_guaranteed_message(DPID idTo, LPVOID lpData, DWORD wDataSize) {
        HRESULT hr;
        hr = gbl_player_info.dp_interface->Send(
                gbl_player_info.dpid, idTo, DPSEND_GUARANTEED, lpData, wDataSize
        );
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
* Entry point:            0x10001BFB
*/

HRESULT bld_create_thread()
{
        HRESULT hr = DP_OK;

        gbl_dp_lobby = NULL;
        is_net_game = false;
        memset(&gbl_unknown_names, 0, sizeof(gbl_unknown_names));
        memset(&gbl_player_info, 0, sizeof(gbl_player_info));

        gbl_player_info.event = CreateEventA(NULL, FALSE, FALSE, NULL);
        if (gbl_player_info.event == NULL)
        {
                hr = DPERR_NOMEMORY;
                goto cleanup;
        }

        gbl_event = CreateEventA(NULL, FALSE, FALSE, NULL);
        if (gbl_event == NULL)
        {
                hr = DPERR_NOMEMORY;
                goto cleanup;
        }

        gbl_thread = CreateThread(
                NULL, 0, bld_thread_start_cb, &gbl_player_info, 0,
                &gbl_thread_id
        );
        if (gbl_thread == NULL)
        {
                hr = DPERR_NOMEMORY;
                goto cleanup;
        }

        return hr;

cleanup:
        bld_destroy_handles();

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
* Entry point:            0x10001CD7
*/

HRESULT bld_update_player_data() {
        HRESULT hr;
        char *player_name;
        LPDPNAME lpdpname;

        hr = bld_get_player_name(
                gbl_player_info.dp_interface, gbl_player_info.dpid, &lpdpname
        );
        if (FAILED(hr))
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
        if (FAILED(hr))
                goto cleanup;

        bld_shift_unknown_names("Net Game");
        is_net_game = true;
        bld_enum_players(gbl_player_info.dp_interface);
        return DP_OK;

cleanup:
        bld_destroy_handles();
        return hr;
}

