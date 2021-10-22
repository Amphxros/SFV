#pragma once
#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "ParticleManager.h"
#include "Firework.h"
#include <list>

#include "ParticleForceRegister.h"
#include "ParticleForceGenerator.h"
#include "ParticleGravity.h"
using namespace physx;

//equivalent to a particle manager, basically handle the particle creation, destruction and update
class Scene
{
public: 
	Scene(Vector3 p);
	~Scene();

	void run(double t);

	void addParticle(Vector3 pos, Vector4 color);
	void addFireWork(Type t, Vector3 pos, Vector4 color);

private:	
	Vector3 p_;
	ParticleManager* mManager_;
	std::vector<Firework*> mFireWorks_;
	std::list<Particle*> mParticles_;
	ParticleGravity* gravity;
	ParticleForceRegister* mRegister;

	int scene = 3;
	float time=0;

};

