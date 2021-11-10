#include "Scene.h"
#include <iostream>
#include "WindGenerator.h"
#include "ParticleDrag.h"
#include "ExplosionForce.h"
#include "ParticleSpring.h"
#include "ParticleAnchoredSpring.h"
#include "ParticleBungee.h"
Scene::Scene(Vector3 p)
{
	registry = new ParticleForceRegistry();
	
	mFireWorks_.reserve(1000);
	mForces_.reserve(FORCES::NUM_FORCES);

	//fuerzas
	ParticleGravity* earth_gravity = new ParticleGravity(Vector3(0, -0.00981, 0));		//100 veces menos ya que de lo contrario no se llega ni a percibir las particulas afectadas
	ParticleGravity* lunar_gravity = new ParticleGravity(Vector3(0, -0.00162, 0));		//100 veces menos ya que de lo contrario no se llega ni a percibir las particulas afectadas
	ParticleDrag* drag = new ParticleDrag(0.5, 0.1);
	WindGenerator* w = new WindGenerator(Vector3(-0.5, 0, -0.5), Vector3(-50, 50, -150), 70);
	ExplosionForce* explosion = new ExplosionForce(Vector3(-50,0, 50), 50);
	ParticleAnchoredSpring* anchor = new ParticleAnchoredSpring(Vector3(0, 20, 0), 0.1, 1);

	mForces_[(int)FORCES::EARTH_GRAVITY] = earth_gravity;
	mForces_[(int)FORCES::LUNAR_GRAVITY] = lunar_gravity;
	mForces_[(int)FORCES::DRAGGING] = drag;
	mForces_[(int)FORCES::WIND] = w;
	mForces_[(int)FORCES::EXPLOSION] = explosion;
	mForces_[(int)FORCES::SPRING_A] = anchor;

	//
}

Scene::~Scene()
{
	delete registry;

	for (auto f : mForces_)
		delete f;
	for (auto f : mFireWorks_)
		delete f;
}


void Scene::run(double t)
{
	registry->integrateForces(t);
	
	for (auto it = mFireWorks_.begin(); it != mFireWorks_.end(); ++it) {
		Firework* f = *it;
		f->integrate(t);
	}

	int i = rand() % 100;
	if (i == 1) {
		int rX = 1 + rand() % 20;
		int rY = 0 + rand() % 20;
		int rZ = 1 + rand() % 20;
		addParticle(FORCES::WIND, Vector3(50, 50, -50), Vector3(-10, 0, -30) - Vector3(rX, -rY / 2, rZ), Vector4(0, 1, 0.5, 1));
	}
}

void Scene::addFireWork(Type t, Vector3 pos, Vector4 color)
{
	Firework* f = new Firework(pos,Vector3(0,10,0),color,0,(int)t, 20);
	mFireWorks_.push_back(f);
}

void Scene::addParticle(FORCES f, Vector3 pos, Vector3 vel, Vector4 color)
{
	Particle* p = new Particle(pos, vel, Vector3(0,0,0), 0.79, 1,1, color, 100);
	registry->add(p, mForces_[(int)f]);
	if (f == FORCES::SPRING_A) {
		registry->add(p, mForces_[(int)FORCES::EARTH_GRAVITY]);
	}
}

void Scene::addSpring()
{
	Particle* pA = new Particle(Vector3(10,-10,0), Vector3(0,0,0), Vector3(0, 0, 0), 0.79, 1, 1, Vector4(1,1,1,1), 999);
	ParticleSpring* muelleA = new ParticleSpring(pA, 0.01, 9.75);

	Particle* pB = new Particle(Vector3(10, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.79, 1, 1, Vector4(1, 1, 1, 1), 999);
	ParticleSpring* muelleB = new ParticleSpring(pB, 0.01, 9.75);

	registry->add(pA, muelleB);  
	registry->add(pB, muelleA);

	registry->add(pA, mForces_[(int)FORCES::LUNAR_GRAVITY]);
	//registry->add(pB, mForces_[(int)FORCES::EARTH_GRAVITY]);
}

