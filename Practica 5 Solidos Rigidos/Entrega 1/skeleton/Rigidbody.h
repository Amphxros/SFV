#pragma once
#include "RenderUtils.hpp"

class RigidBody {
public:
	RigidBody(physx::PxRigidDynamic* dynamics, RenderItem* body, float lifeTime);
	~RigidBody();
protected:
	float mLifeTime_;
	RenderItem* mBody_;
	physx::PxRigidDynamic* mDynamics_;
};