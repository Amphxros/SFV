#pragma once
#include "core.hpp"
#include "RenderUtils.hpp"

class RigidBody
{
public:
	RigidBody(physx::PxPhysics* physics, physx::PxScene* scene, Vector3 pos, float rd, Vector4 color);
	RigidBody(physx::PxPhysics* physics, physx::PxScene* scene, Vector3 pos, float x,float y,float z, Vector4 color);

	~RigidBody();

	inline Vector3 getPosition() { return mDynamic_->getGlobalPose().p; }
	inline void addForce(Vector3 force, float imp) { mDynamic_->addForce(force * imp); }
protected:

	physx::PxScene* mScene_;
	physx::PxPhysics* mPhysicsEngine_;

	physx::PxTransform* tr_;

	physx::PxRigidDynamic* mDynamic_;
	RenderItem* mBody_;

	Vector3 mPos_;
	Vector3 mSpeed_;
	Vector3 mAccel_;

	float drag_;
	Vector4 mColor_;

};

class StaticBody {
public:

};

