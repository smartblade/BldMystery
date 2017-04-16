#ifndef ATMOSPHERE_H

#define ATMOSPHERE_H

#include "BBLibc.h"

#ifdef __cplusplus

class atmosphere_t : public B_NamedObj
{
public:
        atmosphere_t();
        ~atmosphere_t();
public:
        B_Color color;
        float intensity;
};

B_IDataFile &operator >>(B_IDataFile &file, atmosphere_t *atm);

#else

typedef struct {
        BBLibc_named_object_t parent;
        BBLibc_color_t color;
        float intensity;
} atmosphere_t;

#endif

#endif
