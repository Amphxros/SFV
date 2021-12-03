#pragma once
#include "RenderUtils.hpp"
#include <foundation/PxMat33.h>

struct RigidBody {
	RenderItem* mBody_;
	physx::PxRigidDynamic* mPhysics_;

	float mLifetime_;
	float linearDamping;

	// Inverse tensor in local coordinates 
	physx::PxMat33 inverseInertiaTensor;
	physx::PxTransform tr_;

	//position
	Vector3 mPosition_;
	// Velocities 
	Vector3 velocity; // linear 
	Vector3 rotation; // angular
	Vector4 mOrientation_=Vector4();
	Vector3 mForce_;
	Vector3 mTorque_;
	
	void addForceAtPoint(const Vector3& _f, const Vector3& _p) {
		Vector3 pt = _p;
		pt -= mPosition_;
		mForce_ += _f;
		mTorque_ += pt.cross(_f);
	}

	void addForceAtLocalPoint(const Vector3& _f, const Vector3& _p) {
		Vector3 pt = tr_.transform(_p);
		addForceAtPoint(_f, pt);
	}

	//physx::PxMat33 getWorldInverseInertiaTensor(){
	//	physx::PxMat33 R= physx::PxMat33(mOrientation_);
	//	physx::PxMat33 invR = R.getTranspose();
	//	physx::PxMat33 Iw = R * inverseInertiaTensor;
	//	Iw = Iw * invR;
	//	return Iw;
	//}

	Vector3 getWorldPosition() { return tr_.p; }
	void clearAccumulators() { mForce_.isZero(); mTorque_.isZero(); }
};