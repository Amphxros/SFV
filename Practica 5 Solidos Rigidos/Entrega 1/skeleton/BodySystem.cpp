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
	physx::PxTransform tr_ = physx::PxTransform(pos);
	physx::PxRigidStatic* statics = mPhysics_->createRigidStatic(tr_);
	RenderItem* mBody_ = new RenderItem(CreateShape(physx::PxSphereGeometry(4)), &tr_, Vector4());
	StaticRigidbody* body = new StaticRigidbody(statics, mBody_, 0);

	mScene_->addActor(*body->getStaticBody());
}

void BodySystem::createDynamic(Vector3 pos, Vector3 speed)
{
	physx::PxTransform tr_ = physx::PxTransform(pos);
	physx::PxRigidDynamic* dynamics = mPhysics_->createRigidDynamic(tr_);
	RenderItem* mBody_ = new RenderItem(CreateShape(physx::PxSphereGeometry(4)), &tr_, Vector4());
	RigidBody* body = new RigidBody(dynamics, mBody_, 0);

	mScene_->addActor(*body->getMyRigidBody());
	body->getMyRigidBody()->addForce(speed * body->getMyRigidBody()->getMass());

}
