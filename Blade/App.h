
#ifndef APPLICATION_H

#define APPLICATION_H


#include <bld_python.h>
#include "BBLibc.h"
#include "entity.h"
#include "game_clock.h"
#include <array.h>
#include "Location.h"
#include "StringValue.h"


class B_CameraEntity;

class B_App
{
public:
    virtual void ReadArguments(const char *arguments);
    virtual void StringSplit(
        const char *str, const char *sep, B_PtrArray<B_Name> *tokens);
    virtual bool InitPythonPath();
    virtual void ProcessMessage() = 0;
    virtual void *unknown_method010(void *);
    virtual ~B_App();
    virtual bool Start();
    virtual bool ProcessEvents();
    virtual void End();
    virtual const char *GetInputMode(const char *device);
    virtual int SetInputMode(const char *device, const char *mode);
    virtual int Quit();
    virtual void MarkLevelToLoad(const char *map);
    virtual void CloseLevel(const char *statement, const char *auxText);
    virtual void LoadLevel(const char *map);
    virtual void ReadLevel(const char *file_name);
    virtual void unknown_method040();
    virtual int ReassignCombustionData();
    virtual void ClearLevel(int flag);
    virtual void SetPyInteractiveString(const char *str);
    virtual const char *Input(const char *text) = 0;
    virtual void CallCdCb(int arg);
    virtual void ExitWithError(char *title, char* message) = 0;
    virtual void PrintWarning(const char *, const char *) = 0;
    virtual int GetWindow() = 0;
    virtual int GetModule() = 0;
    virtual int SetCurrentMap(const char *map) = 0;
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
    void TakeSnapShot();
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
    int SetAutoGenTexture(const char *textureName, int textureEffect);
    int DeactivateInput();
    int ActivateInput();
    bool OutSound(int soundId, double x, double y, double z, int unknown);
    int CDSetCallBack(PyObject *func);
    void SetAfterFrameFunc(const char *name, PyObject *function);
    PyObject *GetAfterFrameFunc(const char *name);
    const char *GetAfterFrameFuncName(int index);
    int GetnAfterFrameFuncs();
    void SetMenuTgapFunc(PyObject *func);
    PyObject *GetMenuTgapFunc();
    int RemoveAfterFrameFunc(const char *name);
    int SetBloodLevel(int blood_level);
    int GetBloodLevel();
    int SetMutilationLevel(int mutilation_level);
    int GetMutilationLevel();
    int SetStringValue(const char *variable, const char *value);
    const char *GetStringValue(const char *variable);
    int DeleteStringValue(const char *variable);

    char unknownFields1[24];
    boolean bUnknown01C;
    int listenerMode;
    char unknownFields1000[8];
    game_clock_t *clock1;
    game_clock_t *clock2;
    PyObject *CDCallback;
    B_PtrArray<B_Name> arguments;
    void *console;
    long int rootWidget;
    char unknownFields58[8];
    B_Name lastPlayerCType;
    B_PersonEntity *player1;
    B_Entity *client;
    void *unknownPtr070;
    void *unknownPtr074;
    B_CameraEntity *camera;
    location_t location;
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
    char unknownFields10[7];
    bool showConsole;
    B_Name mapName;
    B_Name rasterName;
    B_Name soundDeviceId;
    int drawShadows;
    int autoEngageCombat;
    double aecGap;
    char unknownFields630[8];
    B_PtrArray<B_NamedObj> unknownArr0638;
    B_PtrArray<B_StringValue> values;
    char unknownFields668[264];
};

#endif /* APPLICATION_H */

