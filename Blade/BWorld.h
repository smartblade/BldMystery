
#ifndef GAME_STATE_H

#define GAME_STATE_H


#include <array.h>
#include "entity.h"
#include "atmosphere.h"
#include "sector.h"
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
        array_t<B_Entity *> hash[256];
        int unknown1804;
        B_Entity *foundEntity;
} world_t;


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
    array_t<void *> a054;
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
        void SetSun(int exists, const B_Vector &position);
        int FindSectorIndex(const B_Vector &point);
        const char *GenerateEntityName(const char *prefix);
        int SetTriggerSectorFunc(
            const char *trigger_sector_name, const char *func_type,
            PyObject *func
        );
        int GetTriggerSectorFloorHeight(const char *trigger_sector_name);
        int GetTriggerSectorRoofHeight(const char *trigger_sector_name);
        PyObject *GetTriggerSectorFunc(
            const char *trigger_sector_name, const char *func_type
        );
        int SaveEntitiesData(const char *filename);
        int LoadEntitiesData(const char *filename);

        array_t<B_TriggerSector *> triggerSectors;
        world_t world;
        int nextEntitySuffix;
        array_t<void *> unknown1828;
        char unknownFields1840[28];
        B_Name world_file_name;
        char unknownFields1864[24];
        int unknown187C;
        int unknown1880;
        char unknownFields1884[40];
        array_t<atmosphere_t *> atmospheres;
        array_t<B_Sector *> sectors;
        char unknownFields18DC[28];
        unknown_18F8_class unknown18F8;
        B_Vector unknown18FC;
        double unknown1914;
        void *unknown191C;
        array_t<light_t *> lights;
        char unknownFields1938[28];
        B_Vector initial_point_position;
        B_Vector initial_point_orientation;
};

#ifdef __cplusplus

B_IDataFile& operator >>(B_IDataFile& file, B_World *gs);

#endif


#endif /* GAME_STATE_H */

