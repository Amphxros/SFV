#include "ParticleForceRegistry.h"
#include "InverseExplosionForce.h"

ParticleForceRegistry::ParticleForceRegistry() {
	buoya= new ParticleBuoyancy(100, -30, 1000);
}

ParticleForceRegistry::~ParticleForceRegistry()
{
	clear();
	//delete buoya;
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
		
		//auto* f = (mRegistry_.begin() + i)->force;
		mRegistry_.erase(mRegistry_.begin() + i);
		p->deleteBody();
		
		//(mRegistry_.begin() + i)->particle = nullptr;
		//delete f;
	}
}

void ParticleForceRegistry::clear()
{
	auto it = mRegistry_.begin();
	while (it!=mRegistry_.end() && !mRegistry_.empty()) {
		
		mRegistry_.erase(it);
		it = mRegistry_.begin();
	}
}

bool ParticleForceRegistry::integrateForces(float t)
{
	bool abs = false;
	for (auto it = mRegistry_.begin(); it != mRegistry_.end() && !mRegistry_.empty();) {

		it->force->integrateForce(it->particle, t);
	
		if (it->particle->getPosition().y < -20 && !it->particle->hasBuoyance()) {
			add(it->particle, buoya);
			it->particle->setBuoyancy();
		}


		if (it->particle->isTimeOver(t)) {
			if (it->particle->getPosition().y > -30) {
				abs = true;
			}
			remove(*it);
			it = mRegistry_.begin();

		}
		else if (!mRegistry_.empty()) {
			++it;
		}


		
	}

	return abs;
}
