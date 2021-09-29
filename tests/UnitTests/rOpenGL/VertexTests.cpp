#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <Raster/rOpenGL3/ROpenGLDeviceDLL.h>


TEST(VertexTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Vertex, pos.x, 0x000);
    EXPECT_OFFSET_EQ(B_Vertex, pos.y, 0x008);
    EXPECT_OFFSET_EQ(B_Vertex, pos.z, 0x010);
    EXPECT_OFFSET_EQ(B_Vertex, textureCoords, 0x018);
    EXPECT_OFFSET_EQ(B_Vertex, color, 0x020);
    EXPECT_OFFSET_EQ(B_Vertex, fUnknown02C, 0x02C);
    EXPECT_OFFSET_EQ(B_Vertex, fog, 0x030);
    EXPECT_OFFSET_EQ(B_Vertex, fUnknown034, 0x034);
    EXPECT_OFFSET_EQ(B_Vertex, fUnknown038, 0x038);
    EXPECT_OFFSET_EQ(B_Vertex, fUnknown03C, 0x03C);
    EXPECT_OFFSET_EQ(B_Vertex, fUnknown040, 0x040);
    EXPECT_OFFSET_EQ(B_Vertex, sqrLightDist, 0x044);
    EXPECT_OFFSET_EQ(B_Vertex, unknown048, 0x048);
}
