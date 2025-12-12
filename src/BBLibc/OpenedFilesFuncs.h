#pragma once

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

struct PyObject;

LIB_EXP int GetnOpenedInputFiles();
LIB_EXP int GetnOpenInputFiles();
LIB_EXP void ResetnOpenedInputFiles();
LIB_EXP int SetOnOpenInputFileFunc(PyObject *func);
LIB_EXP void RemoveOnOpenInputFileFunc();
