#pragma once
#include "ParticleForceGenerator.h"
class ParticleGravity :
    public ParticleForceGenerator
{
public:
    ParticleGravity(Vector3 gravity);
    virtual ~ParticleGravity() {}

    virtual void integrateForce(Particle* particle, float t) override;
protected:
    Vector3 mGravity_;
};

