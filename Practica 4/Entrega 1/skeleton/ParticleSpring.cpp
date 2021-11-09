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
	
	Vector3 f = p->getPosition();
	f -= mParticle_->getPosition();

	float length = f.normalize();
	float deltaL = length - mRestLength_;
	if (deltaL <= 0.0f) {
		return;
	}
	else {
		float forceMagnitude = -mK_ * deltaL;

		f *= forceMagnitude;
		p->addForce(f);
	}
}