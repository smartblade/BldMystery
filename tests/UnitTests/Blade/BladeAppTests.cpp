#include <gtest/gtest.h>
#include <bld_system.h>
#include "App.h"


TEST(BladeAppTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_BladeApp), 0x7D0);
}
