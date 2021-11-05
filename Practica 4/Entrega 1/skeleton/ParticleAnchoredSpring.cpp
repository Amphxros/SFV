#include "ParticleAnchoredSpring.h"

ParticleAnchoredSpring::ParticleAnchoredSpring(Vector3 anchor, float k, float restLength): mAnchor_(anchor),mK_(k), mRestLength_(restLength)
{

}

ParticleAnchoredSpring::~ParticleAnchoredSpring()
{
}

void ParticleAnchoredSpring::integrateForce(Particle* p, float t)
{
}
