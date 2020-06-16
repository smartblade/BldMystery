#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include "bld_misc_funcs.h"


TEST(CombustionTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_Combustion), 0x5C);
}

TEST(CombustionTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Combustion, a00C, 0x00C);
    EXPECT_OFFSET_EQ(B_Combustion, unknown0024, 0x024);
    EXPECT_OFFSET_EQ(B_Combustion, particleType, 0x048);
}
