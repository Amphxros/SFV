#pragma once
#include <vector>
#include <PxPhysicsAPI.h>
#include "RenderUtils.hpp"
#include "RenderUtils.hpp"
#include "core.hpp"
#include "StaticRigidbdy.h"
#include "Rigidbody.h"
#include "callbacks.hpp"
class BodySystem
{
public:
	BodySystem(physx::PxPhysics* physics,float time);

	void createStatic(Vector3 pos);
	void createDynamic(Vector3 pos, Vector3 speed);

	void run(float t);


private:
	float time_;
	float timeToSpawn_;
	physx::PxPhysics* mPhysics_;
	std::vector<RigidBody*> mRigidBodys_;
	std::vector<StaticRigidbody*> mStaticBodys_;

	physx::PxScene* mScene_;
	physx::PxMaterial* mMaterial_;
	ContactReportCallback gContactReportCallback;

};

