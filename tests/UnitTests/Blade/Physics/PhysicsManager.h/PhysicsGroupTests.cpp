#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Physics/PhysicsManager.h>


TEST(PhysicsGroupTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PhysicsGroup), 0x44);
}

TEST(PhysicsGroupTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PhysicsGroup, time, 0x000);
    EXPECT_OFFSET_EQ(B_PhysicsGroup, timeStep, 0x008);
    EXPECT_OFFSET_EQ(B_PhysicsGroup, nodes, 0x010);
    EXPECT_OFFSET_EQ(B_PhysicsGroup, unknown040, 0x040);
}
