#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Entities/BipedEntity.h>


TEST(BipedDataTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_BipedData), 0xFC);
}

TEST(BipedDataTests, Fields)
{
    EXPECT_OFFSET_EQ(B_BipedData, actions, 0x030);
    EXPECT_OFFSET_EQ(B_BipedData, charType, 0x080);
}
