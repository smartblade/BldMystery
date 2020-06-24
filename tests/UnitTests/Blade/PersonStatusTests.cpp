#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include "simpleact.h"


TEST(PersonStatusTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PersonStatus), 0x0D4);
}
