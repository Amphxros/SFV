#pragma once
#include "Particle.h"
class ParticleContact
{
public:
	ParticleContact(Particle* particleA, Particle* particleB);
	~ParticleContact();

	
protected:
	void resolve(float t);
	void resolveVelocity(float t);
	void resolveInterPenetration(float t);

	Particle* mParticleA_;
	Particle* mParticleB_;
	Vector3 mNormal_;

	float mPenetration_;
	float mRestitution_;
};

