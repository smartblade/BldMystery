#ifndef ENTITY_H

#define ENTITY_H

#include "BBLibc.h"


#define PLAYER "Player1"

#ifdef __cplusplus

class entity_t :  public B_NamedObj
{
public:
    virtual ~entity_t();
    virtual void *unknown_method004();
    virtual void *unknown_method008();
    virtual void *unknown_method00C();
    virtual int is_type_of(int type);

    char unknownFields[404];
};

class biped_entity_t;
class person_t;

class camera_t : public entity_t
{
public:
    char unknownFields1[588];
    float unknownValueFromApplication;
    float *unknownPtrFromApplication;
    char unknownFields2[72];
};

#else

typedef struct {
        void *unknownFuncs[4];
        int (*is_type_of)(int type); /*person: 0x005305D5, camera: 0x004EACB3*/
} entity_methods_t;

typedef struct _entity_t {
        union {
                entity_methods_t *methods;
                B_NamedObj parent;
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

#endif /*__cplusplus*/

#ifndef BLD_EXT_FUNCS

#ifdef __cplusplus
extern "C" {
#endif

camera_t* camera_init(camera_t *self, int unknown, B_Name *name);

#ifdef __cplusplus
}
#endif

#endif /* BLD_EXT_FUNCS */

#endif /* ENTITY_H */

