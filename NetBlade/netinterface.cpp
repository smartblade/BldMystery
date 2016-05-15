
#include "netblade_int.h"


bool is_valid_ipx = false;
bool is_valid_tcp = false;
bld_abstract_net *gbl_net = NULL;

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


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

