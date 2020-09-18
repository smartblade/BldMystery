#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include "ObjectEntity.h"


TEST(ObjectEntityTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_ObjectEntity), 0x1C0);
}
