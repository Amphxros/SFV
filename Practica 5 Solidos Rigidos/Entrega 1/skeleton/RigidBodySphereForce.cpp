#include "RigidBodySphereForce.h"

RigidBodySphereForce::RigidBodySphereForce(Vector3 center, float rd):
	RigidbodyForceGenerator(),mCenter_(center),mRD_(rd)
{
	mGeometry_ = new physx::PxSphereGeometry(mRD_);
	tr_ = physx::PxTransform(mCenter_);
}


RigidBodySphereForce::~RigidBodySphereForce()
{
	if (mBody_ != nullptr)
		mBody_->release();
	delete mGeometry_;
}

bool RigidBodySphereForce::rigidBodyInsideVolume(Vector3 pos)
{
	Vector3 delta = mCenter_ - pos;
	float f = delta.normalize();
	return f < mRD_;
}

void RigidBodySphereForce::createVolume()
{
	physx::PxShape* shape = CreateShape(*mGeometry_);
	mBody_ = new RenderItem(shape, &tr_, Vector4(0,0,0,0));
	shape->release();
}
