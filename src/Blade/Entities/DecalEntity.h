#ifndef DECAL_ENTITY_H

#define DECAL_ENTITY_H

#include <Entities/Entity.h>


class B_Vector;

class B_DecalEntity : public B_Entity
{
public:
    B_DecalEntity(
        const B_Name &name, const B_Vector &position, double d_unknown1,
        int i_unknown, double d_unknown2);

    char unknown_fields[0x264];
};

#endif /* DECAL_ENTITY_H */
