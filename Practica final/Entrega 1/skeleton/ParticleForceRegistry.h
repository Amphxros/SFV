#pragma once
#include "Particle.h"
#include "ParticleForceGenerator.h"
#include <vector>
#include "ParticleBuoyancy.h"

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
	bool integrateForces(float t);
protected:
	Registry mRegistry_;
	ParticleBuoyancy* buoya;
};

