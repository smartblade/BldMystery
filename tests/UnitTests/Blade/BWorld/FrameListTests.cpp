#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/BWorld.h>


TEST(FrameListTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_FrameList), 0x2C);
}

TEST(FrameListTests, Fields)
{
    EXPECT_OFFSET_EQ(B_FrameList, period, 0x024);
    EXPECT_OFFSET_EQ(B_FrameList, lastFrame, 0x028);
}
