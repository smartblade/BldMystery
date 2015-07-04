
#define BLD_EXT_FUNCS
#include "application.h"

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

DEFINE_METHOD_OF_CLASS_1(application_t, destroy, application_destroy)
DEFINE_METHOD_OF_CLASS_0(application_t, start, application_start)
DEFINE_METHOD_OF_CLASS_0(application_t, end, application_end)
DEFINE_METHOD_OF_CLASS_0(application_t, wait_for_event, application_wait_for_event)

