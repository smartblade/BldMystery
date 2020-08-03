#ifndef NETGAME_H

#define NETGAME_H

#include <bld_system.h>
#include <bld_python.h>
#include <blade_ext.h>
#define BUILD_LIB
#include <export.h>


#ifdef __cplusplus
extern "C" {
#endif

LIB_EXP INIT_PY_MODULE_FUNC initnetgame(void);

#ifdef __cplusplus
}
#endif

#endif /* NETGAME_H */
