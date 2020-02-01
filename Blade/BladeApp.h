
#ifndef BLADE_APP_H

#define BLADE_APP_H

#include "App.h"

class B_BladeApp : public B_WinApp
{
public:
    B_BladeApp(void *module, int nCmdShow, char *cmdLine);
};

extern "C"
{

extern B_App *create_application(void *module, int nCmdShow, char *cmdLine);
extern B_App* get_application();

}

#endif /* BLADE_APP_H */
