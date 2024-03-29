
#include "WinClock.h"

#include "ProcessorTimer.h"
#include <intrin.h>
#include <bld_system.h>


/*
* Module:                 Blade.exe
* Entry point:            0x004CC1C0
* VC++ mangling:          ??0B_WinClock@@QAE@XZ
*/

B_WinClock::B_WinClock()
:
isNotNT(false), hasCpuid(false), hasCpiudFunc(false), hasProcessorTimer(false)
{
    OSVERSIONINFO osVersionInfo;
    osVersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    if (!GetVersionEx(&osVersionInfo))
    {
        this->isNotNT = true;
        return;
    }
    if (osVersionInfo.dwPlatformId == VER_PLATFORM_WIN32_NT)
    {
        this->isNotNT = false;
    }
    else
    {
        this->isNotNT = true;
    }
    timeGetDevCaps(&this->timeCaps, sizeof(TIMECAPS));
    /* Try to change 21-th flag of EFLAGS to check support of CPUID command */
    unsigned int eflags = __readeflags();
    __writeeflags(eflags ^ 0x200000);
    if (__readeflags() ^ eflags)
    {
        this->hasCpuid = true;
        int cpuInfo[4];
        __cpuid(cpuInfo, 0);
        if (((unsigned int)cpuInfo[0]) >= 1 &&
            /* Check processor model. Should be "GenuineIntel" */
            cpuInfo[1] == 0x756E6547 &&
            cpuInfo[3] == 0x49656E69 &&
            cpuInfo[2] == 0x6C65746E)
        {
            this->hasCpiudFunc = true;
        }
    }
    if (this->hasCpiudFunc && this->hasCpuid)
    {
        this->processorTimer = new B_ProcessorTimer();
        this->hasProcessorTimer = true;
    }
    this->initialTime = this->GetSystemTime();
}


/*
* Module:                 Blade.exe
* Entry point:            0x004CC3A6
* VC++ mangling:          ?GetSystemTime@B_WinClock@@UAENXZ
*/

double B_WinClock::GetSystemTime()
{
    if (this->hasProcessorTimer)
        return this->processorTimer->GetTime();
    return timeGetTime() / 1000.0;
}
