#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BBLibc/ObjDscr.h>


TEST(ObjFaceTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ObjFace), 0x38);
}

TEST(ObjFaceTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ObjFace, vertices, 0x000);
    EXPECT_OFFSET_EQ(B_ObjFace, edges, 0x00C);
    EXPECT_OFFSET_EQ(B_ObjFace, unknownField034, 0x034);
}
