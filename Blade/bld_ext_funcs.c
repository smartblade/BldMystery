
#define BLD_EXT_FUNCS
#include "bld_ext_funcs.h"

#define CALL_THISCALL_FUNC_0(class, funcPtr, func_name)\
void func_name(class *self) {\
        _asm { mov ecx, self }\
        _asm { call funcPtr }\
}

#define CALL_THISCALL_FUNC_1(class, funcPtr, func_name)\
void func_name(class *self, void *arg1) {\
        _asm { push arg1 }\
        _asm { mov ecx, self }\
        _asm { call funcPtr }\
}

#define CALL_THISCALL_FUNC_2(class, funcPtr, func_name)\
void func_name(class *self, void *arg1, void *arg2) {\
        _asm { push arg2 }\
        _asm { push arg1 }\
        _asm { mov ecx, self }\
        _asm { call funcPtr }\
}

#define CALL_THISCALL_FUNC_4(class, funcPtr, func_name)\
void func_name(class *self, void *arg1, void *arg2, void *arg3, void *arg4) {\
        _asm { push arg4 }\
        _asm { push arg3 }\
        _asm { push arg2 }\
        _asm { push arg1 }\
        _asm { mov ecx, self }\
        _asm { call funcPtr }\
}

#define DEFINE_THISCALL_FUNC_0(class, funcPtr, func_name)\
void func_name() {\
        class *self;\
        _asm { mov self, ecx}\
        funcPtr(self);\
}

#define DEFINE_THISCALL_FUNC_1(class, funcPtr, func_name)\
void func_name(void *arg1) {\
        class *self;\
        _asm { mov self, ecx}\
        funcPtr(self, arg1);\
}

CALL_THISCALL_FUNC_1(application_t, _thiscall_application_set_mode, application_set_mode)
CALL_THISCALL_FUNC_4(application_t, _thiscall_application_init2, application_init2)
CALL_THISCALL_FUNC_0(application_t, _thiscall_application_prepare_level, application_prepare_level)
CALL_THISCALL_FUNC_0(application_t, _thiscall_application_process_event, application_process_event)
#ifdef __BORLANDC__
        CALL_THISCALL_FUNC_1(application_t, _thiscall_application_load_world, application_load_world)
#endif
#ifdef _MSC_VER
        DEFINE_THISCALL_FUNC_1(application_t, _impl_application_mark_level_to_load, _thiscall_application_mark_level_to_load)
        DEFINE_THISCALL_FUNC_1(application_t, _impl_application_load_level, _thiscall_application_load_level)
        DEFINE_THISCALL_FUNC_1(application_t, _impl_application_read_level, _thiscall_application_read_level)
        DEFINE_THISCALL_FUNC_0(application_t, _impl_application_wait_for_event, _thiscall_application_wait_for_event)
#endif

CALL_THISCALL_FUNC_2(camera_t, _thiscall_camera_init, camera_init)


