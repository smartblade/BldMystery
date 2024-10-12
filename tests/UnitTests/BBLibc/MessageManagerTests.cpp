#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <BBLibc/MessageManager.h>


TEST(MessageManagerTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_MessageManager), 0x0001);
}

TEST(MessageManagerTests, Fields)
{
    EXPECT_OFFSET_EQ(B_MessageManager, unknown00, 0x0000);
}
