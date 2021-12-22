#pragma once
#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "ParticleSpring.h"
#include "ParticleManager.h"
#include "ParticleGravity.h"
#include "ParticleForceRegistry.h"
#include <list>
#include "ForceRegister.h"
#include "RigidBodyForceRegistry.h"
#include "FireWorkSystem.h"
using namespace physx;

class Scene
{
public: 
	Scene(physx::PxScene* scene, physx::PxPhysics* physics);
	~Scene();
	void init();
	void run(double t);
	void handleEvent(unsigned char key);


private:	
	void createParticle(Vector3 pos, Vector4 color);
	void createSolidRigid(Vector3 pos, Vector4 color);
	void addFireWork(Type t, Vector3 pos, Vector4 color);
	void createForces();
	void createLevel();

	std::vector<Firework*> mFireWorks_;
	ParticleForceRegistry* particle_registry;
	RigidBodyForceRegistry* rb_registry;

	ParticleForceRegister* mParticleForces_;
	RigidBodyForceRegister* mRigidBodyForces_;
	FireWorkSystem* fwSys_;

	physx::PxScene* mScene_;
	physx::PxPhysics* mPhysics_;

	float time_ = 0;
	Particle* goal;

};

