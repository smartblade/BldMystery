
#ifndef BMAP_H

#define BMAP_H

#include <BBLibc/array.h>
#include <BBLibc/IDataFile.h>
#include <AnalyticGeometry/BoundingBox.h>
#include <BWorld/Surface.h>
#include <Math/BLights.h>

struct PyObject;
class B_Entity;
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

typedef int (*SectorEntityFunc)(int sectorIndex, const B_Entity &entity);
typedef int (*SectorHitFunc)(
    int sectorIndex,
    B_Entity *source,
    const B_Vector *point
);

class B_SectorFuncs
{
public:
    B_SectorFuncs(int sectorIndex);
    ~B_SectorFuncs();
    int SetOnEnterFunc(PyObject *_OnEnterFunc);
    PyObject *GetOnEnterFunc();
    int SetOnWalkOnFunc(PyObject *_OnWalkOnFunc);
    PyObject *GetOnWalkOnFunc();
    int SetOnWalkOutFunc(PyObject *_OnWalkOutFunc);
    PyObject *GetOnWalkOutFunc();
    int SetOnEnterFunc(SectorEntityFunc _OnEnterFunc);
    int ClearOnEnterFunc();
    int ClearOnWalkOnFunc();
    int ClearOnWalkOutFunc();
    int SetOnLeaveFunc(PyObject *_OnLeaveFunc);
    PyObject *GetOnLeaveFunc();
    int SetOnLeaveFunc(SectorEntityFunc _OnLeaveFunc);
    int ClearOnLeaveFunc();
    int SetOnHitFunc(PyObject *_OnHitFunc);
    PyObject *GetOnHitFunc();
    int SetOnHitFunc(SectorHitFunc _OnHitFunc);
    int ClearOnHitFunc();
    int CallOnHit(
        B_Entity *source,
        const B_Vector *point,
        const B_Vector *direction,
        const B_Vector *normal,
        const char *materialName
    );
    int CallOnEnter(const B_Entity &entity);
    int CallOnWalkOn(const B_Entity &entity);
    int CallOnWalkOut(const B_Entity &entity);
    int CallOnLeave(const B_Entity &entity);
    int IsEmpty();

    PyObject *pyOnEnter;
    SectorEntityFunc onEnter;
    PyObject *pyOnLeave;
    SectorEntityFunc onLeave;
    PyObject *pyOnHit;
    SectorHitFunc onHit;
    PyObject *pyOnWalkOn;
    PyObject *pyOnWalkOut;
    int sectorIndex;
};

class B_Sector : public B_Array<B_Surface>
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
    unsigned int lastQueryId;
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

class B_Map : public B_Array<B_Sector>
{
public:
    B_Map();
    virtual ~B_Map();

private:
    B_Array<void> unknown018;
    int unknown030;
};

B_IDataFile &operator >>(B_IDataFile &file, B_Map &map);

#endif /* BMAP_H */
