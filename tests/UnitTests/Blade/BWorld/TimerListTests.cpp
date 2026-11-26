#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/BWorld.h>


TEST(TimerListTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_TimerList), 0x34);
}

TEST(TimerListTests, Fields)
{
    EXPECT_OFFSET_EQ(B_TimerList, period, 0x024);
    EXPECT_OFFSET_EQ(B_TimerList, lastTime, 0x02C);
}
