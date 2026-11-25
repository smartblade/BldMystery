#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Physics/ContactList.h>


TEST(ContactPointPoolTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ContactPointPool), 0x1C);
}

TEST(ContactPointPoolTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ContactPointPool, freeList, 0x018);
}
