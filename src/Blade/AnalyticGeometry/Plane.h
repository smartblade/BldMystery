
#ifndef PLANE_H

#define PLANE_H

#include <AnalyticGeometry/Vector.h>

class B_Plane
{
public:
    virtual ~B_Plane()
    {
    }

    B_Vector normal;
    double p;
};

B_IDataFile &operator >>(B_IDataFile &file, B_Plane &plane);

#endif /* PLANE_H */
