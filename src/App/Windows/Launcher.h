
#ifndef LAUNCHER_H

#define LAUNCHER_H

#include <bld_system.h>


class B_Name;
class B_YSoundDev;


#ifdef __cplusplus
extern "C" {
#endif

extern int ShowStartupDialog(
    HMODULE module,
    HWND window,
    B_YSoundDev *sound,
    B_Name *rasterName,
    bool showDialog
);

#ifdef __cplusplus
}
#endif

#endif /* LAUNCHER_H */
