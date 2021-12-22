#pragma once
#include "RigidBodyForceGenerator.h"
#include "Particle.h"
class RigidBodyExplosion :
    public RigidBodyForceGenerator
{
public:
    RigidBodyExplosion(Vector3 pos, float rd);
    virtual ~RigidBodyExplosion();

    virtual void integrateForce(RigidBody* rb, float t) override;

    inline void setParticle(Particle* prt) { part_ = prt; }

    bool isParticleOnMyZone(RigidBody* rb);
    float distance(Vector3 posA, Vector3 posB);


private:
    Particle* part_;
    Vector3 mPos_;
    float rd_;
};

