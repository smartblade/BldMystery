#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BBLibc/RDataTriangle.h>


TEST(RItemTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_RItem), 0x04);
}

TEST(RItemTests, Fields)
{
    EXPECT_OFFSET_EQ(B_RItem, type, 0x000);
}
