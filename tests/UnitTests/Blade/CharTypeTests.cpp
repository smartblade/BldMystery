#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <chartype.h>


TEST(CharTypeTests, Fields)
{
    EXPECT_OFFSET_EQ(B_CharType, biped, 0x1A64);
}
