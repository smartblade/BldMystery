
#ifndef BLD_PYTHON_H

#define BLD_PYTHON_H


#ifdef __BORLANDC__

/*
 * Define MS_COREDLL for Borland C Builder to avoid crash after _PyObject_New
 * call
 */
#define MS_COREDLL

/*
 * Define USE_DL_IMPORT for Borland C Builder to avoid access violation
 * when writing to _Py_NoneStruct
 */
#define USE_DL_IMPORT

#endif

/*
 * Define macro to make link with ?CallPythonObject@@YAPAUPyObject@@PAU1@0@Z
 * TODO use appropriate Python version and remove this macro
 */
#define _object PyObject
#include <Python.h>
#undef _object

#ifdef __BORLANDC__

/* Use stdcall to avoid generation underscores */
#define INIT_PY_MODULE_FUNC void __stdcall

#else

#define INIT_PY_MODULE_FUNC void

#endif


#endif /* BLD_PYTHON_H */

