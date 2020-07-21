#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "sound_device.h"


TEST(YSoundDevTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_YSoundDev), 0x264);
}

TEST(YSoundDevTests, Fields)
{
    EXPECT_OFFSET_EQ(B_YSoundDev, unknown04, 0x004);
    EXPECT_OFFSET_EQ(B_YSoundDev, unknown08, 0x008);
    EXPECT_OFFSET_EQ(B_YSoundDev, unknown0C, 0x00C);
}
