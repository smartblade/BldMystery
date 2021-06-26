#include "CallsWatcher.h"

#include "FileInfo.h"
#include "DllMetadata.h"
#include "ReadExportSymbols.h"

CallsWatcher::CallsWatcher(
    HANDLE hProcess,
    const std::string& dllMetadataFileName,
    Dumper &dumper)
    : hProcess(hProcess), dllMetadata(dllMetadataFileName), dumper(dumper)
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
    AddWatchedProcedure(hFile, startAddress, "__entry", false);
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
    dumper.Printf(
        Dumper::Level::Debug, "===========================================\n");
    DumpMemory(Dumper::Level::Debug, address);
    DumpRegisters(Dumper::Level::Debug, threadId, address);
    if (returnAddresses.find(address) != returnAddresses.end())
    {
        OnProcedureReturn(threadId, (LPVOID)lpContext.Esp);
    }
    else
    {
        OnProcedureStart(address, threadId, (LPVOID)lpContext.Esp);
    }
}

void CallsWatcher::OnProcedureStart(
    LPVOID address,
    DWORD threadId,
    LPVOID stackPointer)
{
    auto& stackFrames = stackFramesByThread[threadId];
    AdjustStackFrames(stackFrames, stackPointer);
    PushStackFrame(stackFrames, stackPointer, address);
    AddWatchedReturnAddress(stackFrames, address);
    if (IsInternalSystemCall(stackFrames))
    {
        dumper.Printf(Dumper::Level::Debug, "Internal system call\n");
        DumpProcedureName(Dumper::Level::Debug, stackFrames, address);
    }
    else
    {
        DumpProcedureName(Dumper::Level::Info, stackFrames, address);
    }
}

void CallsWatcher::OnProcedureReturn(DWORD threadId, LPVOID stackPointer)
{
    auto& stackFrames = stackFramesByThread[threadId];
    AdjustStackFrames(stackFrames, stackPointer);
}

void CallsWatcher::OnSingleStep(LPVOID address, DWORD threadId)
{
    DumpMemory(Dumper::Level::Debug, address);
    DumpRegisters(Dumper::Level::Debug, threadId, address);
    dumper.Printf(
        Dumper::Level::Debug, "===========================================\n");
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
        (char*)lpBase,
        dumper);
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
            AddWatchedProcedure(
                hFile, address, symbolName, dllInfo.IsSystem());
        }
    }
    this->dlls[lpBase] = dllName;
}

void CallsWatcher::AddWatchedProcedure(
    HANDLE hFile,
    LPVOID procAddress,
    const std::string &procName,
    bool isSystem)
{
    auto filePath = GetFilePath(hFile);
    auto dllName = GetFileName(filePath);
    procedures[procAddress] = Procedure(dllName, procName, isSystem);
    SetBreakpoint(procAddress);
}

void CallsWatcher::AddWatchedReturnAddress(
    std::vector<StackFrame>& stackFrames,
    LPVOID procAddress)
{
    if (stackFrames.empty())
        return;
    auto returnAddress = stackFrames.back().ReturnAddress();
    returnAddresses[returnAddress] = procAddress;
    SetBreakpoint(returnAddress);
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

void CallsWatcher::PushStackFrame(
    std::vector<StackFrame>& stackFrames,
    LPVOID curStackPointer,
    LPVOID startAddress)
{
    stackFrames.push_back(ReadStackFrame(curStackPointer, startAddress));
}

void CallsWatcher::AdjustStackFrames(
    std::vector<StackFrame>& stackFrames,
    LPVOID curStackPointer)
{
    while (!stackFrames.empty())
    {
        auto& frame = stackFrames.back();
        if (IsStackFrameValid(frame, curStackPointer))
            break;
        stackFrames.pop_back();
    }
}

StackFrame CallsWatcher::ReadStackFrame(
    LPVOID stackPointer, LPVOID startAddress)
{
    LPVOID returnAddress;
    ReadProcessMemory(
        hProcess,
        stackPointer,
        &returnAddress, sizeof(returnAddress), nullptr);
    dumper.Printf(Dumper::Level::Debug, "return addr: %p\n", returnAddress);
    return StackFrame(stackPointer, returnAddress, startAddress);
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

bool CallsWatcher::IsInternalSystemCall(std::vector<StackFrame>& stackFrames)
{
    if (stackFrames.size() < 1)
        return true;
    auto& curFrame = stackFrames[stackFrames.size() - 1];
    if (stackFrames.size() < 2)
    {
        return procedures[curFrame.StartAddress()].IsSystem();
    }
    auto& prevFrame = stackFrames[stackFrames.size() - 2];
    if (
        procedures[prevFrame.StartAddress()].IsSystem() &&
        procedures[curFrame.StartAddress()].IsSystem())
        return true;
    return false;
}

void CallsWatcher::DumpProcedureName(
    Dumper::Level level,
    std::vector<StackFrame>& stackFrames,
    LPVOID procAddress)
{
    auto procedureIter = procedures.find(procAddress);
    if (procedureIter == procedures.end())
        return;
    const auto& procedureName = procedureIter->second.FullName();
    for (unsigned int i = 0; i < stackFrames.size(); i++)
        dumper.Printf(level, " ");
    dumper.Printf(level, "%s\n", procedureName.c_str());
}

void CallsWatcher::DumpRegisters(Dumper::Level level, DWORD threadId, LPVOID address)
{
    auto hThreadIter = threads.find(threadId);
    if (hThreadIter == threads.end())
        return;
    auto hThread = hThreadIter->second;
    CONTEXT lpContext;
    lpContext.ContextFlags = CONTEXT_ALL;
    GetThreadContext(hThread, &lpContext);
    dumper.Printf(level, "eip: %X\n", lpContext.Eip);
    dumper.Printf(level, "esp: %X\n", lpContext.Esp);
    if (lpContext.Eip != (DWORD)address)
    {
        // Looks like task switch
        dumper.Printf(level, "Eip != ExceptionAddress\n");
        DumpMemory(level, (LPVOID)lpContext.Eip);
    }
}

void CallsWatcher::DumpMemory(Dumper::Level level, LPVOID address)
{
    dumper.Printf(level, "Memory: ");
    BYTE bytes[10];
    ReadProcessMemory(
        hProcess,
        address,
        &bytes, sizeof(bytes), nullptr);
    for (int i = 0; i < sizeof(bytes); i++)
    {
        dumper.Printf(level, "%02X", bytes[i]);
    }
    dumper.Printf(level, "\n");
}
