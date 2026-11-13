#ifndef PHYSICS_TEMPLATE_H

#define PHYSICS_TEMPLATE_H

#include <array.h>
#include <AnalyticGeometry/Matrix.h>
#include <Physics/ContactList.h>

class B_Name;
class B_Sector;
class B_Vector;
class B_BoundingBox;
class B_ObjDscr;
class B_PhysicsState;
class B_PhysicsTemplateBase;


class B_PhysicsTemplatePair
{
public:
    B_PhysicsTemplateBase *other;
    int active;
};


class B_PhysicsTemplateArray : public array_t<B_PhysicsTemplatePair>
{
};


class B_PhysicsTemplateBase
{
public:
    B_PhysicsTemplateBase()
    :
        group(0),
        mask(0),
        solidMask(0)
    {
    }

    virtual int ClassId() = 0;

    virtual ~B_PhysicsTemplateBase()
    {
    }

    virtual int unknown_method008(B_PhysicsTemplateBase *other) = 0;
    virtual int DetectCollisions(
        array_t<B_Sector *> *sectors,
        int unknown2,
        int unknown3
    ) = 0;
    virtual int unknown_method010(int unknown) = 0;
    virtual int BindConstraints() = 0;
    virtual const B_BoundingBox &GetBoundingBox() = 0;
    virtual void SetPose(const B_Matrix *pose) = 0;
    virtual B_Matrix &GetPose() = 0;

    /*
    * Module:                 Blade.exe
    * Entry point:            0x004B4550
    * VC++ mangling:          ?IntersectSegment@B_PhysicsTemplateBase@@UAEHABVB_Vector@@0AAV2@@Z
    */
#ifndef BLD_NATIVE
    virtual int IntersectSegment(
        const B_Vector &start,
        const B_Vector &end,
        B_Vector &hit
    )
    {
        return 0;
    }
#else
    virtual int IntersectSegment(
        const B_Vector &start,
        const B_Vector &end,
        B_Vector &hit
    );
#endif

    B_ContactList contacts;
    int unknownField038;
    int unknownField03C;
    int unknownField040;
    B_PhysicsTemplateArray pairs;
    int group;
    B_PhysicsTemplateBase *ignore;
    int mask;
    int solidMask;
};


class B_PhysicsStateCacheHandle
{
public:
    B_PhysicsStateCacheHandle()
    :
        version(0),
        state(nullptr)
    {
    }

    int version;
    int slot;
    B_PhysicsState *state;
};


class B_PhysicsTemplate : public B_PhysicsTemplateBase
{
public:
    B_PhysicsTemplate(const B_Name &name);
    B_PhysicsTemplate(B_ObjDscr *resource);

    /*
    * Module:                 Blade.exe
    * Entry point:            0x004B4680
    * VC++ mangling:          ?ClassId@B_PhysicsTemplate@@UAEHXZ
    */
#ifndef BLD_NATIVE
    virtual int ClassId()
    {
        return 0;
    }
#else
    virtual int ClassId();
#endif
    virtual ~B_PhysicsTemplate();
    virtual int unknown_method008(B_PhysicsTemplateBase *other);
    virtual int DetectCollisions(
        array_t<B_Sector *> *sectors,
        int unknown2,
        int unknown3
    );
    virtual int unknown_method010(int unknown);
    virtual int BindConstraints();
    virtual const B_BoundingBox &GetBoundingBox();
    virtual void SetPose(const B_Matrix *pose);

    /*
    * Module:                 Blade.exe
    * Entry point:            0x004B4690
    * VC++ mangling:          ?GetPose@B_PhysicsTemplate@@UAEAAVB_Matrix@@XZ
    */
#ifndef BLD_NATIVE
    virtual B_Matrix &GetPose()
    {
        return this->pose;
    }
#else
    virtual B_Matrix &GetPose();
#endif
    virtual int IntersectSegment(
        const B_Vector &start,
        const B_Vector &end,
        B_Vector &hit
    );

    B_PhysicsStateCacheHandle stateCache;
    B_ObjDscr *resource;
    B_Matrix pose;
    double scale;
    double invScale;
};

#endif /* PHYSICS_TEMPLATE_H */
