#ifndef BSPLINE_H

#define BSPLINE_H


class B_Vector;

class B_Spline
{
public:
    int Close();
    int Clear();
    int GetPosition(double time, B_Vector *position);
};

#endif /* BSPLINE_H */
