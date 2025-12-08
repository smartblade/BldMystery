#pragma once

#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

LIB_EXP const char *vararg(const char *format, ...);
