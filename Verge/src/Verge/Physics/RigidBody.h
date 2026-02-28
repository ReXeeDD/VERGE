#pragma once

#include"Vec2.h"

class RigidBody
{
public:
    Vec2 position;
    Vec2 velocity;
    Vec2 forceAccum;
    float mass = 0.0f;
    float invMass = 0.0f;
    float restitution = 0.5f;
    float rotation = 0.0f;
    float inertia = 0.0f;
    float invInertia = 0.0f;
    float torqueAccum = 0.0f;
    float angularVelocity = 0.0f;
    float radius=0.0f;

    RigidBody(Vec2 p, Vec2 v, float m, float radius);

    void SetMass(float m);
    void ApplyForce(const Vec2& force);
    void Integrate(float dt);

    float GetMass() const;
    float GetInvMass() const;
    void ApplyTorque(float torque);
};