#ifndef WIN32_ERROR_H

#define WIN32_ERROR_H

#include <bld_system.h>
#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

LIB_EXP void OutputWin32Error(const char *message);

#endif /* WIN32_ERROR_H */
