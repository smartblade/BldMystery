#ifndef ENTITY_H

#define ENTITY_H

#include "BBLibc.h"
#include "Matrix.h"


#define PLAYER "Player1"

#define B_ENTITY_CID_PERSON            4

class B_Entity :  public B_NamedObj
{
public:
    virtual ~B_Entity();
    virtual void *unknown_method004();
    virtual void *unknown_method008();
    virtual int ClassId();
    virtual int is_type_of(int type);

    char unknownFields[404];
};

class Unknown0049A1EF
{
public:
    char unknownFields[36];
    B_Matrix transform;
};

class biped_entity_t : public B_Entity
{
public:
    char unknownFields01A0[12];
    Unknown0049A1EF *unknown01AC;
    char unknownFields01B0[4204];
};

class B_PersonEntity : public biped_entity_t
{
    char unknownFields[3684];
};

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

    array_t<B_CameraMovement *> movements;
    char unknownFields1B8[564];
    float unknownValueFromApplication;
    float *unknownPtrFromApplication;
    char unknownFields2[72];
};


#endif /* ENTITY_H */

