#pragma once
#include "RenderUtils.hpp"
class StaticRigidbody
{
public:
	StaticRigidbody(physx::PxRigidStatic* statics, RenderItem* body, float lifeTime);
	~StaticRigidbody();
	inline float getLifeTime() { return mLifeTime_; }
	inline physx::PxRigidStatic* getStatics() { return mStatics_; }
protected:
	float mLifeTime_;
	RenderItem* mBody_;
	physx::PxRigidStatic* mStatics_;
};

