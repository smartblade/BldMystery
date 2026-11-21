#ifndef PHYSICS_MANAGER_H

#define PHYSICS_MANAGER_H

#include <BBLibc/array.h>
#include <Physics/RigidBody.h>


class B_PhysicsGroup
{
public:
    ~B_PhysicsGroup();

    double time;
    double timeStep;
    B_SharedPtrArray<B_PhysicsNode> nodes;
    char unknownFields028[0x18];
    int unknown040;
};


class B_PhysicsManager
{
public:
    B_PhysicsManager(double timeStep);

    double time;
    double timeStep;
    B_SharedPtrArray<B_PhysicsGroup> groups;
};

#endif /* PHYSICS_MANAGER_H */
