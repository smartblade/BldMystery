
#ifndef BMAP_H

#define BMAP_H

#include <array.h>
#include <BBLibc.h>
#include "BoundingBox.h"
#include "Surface.h"

class B_Sector;

class unknown204
{
public:
    int InsideAA(int AA);

    B_Sector *sector;
};

class B_Sector : public B_PtrArray<B_Surface>
{
public:
    B_Sector();

    char unknownFields[8];
    unsigned long groupId;
    char unknownFields24[56];
    B_BoundingBox boundingBox;
    char unknownFields8C[376];
    unknown204 unknown204;
    char unknownFields208[24];
};

B_IDataFile &operator >>(B_IDataFile &file, B_Sector &sector);

class B_Map : public B_PtrArray<B_Sector>
{
private:
    B_PtrArray<void> unknown018;
    int unknown030;
};

B_IDataFile &operator >>(B_IDataFile &file, B_Map &map);

#endif /* BMAP_H */
