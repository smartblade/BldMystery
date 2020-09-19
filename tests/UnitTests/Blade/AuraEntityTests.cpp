#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <Entities/AuraEntity.h>


TEST(AuraEntityTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_AuraEntity), 0x300);
}

TEST(AuraEntityTests, Fields)
{
    EXPECT_OFFSET_EQ(B_AuraEntity, active, 0x1A0);
    EXPECT_OFFSET_EQ(B_AuraEntity, alphaMode, 0x1A4);
    EXPECT_OFFSET_EQ(B_AuraEntity, hideFrontFaces, 0x1A8);
    EXPECT_OFFSET_EQ(B_AuraEntity, hideBackFaces, 0x1AC);
    EXPECT_OFFSET_EQ(B_AuraEntity, size, 0x1B0);
    EXPECT_OFFSET_EQ(B_AuraEntity, alpha, 0x1B4);
    EXPECT_OFFSET_EQ(B_AuraEntity, colourIntensity, 0x1B8);
    EXPECT_OFFSET_EQ(B_AuraEntity, gradients, 0x1BC);
}
