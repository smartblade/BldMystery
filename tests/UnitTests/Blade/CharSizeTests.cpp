#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "bld_misc_funcs.h"


TEST(CharSizeTests, Fields)
{
    EXPECT_OFFSET_EQ(B_CharSize, width, 0x008);
    EXPECT_OFFSET_EQ(B_CharSize, height, 0x00C);
}
