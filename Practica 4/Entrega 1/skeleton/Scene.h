#pragma once
#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "ParticleManager.h"
#include "Firework.h"
#include "ParticleGravity.h"
#include "ParticleForceRegistry.h"
#include <list>
using namespace physx;


enum FORCES {EARTH_GRAVITY, LUNAR_GRAVITY, DRAGGING, WIND, EXPLOSION,SPRING_A,SPRING_B,NUM_FORCES};

class Scene
{
public: 
	Scene(Vector3 p);
	~Scene();

	void run(double t);

	void addFireWork(Type t, Vector3 pos, Vector4 color);

	void addParticle(FORCES f, Vector3 pos, Vector3 vel,Vector4 color);
	void addSpring();

private:	
	ParticleManager* mManager_;
	std::vector<Firework*> mFireWorks_;
	std::vector<ParticleForceGenerator*> mForces_;

	ParticleForceRegistry* registry;
};

