#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Entities/PhysicSIEntity.h>


TEST(PhysicBodyTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PhysicBody), 0x1BC);
}

TEST(PhysicBodyTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PhysicBody, entity, 0x1B8);
}
