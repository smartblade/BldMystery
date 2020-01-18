#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "App.h"


TEST(BladeAppTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_BladeApp), 0x7D0);
}

TEST(BladeAppTests, Fields)
{
    EXPECT_OFFSET_EQ(B_BladeApp, listenerMode, 0x020);
    EXPECT_OFFSET_EQ(B_BladeApp, clock1, 0x02C);
    EXPECT_OFFSET_EQ(B_BladeApp, clock2, 0x030);
    EXPECT_OFFSET_EQ(B_BladeApp, rootWidget, 0x054);
    EXPECT_OFFSET_EQ(B_BladeApp, lastPlayerCType, 0x060);
    EXPECT_OFFSET_EQ(B_BladeApp, player1, 0x068);
    EXPECT_OFFSET_EQ(B_BladeApp, client, 0x06C);
    EXPECT_OFFSET_EQ(B_BladeApp, camera, 0x078);
    EXPECT_OFFSET_EQ(B_BladeApp, location, 0x07C);
    EXPECT_OFFSET_EQ(B_BladeApp, time, 0x5C8);
    EXPECT_OFFSET_EQ(B_BladeApp, no_sleep, 0x5D2);
    EXPECT_OFFSET_EQ(B_BladeApp, commandLine, 0x5E8);
    EXPECT_OFFSET_EQ(B_BladeApp, mode, 0x5EC);
    EXPECT_OFFSET_EQ(B_BladeApp, map_to_load, 0x5F4);
    EXPECT_OFFSET_EQ(B_BladeApp, pyStatement, 0x5F8);
    EXPECT_OFFSET_EQ(B_BladeApp, auxText, 0x5FC);
    EXPECT_OFFSET_EQ(B_BladeApp, mapName, 0x608);
    EXPECT_OFFSET_EQ(B_BladeApp, drawShadows, 0x620);
    EXPECT_OFFSET_EQ(B_BladeApp, autoEngageCombat, 0x624);
    EXPECT_OFFSET_EQ(B_BladeApp, aecGap, 0x628);
    EXPECT_OFFSET_EQ(B_BladeApp, window, 0x7B8);
    EXPECT_OFFSET_EQ(B_BladeApp, module, 0x7BC);
}
