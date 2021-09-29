#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <Raster/rOpenGL3/ROpenGLDeviceDLL.h>


TEST(PointLightTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PointLight, light, 0x000);
    EXPECT_OFFSET_EQ(B_PointLight, pointToPlane, 0x004);
    EXPECT_OFFSET_EQ(B_PointLight, planeDist, 0x01C);
}
