#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Control/Events.h>


TEST(EventTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_Event), 0x10);
}

TEST(EventTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Event, index, 0x000C);
}