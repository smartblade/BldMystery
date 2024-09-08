
#ifndef B_NAMED_OBJ_H

#define B_NAMED_OBJ_H

#include "Name.h"
#include <bld_system.h>

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

class LIB_EXP B_NamedObj
{
public:
    virtual ~B_NamedObj();
    B_NamedObj();

    B_NamedObj(const B_Name& name);
    const B_Name& Id() const;
public:
    B_Name name;
};

#endif /* B_NAMED_OBJ_H */
