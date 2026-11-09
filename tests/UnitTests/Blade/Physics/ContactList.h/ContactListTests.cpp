#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Physics/ContactList.h>


TEST(ContactListTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ContactList), 0x34);
}

TEST(ContactListTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ContactList, points, 0x000);
    EXPECT_OFFSET_EQ(B_ContactList, sectors, 0x018);
    EXPECT_OFFSET_EQ(B_ContactList, type, 0x030);
}
