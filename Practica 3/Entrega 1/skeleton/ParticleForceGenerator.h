#pragma once
#include "Particle.h"
class ParticleForceGenerator
{
public:
	ParticleForceGenerator(Vector3 mForce): mForce_(mForce) {};
	~ParticleForceGenerator() {};

	virtual void integrateForce(Particle* p, float t) = 0;

	inline Vector3 getForce() { return mForce_; }
	inline void setForce(Vector3 force) { mForce_ = force; }

protected:
	Vector3 mForce_;

};

