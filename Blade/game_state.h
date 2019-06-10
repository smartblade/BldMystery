
#ifndef GAME_STATE_H

#define GAME_STATE_H


#include "array.h"
#include "entity.h"
#include "atmosphere.h"
#include "sector.h"
#include "light.h"
#include "vector.h"


typedef struct {
        double x;
        double y;
        double z;
        int unknown10;
        int unknown14;
} world_point_t;

typedef struct {
        int numEntities;
        array_t<entity_t *> hash[256];
        int unknown1804;
        entity_t *foundEntity;
} world_t;


typedef struct {
        void *unknown_methods[1];
} game_state_methods_t;

class unknown_18F8_class
{
public:
    void unknown_00451A21(void *, int, int);
    int field;
};

class game_state_t
{
public:
        void unknown_00439F5D();
        double get_time();
        int SaveEntitiesData(const char *filename);
        int LoadEntitiesData(const char *filename);

        game_state_methods_t *methods;
        char unknownFields[20];
        world_t world;
        int nextEntitySuffix;
        array_t<int> unknown1828;
        char unknownFields1840[28];
        B_Name world_file_name;
        char unknownFields1864[24];
        int unknown187C;
        int unknown1880;
        char unknownFields1884[40];
        array_t<atmosphere_t *> atmospheres;
        array_t<sector_t *> sectors;
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

B_IDataFile& operator >>(B_IDataFile& file, game_state_t *gs);

#endif


#endif /* GAME_STATE_H */

