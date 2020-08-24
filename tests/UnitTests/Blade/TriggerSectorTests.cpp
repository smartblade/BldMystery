#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/BWorld.h>


TEST(TriggerSectorTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_TriggerSector), 0x80);
}

TEST(TriggerSectorTests, Fields)
{
    EXPECT_OFFSET_EQ(B_TriggerSector, minX, 0x00C);
    EXPECT_OFFSET_EQ(B_TriggerSector, minY, 0x010);
    EXPECT_OFFSET_EQ(B_TriggerSector, maxX, 0x014);
    EXPECT_OFFSET_EQ(B_TriggerSector, maxY, 0x018);
    EXPECT_OFFSET_EQ(B_TriggerSector, maxH, 0x01C);
    EXPECT_OFFSET_EQ(B_TriggerSector, minH, 0x020);
    EXPECT_OFFSET_EQ(B_TriggerSector, floorHeight, 0x024);
    EXPECT_OFFSET_EQ(B_TriggerSector, roofHeight, 0x028);
    EXPECT_OFFSET_EQ(B_TriggerSector, points, 0x02C);
    EXPECT_OFFSET_EQ(B_TriggerSector, a040, 0x040);
    EXPECT_OFFSET_EQ(B_TriggerSector, a054, 0x054);
    EXPECT_OFFSET_EQ(B_TriggerSector, onEnter, 0x06C);
    EXPECT_OFFSET_EQ(B_TriggerSector, onLeave, 0x070);
    EXPECT_OFFSET_EQ(B_TriggerSector, data, 0x074);
    EXPECT_OFFSET_EQ(B_TriggerSector, groupName, 0x078);
}
