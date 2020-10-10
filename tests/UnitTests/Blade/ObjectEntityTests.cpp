#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <Entities/ObjectEntity.h>


TEST(ObjectEntityTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ObjectEntity), 0x1C0);
}

TEST(ObjectEntityTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ObjectEntity, unknown1B8, 0x01B8);
}
