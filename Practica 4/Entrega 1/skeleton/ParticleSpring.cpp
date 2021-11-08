#include "ParticleSpring.h"

ParticleSpring::ParticleSpring(Particle* particle, float k, float restLength) :
	ParticleForceGenerator(), mParticle_(particle),mK_(k), mRestLength_(restLength)
{
	mParticle_->setBoxBody();
}

ParticleSpring::~ParticleSpring()
{
	//delete mParticle_;
}
void ParticleSpring::integrateForce(Particle* p, float t)
{
	Vector3 f = p->getPosition();
	f -= mParticle_->getPosition();

	float length = f.normalize();

	float deltaL = length -mRestLength_;
	float forceMagnitude = - mK_ * deltaL;

	f *= forceMagnitude;
	p->addForce(f);
}