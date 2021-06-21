#include "StackFrame.h"

StackFrame::StackFrame(LPVOID stackPointer, LPVOID returnAddress)
    :
stackPointer(stackPointer), returnAddress(returnAddress)
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
