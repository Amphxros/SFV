#include "BodySystem.h"
#include <PxPhysicsAPI.h>

BodySystem::BodySystem(physx::PxPhysics* physics, float time): 
	mPhysics_(physics), timeToSpawn_(time)
{
	time_ = 0;

	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	mMaterial_ = mPhysics_->createMaterial(0.5f, 0.5f, 0.6f);

	physx::PxSceneDesc sceneDesc(mPhysics_->getTolerancesScale());
	sceneDesc.gravity = physx::PxVec3(0.0f, -9.81f, 0.0f);
	sceneDesc.cpuDispatcher = physx::PxDefaultCpuDispatcherCreate(2);
	//sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	mScene_ = mPhysics_->createScene(sceneDesc);
	// ------------------------------------------------------

}

void BodySystem::createStatic(Vector3 pos)
{
}

void BodySystem::createDynamic(Vector3 pos)
{
}
