#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <App/camera.h>


TEST(CameraTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Camera, movements, 0x000);
    EXPECT_OFFSET_EQ(B_Camera, source, 0x098);
    EXPECT_OFFSET_EQ(B_Camera, target, 0x0B4);
}
