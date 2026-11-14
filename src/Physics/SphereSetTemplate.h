#ifndef SPHERE_SET_TEMPLATE_H

#define SPHERE_SET_TEMPLATE_H

#include <BBLibc/array.h>
#include <AnalyticGeometry/Matrix.h>
#include <AnalyticGeometry/BoundingBox.h>
#include <Physics/PhysicsTemplate.h>


class B_SphereSetTemplate : public B_PhysicsTemplateBase
{
public:
    B_SphereSetTemplate(array_t<B_Sphere> *spheres);

    /*
    * Module:                 Blade.exe
    * Entry point:            0x004B84C0
    * VC++ mangling:          ?ClassId@B_SphereSetTemplate@@UAEHXZ
    */
#ifndef BLD_NATIVE
    virtual int ClassId()
    {
        return 0;
    }
#else
    virtual int ClassId();
#endif
    virtual ~B_SphereSetTemplate();
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
    virtual B_Matrix &GetPose();
    virtual int IntersectSegment(
        const B_Vector &start,
        const B_Vector &end,
        B_Vector &hit
    );

    B_Matrix pose;
    B_BoundingBox boundingBox;
    array_t<B_Sphere> *spheres;
};

#endif /* SPHERE_SET_TEMPLATE_H */
