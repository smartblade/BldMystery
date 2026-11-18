#include "PythonCall.h"


/*
* Module:                 BBLibc.dll
* Data address:           0x10048984
* VC++ mangling:          ?CheckErrors@@3HA
*/
int CheckErrors = 3;


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


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
