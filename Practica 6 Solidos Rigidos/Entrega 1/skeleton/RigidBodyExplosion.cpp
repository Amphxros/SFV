#include "RigidBodyExplosion.h"

RigidBodyExplosion::RigidBodyExplosion(Vector3 center, float rd, float forceMod, float lifeTime ):
	RigidBodySphereForce(center, rd), mForceMod_(forceMod)
{

}

RigidBodyExplosion::~RigidBodyExplosion()
{
}

void RigidBodyExplosion::integrateForce(RigidBody* rb, float t)
{
	if (active_) {
		if (rigidBodyInsideVolume(rb->mBody_->transform->p)) {
			Vector3 dir = Vector3(mCenter_ - rb->mPhysics_->getGlobalPose().p);
			float dst = dir.magnitude();
			Vector3 accel = ((mRD_ - dst) * (-dir.getNormalized())) * mForceMod_;
			
			rb->mPhysics_->addForce(accel);
		}
		else {
			active_ = false;
		}
	}
	else {
		mBody_->release();
	}
}

void RigidBodyExplosion::activateExplosion(Vector3 center)
{
	active_ = true;
	mCenter_ = center;
	createVolume();
}

