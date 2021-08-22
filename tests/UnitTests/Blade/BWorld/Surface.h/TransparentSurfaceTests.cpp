#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/Surface.h>


TEST(TransparentSurfaceTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_TransparentSurface), 0x114);
}

TEST(TransparentSurfaceTests, Fields)
{
    EXPECT_OFFSET_EQ(B_TransparentSurface, normal, 0x004);
    EXPECT_OFFSET_EQ(B_TransparentSurface, p, 0x01C);
    EXPECT_OFFSET_EQ(B_TransparentSurface, unknown024, 0x024);
    EXPECT_OFFSET_EQ(B_TransparentSurface, unknown028, 0x028);
    EXPECT_OFFSET_EQ(B_TransparentSurface, mapTexture, 0x02C);
    EXPECT_OFFSET_EQ(B_TransparentSurface, portal, 0x08C);
}
