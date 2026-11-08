#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/OctTree.h>


TEST(OctantNodeTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_OctantNode), 0x24);
}

TEST(OctantNodeTests, Fields)
{
    EXPECT_OFFSET_EQ(B_OctantNode, children, 0x004);
}
