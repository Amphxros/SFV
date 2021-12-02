#pragma once
#include "RenderUtils.hpp"

struct Staticbody{
	float mLifetime_;
	RenderItem* mBody_;
	physx::PxRigidStatic* mPhysics_;
};

