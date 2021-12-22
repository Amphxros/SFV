#include "FireWorkSystem.h"

FireWorkSystem::FireWorkSystem()
{
	mFireWorks_.reserve(1000);
}

FireWorkSystem::~FireWorkSystem()
{
}

void FireWorkSystem::createFireWork(Type t, Vector3 pos, Vector4 color)
{
	Firework* f = new Firework(pos, Vector3(0, 10, 0), color, 0, (int)t, 20);
	mFireWorks_.push_back(f);

}

void FireWorkSystem::run(float t)
{

	for (auto it = mFireWorks_.begin(); it != mFireWorks_.end(); ++it) {
		Firework* f = *it;
		f->integrate(t);
	}
}
