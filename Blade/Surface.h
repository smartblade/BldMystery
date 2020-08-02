
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

#define B_SURFACE_CID_OPAQUE              7001
#define B_SURFACE_CID_TRANSPARENT         7002
#define B_SURFACE_CID_SINGLE_PORTAL       7003
#define B_SURFACE_CID_MULTIPLE_PORTAL     7004
#define B_SURFACE_CID_DOME                7005

class B_Surface : public B_Plane
{
public:
    B_Surface();
    virtual ~B_Surface();
    virtual int ClassId() = 0;


/*
* Module:                 Blade.exe
* Entry point:            0x0045BCB0
* VC++ mangling:          ?GetPolygon@B_Surface@@UAEPAVB_Polygon@@XZ
*/

    virtual B_Polygon *GetPolygon()
    {
        return NULL;
    }

    virtual void GetPortals(int *numPortals, B_Portal **portals);
    virtual void unknown010();
    virtual void unknown014();
    virtual void unknown018();
    virtual void unknown01C();

    int unknown024;
    B_Plane *unknown028;
};

class B_DomeSurface : public B_Surface
{
public:
    virtual int ClassId();


/*
* Module:                 Blade.exe
* Entry point:            0x0045BCE0
* VC++ mangling:          ?GetPolygon@B_DomeSurface@@UAEPAVB_Polygon@@XZ
*/

    virtual B_Polygon *GetPolygon()
    {
        return &polygon;
    }

    virtual void unknown014();

    B_Polygon polygon;
};

B_IDataFile &operator >>(B_IDataFile &file, B_DomeSurface &surface);


class B_OpaqueSurface : public B_Surface
{
public:
    virtual int ClassId();


/*
* Module:                 Blade.exe
* Entry point:            0x0045BD00
* VC++ mangling:          ?GetPolygon@B_OpaqueSurface@@UAEPAVB_Polygon@@XZ
*/

    virtual B_Polygon *GetPolygon()
    {
        return &polygon;
    }

    virtual void unknown014();
    virtual void unknown018();

    char unknownFields[0x60];
    B_Polygon polygon;
};

B_IDataFile &operator >>(B_IDataFile &file, B_OpaqueSurface &surface);


class B_TransparentSurface : public B_Surface
{
public:
    B_TransparentSurface();
    virtual int ClassId();


/*
* Module:                 Blade.exe
* Entry point:            0x0045BD20
* VC++ mangling:          ?GetPolygon@B_TransparentSurface@@UAEPAVB_Polygon@@XZ
*/

    virtual B_Polygon *GetPolygon()
    {
        return &portal;
    }

    virtual void GetPortals(int *numPortals, B_Portal **portals);
    virtual void unknown010();
    virtual void unknown014();
    virtual void unknown018();

    char unknownFields[0x60];
    B_Portal portal;
};

B_IDataFile &operator >>(B_IDataFile &file, B_TransparentSurface &surface);


class B_SinglePortalSurface : public B_OpaqueSurface
{
public:
    B_SinglePortalSurface();
    virtual int ClassId();
    virtual void GetPortals(int *numPortals, B_Portal **portals);
    virtual void unknown010();
    virtual void unknown014();
    virtual void unknown018();

    char unknownFields[0xA0];
};

B_IDataFile &operator >>(B_IDataFile &file, B_SinglePortalSurface &surface);


class B_MultiplePortalSurface : public B_OpaqueSurface
{
public:
    B_MultiplePortalSurface();
    virtual ~B_MultiplePortalSurface();
    virtual int ClassId();
    virtual void GetPortals(int *numPortals, B_Portal **portals);
    virtual void unknown010();
    virtual void unknown014();
    virtual void unknown018();

    char unknownFields[0x18];
};

B_IDataFile &operator >>(B_IDataFile &file, B_MultiplePortalSurface &surface);


extern "C"
{

extern B_Surface *ReadSurface(B_IDataFile &file);

}

#endif /* SURFACE_H */
