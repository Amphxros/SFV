#pragma once

#include <PxPhysicsAPI.h>

class RigidbodyForceGenerator
{
	public:
		RigidbodyForceGenerator() {}
		virtual void integrateForce(physx::PxRigidDynamic* rb, float t) = 0;
};

