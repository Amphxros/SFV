#include "RigidBodyForceRegistry.h"

RigidBodyForceRegistry::~RigidBodyForceRegistry()
{
}

void RigidBodyForceRegistry::add(RigidBody* rb, RigidBodyForceGenerator* fg)
{
	RigidBodyForcePair pair;
	pair.rb_ = rb;
	pair.force = fg;

	mRegistry_.push_back(pair);
}

void RigidBodyForceRegistry::remove(RigidBody* rb, RigidBodyForceGenerator* fg)
{
	int i = 0;
	while (i < mRegistry_.size() && mRegistry_[i].rb_ != rb && mRegistry_[i].force != fg)
		i++;
	if (i < mRegistry_.size()) {

		auto* r = (mRegistry_.begin() + i)->rb_;
		auto* f = (mRegistry_.begin() + i)->force;
		mRegistry_.erase(mRegistry_.begin() + i);
		delete r;
		//delete f;
	}
}

void RigidBodyForceRegistry::remove(RigidBodyForcePair pair)
{
	int i = 0;
	while (i < mRegistry_.size() && mRegistry_[i].rb_ != pair.rb_ && mRegistry_[i].force != pair.force)
		i++;
	if (i < mRegistry_.size()) {

		auto* r = (mRegistry_.begin() + i)->rb_;
		auto* f = (mRegistry_.begin() + i)->force;

		mRegistry_.erase(mRegistry_.begin() + i);
		delete r;

	}
}

void RigidBodyForceRegistry::clear()
{
	auto it = mRegistry_.begin();
	while (it != mRegistry_.end() && !mRegistry_.empty()) {

		mRegistry_.erase(it);
		it = mRegistry_.begin();
	}
}

void RigidBodyForceRegistry::integrateForces(float t)
{
	for (auto it = mRegistry_.begin(); it != mRegistry_.end() && !mRegistry_.empty();) {

		it->force->integrateForce(it->rb_, t);

		/*
		if (it->particle->isTimeOver(t)) {
			if (it->particle->getPosition().y > -30) {
				abs = true;
			}
			remove(*it);
			it = mRegistry_.begin();

		}
		else*/

		if (!mRegistry_.empty()) {
			++it;
		}


	}
}
