
#include <bld_system.h>
#include <bld_python.h>
#include "bld_ext_funcs.h"
#define BUILD_LIB
#include <blade_ext.h>


int LoadWorld(const char *file_name)
{
        int (*bld_proc)(const char *);
        bld_proc = (int (*)(const char *))GetProcAddress(blade, "LoadWorld");
        return bld_proc(file_name);
}

const char *GetWorldFileName(void)
{
        const char * (*bld_proc)(void);
        bld_proc = (const char * (*)(void))GetProcAddress(blade, "GetWorldFileName");
        return bld_proc();
}

