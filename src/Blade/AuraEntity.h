#ifndef AURA_ENTITY_H

#define AURA_ENTITY_H

#include "entity.h"


struct B_AuraGradient
{
    float startingPoint;
    float endingPoint;
    float r;
    float g;
    float b;
    float alpha;
    char unknown_fields18[0x4];
    float dR;
    float dG;
    float dB;
    float dAlpha;
    char unknown_fields2C[0x14];
};


class B_AuraEntity : public B_Entity
{
public:
    B_AuraGradient &GetGradient(int gap)
    {
        return gradients[gap];
    }
private:
    char unknown_fields1A0[0x1C];
    B_AuraGradient gradients[3];
    char unknown_fields27C[0x84];
};

#endif /* AURA_ENTITY_H */
