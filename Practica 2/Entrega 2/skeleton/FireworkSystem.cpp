#include "FireworkSystem.h"

void FireworkSystem::addFirework(Firework* f)
{
	std::list<Particle*>::iterator it = mFireWorks_.insert(mFireWorks_.end(), f);
	f->setIt(it);
}

void FireworkSystem::integrateParticles(float t)
{
	for (auto& p : mFireWorks_) {
		p->integrate(t);

		if (p->isTimeOver(t)) {

			mFireWorks_.erase(p->getIt());
			delete p;
		}
	}

}
