
#include <bld_system.h>
#include <stdio.h>
#include "application.h"
#include "game_state.h"
#include "sound_device.h"
#include "net_data.h"


#ifdef __cplusplus

#include <bld_abstract_net.h>

#else

typedef net_data_t bld_abstract_net;  

#endif



#ifdef BLD_EXT_FUNCS

#       define EXTERN
#       define NULL_INIT = NULL

#else

#       define EXTERN extern
#       define NULL_INIT

#endif



/*msvcrt functions */
EXTERN FILE* (*msvcrt_fopen)(const char *, const char *) NULL_INIT;
EXTERN int (*msvcrt_fclose)(FILE*) NULL_INIT;

#ifdef __BORLANDC__

#define fopen msvcrt_fopen
#define fclose msvcrt_fclose

#endif


#ifdef __cplusplus
extern "C" {
#endif

EXTERN HMODULE blade NULL_INIT;
EXTERN void (*LoadNetModule)(char *) NULL_INIT;
EXTERN void (*Set007EA988To01)(void) NULL_INIT;
EXTERN void (*reset_client_map_name)(void) NULL_INIT;
EXTERN void (*OnEvent)(int a, int b) NULL_INIT;
EXTERN char *(*get_map_for_net_game)(char *map) NULL_INIT;
EXTERN void (__stdcall *_thiscall_BBlibc_name_set)(char *string) NULL_INIT;
EXTERN void (__stdcall *_thiscall_BBlibc_name_clear)(void) NULL_INIT;
EXTERN void (__stdcall *_thiscall_BBlibc_name_copy)(BBLibc_name_t *name) NULL_INIT;
EXTERN void (__stdcall *_thiscall_BBlibc_name_string)(void) NULL_INIT;
EXTERN void (__stdcall *_thiscall_BBlibc_name_is_equal_string)(void) NULL_INIT;
EXTERN void (__stdcall *_thiscall_BBLibc_named_object_id)(void) NULL_INIT;
EXTERN char * (*BBlibc_format_string)(const char *format, ...) NULL_INIT;
EXTERN void (__stdcall *_thiscall_application_set_mode)(void) NULL_INIT;
EXTERN void (__stdcall *_thiscall_application_init2)(void) NULL_INIT;
EXTERN void (__stdcall *_thiscall_application_prepare_level)(void) NULL_INIT;
EXTERN void (__stdcall *_thiscall_application_process_event)(void) NULL_INIT;
EXTERN void (__stdcall *_thiscall_application_load_world)(void) NULL_INIT;
EXTERN void (*message_manager_print)(void *message_manager, char *message) NULL_INIT;
EXTERN void * (*bld_new)(size_t size) NULL_INIT;
EXTERN void (__stdcall *_thiscall_camera_init)(void) NULL_INIT;
EXTERN void (__stdcall *_thiscall_00439F5D)(void) NULL_INIT;
EXTERN void (__stdcall *_thiscall_camera_004EB1AA)(void) NULL_INIT;
EXTERN void (__stdcall *_thiscall_0040AD82)(void) NULL_INIT;
EXTERN void (__stdcall *_thiscall_0040ADA8)(void) NULL_INIT;
EXTERN B_IDataFile * (*_cdecl_read_points)(B_IDataFile *file, array_t *points) NULL_INIT;
EXTERN B_IDataFile * (*_cdecl_read_point)(B_IDataFile *file, point_t *point) NULL_INIT;
EXTERN B_IDataFile * (*_cdecl_read_sectors)(B_IDataFile *file, array_t *sectors) NULL_INIT;
EXTERN B_IDataFile * (*_cdecl_read_light)(B_IDataFile *file) NULL_INIT;
EXTERN void (*_thiscall_00451A21)(array_t sectors, int a, int b) NULL_INIT;

EXTERN sound_t **sound_device_ptr NULL_INIT;
EXTERN void **msg_manager_ptr NULL_INIT;
EXTERN char *client_map_name NULL_INIT;
EXTERN char *net_game_name NULL_INIT;
EXTERN int *net_max_players_ptr NULL_INIT;
EXTERN bld_abstract_net **net_data_ptr NULL_INIT;
#ifdef __BORLANDC__
        EXTERN bld_abstract_net *net NULL_INIT;
#endif
EXTERN application_t **application_ptr NULL_INIT;
EXTERN application_methods_t *application_methods_ptr NULL_INIT;
EXTERN game_state_t *game_state_ptr NULL_INIT;
EXTERN array_t *world_points_ptr NULL_INIT;
EXTERN void **var005E24DC NULL_INIT;
EXTERN void **var005E24F4 NULL_INIT;

#ifdef __cplusplus
}
#endif

#define sound_device (*sound_device_ptr)
#define message_manager (*msg_manager_ptr)
#define net_max_players (*net_max_players_ptr)
#define net_data (*net_data_ptr)
#ifdef _MSC_VER
        #define net (*net_data_ptr)
#endif
#define application (*application_ptr)
#define game_state (*game_state_ptr)
#define world_points (*world_points_ptr)


#ifdef __cplusplus

__inline B_IDataFile& operator >>(B_IDataFile& file, point_t *point)
{
        return *_cdecl_read_point(&file, point);
}

#endif


#define CALL_THISCALL_VOID_0(self, funcPtr)\
{\
        void *fnPtr = funcPtr;\
        void *selfPtr = self;\
        _asm { mov ecx, selfPtr }\
        _asm { call fnPtr }\
}

#define CALL_THISCALL_VOID_1(self, funcPtr, arg1)\
{\
        void *fnPtr = funcPtr;\
        void *selfPtr = self;\
        void *arg = arg1;\
        _asm { push arg }\
        _asm { mov ecx, selfPtr }\
        _asm { call fnPtr }\
}

#define CALL_THISCALL_VOID_3(self, funcPtr, arg1, arg2, arg3)\
{\
        void *fnPtr = funcPtr;\
        void *selfPtr = self;\
        void *arg01 = (void *)arg1;\
        void *arg02 = (void *)arg2;\
        void *arg03 = (void *)arg3;\
        _asm { push arg03 }\
        _asm { push arg02 }\
        _asm { push arg01 }\
        _asm { mov ecx, selfPtr }\
        _asm { call fnPtr }\
}


#ifndef BLD_EXT_FUNCS
extern void _thiscall_application_mark_level_to_load(char *map);
extern void _thiscall_application_load_level(char *map);
extern void _thiscall_application_read_level(char *file_name);
extern void _thiscall_application_wait_for_event(void);
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern void _impl_application_mark_level_to_load(application_t *self, char *map);
extern void _impl_application_load_level(application_t *self, char *map);
extern void _impl_application_read_level(application_t *self, const char *file_name);
extern void _impl_application_wait_for_event(application_t *self);

extern void create_bcb_wrappers(void);

#ifdef __cplusplus
}
#endif


#define NEW_OBJECT2(result, class, init_func, arg1, arg2)\
{\
        class *new_memory;\
        new_memory = (class *)bld_new(sizeof(class));\
        if (new_memory) {\
                result = init_func(new_memory, arg1, arg2);\
        } else {\
                result = NULL;\
        }\
}

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

#define NEW_CAMERA(result, unknown, name)\
NEW_OBJECT2(result, camera_t, camera_init, unknown, name)


#define NUM_3F266666 0.65f


