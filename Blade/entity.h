#ifndef ENTITY_H

#define ENTITY_H

#include "BBLibc.h"


#define PLAYER "Player1"

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

class biped_entity_t : public entity_t
{
    char unknownFields[4220];
};

class person_t : public biped_entity_t
{
    char unknownFields[3676];
};

class camera_t : public entity_t
{
public:
    char unknownFields1[588];
    float unknownValueFromApplication;
    float *unknownPtrFromApplication;
    char unknownFields2[72];
};


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

