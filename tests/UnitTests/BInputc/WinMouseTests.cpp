#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BInputc.h>


TEST(WinMouseTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_WinMouse), 0x14C);
}

TEST(WinMouseTests, Fields)
{
    EXPECT_OFFSET_EQ(B_WinMouse, fUnknown0148, 0x148);
}
