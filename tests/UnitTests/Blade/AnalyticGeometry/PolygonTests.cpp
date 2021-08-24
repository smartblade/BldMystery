#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <AnalyticGeometry/Polygon.h>


TEST(PolygonTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Polygon, numVertices, 0x004);
    EXPECT_OFFSET_EQ(B_Polygon, vertices, 0x008);
}
