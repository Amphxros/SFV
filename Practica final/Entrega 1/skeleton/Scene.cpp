#include "Scene.h"
#include <iostream>
#include "WindGenerator.h"
#include "ParticleDrag.h"
#include "ExplosionForce.h"

#include "ParticleAnchoredSpring.h"
#include "ParticleBungee.h"
#include "ParticleBuoyancy.h"
#include "InverseExplosionForce.h"
#include "RigidBodyExplosion.h"
#include "ForceRegister.h"

Scene::Scene(physx::PxScene* scene, physx::PxPhysics* physics):
	mScene_(scene), mPhysics_(physics)
{
	srand(1);
	particle_registry = new ParticleForceRegistry();
	rb_registry = new RigidBodyForceRegistry();
	mParticleForces_ = new ParticleForceRegister();
	mRigidBodyForces_ = new RigidBodyForceRegister();
	fwSys_ = new FireWorkSystem();
	init();
}

Scene::~Scene()
{
	delete particle_registry;

	
	for (auto f : mFireWorks_)
		delete f;

	delete goal;
	delete mParticleForces_;
}

void Scene::init()
{
	createForces();
	createLevel();
}


void Scene::run(double t)
{

	time_ += t;
	rb_registry->integrateForces(t);
	fwSys_->run(t);
	if (particle_registry->integrateForces(t)&& time_>10) {
		addFireWork(Type::SPHERE, goal->getPosition(), Vector4(0, 0.5, 0.2, 1));
		time_ = 0;
		int goal_ind = 1 + rand() % 49;
		Vector3 pos = static_cast<ExplosionForce*>(mParticleForces_->getForce(ForceType::EXPLOSION, goal_ind))->getAssociatedParticle()->getPosition();
		pos += Vector3(0, -10, 0);
		goal = new Particle(pos, Vector3(0, 0, 0), Vector3(0, 0, 0), 0.5, 3, 3, Vector4(0, 0.65, 0.45, 0.3), 0);
		static_cast<InverseExplosionForce*>(mParticleForces_->getForce(ForceType::ABSORCION))->setParticle(goal);
	
	}
	
	
	
}

void Scene::handleEvent(unsigned char key)
{
	switch (toupper(key))
	{
		
	case 'Q':

		for (int i = 0; i < 20; i++) {
			createParticle(Vector3(20-rand()%5*i, 50, 0), Vector4(1, 0, 0.5, 1));
			createSolidRigid(Vector3(20 - rand() % 5 * i, 50, 0), Vector4(1, 0.5, 0.1, 1));
			
		}
		break;
	case 'E':
		for (int i = 0; i < 20; i++) {
			createParticle(Vector3(130 - rand() % 5 * i, 50, 0), Vector4(1, 0, 0.5, 1));

			createSolidRigid(Vector3(130 - rand() % 5, 50 , 0), Vector4(1, 0.5, 0.1, 1));
		}
		break;
	default:
		break;
	}
}

void Scene::createParticle(Vector3 pos, Vector4 color)
{
	Particle* p = new Particle(pos, Vector3(0, 10, 0), Vector3(0, 0, 0), 0.5, 0.1, 1, color, 600);

	for (int i = 0; i < 50; i++) {
		particle_registry->add(p, mParticleForces_->getForce(ForceType::EXPLOSION,i));
	}
	particle_registry->add(p, mParticleForces_->getForce(ForceType::GRAVITY));
	particle_registry->add(p, mParticleForces_->getForce(ForceType::WIND));
	particle_registry->add(p, mParticleForces_->getForce(ForceType::WIND,1));
	particle_registry->add(p, mParticleForces_->getForce(ForceType::ABSORCION));
}

void Scene::createSolidRigid(Vector3 pos, Vector4 color)
{
	RigidBody* rb = new RigidBody(mPhysics_, mScene_, pos, 1, 1, 1, color);

	for (int i = 0; i < 50; i++) {
		rb_registry->add(rb, mRigidBodyForces_->getForce(ForceType::EXPLOSION, i));
	}
}

void Scene::addFireWork(Type t, Vector3 pos, Vector4 color)
{
	fwSys_->createFireWork(t, pos, color);
}

void Scene::createForces()
{

	//fuerzas de particulas
	ParticleGravity* earth_gravity = new ParticleGravity(Vector3(0, -9.81, 0));		//100 veces menos ya que de lo contrario no se llega ni a percibir las particulas afectadas
	ParticleGravity* lunar_gravity = new ParticleGravity(Vector3(0, -1.62, 0));		//100 veces menos ya que de lo contrario no se llega ni a percibir las particulas afectadas
	WindGenerator* w = new WindGenerator(Vector3(-0.05, 0.01, 0), Vector3(140, 50, 0), 120);
	WindGenerator* w2 = new WindGenerator(Vector3(0.05, 0.01, 0), Vector3(-60, 50, 0), 120);
	

	mParticleForces_->addForce(ForceType::GRAVITY, earth_gravity);
	mParticleForces_->addForce(ForceType::WIND, w);
	mParticleForces_->addForce(ForceType::WIND, w2);
	
	//fuerzas de solidos rigidos
	
}

void Scene::createLevel()
{
	//back = new Particle(Vector3(100, 0, -10), Vector3(), Vector3(), 0, 0, 0, Vector4(0.03, 0.44, 0.59, 1), 0);
	//back->setBoxBody(200,100,1);
	for (int i = 0; i < 5 ; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 2; k++) {

				RigidBodyExplosion* rb_e = new RigidBodyExplosion(Vector3(20 * i - (10 * (j % 2)), 10 * j, k), 7);

				mRigidBodyForces_->addForce(ForceType::EXPLOSION,rb_e);
				ExplosionForce* e = new ExplosionForce(Vector3(20 * i - (10 * (j % 2)), 10 * j, k), 7);
				mParticleForces_->addForce(ForceType::EXPLOSION, e);

				rb_e->setParticle(e->getAssociatedParticle());
			}
		}
	}

	int goal_ind = 1 + rand() % 49;

	Vector3 pos = static_cast<ExplosionForce*>(mParticleForces_->getForce(ForceType::EXPLOSION, goal_ind))->getAssociatedParticle()->getPosition();
	pos += Vector3(0, -10, 0);

	goal = new Particle(pos, Vector3(0, 0, 0), Vector3(0, 0, 0), 0.5, 3,3, Vector4(0, 0.65, 0.45, 0.3), 0);

	InverseExplosionForce* exp = new InverseExplosionForce(pos, 10);
	exp->setParticle(goal);

	mParticleForces_->addForce(ForceType::ABSORCION, exp);
}

