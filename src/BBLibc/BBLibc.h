#ifndef BBLIBC_H

#define BBLIBC_H

#include <bld_system.h>
#ifdef BBLIBC_LIB_EXPORT
#define BUILD_LIB
#endif
#include <export.h>
#undef BUILD_LIB

#ifdef __cplusplus
extern "C" {
#endif


LIB_EXP void initBBLibc(void);

#ifdef __cplusplus
}
#endif

#endif /* BBLIBC_H */
