#pragma once
#include <vector>
#include <PxPhysicsAPI.h>
#include "RenderUtils.hpp"
class BodySystem
{
public:
	BodySystem(float time);

	void createStatic(physx::PxScene* mScene);
	void createDynamic(physx::PxScene* mScene);

	void run(float t);


private:
	std::vector<physx::PxRigidStatic*> mStatics_;
	std::vector<physx::PxRigidDynamic*> mDynamics_;
	float time;
	float timeToSpawn_;
};

