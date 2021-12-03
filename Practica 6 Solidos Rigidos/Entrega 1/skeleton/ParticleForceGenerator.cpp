#include "ParticleForceGenerator.h"

void ParticleForceGenerator::integrateForce(Particle* p, float t)
{
	p->addForce(mForce_);
}
