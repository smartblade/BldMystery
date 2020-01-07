#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "bld_misc_funcs.h"


TEST(Unknown004CD5ECTests, SizeOf)
{
    EXPECT_EQ(sizeof(Unknown004CD5EC), 0x31C);
}

TEST(Unknown004CD5ECTests, Fields)
{
    EXPECT_OFFSET_EQ(Unknown004CD5EC, unknown000, 0x000);
    EXPECT_OFFSET_EQ(Unknown004CD5EC, unknown004, 0x004);
    EXPECT_OFFSET_EQ(Unknown004CD5EC, unknown008, 0x008);
    EXPECT_OFFSET_EQ(Unknown004CD5EC, unknown00C, 0x00C);
    EXPECT_OFFSET_EQ(Unknown004CD5EC, unknown010, 0x010);
    EXPECT_OFFSET_EQ(Unknown004CD5EC, unknown014, 0x014);
}
