
#include <bld_system.h>
#include "BladeApp.h"
#include "bld_misc_funcs.h"


/*
* Module:                 Blade.exe
* Entry point:            0x005B9B60
*/

B_App* create_application(void *module, int nCmdShow, char *cmdLine)
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

B_App* get_application()
{
    return gbl_application;
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B9BC1
* VC++ mangling:          ??0B_BladeApp@@QAE@PAXHPAD@Z
*/
#ifdef BLD_NATIVE_CONSTRUCTOR
B_BladeApp::B_BladeApp(void *module, int nCmdShow, char *cmdLine)
{
}
#endif
