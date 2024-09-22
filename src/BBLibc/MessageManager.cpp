#define BBLIBC_LIB_EXPORT
#include "MessageManager.h"

B_MessageManager mout;


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002710
* VC++ mangling:          ??1B_MessageManager@@QAE@XZ
*/
#ifndef BLD_NATIVE
B_MessageManager::~B_MessageManager()
{
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10029CFC
* VC++ mangling:          ?Add@B_MessageManager@@QAEIPAVB_MessageChannel@@@Z
*/
#ifndef BLD_NATIVE
unsigned int B_MessageManager::Add(B_MessageChannel* channel)
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10029E17
* VC++ mangling:          ?OpenChannel@B_MessageManager@@QAEIABVB_Name@@@Z
*/
#ifndef BLD_NATIVE
unsigned int B_MessageManager::OpenChannel(const B_Name& channel_name)
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10029E98
* VC++ mangling:          ?CloseChannel@B_MessageManager@@QAEIABVB_Name@@@Z
*/
#ifndef BLD_NATIVE
unsigned int B_MessageManager::CloseChannel(const B_Name& channel_name)
{
    return 1;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10029F19
* VC++ mangling:          ?DisconnectChannel@B_MessageManager@@QAEPAVB_MessageChannel@@ABVB_Name@@@Z
*/
#ifndef BLD_NATIVE
B_MessageChannel* B_MessageManager::DisconnectChannel(const B_Name& channel_name)
{
    return nullptr;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x1002A2C3
* VC++ mangling:          ??6@YAAAVB_MessageManager@@AAV0@PBD@Z
*/
#ifndef BLD_NATIVE
B_MessageManager& operator<<(B_MessageManager& mout, const char* str)
{
    return mout;
}
#endif

