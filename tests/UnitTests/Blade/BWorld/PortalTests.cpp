#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/Surface.h>


TEST(PortalTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_Portal), 0x88);
}

TEST(PortalTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Portal, numVertices, 0x004);
    EXPECT_OFFSET_EQ(B_Portal, vertices, 0x008);
    EXPECT_OFFSET_EQ(B_Portal, sectorIndex, 0x00C);
}
