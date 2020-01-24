
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

int nCDTracks()
{
    if (cdPlayer != NULL)
        return cdPlayer->nCDTracks();
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427799
*/

int CDLenght()
{
    if (cdPlayer != NULL)
        return cdPlayer->CDLenght();
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004277BB
*/

int CDTrackLenght(int ntrack)
{
    if (cdPlayer != NULL)
        return cdPlayer->CDTrackLenght(ntrack);
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004277E2
*/

int CDPresent()
{
    if (cdPlayer != NULL)
        return cdPlayer->CDPresent();
    return 0;
}


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
