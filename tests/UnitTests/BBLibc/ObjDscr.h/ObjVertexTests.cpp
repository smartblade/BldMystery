#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BBLibc/ObjDscr.h>


TEST(ObjVertexTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ObjVertex), 0x30);
}

TEST(ObjVertexTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ObjVertex, position, 0x000);
    EXPECT_OFFSET_EQ(B_ObjVertex, normal, 0x018);
}
