#pragma once
#include "Particle.h"
#include <vector>
#define radians 3.1415/180
enum Type {SPHERE, CIRCLE, BASIC,SPARK, NUM_RULES};
class Firework :
    public Particle
{
public:
    Firework(Type type, Vector3 pos, Vector4 color);
    virtual ~Firework(){}
    
    inline Type getType() { return fwType_; }
    inline void setType(Type type) { fwType_ = type; }
    virtual void integrate(float t);

    struct Payload {
        Type payloadType;
        unsigned int payloadCount;
        Vector4 color;
        std::vector<Particle*> mParticles_;
        Payload() {};
        ~Payload();
        void set(Type type, int count);
        void integrate(float t);
        void setPosition(Vector3 pos);
    };

    struct FireWorkRule {
        Type ruleType;
        float minAge_, maxAge_;

        Vector3 minSpeed_, maxSpeed_;
        float damping;

        std::vector<Payload*> mPayloads;

        void setParameters(Type type, float minAge, float maxAge, Vector3 minVel, Vector3 maxVel, float damp);
        void create(Firework* fw, Firework* parent);
        void integrate(float t);
    };


protected:
    Type fwType_;
    void initFireworkRules();
    std::vector<FireWorkRule> rules;
    bool payload_Created=false;
};

