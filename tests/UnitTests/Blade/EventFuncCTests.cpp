#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <EventFuncC.h>


TEST(EventFuncCTests, Fields)
{
    EXPECT_OFFSET_EQ(B_EventFuncC, func, 0x000C);
}
