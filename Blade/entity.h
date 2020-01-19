#ifndef ENTITY_H

#define ENTITY_H

#include "BBLibc.h"


#define PLAYER "Player1"

class B_Entity :  public B_NamedObj
{
public:
    virtual ~B_Entity();
    virtual void *unknown_method004();
    virtual void *unknown_method008();
    virtual void *unknown_method00C();
    virtual int is_type_of(int type);

    char unknownFields[404];
};

class biped_entity_t : public B_Entity
{
    char unknownFields[4220];
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

