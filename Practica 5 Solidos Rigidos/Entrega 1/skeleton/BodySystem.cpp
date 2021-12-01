#include "BodySystem.h"
#include <PxPhysicsAPI.h>
#include <iostream>
#include <cassert>

BodySystem::BodySystem(physx::PxPhysics* physics, physx::PxScene* scene, float time):
	mPhysics_(physics), mScene_(scene),timeToSpawn_(time)
{
	time_ = 0;

	createStaticBox(Vector3(0, -20, 0), Vector4(0, 0.7, 0.5, 1));
}

void BodySystem::createStaticBox(Vector3 pos, Vector4 color)
{
	Staticbody* s = new Staticbody();


}

void BodySystem::createStaticSphere(Vector3 pos, Vector4 color)
{
	
}

void BodySystem::createDynamic(Vector3 pos, Vector3 speed)
{
	RigidBody* r = new RigidBody();
	physx::PxTransform* tr_ = new physx::PxTransform(pos);
	r->mPhysics_ = mPhysics_->createRigidDynamic(*tr_);
	physx::PxGeometry* geo = new physx::PxSphereGeometry(3);
	physx::PxShape* shape = CreateShape(*geo);
	r->mPhysics_->attachShape(*shape);
	r->mBody_ = new RenderItem(shape, r->mPhysics_, Vector4(0.1, 0.4, 0.4, 1));


	mScene_->addActor(*r->mPhysics_);
	r->mPhysics_->addForce(speed * r->mPhysics_->getMass());
}
