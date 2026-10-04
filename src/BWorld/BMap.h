
#ifndef BMAP_H

#define BMAP_H

#include <array.h>
#include <BBLibc/IDataFile.h>
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
    virtual ~B_Sector();
    void CalculateBoundingBox();

    int visibilityGroup;
    int unknownField01C;
    unsigned long groupId;
    double unknownField24;
    B_Plane unknown02C;
    char unknownFields4C[0x4];
    int lastQueryId;
    int isActive;
    B_BoundingBox boundingBox;
    int unknownField08C;
    int unknownField090;
    char padding[0x10];
    int atmosphere;
    int unknownField0A8;
    int unknownField0AC;
    double ambientIntensity;
    int unknownField0B8;
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
