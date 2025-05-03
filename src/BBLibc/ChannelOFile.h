#pragma once

#include <BBLibc/MessageChannel.h>


#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB


class B_ChannelOFile : public B_MessageChannel
{
};
