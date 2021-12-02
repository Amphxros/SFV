#include "RigidBodyExplosion.h"

RigidBodyExplosion::RigidBodyExplosion(Vector3 center, float rd, float forceMod): 
	RigidBodySphereForce(center, rd), mForceMod_(forceMod)
{
	createVolume();
}

RigidBodyExplosion::~RigidBodyExplosion()
{
}

void RigidBodyExplosion::integrateForce(RigidBody* rb, float t)
{
}
