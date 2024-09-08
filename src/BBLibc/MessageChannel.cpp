#include "MessageChannel.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002550
* VC++ mangling:          ??1B_MessageChannel@@UAE@XZ
*/

B_MessageChannel::~B_MessageChannel()
{
	// Add a dummy statement to prevent optimization
    unknown0Ch = 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100024C0
* VC++ mangling:          ??0B_MessageChannel@@QAE@AAVB_Name@@@Z
*/

// FIXME ??0B_MessageChannel@@QAE@PAVB_Name@@@Z
B_MessageChannel::B_MessageChannel(B_Name* name) : B_NamedObj(*name) {
    // TODO Implement
    unknown0Ch = 1;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1002A284
* VC++ mangling:          ?Message@B_MessageChannel@@UAEIPBD@Z
*/

unsigned int B_MessageChannel::Message(char const* message) {
    // TODO Implement
    this->unknown0Ch = 1;

    return 0;
}
