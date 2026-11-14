#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Physics/PhysicsTemplate.h>


TEST(PhysicsTemplatePairTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PhysicsTemplatePair), 0x8);
}

TEST(PhysicsTemplatePairTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PhysicsTemplatePair, other, 0x000);
    EXPECT_OFFSET_EQ(B_PhysicsTemplatePair, active, 0x004);
}
