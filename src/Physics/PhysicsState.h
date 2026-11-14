#ifndef PHYSICS_STATE_H

#define PHYSICS_STATE_H

#include <BBLibc/array.h>
#include <AnalyticGeometry/Vector.h>
#include <AnalyticGeometry/BoundingBox.h>


class B_PhysicsState
{
public:
    B_PhysicsState()
    :
        version(0)
    {
    }

    int version;
    array_t<B_Vector> vertices;
    char unknownFields018[0x14];
    B_BoundingBox boundingBox;
};

#endif /* PHYSICS_STATE_H */
