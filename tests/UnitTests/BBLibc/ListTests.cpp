#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <BBLibc/List.h>


TEST(ListTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_List), 0x0010);
}

TEST(ListTests, Fields)
{
    EXPECT_OFFSET_EQ(B_List, numElements, 0x0004);
    EXPECT_OFFSET_EQ(B_List, tail, 0x0008);
    EXPECT_OFFSET_EQ(B_List, head, 0x000C);
}
