#include "Firework.h"


Firework::Payload::~Payload()
{
}
void Firework::Payload::set(Type type, int count)
{
	int ang = 360 / count;
	switch (type)
	{
	case Type::SPHERE:
		for (int i = 0; i < count; i++) {
			for (int j = 0; j < count; j++) {
				Particle* p = new Particle(Vector3(), Vector3(), Vector3(0, -9.81, 0), 0.9, 0.01, 3, color, 4);
				p->setSpeed(Vector3(cos(2 * i * ang * radians) * sin(j * ang * radians), cos(-3.1415 / 2 * j * ang * radians) * cos(j * ang * radians) + sin(2 * i * ang * radians)* sin(j*ang*radians), 50));
				mParticles_.push_back(p);
			}
		}
		break;
	case Type::CIRCLE:
		for (int i = 0; i < count; i++) {
			Particle* p= new Particle(Vector3(), Vector3(), Vector3(0, -9.81, 0), 0.9, 0.01, 3, color, 4);
			
			p->setSpeed(Vector3(cos(i * ang * radians), sin(i * ang * radians), 0));
			mParticles_.push_back(p);
		}
		break;
	case Type::SPARK:
		for (int i = 0; i < count; i++) {
			Particle* p = new Particle(Vector3(), Vector3(), Vector3(0, -9.81, 0), 0.9, 0.01, 3, color, 4);
			int j = rand() * count;
			p->setSpeed(Vector3(cos(j * ang * radians), sin(j * ang * radians), 0));
			mParticles_.push_back(p);
		}
		break;
	case Type::BASIC:
		for (int i = 0; i < count; i++) {
			Particle* p = new Particle(Vector3(), Vector3(), Vector3(0, -9.81, 0), 0.9, 0.01, 3, color, 4);
			p->setSpeed(Vector3(i,i,i));
			mParticles_.push_back(p);
		}
		break;
	default:
		break;

	}
}
void Firework::Payload::integrate(float t)
{
	if (!mParticles_.empty()) {
		for (auto p : mParticles_) {
			p->integrate(t);
			if (p->isTimeOver(t)) {
				//borramos las particulas del payload
			}
		}
	}
}
void Firework::Payload::setPosition(Vector3 pos)
{
	for (auto p : mParticles_)
		p->setPosition(pos);
}
void Firework::FireWorkRule::setParameters(Type type, float minAge, float maxAge, Vector3 minVel, Vector3 maxVel, float damp)
{
	ruleType = type;
	minAge_ = minAge;
	maxAge_ = maxAge;
	minSpeed_ = minVel;
	maxSpeed_ = maxVel;
	damping = damp;
}

void Firework::FireWorkRule::create(Firework* fw, Firework* parent)
{
	fw->setType(ruleType);
	fw->setAge(minAge_ + rand() * maxAge_);

	Vector3 vel,start;
	if (parent != nullptr) {
		fw->setPosition(parent->getPosition());
		vel += parent->getSpeed();
	}
	else {
		int x = rand() * 3 - 1;
		start.x = 5.0f * x;
		fw->setPosition(start);
	}

	vel += minSpeed_;
	float x, y, z;
	vel.x += rand() * maxSpeed_.x;
	vel.y += rand() * maxSpeed_.y;
	vel.z += rand() * maxSpeed_.z;
	fw->setSpeed(vel);
	fw->setDamping(damping);
	fw->setAcceleration(Vector3(0, -9.81, 0));
}

void Firework::FireWorkRule::integrate(float t)
{
	for (int i = 0; i < mPayloads.size(); i++) {
		mPayloads[i]->integrate(t);
	}
}

Firework::Firework(Type type, Vector3 pos, Vector4 color): 
	Particle(pos,Vector3(), Vector3(),0.9,0.001, 3, color,10), fwType_(type)
{
}

void Firework::integrate(float t)
{
	if (!payload_Created) {
		Particle::integrate(t);
		if (Particle::isTimeOver(t)) {
			///crear las particulas...
			for (int i = 0; i < rules[fwType_].mPayloads.size(); i++) {
				int r = rand() * rules[fwType_].mPayloads.size();
				rules[fwType_].mPayloads[i]->set(fwType_, r);
			}
			//....

			payload_Created = true;
		}
	}
	else {
		rules[fwType_].integrate(t);
	}
}

void Firework::initFireworkRules()
{
	rules.reserve((int)Type::NUM_RULES);
	for (int i = 0; i < rules.size(); i++) {
		rules[i] = FireWorkRule();
	}
	rules[0].setParameters(Type::CIRCLE, 0.5, 1.4, Vector3(-5, 25, -5), Vector3(5, 28, 5), 0.1);
	rules[1].setParameters(Type::SPHERE, 0.7, 2.4, Vector3(-5, 50, -5), Vector3(5, 28, 5), 0.1);
	rules[2].setParameters(Type::SPARK, 2.7, 3.5, Vector3(-5, 50, -5), Vector3(5, 30, 5), 0.1);
	rules[3].setParameters(Type::BASIC, 2.7, 3.5, Vector3(-5, 50, -5), Vector3(5, 30, 5), 0.1);
	
	Payload* p = new Payload();
	p->set(Type::BASIC, 5);
	rules[0].mPayloads.push_back(p);
	p->set(Type::SPARK, 10);
	rules[0].mPayloads.push_back(p);
	
	p->set(Type::SPARK, 3);
	rules[1].mPayloads.push_back(p);
	p->set(Type::SPHERE, 60);
	rules[1].mPayloads.push_back(p);
	p->set(Type::SPARK, 3);

	p->set(Type::SPARK, 3);
	rules[2].mPayloads.push_back(p);
	p->set(Type::CIRCLE, 10);
	rules[2].mPayloads.push_back(p);
	p->set(Type::SPARK, 3);
}

