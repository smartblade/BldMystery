#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BInputc.h>


TEST(DInputKeybTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_DInputKeyb), 0x1048);
}
