#ifndef PHYSIC_SI_ENTITY_H

#define PHYSIC_SI_ENTITY_H

#include <Entities/ObjectEntity.h>


class B_Vector;

class B_PhysicSIEntity : public B_ObjectEntity
{
public:
    B_PhysicSIEntity(const B_Name &name, const B_Name &kind, int load);
    virtual void unknown_method0D4();
    virtual void unknown_method0D8();
    virtual void unknown_method0DC();
    virtual void ImpulseC(B_Vector &position, B_Vector &direction);
    virtual void unknown_method0E4();
    virtual void unknown_method0E8();
    virtual void unknown_method0EC();

    void SetStatic(int isStatic)
    {
        this->static1D8 = isStatic;
        this->static1DC = isStatic;
    }

private:
    char unknownFields[0x18];
    int static1D8;
    int static1DC;
    char unknownFields1E0[0xC];
};

#endif /* PHYSIC_SI_ENTITY_H */
