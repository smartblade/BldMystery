#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BBLibc/RDataTriangle.h>


TEST(ModelTriangleDataTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ModelTriangleData), 0x1C);
}

TEST(ModelTriangleDataTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ModelTriangleData, bmpHandle, 0x000);
    EXPECT_OFFSET_EQ(B_ModelTriangleData, u, 0x004);
    EXPECT_OFFSET_EQ(B_ModelTriangleData, v, 0x010);
}
