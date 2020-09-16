#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include "AuraEntity.h"


TEST(AuraEntityTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_AuraEntity), 0x300);
}

TEST(AuraEntityTests, Fields)
{
    EXPECT_OFFSET_EQ(B_AuraEntity, gradients, 0x1BC);
}
