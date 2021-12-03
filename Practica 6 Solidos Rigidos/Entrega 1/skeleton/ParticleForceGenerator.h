#pragma once
#include "Particle.h"

class ParticleForceGenerator
{
public:
	ParticleForceGenerator(): mForce_(Vector3(0,0,0)) {}
	ParticleForceGenerator(Vector3 force): mForce_(force){}

	~ParticleForceGenerator(){}

	virtual void integrateForce(Particle* p, float t);

	inline Vector3 getForce() { return mForce_; }
	inline void setForce(Vector3 force) { mForce_ = force; }

protected:
	Vector3 mForce_;

};
