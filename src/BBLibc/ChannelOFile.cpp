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
