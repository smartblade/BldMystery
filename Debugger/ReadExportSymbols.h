#pragma once

#include <map>
#include <string>
#include <windows.h>

std::map<LPVOID, std::string> ReadExportSymbols(
    HANDLE hProcess,
    char* baseAddr);
