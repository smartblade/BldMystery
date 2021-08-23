#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Entities/PersonEntity.h>


TEST(PersonEntityTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_PersonEntity), 0x2080);
}

TEST(PersonEntityTests, Fields)
{
    EXPECT_OFFSET_EQ(B_PersonEntity, data, 0x01A0);
    EXPECT_OFFSET_EQ(B_PersonEntity, unknown01AC, 0x01AC);
    EXPECT_OFFSET_EQ(B_PersonEntity, unknownFields01B0, 0x01B0);
    EXPECT_OFFSET_EQ(B_PersonEntity, per.unknownFields1224, 0x1224);
    EXPECT_OFFSET_EQ(B_PersonEntity, per.animName, 0x1274);
    EXPECT_OFFSET_EQ(B_PersonEntity, per.charType, 0x1B2C);
    EXPECT_OFFSET_EQ(B_PersonEntity, per.combos, 0x1B6C);
    EXPECT_OFFSET_EQ(B_PersonEntity, per.unknownFields1BD8, 0x1BD8);
    EXPECT_OFFSET_EQ(B_PersonEntity, per.status1, 0x1C10);
    EXPECT_OFFSET_EQ(B_PersonEntity, per.unknownFields1CE4, 0x1CE4);
    EXPECT_OFFSET_EQ(B_PersonEntity, unknownFields1DD4, 0x1DD4);
}
