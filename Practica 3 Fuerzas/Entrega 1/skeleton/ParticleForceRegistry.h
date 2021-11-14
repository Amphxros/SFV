#pragma once
#include "Particle.h"
#include "ParticleForceGenerator.h"
#include <vector>

struct ParticleForcePair {		// equivalente a std::pair<particle, force>
	Particle* particle;
	ParticleForceGenerator* force;
};
using Registry =std::vector<ParticleForcePair>; //equialente a typedef ...

class ParticleForceRegistry
{
public:
	ParticleForceRegistry();
	~ParticleForceRegistry();

	void add(Particle* particle, ParticleForceGenerator* force);
	void remove(Particle* particle, ParticleForceGenerator* force);
	void remove(ParticleForcePair registry);
	void clear();
	void integrateForces(float t);
protected:
	Registry mRegistry_;
};

