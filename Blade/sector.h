#ifndef SECTOR_H

#define SECTOR_H

class sector_t;

class unknown204
{
public:
    int InsideAA(int AA);

    sector_t *sector;
};

class sector_t
{
public:
        char unknownFields[32];
        unsigned long groupId;
        char unknownFields24[480];
        unknown204 unknown204;
};

#endif