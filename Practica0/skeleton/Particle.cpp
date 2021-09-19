#include "Particle.h"




Particle::Particle(Vector3 pos, Vector3 speed, Vector3 accel, float drag, float mass, float rd, Vector4 col):
	mPos_(pos), mSpeed_(speed), mAccel_(accel),mDrag_(drag), mMass_(mass), mRadius_(rd), mColor_(col)
{
	mTransform_ = new physx::PxTransform(mPos_);
	mBody_ = new RenderItem(CreateShape(physx::PxSphereGeometry(mRadius_)), mTransform_, mColor_);
}

Particle::~Particle()
{
	DeregisterRenderItem(mBody_);
	
}

void Particle::update(double t)
{
	//update the position
	mPos_ += mSpeed_ * t;
	*mTransform_ = physx::PxTransform(mPos_);


}
