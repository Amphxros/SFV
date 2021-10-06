#pragma once
#include "Particle.h"
#include "ParticleManager.h"

enum Type{ Basico, Simple, Multiple}; //basico no explota en más, Simple genera fuegos simples, multiples genera simples

struct Payload {
    Type mType_;
    unsigned int mCount_;
    Payload(Type mType, int count): mType_(mType), mCount_(count){}
};
class Firework; // declaracion previa para el create
class mFireworkRules
{
protected:
    Type mType_;
    float minAge, maxAge;
    Vector3 minVelocity_, maxVelocity_;
    float damp_;
    std::vector<Payload> mPayloads_;
public:
    mFireworkRules(){}
    mFireworkRules(Type mType, float minAge, float maxAge, Vector3 minVelocity, Vector3 maxVelocity, float damp);
    void create(Firework* mFirework, Firework* parent );

};


class Firework :
    public Particle
{
public:
    Firework(Vector3 pos, Vector3 speed, Vector3 accel, float drag, float mass, float rd, Vector4 col, double limit, Type type, int mCount);
    virtual ~Firework();

    virtual void integrate(float t);

private:
    void initFireWorksRules();
    void OnDestroy();
    
    std::vector<mFireworkRules> mFireWorks_;
    int count;
    Type mType_;

};

