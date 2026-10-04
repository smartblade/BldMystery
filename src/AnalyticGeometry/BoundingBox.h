
#ifndef BOUNDING_BOX_H

#define BOUNDING_BOX_H

#include <array.h>
#include <AnalyticGeometry/Vector.h>

class B_Sector;

class B_Sphere {
public:
    B_Sphere();

    B_Vector center;
    double radius;
};

class B_BoundingBox
{
public:
    B_BoundingBox();
    B_BoundingBox(const B_Vector& minCoords, const B_Vector& maxCoords);

    void CollectIntersectingSectors(const B_PtrArray<B_Sector>&, B_PtrArray<B_Sector>&);

    bool Intersects(const B_Sector* sector) const;

    B_Vector minCoords;
    B_Vector maxCoords;
};

#endif /* BOUNDING_BOX_H */
