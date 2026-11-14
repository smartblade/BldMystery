#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BBLibc/Resource.h>


TEST(ResourceTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_Resource), 0x0C);
}
