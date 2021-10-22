#include "ParticleGravity.h"
#include <limits>

ParticleGravity::ParticleGravity(const Vector3& gravity):
	ParticleForceGenerator(Vector3()), mGravity_(gravity)
{
}

void ParticleGravity::integrateForce(Particle* p, float t)
{
	float inf = std::numeric_limits<float>::infinity();

	if (p->getMass() >=inf ) { //si tiene masa infinita -> tiene fuerza infinita ->no se debería poder mover o sería imparable y no es realista
		return;
	}
	else {
		p->addForce(mGravity_ * p->getMass()); //  f= m*a
	}
}
