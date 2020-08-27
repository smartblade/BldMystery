
#ifndef BLADE_APP_H

#define BLADE_APP_H

#include <App/Windows/WinApp.h>

class B_BladeApp : public B_WinApp
{
public:
    virtual bool Start();
    virtual bool ProcessEvents();
    virtual void End();
    B_BladeApp(HINSTANCE module, int nCmdShow, char *cmdLine);
};

extern "C"
{

extern B_App *CreateApplication(HINSTANCE module, int nCmdShow, char *cmdLine);
extern B_WinApp *GetWinApplication();
extern B_App* GetApplication();

}

#endif /* BLADE_APP_H */
