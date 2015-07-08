
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
EXTERN application_t* (*CreateApp)(HINSTANCE hInstance, int nCmdShow, LPSTR lpCmdLine) NULL_INIT;
EXTERN void (*Set007E7470To01)(void) NULL_INIT;
EXTERN void (*OnEvent)(int a, int b) NULL_INIT;
EXTERN char *(*Unknown005B09A6)(char *map) NULL_INIT;
EXTERN void __stdcall (*_thiscall_BBlibc_name_set)(char *string) NULL_INIT;
EXTERN void __stdcall (*_thiscall_BBlibc_name_clear)(void) NULL_INIT;
EXTERN void __stdcall (*_thiscall_BBlibc_name_copy)(BBLibc_name_t *name) NULL_INIT;
EXTERN char * (*BBlibc_format_string)(const char *format, ...) NULL_INIT;
EXTERN void __stdcall (*_thiscall_application_load_level_script)(char *script) NULL_INIT;
EXTERN void (*message_manager_print)(void *message_manager, char *message) NULL_INIT;

EXTERN int **var007C59B8 NULL_INIT;
EXTERN void **msg_manager_ptr NULL_INIT;
EXTERN net_data_t **net_data_ptr NULL_INIT;

#define message_manager (*msg_manager_ptr)
#define net_data (*net_data_ptr)


