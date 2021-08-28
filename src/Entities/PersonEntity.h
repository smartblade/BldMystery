#ifndef PERSON_ENTITY_H

#define PERSON_ENTITY_H

#include <Entities/BipedEntity.h>
#include <Person/Person.h>


class B_PersonEntity : public B_BipedEntity
{
public:
    int CanISee(B_PersonEntity *that);

    B_Person per;
    char unknownFields1DD4[0x2AC];
};

#endif /* PERSON_ENTITY_H */
