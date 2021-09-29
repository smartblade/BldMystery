#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <Raster/rOpenGL3/ROpenGLDeviceDLL.h>


TEST(EdgeTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Edge, firstVertexIndex, 0x000);
    EXPECT_OFFSET_EQ(B_Edge, secondVertexIndex, 0x004);
    EXPECT_OFFSET_EQ(B_Edge, nextEdge, 0x008);
    EXPECT_OFFSET_EQ(B_Edge, sqrLen, 0x00C);
    EXPECT_OFFSET_EQ(B_Edge, light, 0x010);
}
