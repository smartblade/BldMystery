#define BBLIBC_LIB_EXPORT
#include "OpenedFilesFuncs.h"
#include "IDataFile.h"


/*
* Module:                 BBLibc.dll
* Entry point:            0x100020C3
* VC++ mangling:          ?GetnOpenedInputFiles@@YAHXZ
*/

int GetnOpenedInputFiles()
{
    return B_IDataFile::GetnOpenedFiles();
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100020CD
* VC++ mangling:          ?GetnOpenInputFiles@@YAHXZ
*/

int GetnOpenInputFiles()
{
    return B_IDataFile::GetnOpenFiles();
}


/*
* Module:                 BBLibc.dll
* Entry point:            0x100020D7
* VC++ mangling:          ?ResetnOpenedInputFiles@@YAXXZ
*/
#ifndef BLD_NATIVE
void ResetnOpenedInputFiles()
{
}
#endif

/*
* Module:                 BBLibc.dll
* Entry point:            0x100020E1
* VC++ mangling:          ?SetOnOpenInputFileFunc@@YAHPAUPyObject@@@Z
*/
#ifndef BLD_NATIVE
int SetOnOpenInputFileFunc(PyObject *arg_1)
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
