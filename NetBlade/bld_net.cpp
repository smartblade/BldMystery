
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
// TODO implement
void bld_net::unknown004() {
        assert("unknown004" == NULL);
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
// TODO implement
bool bld_net::is_server() {
        assert("is_server" == NULL);
        return false;
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
// TODO implement
void bld_net::unknown014() {
        assert("unknown014" == NULL);
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x100039E0
*/
// TODO implement
void bld_net::unknown018() {
        assert("unknown018" == NULL);
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
// TODO implement
bool bld_net::browse_sessions(const char *ip_address) {
        assert("browse_sessions" == NULL);
        return false;
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

