#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "Sector.h"


TEST(SectorTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Sector, groupId, 0x020);
    EXPECT_OFFSET_EQ(B_Sector, unknown204, 0x204);
}