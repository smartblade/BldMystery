#include <Physics/RigidBody.h>
#include <Physics/PhysicsTemplate.h>


/*
* Module:                 Blade.exe
* Entry point:            0x004AAF00
* VC++ mangling:          ??0B_RigidBody@@QAE@PAVB_PhysicsTemplate@@@Z
*/

#ifndef BLD_NATIVE
B_RigidBody::B_RigidBody(B_PhysicsTemplate *solid)
{
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004AB1E0
* VC++ mangling:          ??1B_RigidBody@@UAE@XZ
*/

#ifndef BLD_NATIVE
B_RigidBody::~B_RigidBody()
{
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004AB1FD
* VC++ mangling:          ?RemoveFromWorld@B_RigidBody@@UAEXXZ
*/

void B_RigidBody::RemoveFromWorld()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004AB208
* VC++ mangling:          ?PutToWorld@B_RigidBody@@UAEXXZ
*/

void B_RigidBody::PutToWorld()
{
}


/*
* Module:                 Blade.exe
* Entry point:            0x004AB213
* VC++ mangling:          ?GetSolid@B_RigidBody@@UAEPAVB_PhysicsTemplateBase@@XZ
*/

B_PhysicsTemplateBase *B_RigidBody::GetSolid()
{
    return this->solid;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004AB224
* VC++ mangling:          ?unknown_method010@B_RigidBody@@UAEHXZ
*/

int B_RigidBody::unknown_method010()
{
    return this->unknownField0D8 - this->unknownField0E0 > 1.0;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x004AB33E
* VC++ mangling:          ?unknown_method018@B_RigidBody@@UAENXZ
*/

double B_RigidBody::unknown_method018()
{
    return this->unknownField0C0;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
