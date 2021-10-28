#include "Scene.h"
#include <iostream>
#include "WindGenerator.h"

Scene::Scene(Vector3 p)
{
	registry = new ParticleForceRegistry();
	//mManager_ = new ParticleManager(p,1);
	mFireWorks_.reserve(1000);
	mForces_.reserve(100);
	ParticleGravity* earth_gravity = new ParticleGravity(Vector3(0, -0.00981, 0));
	ParticleGravity* lunar_gravity = new ParticleGravity(Vector3(0, -0.00162, 0));
	WindGenerator* w = new WindGenerator(Vector3(-0.5, 0, -0.5), Vector3(-50, 50, -150), 50);

	mForces_[(int)FORCES::EARTH_GRAVITY] = earth_gravity;
	mForces_[(int)FORCES::LUNAR_GRAVITY] = lunar_gravity;
	mForces_[(int)FORCES::WIND] = w;


}

Scene::~Scene()
{
	delete registry;
}


void Scene::run(double t)
{

	registry->integrateForces(t);
	

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

void Scene::addParticle(FORCES f, Vector3 pos, Vector3 vel, Vector4 color)
{
	std::cout << (int)f << std::endl;
	Particle* p = new Particle(pos, vel, Vector3(0,0,0), 0.9, 1,5, color, 10);
	registry->add(p, mForces_[(int)f]);
	
	
}

