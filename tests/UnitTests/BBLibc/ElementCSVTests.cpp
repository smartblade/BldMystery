#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <BBLibc/NDataBase.h>


TEST(ElementCSVTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ElementCSV), 0x18);
}

TEST(ElementCSVTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ElementCSV, name, 0x004);
    EXPECT_OFFSET_EQ(B_ElementCSV, mass, 0x00C);
    EXPECT_OFFSET_EQ(B_ElementCSV, material, 0x010);
}
