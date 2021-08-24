#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <AnalyticGeometry/Location.h>


TEST(LocationTests, SizeOf)
{
    EXPECT_EQ(sizeof(location_t), 0x130);
}

TEST(LocationTests, Fields)
{
    EXPECT_OFFSET_EQ(location_t, position, 0x000);
    EXPECT_OFFSET_EQ(location_t, rotationX, 0x018);
    EXPECT_OFFSET_EQ(location_t, rotationY, 0x020);
    EXPECT_OFFSET_EQ(location_t, rotationZ, 0x028);
    EXPECT_OFFSET_EQ(location_t, matrix0030, 0x030);
    EXPECT_OFFSET_EQ(location_t, matrix00B0, 0x0B0);
}
