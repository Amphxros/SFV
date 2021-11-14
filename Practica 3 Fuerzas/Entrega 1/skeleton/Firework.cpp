#include "Firework.h"

Firework::Payload::Payload(unsigned type, unsigned count, Vector4 color):
	payloadType_(type), payloadCount_(count), color(color)
{
}

void Firework::Payload::integrate(float t)
{
	auto it = mParticles_.begin();
	while (!mParticles_.empty() && it != mParticles_.end()) {
		Particle* p = *it;
		p->integrate(t);
		if (p->isTimeOver(t)) {
			//creamos particulas
			if (payloadType_ == Type::SPHERE && payloadCount_!=0) {
				for (int i = 0; i<payloadCount_; i++) {
					Particle* f = new Particle(p->getPosition(), Vector3(), Vector3(0, -9.81, 0), 0.3, 0.001, 0.5, p->getColor(), 1);
					f->setSpeed(Vector3(cos(rand() % 360) * 10, 10, sin(rand() % 360) * 10));
					mParticles_.push_back(f);
				}
				payloadCount_--;
			}

			
			mParticles_.erase(mParticles_.begin());
			delete p;
			it = mParticles_.begin();
		}
		else if (!mParticles_.empty())
			it++;
	}
}

void Firework::Payload::explode()
{
	switch (payloadType_)
	{
	case Type::SPARK:
		for (int i = 0; i < payloadCount_; i++) {
			Particle* p = new Particle(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.9, 11,1, color, 3);
			p->setSpeed(Vector3(cos(rand() % 360) * 10, 10, sin(rand() % 360) * 10));
			p->setAcceleration(Vector3(0, -9.8, 0));
			mParticles_.push_back(p);
		}
		break;
		
	case Type::SPHERE:
		for (int i = 0; i < payloadCount_; i++) {
			Particle* p = new Particle(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.9, 0.001, 11, color, 3);
			p->setSpeed(Vector3(cos(rand() % 360) * 10, 10* sin(i*360/payloadCount_), sin(rand() % 360) * 10));
			p->setAcceleration(Vector3(0, -9.8, 0));
			mParticles_.push_back(p);
		}
		break;
		
	case Type::ASPERSOR:
		for (int i = 0; i < payloadCount_; i++) {
			Particle* p = new Particle(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.9, 0.001, 11, color, 3);
			p->setSpeed(Vector3(cos(rand() % 360) * 360, 0, sin(rand() % 360) * 360));
			p->setAcceleration(Vector3(0, -9.8, 0));
			mParticles_.push_back(p);
		}
		break;

	default:
		break;
	}
}

void Firework::FireWorkRule::set(unsigned type, float minAge, float maxAge, Vector3 minSpeed, Vector3 maxSpeed)
{

}

void Firework::FireWorkRule::create(Firework* firework, const Firework* parent) const
{
	firework->fireWorkType = ruleType;
	firework->setAge(minAge_ + rand() % (int)(maxAge_ - minAge_));

	Vector3 vel;
	if (parent != nullptr) {
		firework->setPosition(parent->mPos_);
		vel += parent->mSpeed_;
	}
	else {
		Vector3 ini;
		int x = (rand() % 3) - 1;
		ini.x = 5.0f * x;
		firework->setPosition(ini);
	}

	vel = minSpeed_ + rand()* (Vector3)(maxSpeed_ - minSpeed_);
	firework->setSpeed(vel);
	firework->setDamping(damping_);
}

Firework::Firework(Vector3 pos, Vector3 vel, Vector4 color, int rule, int type, int count):
	Particle(pos,vel,Vector3(), 0.7, 1,2,color,7), rule_(rule), fireWorkType(type)
{
	rules[rule_] = new FireWorkRule();
	initFireworkRules(fireWorkType, count);
}

Firework::~Firework()
{
	auto it = rules[rule_]->mPayloads_.begin();
	while (!rules[rule_]->mPayloads_.empty() && it != rules[rule_]->mPayloads_.end()) {
		Payload* p = *it;
		if (!p->mParticles_.empty()) {
			while (!p->mParticles_.empty()) {
				Particle* prt = *p->mParticles_.begin();
				p->mParticles_.erase(p->mParticles_.begin());
				delete prt;
			}
		}
		else {
			rules[rule_]->mPayloads_.erase(rules[rule_]->mPayloads_.begin());
			it = rules[rule_]->mPayloads_.begin();
		}
		if (!rules[rule_]->mPayloads_.empty()) it++;
	}
}

void Firework::initFireworkRules(int type, int count)
{
	rules[rule_]->set(type, 1.0, 5.0, Vector3(-10, -10, 10), Vector3(10, 150, 20));
	rules[rule_]->mPayloads_.push_back(new Payload(type, count, mColor_));
}


void Firework::integrate(float t)
{
	if (isActive()) {
		Particle::integrate(t);
		if (Particle::isTimeOver(t)) {
			setInactive();
			for (Payload* p : rules[rule_]->mPayloads_) {
				
				p->explode();

				for (auto i : p->mParticles_) {
					i->setPosition(mPos_);
				}
			}
			mBody_->release();
		}
	}
	else {
		auto it = rules[rule_]->mPayloads_.begin();
		while (!rules[rule_]->mPayloads_.empty() && it != rules[rule_]->mPayloads_.end()) {
			Payload* p = *it;
			p->integrate(t);
			if (p->mParticles_.empty()) {

				rules[rule_]->mPayloads_.erase(rules[rule_]->mPayloads_.begin());
				it = rules[rule_]->mPayloads_.begin();
			}
			else if (!rules[rule_]->mPayloads_.empty()) {
				it++;
			}
		}
	}
}

void Firework::setInactive()
{
	fireWorkType = Type::NONE;
}
