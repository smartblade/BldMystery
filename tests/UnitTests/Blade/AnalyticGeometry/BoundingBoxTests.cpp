#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <AnalyticGeometry/BoundingBox.h>


TEST(BoundingBoxTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_BoundingBox), 0x30);
}

TEST(BoundingBoxTests, Fields)
{
    EXPECT_OFFSET_EQ(B_BoundingBox, minCoords, 0x000);
    EXPECT_OFFSET_EQ(B_BoundingBox, maxCoords, 0x018);
}
