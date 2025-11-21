#define BBLIBC_LIB_EXPORT
#include "ChannelOFile.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x100298B0
* VC++ mangling:          ??0B_ChannelOFile@@QAE@VB_Name@@PBD@Z
*/
#ifndef BLD_NATIVE
B_ChannelOFile::B_ChannelOFile(B_Name arg_1, const char *)
    : B_MessageChannel(arg_1)
{
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x1002994D
* VC++ mangling:          ??1B_ChannelOFile@@UAE@XZ
*/
#ifndef BLD_NATIVE
B_ChannelOFile::~B_ChannelOFile()
{
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x100299E1
* VC++ mangling:          ?Open@B_ChannelOFile@@UAEIXZ
*/
#ifndef BLD_NATIVE
unsigned int B_ChannelOFile::Open()
{
    return 0;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10029A08
* VC++ mangling:          ?Close@B_ChannelOFile@@UAEIXZ
*/
#ifndef BLD_NATIVE
unsigned int B_ChannelOFile::Close()
{
    return 0;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10029A22
* VC++ mangling:          ?Message@B_ChannelOFile@@UAEIPBD@Z
*/
#ifndef BLD_NATIVE
unsigned int B_ChannelOFile::Message(const char *arg_1)
{
    return 0;
}
#endif
