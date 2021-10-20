#include "Scene.h"
#include <iostream>

Scene::Scene(Vector3 p)
{
	//mManager_ = new ParticleManager(p,1);
	mFireWorks_.reserve(1000);
}

Scene::~Scene()
{
	//delete mManager_;
}


void Scene::run(double t)
{
	//mManager_->integrate(t);

	for (auto it = mFireWorks_.begin(); it != mFireWorks_.end(); ++it) {
		Firework* f = *it;
		f->integrate(t);
	}
	
}

void Scene::addFireWork(Type t, Vector3 pos, Vector4 color)
{
	Firework* f = new Firework(pos,Vector3(0,10,0),color,0,(int)t, 20);
	mFireWorks_.push_back(f);
}

