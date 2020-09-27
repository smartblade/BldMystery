#include <Entities/BipedEntity.h>

#include <bld_system.h>


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
