#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "BladeApp.h"


TEST(BladeAppTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_BladeApp), 0x7D0);
}

TEST(BladeAppTests, Fields)
{
    EXPECT_OFFSET_EQ(B_BladeApp, listenerMode, 0x020);
    EXPECT_OFFSET_EQ(B_BladeApp, clock1, 0x02C);
    EXPECT_OFFSET_EQ(B_BladeApp, clock2, 0x030);
    EXPECT_OFFSET_EQ(B_BladeApp, CDCallback, 0x034);
    EXPECT_OFFSET_EQ(B_BladeApp, arguments, 0x038);
    EXPECT_OFFSET_EQ(B_BladeApp, console, 0x050);
    EXPECT_OFFSET_EQ(B_BladeApp, rootWidget, 0x054);
    EXPECT_OFFSET_EQ(B_BladeApp, lastPlayerCType, 0x060);
    EXPECT_OFFSET_EQ(B_BladeApp, player1, 0x068);
    EXPECT_OFFSET_EQ(B_BladeApp, client, 0x06C);
    EXPECT_OFFSET_EQ(B_BladeApp, unknownPtr070, 0x070);
    EXPECT_OFFSET_EQ(B_BladeApp, unknownPtr074, 0x074);
    EXPECT_OFFSET_EQ(B_BladeApp, camera, 0x078);
    EXPECT_OFFSET_EQ(B_BladeApp, location, 0x07C);
    EXPECT_OFFSET_EQ(B_BladeApp, bloodLevel, 0x1B4);
    EXPECT_OFFSET_EQ(B_BladeApp, mutilationLevel, 0x1B8);
    EXPECT_OFFSET_EQ(B_BladeApp, time, 0x5C8);
    EXPECT_OFFSET_EQ(B_BladeApp, b05D1, 0x5D1);
    EXPECT_OFFSET_EQ(B_BladeApp, no_sleep, 0x5D2);
    EXPECT_OFFSET_EQ(B_BladeApp, isActive, 0x5D3);
    EXPECT_OFFSET_EQ(B_BladeApp, b05D4, 0x5D4);
    EXPECT_OFFSET_EQ(B_BladeApp, cls, 0x5D5);
    EXPECT_OFFSET_EQ(B_BladeApp, saveToBmp, 0x5D8);
    EXPECT_OFFSET_EQ(B_BladeApp, commandLine, 0x5E8);
    EXPECT_OFFSET_EQ(B_BladeApp, mode, 0x5EC);
    EXPECT_OFFSET_EQ(B_BladeApp, map_to_load, 0x5F4);
    EXPECT_OFFSET_EQ(B_BladeApp, pyStatement, 0x5F8);
    EXPECT_OFFSET_EQ(B_BladeApp, newMap, 0x5FC);
    EXPECT_OFFSET_EQ(B_BladeApp, needClearLevel, 0x604);
    EXPECT_OFFSET_EQ(B_BladeApp, noSound, 0x606);
    EXPECT_OFFSET_EQ(B_BladeApp, showConsole, 0x607);
    EXPECT_OFFSET_EQ(B_BladeApp, mapName, 0x608);
    EXPECT_OFFSET_EQ(B_BladeApp, rasterName, 0x610);
    EXPECT_OFFSET_EQ(B_BladeApp, soundDeviceId, 0x618);
    EXPECT_OFFSET_EQ(B_BladeApp, drawShadows, 0x620);
    EXPECT_OFFSET_EQ(B_BladeApp, autoEngageCombat, 0x624);
    EXPECT_OFFSET_EQ(B_BladeApp, aecGap, 0x628);
    EXPECT_OFFSET_EQ(B_BladeApp, menuTgapFunc, 0x630);
    EXPECT_OFFSET_EQ(B_BladeApp, afterFrameFuncs, 0x638);
    EXPECT_OFFSET_EQ(B_BladeApp, values, 0x650);
    EXPECT_OFFSET_EQ(B_BladeApp, rasterLibraryName, 0x770);
    EXPECT_OFFSET_EQ(B_BladeApp, startPath, 0x778);
    EXPECT_OFFSET_EQ(B_BladeApp, destroyRasterCB, 0x780);
    EXPECT_OFFSET_EQ(B_BladeApp, createRasterCB, 0x784);
    EXPECT_OFFSET_EQ(B_BladeApp, rasterLibrary, 0x788);
    EXPECT_OFFSET_EQ(B_BladeApp, winProc, 0x78C);
    EXPECT_OFFSET_EQ(B_BladeApp, windowClass, 0x790);
    EXPECT_OFFSET_EQ(B_BladeApp, window, 0x7B8);
    EXPECT_OFFSET_EQ(B_BladeApp, module, 0x7BC);
    EXPECT_OFFSET_EQ(B_BladeApp, b07C0, 0x7C0);
    EXPECT_OFFSET_EQ(B_BladeApp, noMouse, 0x7C8);
    EXPECT_OFFSET_EQ(B_BladeApp, noKeyboard, 0x7C9);
    EXPECT_OFFSET_EQ(B_BladeApp, noDInput, 0x7CA);
    EXPECT_OFFSET_EQ(B_BladeApp, noExclusiveMouse, 0x7CB);
    EXPECT_OFFSET_EQ(B_BladeApp, r3Dfx, 0x7CC);
    EXPECT_OFFSET_EQ(B_BladeApp, rsoft16b, 0x7CD);
    EXPECT_OFFSET_EQ(B_BladeApp, rOpenGL, 0x7CE);
    EXPECT_OFFSET_EQ(B_BladeApp, rD3D, 0x7CF);
}
