#define BBLIBC_LIB_EXPORT
#include "Pal.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x100093C8
* VC++ mangling:          ?GetRed@B_Pal@@QBEEI@Z
*/

#ifndef BLD_NATIVE
unsigned char B_Pal::GetRed(unsigned int val) const
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x100093E1
* VC++ mangling:          ?GetGreen@B_Pal@@QBEEI@Z
*/

#ifndef BLD_NATIVE
unsigned char B_Pal::GetGreen(unsigned int val) const
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x100093FB
* VC++ mangling:          ?GetBlue@B_Pal@@QBEEI@Z
*/

#ifndef BLD_NATIVE
unsigned char B_Pal::GetBlue(unsigned int val) const
{
    return 0;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10009415
* VC++ mangling:          ?SetRed@B_Pal@@QAEXIE@Z
*/
#ifndef BLD_NATIVE
void B_Pal::SetRed(unsigned int arg_1, unsigned char arg_2)
{
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10009431
* VC++ mangling:          ?SetGreen@B_Pal@@QAEXIE@Z
*/
#ifndef BLD_NATIVE
void B_Pal::SetGreen(unsigned int arg_1, unsigned char arg_2)
{
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x1000944E
* VC++ mangling:          ?SetBlue@B_Pal@@QAEXIE@Z
*/
#ifndef BLD_NATIVE
void B_Pal::SetBlue(unsigned int arg_1, unsigned char arg_2)
{
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x1000946B
* VC++ mangling:          ?GetIndex@B_Pal@@QBEIEEEI@Z
*/
#ifndef BLD_NATIVE
unsigned int B_Pal::GetIndex(
    unsigned char arg_1,
    unsigned char arg_2,
    unsigned char arg_3,
    unsigned int arg_4
)
{
    return 0;
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x10009633
* VC++ mangling:          ?Id@B_Pal@@QAEABV1@XZ
*/
#ifndef BLD_NATIVE
const B_Pal &B_Pal::Id()
{
    return *this;
}
#endif
