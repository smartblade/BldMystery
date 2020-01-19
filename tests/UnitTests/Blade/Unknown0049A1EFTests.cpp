#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "entity.h"


TEST(Unknown0049A1EFTests, Fields)
{
    EXPECT_OFFSET_EQ(Unknown0049A1EF, transform, 0x024);
}
