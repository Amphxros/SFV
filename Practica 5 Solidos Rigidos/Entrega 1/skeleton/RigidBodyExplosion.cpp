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
			Vector3 delta = rb->mBody_->transform->p - mCenter_;
			
			rb->addForceAtPoint(Vector3(), Vector3());
		}
	}
	else {
		mBody_->release();
	}
}
