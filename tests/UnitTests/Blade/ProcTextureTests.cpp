#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "bld_misc_funcs.h"


TEST(ProcTextureTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ProcTexture, data, 0x004);
}
