#include "CallsWatcher.h"

#include "FileInfo.h"
#include "DllMetadata.h"
#include "ReadExportSymbols.h"

CallsWatcher::CallsWatcher(
    HANDLE hProcess, const std::string& dllMetadataFileName)
    : hProcess(hProcess), dllMetadata(dllMetadataFileName)
{
}

void CallsWatcher::OnDllLoaded(HANDLE hFile, LPVOID lpBase)
{
    AddWatchedDll(hFile, lpBase);
}

void CallsWatcher::OnProcessCreated(
    HANDLE hFile,
    LPVOID lpBase,
    LPVOID startAddress,
    DWORD threadId,
    HANDLE hThread)
{
    AddWatchedDll(hFile, lpBase);
    AddWatchedProcedure(hFile, startAddress, "__entry");
    threads[threadId] = hThread;
}

void CallsWatcher::OnThreadCreated(DWORD threadId, HANDLE hThread)
{
    threads[threadId] = hThread;
}

void CallsWatcher::OnBreakpoint(LPVOID address, DWORD threadId)
{
    if (procedures.find(address) != procedures.end())
    {
        printf("%s\n", procedures[address].c_str());
    }
    auto hThread = threads[threadId];
    CONTEXT lcContext;
    lcContext.ContextFlags = CONTEXT_ALL;
    GetThreadContext(hThread, &lcContext);
    // Set trap flag, which raises "single-step" exception
    lcContext.EFlags |= 0x100;
    if (DisableBreakpoint(address))
    {
        lcContext.Eip--;
    }
    SetThreadContext(hThread, &lcContext);
    BYTE byte[10];
    ReadProcessMemory(
        hProcess,
        address,
        &byte, sizeof(byte), nullptr);
    for (int i = 0; i < sizeof(byte); i++)
    {
        printf("%02X", byte[i]);
    }
    printf("\n");
    printf("eip: %X\n", lcContext.Eip);
}

void CallsWatcher::OnSingleStep(LPVOID address, DWORD threadId)
{
    BYTE bytes[10];
    ReadProcessMemory(
        hProcess,
        address,
        &bytes, sizeof(bytes), nullptr);
    for (int i = 0; i < sizeof(bytes); i++)
    {
        printf("%02X", bytes[i]);
    }
    printf("\n");
    auto hThread = threads[threadId];
    CONTEXT lcContext;
    lcContext.ContextFlags = CONTEXT_ALL;
    GetThreadContext(hThread, &lcContext);
    printf("eip: %X\n", lcContext.Eip);
    if (lcContext.Eip != (DWORD)address)
    {
        // Looks like task switch
        printf("Eip != ExceptionAddress\n");
        ReadProcessMemory(
            hProcess,
            (LPVOID)lcContext.Eip,
            &bytes, sizeof(bytes), nullptr);
        for (int i = 0; i < sizeof(bytes); i++)
        {
            printf("%02X", bytes[i]);
        }
        printf("\n");
    }
    EnableAllBreakpoints();
}

std::string CallsWatcher::FindDll(LPVOID address)
{
    auto dllIter = dlls.upper_bound(address);
    if (dllIter == dlls.begin())
        return std::string();
    dllIter--;
    return dllIter->second;
}

void CallsWatcher::AddWatchedDll(HANDLE hFile, LPVOID lpBase)
{
    auto symbols = ReadExportSymbols(
        hProcess,
        (char*)lpBase);
    std::vector<std::string> symbolNames;
    for (auto& symbol : symbols) {
        auto& name = symbol.second;
        symbolNames.push_back(name);
    }
    auto filePath = GetFilePath(hFile);
    auto dllName = GetFileName(filePath);
    dllMetadata.AddDllInfo(dllName, symbolNames);
    auto& dllInfo = dllMetadata.GetDll(dllName);
    for (auto& symbol : symbols)
    {
        auto& address = symbol.first;
        auto& symbolName = symbol.second;
        auto& symbol = dllInfo.GetSymbol(symbolName);
        if (symbol.IsWatched())
        {
            AddWatchedProcedure(hFile, address, symbolName);
        }
    }
    this->dlls[lpBase] = dllName;
}

void CallsWatcher::AddWatchedProcedure(
    HANDLE hFile,
    LPVOID procAddress,
    const std::string &procName)
{
    auto filePath = GetFilePath(hFile);
    auto dllName = GetFileName(filePath);
    procedures[procAddress] = dllName + "!" + procName;
    SetBreakpoint(procAddress);
}

void CallsWatcher::EnableAllBreakpoints()
{
    while (!disabledBreakpoints.empty())
    {
        SetBreakpoint(disabledBreakpoints.back());
        disabledBreakpoints.pop_back();
    }
}

bool CallsWatcher::DisableBreakpoint(LPVOID address)
{
    auto savedByteIter = savedBytes.find(address);
    if (savedByteIter == savedBytes.end())
        return false;
    BYTE savedByte = savedByteIter->second;
    WriteProcessMemory(hProcess,  address, &savedByte, 1, nullptr);
    FlushInstructionCache(hProcess, address, 1);
    disabledBreakpoints.push_back(address);
    return true;
}

void CallsWatcher::SetBreakpoint(LPVOID address)
{
    BYTE debugIstruction = 0xCC;
    BYTE savedByte;
    ReadProcessMemory(hProcess, address, &savedByte, 1, nullptr);
    /* There is already breakpoint */
    if (savedByte == debugIstruction)
        return;
    savedBytes[address] = savedByte;
    WriteProcessMemory(hProcess, address, &debugIstruction, 1, nullptr);
    FlushInstructionCache(hProcess, address, 1);
}