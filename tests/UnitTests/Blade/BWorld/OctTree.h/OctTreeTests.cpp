#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/OctTree.h>


TEST(OctTreeTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_OctTree), 0x28);
}

TEST(OctTreeTests, Fields)
{
    EXPECT_OFFSET_EQ(B_OctTree, m_center, 0x004);
    EXPECT_OFFSET_EQ(B_OctTree, m_halfSize, 0x01C);
    EXPECT_OFFSET_EQ(B_OctTree, m_root, 0x024);
}
