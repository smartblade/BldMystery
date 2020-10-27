#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <Control/Events.h>


TEST(EventsTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Events, events, 0x0000);
    EXPECT_OFFSET_EQ(B_Events, events.elements, 0x0004);
    EXPECT_OFFSET_EQ(B_Events, events.size, 0x0008);
}
