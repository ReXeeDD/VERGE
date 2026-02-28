#pragma once

#include"Vec2.h"

class RigidBody
{
public:
    Vec2 position;
    Vec2 velocity;
    Vec2 forceAccum;
    float mass = 1.0f;
    float restitution = 1.0f;

    RigidBody(Vec2 p, Vec2 v, float m);


    void ApplyForce(const Vec2& force);
    void Integrate(float dt);
};