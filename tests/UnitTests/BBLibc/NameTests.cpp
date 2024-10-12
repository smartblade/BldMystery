#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <BBLibc/Name.h>


TEST(NameTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_Name), 0x0008);
}

TEST(NameTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Name, string, 0x0000);
    EXPECT_OFFSET_EQ(B_Name, len, 0x0004);
}
