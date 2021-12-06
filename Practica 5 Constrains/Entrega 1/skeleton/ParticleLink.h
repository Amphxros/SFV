#pragma once

#include "ParticleContact.h"
class ParticleLink
{
public:
	ParticleLink(Particle* particleA, Particle* particleB) : 
		mParticleA_(particleA), mParticleB_(particleB) {}
	virtual unsigned addContact(ParticleContact* contact) = 0;

protected:
	Particle* mParticleA_;
	Particle* mParticleB_;

};

