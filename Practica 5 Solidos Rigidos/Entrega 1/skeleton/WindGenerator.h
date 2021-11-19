#pragma once
#include "ParticleForceGenerator.h"

class WindGenerator :
    public ParticleForceGenerator
{
public:
    WindGenerator(Vector3 force, Vector3 pos, float rd);
    virtual ~WindGenerator() { delete mParticleWind; }

    virtual void integrateForce(Particle* p, float t) override;

    bool isParticleOnMyZone(Particle* p);
    float distance(Vector3 posA, Vector3 posB);

protected:

    float rd_;
    Particle* mParticleWind;

};

