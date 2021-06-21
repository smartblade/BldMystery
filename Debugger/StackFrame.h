#pragma once

#include <windows.h>

class StackFrame
{
public:
    StackFrame(LPVOID stackPointer, LPVOID returnAddress);
    LPVOID StackPointer();
    LPVOID ReturnAddress();

private:
    LPVOID stackPointer;
    LPVOID returnAddress;
};

