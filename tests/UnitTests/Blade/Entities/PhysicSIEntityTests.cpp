#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <Entities/PhysicSIEntity.h>


TEST(PhysicSIEntityTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PhysicSIEntity), 0x1EC);
}

TEST(PhysicSIEntityTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PhysicSIEntity, static1D8, 0x1D8);
    EXPECT_OFFSET_EQ(B_PhysicSIEntity, static1DC, 0x1DC);
}
