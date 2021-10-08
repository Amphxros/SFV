#include "Scene.h"
#include <iostream>

Scene::Scene(Vector3 p)
{
	mParticleSystem = new ParticleSystem(p,0.1);
	
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

