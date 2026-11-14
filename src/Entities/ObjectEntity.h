#ifndef OBJECT_ENTITY_H

#define OBJECT_ENTITY_H

#include <Entities/Entity.h>


class B_PhysicsTemplate;

class B_ObjectEntity : public B_Entity
{
public:
    char unknownFields[0x18];
    B_PhysicsTemplate *solid;
    char unknownFields1BC[0x4];
};

#endif /* OBJECT_ENTITY_H */
