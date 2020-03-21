#include "libnet.h"


/*
* Module:                 Blade.exe
* Entry point:            0x005B64C0
*/
#ifdef BLD_NATIVE
void SetDedicatedServer(bool isDedicated)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005B64CD
*/
#ifdef BLD_NATIVE
bool IsDedicatedServer()
{
    return false;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x005B65D2
*/
#ifdef BLD_NATIVE
void LoadNetModule(char *fileName)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005B668D
*/
#ifdef BLD_NATIVE
bool FreeNetData(bool freeNetLibrary)
{
    return false;
}
#endif
