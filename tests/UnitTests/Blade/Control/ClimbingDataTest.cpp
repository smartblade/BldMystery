#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Control/Climbing.h>


TEST(ClimbingDataTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ClimbingData), 0x44);
}

TEST(ClimbingDataTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ClimbingData, leftPos, 0x00C);
    EXPECT_OFFSET_EQ(B_ClimbingData, rightPos, 0x024);
    EXPECT_OFFSET_EQ(B_ClimbingData, height, 0x03C);
}
