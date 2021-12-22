#include "Particle.h"

Particle::Particle(Vector3 pos, Vector3 speed, Vector3 accel, float damp, float mass, float rd, Vector4 col,double limit):
	mPos_(pos), mSpeed_(speed), mAccel_(accel),mDamp_(damp),mForce_(Vector3(0,0,0)), mMass_(mass), mRadius_(rd), mColor_(col), age_(limit)
{
	mTransform_ = new physx::PxTransform(mPos_);
	mBody_ = new RenderItem(CreateShape(physx::PxSphereGeometry(mRadius_)), mTransform_, mColor_);
	time_ = 0;
}

Particle::~Particle()
{
	//DeregisterRenderItem(mBody_);
	mBody_->release();
	//delete mTransform_;
	
}

void Particle::integrate(double t)
{
	//si la masa es = 0 tiene acceleracion infinita y no realista
	if (1 / mMass_ <= 0){
		return; 
	}
	else {
		//update the position
		mPos_ += mSpeed_ * t;
		*mTransform_ = physx::PxTransform(mPos_);

		mSpeed_ += mAccel_ * t;
		mAccel_ =  mForce_* (1/mMass_); // ley de newton a=f/m -> a=f* 1/m 
		mSpeed_ *= powf(mDamp_, t);
		clearForce();
	}

}

bool Particle::isTimeOver(double t)
{
	time_ += t;
	
	return time_ >= age_;
}
