#include "BBLibc.h"


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
