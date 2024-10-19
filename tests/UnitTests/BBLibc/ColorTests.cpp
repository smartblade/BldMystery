#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <BBLibc/Color.h>


TEST(ColorTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_Color), 0x0008);
}

TEST(ColorTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Color, r, 0x0004);
    EXPECT_OFFSET_EQ(B_Color, g, 0x0005);
    EXPECT_OFFSET_EQ(B_Color, b, 0x0006);
}
