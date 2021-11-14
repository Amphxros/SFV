#pragma once
#include "ParticleForceGenerator.h"
class ParticleAnchoredSpring :
    public ParticleForceGenerator
{
public:
    ParticleAnchoredSpring(Vector3 anchor, float k,float restLength);
    virtual ~ParticleAnchoredSpring();
    virtual void integrateForce(Particle* p, float t) override;

protected:
    float mK_;
    float mRestLength_;
    Vector3 mAnchor_;
};

