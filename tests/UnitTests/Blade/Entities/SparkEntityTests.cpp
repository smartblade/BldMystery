#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <Entities/SparkEntity.h>


TEST(SparkEntityTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_SparkEntity), 0x288);
}
