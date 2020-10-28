#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Person/simpleact.h>


TEST(PersonStatusTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PersonStatus), 0x0D4);
}

TEST(PersonStatusTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PersonStatus, jumpActivated, 0x07C);
}
