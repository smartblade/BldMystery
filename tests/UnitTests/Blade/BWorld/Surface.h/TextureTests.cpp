#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/MapTexture.h>


TEST(TextureTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Texture, handle, 0x000);
    EXPECT_OFFSET_EQ(B_Texture, xTransform, 0x004);
    EXPECT_OFFSET_EQ(B_Texture, yTransform, 0x01C);
    EXPECT_OFFSET_EQ(B_Texture, xOffset, 0x034);
    EXPECT_OFFSET_EQ(B_Texture, yOffset, 0x038);
}
