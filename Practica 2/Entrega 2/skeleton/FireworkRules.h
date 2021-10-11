#pragma once
#include "core.hpp"
enum Type { NONE,BASIC, EXPLOSIONGLOBE, EXPLOSIONMULTIPLE ,NUM_TYPES };

struct Payload {
    Type mType_;
    unsigned int mCount_;
    Payload() : mType_(Type::NONE), mCount_(0) {}
    Payload(Type mType, int count) : mType_(mType), mCount_(count) {}
};
class FireworkSystem;
class Firework;
struct FireworkRules
{
    FireworkRules() {}
    FireworkRules(Type type,float minAge, float maxAge, Vector3 minVelocity, Vector3 maxVelocity, float damp, int count, FireworkSystem* system);
    void create(Firework* mFirework, Firework* parent);

    FireworkRules getRuleFromType(const Type& type);
    std::vector<Payload> getPayloads() { return mPayloads_; }
protected:
  
    Type fireworkType;
    FireworkSystem* mSystem_;
    
    float minAge_, maxAge_;
    Vector3 minVelocity_, maxVelocity_;
    float damp_;
    std::vector<Payload> mPayloads_;
    std::vector<FireworkRules> mRules_;
};