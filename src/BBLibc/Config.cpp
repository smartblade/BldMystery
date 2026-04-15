#define BBLIBC_LIB_EXPORT
#include "Config.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002740
* VC++ mangling:          ?GetConfigDirectory@@YAPBDXZ
*/
#ifndef BLD_NATIVE
const char *GetConfigDirectory()
{
    return 0;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x100028EC
* VC++ mangling:          ?GetCurrentLanguage@@YAPBDXZ
*/
#ifndef BLD_NATIVE
const char *GetCurrentLanguage()
{
    return 0;
}
#endif
