#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <Entities/PhysicSIEntity.h>


TEST(PhysicSIEntityTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PhysicSIEntity), 0x1EC);
}
