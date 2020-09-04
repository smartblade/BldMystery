#ifndef ENTITY_H

#define ENTITY_H

#include "BBLibc.h"


#define PLAYER "Player1"

#define B_ENTITY_CID_PHYSIC_OBJECT     2
#define B_ENTITY_CID_PERSON            4
#define B_ENTITY_CID_WEAPON            6
#define B_ENTITY_CID_CAMERA            8
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

#endif /* ENTITY_H */

