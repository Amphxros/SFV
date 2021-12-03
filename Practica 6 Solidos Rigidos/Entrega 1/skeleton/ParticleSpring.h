#pragma once
#include "ParticleForceGenerator.h"
class ParticleSpring :
    public ParticleForceGenerator
{
public:
    ParticleSpring(Particle* particle, float k, float restLength);
    virtual ~ParticleSpring();

    virtual void integrateForce(Particle* p, float t) override;
    inline Particle* getAssociatedParticle() { return mParticle_; }
    void setK(float k) { mK_ = k; }
    void addK(float k) { mK_ += k; }
protected:
    Particle* mParticle_;
    float mK_;
    float mRestLength_;
};

