#define BBLIBC_LIB_EXPORT
#include "MessageManager.h"
#include "BBLibc.h"
#include "ObjDscr.h"
#include <crtdbg.h>
#include <direct.h>


/*
* Module:                 BBLibc.dll
* Data address:           0x10048984
* VC++ mangling:          ?CheckErrors@@3HA
*/
int CheckErrors = 3;


/*
* Module:                 BBLibc.dll
* Entry point:            0x1002A590
* VC++ mangling:          ?OutputWin32Error@@YAXPBD@Z
*/

void OutputWin32Error(const char *message)
{
    unsigned int errorCode = GetLastError();

    mout << message;

    LPSTR errorString = nullptr;
    FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
        nullptr, errorCode, 0x400, (LPSTR)&errorString, 0, nullptr);

    mout << errorString;

    LocalFree(errorString);
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x1003E436
* VC++ mangling:          ?CallPythonObject@@YAPAUPyObject@@PAU1@0@Z
*/

#ifndef BLD_NATIVE
PyObject *CallPythonObject(PyObject *func, PyObject *args)
{
    PyObject *result = nullptr;

    return result;
}
#endif

