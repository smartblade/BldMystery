#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "bld_misc_funcs.h"


TEST(Unknown005A52CETests, SizeOf)
{
    EXPECT_EQ(sizeof(Unknown005A52CE), 0x0D4);
}
