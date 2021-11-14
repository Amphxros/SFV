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
using namespace physx;

//equivalent to a particle manager, basically handle the particle creation, destruction and update
class Scene
{
public: 
	Scene(Vector3 p);
	~Scene();

	void run(double t);

	void addFireWork(Type t, Vector3 pos, Vector4 color);

private:	
	ParticleManager* mManager_;
	std::vector<Firework*> mFireWorks_;

};

