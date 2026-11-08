#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/OctTree.h>


TEST(LeafNodeTests, SizeOf)
{
    EXPECT_EQ(sizeof(LeafNode), 0x08);
}

TEST(LeafNodeTests, Fields)
{
    EXPECT_OFFSET_EQ(LeafNode, sectors, 0x004);
}
