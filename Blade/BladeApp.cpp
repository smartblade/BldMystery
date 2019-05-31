
#include <bld_system.h>
#include "App.h"
#include "bld_misc_funcs.h"


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

B_App* create_application(void *module, int nCmdShow, char *cmdLine)
{
        B_App *new_application = (B_App *)new B_BladeApp(module, nCmdShow, cmdLine);
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

#ifdef BLD_NATIVE

B_BladeApp::B_BladeApp(void *module, int nCmdShow, char *cmdLine)
{
        ((B_WinApp *)this)->init(module, nCmdShow, cmdLine, NULL);
        ((application_raw_t *)this)->methods = &application_methods;
        {
            void **src_ptr, **dst_ptr;
            int i;
            src_ptr = (void **)application_methods_ptr;
            dst_ptr = (void **)((application_raw_t *)this)->methods;
            for( i = 0; i < sizeof(application_methods_t)/sizeof(void *); i++)
            {
                if (*dst_ptr == NULL)
                    *dst_ptr = *src_ptr;
                 src_ptr++;
                 dst_ptr++;
            }
        }
}

#endif
