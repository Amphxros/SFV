#pragma once
#include "ParticleForceGenerator.h"
class InverseExplosionForce:
    public ParticleForceGenerator
{
public:
    InverseExplosionForce(Vector3 pos, float rd);
    virtual ~InverseExplosionForce();

    virtual void integrateForce(Particle* p, float t) override;

    bool isParticleOnMyZone(Particle* p);
    float distance(Vector3 posA, Vector3 posB);
    Particle* getAssociatedParticle() { return particleExplosionArea; }
    void setParticle(Particle* p) { delete particleExplosionArea; particleExplosionArea = p; }
protected:
    Particle* particleExplosionArea;    // zona/areade la explosion
    Vector3 mPos_;     //posicion de la misma
    float rd_;         //radio del area de la explosion

};

