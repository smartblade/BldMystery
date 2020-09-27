#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <en_control.h>


TEST(EnControlTests, Fields)
{
    EXPECT_OFFSET_EQ(EnControl, charTypes, 0x03C);
    EXPECT_OFFSET_EQ(EnControl, charTypes.size, 0x044);
}
