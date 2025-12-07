#ifndef B_RDataLight_H
#define B_RDataLight_H


#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB


class LIB_EXP B_RDataLight
{
public:
    B_RDataLight();
    B_RDataLight(float, float, float, float);

    void Interp(double, B_RDataLight&, double, B_RDataLight&);

    B_RDataLight &operator=(const B_RDataLight&);

private:

};


class LIB_EXP B_RItem
{
public:
    B_RItem(unsigned long);

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10007F20
    * VC++ mangling:          ??4B_RItem@@QAEAAV0@ABV0@@Z
    */
#ifndef BLD_NATIVE
    B_RItem &operator =(const B_RItem &that)
    {
        return *this;
    }
#else
    B_RItem &operator =(const B_RItem &that);
#endif
};

#endif  // B_RDataLight_H
