#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "sound_device.h"


TEST(SoundTests, SizeOf)
{
    EXPECT_EQ(sizeof(sound_t), 0x264);
}

TEST(SoundTests, Fields)
{
    EXPECT_OFFSET_EQ(sound_t, unknown04, 0x004);
    EXPECT_OFFSET_EQ(sound_t, unknown08, 0x008);
    EXPECT_OFFSET_EQ(sound_t, unknown0C, 0x00C);
}
