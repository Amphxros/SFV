#include "Scene.h"
#include <iostream>

Scene::Scene(Vector3 p): p_(p)
{
	switch (scene) {
	case 1:
		mManager_ = new ParticleManager(p,1);
		break;
	case 2:
		mFireWorks_.reserve(1000);
		break;
	case 3:
		mRegister = new ParticleForceRegister();
		break;
	}
}

Scene::~Scene()
{
	//delete mManager_;
}


void Scene::run(double t)
{
	switch (scene) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		
		time -= t;
		if (time < 0) {
			time = 0.5;
			gravity = new ParticleGravity(Vector3(0.1f, 2.9f, 0.1f));
			Particle* p = new Particle(p_, Vector3(1, 1, 1), Vector3(), 0.01, 0.01, 3, Vector4(1, 1, 1, 1), 10);
			gravity->integrateForce(p, t);
			mRegister->add(p, gravity);
		}
		mRegister->integrateForces(t);
		break;

	}

}

void Scene::addParticle(Vector3 pos, Vector4 color)
{
}

void Scene::addFireWork(Type t, Vector3 pos, Vector4 color)
{
	Firework* f = new Firework(pos,Vector3(0,10,0),color,0,(int)t, 10);
	mFireWorks_.push_back(f);
}

