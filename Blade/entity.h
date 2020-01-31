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

#endif /* ENTITY_H */

