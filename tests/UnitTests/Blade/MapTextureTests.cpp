#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/MapTexture.h>


TEST(MapTextureTests, Fields)
{
    EXPECT_OFFSET_EQ(B_MapTexture, unknown000, 0x000);
    EXPECT_OFFSET_EQ(B_MapTexture, fUnknown004, 0x004);
    EXPECT_OFFSET_EQ(B_MapTexture, texture, 0x008);
    EXPECT_OFFSET_EQ(B_MapTexture, fUnknown048, 0x048);
    EXPECT_OFFSET_EQ(B_MapTexture, fUnknown04C, 0x04C);
}
