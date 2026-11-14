#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Physics/PhysicsTemplate.h>


TEST(PhysicsStateCacheHandleTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PhysicsStateCacheHandle), 0xC);
}

TEST(PhysicsStateCacheHandleTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PhysicsStateCacheHandle, version, 0x000);
    EXPECT_OFFSET_EQ(B_PhysicsStateCacheHandle, slot, 0x004);
    EXPECT_OFFSET_EQ(B_PhysicsStateCacheHandle, state, 0x008);
}
