#include "Scene.h"
#include <iostream>
#include "WindGenerator.h"
#include "ParticleDrag.h"
#include "ExplosionForce.h"

#include "ParticleAnchoredSpring.h"
#include "ParticleBungee.h"
#include "ParticleBuoyancy.h"


Scene::Scene(Vector3 p)
{
	registry = new ParticleForceRegistry();
	
	mForces_ = new ParticleForceRegister();
	mFireWorks_.reserve(1000);
	init();
}

Scene::~Scene()
{
	delete registry;

	
	for (auto f : mFireWorks_)
		delete f;
}

void Scene::init()
{
	createForces();
	createLevel();
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


void Scene::createForces()
{
	//fuerzas
	ParticleGravity* earth_gravity = new ParticleGravity(Vector3(0, -9.81, 0));		//100 veces menos ya que de lo contrario no se llega ni a percibir las particulas afectadas
	ParticleGravity* lunar_gravity = new ParticleGravity(Vector3(0, -1.62, 0));		//100 veces menos ya que de lo contrario no se llega ni a percibir las particulas afectadas
	WindGenerator* w = new WindGenerator(Vector3(-0.05, 0, 0), Vector3(0, 0, 0), 10);


	mForces_->addForce(ForceType::GRAVITY, earth_gravity);
	mForces_->addForce(ForceType::WIND, w);
}

void Scene::createLevel()
{
	Particle* back = new Particle(Vector3(100, 0, -10), Vector3(), Vector3(), 0, 0, 0, Vector4(0.03, 0.44, 0.59, 1), 0);
	back->setBoxBody(200,100,1);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ExplosionForce* e = new ExplosionForce(Vector3(20 * i - (10*(j % 2)), 10 * j, 0), 3);
			mForces_->addForce(ForceType::EXPLOSION, e);
		}
	}
}

