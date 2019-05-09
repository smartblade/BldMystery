
#include <bld_system.h>


typedef struct {
        void *unknownFuncs10[2];
        void (*init_python_path)(void); /*0x00411B94*/
        void *unknownFuncs20[2];
        int  (*destroy)(int); /*0x005B8E00*/
        boolean (*start)(void);
        void (*wait_for_event)(void);/*0x005B8DD3*/
        void (*end)(void);
        void *unknownFuncs1[3];
        void (*mark_level_to_load)(char *);
        void *unknownFuncs2[1];
        void (*load_level)(char *);
        void (*read_level)(char *);
        void *unknownFuncs3[6];
        void (*exit_with_error)(char *, char *);/*0x00410A93*/
        void *unknownFuncs4[9];
} application_methods_t;

typedef struct {
        application_methods_t *methods;
} application_raw_t;

#ifdef __cplusplus

#include "application.h"
#include "game_state.h"
#include "sound_device.h"
#include <bld_abstract_net.h>

#else

typedef struct B_IDataFile B_IDataFile;
typedef struct array_t array_t;
typedef struct point_t point_t;
typedef application_raw_t application_t;
typedef struct camera_t camera_t;
typedef struct game_state_t game_state_t;
typedef struct net_data_t bld_abstract_net;
typedef int sound_t;

#endif



#ifdef BLD_EXT_FUNCS

#       define EXTERN
#       define NULL_INIT = NULL

#else

#       define EXTERN extern
#       define NULL_INIT

#endif


#ifdef __cplusplus
extern "C" {
#endif

EXTERN HMODULE blade NULL_INIT;
EXTERN void (*LoadNetModule)(char *) NULL_INIT;
EXTERN void (*Set007EA988To01)(void) NULL_INIT;
EXTERN void (*reset_client_map_name)(void) NULL_INIT;
EXTERN void (*OnEvent)(int a, int b) NULL_INIT;
EXTERN char *(*get_map_for_net_game)(const char *map) NULL_INIT;
EXTERN void (__stdcall *_thiscall_application_set_mode)(void) NULL_INIT;
EXTERN void (__stdcall *_thiscall_application_init2)(void) NULL_INIT;
EXTERN void (__stdcall *_thiscall_application_prepare_level)(void) NULL_INIT;
EXTERN void (__stdcall *_thiscall_application_process_event)(void) NULL_INIT;
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
EXTERN void (*BldStartup)(void *) NULL_INIT;
EXTERN int (__stdcall *_stdcall_BladeWinMain)(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow) NULL_INIT;

EXTERN sound_t **sound_device_ptr NULL_INIT;
EXTERN char *client_map_name NULL_INIT;
EXTERN char *net_game_name NULL_INIT;
EXTERN int *net_max_players_ptr NULL_INIT;
EXTERN bld_abstract_net **net_data_ptr NULL_INIT;
#ifdef __BORLANDC__
        EXTERN bld_abstract_net *gbl_net NULL_INIT;
#endif
EXTERN application_t **application_ptr NULL_INIT;
EXTERN application_methods_t *application_methods_ptr NULL_INIT;
EXTERN void (**init_start)(void) NULL_INIT;
EXTERN void (**init_end)(void) NULL_INIT;
EXTERN game_state_t *game_state_ptr NULL_INIT;
EXTERN array_t *world_points_ptr NULL_INIT;
EXTERN void **var005E24DC NULL_INIT;
EXTERN void **var005E24F4 NULL_INIT;
EXTERN array_t *anims_ptr NULL_INIT;
EXTERN void **__onexitbegin_ptr NULL_INIT;

#ifdef __cplusplus
}
#endif

#define gbl_sound_device (*sound_device_ptr)
#define gbl_net_max_players (*net_max_players_ptr)
#define gbl_net_data (*net_data_ptr)
#ifdef _MSC_VER
        #define gbl_net (*net_data_ptr)
#endif
#define gbl_application (*application_ptr)
#define gbl_game_state (*game_state_ptr)
#define gbl_world_points (*world_points_ptr)
#define gbl_anims (*anims_ptr)


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


#ifdef __cplusplus
extern "C" {
#endif

extern void _thiscall_application_mark_level_to_load(char *map);
extern void _thiscall_application_load_level(char *map);
extern void _thiscall_application_read_level(char *file_name);
extern void _thiscall_application_wait_for_event(void);

int BladeWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

extern void create_bcb_wrappers(void);

#ifdef __cplusplus
}
#endif


#define NEW_OBJECT2(result, class, init_func, arg1, arg2)\
{\
        class *new_memory;\
        new_memory = (class *)bld_new(sizeof(class));\
        if (new_memory) {\
                result = new_memory->init_func(arg1, arg2);\
        } else {\
                result = NULL;\
        }\
}

#define NEW_CAMERA(result, unknown, name)\
NEW_OBJECT2(result, camera_t, init, unknown, name)


#define NUM_3F266666 0.65f


