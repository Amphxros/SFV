#pragma once
#include "ParticleForceGenerator.h"
class ParticleDrag :
    public ParticleForceGenerator
{
public:
    ParticleDrag(float k1,float k2);
    virtual ~ParticleDrag() {}
    virtual void integrateForce(Particle* p, float t) override;

protected:
    float k1_;  //coefficient for velocity
    float k2_;  //coefficient for squared velocity
};

