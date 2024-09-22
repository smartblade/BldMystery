
#ifndef B_RESOURCE_H

#define B_RESOURCE_H

#include <bld_system.h>
#include "NamedObj.h"

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

class LIB_EXP B_Resource : public B_NamedObj
{
public:
    B_Resource();


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x100066E0
    * VC++ mangling:          ??0B_Resource@@QAE@ABV0@@Z
    */

    B_Resource(const B_Resource& that) : B_NamedObj(that)
    {
    }


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10006720
    * VC++ mangling:          ??4B_Resource@@QAEAAV0@ABV0@@Z
    */

    B_Resource& operator=(const B_Resource& that)
    {
        B_NamedObj::operator=(that);
        return *this;
    }

    virtual ~B_Resource();

    void* data;
};

#endif /* B_RESOURCE_H */
