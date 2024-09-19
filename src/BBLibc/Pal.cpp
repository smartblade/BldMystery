#define BBLIBC_LIB_EXPORT
#include "Pal.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x100093C8
* VC++ mangling:          ?GetRed@B_Pal@@QBEEI@Z
*/

#ifndef BLD_NATIVE
unsigned char B_Pal::GetRed(unsigned int val) const { return 0; };
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x100093E1
* VC++ mangling:          ?GetGreen@B_Pal@@QBEEI@Z
*/

#ifndef BLD_NATIVE
unsigned char B_Pal::GetGreen(unsigned int val) const { return 0; };
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x100093FB
* VC++ mangling:          ?GetBlue@B_Pal@@QBEEI@Z
*/

#ifndef BLD_NATIVE
unsigned char B_Pal::GetBlue(unsigned int val) const { return 0; };
#endif
