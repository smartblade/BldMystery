#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "bld_misc_funcs.h"


TEST(AGTextureTests, Fields)
{
    EXPECT_OFFSET_EQ(B_AGTexture, textureEffect, 0x000);
    EXPECT_OFFSET_EQ(B_AGTexture, needUpdate, 0x004);
    EXPECT_OFFSET_EQ(B_AGTexture, procTexture, 0x008);
    EXPECT_OFFSET_EQ(B_AGTexture, bmpHandle, 0x00C);
}
