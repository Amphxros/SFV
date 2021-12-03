#include "ParticleContact.h"

ParticleContact::ParticleContact(Particle* particleA, Particle* particleB):
	mParticleA_(particleA), mParticleB_(particleB)
{
}

ParticleContact::~ParticleContact()
{
}

void ParticleContact::resolve(float t)
{
	resolveVelocity(t);
	resolveInterPenetration(t);
}

void ParticleContact::resolveVelocity(float t)
{

}

void ParticleContact::resolveInterPenetration(float t)
{
	if (mPenetration_ <= 0)
		return;
	else {
		float mTotalInvMass = (1 / mParticleA_->getMass()) + (1 / mParticleB_->getMass());
		if (mTotalInvMass <= 0) // si ambas tienen masa infinita no podemos moverlas
			return;
		else {
			Vector3 movePerIMass = mNormal_ *
				(-mPenetration_ / mTotalInvMass);

			if(1/mParticleA_->getMass() > 0)
				mParticleA_->setPosition(mParticleA_->getPosition() + movePerIMass / mParticleA_->getMass());

			if (1 / mParticleB_->getMass() > 0)
				mParticleB_->setPosition(mParticleB_->getPosition() + movePerIMass / mParticleB_->getMass());	
		}
	}
}
