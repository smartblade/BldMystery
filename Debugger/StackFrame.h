#pragma once

#include <windows.h>

class StackFrame
{
public:
    StackFrame(LPVOID stackPointer, LPVOID returnAddress, LPVOID startAddress);
    LPVOID StackPointer();
    LPVOID ReturnAddress();
    LPVOID StartAddress();

private:
    LPVOID stackPointer;
    LPVOID returnAddress;
    LPVOID startAddress;
};

