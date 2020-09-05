#ifndef CAMERA_H

#define CAMERA_H


#include <BBLibc.h>


class B_CameraMovement : public B_NamedObj
{
public:
    B_CameraMovement(
        const char *action_name, double angle, double start_pos,
        double end_pos)
    :
        angle(angle), start_pos(start_pos), end_pos(end_pos)
    {
        name = action_name;
    }
    virtual ~B_CameraMovement()
    {
    }

    double angle;
    double start_pos;
    double end_pos;
};

class B_Camera
{
public:
    int DeleteEvent(int frame);
    void AddEvent(int frame, PyObject *func);

    B_PtrArray<B_CameraMovement> movements;
    char unknownFields1B8[0x228];
};

#endif
