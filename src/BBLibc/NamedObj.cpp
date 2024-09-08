#define BBLIBC_LIB_EXPORT
#include "NamedObj.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x100039E5
* VC++ mangling:          ??0B_NamedObj@@QAE@XZ
*/

B_NamedObj::B_NamedObj() : name() {}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003A07
* VC++ mangling:          ??0B_NamedObj@@QAE@ABVB_Name@@@Z
*/

B_NamedObj::B_NamedObj(const B_Name& n) : name(n) {}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002300
* VC++ mangling:          ??1B_NamedObj@@UAE@XZ
*/

B_NamedObj::~B_NamedObj() {
    // TODO Implement
    //delete name;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10003A2F
* VC++ mangling:          ?Id@B_NamedObj@@QBEABVB_Name@@XZ
*/

const B_Name& B_NamedObj::Id() const {
    return name;
}
