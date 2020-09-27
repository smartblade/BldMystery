#ifndef BIPED_ENTITY_H

#define BIPED_ENTITY_H

#include "Matrix.h"
#include <Entities/Entity.h>


class B_CharType;
class B_Event;

class Unknown0049A1EF
{
public:
    char unknownFields[36];
    B_Matrix transform;
};


class B_BipedData : public B_NamedObj
{
public:
    B_BipedData(const B_Name &bipedName, const B_Name &kind);

    char unknown_fields[0x74];
    B_CharType *charType;
    char unknown_fields84[0x78];
};


class B_BipedEntity : public B_Entity
{
public:
    void DoAction(
        const B_Name &action_name, double unknown1, int iUnknown,
        double *dUnknown
    );
    void DoActionWI(
        const B_Name &actionName, int interpolationType, double time,
        double unknown1, double *dUnknown, double unknown2
    );
    int SetOnFloor();
    int RaiseEvent(int eventIndex);

    char unknownFields01A0[12];
    Unknown0049A1EF *unknown01AC;
    char unknownFields01B0[0x1C0];
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
