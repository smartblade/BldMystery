#ifndef CONSOLE_H

#define CONSOLE_H

#include <export.h>

class B_MessageChannel;

extern "C"
{

LIB_EXP B_MessageChannel *CreateConsole(
    HWND parentWindow, const char *name, int x, int y, int width, int height,
    int isChild);
LIB_EXP void DestroyConsole(void *console);

}

#endif /* CONSOLE_H */
