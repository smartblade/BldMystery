#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BBLibc/RDataTriangle.h>


TEST(RDataTriangleTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_RDataTriangle), 0x1C);
}

TEST(RDataTriangleTests, Fields)
{
    EXPECT_OFFSET_EQ(B_RDataTriangle, type, 0x000);
    EXPECT_OFFSET_EQ(B_RDataTriangle, unknownField004, 0x004);
    EXPECT_OFFSET_EQ(B_RDataTriangle, vertices, 0x008);
    EXPECT_OFFSET_EQ(B_RDataTriangle, bmpHandle, 0x014);
    EXPECT_OFFSET_EQ(B_RDataTriangle, data, 0x018);
}
