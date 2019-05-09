
#ifndef APPLICATION_H

#define APPLICATION_H


#include "BBLibc.h"
#include "entity.h"
#include "game_clock.h"
#include "array.h"


class application_t
{
public:
        virtual void read_arguments(const char *arguments);
        virtual void string_split(
                const char *str, const char *sep, array_t *tokens);
        virtual bool init_python_path();
        virtual void process_message();
        virtual void *unknown_method010(void *);
        virtual ~application_t();
        virtual bool start();
        virtual void process_events();
        virtual void end();
        virtual void *unknown_method024();
        virtual void *unknown_method028();
        virtual int quit();
        virtual void mark_level_to_load(const char *map);
        virtual void close_level(const char *command, const char *map);
        virtual void load_level(const char *map);
        virtual void read_level(const char *file_name);
        virtual void unknown_method040();
        virtual void *unknown_method044();
        virtual void clear_level(int flag);
        virtual void set_py_interactive_string(const char *str);
        virtual const char *input(const char *text);
        virtual void call_CD_cb(int arg);
        virtual void exit_with_error(char *title, char* message);
        virtual void print_warning(const char *, const char *);
        virtual void *get_window();
        virtual void *get_module();
        virtual int set_current_map(const char *map);
        virtual bool init_window();
        virtual void *unknown_method070();
        virtual void *create_window();
        virtual void mouse(bool acquireFlag);
        virtual LRESULT window_procedure(
                HWND hwnd, UINT uMsg, WPARAM wParam,  LPARAM lParam);

        char unknownFields1[24];
        boolean bUnknown01C;
        char unknownFields1000[12];
        game_clock_t *clock1;
        game_clock_t *clock2;
        void *unknown034;
        void *argsMethods;
        B_Name **arguments;
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
        B_Name mode;
        char *map_to_load;
        char unknownFields10[16];
        B_Name mapName;
        char unknownFields2[424];
        void *window;
        void *module;
        char unknownFields3[16];
};


#ifndef BLD_EXT_FUNCS

#ifdef __cplusplus
extern "C" {
#endif

extern void application_set_mode(application_t *self, B_Name *mode);
extern void application_load_level_script(application_t *self, const char *script);
extern application_t* application_init(
        application_t *self, void *module, int nCmdShow, char *cmdLine
);
extern application_t *application_init2(
        application_t *self, void *module, int nCmdShow, char *cmdLine,
        void *unknown
);
extern boolean application_run_python_file(application_t *self, const char *file_name);
extern int application_load_world(application_t *self, const char *file_name);
extern void application_prepare_level(application_t *self);
extern boolean application_process_event(application_t *self);


extern application_t *create_application(void *module, int nCmdShow, char *cmdLine);
extern application_t* get_application();

#ifdef __cplusplus
}
#endif

#endif

#endif /* APPLICATION_H */

