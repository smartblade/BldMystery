#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/OctTree.h>


TEST(SectorSurfaceCacheTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_SectorSurfaceCache), 0x110);
}

TEST(SectorSurfaceCacheTests, Fields)
{
    EXPECT_OFFSET_EQ(B_SectorSurfaceCache, sector, 0x004);
    EXPECT_OFFSET_EQ(B_SectorSurfaceCache, numSurfaces, 0x008);
    EXPECT_OFFSET_EQ(B_SectorSurfaceCache, surfaces, 0x00C);
    EXPECT_OFFSET_EQ(B_SectorSurfaceCache, hasNoIntersections, 0x10C);
}
