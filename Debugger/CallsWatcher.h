#pragma once

#include <map>
#include <string>
#include <windows.h>
#include "DllMetadata.h"

class CallsWatcher
{
public:
	CallsWatcher(HANDLE hProcess, const std::string& dllMetadataFileName);
	void OnDllLoaded(HANDLE hFile, LPVOID lpBase);
	void OnProcessCreated(
		HANDLE hFile,
		LPVOID lpBase,
		LPVOID startAddress,
		DWORD threadId,
		HANDLE hThread);
	void OnThreadCreated(DWORD threadId, HANDLE hThread);
	void OnBreakpoint(LPVOID address, DWORD threadId);
	void OnSingleStep(LPVOID address, DWORD threadId);
	std::string FindDll(LPVOID address);

private:
	void AddWatchedDll(HANDLE hFile, LPVOID lpBase);
	void AddWatchedProcedure(
		HANDLE hFile,
		LPVOID procAddress,
		const std::string& procName);
	void EnableAllBreakpoints();
	bool DisableBreakpoint(LPVOID address);
	void SetBreakpoint(LPVOID address);

	HANDLE hProcess;
	DllMetadata dllMetadata;
	std::map<DWORD, HANDLE> threads;
	std::map<LPVOID, std::string> dlls;
	std::map<LPVOID, BYTE> savedBytes;
	std::map<LPVOID, std::string> procedures;
	std::vector<LPVOID> disabledBreakpoints;
};

