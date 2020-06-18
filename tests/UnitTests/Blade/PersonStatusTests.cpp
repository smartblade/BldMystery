#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "bld_misc_funcs.h"


TEST(PersonStatusTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PersonStatus), 0x0D4);
}
