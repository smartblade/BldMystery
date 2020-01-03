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
    EXPECT_OFFSET_EQ(B_ParticleGType, unknown0024, 0x024);
    EXPECT_OFFSET_EQ(B_ParticleGType, unknown0028, 0x028);
}