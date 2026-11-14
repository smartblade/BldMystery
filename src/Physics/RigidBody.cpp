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
* Module:                 Blade.exe
* Entry point:            0x004AB257
* VC++ mangling:          ?ResetForcesAndPose@B_RigidBody@@UAEXN@Z
*/

void B_RigidBody::ResetForcesAndPose(double time)
{
    this->unknownField0C0 = time;
    this->unknownField0D8 = time;
    this->unknownField0C8 = time;
    this->unknownField0E0 = time;
    this->pose = this->solid->pose;
    this->solid->contacts.Clear();
    B_Vector zero;
    this->linearImpulse = this->angularImpulse = zero;
    this->unknown_method020();
}


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
* Module:                 Blade.exe
* Entry point:            0x004AB352
* VC++ mangling:          ?unknown_method020@B_RigidBody@@UAEXXZ
*/
#ifndef BLD_NATIVE
void B_RigidBody::unknown_method020()
{
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004AB7D9
* VC++ mangling:          ?unknown_method01C@B_RigidBody@@UAEXN@Z
*/

void B_RigidBody::unknown_method01C(double unknown)
{
    this->unknownField0D8 = unknown;
    this->unknown_method020();
}


/*
* Module:                 Blade.exe
* Entry point:            0x004AB806
* VC++ mangling:          ?unknown_method024@B_RigidBody@@UAEHN@Z
*/
#ifndef BLD_NATIVE
int B_RigidBody::unknown_method024(double time)
{
    return 0;
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004ABB97
* VC++ mangling:          ?GetWorldCenterOfMass@B_RigidBody@@UAE?AVB_Vector@@XZ
*/

B_Vector B_RigidBody::GetWorldCenterOfMass()
{
    return this->worldCenterOfMass;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004ABBBE
* VC++ mangling:          ?CalculateImpulseDeltas@B_RigidBody@@UAEXABVB_Vector@@0AAV2@11@Z
*/
#ifndef BLD_NATIVE
void B_RigidBody::CalculateImpulseDeltas(
    const B_Vector &worldPoint,
    const B_Vector &worldImpulse,
    B_Vector &linearDelta,
    B_Vector &angularDelta,
    B_Vector &centerOfMass
)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004ABC53
* VC++ mangling:          ?ApplyImpulseAtPoint@B_RigidBody@@UAEABVB_Vector@@ABV2@0@Z
*/
#ifndef BLD_NATIVE
const B_Vector &B_RigidBody::ApplyImpulseAtPoint(
    const B_Vector &worldPoint,
    const B_Vector &worldImpulse
)
{
    return worldPoint;
}
#endif
