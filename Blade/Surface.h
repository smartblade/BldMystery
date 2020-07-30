
#ifndef SURFACE_H

#define SURFACE_H

#include "Plane.h"

class B_Polygon;

class B_Surface : public B_Plane
{
public:
    virtual ~B_Surface();
    virtual int ClassId() = 0;
    virtual B_Polygon *GetPolygon();
};

#endif /* SURFACE_H */
