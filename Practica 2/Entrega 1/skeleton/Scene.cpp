#include "Scene.h"
#include <iostream>

Scene::Scene(Vector3 p)
{
	mManager_ = new ParticleManager(p,0.2);
}

Scene::~Scene()
{
	delete mManager_;
}


void Scene::run(double t)
{
	mManager_->integrate(t);

}

void Scene::add()
{
	mManager_->addSome(100);
}

