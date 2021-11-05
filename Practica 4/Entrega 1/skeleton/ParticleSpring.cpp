#include "ParticleSpring.h"

ParticleSpring::ParticleSpring(Vector3 pos, Vector4 col, float k, float restLength) : ParticleForceGenerator(), mK_(k), mRestLength_(restLength)
{
	mParticle_ = new Particle(pos, Vector3(1, 0, 1), Vector3(0, 0, 0), 0.1, 1, 3, col, 1);
	mParticle_->setBoxBody();
}

ParticleSpring::~ParticleSpring()
{
	//delete mParticle_;
}
void ParticleSpring::integrateForce(Particle* p, float t)
{
	mParticle_->integrate(t);
	Vector3 f = p->getPosition();
	f -= mParticle_->getPosition();

	float length = f.normalize();

	float deltaL = length - mRestLength_;
	float forceMagnitude = -mK_ * deltaL;

	f *= forceMagnitude;
	p->addForce(f);
}
