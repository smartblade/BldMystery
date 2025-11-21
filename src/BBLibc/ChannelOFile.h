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
};
