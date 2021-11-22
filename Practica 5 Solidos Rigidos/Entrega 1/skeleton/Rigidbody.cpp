#include "Rigidbody.h"

RigidBody::RigidBody(physx::PxRigidDynamic* dynamics, RenderItem* body, float lifeTime):
	mDynamics_(dynamics), mBody_(body), mLifeTime_(lifeTime)
{
}

RigidBody::~RigidBody()
{
	mBody_->release();
	mDynamics_->release();
}
