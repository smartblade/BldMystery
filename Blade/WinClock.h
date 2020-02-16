

#ifndef B_WINCLOCK_H

#define B_WINCLOCK_H

#include "Clock.h"

class B_WinClock : public B_Clock
{
public:
    B_WinClock();
    virtual double GetSystemTime();
};

#endif /* B_WINCLOCK_H */
