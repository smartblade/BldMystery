#ifndef BBLIBC_H

#define BBLIBC_H

#include <bld_system.h>
#include <bld_python.h>
#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

LIB_EXP int CheckErrors;

LIB_EXP const char* vararg(const char* format, ...);

LIB_EXP void OutputWin32Error(char const* message);

LIB_EXP const char* GetConfigDirectory();

LIB_EXP char const* GetCurrentLanguage(void);

LIB_EXP void RemoveOnOpenInputFileFunc(void);

LIB_EXP PyObject* CallPythonObject(PyObject* func, PyObject* args);

struct PyObject;


#ifdef __cplusplus
extern "C" {
#endif


LIB_EXP INIT_PY_MODULE_FUNC initBBLibc(void);

#ifdef __cplusplus
}
#endif

#endif /* BBLIBC_H */
