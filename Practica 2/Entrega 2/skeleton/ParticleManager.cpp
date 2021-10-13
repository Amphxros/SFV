#include "ParticleManager.h"

ParticleManager::ParticleManager(Vector3 point, float time) :
	mPoint_(point), gen_time_(time)
{
	
}

ParticleManager::~ParticleManager()
{
	for (auto* p : mParticles_) {
		delete p;
	}
}

void ParticleManager::add(Vector3 p, Vector3 v, Vector3 a, float d, float m, float r, Vector4 c, float time)
{
	Particle* p_ = new Particle(p, v, a, d, m, r, c, time);
	std::list<Particle*>::iterator it = mParticles_.insert(mParticles_.end(), p_);
	p_->setIt(it);

}

void ParticleManager::integrate(double t)
{
	mTime_ -= t;
	if (mTime_ < 0) {
		mTime_ = gen_time_;

		addNRandomParticles(1);
	}

	for (auto& p : mParticles_) {
		p->integrate(t);

		if (p->isTimeOver(t)) {
			mParticles_.erase(p->getIt());
			delete p;
		}
	}

}

void ParticleManager::addNRandomParticles(int n)
{
	for (int i = 0; i < n; i++) {

		float x = 1 + rand() % 9;
		float y = 1 + rand() % 9;
		float z = 1 + rand() % 9;
		
		int nan = rand() % 3;
		if (nan == 1) {
			y *= -1;
		}
		else if (nan ==0) {
			y = 0.02f +  rand() % 3;
		}

		add(mPoint_ - Vector3(5, 0, 5), -Vector3(x, y, z), Vector3(0,-10,0), 1, 0.9, 0.2, Vector4(1, 0.1, 0.2, 1), 3);

	}
}
