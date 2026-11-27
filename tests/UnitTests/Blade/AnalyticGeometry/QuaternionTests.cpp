#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <AnalyticGeometry/Quaternion.h>


TEST(QuaternionTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_Quaternion), 0x10);
}

TEST(QuaternionTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Quaternion, w, 0x000);
    EXPECT_OFFSET_EQ(B_Quaternion, x, 0x004);
    EXPECT_OFFSET_EQ(B_Quaternion, y, 0x008);
    EXPECT_OFFSET_EQ(B_Quaternion, z, 0x00C);
}
