#include "ForceRegister.h"

ParticleForceRegister::ParticleForceRegister()
{

	mForces_.reserve((int)ForceType::TAM_FORCES);

	for (int i = 0; i < (int)ForceType::TAM_FORCES; i++) {
		mForces_[i].reserve(100);
	}

}

ParticleForceRegister::~ParticleForceRegister()
{

	for (int i = 0; i < (int)TAM_FORCES; i++) {
		for (ParticleForceGenerator* fg : mForces_[i]) {
			delete fg;
		}
	}

}
RigidBodyForceRegister::RigidBodyForceRegister()
{
	mForces_.reserve((int)ForceType::TAM_FORCES);

	for (int i = 0; i < (int)ForceType::TAM_FORCES; i++) {
		mForces_[i].reserve(100);
	}
}

RigidBodyForceRegister::~RigidBodyForceRegister()
{
	for (int i = 0; i < (int)TAM_FORCES; i++) {
		for (RigidBodyForceGenerator* fg : mForces_[i]) {
			delete fg;
		}
	}
}

