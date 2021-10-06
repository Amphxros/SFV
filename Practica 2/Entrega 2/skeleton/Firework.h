#pragma once
#include "Particle.h"
#include "ParticleManager.h"

enum Type{ Basico, Simple, Multiple}; //basico no explota en más, Simple genera fuegos simples, multiples genera simples

struct mFireworkRules
{
    Type mType;
    unsigned int mCount;

    mFireworkRules(Type t, int c): mType(t), mCount(c){}
};


class Firework :
    public Particle
{
public:
    Firework(Vector3 pos, Vector3 speed, Vector3 accel, float drag, float mass, float rd, Vector4 col, double limit, Type type, int mCount);
    virtual ~Firework();
    virtual void integrate(float t);

private:
    void OnDestroy();
    
    std::vector<mFireworkRules> mFireWorks_;
    int count;
    Type mType_;
};

