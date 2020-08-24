#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/Surface.h>


TEST(DomeSurfaceTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_DomeSurface), 0x38);
}

TEST(DomeSurfaceTests, Fields)
{
    EXPECT_OFFSET_EQ(B_DomeSurface, normal, 0x004);
    EXPECT_OFFSET_EQ(B_DomeSurface, p, 0x01C);
    EXPECT_OFFSET_EQ(B_DomeSurface, unknown024, 0x024);
    EXPECT_OFFSET_EQ(B_DomeSurface, unknown028, 0x028);
    EXPECT_OFFSET_EQ(B_DomeSurface, polygon, 0x02C);
}
