#include "Firework.h"

void Firework::update(float t)
{
	Particle::update(t);
	if (Particle::isTimeOver(t)) {
		//delete the parent dynamic memory
		DeregisterRenderItem(mBody_);
		delete mBody_;
		delete mTransform_;

		// and if it's needed create the children fireworks


	}
}
