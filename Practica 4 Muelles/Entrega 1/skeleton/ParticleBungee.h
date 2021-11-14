#pragma once
#include "ParticleForceGenerator.h"
class ParticleBungee :
    public ParticleForceGenerator
{
public:
    ParticleBungee(Particle* particle, float k, float restLength);
    virtual ~ParticleBungee();

    virtual void integrateForce(Particle* p, float t) override;


private:
    Particle* mParticle_;
    float mK_;
    float mRestLength_;
};

