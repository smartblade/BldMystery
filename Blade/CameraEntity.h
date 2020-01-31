#ifndef CAMERA_ENTITY_H

#define CAMERA_ENTITY_H

#include "entity.h"

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

class B_CameraEntity : public B_Entity
{
public:
    B_CameraEntity(int unknown, const B_Name &name);
    void unknown_004EB1AA(void *);

    B_PtrArray<B_CameraMovement> movements;
    char unknownFields1B8[564];
    float unknownValueFromApplication;
    float *unknownPtrFromApplication;
    char unknownFields2[72];
};

#endif /*CAMERA_ENTITY_H*/