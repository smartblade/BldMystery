#ifndef BUIXC_H

#define BUIXC_H

#include <export.h>

class LIB_EXP B_Widget
{
public:
    virtual void unknown000() = 0;
    virtual unsigned int SetSize(float w, float h);
    virtual void unknown008() = 0;
    virtual void unknown00C() = 0;
    virtual void Draw(int x, int y, float time);
};

#endif /* BUIXC_H */
