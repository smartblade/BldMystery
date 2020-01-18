#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "StringValue.h"


TEST(StringValueTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_StringValue), 0x14);
}

TEST(StringValueTests, Fields)
{
    EXPECT_OFFSET_EQ(B_StringValue, value, 0x00C);
}
