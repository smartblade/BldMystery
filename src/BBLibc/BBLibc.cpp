#define BBLIBC_LIB_EXPORT
#include "MessageManager.h"
#include "BBLibc.h"
#include "ObjDscr.h"
#include <crtdbg.h>
#include <direct.h>
#include <stdio.h>

char Dest[1024];
char currDirBuffer[260]; // 104h = 260 bytes
bool currDirInitialised_1004A110 = false;

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

void OutputWin32Error(char const *message)
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
* Entry point:            0x10029BE0
* VC++ mangling:          ?vararg@@YAPBDPBDZZ
*/

const char *vararg(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    vsprintf(Dest, format, args);

    va_end(args);

    return Dest;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x10002740
* VC++ mangling:          ?GetConfigDirectory@@YAPBDXZ
*/
#ifndef BLD_NATIVE
const char *GetConfigDirectory()
{
    return currDirBuffer;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x100028EC
* VC++ mangling:          ?GetCurrentLanguage@@YAPBDXZ
*/
#ifndef BLD_NATIVE
char const *GetCurrentLanguage()
{
    return 0;
}
#endif


/*
* Module:                 BBLibc.dll
* Entry point:            0x100020F2
* VC++ mangling:          ?RemoveOnOpenInputFileFunc@@YAXXZ
*/
#ifndef BLD_NATIVE
void RemoveOnOpenInputFileFunc()
{

}
#endif


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

