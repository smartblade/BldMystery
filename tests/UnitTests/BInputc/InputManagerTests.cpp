#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BInputc.h>


TEST(InputManagerTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_InputManager), 0x40);
}
