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
#include "BodySystem.h"
#include "RigidbodyForceRegistry.h"
using namespace physx;
  
enum PARTICLE_FORCES {EARTH_GRAVITY, LUNAR_GRAVITY, DRAGGING, WIND, EXPLOSION, BUOYANCY, BUNGEE,SPRING_A,NUM_FORCES};

enum RIGID_FORCES {GRAVITY, P_EXPLOSION};

class Scene
{
public: 
	Scene(Vector3 p);
	Scene(PxPhysics* physics);
	~Scene();

	void run(double t);

	void addFireWork(Type t, Vector3 pos, Vector4 color);

	void addParticle(PARTICLE_FORCES f, Vector3 pos, Vector3 vel,Vector4 color);
	void addSpring();

	void addBuoyancyParticle(Vector3 pos, Vector3 speed, Vector4 color, float rd, float mass);
	void addK();
	void sustrateK();


	void addRigidBody();

private:	
	ParticleManager* mManager_;
	std::vector<Firework*> mFireWorks_;
	std::vector<ParticleForceGenerator*> mForces_; 
	ParticleSpring* muelle;
	ParticleForceRegistry* particleregistry;
	RigidbodyForceRegistry* rigidbodyRegistry_;

	PxPhysics* mPhysics_;
	

	PxMaterial* gMaterial = NULL;

	PxPvd* gPvd = NULL;

	PxDefaultCpuDispatcher* gDispatcher = NULL;
	physx::PxScene* gScene;
	ContactReportCallback gContactReportCallback;

	BodySystem* mRigidSystem_;
};

