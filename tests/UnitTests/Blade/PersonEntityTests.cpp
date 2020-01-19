#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "entity.h"


TEST(PersonEntityTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PersonEntity), 0x2080);
}

TEST(PersonEntityTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PersonEntity, unknownFields01A0, 0x01A0);
    EXPECT_OFFSET_EQ(B_PersonEntity, unknown01AC, 0x01AC);
    EXPECT_OFFSET_EQ(B_PersonEntity, unknownFields01B0, 0x01B0);
}
