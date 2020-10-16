#include <Entities/BipedEntity.h>

#include <bld_system.h>


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004D6B8A
* VC++ mangling:          ?GetEventTime@B_BipedAction@@QAENPBD@Z
*/
#ifdef BLD_NATIVE
double B_BipedAction::GetEventTime(const char *eventName)
{
    return 0.0;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004D741B
* VC++ mangling:          ??0B_BipedData@@QAE@ABVB_Name@@0@Z
*/
#ifdef BLD_NATIVE
B_BipedData::B_BipedData(const B_Name &bipedName, const B_Name &kind)
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004D7990
* VC++ mangling:          ?GetNodePose@B_BipedData@@QAEABVB_Matrix@@PAVB_BipedAction@@MH@Z
*/
#ifdef BLD_NATIVE
const B_Matrix &B_BipedData::GetNodePose(
    B_BipedAction *action, float time, int nodeIndex)
{
    return *(new B_Matrix());
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004D7A82
* VC++ mangling:          ?GetPose@B_BipedData@@QAEABVB_Matrix@@PAVB_BipedAction@@M@Z
*/
#ifdef BLD_NATIVE
const B_Matrix &B_BipedData::GetPose(B_BipedAction *action, float time)
{
    return *(new B_Matrix());
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x004D7D97
* VC++ mangling:          ?GetRightFootPose@B_BipedData@@QAEHPAVB_BipedAction@@MPAVB_Vector@@1@Z
*/
#ifdef BLD_NATIVE
int B_BipedData::GetRightFootPose(
    B_BipedAction *action, float time, B_Vector *, B_Vector *)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x04D7E72
* VC++ mangling:          ?GetLeftFootPose@B_BipedData@@QAEHPAVB_BipedAction@@MPAVB_Vector@@1@Z
*/
#ifdef BLD_NATIVE
int B_BipedData::GetLeftFootPose(
    B_BipedAction *action, float time, B_Vector *, B_Vector *)
{
    return 0;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004DDB85
* VC++ mangling:          ?GetAngle@B_BipedEntity@@QAENXZ
*/
#ifdef BLD_NATIVE
double B_BipedEntity::GetAngle()
{
    return 0;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004E3AD9
* VC++ mangling:          ?DoAction@B_BipedEntity@@QAEXABVB_Name@@NHPAN@Z
*/
#ifdef BLD_NATIVE
void B_BipedEntity::DoAction(
    const B_Name &action_name, double unknown1, int iUnknown,
    double *dUnknown)
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004E3B6A
* VC++ mangling:          ?DoActionWI@B_BipedEntity@@QAEXABVB_Name@@HNNPANN@Z
*/
#ifdef BLD_NATIVE
void B_BipedEntity::DoActionWI(
    const B_Name &actionName, int interpolationType, double time,
    double unknown1, double *dUnknown, double unknown2)
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004E56DE
* VC++ mangling:          ?IsIncorrectPosition@B_BipedEntity@@QAEHABVB_Vector@@@Z
*/
#ifdef BLD_NATIVE
int B_BipedEntity::IsIncorrectPosition(const B_Vector &pos)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004E5798
* VC++ mangling:          ?unknown004E5798@B_BipedEntity@@QAEXABVB_Vector@@@Z
*/
#ifdef BLD_NATIVE
void B_BipedEntity::unknown004E5798(const B_Vector &pos)
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004E5DA7
* VC++ mangling:          ?SetOnFloor@B_BipedEntity@@QAEHXZ
*/
#ifdef BLD_NATIVE
int B_BipedEntity::SetOnFloor()
{
    return 0;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004E73AF
* VC++ mangling:          ?RaiseEvent@B_BipedEntity@@QAEHH@Z
*/
#ifdef BLD_NATIVE
int B_BipedEntity::RaiseEvent(int eventIndex)
{
    return 0;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

/*
* Module:                 Blade.exe
* Entry point:            0x004E7E61
* VC++ mangling:          ?GetFloorHeight@B_BipedEntity@@QAENPAX0@Z
*/
#ifdef BLD_NATIVE
double B_BipedEntity::GetFloorHeight(void *unknown1, void *unknown2)
{
    return 0.0;
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
