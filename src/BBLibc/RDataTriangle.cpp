#define BBLIBC_LIB_EXPORT
#include "RDataTriangle.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x10040F51
* VC++ mangling:          ??0B_RDataTriangle@@QAE@XZ
*/
#ifndef BLD_NATIVE
B_RDataTriangle::B_RDataTriangle()
{

}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x10007F40
* VC++ mangling:          ??4B_RDataTriangle@@QAEAAV0@ABV0@@Z
*/
#ifndef BLD_NATIVE
B_RDataTriangle &B_RDataTriangle::operator=(const B_RDataTriangle &other)
{
    return *this;
}
#endif

