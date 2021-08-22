#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BWorld/Surface.h>


TEST(PortalPlanesTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PortalPlanes, unknown000, 0x000);
    EXPECT_OFFSET_EQ(B_PortalPlanes, numPlanes, 0x004);
    EXPECT_OFFSET_EQ(B_PortalPlanes, planes, 0x008);
    EXPECT_OFFSET_EQ(B_PortalPlanes, unknown00C, 0x00C);
}
