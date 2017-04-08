#ifndef ATMOSPHERE_H

#define ATMOSPHERE_H

#include "BBLibc.h"

typedef struct {
        BBLibc_named_object_t parent;
        BBLibc_color_t color;
        float intensity;
} atmosphere_t;

#endif
