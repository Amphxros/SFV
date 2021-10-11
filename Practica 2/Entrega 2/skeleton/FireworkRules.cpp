#include "FireworkRules.h"
#include "Firework.h"
#include "FireworkSystem.h"


FireworkRules::FireworkRules(Type type, float minAge, float maxAge, Vector3 minVelocity, Vector3 maxVelocity, float damp, int count, FireworkSystem* system):
	fireworkType(type), minAge_(minAge), maxAge_(maxAge), minVelocity_(minVelocity), maxVelocity_(maxVelocity),damp_(damp), mSystem_(system)
{
	mPayloads_ = std::vector<Payload>(count);
}

void FireworkRules::create(Firework* mFirework, Firework* parent=nullptr)
{
	Vector3 pos, vel, acc;
	float age, mass;
	Vector4 col;
	if (parent != nullptr) {
		pos = parent->getPosition();
		vel = parent->getSpeed();
	}
	else {
		Vector3 s;
		int x = rand() % 3 - 1;
		s.x = 5.0f + x;
		pos = s;
	}

	vel += minVelocity_ + rand()* maxVelocity_;
	mass = 1.0f;
	damp_ = 1.0f;
	acc = Vector3(0, -10, 0);
	col = Vector4(0.1*vel, 1);
	age = minAge_ + rand() * maxAge_;
	
	//mFirework = new Firework(pos, vel, acc, age, mass, dump, col, age, mPayloads_.size(),mSystem_);
	//mSystem_->addFirework(mFirework);
}
