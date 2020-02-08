
#include <bld_system.h>
#include "BladeApp.h"
#include "bld_misc_funcs.h"


/*
* Module:                 Blade.exe
* Entry point:            0x005B9B60
*/

B_App* CreateApplication(void *module, int nCmdShow, char *cmdLine)
{
    B_App *new_application = new B_BladeApp(module, nCmdShow, cmdLine);
    gbl_application = new_application;

    return gbl_application;
}

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x005B9BB7
*/

B_App* GetApplication()
{
    return gbl_application;
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B9BC1
* VC++ mangling:          ??0B_BladeApp@@QAE@PAXHPAD@Z
*/

B_BladeApp::B_BladeApp(void *module, int nCmdShow, char *cmdLine)
:
B_WinApp(module, nCmdShow, cmdLine, NULL)
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B9BF0
* VC++ mangling:          ?Start@B_BladeApp@@UAE_NXZ
*/

bool B_BladeApp::Start()
{
    return B_WinApp::Start();
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B9C03
* VC++ mangling:          ?ProcessEvents@B_BladeApp@@UAE_NXZ
*/

bool B_BladeApp::ProcessEvents()
{
    return B_WinApp::ProcessEvents();
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B9C16
* VC++ mangling:          ?End@B_BladeApp@@UAEXXZ
*/

void B_BladeApp::End()
{
    B_WinApp::End();
}
