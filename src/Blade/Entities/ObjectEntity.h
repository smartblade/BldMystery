#ifndef OBJECT_ENTITY_H

#define OBJECT_ENTITY_H

#include <AnalyticGeometry/Matrix.h>
#include <Entities/Entity.h>


class Unknown004ACF58
{
public:
    char unknownFields[0x78];
    B_Matrix pose;
    char unknownFieldsF8[0x10];
};

class B_ObjectEntity : public B_Entity
{
public:
    char unknownFields[0x18];
    Unknown004ACF58 *unknown1B8;
    char unknownFields1BC[0x4];
};

#endif /* OBJECT_ENTITY_H */
