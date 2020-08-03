
#ifndef BINPUTC_H

#define BINPUTC_H

#include <export.h>

class LIB_EXP B_InputDevice
{
};

class LIB_EXP B_WinMouse : public B_InputDevice
{
public:
    B_WinMouse(bool exclusive, HMODULE module, HWND window);
    bool Acquire();
    void UnAcquire();

    char unknown_fields[328];
    float fUnknown0148;
};

class LIB_EXP B_DInputKeyb : public B_InputDevice
{
public:
    B_DInputKeyb(HMODULE module, HWND window);
    bool Acquire();
    void UnAcquire();
private:
    char unknown_fields[4168];
};

class LIB_EXP B_InputManager
{
public:
    B_InputManager();
    void AddDevice(B_InputDevice *device);
    int AddInputActionsSet(const char *actionsSet);
    int SetInputActionsSet(const char *actionsSet);
    void ProcessInput(float time);
private:
    char unknown_fields[64];
};

LIB_EXP B_InputManager *InputManager;

#endif /* BINPUTC_H */
