#pragma once
#include "Particle.h"
#include "FireworkRules.h"
class FireworkSystem;
class Firework :
    public Particle
{
public:
    Firework(Vector3 pos, Vector3 speed, Vector3 accel, float drag, float mass, float rd, Vector4 col, double limit, Type type, int mCount, FireworkSystem* system);
    virtual ~Firework();

    virtual void integrate(float t);
    
    inline Type getType() { return mType_; }
    inline void setType(Type t) { mType_ = t; }
private:
    void initFireWorksRules() {};
    void OnDestroy();
    int count;
    Type mType_;

    FireworkSystem* mSystem_;

};

