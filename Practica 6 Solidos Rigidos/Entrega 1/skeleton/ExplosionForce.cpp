#include "ExplosionForce.h"

ExplosionForce::ExplosionForce(Vector3 pos, float rd): ParticleForceGenerator(),mPos_(pos),rd_(rd)
{
	particleExplosionArea = new Particle(mPos_, Vector3(0, 0, 0), Vector3(0, 0, 0), 0, 0, rd_, Vector4(1, 0.5, 0, 0.2), 0); 
}

ExplosionForce::~ExplosionForce()
{
	delete particleExplosionArea;
}

void ExplosionForce::integrateForce(Particle* p, float t)
{
	p->integrate(t);

	mForce_ = particleExplosionArea->getPosition() - p->getPosition();

	if (isParticleOnMyZone(p) && !p->hasInfiniteMass()) {
		p->addForce(-mForce_ * mForce_.normalize()); //fuerza hacia fuera 
	}
}

bool ExplosionForce::isParticleOnMyZone(Particle* p)
{
	return distance(p->getPosition(), particleExplosionArea->getPosition()) < rd_;
}

/// EXPLICACION: la distancia en un plano entre un punto A y B es el modulo (linea recta)-> modulo= raiz(x^2+ y^2 + z^2)
float ExplosionForce::distance(Vector3 posA, Vector3 posB)
{
	float x = (posA.x - posB.x) * (posA.x - posB.x);
	float y = (posA.y - posB.y) * (posA.y - posB.y);
	float z = (posA.z - posB.z) * (posA.z - posB.z);

	return sqrt(x + y + z);
}
