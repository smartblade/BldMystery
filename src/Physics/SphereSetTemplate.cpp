#include <Physics/SphereSetTemplate.h>


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x004B483E
* VC++ mangling:          ??0B_SphereSetTemplate@@QAE@PAV?$array_t@VB_Sphere@@@@@Z
*/

#ifndef BLD_NATIVE
B_SphereSetTemplate::B_SphereSetTemplate(array_t<B_Sphere> *spheres)
{
}
#endif


/*
* Module:                 Blade.exe
* Entry point:            0x004B48F3
* VC++ mangling:          ??1B_SphereSetTemplate@@UAE@XZ
*/

#ifndef BLD_NATIVE
B_SphereSetTemplate::~B_SphereSetTemplate()
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
* Entry point:            0x004B4E76
* VC++ mangling:          ?DetectCollisions@B_SphereSetTemplate@@UAEHPAV?$array_t@PAVB_Sector@@@@HH@Z
*/
#ifndef BLD_NATIVE
int B_SphereSetTemplate::DetectCollisions(
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
* Entry point:            0x004B550A
* VC++ mangling:          ?BindConstraints@B_SphereSetTemplate@@UAEHXZ
*/

int B_SphereSetTemplate::BindConstraints()
{
    return 2;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004B551A
* VC++ mangling:          ?unknown_method008@B_SphereSetTemplate@@UAEHPAVB_PhysicsTemplateBase@@@Z
*/

int B_SphereSetTemplate::unknown_method008(B_PhysicsTemplateBase *other)
{
    return 0;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004B5529
* VC++ mangling:          ?unknown_method010@B_SphereSetTemplate@@UAEHH@Z
*/

int B_SphereSetTemplate::unknown_method010(int unknown)
{
    return 2;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004B553B
* VC++ mangling:          ?GetBoundingBox@B_SphereSetTemplate@@UAEABVB_BoundingBox@@XZ
*/

const B_BoundingBox &B_SphereSetTemplate::GetBoundingBox()
{
    return this->boundingBox;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004B554E
* VC++ mangling:          ?SetPose@B_SphereSetTemplate@@UAEXPBVB_Matrix@@@Z
*/

void B_SphereSetTemplate::SetPose(const B_Matrix *pose)
{
    this->pose = *pose;
}


/*
* Module:                 Blade.exe
* Entry point:            0x004B556F
* VC++ mangling:          ?GetPose@B_SphereSetTemplate@@UAEAAVB_Matrix@@XZ
*/

B_Matrix &B_SphereSetTemplate::GetPose()
{
    return this->pose;
}


/*
................................................................................
................................................................................
................................................................................
................................................................................
*/


/*
* Module:                 Blade.exe
* Entry point:            0x004B8202
* VC++ mangling:          ?IntersectSegment@B_SphereSetTemplate@@UAEHABVB_Vector@@0AAV2@@Z
*/
#ifndef BLD_NATIVE
int B_SphereSetTemplate::IntersectSegment(
    const B_Vector &start,
    const B_Vector &end,
    B_Vector &hit
)
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
