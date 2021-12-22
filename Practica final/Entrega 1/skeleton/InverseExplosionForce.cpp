#include "InverseExplosionForce.h"

InverseExplosionForce::InverseExplosionForce(Vector3 pos, float rd):
	ParticleForceGenerator(), mPos_(pos), rd_(rd)
{
	particleExplosionArea = new Particle(mPos_, Vector3(0, 0, 0), Vector3(0, 0, 0), 0, 0, rd_ / 2, Vector4(0.1, 0.5, 0.2, 0.3), 0);

}

InverseExplosionForce::~InverseExplosionForce()
{
}

void InverseExplosionForce::integrateForce(Particle* p, float t)
{
	p->integrate(t);
	mPos_ = p->getPosition();

	mForce_ = particleExplosionArea->getPosition() - p->getPosition();

	if (isParticleOnMyZone(p) && !p->hasInfiniteMass()) {
		p->addForce(mForce_ * mForce_.normalize()); //fuerza hacia fuera 
	}


}

bool InverseExplosionForce::isParticleOnMyZone(Particle* p)
{
	return distance(p->getPosition(), particleExplosionArea->getPosition()) < rd_;

}

float InverseExplosionForce::distance(Vector3 posA, Vector3 posB)
{
	float x = (posA.x - posB.x) * (posA.x - posB.x);
	float y = (posA.y - posB.y) * (posA.y - posB.y);
	float z = (posA.z - posB.z) * (posA.z - posB.z);

	return sqrt(x + y + z);
}
