#pragma once
#include <vector>
#include <PxPhysicsAPI.h>
#include "RenderUtils.hpp"
#include "RenderUtils.hpp"
#include "core.hpp"
class BodySystem
{
public:
	BodySystem(float time);

	void createStatic(physx::PxScene* mScene);
	void createDynamic(physx::PxScene* mScene);

	void run(float t);


private:
	float time;
	float timeToSpawn_;

	std::vector<RigidBody*> mRigidBodys_;
};

