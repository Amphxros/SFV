#pragma once
#include "Particle.h"
class ParticleContact
{
public:
	ParticleContact(Particle* particleA, Particle* particleB);
	~ParticleContact();
	void resolve(float t);

	inline void setRestitution(float rest) { mRestitution_ = rest; }
	inline void setPenetration(float pen) { mPenetration_ = pen; }
	inline void setNormal(Vector3 normal) { mNormal_ = normal; }

protected:
	void resolveVelocity(float t);
	void resolveInterPenetration(float t);

	Particle* mParticleA_;
	Particle* mParticleB_;
	Vector3 mNormal_;

	float mPenetration_;
	float mRestitution_;
};