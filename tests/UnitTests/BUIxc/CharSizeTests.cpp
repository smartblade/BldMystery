#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <BUIxc.h>


TEST(CharSizeTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Font::B_CharSize, x, 0x000);
    EXPECT_OFFSET_EQ(B_Font::B_CharSize, y, 0x004);
    EXPECT_OFFSET_EQ(B_Font::B_CharSize, width, 0x008);
    EXPECT_OFFSET_EQ(B_Font::B_CharSize, height, 0x00C);
}
