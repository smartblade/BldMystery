#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "bld_misc_funcs.h"


TEST(ClimbStartPoseTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ClimbStartPose), 0x44);
}

TEST(ClimbStartPoseTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ClimbStartPose, position, 0x00C);
    EXPECT_OFFSET_EQ(B_ClimbStartPose, v, 0x024);
    EXPECT_OFFSET_EQ(B_ClimbStartPose, w, 0x03C);
}
