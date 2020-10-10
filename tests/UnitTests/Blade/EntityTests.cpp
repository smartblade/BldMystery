#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Entities/Entity.h>


TEST(EntityTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Entity, timerFunc, 0x044);
    EXPECT_OFFSET_EQ(B_Entity, frameFunc, 0x04C);
    EXPECT_OFFSET_EQ(B_Entity, hitFunc, 0x054);
    EXPECT_OFFSET_EQ(B_Entity, func084, 0x084);
    EXPECT_OFFSET_EQ(B_Entity, data, 0x158);
    EXPECT_OFFSET_EQ(B_Entity, sendSectorMsgs, 0x15C);
    EXPECT_OFFSET_EQ(B_Entity, sendTriggerSectorMsgs, 0x160);
}
