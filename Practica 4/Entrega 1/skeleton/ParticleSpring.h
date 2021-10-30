#pragma once
#include "ParticleForceGenerator.h"
class ParticleSpring :
    public ParticleForceGenerator
{
public:
    ParticleSpring(Vector3 pos, Vector4 col, float k);
    virtual ~ParticleSpring();

    virtual void integrateForce(Particle* p, float t) override;


protected:
    Particle* mParticle_;
    float mK_;
};

