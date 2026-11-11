#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/BWorld.h>


TEST(WorldTests, Fields)
{
    EXPECT_OFFSET_EQ(B_World, entities, 0x0018);
    EXPECT_OFFSET_EQ(B_World, entities.size, 0x0018);
    EXPECT_OFFSET_EQ(B_World, entities.hash, 0x001C);
    EXPECT_OFFSET_EQ(B_World, entities.unknown1804, 0x181C);
    EXPECT_OFFSET_EQ(B_World, entities.lastItem, 0x1820);
    EXPECT_OFFSET_EQ(B_World, nextEntitySuffix, 0x1824);
    EXPECT_OFFSET_EQ(B_World, subscriptions, 0x1828);
    EXPECT_OFFSET_EQ(B_World, scheduledFuncs, 0x1840);
    EXPECT_OFFSET_EQ(B_World, unknown1858, 0x1858);
    EXPECT_OFFSET_EQ(B_World, world_file_name, 0x185C);
    EXPECT_OFFSET_EQ(B_World, timeStep, 0x1870);
    EXPECT_OFFSET_EQ(B_World, currentTick, 0x1878);
    EXPECT_OFFSET_EQ(B_World, lastTime, 0x187C);
    EXPECT_OFFSET_EQ(B_World, physicsMgr, 0x1884);
    EXPECT_OFFSET_EQ(B_World, atmospheres, 0x18AC);
    EXPECT_OFFSET_EQ(B_World, map, 0x18C4);
    EXPECT_OFFSET_EQ(B_World, octTree, 0x18F8);
    EXPECT_OFFSET_EQ(B_World, octTree.m_center, 0x18FC);
    EXPECT_OFFSET_EQ(B_World, octTree.m_halfSize, 0x1914);
    EXPECT_OFFSET_EQ(B_World, octTree.m_root, 0x191C);
    EXPECT_OFFSET_EQ(B_World, lights, 0x1920);
    EXPECT_OFFSET_EQ(B_World, unknown1938, 0x1938);
    EXPECT_OFFSET_EQ(B_World, sunVector, 0x193C);
    EXPECT_OFFSET_EQ(B_World, initial_point_position, 0x1954);
    EXPECT_OFFSET_EQ(B_World, initial_point_orientation, 0x196C);
}
