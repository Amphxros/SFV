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
	virtual void integrate(double t);
	bool isTimeOver(double t);

	inline Vector3 getPosition() { return mPos_; }
	inline Vector3 getSpeed() { return mSpeed_; }
	inline Vector3 getAccel() { return mAccel_; }

	

	inline void setPosition(Vector3 pos) { mPos_ = pos; }
	inline void setSpeed(Vector3 speed) { mSpeed_ = speed; }
	inline void setAcceleration(Vector3 accel) { mAccel_= accel; }

	inline std::list<Particle*>::iterator getIt() { return mIt_; }
	inline void setIt(std::list<Particle*>::iterator it) { mIt_ = it; }
	
protected:
	//components for the physics of the particle

	physx::PxTransform* mTransform_; //transform para actualizar el cuerpo

	Vector3 mPos_;		//position
	Vector3 mSpeed_;	//velocity
	Vector3 mAccel_;	//acceleration

	float mMass_;		//mass
	float mDamp_;		//damping

	double time_;
	double limit_;

	std::list<Particle*>::iterator mIt_;
	
	//components fo rendering the particle

	RenderItem* mBody_; //body of the particle itself
	Vector4 mColor_; //colour of the particle
	float mRadius_; //radius of the particle sphere

};

