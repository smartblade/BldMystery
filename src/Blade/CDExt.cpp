
#include <bld_system.h>
#include "CDPlayer.h"
#include "BladeApp.h"
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

int CDStop()
{
    if (cdPlayer != NULL)
        return cdPlayer->CDStop();
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427826
*/

int CDPause()
{
    if (cdPlayer != NULL)
        return cdPlayer->CDPause();
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x00427848
*/

int CDSetCallBack(PyObject *func)
{
    B_App *App = GetApplication();
    if (App != NULL)
    {
        App->CDSetCallBack(func);
        return 1;
    }
    return 0;
}
