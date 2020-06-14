#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "entity.h"


TEST(BipedEntityTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_BipedEntity), 0x1224);
}
