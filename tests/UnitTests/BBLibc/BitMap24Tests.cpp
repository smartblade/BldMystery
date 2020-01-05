#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BBLibc.h>


TEST(BitMap24Tests, Fields)
{
    EXPECT_OFFSET_EQ(B_BitMap24, dimension1, 0x004);
    EXPECT_OFFSET_EQ(B_BitMap24, dimension2, 0x008);
    EXPECT_OFFSET_EQ(B_BitMap24, data, 0x00C);
}
