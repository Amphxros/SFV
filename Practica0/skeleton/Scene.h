#pragma once
#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "Particle.h"
using namespace physx;

class Scene
{
public: 
	Scene() {};
	~Scene() { delete mParticle_; };

	void init();
	void run();


private:
	void initPhysics(bool interactive);
	void cleanupPhysics(bool interactive);

	
	void stepPhysics(bool interactive, double t);


	void onCollision(physx::PxActor* actor1, physx::PxActor* actor2);
	void keyPress(unsigned char key, const physx::PxTransform& camera);



	
	Particle* mParticle_;



};

