#pragma once
#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "Particle.h"
#include <list>
using namespace physx;

class Scene
{
public: 
	Scene() {};
	~Scene();

	void init();
	void run(double t);

	void addParticle(Vector3 p, Vector3 v, Vector3 a, float m, float d, float r, Vector4 c);



private:
	
	std::list<Particle*> mParticles_;
};

