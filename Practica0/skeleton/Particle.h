#pragma once

#include "RenderUtils.hpp"
#include "core.hpp"

class Particle
{
public:
	Particle();
	Particle(Vector3 pos, Vector3 speed, Vector3 accel, RenderItem* body, float mass);

	~Particle();
	void update(double t);
	

protected:
	Vector3 mPos_;
	Vector3 mSpeed_;
	Vector3 mAccel_;

	float mMass_;

	RenderItem* mBody_;


};

