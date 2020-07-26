
#ifndef GAME_STATE_H

#define GAME_STATE_H


#include <array.h>
#include "entity.h"
#include "atmosphere.h"
#include "BMap.h"
#include "light.h"
#include "vector.h"
#include <bld_python.h>


typedef struct {
    double x;
    double y;
    double z;
    int unknown10;
    int unknown14;
} world_point_t;

typedef struct {
    int numEntities;
    B_PtrArray<B_Entity> hash[256];
    int unknown1804;
    B_Entity *foundEntity;
} B_Entities;


class unknown_18F8_class
{
public:
    void unknown_00451A21(void *, int, int);
    int field;
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
    double get_time();
    int SetTime(double time);
    void GoToTime(double time);
    void AddScheduledFunc(
        double time, PyObject *func, PyObject *args, const char *name);
    void SetSun(int exists, const B_Vector &position);
    int FindSectorIndex(const B_Vector &point);
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

    B_PtrArray<B_TriggerSector> triggerSectors;
    B_Entities entities;
    int nextEntitySuffix;
    B_PtrArray<void> unknown1828;
    char unknownFields1840[28];
    B_Name world_file_name;
    char unknownFields1864[24];
    int unknown187C;
    int unknown1880;
    char unknownFields1884[40];
    B_PtrArray<atmosphere_t> atmospheres;
    B_Map map;
    unknown_18F8_class unknown18F8;
    B_Vector unknown18FC;
    double unknown1914;
    void *unknown191C;
    B_PtrArray<light_t> lights;
    char unknownFields1938[28];
    B_Vector initial_point_position;
    B_Vector initial_point_orientation;
};

#ifdef __cplusplus

B_IDataFile& operator >>(B_IDataFile& file, B_World *gs);

#endif


#endif /* GAME_STATE_H */

