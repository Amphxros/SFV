#pragma once
#include <vector>
#include "Firework.h"
class FireWorkSystem
{
public:
	FireWorkSystem();
	~FireWorkSystem();

	void createFireWork(Type t, Vector3 pos, Vector4 color);
	void run(float t);
protected:
	std::vector<Firework*> mFireWorks_;

};


