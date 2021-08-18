#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <Math/BLights.h>


TEST(FlatLightTests, Fields)
{
    EXPECT_OFFSET_EQ(B_FlatLight, color, 0x014);
    EXPECT_OFFSET_EQ(B_FlatLight, intensity, 0x01C);
    EXPECT_OFFSET_EQ(B_FlatLight, precision, 0x020);
    EXPECT_OFFSET_EQ(B_FlatLight, unknown24, 0x024);
    EXPECT_OFFSET_EQ(B_FlatLight, plane, 0x028);
    EXPECT_OFFSET_EQ(B_FlatLight, fUnknown, 0x04C);
    EXPECT_OFFSET_EQ(B_FlatLight, unknownPlane, 0x050);
    EXPECT_OFFSET_EQ(B_FlatLight, direction, 0x074);
    EXPECT_OFFSET_EQ(B_FlatLight, unknownVector, 0x08C);
}
