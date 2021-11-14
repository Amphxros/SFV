#include "ParticleForceRegistry.h"

ParticleForceRegistry::ParticleForceRegistry() {

}

ParticleForceRegistry::~ParticleForceRegistry()
{
	clear();
}

void ParticleForceRegistry::add(Particle* particle, ParticleForceGenerator* force)
{
	ParticleForcePair pair;
	pair.particle = particle;
	pair.force = force;

	mRegistry_.push_back(pair);
	
}

void ParticleForceRegistry::remove(Particle* particle, ParticleForceGenerator* force)
{
	int i = 0;
	while (i < mRegistry_.size() && mRegistry_[i].particle != particle && mRegistry_[i].force != force)
		i++;
	if (i < mRegistry_.size()) {

		auto* p = (mRegistry_.begin() +i )->particle;
		auto* f = (mRegistry_.begin() + i)->force;
		mRegistry_.erase(mRegistry_.begin() + i);
		delete p;
		//delete f;
	}
}

void ParticleForceRegistry::remove(ParticleForcePair registry)
{

	int i = 0;
	while (i < mRegistry_.size() && mRegistry_[i].particle != registry.particle && mRegistry_[i].force != registry.force)
		i++;
	if (i < mRegistry_.size()) {

		auto* p = (mRegistry_.begin() + i)->particle;
		auto* f = (mRegistry_.begin() + i)->force;
		mRegistry_.erase(mRegistry_.begin() + i);
		(mRegistry_.begin() + i)->particle = nullptr;
		delete p;
		//delete f;
	}
}

void ParticleForceRegistry::clear()
{
	auto it = mRegistry_.begin();
	while (it!=mRegistry_.end() && !mRegistry_.empty()) {
		auto* p = it->particle;
		auto* f = it->force;
		mRegistry_.erase(it);
		it++;
		delete p;
		delete f;
	}
}

void ParticleForceRegistry::integrateForces(float t)
{
	for (auto it = mRegistry_.begin(); it != mRegistry_.end() && !mRegistry_.empty();) {


		it->force->integrateForce(it->particle, t);
		if (it->particle->isTimeOver(t)) {
			remove(it->particle, it->force);

			it = mRegistry_.begin();

		}
		else if (!mRegistry_.empty()) {
			++it;
		}

		
	}
}
