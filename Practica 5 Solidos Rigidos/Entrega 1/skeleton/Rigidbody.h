#pragma once
#include "RenderUtils.hpp"

class RigidBody {
public:
	RigidBody(physx::PxRigidDynamic* dynamics, RenderItem* body, float lifeTime);
	~RigidBody();

	inline physx::PxRigidDynamic* getMyRigidBody() { return mDynamics_; }
	inline RenderItem* getMyBody() { return mBody_; }
	inline void setMyBody(RenderItem* item) { mBody_ = item; }


protected:
	float mLifeTime_;
	RenderItem* mBody_;
	physx::PxRigidDynamic* mDynamics_;
};