#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#define protected public
#include <Raster/rOpenGL3/ROpenGLDeviceDLL.h>


TEST(OpenGLRasterDeviceTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_OpenGLRasterDevice), 0xB24A4);
}

TEST(OpenGLRasterDeviceTests, Fields)
{
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, flags, 0x00004);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, posX, 0x00008);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, posY, 0x0000C);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, currentFont, 0x00010);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, textMode, 0x00014);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, textDirection, 0x00018);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, textShadowX, 0x0001C);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, textShadowY, 0x00020);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, textScaleX, 0x00024);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, textScaleY, 0x00028);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, mode, 0x0002C);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, blurLeft, 0x00030);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, blurTop, 0x00034);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, blurRight, 0x00038);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, blurBottom, 0x0003C);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, clipX, 0x00040);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, clipY, 0x00044);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, clipWidth, 0x00048);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, clipHeight, 0x0004C);
    EXPECT_OFFSET_EQ(B_OpenGLRasterDevice, clipActive, 0x00050);
}
