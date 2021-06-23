#pragma once

#include <string>
#include <windows.h>

void EnterDebugLoop(
    LPPROCESS_INFORMATION lpProcessInfo,
    const std::string& dllMetadataFileName,
    bool verbose);

