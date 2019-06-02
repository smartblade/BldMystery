#ifndef LOCATION_H

#define LOCATION_H

#include "Vector.h"

class location_t
{
public:
    void setPosition(const B_Vector &pos);
    void setOrientation(const B_Vector &orientation);
private:
    B_Vector position;
};

#endif