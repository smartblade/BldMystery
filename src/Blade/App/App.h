
#ifndef APPLICATION_H

#define APPLICATION_H


#include <bld_python.h>
#include "BBLibc.h"
#include <Entities/Entity.h>
#include "Clock.h"
#include <array.h>
#include <AnalyticGeometry/Location.h>
#include "StringValue.h"


class B_CameraEntity;
class B_InputActions;
class B_InputDevice;
class B_PersonStatus;
class B_Widget;

class B_AfterFrameFunc : public B_NamedObj
{
public:
    void Call(float time);

    PyObject *func;
    PyObject *param;
    int removed;
};

class B_App
{
public:
    B_App(char *cmdLine);
    virtual void ReadArguments(const char *args);
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
    virtual void CloseLevel(const char *statement, const char *newMap);
    virtual void LoadLevel(const char *map);
    virtual void ReadLevel(const char *file_name);
    virtual void StoreCombustionParticleNames();
    virtual void ReassignCombustionData();
    virtual void ClearLevel(int flag);
    virtual void SetPyInteractiveString(const char *str);
    virtual const char *Input(const char *text) = 0;
    virtual void CallCdCb(int arg);
    virtual void ExitWithError(char *title, char* message) = 0;
    virtual void PrintWarning(const char *Title, const char *Message) = 0;
    virtual size_t GetWindow() = 0;
    virtual size_t GetModule() = 0;
    virtual int SetDirMap(const char *map) = 0;
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
    double GetTime();
    void StopTime();
    void RestartTime();
    void SetTimeSpeed(double speed);
    void SaveScreenShot(const char *filename, int width, int height);
    void TakeSnapShot();
    double GetTimeSpeed();
    B_PersonStatus *GetPlayerStatus1();
    B_PersonStatus *GetPlayerStatus2();
    B_InputDevice *GetAttachedDevice(const char *device);
    B_InputActions *GetInputActions();
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
    int SetBloodLevel(int bloodLevel);
    int GetBloodLevel();
    int SetMutilationLevel(int mutilationLevel);
    int GetMutilationLevel();
    int SetStringValue(const char *variable, const char *value);
    const char *GetStringValue(const char *variable);
    int DeleteStringValue(const char *variable);
    void DisplayStats();

    bool invertMouse;
    double xMouseSens;
    double yMouseSens;
    char unknownFields18[4];
    bool b001C;
    bool b001D;
    int listenerMode;
    char unknownFields1000[8];
    B_Clock *clock1;
    B_Clock *clock2;
    PyObject *CDCallback;
    B_PtrArray<B_Name> arguments;
    B_MessageChannel *console;
    B_Widget *rootWidget;
    void *unknown058;
    void *unknown05C;
    B_Name lastPlayerCType;
    B_Entity *player1;
    B_Entity *client;
    B_PersonStatus *playerStatus1;
    B_PersonStatus *playerStatus2;
    B_CameraEntity *camera;
    location_t location;
    float unknown1AC;
    float unknownPtrForCamera;
    int bloodLevel;
    int mutilationLevel;
    float timeByFrame[256];
    unsigned int frameIndex;
    float FPS20;
    float FPS5;
    float time;
    float lastFrameTimeDelta;
    bool b05D0;
    bool b05D1;
    bool mouseAcquired;
    bool isActive;
    bool b05D4;
    bool cls;
    byte currentStatsIndex;
    float saveToBmp;
    int numSavedBMPs;
    int numFrames;
    char unknownFields5E4[4];
    const char *commandLine;
    B_Name mode;
    char *mapToLoad;
    char *pyStatement;
    char *newMap;
    char *pyInteractiveString;
    bool needClearLevel;
    bool b0605;
    bool noSound;
    bool showConsole;
    B_Name mapName;
    B_Name rasterName;
    B_Name soundDeviceId;
    int drawShadows;
    int autoEngageCombat;
    double aecGap;
    PyObject *menuTgapFunc;
    int isInputActive;
    B_PtrArray<B_AfterFrameFunc> afterFrameFuncs;
    B_PtrArray<B_StringValue> values;
    char screenShotFileName[256];
    int screenShotWidth;
    int screenShotHeight;
};

#endif /* APPLICATION_H */

