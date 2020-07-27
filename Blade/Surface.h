
#ifndef SURFACE_H

#define SURFACE_H


class B_Polygon;

class B_Surface
{
public:
    virtual ~B_Surface();
    virtual void unknown004() = 0;
    virtual B_Polygon *GetPolygon();
};

#endif /* SURFACE_H */
