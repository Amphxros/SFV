#pragma once
#include "ParticleForceGenerator.h"
class ParticleSpring :
    public ParticleForceGenerator
{
public:
    ParticleSpring(Vector3 pos, Vector4 col, float k, float restLength);
    virtual ~ParticleSpring();

    virtual void integrateForce(Particle* p, float t) override;
    inline Particle* getAssociatedParticle() { return mParticle_; }

protected:
    Particle* mParticle_;
    float mK_;
    float mRestLength_;
};

