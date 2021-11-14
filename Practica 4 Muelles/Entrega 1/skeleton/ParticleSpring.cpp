#include "ParticleSpring.h"

ParticleSpring::ParticleSpring(Particle* particle, float k, float restLength) :
	ParticleForceGenerator(Vector3(0,0,0)), mParticle_(particle),mK_(k), mRestLength_(restLength)
{
	mParticle_->setBoxBody();
}

ParticleSpring::~ParticleSpring()
{
}
void ParticleSpring::integrateForce(Particle* p, float t)
{
	Vector3 f = p->getPosition() - mParticle_->getPosition();
	float l = f.normalize();
	float deltaL = l - mRestLength_;
	deltaL *= -mK_;
	f *= deltaL;
	p->addForce(f);
}