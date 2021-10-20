#pragma once
#include "ParticleForceGenerator.h"
class ParticleForceRegister
{
public:
	ParticleForceRegister();

	void add(Particle* p, ParticleForceGenerator* mgen);
	void remove(Particle* p, ParticleForceGenerator* mgen);
	void clear();
	void integrateForces(float t);


protected:
	struct mParticleForceRegistration
	{
		mParticleForceRegistration(Particle* p, ParticleForceGenerator* mgen):
			mParticle_(p), mGenerator_(mgen)
		{

		}
		Particle* mParticle_;
		ParticleForceGenerator* mGenerator_;
	};
	using Registry = std::vector<mParticleForceRegistration>;

	Registry mRegistry_;
};


