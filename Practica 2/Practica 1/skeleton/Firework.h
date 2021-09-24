#pragma once
#include "Particle.h"

enum ParticleType{NONE,SIMPLE_FIREWORK, MULTIPLE_FIREWORK};

struct PayLoad {
	ParticleType mType_;
	unsigned int count_;

	PayLoad(ParticleType type, unsigned int num): mType_(type),count_(num) {}
};

struct FireworkRule {
	ParticleType mType_;
	float minAge_;
	float maxAge_;

	Vector3 minSpeed_, maxSpeed_;
	float mDamping_;

	std::vector<PayLoad> mPayloads_;

	Firework* mFirework_;
	Firework* mParent_;

	FireworkRule(Firework* mFirework, Firework* mParent=nullptr): mFirework_(mFirework), mParent_(mParent){
		mFirework_->setParticleType(mType_);
		mFirework_->setAge(minAge_ + rand()* maxAge_);

		if (mParent_ != nullptr) {
			mFirework_->setPosition(mParent_->getPosition());
			mFirework_->setSpeed(mParent_->getSpeed());
		}
		else {
			int x = rand() % 3 - 1;
			mFirework_->setPosition(Vector3(5.0f*x, 0, 0));
		}

		Vector3 vel;
		vel += minSpeed_ + rand()* maxSpeed_;

		mFirework_->setSpeed(mFirework_->getSpeed() + vel);
		mFirework_->setMass(1);
		mFirework_->setAcceleration(Vector3(0, -10, 0));
		
	}

	void init() {

	}

};


class Scene;
class Firework :
	public Particle
{
public:
	Firework(Vector3 pos, Vector3 speed, Vector3 accel, float drag, float mass, float rd, Vector4 col, double limit);
	virtual ~Firework();

	virtual void update(float t);

	inline ParticleType getType() { return mParticleType_; }
	inline void setParticleType(ParticleType p) { mParticleType_ = p; }

	

protected:
	ParticleType mParticleType_;
	std::list <Firework*> mFireWorks_;
};

