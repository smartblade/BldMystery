#include <gtest/gtest.h>
#include <bld_system.h>
#include "entity.h"


TEST(CameraEntityTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_CameraEntity), 0x43C);
}
