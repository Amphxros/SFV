#pragma once
#include "Firework.h"
#include <list>
class FireworkSystem
{
public:
	FireworkSystem() {};
	~FireworkSystem();

	void addFirework(Firework* f);
	void integrateParticles(float t);
	
protected:
	std::list<Particle*> mFireWorks_;

};

