#pragma once
#include <vector>
#include "ParticleForceGenerator.h"

enum ForceType{GRAVITY, EXPLOSION, WIND,TAM_FORCES};

class ParticleForceRegister
{
public:
	ParticleForceRegister(){
	
		mForces_.reserve((int)ForceType::TAM_FORCES);

		for (int i = 0; mForces_.size(); i++) {
			mForces_[i].reserve(100);
		}

	}
	~ParticleForceRegister(){}

	void addForce(ForceType type, ParticleForceGenerator* force) {
		mForces_[(int)type].push_back(force);
	}

	ParticleForceGenerator* getForce(ForceType type, int ind = 0) {
		return mForces_[(int)type][ind];
	}

protected:
	std::vector <std::vector<ParticleForceGenerator*>>mForces_;
};

class RigidbodyForceRegister
{
public:
	RigidbodyForceRegister(){}
	~RigidbodyForceRegister(){}

	//std::vector<std::vector<RigidbodyForceGenerator*>
};


