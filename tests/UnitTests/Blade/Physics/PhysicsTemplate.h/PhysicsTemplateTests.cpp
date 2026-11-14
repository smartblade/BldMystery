#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Physics/PhysicsTemplate.h>


TEST(PhysicsTemplateTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PhysicsTemplate), 0x108);
}

TEST(PhysicsTemplateTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PhysicsTemplate, stateCache, 0x068);
    EXPECT_OFFSET_EQ(B_PhysicsTemplate, resource, 0x074);
    EXPECT_OFFSET_EQ(B_PhysicsTemplate, pose, 0x078);
    EXPECT_OFFSET_EQ(B_PhysicsTemplate, scale, 0x0F8);
    EXPECT_OFFSET_EQ(B_PhysicsTemplate, invScale, 0x100);
}
