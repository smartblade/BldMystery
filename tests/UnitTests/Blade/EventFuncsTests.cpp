#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <Control/Events.h>


TEST(EventFuncsTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_EventFuncs), 0x20);
}

TEST(EventFuncsTests, Fields)
{
    EXPECT_OFFSET_EQ(B_EventFuncs, eventFuncs, 0x000C);
    EXPECT_OFFSET_EQ(B_EventFuncs, eventFuncs.elements, 0x0010);
    EXPECT_OFFSET_EQ(B_EventFuncs, eventFuncs.size, 0x0014);
}
