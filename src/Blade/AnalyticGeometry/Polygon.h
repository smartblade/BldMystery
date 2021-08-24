
#ifndef POLYGON_H

#define POLYGON_H

#include "array.h"
#include <AnalyticGeometry/Vector.h>

class B_IDataFile;

class B_WorldPoint
{
public:
    B_WorldPoint();

    B_Vector v;
    int unknown18;
    int unknown1C;
};

B_IDataFile &operator >>(B_IDataFile &file, B_WorldPoint &point);

class B_WorldPoints
{
public:
    array_t<B_WorldPoint> points;
};

B_IDataFile &operator >>(B_IDataFile &file, B_WorldPoints &wordPoints);


class B_Polygon
{
public:
    B_Polygon();
    virtual ~B_Polygon();

    unsigned int numVertices;
    unsigned int *vertices;
};

B_IDataFile &operator >>(B_IDataFile &file, B_Polygon &polygon);

#endif /* POLYGON_H */
