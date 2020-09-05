#ifndef BSPLINE_H

#define BSPLINE_H


class B_Vector;

class B_Spline
{
public:
    int AddNode(double time, const B_Vector &position);
    int Close();
    int Clear();
    int GetPosition(double time, B_Vector *position);
    int SetStartTangent(int nodeIndex, const B_Vector &startTangent);
    int SetEndTangent(int nodeIndex, const B_Vector &endTangent);

    char unknownFields[0x1C];
};

#endif /* BSPLINE_H */
