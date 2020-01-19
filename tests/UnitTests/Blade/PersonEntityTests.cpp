#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "entity.h"


TEST(PersonEntityTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PersonEntity), 0x2080);
}
