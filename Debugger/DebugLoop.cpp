#include "DebugLoop.h"
#include <windows.h>
#include <string>
#include "CallsWatcher.h"
#include "FileInfo.h"


void PrintLoadedFileMessage(HANDLE hFile, LPVOID lpBase)
{
    auto filePath = GetFilePath(hFile);
    printf("Loaded %s at %p\n", filePath.c_str(), lpBase);
}

void PrintException(
    const char* excName,
    const std::string &dllName,
    LPEXCEPTION_DEBUG_INFO exception)
{
    if (!exception->dwFirstChance)
    {
        ExitProcess(exception->ExceptionRecord.ExceptionCode);
    }
    printf(
        "First chance %s at %s!%p, exception-code: 0x%08x\n",
        excName ? excName : "exception",
        dllName.c_str(),
        exception->ExceptionRecord.ExceptionAddress,
        exception->ExceptionRecord.ExceptionCode);
}

DWORD OnExceptionDebugEvent(
    CallsWatcher& callsWatcher,
    const LPDEBUG_EVENT debugEv)
{
    auto dllName = callsWatcher.FindDll(
        debugEv->u.Exception.ExceptionRecord.ExceptionAddress);
    switch (debugEv->u.Exception.ExceptionRecord.ExceptionCode)
    {
    case EXCEPTION_ACCESS_VIOLATION:
        // First chance: Pass this on to the system.
        // Last chance: Display an appropriate error.
        PrintException(
            "AccessViolationException", dllName, &debugEv->u.Exception);
        return DBG_EXCEPTION_NOT_HANDLED;
    case EXCEPTION_BREAKPOINT:
        // First chance: Display the current
        // instruction and register values.
        printf(
            "Breakpoint at %p (Thread %d)\n",
            debugEv->u.Exception.ExceptionRecord.ExceptionAddress,
            debugEv->dwThreadId);
        callsWatcher.OnBreakpoint(
            debugEv->u.Exception.ExceptionRecord.ExceptionAddress,
            debugEv->dwThreadId);
        break;
    case EXCEPTION_DATATYPE_MISALIGNMENT:
        // First chance: Pass this on to the system.
        // Last chance: Display an appropriate error.
        PrintException(
            "DataTypeMisalignmentException", dllName, &debugEv->u.Exception);
        return DBG_EXCEPTION_NOT_HANDLED;
    case EXCEPTION_SINGLE_STEP:
    {
        // First chance: Update the display of the
        // current instruction and register values.
        printf(
            "Single step at %p (Thread %d)\n",
            debugEv->u.Exception.ExceptionRecord.ExceptionAddress,
            debugEv->dwThreadId);
        callsWatcher.OnSingleStep(
            debugEv->u.Exception.ExceptionRecord.ExceptionAddress,
            debugEv->dwThreadId);
        break;
    }
    case DBG_CONTROL_C:
        // First chance: Pass this on to the system.
        // Last chance: Display an appropriate error.
        PrintException("ControlCException", dllName, &debugEv->u.Exception);
        return DBG_EXCEPTION_NOT_HANDLED;
    default:
        // Handle other exceptions.
        PrintException(nullptr, dllName, &debugEv->u.Exception);
        return DBG_EXCEPTION_NOT_HANDLED;
    }
    return DBG_CONTINUE;
}

DWORD OnCreateThreadDebugEvent(
    CallsWatcher& callsWatcher,
    const LPDEBUG_EVENT debugEv)
{
    printf(
        "Thread 0x%p (Id: %d) created at: 0x%p\n",
        debugEv->u.CreateThread.hThread,
        debugEv->dwThreadId,
        debugEv->u.CreateThread.lpStartAddress);
    callsWatcher.OnThreadCreated(
        debugEv->dwThreadId,
        debugEv->u.CreateThread.hThread);
    return DBG_CONTINUE;
}

DWORD OnCreateProcessDebugEvent(
    CallsWatcher& callsWatcher,
    const LPDEBUG_EVENT debugEv)
{
    printf("Start address: %p ", debugEv->u.CreateProcessInfo.lpStartAddress);
    PrintLoadedFileMessage(
        debugEv->u.CreateProcessInfo.hFile,
        debugEv->u.CreateProcessInfo.lpBaseOfImage);
    callsWatcher.OnProcessCreated(
        debugEv->u.CreateProcessInfo.hFile,
        debugEv->u.CreateProcessInfo.lpBaseOfImage,
        debugEv->u.CreateProcessInfo.lpStartAddress,
        debugEv->dwThreadId,
        debugEv->u.CreateProcessInfo.hThread);
    return DBG_CONTINUE;
}

DWORD OnExitThreadDebugEvent(const LPDEBUG_EVENT debugEv)
{
    printf(
        "The thread %d exited with code: %d\n",
        debugEv->dwThreadId,
        debugEv->u.ExitThread.dwExitCode);
    return DBG_CONTINUE;
}

DWORD OnExitProcessDebugEvent(const LPDEBUG_EVENT debugEv)
{
    printf(
        "Process exited with code: %d\n",
        debugEv->u.ExitProcess.dwExitCode);
    ExitProcess(0);
    return DBG_CONTINUE;
}

DWORD OnLoadDllDebugEvent(
    CallsWatcher& callsWatcher,
    const LPDEBUG_EVENT debugEv)
{
    printf("%d:", debugEv->dwThreadId);
    PrintLoadedFileMessage(
        debugEv->u.LoadDll.hFile,
        debugEv->u.LoadDll.lpBaseOfDll);
    callsWatcher.OnDllLoaded(
        debugEv->u.LoadDll.hFile,
        debugEv->u.LoadDll.lpBaseOfDll);
    return DBG_CONTINUE;
}

DWORD OnUnloadDllDebugEvent(const LPDEBUG_EVENT debugEv)
{
    printf(
        "Unloaded at %p\n",
        debugEv->u.UnloadDll.lpBaseOfDll);
    return DBG_CONTINUE;
}

DWORD OnOutputDebugStringEvent(const LPDEBUG_EVENT debugEv)
{
    printf("OUTPUT_DEBUG_STRING_EVENT\n");
    return DBG_CONTINUE;
}

DWORD OnRipEvent(const LPDEBUG_EVENT debugEv)
{
    printf("RIP_EVENT\n");
    return DBG_CONTINUE;
}

void EnterDebugLoop(
    LPPROCESS_INFORMATION lpProcessInfo,
    const std::string& dllMetadataFileName)
{
    DEBUG_EVENT debugEv;
    ZeroMemory(&debugEv, sizeof(debugEv));
    CallsWatcher callsWatcher(lpProcessInfo->hProcess, dllMetadataFileName);
    DWORD dwContinueStatus = DBG_CONTINUE; // exception continuation
    for (;;)
    {
        // Wait for a debugging event to occur. The second parameter indicates
        // that the function does not return until a debugging event occurs.
        if (!WaitForDebugEvent(&debugEv, INFINITE))
            return;
        // Process the debugging event code.
        switch (debugEv.dwDebugEventCode)
        {
        case EXCEPTION_DEBUG_EVENT:
            // Process the exception code. When handling
            // exceptions, remember to set the continuation
            // status parameter (dwContinueStatus). This value
            // is used by the ContinueDebugEvent function.
            dwContinueStatus = OnExceptionDebugEvent(callsWatcher, &debugEv);
            break;
        case CREATE_THREAD_DEBUG_EVENT:
            // As needed, examine or change the thread's registers
            // with the GetThreadContext and SetThreadContext functions;
            // and suspend and resume thread execution with the
            // SuspendThread and ResumeThread functions.
            dwContinueStatus = OnCreateThreadDebugEvent(
                callsWatcher, &debugEv);
            break;
        case CREATE_PROCESS_DEBUG_EVENT:
            // As needed, examine or change the registers of the
            // process's initial thread with the GetThreadContext and
            // SetThreadContext functions; read from and write to the
            // process's virtual memory with the ReadProcessMemory and
            // WriteProcessMemory functions; and suspend and resume
            // thread execution with the SuspendThread and ResumeThread
            // functions. Be sure to close the handle to the process image
            // file with CloseHandle.
            dwContinueStatus = OnCreateProcessDebugEvent(
                callsWatcher, &debugEv);
            break;
        case EXIT_THREAD_DEBUG_EVENT:
            // Display the thread's exit code.
            dwContinueStatus = OnExitThreadDebugEvent(&debugEv);
            break;
        case EXIT_PROCESS_DEBUG_EVENT:
            // Display the process's exit code.
            dwContinueStatus = OnExitProcessDebugEvent(&debugEv);
            break;
        case LOAD_DLL_DEBUG_EVENT:
            // Read the debugging information included in the newly
            // loaded DLL. Be sure to close the handle to the loaded DLL
            // with CloseHandle.
            dwContinueStatus = OnLoadDllDebugEvent(callsWatcher, &debugEv);
            break;
        case UNLOAD_DLL_DEBUG_EVENT:
            // Display a message that the DLL has been unloaded.
            dwContinueStatus = OnUnloadDllDebugEvent(&debugEv);
            break;
        case OUTPUT_DEBUG_STRING_EVENT:
            // Display the output debugging string.
            dwContinueStatus = OnOutputDebugStringEvent(&debugEv);
            break;
        case RIP_EVENT:
            dwContinueStatus = OnRipEvent(&debugEv);
            break;
        }
        // Resume executing the thread that reported the debugging event.
        ContinueDebugEvent(debugEv.dwProcessId,
            debugEv.dwThreadId,
            dwContinueStatus);
    }
}
