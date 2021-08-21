#pragma once


class B_IDataFile;

class B_MapTexture
{
    char unknownFields[0x60];
};

B_IDataFile &operator >>(B_IDataFile &file, B_MapTexture &mapTexture);
