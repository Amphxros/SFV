#include "ParticleAnchoredSpring.h"

ParticleAnchoredSpring::ParticleAnchoredSpring(Vector3 anchor, float k, float restLength): 
	ParticleForceGenerator(), mAnchor_(anchor),mK_(k), mRestLength_(restLength)
{

}

ParticleAnchoredSpring::~ParticleAnchoredSpring()
{
}

void ParticleAnchoredSpring::integrateForce(Particle* p, float t)
{
	Vector3 f = p->getPosition();
	f -= mAnchor_;
	float length = f.normalize();
	
	f *= -(length - mRestLength_) * mK_;
	p->addForce(f);
}
