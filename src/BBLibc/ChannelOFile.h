#pragma once

#include <BBLibc/MessageChannel.h>


#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB


class B_ChannelOFile : public B_MessageChannel
{
    B_ChannelOFile(B_Name, const char *);
    virtual ~B_ChannelOFile();
    virtual unsigned int Open();
    virtual unsigned int Close();
    virtual unsigned int Message(const char *arg_1);

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10029A60
    * VC++ mangling:          ??0B_ChannelOFile@@QAE@ABV0@@Z
    */
#ifndef BLD_NATIVE
    B_ChannelOFile(const B_ChannelOFile &arg_1)
    {
    }
#else
    B_ChannelOFile(const B_ChannelOFile &arg_1);
#endif

    /*
    * Module:                 BBLibc.dll
    * Entry point:            0x10029AC0
    * VC++ mangling:          ??4B_ChannelOFile@@QAEAAV0@ABV0@@Z
    */
#ifndef BLD_NATIVE
    B_ChannelOFile &operator =(const B_ChannelOFile &arg_1)
    {
        return *this;
    }
#else
    B_ChannelOFile &operator =(const B_ChannelOFile &arg_1);
#endif
};
