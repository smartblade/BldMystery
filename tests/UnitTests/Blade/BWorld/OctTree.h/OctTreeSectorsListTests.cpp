#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/OctTree.h>


TEST(OctTreeSectorsListTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_OctTreeSectorsList), 0x804);
}

TEST(OctTreeSectorsListTests, Fields)
{
    EXPECT_OFFSET_EQ(B_OctTreeSectorsList, size, 0x000);
    EXPECT_OFFSET_EQ(B_OctTreeSectorsList, sectors, 0x004);
}
