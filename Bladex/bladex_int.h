
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


#include <Python.h>
#include <windows.h>
#include <assert.h>
#include <blade_ext.h>
#define BUILD_LIB
#include <export.h>


extern PyObject *get_char_by_name(const char *name, const char *short_name);
extern void init_char(void);

