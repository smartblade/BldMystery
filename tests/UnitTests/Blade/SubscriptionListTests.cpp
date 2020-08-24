#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/BWorld.h>


TEST(SubscriptionListTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_SubscriptionList), 0x24);
}

TEST(SubscriptionListTests, Fields)
{
    EXPECT_OFFSET_EQ(B_SubscriptionList, elements, 0x004);
    EXPECT_OFFSET_EQ(B_SubscriptionList, size, 0x008);
    EXPECT_OFFSET_EQ(B_SubscriptionList, name, 0x01C);
}
