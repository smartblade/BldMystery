
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
    void* data;
};

#endif /* B_RESOURCE_H */
