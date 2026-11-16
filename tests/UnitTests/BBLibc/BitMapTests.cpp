#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BBLibc/BitMap.h>


TEST(BitMapTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_BitMap), 0x18);
}

TEST(BitMapTests, Fields)
{
    EXPECT_OFFSET_EQ(B_BitMap, type, 0x004);
    EXPECT_OFFSET_EQ(B_BitMap, dimension1, 0x008);
    EXPECT_OFFSET_EQ(B_BitMap, dimension2, 0x00C);
    EXPECT_OFFSET_EQ(B_BitMap, data, 0x010);
    EXPECT_OFFSET_EQ(B_BitMap, pal, 0x014);
}
