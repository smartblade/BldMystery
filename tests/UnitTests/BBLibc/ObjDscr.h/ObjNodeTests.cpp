#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BBLibc/ObjDscr.h>


TEST(ObjNodeTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ObjNode), 0xAC);
}

TEST(ObjNodeTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ObjNode, parent, 0x00C);
    EXPECT_OFFSET_EQ(B_ObjNode, unknownField010, 0x010);
    EXPECT_OFFSET_EQ(B_ObjNode, vertexCount, 0x0A4);
    EXPECT_OFFSET_EQ(B_ObjNode, firstVertex, 0x0A8);
}
