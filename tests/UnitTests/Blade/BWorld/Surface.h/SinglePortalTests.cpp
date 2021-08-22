#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/Surface.h>


TEST(SinglePortalSurfaceTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_SinglePortalSurface), 0x138);
}

TEST(SinglePortalSurfaceTests, Fields)
{
    EXPECT_OFFSET_EQ(B_SinglePortalSurface, normal, 0x004);
    EXPECT_OFFSET_EQ(B_SinglePortalSurface, p, 0x01C);
    EXPECT_OFFSET_EQ(B_SinglePortalSurface, unknown024, 0x024);
    EXPECT_OFFSET_EQ(B_SinglePortalSurface, unknown028, 0x028);
    EXPECT_OFFSET_EQ(B_SinglePortalSurface, portal, 0x0A0);
    EXPECT_OFFSET_EQ(B_SinglePortalSurface, portalPlanes, 0x128);
}
