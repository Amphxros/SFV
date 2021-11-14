#include "ParticleGravity.h"

ParticleGravity::ParticleGravity(Vector3 gravity): ParticleForceGenerator(mGravity_), mGravity_(gravity)
{
}

void ParticleGravity::integrateForce(Particle* particle, float t)
{
	if (!particle->hasInfiniteMass()) {
	
		particle->addForce( mGravity_* particle->getMass());
		particle->integrate(t);
	}
}
