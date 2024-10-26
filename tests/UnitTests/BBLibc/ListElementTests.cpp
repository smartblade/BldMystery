#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <BBLibc/List.h>


TEST(ListElementTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ListElement), 0x0010);
}

TEST(ListElementTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ListElement, list, 0x0004);
    EXPECT_OFFSET_EQ(B_ListElement, next, 0x0008);
    EXPECT_OFFSET_EQ(B_ListElement, member3, 0x000C);
}
