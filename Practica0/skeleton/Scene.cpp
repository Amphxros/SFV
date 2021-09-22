#include "Scene.h"
#include <iostream>

Scene::~Scene()
{
	for (auto* p : mParticles_) {
		delete p;
	}
}

void Scene::init()
{
	mParticles_ = std::list<Particle*>();
}

void Scene::run(double t)
{
	for (auto p : mParticles_) {
		p->update(t);
		if (p->isTimeOver(t)) {
			mParticles_.erase(p->getIt());
			delete p;
		}
	
	}
}

void Scene::addParticle(Vector3 p, Vector3 v, Vector3 a, float m, float d, float r, Vector4 c)
{
	Particle* p_ = new Particle(p, v, a, d, m, r, c, 2);

	auto it = mParticles_.insert(mParticles_.end(), p_);
	p_->setIt(it);
}
