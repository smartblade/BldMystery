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
    auto hThread = threads[threadId];
    CONTEXT lpContext;
    lpContext.ContextFlags = CONTEXT_ALL;
    GetThreadContext(hThread, &lpContext);
    if (DisableBreakpoint(address))
    {
        lpContext.Eip--;
        // Set trap flag, which raises "single-step" exception
        lpContext.EFlags |= 0x100;
    }
    SetThreadContext(hThread, &lpContext);
    if (verbose)
    {
        printf("===========================================\n");
        DumpMemory(address);
        DumpRegisters(threadId, address);
    }
    AdjustStackFrames((LPVOID)lpContext.Esp);
    DumpProcedureName(address);
}

void CallsWatcher::OnSingleStep(LPVOID address, DWORD threadId)
{
    if (verbose)
    {
        DumpMemory(address);
        DumpRegisters(threadId, address);
        printf("===========================================\n");
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

void CallsWatcher::AdjustStackFrames(LPVOID curStackPointer)
{
    while (!stackFrames.empty())
    {
        auto& frame = stackFrames.back();
        if (IsStackFrameValid(frame, curStackPointer))
            break;
        stackFrames.pop_back();
    }
    stackFrames.push_back(ReadStackFrame(curStackPointer));
}

StackFrame CallsWatcher::ReadStackFrame(LPVOID stackPointer)
{
    LPVOID returnAddress;
    ReadProcessMemory(
        hProcess,
        stackPointer,
        &returnAddress, sizeof(returnAddress), nullptr);
    if (verbose)
    {
        printf("return addr: %p\n", returnAddress);
    }
    return StackFrame(stackPointer, returnAddress);
}

bool CallsWatcher::IsStackFrameValid(StackFrame& frame, LPVOID curStackPointer)
{
    if (curStackPointer >= frame.StackPointer())
        return false;
    LPVOID newReturnAddress;
    ReadProcessMemory(
        hProcess,
        frame.StackPointer(),
        &newReturnAddress, sizeof(newReturnAddress), nullptr);
    if (newReturnAddress != frame.ReturnAddress())
        return false;
    return true;;
}

void CallsWatcher::DumpProcedureName(LPVOID procAddress)
{
    auto procedureIter = procedures.find(procAddress);
    if (procedureIter == procedures.end())
        return;
    auto &procedureName = procedureIter->second;
    for (unsigned int i = 0; i < stackFrames.size(); i++)
        printf(" ");
    printf("%s\n", procedureName.c_str());
}

void CallsWatcher::DumpRegisters(DWORD threadId, LPVOID address)
{
    auto hThreadIter = threads.find(threadId);
    if (hThreadIter == threads.end())
        return;
    auto hThread = hThreadIter->second;
    CONTEXT lpContext;
    lpContext.ContextFlags = CONTEXT_ALL;
    GetThreadContext(hThread, &lpContext);
    printf("eip: %X\n", lpContext.Eip);
    printf("esp: %X\n", lpContext.Esp);
    if (lpContext.Eip != (DWORD)address)
    {
        // Looks like task switch
        printf("Eip != ExceptionAddress\n");
        DumpMemory((LPVOID)lpContext.Eip);
    }
}

void CallsWatcher::DumpMemory(LPVOID address)
{
    printf("Memory: ");
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
}
