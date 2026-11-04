#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/OctTree.h>


TEST(GlobalSurfaceCacheTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_GlobalSurfaceCache), 0x8804);
}

TEST(GlobalSurfaceCacheTests, Fields)
{
    EXPECT_OFFSET_EQ(B_GlobalSurfaceCache, count, 0x000);
    EXPECT_OFFSET_EQ(B_GlobalSurfaceCache, elements, 0x004);
}
