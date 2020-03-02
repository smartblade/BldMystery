#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include "WinClock.h"


TEST(WinClockTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_WinClock), 0x44);
}

TEST(WinClockTests, Fields)
{
    EXPECT_OFFSET_EQ(B_WinClock, isActive, 0x004);
    EXPECT_OFFSET_EQ(B_WinClock, timeSpeed, 0x008);
    EXPECT_OFFSET_EQ(B_WinClock, idleTime, 0x010);
    EXPECT_OFFSET_EQ(B_WinClock, stopTime, 0x018);
    EXPECT_OFFSET_EQ(B_WinClock, isNotNT, 0x020);
    EXPECT_OFFSET_EQ(B_WinClock, hasCpuid, 0x024);
    EXPECT_OFFSET_EQ(B_WinClock, hasCpiudFunc, 0x028);
    EXPECT_OFFSET_EQ(B_WinClock, hasProcessorTimer, 0x02C);
    EXPECT_OFFSET_EQ(B_WinClock, timeCaps, 0x030);
    EXPECT_OFFSET_EQ(B_WinClock, processorTimer, 0x038);
    EXPECT_OFFSET_EQ(B_WinClock, initialTime, 0x03C);
}
