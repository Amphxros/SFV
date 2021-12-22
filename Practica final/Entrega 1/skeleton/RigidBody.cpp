#include "RigidBody.h"


RigidBody::RigidBody(physx::PxPhysics* physics, physx::PxScene* scene, Vector3 pos, float rd, Vector4 color):
	mPhysicsEngine_(physics), mScene_(scene), mPos_(pos),mColor_(color)
{
	tr_ = new physx::PxTransform(mPos_);
	physx::PxShape* shape = CreateShape(physx::PxSphereGeometry(rd));
	mDynamic_ = mPhysicsEngine_->createRigidDynamic(*tr_);
	mDynamic_->attachShape(*shape);

	mBody_ = new RenderItem(shape, mDynamic_, color);
	physx::PxRigidBodyExt::updateMassAndInertia(*mDynamic_, 1.0);
	mScene_->addActor(*mDynamic_);
}

RigidBody::RigidBody(physx::PxPhysics* physics, physx::PxScene* scene, Vector3 pos, float x, float y, float z, Vector4 color) :
	mPhysicsEngine_(physics), mScene_(scene), mPos_(pos), mColor_(color)
{
	tr_ = new physx::PxTransform(mPos_);
	physx::PxShape* shape = CreateShape(physx::PxBoxGeometry(x,y,z));
	mDynamic_ = mPhysicsEngine_->createRigidDynamic(*tr_);
	mDynamic_->attachShape(*shape);

	mBody_ = new RenderItem(shape, mDynamic_, color);

	physx::PxRigidBodyExt::updateMassAndInertia(*mDynamic_, 1.0);
	mScene_->addActor(*mDynamic_);
}

RigidBody::~RigidBody()
{
	mDynamic_->release();
	mBody_->release();
}