#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Entities/DecalEntity.h>


TEST(DecalEntityTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_DecalEntity), 0x404);
}
