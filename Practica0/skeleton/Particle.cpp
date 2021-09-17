#include "Particle.h"

Particle::Particle(): 
	mPos_(0,0,0), mSpeed_(0,0,0), mAccel_(0,0,0), mBody_(nullptr), mMass_(0)
{
}

Particle::Particle(Vector3 pos, Vector3 speed, Vector3 accel, RenderItem* body, float mass):
	mPos_(pos), mSpeed_(speed), mAccel_(accel), mBody_(body), mMass_(mass)
{

	RegisterRenderItem(mBody_);
}

Particle::~Particle()
{
	DeregisterRenderItem(mBody_);
	
}

void Particle::update(double t)
{
}
