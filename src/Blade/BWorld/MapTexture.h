#pragma once


class B_IDataFile;

class B_Texture
{
    char unknownFields[0x40];
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
