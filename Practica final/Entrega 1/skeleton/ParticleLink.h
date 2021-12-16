#pragma once

#include "ParticleContact.h"
class ParticleLink
{
public:
	ParticleLink(Particle* particleA, Particle* particleB) :
		mParticleA_(particleA), mParticleB_(particleB) {}
	virtual unsigned addContact(ParticleContact* contact) = 0;

	inline float getCurrentLength() const {
		Vector3 deltaPos = mParticleA_->getPosition() - mParticleB_->getPosition();
		return deltaPos.magnitude();
	}

protected:
	Particle* mParticleA_;
	Particle* mParticleB_;

};


class ParticleCable : public ParticleLink {
public:
	ParticleCable(Particle* particleA, Particle* particleB, float maxLength);
	virtual unsigned addContact(ParticleContact* contact);
protected:
	float mMaxLength_;
	float mRestitution_ = 1;
};

class ParticleRod : public ParticleLink {
public:
	ParticleRod(Particle* particleA, Particle* particleB, float length);
	virtual unsigned addContact(ParticleContact* contact);
protected:
	float mLength_;
};