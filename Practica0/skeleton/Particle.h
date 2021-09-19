#pragma once
#include <PxPhysicsAPI.h>
#include "RenderUtils.hpp"
#include "core.hpp"

class Particle
{
public:
	Particle(Vector3 pos, Vector3 speed, Vector3 accel, float drag, float mass, float rd, Vector4 col);
	~Particle();
	void update(double t);
	
protected:
	//components for the physics of the particle

	physx::PxTransform* mTransform_; //transform para actualizar el cuerpo

	Vector3 mPos_;		//position
	Vector3 mSpeed_;	//velocity
	Vector3 mAccel_;	//acceleration

	float mMass_;		//mass
	float mDrag_;		//damping

	
	//components fo rendering the particle

	RenderItem* mBody_; //body of the particle itself
	Vector4 mColor_; //colour of the particle
	float mRadius_; //radius of the particle sphere

};

