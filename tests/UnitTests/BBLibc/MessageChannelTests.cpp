#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <BBLibc/MessageChannel.h>


TEST(MessageChannelTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_MessageChannel), 0x0010);
}

TEST(MessageChannelTests, Fields)
{
    EXPECT_OFFSET_EQ(B_MessageChannel, unknown0Ch, 0x000C);
}
