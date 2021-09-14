#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <BBLibc.h>


TEST(ParticleGTypeTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ParticleGType), 0x2C);
}

TEST(ParticleGTypeTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ParticleGType, a00C, 0x00C);
    EXPECT_OFFSET_EQ(B_ParticleGType, duration, 0x020);
    EXPECT_OFFSET_EQ(B_ParticleGType, bmpHandle, 0x024);
    EXPECT_OFFSET_EQ(B_ParticleGType, operation_type, 0x028);
}