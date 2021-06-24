#include "StackFrame.h"

StackFrame::StackFrame(
    LPVOID stackPointer, LPVOID returnAddress, LPVOID startAddress)
    :
stackPointer(stackPointer), returnAddress(returnAddress),
startAddress(startAddress)
{
}

LPVOID StackFrame::StackPointer()
{
    return stackPointer;
}

LPVOID StackFrame::ReturnAddress()
{
    return returnAddress;
}

LPVOID StackFrame::StartAddress()
{
    return startAddress;
}
