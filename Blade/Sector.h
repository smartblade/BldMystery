#ifndef SECTOR_H

#define SECTOR_H

class B_Sector;

class unknown204
{
public:
    int InsideAA(int AA);

    B_Sector *sector;
};

class B_Sector
{
public:
    char unknownFields[32];
    unsigned long groupId;
    char unknownFields24[480];
    unknown204 unknown204;
};

#endif