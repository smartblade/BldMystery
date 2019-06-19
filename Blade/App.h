
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
        virtual void ReadArguments(const char *arguments);
        virtual void StringSplit(
                const char *str, const char *sep, array_t<B_Name*> *tokens);
        virtual bool InitPythonPath();
        virtual void ProcessMessage();
        virtual void *unknown_method010(void *);
        virtual ~B_App();
        virtual bool Start();
        virtual void ProcessEvents();
        virtual void End();
        virtual void *unknown_method024();
        virtual void *unknown_method028();
        virtual int Quit();
        virtual void MarkLevelToLoad(const char *map);
        virtual void CloseLevel(const char *statement, const char *auxText);
        virtual void LoadLevel(const char *map);
        virtual void ReadLevel(const char *file_name);
        virtual void unknown_method040();
        virtual int ReassignCombustionData();
        virtual void ClearLevel(int flag);
        virtual void SetPyInteractiveString(const char *str);
        virtual const char *Input(const char *text);
        virtual void CallCdCb(int arg);
        virtual void ExitWithError(char *title, char* message);
        virtual void PrintWarning(const char *, const char *);
        virtual void *GetWindow();
        virtual void *GetModule();
        virtual int SetCurrentMap(const char *map);
        virtual bool InitWindow();
        virtual void *unknown_method070();
        virtual void *NewWindow();
        virtual void Mouse(bool acquireFlag);
        virtual LRESULT WindowProcedure(
                HWND hwnd, UINT uMsg, WPARAM wParam,  LPARAM lParam);
        int LoadWorld(const char *file_name);
        bool RunPythonFile(const char *file_name);
        int SetAppMode(const B_Name &mode);
        const B_Name &GetAppMode();
        void BeginLoadGame();
        void DoneLoadGame();
        const char *GetCmdLine();
        void PrepareLevel();
        bool BindPred(const char *key, const char *pred);
        int SetListenerMode(int mode, const B_Vector &v);
        int SetTime(double time);
        int GoToTime(double time);
        void StopTime();
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
        bool UnBindPred(const char *key, const char *pred);
        void UnBindAll();

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
        B_Entity *client;
        char unknownFields100[8];
        B_CameraEntity *camera;
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
        char *pyStatement;
        char *auxText;
        char unknownFields10[8];
        B_Name mapName;
        char unknownFields2[424];
        void *window;
        void *module;
        char unknownFields3[16];
};

class B_WinApp : public B_App
{
public:
    virtual void ProcessEvents();
    virtual void LoadLevel(const char *map);
    B_WinApp(void *module, int nCmdShow, char *cmdLine, void *unknown);
};

class B_BladeApp : public B_WinApp
{
public:
    B_BladeApp(void *module, int nCmdShow, char *cmdLine);
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

