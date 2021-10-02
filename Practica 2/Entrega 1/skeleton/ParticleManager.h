#pragma once

#include <ctype.h>

#include <PxPhysicsAPI.h>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "Particle.h"
#include <list>

class ParticleManager
{
public:
	ParticleManager(Vector3 point,float time);
	~ParticleManager();

	void integrate(double t);

	void addNRandomParticles(int n);
	

protected:
	void add(Vector3 p , Vector3 v, Vector3 a, float d, float m, float r, Vector4 c, float time);
	
	std::list<Particle*> mParticles_;
	float gen_time_;
	float mTime_;
	Vector3 mPoint_;
};

