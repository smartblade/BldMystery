#ifndef BIPED_ENTITY_H

#define BIPED_ENTITY_H

#include <AnalyticGeometry/Matrix.h>
#include <Control/Events.h>
#include <Entities/Entity.h>


class B_CharType;
class B_Event;

class Unknown0049A1EF
{
public:
    char unknownFields[36];
    B_Matrix transform;
};


class B_BipedAction : public B_NamedObj
{
public:
    double GetEventTime(const char *eventName);

    char unknown_fields[0x28];
    B_EventFuncs *eventTable;
};


class B_BipedData : public B_NamedObj
{
public:
    B_BipedData(const B_Name &bipedName, const B_Name &kind);
    const B_Matrix &GetNodePose(
        B_BipedAction *action, float time, int nodeIndex);
    const B_Matrix &GetPose(B_BipedAction *action, float time);
    int GetRightFootPose(
        B_BipedAction *action, float time, B_Vector *, B_Vector *);
    int GetLeftFootPose(
        B_BipedAction *action, float time, B_Vector *, B_Vector *);

    char unknown_fields[0x24];
    B_PtrArray<B_BipedAction> actions;
    char unknown_fields48[0x38];
    B_CharType *charType;
    char unknown_fields84[0x78];
};


class B_BipedEntity : public B_Entity
{
public:
    virtual void unknown_method0D4();
    virtual void unknown_method0D8();
    virtual void unknown_method0DC();
    virtual void unknown_method0E0();
    virtual void unknown_method0E4();
    virtual int GetNodeIndex(const B_Name &nodeName);
    virtual void unknown_method0EC();
    double GetAngle();
    void DoAction(
        const B_Name &action_name, double unknown1, int iUnknown,
        double *dUnknown
    );
    void DoActionWI(
        const B_Name &actionName, int interpolationType, double time,
        double unknown1, double *dUnknown, double unknown2
    );
    int IsIncorrectPosition(const B_Vector &pos);
    void unknown004E5798(const B_Vector &pos);
    int SetOnFloor();
    int RaiseEvent(int eventIndex);
    double GetFloorHeight(void *unknown1, void *unknown2);

    B_BipedData *data;
    char unknownFields01A4[0x8];
    Unknown0049A1EF *unknown01AC;
    char unknownFields01B0[0x160];
    B_EventFuncs eventTable;
    char unknownFields0330[0x40];
    int unknown0370;
    char unknownFields0374[0xEB0];
};

#ifdef __cplusplus
extern "C" {
#endif

/*
* Module:                 Blade.exe
* Data address:           0x007C9878
*/
extern B_PtrArray<B_BipedData> gbl_bipeds;

#ifdef __cplusplus
}
#endif

#endif /* BIPED_ENTITY_H */
