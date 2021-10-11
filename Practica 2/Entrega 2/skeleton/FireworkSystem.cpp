#include "FireworkSystem.h"

FireworkSystem::~FireworkSystem()
{
	for (auto* p : mFireWorks_) {
		delete p;
	}
}

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
			FireworkRules r;
			for (int i = 0; i < r.getPayloads().size(); i++) {
				for (size_t j = 0; j < r.getPayloads()[i].mCount_; j++) {
					Payload payload = r.getPayloads()[i];

					
				}
			}


			mFireWorks_.erase(p->getIt());
			delete p;
		}
	}
}

void FireworkSystem::setFireworkRules()
{
	sys_Rules.reserve(Type::NUM_TYPES);

	for (int i = 0; i < sys_Rules.size(); i++) {
		sys_Rules[i] = FireworkRules(Type(i),3, 6, Vector3(0, 10, 0), Vector3(0, 20, 0), 0.9, 0, this);
	}

}
