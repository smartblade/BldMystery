#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/OctTree.h>


TEST(SectorListNodeTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_SectorListNode), 0x1C);
}

TEST(SectorListNodeTests, Fields)
{
    EXPECT_OFFSET_EQ(B_SectorListNode, elements, 0x008);
    EXPECT_OFFSET_EQ(B_SectorListNode, size, 0x00C);
}
