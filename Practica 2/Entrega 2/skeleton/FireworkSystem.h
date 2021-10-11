#pragma once
#include "Firework.h"
#include <list>

const int NUM_RULES = 4; //numero de reglas en este sistema

class FireworkSystem
{
public:
	FireworkSystem() {};
	~FireworkSystem();

	void addFirework(Firework* f);
	void integrateParticles(float t);
	
protected:
	std::list<Particle*> mFireWorks_;
	std::vector<FireworkRules> sys_Rules;
	void setFireworkRules();

};

