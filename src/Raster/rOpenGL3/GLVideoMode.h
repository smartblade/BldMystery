#pragma once

#include <BBLibc/array.h>


struct B_VideoMode
{
    int depth;
    int width;
    int height;
    int flags;
    int frequency;
};

#ifdef __cplusplus
extern "C" {
#endif

void GetVideoModes(B_Array<B_VideoMode> &videoModes);

#ifdef __cplusplus
}
#endif
