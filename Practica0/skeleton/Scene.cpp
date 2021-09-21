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
	}
}

void Scene::addParticle(Vector3 p, Vector3 v, Vector3 a, float m, float d, float r, Vector4 c)
{
	std::cout << "p added" << std::endl;
	Particle* p_ = new Particle(p, v, a, d, m, r, c);
	mParticles_.push_back(p_);
}
