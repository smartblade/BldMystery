#ifndef ENTITY_H

#define ENTITY_H


#define PLAYER "Player1"


typedef struct {
        void *unknownFuncs[4];
        int (*is_type_of)(int type); /*person: 0x005305D5, camera: 0x004EACB3*/
} entity_methods_t;

typedef struct _entity_t {
        union {
                entity_methods_t *methods;
                BBLibc_named_object_t parent;
        };
        char unknownFields[404];
} entity_t;

typedef struct {
        union {
                entity_methods_t *methods;
                entity_t parent;
        };
        char unknownFields[4220];
} biped_entity_t;

typedef struct {
        union {
                entity_methods_t *methods;
                biped_entity_t parent;
        };
        char unknownFields[3676];
} person_t;

typedef struct {
        union {
                entity_methods_t *methods;
                entity_t parent;
        };
        char unknownFields1[588];
        float unknownValueFromApplication;
        float *unknownPtrFromApplication;
        char unknownFields2[72];
} camera_t;

#ifndef BLD_EXT_FUNCS

camera_t* camera_init(camera_t *self, int unknown, BBLibc_name_t *name);

#endif

#endif /* ENTITY_H */

