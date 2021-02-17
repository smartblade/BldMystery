#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#include <App/App.h>


TEST(AfterFrameFuncTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_AfterFrameFunc), 0x18);
}

TEST(AfterFrameFuncTests, Fields)
{
    EXPECT_OFFSET_EQ(B_AfterFrameFunc, func, 0x00C);
    EXPECT_OFFSET_EQ(B_AfterFrameFunc, param, 0x010);
    EXPECT_OFFSET_EQ(B_AfterFrameFunc, removed, 0x014);
}
