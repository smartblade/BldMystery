#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <AnalyticGeometry/Vector.h>


TEST(VectorTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_Vector), 0x18);
}

TEST(VectorTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Vector, x, 0x000);
    EXPECT_OFFSET_EQ(B_Vector, y, 0x008);
    EXPECT_OFFSET_EQ(B_Vector, z, 0x010);
}
