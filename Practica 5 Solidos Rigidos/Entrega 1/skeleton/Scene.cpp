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
	particleregistry = new ParticleForceRegistry();
	
	mFireWorks_.reserve(1000);
	mForces_ = std::vector<ParticleForceGenerator*>((int)PARTICLE_FORCES::NUM_FORCES);

	//fuerzas
	ParticleGravity* earth_gravity = new ParticleGravity(Vector3(0, -9.81, 0));		//100 veces menos ya que de lo contrario no se llega ni a percibir las particulas afectadas
	ParticleGravity* lunar_gravity = new ParticleGravity(Vector3(0, -1.62, 0));		//100 veces menos ya que de lo contrario no se llega ni a percibir las particulas afectadas
	ParticleDrag* drag = new ParticleDrag(0.5, 0.1);
	WindGenerator* w = new WindGenerator(Vector3(-0.05, 0, 0), Vector3(0, 0, 0), 10);
	ExplosionForce* explosion = new ExplosionForce(Vector3(0, 0, 0), 1);
	ParticleAnchoredSpring* anchor = new ParticleAnchoredSpring(Vector3(0, 20, 0), 0.1, 1);
	ParticleBuoyancy* buoya = new ParticleBuoyancy(10,80,1000);


	mForces_[(int)PARTICLE_FORCES::EARTH_GRAVITY] = earth_gravity;
	mForces_[(int)PARTICLE_FORCES::LUNAR_GRAVITY] = lunar_gravity;
	mForces_[(int)PARTICLE_FORCES::DRAGGING] = drag;
	mForces_[(int)PARTICLE_FORCES::WIND] = w;
	mForces_[(int)PARTICLE_FORCES::EXPLOSION] = explosion;
	mForces_[(int)PARTICLE_FORCES::SPRING_A] = anchor;
	mForces_[(int)PARTICLE_FORCES::BUOYANCY] = buoya;

	addSpring();
	//
}

Scene::Scene(PxPhysics* physics): 
	mPhysics_(physics)
{

	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	
	//mRigidSystem_ = new BodySystem(mPhysics_,0.1f);
}

Scene::~Scene()
{
	delete particleregistry;

	for (auto f : mForces_)
		delete f;
	for (auto f : mFireWorks_)
		delete f;
}


void Scene::run(double t)
{
	particleregistry->integrateForces(t);
	
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

void Scene::addParticle(PARTICLE_FORCES f, Vector3 pos, Vector3 vel, Vector4 color)
{
	Particle* p = new Particle(pos, vel, Vector3(0,0,0), 0.0009, 1,1, color, 100);
	particleregistry->add(p, mForces_[(int)f]);
	particleregistry->add(p, mForces_[(int)PARTICLE_FORCES::BUOYANCY]);
	particleregistry->add(p, mForces_[(int)PARTICLE_FORCES::EARTH_GRAVITY]);
}

void Scene::addSpring()
{
	int rx = -10 + rand() % 20;
	int ry = -10 + rand() % 20;
	int rz = -10 + rand() % 20;

	Particle* pA = new Particle(Vector3(0, 0, 0), Vector3(60, 0, 0), Vector3(0, 0, 0), 0.07, 10, 4, Vector4(0, 1, 1, 1), 999);
	Particle* pB = new Particle(Vector3(5, -10, 40), Vector3(rx, ry, rz), Vector3(0, 0, 0), 0.07, 10, 4, Vector4(1, 0, 1, 1), 999);

	muelle = new ParticleSpring(pA, 2,3.5);
	mForces_[(int)PARTICLE_FORCES::SPRING_A] = muelle;
	particleregistry->add(pA, muelle);
	particleregistry->add(pB, muelle);

	particleregistry->add(pB, mForces_[PARTICLE_FORCES::EARTH_GRAVITY]);
		
}

void Scene::addBuoyancyParticle(Vector3 pos, Vector3 speed, Vector4 color, float rd, float mass)
{
	Particle* p = new Particle(pos, speed, Vector3(0, 0.5, 0), 0.79, 1, 1, color, 100);
	particleregistry->add(p, mForces_[(int)PARTICLE_FORCES::BUOYANCY]);
	particleregistry->add(p, mForces_[(int)PARTICLE_FORCES::EARTH_GRAVITY]);

}

void Scene::addK()
{
	muelle->addK(1);
}

void Scene::sustrateK()
{
	muelle->addK(-1);
}

void Scene::addRigidBody()
{
	if (mRigidSystem_ != nullptr && mPhysics_ != nullptr) {
		
		Vector3 pos = Vector3(0, 0, 0); //cambiar esto por random
		Vector3 speed = Vector3(0, 0, 0);
		
		mRigidSystem_->createDynamic(pos, speed);
	}
}

