#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Person/simpleact.h>


TEST(PersonStatusTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PersonStatus), 0x0D4);
}

TEST(PersonStatusTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PersonStatus, jumpActivated, 0x07C);
    EXPECT_OFFSET_EQ(B_PersonStatus, unknown84, 0x084);
    EXPECT_OFFSET_EQ(B_PersonStatus, unknown8C, 0x08C);
    EXPECT_OFFSET_EQ(B_PersonStatus, unknown94, 0x094);
    EXPECT_OFFSET_EQ(B_PersonStatus, unknown9C, 0x09C);
    EXPECT_OFFSET_EQ(B_PersonStatus, unknownA4, 0x0A4);
    EXPECT_OFFSET_EQ(B_PersonStatus, unknownAC, 0x0AC);
    EXPECT_OFFSET_EQ(B_PersonStatus, unknownB4, 0x0B4);
}
