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
	physx::PxTransform* tr_ = new physx::PxTransform(pos);
	s->mPhysics_ = mPhysics_->createRigidStatic(*tr_);
	physx::PxGeometry* geo = new physx::PxBoxGeometry(300,3,300);
	physx::PxShape* shape = CreateShape(*geo);
	s->mPhysics_->attachShape(*shape);
	s->mBody_ = new RenderItem(shape, s->mPhysics_, color);
	mScene_->addActor(*s->mPhysics_);
}

void BodySystem::createStaticSphere(Vector3 pos, Vector4 color)
{
	Staticbody* s = new Staticbody();
	physx::PxTransform* tr_ = new physx::PxTransform(pos);
	s->mPhysics_ = mPhysics_->createRigidStatic(*tr_);
	physx::PxGeometry* geo = new physx::PxSphereGeometry(3);
	physx::PxShape* shape = CreateShape(*geo);
	s->mPhysics_->attachShape(*shape);
	s->mBody_ = new RenderItem(shape, s->mPhysics_, color);
	mScene_->addActor(*s->mPhysics_);

}

void BodySystem::createDynamic(Vector3 pos, Vector3 speed)
{
	RigidBody* r = new RigidBody();
	
	physx::PxTransform* tr_ = new physx::PxTransform(pos+ Vector3(rand()%10, rand() % 10, rand() % 10));
	r->mPhysics_ = mPhysics_->createRigidDynamic(*tr_);
	physx::PxGeometry* geo = new physx::PxSphereGeometry(3);
	physx::PxShape* shape = CreateShape(*geo);
	r->mPhysics_->attachShape(*shape);
	r->mBody_ = new RenderItem(shape, r->mPhysics_, Vector4(0.1, 0.4, 0.4, 1));
	r->mLifetime_ = 12;

	mScene_->addActor(*r->mPhysics_);
	r->mPhysics_->addForce(speed * r->mPhysics_->getMass());

	mRigidBodys_.push_back(r);
}

void BodySystem::run(float t)
{
	time_ += t;

	if (time_ > timeToSpawn_) {
		
		time_ = 0;
		createDynamic(Vector3(0, 0, 0), Vector3(10, 10, 10));
	
	}

	for (auto it = mRigidBodys_.begin(); it != mRigidBodys_.end() && !mRigidBodys_.empty();) {
		RigidBody* r = *it;

		r->mLifetime_ -=t;
		if (r->mLifetime_ <= 0) {
			
			r->mBody_->release();
			delete r;

			it =mRigidBodys_.erase(it);
		}
		else {
			++it;
		}
	}

}
