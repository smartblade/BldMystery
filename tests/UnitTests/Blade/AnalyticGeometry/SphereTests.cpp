#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <AnalyticGeometry/BoundingBox.h>


TEST(SphereTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_Sphere), 0x20);
}

TEST(SphereTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Sphere, center, 0x000);
    EXPECT_OFFSET_EQ(B_Sphere, radius, 0x018);
}
