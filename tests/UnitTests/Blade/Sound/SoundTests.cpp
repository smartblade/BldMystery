#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "Sound/Sound.h"


TEST(SoundTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Sound, sendNotify, 0x019);
}
