#pragma once

#include <map>
#include <string>
#include <windows.h>
#include "Dumper.h"

std::map<LPVOID, std::string> ReadExportSymbols(
    HANDLE hProcess,
    char* baseAddr,
    Dumper &dumper);
