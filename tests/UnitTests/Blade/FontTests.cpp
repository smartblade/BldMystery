#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "bld_misc_funcs.h"


TEST(FontTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Font, charData, 0x028);
}
