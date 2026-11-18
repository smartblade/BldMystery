#ifndef PYTHON_CALL_H

#define PYTHON_CALL_H

#include <bld_system.h>
#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

struct PyObject;

extern LIB_EXP int CheckErrors;

LIB_EXP PyObject *CallPythonObject(PyObject *func, PyObject *args);

#endif /* PYTHON_CALL_H */
