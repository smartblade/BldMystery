#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <Raster/rOpenGL3/ROpenGLDeviceDLL.h>


TEST(AtmosphereTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_Atmosphere), 0x18);
}

TEST(AtmosphereTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Atmosphere, color, 0x00C);
    EXPECT_OFFSET_EQ(B_Atmosphere, intensity, 0x014);
}
