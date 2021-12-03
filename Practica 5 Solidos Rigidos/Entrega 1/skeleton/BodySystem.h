#pragma once
#include <vector>
#include <PxPhysicsAPI.h>
#include "RenderUtils.hpp"
#include "RenderUtils.hpp"
#include "core.hpp"
#include "StaticRigidbdy.h"
#include "Rigidbody.h"
#include "callbacks.hpp"
#include "RigidBodyExplosion.h"
#include "RigidbodyForceRegistry.h"



class BodySystem
{
public:
	BodySystem(physx::PxPhysics* physics, physx::PxScene* scene, float time);

	void createStaticBox(Vector3 pos,Vector4 color);
	void createStaticSphere(Vector3 pos, Vector4 color);
	RigidBody* createDynamic(Vector3 pos, Vector3 speed);

	void run(float t);
	void activateExplosion();

private:
	float time_;
	float timeToSpawn_;
	physx::PxPhysics* mPhysics_;
	physx::PxScene* mScene_;
	
	

	RigidbodyForceRegistry* mRegistry_;
	RigidBodyExplosion* mExplosion_;

};

