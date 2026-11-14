#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Physics/RigidBody.h>


TEST(PhysicsNodeTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PhysicsNode), 0x38);
}

TEST(PhysicsNodeTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PhysicsNode, linearImpulse, 0x004);
    EXPECT_OFFSET_EQ(B_PhysicsNode, angularImpulse, 0x01C);
    EXPECT_OFFSET_EQ(B_PhysicsNode, owner, 0x034);
}
