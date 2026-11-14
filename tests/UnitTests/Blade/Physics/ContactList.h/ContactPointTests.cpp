#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Physics/ContactList.h>


TEST(ContactPointTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ContactPoint), 0x3C);
}

TEST(ContactPointTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ContactPoint, next, 0x000);
    EXPECT_OFFSET_EQ(B_ContactPoint, kind, 0x004);
    EXPECT_OFFSET_EQ(B_ContactPoint, source, 0x008);
    EXPECT_OFFSET_EQ(B_ContactPoint, position, 0x00C);
    EXPECT_OFFSET_EQ(B_ContactPoint, normal, 0x024);
}
