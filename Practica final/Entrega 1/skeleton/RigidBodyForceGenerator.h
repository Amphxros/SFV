#pragma once
#include "core.hpp"
#include "RigidBody.h"
class RigidBodyForceGenerator
{
public:
	RigidBodyForceGenerator(Vector3 force):mForce_(force) {}
	~RigidBodyForceGenerator(){}

	virtual void integrateForce(RigidBody* rb, float t) {}

protected:
	Vector3 mForce_;
};

