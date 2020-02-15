#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "WinClock.h"


TEST(WinClockTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_WinClock), 0x44);
}

TEST(WinClockTests, Fields)
{
    EXPECT_OFFSET_EQ(B_WinClock, isActive, 0x004);
    EXPECT_OFFSET_EQ(B_WinClock, timeSpeed, 0x008);
    EXPECT_OFFSET_EQ(B_WinClock, fUnknown10, 0x010);
    EXPECT_OFFSET_EQ(B_WinClock, fUnknown18, 0x018);
}
