#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Entities/AuraEntity.h>


TEST(AuraGradientTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_AuraGradient), 0x40);
}

TEST(AuraGradientTests, Fields)
{
    EXPECT_OFFSET_EQ(B_AuraGradient, startingPoint, 0x000);
    EXPECT_OFFSET_EQ(B_AuraGradient, endingPoint, 0x004);
    EXPECT_OFFSET_EQ(B_AuraGradient, r, 0x008);
    EXPECT_OFFSET_EQ(B_AuraGradient, g, 0x00C);
    EXPECT_OFFSET_EQ(B_AuraGradient, b, 0x010);
    EXPECT_OFFSET_EQ(B_AuraGradient, alpha, 0x014);
    EXPECT_OFFSET_EQ(B_AuraGradient, dR, 0x01C);
    EXPECT_OFFSET_EQ(B_AuraGradient, dG, 0x020);
    EXPECT_OFFSET_EQ(B_AuraGradient, dB, 0x024);
    EXPECT_OFFSET_EQ(B_AuraGradient, dAlpha, 0x028);
}
