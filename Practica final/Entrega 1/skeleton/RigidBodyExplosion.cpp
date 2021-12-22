#include "RigidBodyExplosion.h"

RigidBodyExplosion::RigidBodyExplosion(Vector3 pos, float rd):
	RigidBodyForceGenerator(Vector3(0,0,0)), mPos_(pos), rd_(rd)
{
}

RigidBodyExplosion::~RigidBodyExplosion()
{
	
}

void RigidBodyExplosion::integrateForce(RigidBody* rb, float t)
{
	//part_->integrate(t);
	mForce_ = part_->getPosition() - rb->getPosition();
	if (isParticleOnMyZone(rb)) {
		rb->addForce(-mForce_ * mForce_.normalize(),0.1);
	}
}

bool RigidBodyExplosion::isParticleOnMyZone(RigidBody* rb)
{
	if (part_ != nullptr) {
		return distance(rb->getPosition(), part_->getPosition()) < rd_;
	}
	return false;
}

float RigidBodyExplosion::distance(Vector3 posA, Vector3 posB)
{
	float x = (posA.x - posB.x) * (posA.x - posB.x);
	float y = (posA.y - posB.y) * (posA.y - posB.y);
	float z = (posA.z - posB.z) * (posA.z - posB.z);

	return sqrt(x + y + z);
}
