#ifndef LOCATION_H

#define LOCATION_H

#include "Vector.h"
#include "transform_matrix.h"

class location_t
{
public:
    void setPosition(const B_Vector &pos);
    void setOrientation(const B_Vector &orientation);
    void updateMatrix();
private:
    B_Vector position;
    double rotateX;
    double rotateY;
    double ratateZ;
    transform_matrix_t matrix;
    transform_matrix_t invMatrix;
};

#endif