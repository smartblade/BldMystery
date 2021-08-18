#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <BWorld/BMap.h>


TEST(SectorLightsTests, Fields)
{
    EXPECT_OFFSET_EQ(B_SectorLights, ambient, 0x00C);
    EXPECT_OFFSET_EQ(B_SectorLights, flat, 0x080);
}
