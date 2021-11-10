#pragma once
#include "ParticleForceGenerator.h"
class ParticleBuoyancy :
    public ParticleForceGenerator
{
public:
    ParticleBuoyancy(Particle* particle, float depth, float height, float density);
    virtual ~ParticleBuoyancy();
    virtual void integrateForce(Particle* p, float t) override;

    bool isParticleOnMyBody(Particle* p);

protected:
    Particle* mParticle_;
    float maxDepth_;
    float mHeightBody_;
    float mVolume_;
    float mDensityBody_;
};

