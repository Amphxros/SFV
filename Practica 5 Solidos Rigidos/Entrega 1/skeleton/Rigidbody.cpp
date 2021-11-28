#include "Rigidbody.h"

RigidBody::RigidBody(physx::PxRigidDynamic* dynamics, RenderItem* body, float lifeTime):
	mDynamics_(dynamics), mBody_(body), mLifeTime_(lifeTime)
{
	mDynamics_->attachShape(*(body->shape));
	physx::PxRigidBodyExt::updateMassAndInertia(*mDynamics_, physx::PxReal(2));
}

RigidBody::~RigidBody()
{
	mBody_->release();
	mDynamics_->release();
}
