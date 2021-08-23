#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Entities/CameraEntity.h>


TEST(CameraMovementTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_CameraMovement), 0x24);
}

TEST(CameraMovementTests, Fields)
{
    EXPECT_OFFSET_EQ(B_CameraMovement, angle, 0x00C);
    EXPECT_OFFSET_EQ(B_CameraMovement, start_pos, 0x014);
    EXPECT_OFFSET_EQ(B_CameraMovement, end_pos, 0x01C);
}
