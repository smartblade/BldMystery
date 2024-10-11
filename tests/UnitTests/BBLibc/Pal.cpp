#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <BBLibc/Pal.h>


TEST(PalTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_Pal), 0x0300);
}

TEST(PalTests, Fields)
{
    EXPECT_OFFSET_EQ(B_Pal, data, 0x0000);
}
