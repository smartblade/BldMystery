
#ifndef GAME_STATE_H

#define GAME_STATE_H


#include <array.h>
#include <Entities/Entity.h>
#include <BWorld/atmosphere.h>
#include <BWorld/BMap.h>
#include <BWorld/light.h>
#include <BWorld/OctTree.h>
#include <Hash.h>
#include <AnalyticGeometry/Vector.h>
#include <bld_python.h>


class location_t;

class B_SubscriptionList : public B_PtrArray<B_Entity>, public B_NamedObj
{
};

class B_TriggerSector : public B_NamedObj
{
public:
    B_TriggerSector(
        const char *trigger_sector_name, const char *group_name,
        float floor_height, float roof_height)
    :
    B_NamedObj(trigger_sector_name)
    {
        this->floorHeight = floor_height;
        this->minH = floor_height;
        this->roofHeight = roof_height;
        this->maxH = roof_height;
        this->onEnter = NULL;
        this->onLeave = NULL;
        this->data = NULL;
        this->groupName = group_name;
    }
    void AddPoint(const B_Vector& point, int numPoints);

    float minX;
    float minY;
    float maxX;
    float maxY;
    float maxH;
    float minH;
    float floorHeight;
    float roofHeight;
    array_t<B_Vector> points;
    array_t<B_Vector> a040;
    B_PtrArray<void> a054;
    PyObject *onEnter;
    PyObject *onLeave;
    PyObject *data;
    B_Name groupName;
};

class B_World
{
public:
    void unknown_00439F5D();
    double GetTime();
    int SetTime(double time);
    void GoToTime(double time);
    void AddScheduledFunc(
        double time, PyObject *func, PyObject *args, const char *name);
    void Update(
        location_t *location, void *unknown, double time, int updateRaster);
    void SetSun(int exists, const B_Vector &position);
    void GetEnemiesVisibleFrom(
        const B_Vector &position, double radius,
        const B_Vector &direction, double angle,
        B_PtrArray<B_Entity> *enemies);
    int FindSectorIndex(const B_Vector &point);
    int IntersectSegment(
        const B_Vector &startPoint, const B_Vector &endPoint,
        const B_Vector &intersection, int flags, int, void *);
    const char *GenerateEntityName(const char *prefix);
    int SetTriggerSectorFunc(
        const char *trigger_sector_name, const char *func_type,
        PyObject *func
    );
    int GetTriggerSectorFloorHeight(const char *trigger_sector_name);
    int GetTriggerSectorRoofHeight(const char *trigger_sector_name);
    const char *GetTriggerSectorGroup(const char *trigger_sector_name);
    double *GetTriggerSectorPoints(const char *trigger_sector_name);
    PyObject *GetTriggerSectorFunc(
        const char *trigger_sector_name, const char *func_type
    );
    int SetTriggerSectorData(
        const char *trigger_sector_name, PyObject *data
    );
    PyObject *GetTriggerSectorData(const char *trigger_sector_name);
    int SaveEntitiesData(const char *filename);
    int LoadEntitiesData(const char *filename);
    const char *GetTriggerSectorName(int index);

    unsigned int NumEntities()
    {
        return entities.Size();
    }

    bool RemoveEntity(const char *name, int deleteEntity)
    {
        assert(name);
        entities.Remove(name, deleteEntity);
        return true;
    }

    B_Entity *GetEntity(const char *name)
    {
        assert(name);
        return entities.Get(name);
    }

    B_Entity *GetEntity(unsigned int i)
    {
        assert(i>=0);
        return entities.Get(i);
    }

    B_PtrArray<B_TriggerSector> triggerSectors;
    B_Hash<B_Entity> entities;
    int nextEntitySuffix;
    B_PtrArray<B_SubscriptionList> subscriptions;
    char unknownFields1840[28];
    B_Name world_file_name;
    char unknownFields1864[24];
    int unknown187C;
    int unknown1880;
    char unknownFields1884[40];
    B_PtrArray<atmosphere_t> atmospheres;
    B_Map map;
    B_OctTree octTree;
    B_Vector unknown18FC;
    double unknown1914;
    void *unknown191C;
    B_PtrArray<light_t> lights;
    char unknownFields1938[28];
    B_Vector initial_point_position;
    B_Vector initial_point_orientation;
};

B_IDataFile& operator >>(B_IDataFile& file, B_World *gs);

#ifdef __cplusplus
extern "C" {
#endif

/*
* Module:                 Blade.exe
* Data address:           0x005E0B88
*/
extern B_World B_world;

#ifdef __cplusplus
}
#endif


#endif /* GAME_STATE_H */

