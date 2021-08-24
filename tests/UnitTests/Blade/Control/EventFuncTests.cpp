#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Control/Events.h>


TEST(EventFuncTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_EventFunc), 0xC);
}

TEST(EventFuncTests, Fields)
{
    EXPECT_OFFSET_EQ(B_EventFunc, pyFunc, 0x0000);
    EXPECT_OFFSET_EQ(B_EventFunc, func, 0x0004);
    EXPECT_OFFSET_EQ(B_EventFunc, name, 0x0008);
}
