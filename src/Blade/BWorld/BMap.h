
#ifndef BMAP_H

#define BMAP_H

#include <array.h>
#include <BBLibc.h>
#include <AnalyticGeometry/BoundingBox.h>
#include <BWorld/Surface.h>
#include <Math/BLights.h>

class B_Sector;

class unknown204
{
public:
    int InsideAA(int AA);

    B_Sector *sector;
};

class B_SectorLights
{
public:
    char unknownFields[0x00C];
    B_AmbientLight ambient;
    B_FlatLight flat;
    char unknownFields0128[0x010];
};

B_IDataFile &operator >>(B_IDataFile &file, B_SectorLights &lights);

class B_Sector : public B_PtrArray<B_Surface>
{
public:
    B_Sector();
    void CalculateBoundingBox();

    char unknownFields[8];
    unsigned long groupId;
    char unknownFields24[56];
    B_BoundingBox boundingBox;
    char unknownFields08C[0x18];
    int atmosphere;
    char unknownFields0A8[0x014];
    B_SectorLights lights;
    char unknownFields1F4[0x10];
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
