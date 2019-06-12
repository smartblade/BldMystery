
#ifndef APPLICATION_H

#define APPLICATION_H


#include <bld_python.h>
#include "BBLibc.h"
#include "entity.h"
#include "game_clock.h"
#include <array.h>
#include "Location.h"


class B_App
{
public:
        virtual void read_arguments(const char *arguments);
        virtual void string_split(
                const char *str, const char *sep, array_t<B_Name*> *tokens);
        virtual bool init_python_path();
        virtual void process_message();
        virtual void *unknown_method010(void *);
        virtual ~B_App();
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
        virtual int ReassignCombustionData();
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
        int load_world(const char *file_name);
        bool run_python_file(const char *file_name);
        int SetAppMode(const B_Name &mode);
        const B_Name &GetAppMode();
        void BeginLoadGame();
        void DoneLoadGame();
        const char *GetCmdLine();
        void prepare_level();
        bool bind_pred(const char *key, const char *pred);
        int set_listener_mode(int mode, const B_Vector &v);
        int set_time(double time);
        int go_to_time(double time);
        void stop_time();
        void RestartTime();
        void SetTimeSpeed(double speed);
        double GetTimeSpeed();
        void AddInputAction(const char *action_name, int npi);
        void RemoveInputAction(const char *action_name);
        int AssocKey(
            const char *action, const char *input_device, const char *key,
            int press
        );
        bool Bind(const char *key, PyObject *proc);
        bool UnBind(const char *key, PyObject *proc);
        void Bind2(
            const char *act, const char *subact1,
            const char *subact2, int unknown
        );
        double GetTimeActionHeld(const char *action);

        char unknownFields1[24];
        boolean bUnknown01C;
        int listenerMode;
        char unknownFields1000[8];
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
        location_t location;
        char unknownFields200[280];
        float unknown1AC;
        float unknownPtrForCamera;
        char unknownFields300[1036];
        float fUnknown5C0;
        char unknownFields400[4];
        float time;
        char unknownFields310[6];
        boolean no_sleep;
        char unknownFields320[20];
        const char *commandLine;
        B_Name mode;
        char *map_to_load;
        char unknownFields10[16];
        B_Name mapName;
        char unknownFields2[424];
        void *window;
        void *module;
        char unknownFields3[16];
};

class B_WinApp : public B_App
{
public:
    virtual void process_events();
    virtual void load_level(const char *map);
    B_WinApp(void *module, int nCmdShow, char *cmdLine, void *unknown);
};

class B_BladeApp : public B_WinApp
{
public:
    B_BladeApp(void *module, int nCmdShow, char *cmdLine);
    char unknownFields[0x7D0];
};

#ifdef __cplusplus
extern "C" {
#endif

extern B_App *create_application(void *module, int nCmdShow, char *cmdLine);
extern B_App* get_application();

#ifdef __cplusplus
}
#endif

#endif /* APPLICATION_H */

