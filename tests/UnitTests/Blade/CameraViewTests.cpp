#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "bld_misc_funcs.h"


TEST(CameraViewTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_CameraView), 0x31C);
}

TEST(CameraViewTests, Fields)
{
    EXPECT_OFFSET_EQ(B_CameraView, unknown000, 0x000);
    EXPECT_OFFSET_EQ(B_CameraView, unknown004, 0x004);
    EXPECT_OFFSET_EQ(B_CameraView, unknown008, 0x008);
    EXPECT_OFFSET_EQ(B_CameraView, unknown00C, 0x00C);
    EXPECT_OFFSET_EQ(B_CameraView, unknown010, 0x010);
    EXPECT_OFFSET_EQ(B_CameraView, unknown014, 0x014);
}
