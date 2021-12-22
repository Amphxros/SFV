#pragma once
#include "ParticleForceGenerator.h"
class ExplosionForce :
    public ParticleForceGenerator
{
public:
    ExplosionForce(Vector3 pos, float rd);
    virtual ~ExplosionForce();

    virtual void integrateForce(Particle* p, float t) override;

    bool isParticleOnMyZone(Particle* p);
    float distance(Vector3 posA, Vector3 posB);
    Particle* getAssociatedParticle() { return particleExplosionArea; }

protected:
    Particle* particleExplosionArea;    // zona/areade la explosion
    Vector3 mPos_;     //posicion de la misma
    float rd_;         //radio del area de la explosion
};

