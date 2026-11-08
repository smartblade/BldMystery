#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/OctTree.h>


TEST(OctantNodeBaseTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_OctantNodeBase), 0x04);
}
