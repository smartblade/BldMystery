
#include "netblade_int.h"

/*
* Module:                 NetBlade.dll
* Entry point:            0x10003960
*/
// TODO implement
void bld_net::unknown000() {
        assert("unknown000" == NULL);
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003970
*/

unsigned long bld_net::get_all_players_id() {
        return DPID_ALLPLAYERS;
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003980
*/

bool bld_net::is_net_game() {
        return bld_is_net_game();
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003990
*/

bool bld_net::is_server() {
        return bld_is_server();
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x100039A0
*/
// TODO implement
void bld_net::unknown010() {
        assert("unknown010" == NULL);
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x100039B0
*/

long bld_net::send_message(unsigned long idTo, void *lpData, unsigned long wDataSize) {
        return bld_send_message(idTo, lpData, wDataSize);
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x100039E0
*/

long bld_net::send_guaranteed_message(
        unsigned long idTo, void *lpData, unsigned long wDataSize
) {
        return bld_send_guaranteed_message(idTo, lpData, wDataSize);
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003A10
*/

bool bld_net::start_server(
                const char *game_name, const char *player_name, int max_players,
                bool TCP
) {
        return bld_start_server(game_name, player_name, max_players, TCP);
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003A40
*/

bool bld_net::browse_sessions(const char *ip_address) {
        return bld_browse_sessions(ip_address);
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003A60
*/
// TODO implement
bool bld_net::get_browse_result(int index, bld_server_info *info) {
        assert("get_browse_result" == NULL);
        return false;
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003A80
*/
// TODO implement
bool bld_net::join_session(int index, const char *player_name) {
        assert("join_session" == NULL);
        return false;
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003AA0
*/

bool bld_net::is_valid_protocol(bool tcp) {
        if (tcp)
                return is_valid_tcp;
        else
                return is_valid_ipx;
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003AD0
*/
// TODO implement
bld_net::~bld_net() {
        assert("~bld_net" == NULL);
}

