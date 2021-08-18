#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <Math/BLights.h>


TEST(AmbientLightTests, Fields)
{
    EXPECT_OFFSET_EQ(B_AmbientLight, color, 0x014);
    EXPECT_OFFSET_EQ(B_AmbientLight, intensity, 0x01C);
    EXPECT_OFFSET_EQ(B_AmbientLight, precision, 0x020);
    EXPECT_OFFSET_EQ(B_AmbientLight, unknown24, 0x024);
    EXPECT_OFFSET_EQ(B_AmbientLight, plane, 0x028);
    EXPECT_OFFSET_EQ(B_AmbientLight, fUnknown, 0x04C);
    EXPECT_OFFSET_EQ(B_AmbientLight, unknownPlane, 0x050);
}
