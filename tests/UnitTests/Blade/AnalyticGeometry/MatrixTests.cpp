#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <AnalyticGeometry/Matrix.h>


TEST(MatrixTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_Matrix), 0x80);
}

TEST(MatrixTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Matrix, m, 0x000);
}
