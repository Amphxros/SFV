#pragma once
#include "RigidBodySphereForce.h"
class RigidBodyExplosion :
    public RigidBodySphereForce
{
public:
    RigidBodyExplosion(Vector3 center, float rd, float forceMod,float lifeTime=1.0f);
    virtual ~RigidBodyExplosion();

    virtual void integrateForce(RigidBody* rb, float t) override;

    void activateExplosion(Vector3 center);
protected:
    float mForceMod_;
    float mLifeTime_;
    bool active_=false;
};

