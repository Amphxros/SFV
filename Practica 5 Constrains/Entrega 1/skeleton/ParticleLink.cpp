#include "ParticleLink.h"

ParticleCable::ParticleCable(Particle* particleA, Particle* particleB, float maxLength):
	ParticleLink(particleA, particleB), mMaxLength_(maxLength)
{
}

unsigned ParticleCable::addContact(ParticleContact* contact)
{
	float length = getCurrentLength();
	if (length > mMaxLength_) {
		return 0;
	}
	else {
		contact = new ParticleContact(mParticleA_, mParticleB_);
		contact->setNormal((mParticleB_->getPosition() - mParticleA_->getPosition()).getNormalized());
		contact->setPenetration(length - mMaxLength_);
		contact->setRestitution(0.5);

		return 1;
	}

}

ParticleRod::ParticleRod(Particle* particleA, Particle* particleB, float length):
	ParticleLink(particleA, particleB), mLength_(length)
{
}

unsigned ParticleRod::addContact(ParticleContact* contact)
{
	float length = getCurrentLength();
	
	if (mLength_ == length) {
		return 0;
	}
	else {
		contact = new ParticleContact(mParticleA_, mParticleB_);
		if (length > mLength_) {
			contact->setNormal((mParticleB_->getPosition() - mParticleA_->getPosition()).getNormalized());
			contact->setPenetration(mLength_ - length);
		}
		else {
			contact->setNormal(-(mParticleB_->getPosition() - mParticleA_->getPosition()).getNormalized());
			contact->setPenetration(length -mLength_ );
		}
	}
	contact->setPenetration(0);
	
	return 1;
}
