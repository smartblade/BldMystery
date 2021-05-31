#include <windows.h>
#include <strsafe.h>
#include <tchar.h>
#include <string>
#include "DebugLoop.h"
#include "FileInfo.h"

void ErrorExit(LPTSTR lpszFunction)
{
    // Retrieve the system error message for the last-error code
    LPVOID lpMsgBuf;
    LPVOID lpDisplayBuf;
    DWORD dw = GetLastError();
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER |
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&lpMsgBuf,
        0, NULL);
    // Display the error message and exit the process
    lpDisplayBuf = (LPVOID)LocalAlloc(
        LMEM_ZEROINIT,
        (lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40)
        * sizeof(TCHAR));
    if (lpDisplayBuf == nullptr)
        return;
    StringCchPrintf((LPTSTR)lpDisplayBuf,
        LocalSize(lpDisplayBuf) / sizeof(TCHAR),
        TEXT("%s failed with error %d: %s"),
        lpszFunction, dw, (LPTSTR)lpMsgBuf);
    MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);
    LocalFree(lpMsgBuf);
    LocalFree(lpDisplayBuf);
    ExitProcess(dw);
}

std::wstring toWideChar(const std::string s)
{
    std::wstring ws(s.size() + 1, L'#');
    size_t numOfCharConverted;
    mbstowcs_s(&numOfCharConverted, &ws[0], ws.size(), s.c_str(), s.size());
    return ws;
}

int _tmain(int argc, LPTSTR* argv)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));
    if (argc < 2)
    {
        printf("Usage: %ws executable-name\n", argv[0]);
        return -1;
    }
    auto processName = argv[1];
    char sProcessPath[MAX_PATH];
    sprintf_s(sProcessPath, "%ws", processName);
    auto directoryName = toWideChar(GetDirectoryName(sProcessPath));
    printf("Starting %ws\n", processName);
    if (!CreateProcess(
        processName, NULL, NULL, NULL, FALSE,
        DEBUG_ONLY_THIS_PROCESS, NULL, directoryName.c_str(), &si, &pi))
    {
        printf("Failed to start %ws\n", processName);
        ErrorExit(processName);
        return -1;
    }
    EnterDebugLoop(&pi, "dlls.json");
    return 0;
}
