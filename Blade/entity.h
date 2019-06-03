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

class person_t : public biped_entity_t
{
    char unknownFields[3676];
};

class B_CameraEntity : public B_Entity
{
public:
    B_CameraEntity(int unknown, const B_Name &name);
    void unknown_004EB1AA(void *);
/*
    ....1A0
    B_Camera camera(240 : location);*/
    char unknownFields1[588];
    float unknownValueFromApplication;
    float *unknownPtrFromApplication;
    char unknownFields2[72];
};


#endif /* ENTITY_H */

