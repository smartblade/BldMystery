#define BBLIBC_LIB_EXPORT
#include "RDataLight.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10040CB0
* VC++ mangling:          ??0B_RDataLight@@QAE@XZ
*/
#ifndef BLD_NATIVE
B_RDataLight::B_RDataLight()
{

}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10040CBE
* VC++ mangling:          ??0B_RDataLight@@QAE@MMMM@Z
*/
#ifndef BLD_NATIVE
B_RDataLight::B_RDataLight(float a, float b, float c, float d)
{

}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10040CE6
* VC++ mangling:          ?Interp@B_RDataLight@@QAEXNAAV1@N0@Z
*/
#ifndef BLD_NATIVE
void B_RDataLight::Interp(double t, B_RDataLight& start, double u, B_RDataLight& end)
{

}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10007EF0
* VC++ mangling:          ??4B_RDataLight@@QAEAAV0@ABV0@@Z
*/
#ifndef BLD_NATIVE
B_RDataLight& B_RDataLight::operator=(const B_RDataLight& other)
{
    return *this;
}
#endif
