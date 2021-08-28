#pragma once

#include <AnalyticGeometry/Vector.h>

class B_IDataFile;


class B_Texture
{
public:
    long handle;
    B_Vector xTransform;
    B_Vector yTransform;
    float xOffset;
    float yOffset;
    char unknownFields[0x4];
};

B_IDataFile &operator >>(B_IDataFile &file, B_Texture &texture);


class B_MapTexture
{
public:
    unsigned long unknown000;
    float fUnknown004;
    B_Texture texture;
    float fUnknown048;
    float fUnknown04C;
    char unknownFields[0x10];
};

B_IDataFile &operator >>(B_IDataFile &file, B_MapTexture &mapTexture);
