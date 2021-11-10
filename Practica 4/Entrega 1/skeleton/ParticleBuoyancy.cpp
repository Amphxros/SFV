#include "ParticleBuoyancy.h"

ParticleBuoyancy::ParticleBuoyancy(Particle* particle, float depth, float height, float density=1000): 
    ParticleForceGenerator(), maxDepth_(depth), mHeightBody_(height), mDensityBody_(density)
{
    particle->setBoxBody(500,height,500);
    mVolume_ = 500 * 500 * mHeightBody_;

}

ParticleBuoyancy::~ParticleBuoyancy()
{
}

void ParticleBuoyancy::integrateForce(Particle* p, float t)
{
        float depth;
        depth = p->getPosition().y;
        Vector3 f(0.0f, 0.0f, 0.0f);
        if (depth > (mHeightBody_ + maxDepth_)) {
            return;
        }
        if (depth < (mHeightBody_ - maxDepth_)) {
        
            f.y = mDensityBody_ * mVolume_;
        }
        else {
            float depthExt = mHeightBody_ + maxDepth_;
            float volFactor = (depthExt - depth) / (2 * maxDepth_);
            f.y = mDensityBody_ * mVolume_ * volFactor;
            
        }
        p->addForce(f);
  
}
