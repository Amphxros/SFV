#pragma once
#include "RenderUtils.hpp"
class Staticbody{
	float mLifetime_;
	RenderItem* mBody_;
	physx::PxRigidStatic* mPhysics_;
};

