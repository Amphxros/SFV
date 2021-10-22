#pragma once
#include "ParticleForceGenerator.h"
class ParticleGravity :
    public ParticleForceGenerator
{
public:
    ParticleGravity(const Vector3& gravity);
    virtual void integrateForce(Particle* p, float t);
protected:
    Vector3 mGravity_;

};

