#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <BWorld/BMap.h>


TEST(BMapTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Map, unknown018, 0x018);
    EXPECT_OFFSET_EQ(B_Map, unknown030, 0x030);
}
