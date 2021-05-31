#pragma once

#include <string>
#include <windows.h>

std::string GetFilePath(HANDLE hFile);
std::string GetFileName(const std::string& filePath);
std::string GetDirectoryName(const std::string& filePath);
