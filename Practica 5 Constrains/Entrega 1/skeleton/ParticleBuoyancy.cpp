#include "ParticleBuoyancy.h"

ParticleBuoyancy::ParticleBuoyancy( float depth, float height, float density=1000): 
    ParticleForceGenerator(Vector3(0,0,0)), maxDepth_(depth), mHeightBody_(height), mDensityBody_(density)
{
    mParticle_ = new Particle(Vector3(0,mHeightBody_,0), Vector3(), Vector3(), 0,0,mHeightBody_, Vector4(0.3, 0.3, 0.9, 0.1), 0);
    //mParticle_->setBoxBody(mHeightBody_, 0.1,  mHeightBody_);
   
    mVolume_ = mHeightBody_*mHeightBody_;

}

ParticleBuoyancy::~ParticleBuoyancy()
{
    delete mParticle_;
}

void ParticleBuoyancy::integrateForce(Particle* p, float t)
{
        float depth=  p->getPosition().y;
        Vector3 f= Vector3(0.0f, 0.0f, 0.0f);
        if (depth > (mHeightBody_ + maxDepth_)) {
            p->setBoxBody();
            
            
            return;
        }
        p->setSphereBody();
        if (depth < (mHeightBody_/2 - maxDepth_)) {
            
            f.y = mDensityBody_ * mVolume_;
        }
        else {
            p->clearForce();
            float depthExt = mHeightBody_ + maxDepth_;
            float volFactor = (depthExt - depth) / (2 * maxDepth_);
            f.y = mDensityBody_ * mVolume_ * volFactor;
            
        }
        p->addForce(f);
  
}

