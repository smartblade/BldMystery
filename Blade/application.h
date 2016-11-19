
#ifndef APPLICATION_H

#define APPLICATION_H


#include "BBLibc.h"
#include "entity.h"
#include "game_clock.h"


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
        void *unknownFuncs3[7];
        void (*exit_with_error)(char *, char *);/*0x00410A93*/
        void *unknownFuncs4[9];
} application_methods_t;


typedef struct {
        application_methods_t *methods;
        char unknownFields1[24];
        boolean bUnknown01C;
        char unknownFields1000[12];
        game_clock_t *clock1;
        game_clock_t *clock2;
        void *unknown034;
        void *argsMethods;
        BBLibc_name_t **arguments;
        int numArguments;
        char unknownFields20[36];
        person_t *player1;
        entity_t *client;
        char unknownFields100[8];
        camera_t *camera;
        void *unknown7C;
        char unknownFields200[300];
        float unknown1AC;
        float unknownPtrForCamera;
        char unknownFields300[1036];
        float fUnknown5C0;
        char unknownFields400[4];
        void *unknown5C8;
        char unknownFields310[6];
        boolean no_sleep;
        char unknownFields320[24];
        BBLibc_name_t mode;
        char *map_to_load;
        char unknownFields10[16];
        BBLibc_name_t mapName;
        char unknownFields2[424];
        void *window;
        void *module;
        char unknownFields3[16];
} application_t;


#ifndef BLD_EXT_FUNCS

extern void application_init_python_path(application_t *self);
extern int application_destroy(application_t *self, int a);
extern boolean application_start(application_t *self);
extern void application_wait_for_event(application_t *self);
extern void application_end(application_t *self);
extern void application_exit_with_error(
        application_t *self, const char *title, const char *message
);
extern void application_set_mode(application_t *self, BBLibc_name_t *mode);
extern void application_load_level_script(application_t *self, const char *script);
extern application_t* application_init(
        application_t *self, void *module, int nCmdShow, char *cmdLine
);
extern application_t *application_init2(
        application_t *self, void *module, int nCmdShow, char *cmdLine,
        void *unknown
);
extern boolean application_run_python_file(application_t *self, const char *file_name);
extern void application_prepare_level(application_t *self);
extern boolean application_process_event(application_t *self);


extern application_t *create_application(void *module, int nCmdShow, char *cmdLine);

#endif

#endif /* APPLICATION_H */

