#pragma once

#include <AnalyticGeometry/Vector.h>
#include <AnalyticGeometry/Matrix.h>

class B_ViewPose
{
public:
    B_ViewPose(
        const B_Vector &position,
        double rotationX,
        double rotationY,
        double rotationZ);
    ~B_ViewPose();
    void setPosition(const B_Vector &pos);
    void setOrientation(const B_Vector &orientation);

    B_Vector position;
    double rotationX;
    double rotationY;
    double rotationZ;
    B_Matrix fromWorld;
    B_Matrix toWorld;
};
