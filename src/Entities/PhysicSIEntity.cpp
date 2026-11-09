#include <Entities/PhysicSIEntity.h>
#include <BBLibc/Name.h>


/*
* Module:                 Blade.exe
* Entry point:            0x00544700
* VC++ mangling:          ??0B_PhysicBody@@QAE@PAVB_PhysicsTemplate@@PAVB_PhysicSIEntity@@@Z
*/

#ifndef BLD_NATIVE
B_PhysicBody::B_PhysicBody(B_PhysicsTemplate *solid, B_PhysicSIEntity *entity)
:
    B_RigidBody(solid),
    entity(entity)
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
* Entry point:            0x00544919
* VC++ mangling:          ??0B_PhysicSIEntity@@QAE@ABVB_Name@@0H@Z
*/
#ifdef BLD_NATIVE_CONSTRUCTOR
B_PhysicSIEntity::B_PhysicSIEntity(
    const B_Name &name, const B_Name &kind, int load)
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/

