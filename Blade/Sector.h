#ifndef SECTOR_H

#define SECTOR_H

class B_IDataFile;
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
    B_Sector();

    char unknownFields[32];
    unsigned long groupId;
    char unknownFields24[480];
    unknown204 unknown204;
    char unknownFields208[24];
};

B_IDataFile &operator >>(B_IDataFile &file, B_Sector &sector);

#endif