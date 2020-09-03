#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <NetMod/libnet.h>


TEST(NetCallbacksTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_NetCallbacks), 0x018);
}
