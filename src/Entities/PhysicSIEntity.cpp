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
* Module:                 Blade.exe
* Entry point:            0x00544731
* VC++ mangling:          ?RemoveFromWorld@B_PhysicBody@@UAEXXZ
*/

void B_PhysicBody::RemoveFromWorld()
{
    this->entity->RemoveFromWorld();
}


/*
* Module:                 Blade.exe
* Entry point:            0x00544753
* VC++ mangling:          ?PutToWorld@B_PhysicBody@@UAEXXZ
*/

void B_PhysicBody::PutToWorld()
{
    this->entity->PutToWorld();
}


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

/*
* Module:                 Blade.exe
* Entry point:            0x005453E5
* VC++ mangling:          ?unknown_method0D4@B_PhysicSIEntity@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_PhysicSIEntity::unknown_method0D4()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0054540B
* VC++ mangling:          ?unknown_method0D8@B_PhysicSIEntity@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_PhysicSIEntity::unknown_method0D8()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x00545447
* VC++ mangling:          ?unknown_method0DC@B_PhysicSIEntity@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_PhysicSIEntity::unknown_method0DC()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x0054551A
* VC++ mangling:          ?unknown_method0E4@B_PhysicSIEntity@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_PhysicSIEntity::unknown_method0E4()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x005455B6
* VC++ mangling:          ?ImpulseC@B_PhysicSIEntity@@UAEXAAVB_Vector@@0@Z
*/
#ifndef BLD_NATIVE
void B_PhysicSIEntity::ImpulseC(B_Vector &position, B_Vector &direction)
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
* Entry point:            0x00546671
* VC++ mangling:          ?unknown_method0E8@B_PhysicSIEntity@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_PhysicSIEntity::unknown_method0E8()
{
}
#endif

/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
