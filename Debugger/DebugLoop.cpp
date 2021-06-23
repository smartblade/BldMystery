#include "DebugLoop.h"
#include <windows.h>
#include <string>
#include "CallsWatcher.h"
#include "Dumper.h"
#include "FileInfo.h"


void PrintLoadedFileMessage(Dumper& dumper, HANDLE hFile, LPVOID lpBase)
{
    auto filePath = GetFilePath(hFile);
    dumper.Printf(
        Dumper::Level::Debug,
        "Loaded %s at %p\n",
        filePath.c_str(), lpBase);
}

void PrintException(
    Dumper& dumper,
    const char* excName,
    const std::string &dllName,
    LPEXCEPTION_DEBUG_INFO exception)
{
    if (!exception->dwFirstChance)
    {
        ExitProcess(exception->ExceptionRecord.ExceptionCode);
    }
    dumper.Printf(
        Dumper::Level::Debug,
        "First chance %s at %s!%p, exception-code: 0x%08x\n",
        excName ? excName : "exception",
        dllName.c_str(),
        exception->ExceptionRecord.ExceptionAddress,
        exception->ExceptionRecord.ExceptionCode);
}

DWORD OnExceptionDebugEvent(
    Dumper& dumper,
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
            dumper,
            "AccessViolationException",
            dllName,
            &debugEv->u.Exception);
        return DBG_EXCEPTION_NOT_HANDLED;
    case EXCEPTION_BREAKPOINT:
        // First chance: Display the current
        // instruction and register values.
        dumper.Printf(
            Dumper::Level::Debug,
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
            dumper,
            "DataTypeMisalignmentException",
            dllName,
            &debugEv->u.Exception);
        return DBG_EXCEPTION_NOT_HANDLED;
    case EXCEPTION_SINGLE_STEP:
    {
        // First chance: Update the display of the
        // current instruction and register values.
        dumper.Printf(
            Dumper::Level::Debug,
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
        PrintException(
            dumper,
            "ControlCException",
            dllName,
            &debugEv->u.Exception);
        return DBG_EXCEPTION_NOT_HANDLED;
    default:
        // Handle other exceptions.
        PrintException(dumper, nullptr, dllName, &debugEv->u.Exception);
        return DBG_EXCEPTION_NOT_HANDLED;
    }
    return DBG_CONTINUE;
}

DWORD OnCreateThreadDebugEvent(
    Dumper& dumper,
    CallsWatcher& callsWatcher,
    const LPDEBUG_EVENT debugEv)
{
    dumper.Printf(
        Dumper::Level::Debug,
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
    Dumper& dumper,
    CallsWatcher& callsWatcher,
    const LPDEBUG_EVENT debugEv)
{
    dumper.Printf(
        Dumper::Level::Debug,
        "Start address: %p ",
        debugEv->u.CreateProcessInfo.lpStartAddress);
    PrintLoadedFileMessage(
        dumper,
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

DWORD OnExitThreadDebugEvent(Dumper& dumper, const LPDEBUG_EVENT debugEv)
{
    dumper.Printf(
        Dumper::Level::Debug,
        "The thread %d exited with code: %d\n",
        debugEv->dwThreadId,
        debugEv->u.ExitThread.dwExitCode);
    return DBG_CONTINUE;
}

DWORD OnExitProcessDebugEvent(Dumper& dumper, const LPDEBUG_EVENT debugEv)
{
    dumper.Printf(
        Dumper::Level::Debug,
        "Process exited with code: %d\n",
        debugEv->u.ExitProcess.dwExitCode);
    ExitProcess(0);
    return DBG_CONTINUE;
}

DWORD OnLoadDllDebugEvent(
    Dumper& dumper,
    CallsWatcher& callsWatcher,
    const LPDEBUG_EVENT debugEv)
{
    dumper.Printf(Dumper::Level::Debug, "%d:", debugEv->dwThreadId);
    PrintLoadedFileMessage(
        dumper,
        debugEv->u.LoadDll.hFile,
        debugEv->u.LoadDll.lpBaseOfDll);
    callsWatcher.OnDllLoaded(
        debugEv->u.LoadDll.hFile,
        debugEv->u.LoadDll.lpBaseOfDll);
    return DBG_CONTINUE;
}

DWORD OnUnloadDllDebugEvent(Dumper& dumper, const LPDEBUG_EVENT debugEv)
{
    dumper.Printf(
        Dumper::Level::Debug,
        "Unloaded at %p\n",
        debugEv->u.UnloadDll.lpBaseOfDll);
    return DBG_CONTINUE;
}

DWORD OnOutputDebugStringEvent(Dumper& dumper, const LPDEBUG_EVENT debugEv)
{
    dumper.Printf(Dumper::Level::Debug, "OUTPUT_DEBUG_STRING_EVENT\n");
    return DBG_CONTINUE;
}

DWORD OnRipEvent(Dumper &dumper, const LPDEBUG_EVENT debugEv)
{
    dumper.Printf(Dumper::Level::Debug, "RIP_EVENT\n");
    return DBG_CONTINUE;
}

void EnterDebugLoop(
    LPPROCESS_INFORMATION lpProcessInfo,
    const std::string& dllMetadataFileName,
    bool verbose)
{
    DEBUG_EVENT debugEv;
    ZeroMemory(&debugEv, sizeof(debugEv));
    Dumper dumper(verbose ? Dumper::Level::Debug : Dumper::Level::Info);
    CallsWatcher callsWatcher(
        lpProcessInfo->hProcess,
        dllMetadataFileName,
        dumper);
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
            dwContinueStatus = OnExceptionDebugEvent(
                dumper, callsWatcher, &debugEv);
            break;
        case CREATE_THREAD_DEBUG_EVENT:
            // As needed, examine or change the thread's registers
            // with the GetThreadContext and SetThreadContext functions;
            // and suspend and resume thread execution with the
            // SuspendThread and ResumeThread functions.
            dwContinueStatus = OnCreateThreadDebugEvent(
                dumper, callsWatcher, &debugEv);
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
                dumper, callsWatcher, &debugEv);
            break;
        case EXIT_THREAD_DEBUG_EVENT:
            // Display the thread's exit code.
            dwContinueStatus = OnExitThreadDebugEvent(dumper , &debugEv);
            break;
        case EXIT_PROCESS_DEBUG_EVENT:
            // Display the process's exit code.
            dwContinueStatus = OnExitProcessDebugEvent(dumper , &debugEv);
            break;
        case LOAD_DLL_DEBUG_EVENT:
            // Read the debugging information included in the newly
            // loaded DLL. Be sure to close the handle to the loaded DLL
            // with CloseHandle.
            dwContinueStatus = OnLoadDllDebugEvent(
                dumper, callsWatcher, &debugEv);
            break;
        case UNLOAD_DLL_DEBUG_EVENT:
            // Display a message that the DLL has been unloaded.
            dwContinueStatus = OnUnloadDllDebugEvent(dumper , &debugEv);
            break;
        case OUTPUT_DEBUG_STRING_EVENT:
            // Display the output debugging string.
            dwContinueStatus = OnOutputDebugStringEvent(dumper , &debugEv);
            break;
        case RIP_EVENT:
            dwContinueStatus = OnRipEvent(dumper , &debugEv);
            break;
        }
        // Resume executing the thread that reported the debugging event.
        ContinueDebugEvent(debugEv.dwProcessId,
            debugEv.dwThreadId,
            dwContinueStatus);
    }
}
