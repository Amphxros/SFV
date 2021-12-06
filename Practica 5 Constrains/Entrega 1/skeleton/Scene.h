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
#include "ParticleContact.h"
#include "ParticleLink.h"
using namespace physx;

enum FORCES {EARTH_GRAVITY, LUNAR_GRAVITY, DRAGGING, WIND, EXPLOSION, BUOYANCY, BUNGEE,SPRING_A,NUM_FORCES};

class Scene
{
public: 
	Scene(Vector3 p);
	~Scene();

	void run(double t);

	void addFireWork(Type t, Vector3 pos, Vector4 color);

	void addParticle(FORCES f, Vector3 pos, Vector3 vel,Vector4 color);
	void addSpring();

	void addBuoyancyParticle(Vector3 pos, Vector3 speed, Vector4 color, float rd, float mass);
	void addK();
	void sustrateK();

	void setParticleSpeed(Vector3 v) { mParticleA->setSpeed(v); }

private:	
	ParticleManager* mManager_;
	std::vector<Firework*> mFireWorks_;
	std::vector<ParticleForceGenerator*> mForces_;
	ParticleSpring* muelle;
	ParticleForceRegistry* registry;

	Particle* mParticleA;
	Particle* mParticleB;
	ParticleContact* mContact_;
	ParticleCable* mCable_;

};

