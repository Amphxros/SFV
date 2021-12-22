#pragma once
#include "RigidBody.h"
#include "RigidBodyForceGenerator.h"

struct RigidBodyForcePair {
	RigidBody* rb_;
	RigidBodyForceGenerator* force;
};
using RBRegistry = std::vector<RigidBodyForcePair>;
class RigidBodyForceRegistry
{
public:
	RigidBodyForceRegistry() {}
	~RigidBodyForceRegistry();

	void add(RigidBody* rb, RigidBodyForceGenerator* fg);
	void remove(RigidBody* rb, RigidBodyForceGenerator* fg);
	void remove(RigidBodyForcePair pair);
	void clear();

	void integrateForces(float t);
protected:
	RBRegistry mRegistry_;
};

