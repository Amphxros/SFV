#include "RigidbodyForceRegistry.h"

RigidbodyForceRegistry::RigidbodyForceRegistry()
{
}

RigidbodyForceRegistry::~RigidbodyForceRegistry()
{
	clear();
}

void RigidbodyForceRegistry::add(RigidBody* rb, RigidbodyForceGenerator* force)
{
	RigidBodyForcePair pair;
	pair.rb = rb;
	pair.force = force;

	mRegistry_.push_back(pair);
}

void RigidbodyForceRegistry::remove(RigidBody* rb, RigidbodyForceGenerator* force)
{
	auto it = mRegistry_.begin();

	while (it != mRegistry_.end()) {
		if ((*it).rb == rb && (*it).force== force) {
			it = mRegistry_.erase(it);
		}
		else ++it;
	}
}

void RigidbodyForceRegistry::remove(RigidBodyForcePair registry)
{
	auto it = mRegistry_.begin();

	while (it != mRegistry_.end()) {
		if ((*it).rb == registry.rb && (*it).force == registry.force) {
			it = mRegistry_.erase(it);
		}
		else ++it;
	}
}

void RigidbodyForceRegistry::clear()
{
	mRegistry_.clear();
}

void RigidbodyForceRegistry::integrateForces(float t)
{
	for (RigidBodyForcePair pair : mRegistry_) {
		pair.force->integrateForce(pair.rb, t);
	}
}
