#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BBLibc/ObjDscr.h>


TEST(ObjDscrTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ObjDscr), 0x278);
}

TEST(ObjDscrTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ObjDscr, vertices, 0x024);
    EXPECT_OFFSET_EQ(B_ObjDscr, faces, 0x038);
    EXPECT_OFFSET_EQ(B_ObjDscr, nodes, 0x04C);
    EXPECT_OFFSET_EQ(B_ObjDscr, faceGroups, 0x064);
    EXPECT_OFFSET_EQ(B_ObjDscr, edges, 0x0BC);
    EXPECT_OFFSET_EQ(B_ObjDscr, inertia, 0x130);
    EXPECT_OFFSET_EQ(B_ObjDscr, unknownField1B0, 0x1B0);
    EXPECT_OFFSET_EQ(B_ObjDscr, area, 0x230);
    EXPECT_OFFSET_EQ(B_ObjDscr, mass, 0x238);
    EXPECT_OFFSET_EQ(B_ObjDscr, centerOfMass, 0x240);
    EXPECT_OFFSET_EQ(B_ObjDscr, boundingSphere, 0x258);
}
