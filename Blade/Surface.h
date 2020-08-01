
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

    int unknown024;
    B_Plane *unknown028;
};

class B_DomeSurface : public B_Surface
{
public:
    B_Polygon polygon;
};

class B_OpaqueSurface : public B_Surface
{
public:
    char unknownFields[0x60];
    B_Polygon polygon;
};

class B_TransparentSurface : public B_Surface
{
public:
    char unknownFields[0xE8];
};

class B_SinglePortalSurface : public B_OpaqueSurface
{
public:
    char unknownFields[0xA0];
};

class B_MultiplePortalSurface : public B_OpaqueSurface
{
public:
    char unknownFields[0x18];
};

extern "C"
{

extern B_Surface *ReadSurface(B_IDataFile &file);

}

#endif /* SURFACE_H */
