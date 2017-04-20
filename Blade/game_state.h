
#ifndef GAME_STATE_H

#define GAME_STATE_H


#include "array.h"
#include "entity.h"
#include "atmosphere.h"


typedef struct {
        double x;
        double y;
        double z;
        int unknown10;
        int unknown14;
} world_point_t;

typedef struct {
        double x;
        double y;
        double z;
} point_t;

typedef struct {
        int numEntities;
        array_t hash[256];
        int unknown1804;
        entity_t *foundEntity;
} world_t;


typedef struct {
        void *unknown_methods[1];
} game_state_methods_t;

typedef struct {
        game_state_methods_t *methods;
        char unknownFields[20];
        world_t world;
        void *unknown1824;
        array_t unknown1828;
        char unknownFields1840[60];
        int unknown187C;
        int unknown1880;
        char unknownFields1884[40];
        array_t atmospheres;
        array_t sectors;
        char unknownFields18DC[68];
        array_t lights;
        char unknownFields1938[28];
        point_t initial_point_position;
        point_t initial_point_orientation;
} game_state_t;

#ifdef __cplusplus

B_IDataFile& operator >>(B_IDataFile& file, game_state_t *gs);

#endif


#endif /* GAME_STATE_H */

