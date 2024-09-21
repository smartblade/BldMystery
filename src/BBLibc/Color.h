
#ifndef B_COLOR_H

#define B_COLOR_H

#include <bld_system.h>

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

class LIB_EXP B_Color
{
public:
    B_Color();
    B_Color(byte r, byte g, byte b);

    virtual void MakeCons();

    B_Color operator +(B_Color const& color) const;
    B_Color operator *(float coef) const;
    B_Color operator /(float f)const;
    B_Color& operator =(const B_Color& that);

    byte r, g, b;
};

#endif /* B_COLOR_H */
