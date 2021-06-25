#pragma once

#include <map>
#include <string>
#include <windows.h>
#include "Dumper.h"
#include "DllMetadata.h"
#include "Procedure.h"
#include "StackFrame.h"

class CallsWatcher
{
public:
	CallsWatcher(
		HANDLE hProcess,
		const std::string& dllMetadataFileName,
		Dumper &dumper);
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
		const std::string& procName,
		bool isSystem);
	void EnableAllBreakpoints();
	bool DisableBreakpoint(LPVOID address);
	void SetBreakpoint(LPVOID address);
	void AdjustStackFrames(
		std::vector<StackFrame> &stackFrames,
		LPVOID curStackPointer,
		LPVOID startAddress);
	StackFrame ReadStackFrame(LPVOID stackPointer, LPVOID startAddress);
	bool IsStackFrameValid(StackFrame& frame, LPVOID curStackPointer);
	bool IsInternalSystemCall(std::vector<StackFrame>& stackFrames);
	void DumpProcedureName(
		Dumper::Level level,
		std::vector<StackFrame>& stackFrames,
		LPVOID procAddress);
	void DumpRegisters(Dumper::Level level, DWORD threadId, LPVOID address);
	void DumpMemory(Dumper::Level level, LPVOID address);

	HANDLE hProcess;
	DllMetadata dllMetadata;
	std::map<DWORD, HANDLE> threads;
	std::map<LPVOID, std::string> dlls;
	std::map<LPVOID, BYTE> savedBytes;
	std::map<LPVOID, Procedure> procedures;
	std::vector<LPVOID> disabledBreakpoints;
	std::map<DWORD, std::vector<StackFrame>> stackFramesByThread;
	Dumper dumper;
};
