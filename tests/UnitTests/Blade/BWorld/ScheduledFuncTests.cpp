#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/BWorld.h>


TEST(ScheduledFuncTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ScheduledFunc), 0x24);
}

TEST(ScheduledFuncTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ScheduledFunc, time, 0x00C);
    EXPECT_OFFSET_EQ(B_ScheduledFunc, func, 0x014);
    EXPECT_OFFSET_EQ(B_ScheduledFunc, args, 0x018);
    EXPECT_OFFSET_EQ(B_ScheduledFunc, nativeFunc, 0x01C);
    EXPECT_OFFSET_EQ(B_ScheduledFunc, nativeArg, 0x020);
}
