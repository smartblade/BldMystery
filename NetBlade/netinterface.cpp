
#include "netblade_int.h"


bool is_valid_ipx = false;
bool is_valid_tcp = false;

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
bld_abstract_net *GetNetInterface(void *cb, void *module) {
        return new bld_net();
}

/*
* Module:                 NetBlade.dll
* Entry point:            0x10003928
*/
// TODO implement
void CloseConnection() {
        assert("CloseConnection" == NULL);
}

