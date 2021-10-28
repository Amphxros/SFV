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


enum FORCES {EARTH_GRAVITY, LUNAR_GRAVITY, DRAGGING, WIND, NUM_FORCES};
//equivalent to a particle manager, basically handle the particle creation, destruction and update
class Scene
{
public: 
	Scene(Vector3 p);
	~Scene();

	void run(double t);

	void addFireWork(Type t, Vector3 pos, Vector4 color);

	void addParticle(FORCES f, Vector3 pos, Vector3 vel,Vector4 color);


private:	
	ParticleManager* mManager_;
	std::vector<Firework*> mFireWorks_;
	std::vector<ParticleForceGenerator*> mForces_;

	ParticleForceRegistry* registry;
};

