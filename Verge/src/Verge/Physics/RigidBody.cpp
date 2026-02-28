#include "RigidBody.h"
#include"Vec2.h"

RigidBody::RigidBody(Vec2 p, Vec2 v, float m=1.0f,float radius=1.0f):position(p),velocity(v),mass(m),radius(radius){
    invMass= invMass = (mass > 0) ? 1.0f / mass : 0.0f;
    inertia = 0.5f * mass * radius * radius;
    invInertia = (inertia > 0) ? 1.0f / inertia : 0.0f;
}

void RigidBody::ApplyForce(const Vec2& force) {
	forceAccum += force;
}
void RigidBody::Integrate(float dt) {
    // Linear
    Vec2 acceleration = forceAccum * invMass;
    velocity += acceleration * dt;
    position += velocity * dt;

    // Angular
    float angularAcc = torqueAccum * invInertia;
    angularVelocity += angularAcc * dt;
    rotation += angularVelocity * dt;

    forceAccum = Vec2::Zero();
    torqueAccum = 0.0f;
}
void RigidBody::SetMass(float m) {
    mass = m;
    invMass = (mass > 0.0f) ? 1.0f / mass : 0.0f;
}
float RigidBody::GetMass() const { return mass; }
float RigidBody::GetInvMass() const { return invMass; }

void RigidBody::ApplyTorque(float torque)
{
    torqueAccum += torque;
}