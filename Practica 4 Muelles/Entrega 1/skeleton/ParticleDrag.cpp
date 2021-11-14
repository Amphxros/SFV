#include "ParticleDrag.h"

ParticleDrag::ParticleDrag(float k1, float k2): 
	ParticleForceGenerator(), k1_(k1), k2_(k2)
{
}

void ParticleDrag::integrateForce(Particle* p, float t) 
{
	mForce_= p->getSpeed();
	
	float drag = mForce_.normalize();
	drag = k1_ * drag + k2_ * drag;

	mForce_ *= -drag;
	p->integrate(t);
	p->addForce(mForce_);

}
