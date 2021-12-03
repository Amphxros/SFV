#pragma once
#include "ParticleForceGenerator.h"
class ParticleBuoyancy :
    public ParticleForceGenerator
{
public:
    ParticleBuoyancy(float depth, float height, float density);
    virtual ~ParticleBuoyancy();
    virtual void integrateForce(Particle* p, float t) override;
    void setDepth(float depth) { maxDepth_ = depth; }
   

protected:
    Particle* mParticle_;
    float maxDepth_;
    float mHeightBody_;
    float mVolume_;
    float mDensityBody_;
};

