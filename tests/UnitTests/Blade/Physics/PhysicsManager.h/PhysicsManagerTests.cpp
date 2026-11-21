#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Physics/PhysicsManager.h>


TEST(PhysicsManagerTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PhysicsManager), 0x28);
}

TEST(PhysicsManagerTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PhysicsManager, time, 0x000);
    EXPECT_OFFSET_EQ(B_PhysicsManager, timeStep, 0x008);
    EXPECT_OFFSET_EQ(B_PhysicsManager, groups, 0x010);
}
