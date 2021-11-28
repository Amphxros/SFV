#include "StaticRigidbdy.h"

StaticRigidbody::StaticRigidbody(physx::PxRigidStatic* statics, RenderItem* body, float lifeTime):
	mStatics_(statics), mBody_(body), mLifeTime_(lifeTime)
{
	mStatics_->attachShape(*(body->shape));
}

StaticRigidbody::~StaticRigidbody()
{
	mBody_->release();
	mStatics_->release();
}
