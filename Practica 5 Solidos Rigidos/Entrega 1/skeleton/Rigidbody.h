#pragma once
#include "RenderUtils.hpp"

struct RigidBody {
	float mLifetime_;
	RenderItem* mBody_;
	physx::PxRigidDynamic* mPhysics_;
};