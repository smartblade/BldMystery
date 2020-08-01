
#ifndef PLANE_H

#define PLANE_H

#include "Vector.h"

class B_Plane
{
public:
    virtual ~B_Plane()
    {
    }

    B_Vector normal;
    double p;
};

#endif /* PLANE_H */
