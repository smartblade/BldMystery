#include "FileInfo.h"

std::string GetFilePath(HANDLE hFile)
{
    TCHAR wFilePath[MAX_PATH];
    auto pathSize = GetFinalPathNameByHandle(
        hFile,
        wFilePath,
        MAX_PATH,
        FILE_NAME_NORMALIZED);
    if (!pathSize || pathSize >= MAX_PATH)
    {
        printf("Failed to read file path\n");
        return std::string();
    }
    char filePath[MAX_PATH];
    sprintf_s(filePath, "%ws", wFilePath);
    return std::string(filePath);
}

std::string GetFileName(const std::string& filePath)
{
    char drive[_MAX_DRIVE];
    char dir[_MAX_DIR];
    char fname[_MAX_FNAME];
    char ext[_MAX_EXT];
    _splitpath_s(filePath.c_str(), drive, dir, fname, ext);
    return std::string(fname) + ext;
}

std::string GetDirectoryName(const std::string& filePath)
{
    char drive[_MAX_DRIVE];
    char dir[_MAX_DIR];
    char fname[_MAX_FNAME];
    char ext[_MAX_EXT];
    _splitpath_s(filePath.c_str(), drive, dir, fname, ext);
    return std::string(drive) + dir;
}

