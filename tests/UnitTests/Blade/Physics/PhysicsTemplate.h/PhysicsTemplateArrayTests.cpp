#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Physics/PhysicsTemplate.h>


TEST(PhysicsTemplateArrayTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PhysicsTemplateArray), 0x14);
}

TEST(PhysicsTemplateArrayTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PhysicsTemplateArray, elements, 0x004);
    EXPECT_OFFSET_EQ(B_PhysicsTemplateArray, size, 0x008);
    EXPECT_OFFSET_EQ(B_PhysicsTemplateArray, increment, 0x00C);
    EXPECT_OFFSET_EQ(B_PhysicsTemplateArray, num_alloc, 0x010);
}
