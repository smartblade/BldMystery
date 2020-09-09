#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <App/camera.h>


TEST(CameraTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Camera, movements, 0x000);
    EXPECT_OFFSET_EQ(B_Camera, source, 0x098);
    EXPECT_OFFSET_EQ(B_Camera, target, 0x0B4);
    EXPECT_OFFSET_EQ(B_Camera, curSourceNode, 0x104);
    EXPECT_OFFSET_EQ(B_Camera, curTargetNode, 0x108);
    EXPECT_OFFSET_EQ(B_Camera, time, 0x114);
    EXPECT_OFFSET_EQ(B_Camera, unknown011C, 0x11C);
    EXPECT_OFFSET_EQ(B_Camera, unknown014C, 0x14C);
    EXPECT_OFFSET_EQ(B_Camera, unknown0150, 0x150);
    EXPECT_OFFSET_EQ(B_Camera, curTargetTime, 0x208);
    EXPECT_OFFSET_EQ(B_Camera, curSourceTime, 0x210);
}
