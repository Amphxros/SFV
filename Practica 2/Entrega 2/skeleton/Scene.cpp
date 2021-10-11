#include "Scene.h"
#include <iostream>

Scene::Scene(Vector3 p)
{
	mParticleSystem = new ParticleSystem(p,0.6);
	mFireworkSystem = new FireworkSystem();
}

Scene::~Scene()
{
	delete mParticleSystem;
}


void Scene::run(double t)
{
	mParticleSystem->integrate(t);
}

void Scene::shootFireWork(int t)
{
	switch (t)
	{
	default:
		break;
	}
}

