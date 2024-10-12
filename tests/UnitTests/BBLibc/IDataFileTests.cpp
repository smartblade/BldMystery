#include <gtest/gtest.h>
#include <Utils/FieldOffset.h>
#include <bld_system.h>
#define private public
#include <BBLibc/IDataFile.h>


TEST(IDataFileTests, SizeOf)
{
    EXPECT_EQ(sizeof(B_IDataFile), 0x4018);
}

TEST(IDataFileTests, Fields)
{
    EXPECT_OFFSET_EQ(B_IDataFile, fd, 0x0000);
    EXPECT_OFFSET_EQ(B_IDataFile, file_name, 0x0004);
    EXPECT_OFFSET_EQ(B_IDataFile, file_size, 0x0008);
    EXPECT_OFFSET_EQ(B_IDataFile, fileCache, 0x000C);
    EXPECT_OFFSET_EQ(B_IDataFile, cacheBlockBytesRead, 0x400C);
    EXPECT_OFFSET_EQ(B_IDataFile, cacheBlockPos, 0x4010);
    EXPECT_OFFSET_EQ(B_IDataFile, filePosition, 0x4014);
}
