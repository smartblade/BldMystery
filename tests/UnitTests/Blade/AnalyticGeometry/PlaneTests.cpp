#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <AnalyticGeometry/Plane.h>


TEST(PlaneTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_Plane), 0x24);
}

TEST(PlaneTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Plane, normal, 0x004);
    EXPECT_OFFSET_EQ(B_Plane, p, 0x01C);
}
