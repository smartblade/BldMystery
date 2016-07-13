
#include "netblade_int.h"


bool is_valid_ipx = false;
bool is_valid_tcp = false;
bld_net *gbl_net = NULL;



/*
* Module:                 NetBlade.dll
* Entry point:            0x100037D0
*/

void bld_net::message_received(
        unsigned long idFrom, void *message, unsigned int messageSize
) {
        gbl_net->cb->message_received(idFrom, message, messageSize);
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x100037F6
*/

void unknown100037F6() {
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x100037FB
*/

void bld_net::player_destroyed(unsigned long playerId)
{
        gbl_net->cb->player_destroyed(playerId);
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x1000381B
*/

void bld_net::cb_unknown00C(int i1, int i2, int i3, const char *s) {
        gbl_net->cb->unknown00C(i1, i2, i3, s);
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x10003847
*/

void unknown10003847() {
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x1000384C
*/

void bld_net::player_created(unsigned long playerId, const char *name)
{
        gbl_net->cb->player_created(playerId, name);
}


/*
* Module:                 NetBlade.dll
* Entry point:            0x1000386F
*/
// TODO implement
bld_abstract_net *GetNetInterface(bld_net_cb *cb, void *module) {

        if (gbl_net == NULL) {

                assert(cb!=NULL);

                gbl_net = new bld_net(cb);

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

                is_valid_ipx = bld_check_protocol(false);
                is_valid_tcp = bld_check_protocol(true);
        }

        return gbl_net;
}

/*
* Module:                 NetBlade.dll
* Entry point:            0x10003928
*/
// TODO implement
void CloseConnection() {
        assert("CloseConnection" == NULL);
}

