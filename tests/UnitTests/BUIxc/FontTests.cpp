#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <BUIxc.h>


TEST(FontTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Font, bitmapHandle, 0x00C);
    EXPECT_OFFSET_EQ(B_Font, charData, 0x028);
}
