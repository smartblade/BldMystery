
#include <windows.h>

#ifdef BLD_EXT_FUNCS

#       define EXTERN
#       define NULL_INIT = NULL

#else

#       define EXTERN extern
#       define NULL_INIT

#endif;

EXTERN HMODULE blade NULL_INIT;
EXTERN void (*LoadNetModule)(char *) NULL_INIT;
EXTERN void (*Set007E7470To01)(void) NULL_INIT;
EXTERN void (*OnEvent)(int a, int b) NULL_INIT;
EXTERN char *(*get_map_for_net_game)(char *map) NULL_INIT;
EXTERN void __stdcall (*_thiscall_BBlibc_name_set)(char *string) NULL_INIT;
EXTERN void __stdcall (*_thiscall_BBlibc_name_clear)(void) NULL_INIT;
EXTERN void __stdcall (*_thiscall_BBlibc_name_copy)(BBLibc_name_t *name) NULL_INIT;
EXTERN char * (*BBlibc_format_string)(const char *format, ...) NULL_INIT;
EXTERN void __stdcall (*_thiscall_application_load_level_script)(char *script) NULL_INIT;
EXTERN void __stdcall (*_thiscall_application_init2)(void) NULL_INIT;
EXTERN void (*message_manager_print)(void *message_manager, char *message) NULL_INIT;
EXTERN void * (*bld_new)(size_t size) NULL_INIT;

EXTERN int **var007C59B8 NULL_INIT;
EXTERN void **msg_manager_ptr NULL_INIT;
EXTERN net_data_t **net_data_ptr NULL_INIT;
EXTERN application_t **application_ptr NULL_INIT;
EXTERN application_methods_t *application_methods_ptr NULL_INIT;

#define message_manager (*msg_manager_ptr)
#define net_data (*net_data_ptr)
#define application (*application_ptr)


#ifndef BLD_EXT_FUNCS
extern void _thiscall_application_load_level(char *map);
#endif

extern void _impl_application_load_level(application_t *self, char *map);


#define NEW_OBJECT3(result, class, init_func, arg1, arg2, arg3)\
{\
        class *new_memory;\
        new_memory = (class *)bld_new(sizeof(class));\
        if (new_memory) {\
                result = init_func(new_memory, arg1, arg2, arg3);\
        } else {\
                result = NULL;\
        }\
}

#define NEW_APPLICATION(result, module, nCmdShow, cmdLine)\
NEW_OBJECT3(result, application_t, application_init, module, nCmdShow, cmdLine)\
{\
        void **src_ptr, **dst_ptr;\
        int i;\
        src_ptr = (void **)application_methods_ptr;\
        dst_ptr = (void **)result->methods;\
        for( i = 0; i < sizeof(application_methods_t)/sizeof(void *); i++) {\
                if (*dst_ptr == NULL)\
                        *dst_ptr = *src_ptr;\
                src_ptr++;\
                dst_ptr++;\
        }\
}\


