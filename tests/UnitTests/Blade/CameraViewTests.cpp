#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <View/CameraView.h>


TEST(CameraViewTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_CameraView), 0x31C);
}

TEST(CameraViewTests, Fields)
{
    EXPECT_OFFSET_EQ(B_CameraView, xCentre, 0x000);
    EXPECT_OFFSET_EQ(B_CameraView, yCentre, 0x004);
    EXPECT_OFFSET_EQ(B_CameraView, width, 0x008);
    EXPECT_OFFSET_EQ(B_CameraView, height, 0x00C);
    EXPECT_OFFSET_EQ(B_CameraView, unknown010, 0x010);
    EXPECT_OFFSET_EQ(B_CameraView, z, 0x014);
}
