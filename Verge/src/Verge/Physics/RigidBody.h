#pragma once

#include"Vec2.h"

class RigidBody
{
public:
    Vec2 position;
    Vec2 velocity;
    Vec2 forceAccum;
    RigidBody(Vec2 p, Vec2 v, Vec2 f);

    float mass = 1.0f;

    void ApplyForce(const Vec2& force);
    void Integrate(float dt);
};