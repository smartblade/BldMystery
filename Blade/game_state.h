
#ifndef GAME_STATE_H

#define GAME_STATE_H


#include "array.h"
#include "entity.h"
#include "atmosphere.h"


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
        char unknownFields1840[108];
        array_t atmospheres;
} game_state_t;


#endif /* GAME_STATE_H */

