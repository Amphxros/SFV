#include "WindGenerator.h"
#include <iostream>
WindGenerator::WindGenerator(Vector3 force, Vector3 pos, float rd):
	ParticleForceGenerator(force), rd_(rd)
{
	mParticleWind = new Particle(pos, Vector3(0, 0, 0), Vector3(0, 0, 0), 0, 0, rd, Vector4(0, 1, 0.5, 0.3), 0);
}

void WindGenerator::integrateForce(Particle* p, float t) 
{
	if (isParticleOnMyZone(p)) {
		p->addForce(mForce_);
		
	}
	p->integrate(t);
	
}

bool WindGenerator::isParticleOnMyZone(Particle* p)
{
	return distance(p->getPosition(), mParticleWind->getPosition()) < rd_;
}

float WindGenerator::distance(Vector3 posA, Vector3 posB)
{
	float x = (posA.x - posB.x)*(posA.x - posB.x);
	float y = (posA.y - posB.y)*(posA.y - posB.y);
	float z = (posA.z - posB.z)*(posA.z - posB.z);

	return sqrt(x + y + z);
}
