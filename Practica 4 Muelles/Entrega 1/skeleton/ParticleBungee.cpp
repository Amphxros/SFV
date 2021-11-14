#include "ParticleBungee.h"

ParticleBungee::ParticleBungee(Particle* particle, float k, float restLength):
	ParticleForceGenerator(), mK_(k), mRestLength_(restLength)
{
	mParticle_->setBoxBody();
}

ParticleBungee::~ParticleBungee()
{
}

void ParticleBungee::integrateForce(Particle* p, float t)
{
	Vector3 f = p->getPosition();
	f -= mParticle_->getPosition();

	float length = f.normalize();
	length -= mRestLength_;
	length *= mK_;
	if (length <= 0.0f) {
		return;
	}
	else {
		f *= -length;
		mParticle_->addForce(f);
	}
}
