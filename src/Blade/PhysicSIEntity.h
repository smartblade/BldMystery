#ifndef PHYSIC_SI_ENTITY_H

#define PHYSIC_SI_ENTITY_H

#include "ObjectEntity.h"


class B_Vector;

class B_PhysicSIEntity : public B_ObjectEntity
{
public:
    virtual void unknown_method0D4();
    virtual void unknown_method0D8();
    virtual void unknown_method0DC();
    virtual void ImpulseC(B_Vector &position, B_Vector &direction);
    virtual void unknown_method0E4();
    virtual void unknown_method0E8();
    virtual void unknown_method0EC();

private:
    char unknownFields[0x2C];
};

#endif /* PHYSIC_SI_ENTITY_H */
