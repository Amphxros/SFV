#pragma once
#include "RigidBodySphereForce.h"
class RigidBodyExplosion :
    public RigidBodySphereForce
{
public:
    RigidBodyExplosion(Vector3 center, float rd, float forceMod);
    virtual ~RigidBodyExplosion();

    virtual void integrateForce(RigidBody* rb, float t) override;
protected:
    float mForceMod_;
};

