#ifndef RIGID_BODY_H

#define RIGID_BODY_H

#include <AnalyticGeometry/Vector.h>
#include <AnalyticGeometry/Matrix.h>

class B_Entity;
class B_PhysicsTemplateBase;
class B_PhysicsTemplate;


class B_PhysicsNode
{
public:
    B_PhysicsNode()
    :
        owner(nullptr)
    {
    }

    virtual ~B_PhysicsNode()
    {
    }

    virtual void RemoveFromWorld() = 0;
    virtual void PutToWorld() = 0;
    virtual B_PhysicsTemplateBase *GetSolid() = 0;
    virtual int unknown_method010() = 0;
    virtual void ResetForcesAndPose(double time) = 0;
    virtual double unknown_method018() = 0;
    virtual void unknown_method01C(double unknown) = 0;
    virtual void unknown_method020() = 0;
    virtual int unknown_method024(double time) = 0;
    virtual B_Vector GetWorldCenterOfMass() = 0;
    virtual void CalculateImpulseDeltas(
        const B_Vector &worldPoint,
        const B_Vector &worldImpulse,
        B_Vector &linearDelta,
        B_Vector &angularDelta,
        B_Vector &centerOfMass
    ) = 0;
    virtual const B_Vector &ApplyImpulseAtPoint(
        const B_Vector &worldPoint,
        const B_Vector &worldImpulse
    ) = 0;

    B_Vector linearImpulse;
    B_Vector angularImpulse;
    B_Entity *owner;
};


class B_RigidBody : public B_PhysicsNode
{
public:
    B_RigidBody(B_PhysicsTemplate *solid);
    virtual ~B_RigidBody();
    virtual void RemoveFromWorld();
    virtual void PutToWorld();
    virtual B_PhysicsTemplateBase *GetSolid();
    virtual int unknown_method010();
    virtual void ResetForcesAndPose(double time);
    virtual double unknown_method018();
    virtual void unknown_method01C(double unknown);
    virtual void unknown_method020();
    virtual int unknown_method024(double time);
    virtual B_Vector GetWorldCenterOfMass();
    virtual void CalculateImpulseDeltas(
        const B_Vector &worldPoint,
        const B_Vector &worldImpulse,
        B_Vector &linearDelta,
        B_Vector &angularDelta,
        B_Vector &centerOfMass
    );
    virtual const B_Vector &ApplyImpulseAtPoint(
        const B_Vector &worldPoint,
        const B_Vector &worldImpulse
    );

    int materialId;
    B_PhysicsTemplate *solid;
    B_Matrix pose;
    double unknownField0C0;
    double unknownField0C8;
    double timeStep;
    double unknownField0D8;
    double unknownField0E0;
    B_Matrix inverseInertiaWorld;
    double mass;
    B_Vector worldCenterOfMass;
    B_Vector previousCenterOfMass;
    B_Vector gravity;
};

#endif /* RIGID_BODY_H */
