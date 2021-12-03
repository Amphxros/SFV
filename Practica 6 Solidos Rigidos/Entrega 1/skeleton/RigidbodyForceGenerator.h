#pragma once

#include <PxPhysicsAPI.h>
#include "Rigidbody.h"
class RigidbodyForceGenerator
{
	public:
		RigidbodyForceGenerator() {}
		virtual void integrateForce(RigidBody* rb, float t) = 0;
	
};

