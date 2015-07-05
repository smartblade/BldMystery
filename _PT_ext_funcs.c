
#define BLD_EXT_FUNCS
#include "application.h"
#include "BBLibc.h"
#include "bld_ext_funcs.h"

#define DEFINE_METHOD_OF_CLASS_0(class, method, func_name)\
void func_name(class *self) {\
        void *funcPtr = self->methods->method;\
        _asm { mov ecx, self }\
        _asm { call funcPtr }\
}

#define DEFINE_METHOD_OF_CLASS_1(class, method, func_name)\
void func_name(class *self, void *arg1) {\
        void *funcPtr = self->methods->method;\
        _asm { push arg1 }\
        _asm { mov ecx, self }\
        _asm { call funcPtr }\
}

#define DEFINE_THISCALL_FUNC_0(class, funcPtr, func_name)\
void func_name(class *self) {\
        _asm { mov ecx, self }\
        _asm { call funcPtr }\
}

#define DEFINE_THISCALL_FUNC_1(class, funcPtr, func_name)\
void func_name(class *self, void *arg1) {\
        _asm { push arg1 }\
        _asm { mov ecx, self }\
        _asm { call funcPtr }\
}

DEFINE_METHOD_OF_CLASS_1(application_t, destroy, application_destroy)
DEFINE_METHOD_OF_CLASS_0(application_t, start, application_start)
DEFINE_METHOD_OF_CLASS_0(application_t, end, application_end)
DEFINE_METHOD_OF_CLASS_0(application_t, wait_for_event, application_wait_for_event)
DEFINE_THISCALL_FUNC_1(application_t, _thiscall_application_load_level_script, application_load_level_script)

DEFINE_THISCALL_FUNC_1(BBLibc_name_t, _thiscall_BBlibc_name_set, BBlibc_name_set)
DEFINE_THISCALL_FUNC_0(BBLibc_name_t, _thiscall_BBlibc_name_clear, BBlibc_name_clear)
DEFINE_THISCALL_FUNC_1(BBLibc_name_t, _thiscall_BBlibc_name_copy, BBlibc_name_copy)


