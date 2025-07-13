
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


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10002720
    * VC++ mangling:          ??4B_MessageManager@@QAEAAV0@ABV0@@Z
    */

    B_MessageManager &operator=(const B_MessageManager &that)
    {
        this->unknown00 = that.unknown00;
        return *this;
    }

    unsigned int Add(B_MessageChannel *channel);
    unsigned int OpenChannel(const B_Name &channel_name);
    unsigned int CloseChannel(const B_Name &channel_name);
    B_MessageChannel *DisconnectChannel(const B_Name &channel_name);

private:
    byte unknown00;
};

LIB_EXP B_MessageManager &operator <<(B_MessageManager &mout, const char *str);

extern LIB_EXP B_MessageManager mout;

#endif /* B_MESSAGE_MANAGER_H */
