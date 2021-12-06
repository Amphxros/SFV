#include "ParticleLink.h"

ParticleCable::ParticleCable(Particle* particleA, Particle* particleB, float maxLength):
	ParticleLink(particleA, particleB), mMaxLength_(maxLength)
{
}

unsigned ParticleCable::addContact(ParticleContact* contact)
{
	float length = getCurrentLength();
	if (length < mMaxLength_) {
		return 0;
	}
	else {
		contact = new ParticleContact(mParticleA_, mParticleB_);
		contact->setNormal((mParticleB_->getPosition() - mParticleA_->getPosition()).getNormalized());
		contact->setPenetration(length - mMaxLength_);
		contact->setRestitution(mRestitution_);

		return 1;
	}

}
