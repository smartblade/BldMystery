
#ifndef PLANE_H

#define PLANE_H

#include <AnalyticGeometry/Vector.h>
#include <BBLibc/IDataFile.h>
#include <BBLibc/ODataFile.h>

class B_Plane
{
public:
    B_Plane()
    {
    }

    B_Plane(double p, const B_Vector &normal);
    B_Plane(const B_Vector &point, const B_Vector &normal);
    B_Plane(const B_Vector &point, const B_Vector &u, const B_Vector &v);

    virtual ~B_Plane()
    {
    }

    void Set(double p, const B_Vector &normal);
    void Set(const B_Vector &point, const B_Vector &normal);
    void Set(const B_Vector &point, const B_Vector &u, const B_Vector &v);
    int operator ==(const B_Plane &that) const;
    void Translate(const B_Vector &offset);
    void PassThrough(const B_Vector &point);

    B_Vector normal;
    double p;
};

B_IDataFile &operator >>(B_IDataFile &file, B_Plane &plane);
B_ODataFile &operator <<(B_ODataFile &file, B_Plane &plane);

#endif /* PLANE_H */
