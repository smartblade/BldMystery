
#ifndef SURFACE_H

#define SURFACE_H

#include "Plane.h"
#include "Polygon.h"

class B_Portal : public B_Polygon
{
public:
    virtual ~B_Portal();

    int sectorIndex;
    char unknownFields[0x78];
};

B_IDataFile &operator >>(B_IDataFile &file, B_Portal &portal);

class B_Surface : public B_Plane
{
public:
    virtual ~B_Surface();
    virtual int ClassId() = 0;
    virtual B_Polygon *GetPolygon();
    virtual void GetPortals(int *numPortals, B_Portal **portals);
};

extern "C"
{

extern B_Surface *ReadSurface(B_IDataFile &file);

}

#endif /* SURFACE_H */
