
#ifndef BINPUTC_H

#define BINPUTC_H

#include <export.h>

class LIB_EXP B_InputDevice
{
};

class LIB_EXP B_WinMouse : public B_InputDevice
{
public:
    bool Acquire();
    void UnAcquire();
};

class LIB_EXP B_DInputKeyb : public B_InputDevice
{
public:
    bool Acquire();
    void UnAcquire();
};

#endif /* BINPUTC_H */
