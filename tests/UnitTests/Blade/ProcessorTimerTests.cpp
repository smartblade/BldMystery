#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "ProcessorTimer.h"


TEST(ProcessorTimerTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ProcessorTimer), 0x30);
}
