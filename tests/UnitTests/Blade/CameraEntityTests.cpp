#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "entity.h"


TEST(CameraEntityTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_CameraEntity), 0x43C);
}

TEST(CameraEntityTests, Fields)
{
    EXPECT_OFFSET_EQ(B_CameraEntity, movements, 0x1A0);
    EXPECT_OFFSET_EQ(B_CameraEntity, unknownValueFromApplication, 0x3EC);
    EXPECT_OFFSET_EQ(B_CameraEntity, unknownPtrFromApplication, 0x3F0);
}