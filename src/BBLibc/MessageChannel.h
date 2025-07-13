
#ifndef B_MESSAGE_CHANNEL_H

#define B_MESSAGE_CHANNEL_H

#include <bld_system.h>
#include "NamedObj.h"


#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB


class LIB_EXP B_MessageChannel : public B_NamedObj
{
public:

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x100024C0
    * VC++ mangling:          ??0B_MessageChannel@@QAE@AAVB_Name@@@Z
    */

    B_MessageChannel(B_Name &name) : B_NamedObj(name)
    {
        unknown0Ch = 1;
    }

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10002550
    * VC++ mangling:          ??1B_MessageChannel@@UAE@XZ
    */

    virtual ~B_MessageChannel()
    {
    }

    virtual unsigned int Open();
    virtual unsigned int Close();
    virtual unsigned int Message(const char *message);

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10002580
    * VC++ mangling:          ??0B_MessageChannel@@QAE@ABV0@@Z
    */

    B_MessageChannel(const B_MessageChannel &that)
        : B_NamedObj(that), unknown0Ch(that.unknown0Ch)
    {
    }


    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x100025C0
    * VC++ mangling:          ??4B_MessageChannel@@QAEAAV0@ABV0@@Z
    */

    B_MessageChannel &operator=(const B_MessageChannel &that)
    {
        B_NamedObj::operator=(that);
        unknown0Ch = that.unknown0Ch;
        return *this;
    }
private:
    unsigned int unknown0Ch;
};

#endif /* B_MESSAGE_CHANNEL_H */
