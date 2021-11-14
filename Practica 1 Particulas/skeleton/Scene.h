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

//equivalent to a particle manager, basically handle the particle creation, destruction and update
class Scene
{
public: 
	Scene() {};
	~Scene();

	//initialize the list
	void init();
	
	//updates all the particles and deletes if needed
	void run(double t);

	//add a particle with these parameters p= position, v= speed, a=accel, m=mass ...
	void addParticle(Vector3 p, Vector3 v, Vector3 a, float m, float d, float r, Vector4 c);

private:	
	std::list<Particle*> mParticles_;
};

