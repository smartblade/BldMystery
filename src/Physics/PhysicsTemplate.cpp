#include <Physics/PhysicsTemplate.h>
#include <Physics/PhysicsState.h>
#include <AnalyticGeometry/BoundingBox.h>


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x004ACE39
* VC++ mangling:          ??0B_PhysicsTemplate@@QAE@ABVB_Name@@@Z
*/

#ifndef BLD_NATIVE
B_PhysicsTemplate::B_PhysicsTemplate(const B_Name &name)
{
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004ACF58
* VC++ mangling:          ??0B_PhysicsTemplate@@QAE@PAVB_ObjDscr@@@Z
*/

#ifndef BLD_NATIVE
B_PhysicsTemplate::B_PhysicsTemplate(B_ObjDscr *resource)
{
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004AD047
* VC++ mangling:          ??1B_PhysicsTemplate@@UAE@XZ
*/

#ifndef BLD_NATIVE
B_PhysicsTemplate::~B_PhysicsTemplate()
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004AD615
* VC++ mangling:          ?SetPose@B_PhysicsTemplate@@UAEXPBVB_Matrix@@@Z
*/
#ifndef BLD_NATIVE
void B_PhysicsTemplate::SetPose(const B_Matrix *pose)
{
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004B1203
* VC++ mangling:          ?DetectCollisions@B_PhysicsTemplate@@UAEHPAV?$array_t@PAVB_Sector@@@@HH@Z
*/
#ifndef BLD_NATIVE
int B_PhysicsTemplate::DetectCollisions(
    array_t<B_Sector *> *sectors,
    int unknown2,
    int unknown3
)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004B3000
* VC++ mangling:          ?BindConstraints@B_PhysicsTemplate@@UAEHXZ
*/
#ifndef BLD_NATIVE
int B_PhysicsTemplate::BindConstraints()
{
    return 0;
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004AD0E7
* VC++ mangling:          ?Update@B_PhysicsTemplate@@QAEXXZ
*/

#ifndef BLD_NATIVE
void B_PhysicsTemplate::Update()
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
* Entry point:            0x004B30A4
* VC++ mangling:          ?unknown_method008@B_PhysicsTemplate@@UAEHPAVB_PhysicsTemplateBase@@@Z
*/

int B_PhysicsTemplate::unknown_method008(B_PhysicsTemplateBase *other)
{
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004B30B3
* VC++ mangling:          ?unknown_method010@B_PhysicsTemplate@@UAEHH@Z
*/

int B_PhysicsTemplate::unknown_method010(int unknown)
{
    return 2;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004B34AF
* VC++ mangling:          ?IntersectSegment@B_PhysicsTemplate@@UAEHABVB_Vector@@0AAV2@@Z
*/
#ifndef BLD_NATIVE
int B_PhysicsTemplate::IntersectSegment(
    const B_Vector &start,
    const B_Vector &end,
    B_Vector &hit
)
{
    return 0;
}
#endif

/*
* Module:                 Blade.exe
* Entry point:            0x004B3978
* VC++ mangling:          ?GetBoundingBox@B_PhysicsTemplate@@UAEABVB_BoundingBox@@XZ
*/
#ifndef BLD_NATIVE
const B_BoundingBox &B_PhysicsTemplate::GetBoundingBox()
{
    static B_BoundingBox stub;
    return stub;
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
* Entry point:            0x004B3978
* VC++ mangling:          ?GetBoundingBox@B_PhysicsTemplate@@UAEABVB_BoundingBox@@XZ
*/

const B_BoundingBox &B_PhysicsTemplate::GetBoundingBox()
{
    this->Update();
    return this->stateCache.state->boundingBox;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/
