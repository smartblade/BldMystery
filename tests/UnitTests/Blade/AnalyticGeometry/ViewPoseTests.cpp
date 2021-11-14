#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <AnalyticGeometry/ViewPose.h>


TEST(ViewPoseTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ViewPose), 0x130);
}

TEST(ViewPoseTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ViewPose, position, 0x000);
    EXPECT_OFFSET_EQ(B_ViewPose, rotationX, 0x018);
    EXPECT_OFFSET_EQ(B_ViewPose, rotationY, 0x020);
    EXPECT_OFFSET_EQ(B_ViewPose, rotationZ, 0x028);
    EXPECT_OFFSET_EQ(B_ViewPose, fromWorld, 0x030);
    EXPECT_OFFSET_EQ(B_ViewPose, toWorld, 0x0B0);
}
