#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/Surface.h>


TEST(OpaqueSurfaceTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_OpaqueSurface), 0x98);
}

TEST(OpaqueSurfaceTests, Fields)
{
    EXPECT_OFFSET_EQ(B_OpaqueSurface, normal, 0x004);
    EXPECT_OFFSET_EQ(B_OpaqueSurface, p, 0x01C);
    EXPECT_OFFSET_EQ(B_OpaqueSurface, unknown024, 0x024);
    EXPECT_OFFSET_EQ(B_OpaqueSurface, unknown028, 0x028);
    EXPECT_OFFSET_EQ(B_OpaqueSurface, mapTexture, 0x02C);
    EXPECT_OFFSET_EQ(B_OpaqueSurface, polygon, 0x08C);
}
