#define BBLIBC_LIB_EXPORT
#include "MessageChannel.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x100024C0
* VC++ mangling:          ??0B_MessageChannel@@QAE@AAVB_Name@@@Z
*/

B_MessageChannel::B_MessageChannel(B_Name& name) : B_NamedObj(name)
{
    unknown0Ch = 1;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002550
* VC++ mangling:          ??1B_MessageChannel@@UAE@XZ
*/

B_MessageChannel::~B_MessageChannel()
{
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1002A284
* VC++ mangling:          ?Message@B_MessageChannel@@UAEIPBD@Z
*/

unsigned int B_MessageChannel::Message(char const* message)
{
    return 0; // This is the actual implementation (xor     eax, eax)
}

