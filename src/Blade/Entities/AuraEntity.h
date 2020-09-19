#ifndef AURA_ENTITY_H

#define AURA_ENTITY_H

#include <Entities/Entity.h>


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

    void setActive(bool active)
    {
        this->active = active;
    }

    void setAlphaMode(bool alphaMode)
    {
        this->alphaMode = alphaMode;
    }

    void setHideFaces(bool hideFrontFaces, bool hideBackFaces)
    {
        this->hideFrontFaces = hideFrontFaces;
        this->hideBackFaces = hideBackFaces;
    }

    void setSize(float size)
    {
        this->size = size;
    }

    void setAlpha(float alpha)
    {
        this->alpha = alpha;
    }

    void setColourIntensity(float colourIntensity)
    {
        this->colourIntensity = colourIntensity;
    }

private:
    int active;
    int alphaMode;
    int hideFrontFaces;
    int hideBackFaces;
    float size;
    float alpha;
    float colourIntensity;
    B_AuraGradient gradients[3];
    char unknown_fields27C[0x84];
};

#endif /* AURA_ENTITY_H */
