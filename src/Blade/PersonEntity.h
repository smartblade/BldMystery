#ifndef PERSON_ENTITY_H

#define PERSON_ENTITY_H

#include "BipedEntity.h"
#include "simpleact.h"


class B_PersonEntity : public B_BipedEntity
{
public:
    char unknownFields1224[0x9EC];
    B_PersonStatus status1;
    char unknownFields1CE4[0x39C];
};

#endif /* PERSON_ENTITY_H */
