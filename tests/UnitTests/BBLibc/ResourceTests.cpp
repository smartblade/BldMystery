#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BBLibc/Resource.h>


TEST(ResourceTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Resource, data, 0x00C);
}
