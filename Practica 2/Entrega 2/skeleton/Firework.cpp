#include "Firework.h"
#include "FireworkSystem.h"
Firework::Firework(Vector3 pos, Vector3 speed, Vector3 accel, float drag, float mass, float rd, Vector4 col, double limit, Type type, int mCount, FireworkSystem* system):
	Particle(pos,speed,accel,drag,mass,rd,col,limit), mType_(type), count(mCount)
{
	initFireWorksRules();
}

Firework::~Firework()
{
}

void Firework::integrate(float t)
{
	Particle::integrate(t);
	if (Particle::isTimeOver(t)) {
		OnDestroy();
	}

}

void Firework::OnDestroy()
{
}

