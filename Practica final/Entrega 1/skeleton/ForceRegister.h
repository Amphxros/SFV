#pragma once
#include <vector>
#include "ParticleForceGenerator.h"
#include "RigidBodyForceGenerator.h"

enum ForceType{GRAVITY, EXPLOSION, ABSORCION, SPRING, WIND,TAM_FORCES};

class ParticleForceRegister
{
public:
	ParticleForceRegister();
	~ParticleForceRegister();

	void addForce(ForceType type, ParticleForceGenerator* force) {
		mForces_[(int)type].push_back(force);
	}

	int getLengthOfType(ForceType type) { return mForces_[(int)type].size(); }

	ParticleForceGenerator* getForce(ForceType type, int ind = 0) {
		return mForces_[(int)type][ind];
	}

protected:
	std::vector <std::vector<ParticleForceGenerator*>>mForces_;
};

class RigidBodyForceRegister {
public:
	RigidBodyForceRegister();
	~RigidBodyForceRegister();
	void addForce(ForceType type, RigidBodyForceGenerator* force) {
		mForces_[(int)type].push_back(force);
	}

	RigidBodyForceGenerator* getForce(ForceType type, int ind = 0) {
		return mForces_[(int)type][ind];
	}

	int getLengthOfType(ForceType type) { return mForces_[(int)type].size(); }

protected:
	std::vector <std::vector<RigidBodyForceGenerator*>>mForces_;
};


