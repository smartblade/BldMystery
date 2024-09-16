#include <crtdbg.h>
#include <direct.h>

#include "MessageManager.h"
#define BBLIBC_LIB_EXPORT
#include "BBLibc.h"
#include "ObjDscr.h"


char Dest[1024];
char currDirBuffer[260]; // 104h = 260 bytes
bool currDirInitialised_1004A110 = false;

/*
* Module:                 BBLibc.dll
* Entry point:            0x1002A590
* VC++ mangling:          ?OutputWin32Error@@YAXPBD@Z
*/

void OutputWin32Error(char const* message)
{
    unsigned int errorCode = GetLastError();

    mout << message;

    LPSTR errorString = nullptr;
    FormatMessageA(
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

const char* vararg(const char* format, ...) {
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

const char* GetConfigDirectory() {
    // TODO implement
    return currDirBuffer;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100028EC
* VC++ mangling:          ?GetCurrentLanguage@@YAPBDXZ
*/

char const* GetCurrentLanguage(void) {
    // TODO implement
    return 0;
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100020F2
* VC++ mangling:          ?RemoveOnOpenInputFileFunc@@YAXXZ
*/

void RemoveOnOpenInputFileFunc(void) {
    // TODO implement
}

