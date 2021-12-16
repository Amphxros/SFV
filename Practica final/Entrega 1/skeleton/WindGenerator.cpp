#include "WindGenerator.h"
#include <iostream>
WindGenerator::WindGenerator(Vector3 force, Vector3 pos, float rd):
	ParticleForceGenerator(force), rd_(rd)
{
	//mParticleWind = new Particle(pos, Vector3(0, 0, 0), Vector3(0, 0, 0), 0, 0, rd, Vector4(0, 1, 0.5, 0.3), 0);
}

void WindGenerator::integrateForce(Particle* p, float t) 
{
	if (isParticleOnMyZone(p)) {
		p->addForce(mForce_ * 1/p->getMass());
		
	}
	p->integrate(t);
	
}

bool WindGenerator::isParticleOnMyZone(Particle* p)
{
	return distance(p->getPosition(), mParticleWind->getPosition()) < rd_;
}


/// EXPLICACION: la distancia en un plano entre un punto A y B es el modulo (linea recta)-> modulo= raiz(x^2+ y^2 + z^2)
float WindGenerator::distance(Vector3 posA, Vector3 posB)
{
	float x = (posA.x - posB.x)*(posA.x - posB.x);
	float y = (posA.y - posB.y)*(posA.y - posB.y);
	float z = (posA.z - posB.z)*(posA.z - posB.z);

	return sqrt(x + y + z);
}
