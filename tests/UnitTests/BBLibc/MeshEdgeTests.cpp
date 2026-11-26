#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BBLibc/MeshEdge.h>


TEST(MeshEdgeTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_MeshEdge), 0x18);
}

TEST(MeshEdgeTests, Fields)
{
    EXPECT_OFFSET_EQ(B_MeshEdge, node, 0x000);
    EXPECT_OFFSET_EQ(B_MeshEdge, vertexA, 0x004);
    EXPECT_OFFSET_EQ(B_MeshEdge, vertexB, 0x008);
    EXPECT_OFFSET_EQ(B_MeshEdge, invLength, 0x00C);
    EXPECT_OFFSET_EQ(B_MeshEdge, sharp, 0x014);
}
