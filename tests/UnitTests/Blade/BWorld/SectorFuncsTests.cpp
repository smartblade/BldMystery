#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/BMap.h>


TEST(SectorFuncsTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_SectorFuncs), 0x24);
}

TEST(SectorFuncsTests, Fields)
{
    EXPECT_OFFSET_EQ(B_SectorFuncs, pyOnEnter, 0x000);
    EXPECT_OFFSET_EQ(B_SectorFuncs, onEnter, 0x004);
    EXPECT_OFFSET_EQ(B_SectorFuncs, pyOnLeave, 0x008);
    EXPECT_OFFSET_EQ(B_SectorFuncs, onLeave, 0x00C);
    EXPECT_OFFSET_EQ(B_SectorFuncs, pyOnHit, 0x010);
    EXPECT_OFFSET_EQ(B_SectorFuncs, onHit, 0x014);
    EXPECT_OFFSET_EQ(B_SectorFuncs, pyOnWalkOn, 0x018);
    EXPECT_OFFSET_EQ(B_SectorFuncs, pyOnWalkOut, 0x01C);
    EXPECT_OFFSET_EQ(B_SectorFuncs, sectorIndex, 0x020);
}
