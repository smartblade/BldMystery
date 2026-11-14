#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Physics/SphereSetTemplate.h>


TEST(SphereSetTemplateTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_SphereSetTemplate), 0x11C);
}

TEST(SphereSetTemplateTests, Fields)
{
    EXPECT_OFFSET_EQ(B_SphereSetTemplate, pose, 0x068);
    EXPECT_OFFSET_EQ(B_SphereSetTemplate, boundingBox, 0x0E8);
    EXPECT_OFFSET_EQ(B_SphereSetTemplate, spheres, 0x118);
}
