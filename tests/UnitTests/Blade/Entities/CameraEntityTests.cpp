#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Entities/CameraEntity.h>


TEST(CameraEntityTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_CameraEntity), 0x43C);
}

TEST(CameraEntityTests, Fields)
{
    EXPECT_OFFSET_EQ(B_CameraEntity, cam, 0x1A0);
    EXPECT_OFFSET_EQ(B_CameraEntity, cam.movements, 0x1A0);
    EXPECT_OFFSET_EQ(B_CameraEntity, cam.source, 0x238);
    EXPECT_OFFSET_EQ(B_CameraEntity, cam.target, 0x254);
    EXPECT_OFFSET_EQ(B_CameraEntity, cam.curSourceNode, 0x2A4);
    EXPECT_OFFSET_EQ(B_CameraEntity, cam.curTargetNode, 0x2A8);
    EXPECT_OFFSET_EQ(B_CameraEntity, cam.time, 0x2B4);
    EXPECT_OFFSET_EQ(B_CameraEntity, cam.unknown011C, 0x2BC);
    EXPECT_OFFSET_EQ(B_CameraEntity, cam.unknown014C, 0x2EC);
    EXPECT_OFFSET_EQ(B_CameraEntity, cam.unknown0150, 0x2F0);
    EXPECT_OFFSET_EQ(B_CameraEntity, cam.curTargetTime, 0x3A8);
    EXPECT_OFFSET_EQ(B_CameraEntity, cam.curSourceTime, 0x3B0);
    EXPECT_OFFSET_EQ(B_CameraEntity, unknownValueFromApplication, 0x3EC);
    EXPECT_OFFSET_EQ(B_CameraEntity, unknownPtrFromApplication, 0x3F0);
}
