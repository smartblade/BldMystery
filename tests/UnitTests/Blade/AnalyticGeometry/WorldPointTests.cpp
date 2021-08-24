#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <AnalyticGeometry/Polygon.h>


TEST(WorldPointTests, Fields)
{
    EXPECT_OFFSET_EQ(B_WorldPoint, v, 0x000);
    EXPECT_OFFSET_EQ(B_WorldPoint, unknown18, 0x018);
    EXPECT_OFFSET_EQ(B_WorldPoint, unknown1C, 0x01C);
}
