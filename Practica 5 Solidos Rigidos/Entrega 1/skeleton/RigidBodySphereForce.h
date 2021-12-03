#pragma once

#include "RigidbodyForceGenerator.h"

class RigidBodySphereForce :
    public RigidbodyForceGenerator
{
public:
    RigidBodySphereForce(Vector3 center, float rd);
    virtual ~RigidBodySphereForce();

    bool rigidBodyInsideVolume(Vector3 pos);
    void createVolume();
protected:
    Vector3 mCenter_;
    physx::PxTransform tr_;
    float mRD_;
    RenderItem* mBody_;
    physx::PxSphereGeometry* mGeometry_;
    
   
};

