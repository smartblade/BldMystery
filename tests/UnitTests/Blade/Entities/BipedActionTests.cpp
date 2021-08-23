#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Entities/BipedEntity.h>


TEST(BipedActionTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_BipedAction), 0x38);
}

TEST(BipedActionTests, Fields)
{
    EXPECT_OFFSET_EQ(B_BipedAction, eventTable, 0x034);
}
