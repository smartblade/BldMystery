#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <BBLibc/NamedObj.h>


TEST(NamedObjTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_NamedObj), 0x000C);
}

TEST(NamedObjTests, Fields)
{
    EXPECT_OFFSET_EQ(B_NamedObj, name, 0x0004);
}
