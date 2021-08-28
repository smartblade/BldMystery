#ifndef ATMOSPHERE_H

#define ATMOSPHERE_H

#include "BBLibc.h"

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

#endif
