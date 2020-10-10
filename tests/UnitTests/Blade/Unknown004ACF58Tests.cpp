#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <Entities/ObjectEntity.h>


TEST(Unknown004ACF58Tests, SizeOf)
{
    EXPECT_EQ(sizeof(Unknown004ACF58), 0x108);
}

TEST(Unknown004ACF58Tests, Fields)
{
    EXPECT_OFFSET_EQ(Unknown004ACF58, pose, 0x078);
}
