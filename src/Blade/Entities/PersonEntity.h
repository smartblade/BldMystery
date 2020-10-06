#ifndef PERSON_ENTITY_H

#define PERSON_ENTITY_H

#include <Entities/BipedEntity.h>
#include <enemies/Combos_Stuff.h>
#include "simpleact.h"


class B_PersonEntity : public B_BipedEntity
{
public:
    char unknownFields1224[0x948];
    B_Combos combos;
    char unknownFields1BD8[0x38];
    B_PersonStatus status1;
    char unknownFields1CE4[0x39C];
};

#endif /* PERSON_ENTITY_H */
