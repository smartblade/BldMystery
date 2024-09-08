
#ifndef B_MESSAGE_CHANNEL_H

#define B_MESSAGE_CHANNEL_H

#include <bld_system.h>
#include "NamedObj.h"


#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB


class LIB_EXP B_MessageChannel : public B_NamedObj {
public:
    B_MessageChannel(B_Name* name);
    ~B_MessageChannel();
    virtual unsigned int Message(char const* message);
private:
    unsigned int unknown0Ch;
};

#endif /* B_MESSAGE_CHANNEL_H */
