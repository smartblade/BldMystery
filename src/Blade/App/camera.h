#ifndef CAMERA_H

#define CAMERA_H


#include <Math/BSpline.h>
#include <BBLibc.h>


class B_Vector;

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
    int SetTravelingView(int s_type, int t_type);
    int SetPersonView(const char *person_name);
    int Read3dsMaxAnimation(
        const char *cam_file_name, int i_unknown, int num_frames);
    int DeleteEvent(int frame);
    void AddEvent(int frame, PyObject *func);
    int AddSourceNode(double time, const B_Vector &position);

    int AddTargetNode(double time, const B_Vector &position)
    {
        return target.AddNode(time, position);
    }

    int SetStartTangentSourceNode(int nodeIndex, const B_Vector &startTangent)
    {
        return source.SetStartTangent(nodeIndex, startTangent);
    }

    int SetEndTangentSourceNode(int nodeIndex, const B_Vector &endTangent)
    {
        return source.SetEndTangent(nodeIndex, endTangent);
    }

    int SetStartTangentTargetNode(int nodeIndex, const B_Vector &startTangent)
    {
        return target.SetStartTangent(nodeIndex, startTangent);
    }

    int SetEndTangentTargetNode(int nodeIndex, const B_Vector &endTangent)
    {
        return target.SetEndTangent(nodeIndex, endTangent);
    }

    B_PtrArray<B_CameraMovement> movements;
    char unknownFields018[0x080];
    B_Spline source;
    B_Spline target;
    char unknownFields0D0[0x170];
};

#endif
