#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Physics/PhysicsState.h>


TEST(PhysicsStateTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PhysicsState), 0x5C);
}

TEST(PhysicsStateTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PhysicsState, version, 0x000);
    EXPECT_OFFSET_EQ(B_PhysicsState, vertices, 0x004);
    EXPECT_OFFSET_EQ(B_PhysicsState, boundingBox, 0x02C);
}
