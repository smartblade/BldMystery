#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Physics/RigidBody.h>


TEST(RigidBodyTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_RigidBody), 0x1B8);
}

TEST(RigidBodyTests, Fields)
{
    EXPECT_OFFSET_EQ(B_RigidBody, materialId, 0x038);
    EXPECT_OFFSET_EQ(B_RigidBody, solid, 0x03C);
    EXPECT_OFFSET_EQ(B_RigidBody, pose, 0x040);
    EXPECT_OFFSET_EQ(B_RigidBody, unknownField0C0, 0x0C0);
    EXPECT_OFFSET_EQ(B_RigidBody, unknownField0C8, 0x0C8);
    EXPECT_OFFSET_EQ(B_RigidBody, timeStep, 0x0D0);
    EXPECT_OFFSET_EQ(B_RigidBody, unknownField0D8, 0x0D8);
    EXPECT_OFFSET_EQ(B_RigidBody, unknownField0E0, 0x0E0);
    EXPECT_OFFSET_EQ(B_RigidBody, inverseInertiaWorld, 0x0E8);
    EXPECT_OFFSET_EQ(B_RigidBody, mass, 0x168);
    EXPECT_OFFSET_EQ(B_RigidBody, worldCenterOfMass, 0x170);
    EXPECT_OFFSET_EQ(B_RigidBody, previousCenterOfMass, 0x188);
    EXPECT_OFFSET_EQ(B_RigidBody, gravity, 0x1A0);
}
