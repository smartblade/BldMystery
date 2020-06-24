#ifndef ENTITY_H

#define ENTITY_H

#include "BBLibc.h"
#include "Matrix.h"
#include "simpleact.h"


#define PLAYER "Player1"

#define B_ENTITY_CID_PHYSIC_OBJECT     2
#define B_ENTITY_CID_PERSON            4
#define B_ENTITY_CID_WEAPON            6
#define B_ENTITY_CID_ACTOR             13
#define B_ENTITY_CID_BIPED             21
#define B_ENTITY_CID_CLIENT            27

class B_Entity :  public B_NamedObj
{
public:
    virtual ~B_Entity();
    virtual void *unknown_method004();
    virtual void *unknown_method008();
    virtual int ClassId();
    virtual int IsClassOf(int type);

    char unknownFields[404];
};

class Unknown0049A1EF
{
public:
    char unknownFields[36];
    B_Matrix transform;
};

class B_BipedEntity : public B_Entity
{
public:
    char unknownFields01A0[12];
    Unknown0049A1EF *unknown01AC;
    char unknownFields01B0[0x1C0];
    int unknown0370;
    char unknownFields0374[0xEB0];
};

class B_PersonEntity : public B_BipedEntity
{
public:
    char unknownFields1224[0x9EC];
    B_PersonStatus status1;
    char unknownFields1CE4[0x39C];
};

#endif /* ENTITY_H */

