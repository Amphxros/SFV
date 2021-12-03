#pragma once
#include <PxPhysicsAPI.h>
#include "RenderUtils.hpp"
#include "core.hpp"
#include <list>

class Particle
{
public:
	Particle(Vector3 pos, Vector3 speed, Vector3 accel, float drag, float mass, float rd, Vector4 col, double limit);
	~Particle();
	void integrate(double t);
	bool isTimeOver(double t);

	inline Vector3 getPosition() { return mPos_; }
	inline Vector3 getSpeed() { return mSpeed_; }
	inline Vector3 getAccel() { return mAccel_; }

	inline float getAge() { return age_; }
	inline void setAge(float age) { age_ = age; }

	inline float getMass() { return mMass_; }
	inline float getDump() { return mDamp_; }
	inline void setDamping(float d) { mDamp_ = d; }

	inline void setPosition(Vector3 pos) { mPos_ = pos; }
	inline void setSpeed(Vector3 speed) { mSpeed_ = speed; }
	inline void setAcceleration(Vector3 accel) { mAccel_= accel; }

	inline Vector4 getColor() { return mColor_; }
	
	inline std::list<Particle*>::iterator getIt() { return mIt_; }
	inline void setIt(std::list<Particle*>::iterator it) { mIt_ = it; }
	
	inline Vector3 getForce() { return mForce_; }
	inline void addForce(Vector3 force) { mForce_ += force; }
	inline void clearForce() { mForce_ = Vector3(0, 0, 0); }

	inline bool hasInfiniteMass() { return (1 / mMass_) <= 0; }

	inline void setBoxBody() { mBody_ = new RenderItem(CreateShape(physx::PxBoxGeometry(mRadius_, mRadius_, mRadius_)), mTransform_, mColor_); }
	inline void setBoxBody(float x, float y, float z) { mBody_ = new RenderItem(CreateShape(physx::PxBoxGeometry(x,y,z)), mTransform_, mColor_);}

	void setSphereBody() { mBody_= new RenderItem(CreateShape(physx::PxSphereGeometry(mRadius_)), mTransform_, mColor_); }

protected:
	//components for the physics of the particle

	physx::PxTransform* mTransform_; //transform para actualizar el cuerpo

	Vector3 mPos_;		//position
	Vector3 mSpeed_;	//velocity
	Vector3 mAccel_;	//acceleration

	Vector3 mForce_;	

	float mMass_;		//mass
	float mDamp_;		//damping

	double time_;
	double age_;

	std::list<Particle*>::iterator mIt_;
	
	//components fo rendering the particle

	RenderItem* mBody_; //body of the particle itself
	Vector4 mColor_; //colour of the particle
	float mRadius_; //radius of the particle sphere

};

