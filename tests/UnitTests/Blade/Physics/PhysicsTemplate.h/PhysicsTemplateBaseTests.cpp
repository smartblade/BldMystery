#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Physics/PhysicsTemplate.h>


TEST(PhysicsTemplateBaseTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PhysicsTemplateBase), 0x68);
}

TEST(PhysicsTemplateBaseTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PhysicsTemplateBase, contacts, 0x004);
    EXPECT_OFFSET_EQ(B_PhysicsTemplateBase, unknownField038, 0x038);
    EXPECT_OFFSET_EQ(B_PhysicsTemplateBase, unknownField03C, 0x03C);
    EXPECT_OFFSET_EQ(B_PhysicsTemplateBase, unknownField040, 0x040);
    EXPECT_OFFSET_EQ(B_PhysicsTemplateBase, pairs, 0x044);
    EXPECT_OFFSET_EQ(B_PhysicsTemplateBase, group, 0x058);
    EXPECT_OFFSET_EQ(B_PhysicsTemplateBase, ignore, 0x05C);
    EXPECT_OFFSET_EQ(B_PhysicsTemplateBase, mask, 0x060);
    EXPECT_OFFSET_EQ(B_PhysicsTemplateBase, solidMask, 0x064);
}
