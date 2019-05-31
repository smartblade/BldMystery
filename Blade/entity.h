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
    camera_t *init(int unknown, const B_Name &name);
    camera_t(int unknown, const B_Name &name);
    void unknown_004EB1AA(void *);

    char unknownFields1[588];
    float unknownValueFromApplication;
    float *unknownPtrFromApplication;
    char unknownFields2[72];
};


#endif /* ENTITY_H */

