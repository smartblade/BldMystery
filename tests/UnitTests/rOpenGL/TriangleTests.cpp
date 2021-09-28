#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <Raster/rOpenGL3/ROpenGLDeviceDLL.h>


TEST(TriangleTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Triangle, invEdge1, 0x000);
    EXPECT_OFFSET_EQ(B_Triangle, invEdge2, 0x004);
    EXPECT_OFFSET_EQ(B_Triangle, invEdge3, 0x008);
    EXPECT_OFFSET_EQ(B_Triangle, edge1, 0x00C);
    EXPECT_OFFSET_EQ(B_Triangle, edge2, 0x010);
    EXPECT_OFFSET_EQ(B_Triangle, edge3, 0x014);
}
