#pragma once
#include "core.hpp"
enum Type { NONE, Basic, Simple, Multiple }; //basico no explota en más, Simple genera fuegos fuegos basicos, multiples genera simples

struct Payload {
    Type mType_;
    unsigned int mCount_;
    Payload() : mType_(Type::NONE), mCount_(0) {}
    Payload(Type mType, int count) : mType_(mType), mCount_(count) {}
};
class FireworkSystem;
class Firework;
class mFireworkRules
{
public:
    mFireworkRules() {}
    mFireworkRules(Type mType, float minAge, float maxAge, Vector3 minVelocity, Vector3 maxVelocity, float damp, int count, FireworkSystem* system);
    void create(Firework* mFirework, Firework* parent);
    void setType(Type t) { mType_ = t; }

protected:
    Type mType_;
    float minAge_, maxAge_;
    Vector3 minVelocity_, maxVelocity_;
    float damp_;
    std::vector<Payload> mPayloads_;
    FireworkSystem* mSystem_;
};