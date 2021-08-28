#ifndef ENTITY_H

#define ENTITY_H

#include "BBLibc.h"


#define PLAYER "Player1"

#define B_ENTITY_CID_OBJECT            1
#define B_ENTITY_CID_PHYSIC_OBJECT     2
#define B_ENTITY_CID_PERSON            4
#define B_ENTITY_CID_WEAPON            6
#define B_ENTITY_CID_CAMERA            8
#define B_ENTITY_CID_ACTOR             13
#define B_ENTITY_CID_BIPED             21
#define B_ENTITY_CID_CLIENT            26
#define B_ENTITY_CID_AURA              27


class B_Matrix;

class B_Entity :  public B_NamedObj
{
public:
    virtual ~B_Entity();
    virtual void *unknown_method004();
    virtual void *unknown_method008();
    virtual int ClassId();
    virtual int IsClassOf(int type);
    virtual void unknown_method014();
    virtual const char *GetKind();
    virtual void unknown_method01C();
    virtual const B_Matrix &GetPose();
    virtual void SetPose(const B_Matrix &pose);
    virtual void unknown_method028();
    virtual void unknown_method02C();
    virtual void unknown_method030();
    virtual void PutToWorld();
    virtual void RemoveFromWorld();
    virtual void RemoveFromWorldWithChilds();
    virtual void unknown_method040();
    virtual void unknown_method044();
    virtual void unknown_method048();
    virtual void unknown_method04C();
    virtual void unknown_method050();
    virtual void unknown_method054();
    virtual void unknown_method058();
    virtual void unknown_method05C();
    virtual void unknown_method060();
    virtual void unknown_method064();
    virtual void unknown_method068();
    virtual void unknown_method06C();
    virtual void unknown_method070();
    virtual void unknown_method074();
    virtual void unknown_method078();
    virtual void unknown_method07C();
    virtual void unknown_method080();
    virtual void unknown_method084();
    virtual void unknown_method088();
    virtual void unknown_method08C();
    virtual void unknown_method090();
    virtual void unknown_method094();
    virtual void unknown_method098();
    virtual void unknown_method09C();
    virtual void unknown_method0A0();
    virtual void unknown_method0A4();
    virtual void unknown_method0A8();
    virtual void unknown_method0AC();
    virtual void unknown_method0B0();
    virtual void unknown_method0B4();
    virtual void unknown_method0B8();
    virtual void unknown_method0BC();
    virtual void unknown_method0C0();
    virtual void Use(int unknown);
    virtual void unknown_method0C8();
    virtual void unknown_method0CC();
    virtual void unknown_method0D0();

    char unknownFields[0x38];
    PyObject *timerFunc;
    int unknown048;
    PyObject *frameFunc;
    int unknown050;
    PyObject *hitFunc;
    char unknownFields058[0x2C];
    PyObject *func084;
    char unknownFields088[0xD0];
    PyObject *data;
    int sendSectorMsgs;
    int sendTriggerSectorMsgs;
    char unknownFields164[0x3C];
};

#endif /* ENTITY_H */

