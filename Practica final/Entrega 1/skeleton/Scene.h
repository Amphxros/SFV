#pragma once
#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "ParticleSpring.h"
#include "ParticleManager.h"
#include "Firework.h"
#include "ParticleGravity.h"
#include "ParticleForceRegistry.h"
#include <list>
#include "ForceRegister.h"
using namespace physx;

class Scene
{
public: 
	Scene(Vector3 p);
	~Scene();
	void init();
	void run(double t);

	void addFireWork(Type t, Vector3 pos, Vector4 color);

private:	

	void createForces();
	void createLevel();

	std::vector<Firework*> mFireWorks_;
	
	ParticleForceRegistry* registry;
	ParticleForceRegister* mForces_;

	int level_;

};

