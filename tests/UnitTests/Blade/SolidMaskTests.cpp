#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Entities/SolidMask.h>


TEST(SolidMaskTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_SolidMask), 0x10);
}

TEST(SolidMaskTests, Fields)
{
    EXPECT_OFFSET_EQ(B_SolidMask, mask, 0x0C);
}
