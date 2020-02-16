
#include "WinClock.h"


/*
* Module:                 Blade.exe
* Entry point:            0x004CC1C0
* VC++ mangling:          ??0B_WinClock@@QAE@XZ
*/
#ifdef BLD_NATIVE_CONSTRUCTOR
B_WinClock::B_WinClock()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004CC480
* VC++ mangling:          ?GetTimeSpeed@B_Clock@@UAENXZ
*/

double B_Clock::GetTimeSpeed()
{
    return this->timeSpeed;
}

/*
* Module:                 Blade.exe
* Entry point:            0x004CC5F0
* VC++ mangling:          ?IsActive@B_Clock@@UAE_NXZ
*/
bool B_Clock::IsActive()
{
    return this->isActive;
}
