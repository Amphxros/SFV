#pragma once

#include <PxPhysicsAPI.h>
#include "RenderUtils.hpp"
#include "RigidBody.h"
#include "RigidbodyForceGenerator.h"
#include <vector>

struct RigidBodyForcePair {
	RigidBody* rb;
	RigidbodyForceGenerator* force;
};

using RigidBodyRegistry = std::vector<RigidBodyForcePair>;

class RigidbodyForceRegistry
{
	public:
		RigidbodyForceRegistry();
		~RigidbodyForceRegistry();

		void add(RigidBody* rb, RigidbodyForceGenerator* force);
		void remove(RigidBody* rb, RigidbodyForceGenerator* force);
		void remove(RigidBodyForcePair registry);
		void clear();
		void integrateForces(float t);

	protected:
		RigidBodyRegistry mRegistry_;
};

