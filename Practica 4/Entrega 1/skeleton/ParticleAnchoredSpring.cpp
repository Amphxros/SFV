#include "ParticleAnchoredSpring.h"

ParticleAnchoredSpring::ParticleAnchoredSpring(Vector3 anchor, float k, float restLength): 
	mAnchor_(anchor),mK_(k), mRestLength_(restLength)
{

}

ParticleAnchoredSpring::~ParticleAnchoredSpring()
{
}

void ParticleAnchoredSpring::integrateForce(Particle* p, float t)
{
	Vector3 pos = p->getPosition();
	pos -= mAnchor_;
	float length = pos.normalize();
	
	pos *= -(length - mRestLength_) * mK_;
	p->addForce(pos);
}
