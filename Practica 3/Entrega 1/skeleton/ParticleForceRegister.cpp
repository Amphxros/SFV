#include "ParticleForceRegister.h"

ParticleForceRegister::ParticleForceRegister()
{
}

void ParticleForceRegister::add(Particle* p, ParticleForceGenerator* mgen)
{
	mParticleForceRegistration r = mParticleForceRegistration(p, mgen);
	mRegistry_.push_back(r);
}

void ParticleForceRegister::remove(Particle* p, ParticleForceGenerator* mgen)
{

}

void ParticleForceRegister::clear()
{
	auto it = mRegistry_.begin();
	while (!mRegistry_.empty()) {
		mRegistry_.erase(it);
		it = mRegistry_.begin();
	}
}

void ParticleForceRegister::integrateForces(float t)
{
	for (auto r : mRegistry_) {
		r.mGenerator_->integrateForce(r.mParticle_, t);
		if (r.mParticle_ != nullptr) {
			r.mParticle_->integrate(t);

			if (r.mParticle_->isTimeOver(t)) {
				
			}
		}
	}
}
