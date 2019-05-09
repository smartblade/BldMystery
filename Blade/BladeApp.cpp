
#include <bld_system.h>
#include "application.h"
#include "bld_ext_funcs.h"


static application_methods_t application_methods = {
        NULL, NULL, NULL, NULL, NULL, NULL, NULL,
#ifdef _MSC_VER
        _thiscall_application_wait_for_event,
        NULL, NULL, NULL, NULL,
        _thiscall_application_mark_level_to_load,
         NULL,
        _thiscall_application_load_level,
        _thiscall_application_read_level,
#endif
};


/*
* Module:                 Blade.exe
* Entry point:            0x005B9B60
*/

application_t* create_application(void *module, int nCmdShow, char *cmdLine)
{
        application_t *new_application;

        NEW_APPLICATION(new_application, module, nCmdShow, cmdLine)

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

application_t* get_application()
{
        return gbl_application;
}


/*
* Module:                 Blade.exe
* Entry point:            0x005B9BC1
*/

application_t* application_init(
        application_t *self, void *module, int nCmdShow, char *cmdLine
) {
        application_init2(self, module, nCmdShow, cmdLine, NULL);
        ((application_raw_t *)self)->methods = &application_methods;
        return self;
}
