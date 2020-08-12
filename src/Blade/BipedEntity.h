#ifndef BIPED_ENTITY_H

#define BIPED_ENTITY_H

#include "Matrix.h"
#include "entity.h"


class B_Event;

class Unknown0049A1EF
{
public:
    char unknownFields[36];
    B_Matrix transform;
};


class B_BipedEntity : public B_Entity
{
public:
    int RaiseEvent(B_Event *event);

    char unknownFields01A0[12];
    Unknown0049A1EF *unknown01AC;
    char unknownFields01B0[0x1C0];
    int unknown0370;
    char unknownFields0374[0xEB0];
};

#endif /* BIPED_ENTITY_H */
