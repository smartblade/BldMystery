
#include <bld_system.h>
#include "CDPlayer.h"
#define BUILD_LIB
#include <blade_ext.h>

/*
* Module:                 Blade.exe
* Entry point:            0x00427750
*/

int PlayCDTrack(int ntrack)
{
    if (cdPlayer != NULL)
        return cdPlayer->PlayCDTrack(ntrack);
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427777
*/
#ifdef BLD_NATIVE
int nCDTracks(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "nCDTracks");
        return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00427799
*/
#ifdef BLD_NATIVE
int CDLenght(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "CDLenght");
        return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004277BB
*/
#ifdef BLD_NATIVE
int CDTrackLenght(int ntrack)
{
        int (*bld_proc)(int ntrack);
        bld_proc = (int (*)(int ntrack))GetProcAddress(blade, "CDTrackLenght");
        return bld_proc(ntrack);
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004277E2
*/
#ifdef BLD_NATIVE
int CDPresent(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "CDPresent");
        return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00427804
*/
#ifdef BLD_NATIVE
int CDStop(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "CDStop");
        return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00427826
*/
#ifdef BLD_NATIVE
int CDPause(void)
{
        int (*bld_proc)(void);
        bld_proc = (int (*)(void))GetProcAddress(blade, "CDPause");
        return bld_proc();
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00427848
*/
#ifdef BLD_NATIVE
int CDSetCallBack(PyObject *func)
{
        int (*bld_proc)(PyObject *func);
        bld_proc = (int (*)(PyObject *func))GetProcAddress(blade, "CDSetCallBack");
        return bld_proc(func);
}
#endif
