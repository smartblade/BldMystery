
#ifndef B_MESSAGE_MANAGER_H

#define B_MESSAGE_MANAGER_H

#include <BBLibc/Name.h>
#include <BBLibc/MessageChannel.h>
#include <bld_system.h>

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

class LIB_EXP B_MessageManager
{
public:
    ~B_MessageManager();
    unsigned int OpenChannel(const B_Name& channel_name);
    unsigned int CloseChannel(const B_Name& channel_name);
    unsigned int Add(B_MessageChannel* channel);
    B_MessageChannel* DisconnectChannel(const B_Name& channel_name);
};

LIB_EXP B_MessageManager& operator <<(B_MessageManager& mout, const char* str);

LIB_EXP B_MessageManager mout;

#endif /* B_MESSAGE_MANAGER_H */
