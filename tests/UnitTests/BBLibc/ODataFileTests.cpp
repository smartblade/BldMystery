#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <BBLibc/ODataFile.h>


TEST(ODataFileTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ODataFile), 0x4010);
}

TEST(ODataFileTests, Fields)
{
    EXPECT_OFFSET_EQ(B_ODataFile, fd, 0x0000);
    EXPECT_OFFSET_EQ(B_ODataFile, file_name, 0x0004);
    EXPECT_OFFSET_EQ(B_ODataFile, unknown_fields, 0x0008);
}
