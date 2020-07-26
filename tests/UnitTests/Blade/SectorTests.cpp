#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "BMap.h"


TEST(SectorTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_Sector), 0x220);
}

TEST(SectorTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Sector, groupId, 0x020);
    EXPECT_OFFSET_EQ(B_Sector, unknown204, 0x204);
}
